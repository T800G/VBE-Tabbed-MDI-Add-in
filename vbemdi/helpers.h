#ifndef _HELPERS_9EF22F0D_46AB_423F_BA5A_D1BD482453D1_
#define _HELPERS_9EF22F0D_46AB_423F_BA5A_D1BD482453D1_

BOOL IsWindowCurrentProcessThread(HWND hWnd)
{
	DWORD dwpid;
return (GetWindowThreadProcessId(hWnd, & dwpid)==GetCurrentThreadId()) && (dwpid==GetCurrentProcessId());
}

BOOL CopyWindowText(HWND hwFrom, HWND hwTo)
{
	//same thread and process only?
	//if (!IsWindowCurrentProcessThread(hwFrom) || !IsWindowCurrentProcessThread(hwTo)) return FALSE;

	//get text size and allocate buffer
	LRESULT lBufLen = SendMessage(hwFrom, WM_GETTEXTLENGTH, NULL, NULL) + 1;//terminating null is not counted
	LPTSTR pszBuf = (LPTSTR)LocalAlloc(LPTR, lBufLen*sizeof(TCHAR));
	if (pszBuf == NULL)
	{
		DBGTRACE2("LocalAlloc failed\n");
		return FALSE;
	}
	if (SendMessage(hwFrom, WM_GETTEXT, lBufLen, (LPARAM)pszBuf) == (lBufLen-1)) SendMessage(hwTo, WM_SETTEXT, NULL, (LPARAM)pszBuf);
	LocalFree(pszBuf);
return TRUE;
}

BOOL IsWindowClass(HWND hWnd, LPCTSTR pszClsName)
{
	TCHAR strBuf[256];
return ((GetClassName(hWnd, strBuf, 256) && lstrcmp(strBuf, pszClsName)==0));
}

BOOL IsWindowMaximized(HWND hWnd)
{
	if (NULL==hWnd) return FALSE;
	WINDOWPLACEMENT wpl;
	wpl.length=sizeof(WINDOWPLACEMENT);
	wpl.showCmd=SW_MAX;
	::GetWindowPlacement(hWnd, &wpl);
return (SW_SHOWMAXIMIZED==wpl.showCmd);
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

#endif//_HELPERS_9EF22F0D_46AB_423F_BA5A_D1BD482453D1_
