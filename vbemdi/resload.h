#ifndef _RESLOAD_533AC41F_6985_46F3_B624_A917ADE10797_
#define _RESLOAD_533AC41F_6985_46F3_B624_A917ADE10797_
#include <windows.h>

//http://blogs.msdn.com/b/oldnewthing/archive/2004/01/30/65013.aspx
//this function can only be used if resources are compiled with /n switch:
// rc.exe /n
inline LPCWSTR LoadStringLCNull(HINSTANCE hResInstance, UINT uID, WORD wLangID)
{
	if (HRSRC hrsrc=FindResourceEx(hResInstance, RT_STRING, MAKEINTRESOURCE(uID/16 + 1), wLangID))
	{
		if (HGLOBAL hglob=LoadResource(hResInstance, hrsrc))
		{
			if (LPWSTR pwsz=(LPWSTR)LockResource(hglob))
			{
				for (wLangID=0; wLangID<(uID & 15); wLangID++)//reuse wLangID
				{
					pwsz += 1+(UINT)*pwsz;
				}
//?test nonexisting uID
				if ((UINT)*pwsz) return ++pwsz;//0-length string returns null
			}
		}
	}
return NULL;
}

//similar to LoadString
inline UINT LoadStringLC(HINSTANCE hResInstance, UINT uID, LPTSTR pwBuffer, UINT nBufferMax, WORD wLangID)
{
	pwBuffer[0]=L'\0';
	if (HRSRC hrsrc=FindResourceEx(hResInstance, RT_STRING, MAKEINTRESOURCE(uID/16 + 1), wLangID))
	{
		if (HGLOBAL hglob=LoadResource(hResInstance, hrsrc))
		{
			if (LPWSTR pwsz=(LPWSTR)LockResource(hglob))
			{
				for (wLangID=0; wLangID<(uID & 15); wLangID++)//reuse wLangID
				{
					pwsz += 1+(UINT)*pwsz;
				}
				if ((UINT)*pwsz)
				{
					//alternatively -> use rc.exe /n switch and LoadStringLCNull()
					nBufferMax--;//reuse var
					nBufferMax=min((UINT)*pwsz, nBufferMax);
					CopyMemory(pwBuffer, ++pwsz, sizeof(WCHAR)*nBufferMax);
					pwBuffer[nBufferMax]=L'\0';
				}
				return nBufferMax;
			}
		}
	}
return 0;
}


inline HMENU LoadMenuLC(HINSTANCE hResInstance, UINT uID, WORD wLangID)
{
	HMENU hMenu = NULL;
	if (HRSRC hResource = FindResourceEx(hResInstance, RT_MENU, MAKEINTRESOURCE(uID), wLangID))
	{
		if (HGLOBAL hGlobal = LoadResource(hResInstance, hResource))
		{
			if (LPVOID lpMenuTemplate = (LPVOID)LockResource(hGlobal))
			{
				hMenu = LoadMenuIndirect(lpMenuTemplate);
			}
		}
	}
return hMenu;
}

#endif//_RESLOAD_533AC41F_6985_46F3_B624_A917ADE10797_
