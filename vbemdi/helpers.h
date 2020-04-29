#ifndef _HELPERS_9EF22F0D_46AB_423F_BA5A_D1BD482453D1_
#define _HELPERS_9EF22F0D_46AB_423F_BA5A_D1BD482453D1_

#ifndef _INC_SHLWAPI
#include <Shlwapi.h>
#pragma comment(lib,"Shlwapi.lib")
#endif

/////////////////////////////////////////////////////////////////////////////////
//fix for Windows 10 IME crash
typedef HANDLE (WINAPI *pfnImmAssociateContext)(HWND hWnd, HANDLE hIMC);
HANDLE RemoveIME(HWND hWnd)
{
	if (!IsWindow(hWnd)) return NULL;

	HMODULE hImm32 = LoadLibrary(_T("imm32.dll"));
	if (NULL == hImm32) { DBGTRACE("LoadLibrary imm32.dll failed\n"); return NULL; }

	HANDLE hIME = NULL;
	pfnImmAssociateContext pfn = (pfnImmAssociateContext) GetProcAddress(hImm32, "ImmAssociateContext");
	if (pfn)
	{
		hIME = pfn(hWnd, NULL);
		if (hIME) {DBGTRACE("removed IME context 0x%x from 0x%x\n", hIME, hWnd);}
	}
	else {DBGTRACE("GetProcAddress(imm32.dll,ImmAssociateContext) failed\n");}
	FreeLibrary(hImm32);
return hIME;
}
BOOL RestoreIME(HWND hWnd, HANDLE hIMEContext)
{
	if (!IsWindow(hWnd)) return FALSE;
	if (NULL == hIMEContext) return FALSE;

	HMODULE hImm32 = LoadLibrary(_T("imm32.dll"));
	if (NULL == hImm32) { DBGTRACE("LoadLibrary imm32.dll failed\n"); return FALSE; }

	BOOL bRet = FALSE;
	HANDLE hIME = NULL;
	pfnImmAssociateContext pfn = (pfnImmAssociateContext) GetProcAddress(hImm32, "ImmAssociateContext");
	if (pfn)
	{
		hIME = pfn(hWnd, hIMEContext);
		_ASSERTE(NULL == hIME);
		DBGTRACE("restored IME context 0x%x to 0x%x\n", hIMEContext, hWnd);
		bRet = TRUE;
	}
	else {DBGTRACE("GetProcAddress(imm32.dll,ImmAssociateContext) failed\n");}
	FreeLibrary(hImm32);
return bRet;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
LSTATUS HKCUSetBoolValue(LPCTSTR pszSubKey, LPCTSTR pszValue, BOOL bValue)
{
	DWORD d = bValue;
	HKEY hk = NULL;
	LSTATUS ls = RegCreateKeyEx(HKEY_CURRENT_USER, pszSubKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hk, NULL);
	if (ERROR_SUCCESS != ls) return ls;
	ls = RegSetValueEx(hk, pszValue, 0, REG_DWORD, (BYTE*)&d, sizeof(DWORD));
return RegCloseKey(hk);
}
/////////////////////////////////////////////////////////////////////////////////
BOOL IsWindowCurrentProcessThread(HWND hWnd)
{
	DWORD dwpid;
return (GetWindowThreadProcessId(hWnd, & dwpid)==GetCurrentThreadId()) && (dwpid==GetCurrentProcessId());
}

BOOL CopyWindowText(HWND hwFrom, HWND hwTo)
{
	BOOL retVal = FALSE;
	//TODO: same thread and process only?
	//if (!IsWindowCurrentProcessThread(hwFrom) || !IsWindowCurrentProcessThread(hwTo)) return FALSE;

	//get text size and allocate buffer
	LRESULT lBufLen = SendMessage(hwFrom, WM_GETTEXTLENGTH, NULL, NULL) + 1;//terminating null is not counted
	HANDLE hProcHeap = GetProcessHeap();
	if (!hProcHeap) return retVal;
	LPVOID pBuf = HeapAlloc(hProcHeap, HEAP_ZERO_MEMORY, (SIZE_T)(lBufLen*sizeof(TCHAR)));
	if (pBuf)
	{
		if (SendMessage(hwFrom, WM_GETTEXT, lBufLen, (LPARAM)pBuf) == (lBufLen-1)) {retVal = (BOOL)SendMessage(hwTo, WM_SETTEXT, NULL, (LPARAM)pBuf);}
		HeapFree(hProcHeap, NULL, pBuf);
	}
	else
	{
		DBGTRACE2("HeapAlloc failed\n");
		retVal = FALSE;
	}
return retVal;
}

BOOL IsWindowClass(HWND hWnd, LPCTSTR pszClsName)
{
	TCHAR strBuf[256];
return ((GetClassName(hWnd, strBuf, 256) && lstrcmp(strBuf, pszClsName) == 0));
}

BOOL IsWindowMaximized(HWND hWnd)
{
	if (NULL == hWnd) return FALSE;
	WINDOWPLACEMENT wpl;
	wpl.length = sizeof(WINDOWPLACEMENT);
	wpl.showCmd = 0;
	::GetWindowPlacement(hWnd, &wpl);
return (SW_SHOWMAXIMIZED == wpl.showCmd);
}

UINT GetChildWindowCount(HWND hWnd, __in_opt LPCTSTR lpszChildClass, __in_opt BOOL bVisibleOnly)
{
	UINT c = 0;
	HWND hwch = FindWindowEx(hWnd, NULL, lpszChildClass, NULL);
	while (hwch)
	{
		if (bVisibleOnly) {if (IsWindowVisible(hwch)) c++;}
		else c++;
		hwch = FindWindowEx(hWnd, hwch, lpszChildClass, NULL);
	}
return c;
}

HWND GetActiveMDIChild(WNDPROC mdiProc, HWND hwMDI, LPARAM lParam=NULL)
{
	return (HWND)mdiProc(hwMDI, WM_MDIGETACTIVE, NULL, lParam);
}

BOOL ScreenToClientRect(HWND hWindow, LPRECT lpRc)
{
	if (!::ScreenToClient(hWindow, reinterpret_cast<POINT*>(&lpRc->left)  )) return FALSE;
	if (!::ScreenToClient(hWindow, reinterpret_cast<POINT*>(&lpRc->right) )) return FALSE;
return TRUE;
}

HFONT CreateMenuFont()//LONG lfWeight)
{
	NONCLIENTMETRICS ncm;
	ncm.cbSize = sizeof(NONCLIENTMETRICS);
	if (!SystemParametersInfo(SPI_GETNONCLIENTMETRICS,0,&ncm,0)) return NULL;
	//ncm.lfMenuFont.lfWeight = lfWeight;//CLEARTYPE_QUALITY?
	return CreateFontIndirect(&ncm.lfMenuFont);
}

//https://blogs.msdn.microsoft.com/oldnewthing/20101020-00/?p=12493
// Also works for cursors
LONG GetIconHeight(__in HICON hico)
{
SIZE sz;
  ICONINFO ii;
  BOOL fResult = GetIconInfo(hico, &ii);
  if (fResult) {
    BITMAP bm;
    fResult = GetObject(ii.hbmMask, sizeof(bm), &bm) == sizeof(bm);
    if (fResult) {
      sz.cx = bm.bmWidth;
      sz.cy = ii.hbmColor ? bm.bmHeight : bm.bmHeight / 2;
    }
    if (ii.hbmMask)  DeleteObject(ii.hbmMask);
    if (ii.hbmColor) DeleteObject(ii.hbmColor);
  }
  return sz.cy;
}

int FindListBoxItem(HWND hwListBox, LPCTSTR pszSubstring, BOOL bWrapAround, BOOL bSetCaretIndex)
{
	int endItem = ListBox_GetCount(hwListBox);
	if (LB_ERR == endItem) return LB_ERR;
	int startItem = ListBox_GetCaretIndex(hwListBox) +1;//start from next after selection
	HANDLE hProcHeap = GetProcessHeap();
	if (!hProcHeap) return LB_ERR;
	LPVOID pBuf = HeapAlloc(hProcHeap, HEAP_ZERO_MEMORY, (SIZE_T)(1024*sizeof(TCHAR)));//should be enough
	if (NULL == pBuf) return LB_ERR;
	int retval = LB_ERR;
LBFIWRAPLOOP:
	int i;
	for (i = startItem; i < endItem; i++)
	{
		if (ListBox_GetText(hwListBox, i, pBuf) > LB_ERR)
		{
			if (StrStrI((LPCTSTR)pBuf, pszSubstring))
			{
				retval = i; //DBGTRACE("listbox item found i=%d\n", i);
				if (bSetCaretIndex) ListBox_SetCaretIndex(hwListBox, i);
				break;
			}
		}
	}
	if ((LB_ERR == retval) && bWrapAround)
	{
		bWrapAround = FALSE;//prevent recursion error
		endItem = startItem;
		startItem = 0;//restart from top
		goto LBFIWRAPLOOP;
	}
	HeapFree(hProcHeap, NULL, pBuf);
return retval;
}

#endif//_HELPERS_9EF22F0D_46AB_423F_BA5A_D1BD482453D1_
