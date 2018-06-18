#include "stdafx.h"
#include "debugtrace.h"
#include "helpers.h"
#include "VBEres.h"
#include "resload.h"

extern "C" IMAGE_DOS_HEADER __ImageBase;

IDispatch* g_pApplication;

#define MAX_WNDCLASSNAME 256
TCHAR g_strBuff[MAX_WNDCLASSNAME];

HWINEVENTHOOK g_hEventHook;

HWND g_hwMDIwnd;
HWND g_hwLastActiveMDIChild;
WNDPROC g_oldMDIproc;

HWND g_hwTabStrip;
WNDPROC g_oldTabProc;
long g_tabstripHeight;

HFONT g_hMenuFont;

HWND g_hwPathEditBox;
HWND g_hwStatic;
WNDPROC g_oldStaticProc;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void FixVBMdiChildHack()
{
	if (g_hwMDIwnd == NULL) return;
	HWND hwhack = FindWindowEx(g_hwMDIwnd, NULL, L"VBMdiChildHack", NULL);
	if (hwhack && IsWindowVisible(hwhack)) ShowWindow(hwhack, SW_HIDE);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK NewTabstripProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT idx=-1;
    switch (message)
	{

//TODO case WM_MOUSEWHEEL:  //scroll tabs with mouse wheel?  <<< need mousehook for this because tabstrip never gets focus!
		//	DBGTRACE("WM_MOUSEWHEEL\n");
		//	SendMessage(hWnd, WM_HSCROLL, NULL, ((HIWORD(wParam)<0) ? SB_LINERIGHT : SB_LINELEFT));
		//return 0;

		case WM_LBUTTONDOWN:
		case WM_RBUTTONDOWN: //activate tab on right-click to associate context menu with correct tab
			DBGTRACE("tab activate tab\n"); 
			{
				LRESULT lret=CallWindowProc(g_oldTabProc, hWnd, WM_LBUTTONDOWN, wParam, lParam);//select tab first
				if ((idx=CallWindowProc(g_oldTabProc, hWnd, TCM_GETCURSEL, NULL, NULL))> -1)
				{
					TCITEM ti;
					SecureZeroMemory(&ti, sizeof(TCITEM));
					ti.mask=TCIF_PARAM;
					if (CallWindowProc(g_oldTabProc, hWnd, TCM_GETITEM, idx, (LPARAM)&ti))
						SendMessage(g_hwMDIwnd, TCM_SETCURSEL, (WPARAM)ti.lParam, NULL);	
				}
				return lret;
			}
		break;

		//show context menu
		case WM_RBUTTONUP:
			{
//TODO localize menu in more languages
//TODO more testing of localization
				HMENU hctxmenu = LoadMenuLC((HINSTANCE)&__ImageBase, IDM_TABSTRIP, GetUserDefaultUILanguage());
				if (hctxmenu == NULL) return 0;
				HMENU hmenuTrackPopup = GetSubMenu(hctxmenu, 0);
				if (hmenuTrackPopup)
				{
					POINT pt;
					pt.x = GET_X_LPARAM(lParam);
					pt.y = GET_Y_LPARAM(lParam),
					ClientToScreen(hWnd, &pt);
					TrackPopupMenu(hmenuTrackPopup, TPM_LEFTALIGN, pt.x, pt.y, 0, hWnd, NULL);
				}
				DestroyMenu(hctxmenu);
			}
		break;

		//context menu commands
		case WM_COMMAND:
			switch (wParam) //HIWORD should be 0 if from menu, so check full dword
			{
			case IDC_MDICLOSE:
				DBGTRACE("IDC_MDICLOSE\n");
				if ((idx=CallWindowProc(g_oldTabProc, hWnd, TCM_GETCURSEL, NULL, NULL))> -1)
				{
					TCITEM ti;
					SecureZeroMemory(&ti, sizeof(TCITEM));
					ti.mask=TCIF_PARAM;
					if (CallWindowProc(g_oldTabProc, hWnd, TCM_GETITEM, idx, (LPARAM)&ti))
					{
						if (SendMessage(g_hwMDIwnd, TCM_DELETEITEM, (WPARAM)ti.lParam, NULL))
							CallWindowProc(g_oldTabProc, hWnd, TCM_DELETEITEM, idx, NULL);
					}
					FixVBMdiChildHack();
				}
				break;
			case IDC_MDICLOSEOTHERS:
				DBGTRACE("IDC_MDICLOSE OTHERS\n");
				{
					TCITEM ti;
					if ((idx=CallWindowProc(g_oldTabProc, hWnd, TCM_GETCURSEL, NULL, NULL))> -1)
					{
						SecureZeroMemory(&ti, sizeof(TCITEM));
						ti.mask=TCIF_PARAM;
						if (CallWindowProc(g_oldTabProc, hWnd, TCM_GETITEM, idx, (LPARAM)&ti))
						{
							LPARAM hwtab = ti.lParam;
							LRESULT tabcount = CallWindowProc(g_oldTabProc, hWnd, TCM_GETITEMCOUNT, NULL, NULL);
							for (idx = (tabcount-1); idx >= 0; idx--)
							{
								SecureZeroMemory(&ti, sizeof(TCITEM));
								ti.mask=TCIF_PARAM;

								if (CallWindowProc(g_oldTabProc, hWnd, TCM_GETITEM, idx, (LPARAM)&ti) && (hwtab != ti.lParam))
								{
									if (SendMessage(g_hwMDIwnd, TCM_DELETEITEM, (WPARAM)ti.lParam, NULL))
										CallWindowProc(g_oldTabProc, hWnd, TCM_DELETEITEM, idx, NULL);
								}
							}
						}
					}
				}
				break;			
			case IDC_MDICLOSEALL:
				DBGTRACE("IDC_MDICLOSE ALL\n");
				{
					//loop and close all mdi childs and tabs
					TCITEM ti;
					LRESULT tabcount = CallWindowProc(g_oldTabProc, hWnd, TCM_GETITEMCOUNT, NULL, NULL);
					for (idx = (tabcount-1); idx >= 0; idx--)
					{
						SecureZeroMemory(&ti, sizeof(TCITEM));
						ti.mask=TCIF_PARAM;
						if (CallWindowProc(g_oldTabProc, hWnd, TCM_GETITEM, idx, (LPARAM)&ti))
						{
							if (SendMessage(g_hwMDIwnd, TCM_DELETEITEM, (WPARAM)ti.lParam, NULL))
								CallWindowProc(g_oldTabProc, hWnd, TCM_DELETEITEM, idx, NULL);
						}
					}
					FixVBMdiChildHack();
				}
				break;			
			}
		break;


		//notifications from MDI subclass proc
		case WM_MDIACTIVATE:
			DBGTRACE("tab WM_MDIACTIVATE\n");
			{
				LRESULT i=CallWindowProc(g_oldTabProc, hWnd, TCM_GETITEMCOUNT, 0, 0);
				TCITEM ti;
				for (idx=0; idx < i; idx++)
				{
					SecureZeroMemory(&ti, sizeof(TCITEM));
					ti.mask=TCIF_PARAM;
					if (CallWindowProc(g_oldTabProc, hWnd, TCM_GETITEM, idx, (LPARAM)&ti))
					{
						if (ti.lParam == (LPARAM)wParam) return CallWindowProc(g_oldTabProc, hWnd, TCM_SETCURSEL, idx, 0);//already exists
					}
				}
				//new item, insert and select
				if (GetWindowText((HWND)wParam, g_strBuff, MAX_WNDCLASSNAME))
				{
					SecureZeroMemory(&ti, sizeof(TCITEM));
					ti.mask=TCIF_TEXT | TCIF_PARAM;
					ti.lParam=(LPARAM)wParam;
					ti.pszText=g_strBuff;
					if (CallWindowProc(g_oldTabProc, hWnd, TCM_INSERTITEM, idx, (LPARAM)&ti)>-1)
						return CallWindowProc(g_oldTabProc, hWnd, TCM_SETCURSEL, idx, 0);
				}
			return 0;
			}
		break;
		case WM_MDIDESTROY:
			DBGTRACE("tab WM_MDIDESTROY\n");
			{
				//maybe Close All was called (mdi child destroy order?)
				LRESULT i=CallWindowProc(g_oldTabProc, hWnd, TCM_GETITEMCOUNT, 0, 0);
				TCITEM ti;
				for (idx=0; idx < i; idx++)
				{
					SecureZeroMemory(&ti, sizeof(TCITEM));
					ti.mask=TCIF_PARAM;
					if (CallWindowProc(g_oldTabProc, hWnd, TCM_GETITEM, idx, (LPARAM)&ti))
					{
						if (ti.lParam == (LPARAM)wParam) return CallWindowProc(g_oldTabProc, hWnd, TCM_DELETEITEM, idx, 0);
					}
				}
			}
		return FALSE;
		break;

		//finally
		case WM_NCDESTROY:
			DBGTRACE("NewTabstripProc  WM_NCDESTROY\n");
			if (SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(g_oldTabProc))) g_oldTabProc = NULL;
			else
			{
				DBGTRACE2("tab ERROR unsubclass tabstrip\n");
			}
		break;
	}
return CallWindowProc(g_oldTabProc, hWnd, message, wParam, lParam);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK NewMDIProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
		case WM_NCCALCSIZE: //adjust for tabstrip height
		{
			DBGTRACE("mdi WM_NCCALCSIZE\n");
			LRESULT lret = CallWindowProc(g_oldMDIproc, hWnd, message, wParam, lParam);
//TODO hide tabstrip if no child windows
			if (wParam) { ((LPNCCALCSIZE_PARAMS)lParam)->rgrc[0].top += (g_tabstripHeight - GetSystemMetrics(SM_CXEDGE)); }
			else { ((LPRECT)lParam)->top += (g_tabstripHeight - GetSystemMetrics(SM_CXEDGE)); }
		return lret;
		}
		break;

		case WM_WINDOWPOSCHANGED:
			{
			DBGTRACE("mdi WM_WINDOWPOSCHANGED\n");
			//reposition tabstrip
			//_ASSERTE(g_hwMDIwnd==hWnd);
			RECT rc;
			SetRectEmpty(&rc);
			GetWindowRect(hWnd, &rc);
			ScreenToClientRect(GetParent(hWnd), &rc);
			SetWindowPos(g_hwTabStrip, HWND_TOP, rc.left+GetSystemMetrics(SM_CXEDGE), rc.top, (rc.right-rc.left-GetSystemMetrics(SM_CXEDGE)), g_tabstripHeight, SWP_SHOWWINDOW);
			}
		break; 
		
		case WM_MDIGETACTIVE:
			{
				LRESULT lret = CallWindowProc(g_oldMDIproc, hWnd, message, wParam, lParam);
				if (g_hwLastActiveMDIChild != (HWND)lret)
				{
					g_hwLastActiveMDIChild = (HWND)lret;
					SendMessage(g_hwTabStrip, WM_MDIACTIVATE, (WPARAM)lret, NULL);
				}
			return lret;
			}
		break;
			
		//route MDI messages to tabstrip
		case WM_MDIACTIVATE:
			DBGTRACE("mdi WM_MDIACTIVATE\n");
			SendMessage(g_hwTabStrip, WM_MDIACTIVATE, wParam, NULL);
		break;
		case WM_MDIDESTROY:
			DBGTRACE("mdi WM_MDIDESTROY\n");
			PostMessage(g_hwTabStrip, WM_MDIDESTROY, wParam, NULL);
			PostMessage(g_hwTabStrip, WM_MDIACTIVATE, (WPARAM)GetActiveMDIChild(g_oldMDIproc, hWnd), NULL);
		break;

		//tabstrip notifications
		case TCM_SETCURSEL:
			DBGTRACE("mdi TCM_SETCURSEL\n");
			if (0==CallWindowProc(g_oldMDIproc, hWnd, WM_MDIACTIVATE, wParam, NULL)) return TRUE;
			else return FALSE;
		break;
		case TCM_DELETEITEM:
			DBGTRACE("mdi TCM_DELETEITEM\n");
			if (0==CallWindowProc(g_oldMDIproc, hWnd, WM_MDIDESTROY, wParam, NULL))
			{
				SendMessage(g_hwTabStrip, WM_MDIACTIVATE, CallWindowProc(g_oldMDIproc, hWnd, WM_MDIGETACTIVE, NULL, NULL), NULL);
				return TRUE;
			}
			else return FALSE;
		break;

		//finally
		case WM_NCDESTROY:
			DBGTRACE("NewMDIProc  WM_NCDESTROY\n");
			if (SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(g_oldMDIproc))) g_oldMDIproc = NULL;
			else
			{
				DBGTRACE2("ERROR unsubclass MDI\n");
			}
		break;//resume default processing
    }
return CallWindowProc(g_oldMDIproc, hWnd, message, wParam, lParam);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitTabstrip(HWND hwVBE)
{
	if (IsWindow(g_hwMDIwnd)) return;
	g_hwMDIwnd=FindWindowEx(hwVBE, NULL, L"MDIClient", NULL);
	if (g_hwMDIwnd)
	{
		DBGTRACE("g_hwMDIwnd\n");

		//create tabstrip
		g_hwTabStrip = CreateWindow(WC_TABCONTROL, _T("MDITabStrip"), WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE | TCS_FOCUSNEVER,
									0, 0, 100, 30, hwVBE, NULL, (HINSTANCE)&__ImageBase, NULL);
		_ASSERTE(g_hwTabStrip);
		if (NULL == g_hwTabStrip) return;
		DBGTRACE("g_hwTabStrip\n");
		//set tabs font
		g_hMenuFont=CreateMenuFont();
		if (g_hMenuFont) SendMessage(g_hwTabStrip, WM_SETFONT, (WPARAM)g_hMenuFont, FALSE);

		//subclass tabstrip
		g_oldTabProc = (WNDPROC)SetWindowLongPtr(g_hwTabStrip, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(NewTabstripProc));

		//sync tabstrip items with MDI
		HWND hwndChildAfter = FindWindowEx(g_hwMDIwnd, NULL, NULL, NULL);
		int i=0;
		while (hwndChildAfter)
		{
			if (GetWindowText(hwndChildAfter, g_strBuff, MAX_WNDCLASSNAME))
			{
				TCITEM ti;
				SecureZeroMemory(&ti, sizeof(TCITEM));
				ti.mask=TCIF_TEXT | TCIF_PARAM;
				ti.lParam=(LPARAM)hwndChildAfter;
				ti.pszText=g_strBuff;
				TabCtrl_InsertItem(g_hwTabStrip, i++, &ti);
			}
			hwndChildAfter = FindWindowEx(g_hwMDIwnd, hwndChildAfter, NULL, NULL);
		}

		//setup tabstrip height
		RECT rc;
		SetRectEmpty(&rc);
		if (TabCtrl_GetItemCount(g_hwTabStrip)==0)
		{
			TCITEM ti;//insert dummy item to get correct tab height
			SecureZeroMemory(&ti, sizeof(TCITEM));
			TabCtrl_InsertItem(g_hwTabStrip, 0, &ti);
			TabCtrl_GetItemRect(g_hwTabStrip, 0, &rc);					
			TabCtrl_DeleteAllItems(g_hwTabStrip);
		}
		else TabCtrl_GetItemRect(g_hwTabStrip, 0, &rc);

		g_tabstripHeight = (rc.bottom-rc.top)+2;

		//reposition tabstrip
		SetRectEmpty(&rc);
		GetWindowRect(g_hwMDIwnd, &rc);
		ScreenToClientRect(hwVBE, &rc);
		SetWindowPos(g_hwTabStrip, HWND_TOP, rc.left+GetSystemMetrics(SM_CXEDGE), rc.top, (rc.right-rc.left-GetSystemMetrics(SM_CXEDGE)), g_tabstripHeight, SWP_SHOWWINDOW);

		//subclass MDI
		g_oldMDIproc = (WNDPROC)SetWindowLongPtr(g_hwMDIwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(NewMDIProc));
		//redraw MDI?
		//RedrawWindow(g_hwMDIwnd, NULL,NULL, RDW_INVALIDATE | RDW_FRAME | RDW_UPDATENOW | RDW_ERASE | RDW_ALLCHILDREN);
		SetWindowPos(g_hwMDIwnd, NULL, 0,0,0,0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED | SWP_NOOWNERZORDER);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK NewStaticProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
    {
		case WM_SETTEXT:
			SetWindowText(g_hwPathEditBox, (LPCTSTR)lParam);
			//fix listbox redrawing problems
			RedrawWindow(GetDlgItem(GetParent(hWnd), 5050), NULL,NULL, RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);
		break;
		case WM_NCDESTROY:
			if (SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(g_oldStaticProc))) g_oldStaticProc=NULL;
			else
			{
				DBGTRACE2("ERROR unsubclass MDI\n");
			}
		break;//resume default processing
	}
return CallWindowProc(g_oldStaticProc, hWnd, message, wParam, lParam);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitReferenceDialog(HWND hDlg)
{
	if (IsWindow(g_hwPathEditBox)) return;
	
	//check if dialog is the References dialog
	HWND hwListBox = GetDlgItem(hDlg, VBE_REFDLG_LISTBOX);
	if (hwListBox == NULL) return;
	RECT rcListBox;
	if (!GetWindowRect(hwListBox, &rcListBox)) return;

	//add extra width to dialog based on OK button
	HWND hwOK = GetDlgItem(hDlg, VBE_REFDLG_OKBUTTON);
	RECT rcOK;
	if (!GetWindowRect(hwOK, &rcOK)) return;
	LONG xw = (rcOK.right - rcOK.left)*2;
	RECT rcDlg;
	if (!GetWindowRect(hDlg, &rcDlg)) return;
	rcDlg.right += xw;
	if (!SetWindowPos(hDlg, NULL, 0,0, rcDlg.right - rcDlg.left, rcDlg.bottom - rcDlg.top, SWP_NOMOVE | SWP_NOZORDER | SWP_NOOWNERZORDER)) return;

	//move controls to the right of listbox
	HWND hwCtrl = FindWindowEx(hDlg, NULL, NULL, NULL);
	while (hwCtrl)
	{
		RECT rcCtrl;
		if (!GetWindowRect(hwCtrl, &rcCtrl)) return;
		//DBGTRACE2("GetDlgCtrlID=%d   (%d, %d, %d, %d)\n", GetDlgCtrlID(hwCtrl), rcCtrl.left, rcCtrl.top, rcCtrl.right, rcCtrl.bottom);
		if (rcCtrl.left > rcListBox.right)// && (rcCtrl.bottom > rcResultsGroup.top))
		{
			rcCtrl.left += xw;
			rcCtrl.right += xw;
			if (!ScreenToClientRect(hDlg, &rcCtrl)) return;
			SetWindowPos(hwCtrl, NULL, rcCtrl.left, rcCtrl.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
		}
		hwCtrl = FindWindowEx(hDlg, hwCtrl, NULL, NULL);
	}

	//widen listbox
	rcListBox.right += xw;
	if (!ScreenToClientRect(hDlg, &rcListBox)) return;
	SetWindowPos(hwListBox, NULL, 0, 0, rcListBox.right - rcListBox.left, rcListBox.bottom - rcListBox.top, SWP_NOMOVE | SWP_NOZORDER | SWP_NOOWNERZORDER);

	//widen results group
	HWND hwResultsGroup = GetDlgItem(hDlg, VBE_REFDLG_RESULTGROUP);
	if (hwResultsGroup == NULL) return;
	RECT rcResultsGroup;
	if (!GetWindowRect(hwResultsGroup, &rcResultsGroup)) return;
	rcResultsGroup.right += xw;
	if (!ScreenToClientRect(hDlg, &rcResultsGroup)) return;
	SetWindowPos(hwResultsGroup, NULL, 0,0, rcResultsGroup.right - rcResultsGroup.left, rcResultsGroup.bottom - rcResultsGroup.top, SWP_NOMOVE | SWP_NOZORDER | SWP_NOOWNERZORDER);

//TODO move controls inside Results group control a little to the left?

	//setup path edit box
	g_hwStatic = GetDlgItem(hDlg, VBE_REFDLG_LOCATIONSTATIC);
	if (g_hwStatic)
	{
		RECT rc;
		if (!GetWindowRect(g_hwStatic, &rc)) return;
		rc.right += xw;
		if (!ScreenToClientRect(hDlg, &rc)) return;
		if (!ShowWindow(g_hwStatic, SW_HIDE)) return;//fix redrawing problems

		//adjust position because of the editbox edge
		//"This API is not DPI aware, and should not be used if the calling thread is per-monitor DPI aware
		//For the DPI-aware version of this API, see AdjustWindowsRectExForDPI" (https://msdn.microsoft.com/en-us/library/windows/desktop/mt748618(v=vs.85).aspx)
		//using WS_EX_CLIENTEDGE gives slightly bigger rect than WS_EX_STATICEDGE
		AdjustWindowRectEx(&rc, WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE | ES_LEFT | ES_READONLY | ES_AUTOHSCROLL,
							FALSE, WS_EX_CLIENTEDGE | WS_EX_NOPARENTNOTIFY);

		//create editbox in place of static control
		g_hwPathEditBox = CreateWindowEx(WS_EX_STATICEDGE | WS_EX_NOPARENTNOTIFY, WC_EDIT, NULL,
										WS_CHILD | WS_CLIPSIBLINGS | ES_LEFT | ES_READONLY | ES_AUTOHSCROLL,
										rc.left, rc.top, (rc.right - rc.left), (rc.bottom - rc.top),
										hDlg, NULL, (HINSTANCE)&__ImageBase, NULL);
		if (g_hwPathEditBox == NULL) return;
		//set font, match size
		HFONT hStaticFont = (HFONT)SendMessage(g_hwStatic, WM_GETFONT, NULL, NULL);
		if (hStaticFont) SendMessage(g_hwPathEditBox, WM_SETFONT, (WPARAM)hStaticFont, TRUE);

		//copy text from static to pathbox
		CopyWindowText(g_hwStatic, g_hwPathEditBox);
		//show path edit box and move to top
		SetWindowPos(g_hwPathEditBox, HWND_TOP, 0,0,0,0, SWP_NOSIZE | SWP_NOMOVE | SWP_SHOWWINDOW);
		//subclass static control to catch WM_SETTEXT
		g_oldStaticProc = (WNDPROC)SetWindowLongPtr(g_hwStatic, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(NewStaticProc));
		return;
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DestroyPathBox(HWND hDlg)
{
	if (GetParent(g_hwStatic) != hDlg) return;//'Browse...' file dialog also triggers EVENT_OBJECT_HIDE

	//unsubclass static
	if (IsWindow(g_hwStatic))
	{
		if (SetWindowLongPtr(g_hwStatic, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(g_oldStaticProc)))
		{
			g_hwStatic = NULL;
			g_oldStaticProc = NULL;
			DBGTRACE("unsubclass static\n");
		}
		else
		{
			DBGTRACE("ERROR unsubclass static\n");
		}
	}
	//be careful who destroys the control (parent dialog or us)
	if (IsWindow(g_hwPathEditBox))
	{
		if (DestroyWindow(g_hwPathEditBox)) g_hwPathEditBox = NULL;
		DBGTRACE("DestroyWindow  g_hwPathEditBox\n");
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CALLBACK WinEventProcCallback(HWINEVENTHOOK hook, DWORD dwEvent, HWND hwnd,
								   LONG idObject, LONG idChild, DWORD dwEventThread, DWORD dwmsEventTime)
{
	UNREFERENCED_PARAMETER(hook);
	UNREFERENCED_PARAMETER(dwEventThread);
	UNREFERENCED_PARAMETER(dwmsEventTime);

	if ((idObject == OBJID_WINDOW) && (idChild == CHILDID_SELF))
		switch (dwEvent)
		{
		case EVENT_OBJECT_SHOW:
				if (IsWindowClass(hwnd, _T("wndclass_desked_gsk")))
				{
					DBGTRACE("EVENT_OBJECT_SHOW  wndclass_desked_gsk\n");
					InitTabstrip(hwnd);
				}

				if (IsWindowClass(hwnd, _T("#32770")))
				{
					DBGTRACE("EVENT_OBJECT_SHOW  #32770\n");
					InitReferenceDialog(hwnd);
				}

			break;
		case EVENT_OBJECT_HIDE:  //dialog is hidden before it is destroyed
				if (IsWindowClass(hwnd, _T("#32770")))
				{
					DBGTRACE("EVENT_OBJECT_HIDE  #32770\n");
					DestroyPathBox(hwnd);
				}
			break;
		}

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
STDAPI Connect(IDispatch *pApplication)
{
	if (NULL==pApplication) return E_INVALIDARG;
	HRESULT hr=S_OK;

	_ASSERTE(NULL==g_hwLastActiveMDIChild);

	INITCOMMONCONTROLSEX iccex;
	iccex.dwSize=sizeof(INITCOMMONCONTROLSEX);
	iccex.dwICC=ICC_TAB_CLASSES;
	if (!InitCommonControlsEx(&iccex)) return E_FAIL;

	_ASSERTE(NULL==g_pApplication);
	if (NULL==g_pApplication)
	{
		g_pApplication = pApplication;
		g_pApplication->AddRef();
		DBGTRACE("vbemdi::Connect\n");
	}
	else hr=ERROR_ALREADY_ASSIGNED;

	_ASSERTE(NULL==g_hEventHook);
	if SUCCEEDED(hr)
	{
		if (NULL==g_hEventHook)
		{
			g_hEventHook = SetWinEventHook(EVENT_OBJECT_SHOW, EVENT_OBJECT_HIDE, (HINSTANCE)&__ImageBase,
											WinEventProcCallback, GetCurrentProcessId(), 0, WINEVENT_INCONTEXT);
			if (g_hEventHook)
			{
				DBGTRACE("vbemdi::SetWinEventHook\n");
				//check if VBE is already opened
				HWND hwVBE = FindWindowEx(NULL, NULL, _T("wndclass_desked_gsk"), NULL);
				while (hwVBE)
				{
					if (IsWindowCurrentProcessThread(hwVBE))
					{
						WinEventProcCallback(g_hEventHook, EVENT_OBJECT_SHOW, hwVBE,
												OBJID_WINDOW, CHILDID_SELF,
												GetCurrentThreadId(), 0);
						break;
					}
					hwVBE = FindWindowEx(NULL, hwVBE, _T("wndclass_desked_gsk"), NULL);
				}
			}
		}
		else {hr=ERROR_ALREADY_EXISTS; DBGTRACE("ERROR_ALREADY_EXISTS\n");}
	}
return hr;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
STDAPI Disconnect()
{
	//unsublcass and destroy tabstrip
	if (g_oldTabProc)
	{
		DBGTRACE("destroy tabstrip\n");
		if (SetWindowLongPtr(g_hwTabStrip, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(g_oldTabProc))) g_oldTabProc = NULL;
		else
		{
			DBGTRACE("ERROR unsubclass tabstrip\n");
		}
	}
	if (DestroyWindow(g_hwTabStrip)) g_hwTabStrip = NULL;

	//cleanup font resources
	if (DeleteObject((HGDIOBJ)g_hMenuFont)) g_hMenuFont = NULL;

	//unsubclass MDI
	if (g_oldMDIproc)
	{
		DBGTRACE("mdi unsubclass\n");
		if (SetWindowLongPtr(g_hwMDIwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(g_oldMDIproc)))
		{
			SetWindowPos(g_hwMDIwnd, NULL, 0,0,0,0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED | SWP_NOOWNERZORDER);
			g_oldMDIproc = NULL;
			g_hwMDIwnd = NULL;
		}
		else
		{
			DBGTRACE("ERROR unsubclass MDI\n");
		}
	}

	//remove event hooks
	_ASSERTE(g_hEventHook);
	if (g_hEventHook)
	{
		UnhookWinEvent(g_hEventHook);
		g_hEventHook=NULL;
		DBGTRACE("vbemdi::UnhookWinEvent\n");
	}

	//release app reference
	_ASSERTE(g_pApplication);
	if (g_pApplication)
	{
		g_pApplication->Release();
		g_pApplication = NULL;
		DBGTRACE("vbemdi::Disconnect\n");
	}
return S_OK;
}