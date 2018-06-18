#include <tchar.h>
#ifndef _DEBUGTRACE_8A7AC67B_B017_4AAB_BBA7_1EE09FEDC416_
#define _DEBUGTRACE_8A7AC67B_B017_4AAB_BBA7_1EE09FEDC416_
#ifdef _DEBUG

#define DBGTRACE(msg, ...) DbgTrace(0, "", msg, __VA_ARGS__)
#define DBGTRACE2(msg, ...) DbgTrace(__LINE__, __FILE__, msg, __VA_ARGS__)

void DbgTrace(int line, const char* fileName, const char* msg, ...)
{
    va_list args;
    char buffer[256] = { 0 };
	if (line)
	{
		/*_stprintf_s*/sprintf_s(buffer, "%s(%d) : ", (strrchr(fileName, '\\') ? strrchr(fileName, '\\') + 1 : fileName), line);
		OutputDebugStringA(buffer);
	}

    // retrieve the variable arguments
    va_start(args, msg);
    /*_vstprintf_s*/vsprintf_s(buffer, msg, args);
    OutputDebugStringA(buffer);
    va_end(args);
}

#else
#define DBGTRACE(msg, ...)
#define DBGTRACE2(msg, ...)
#endif//_DEBUG


char* DbgGetWindowsMessageNameA(UINT message)
{
	switch(message)
	{
		case 0x00: return "WM_NULL";
		case 0x01: return "WM_CREATE";
		case 0x02: return "WM_DESTROY";
		case 0x03: return "WM_MOVE";
		case 0x05: return "WM_SIZE";
		case 0x06: return "WM_ACTIVATE";
		case 0x07: return "WM_SETFOCUS";
		case 0x08: return "WM_KILLFOCUS";
		case 0x0A: return "WM_ENABLE";
		case 0x0B: return "WM_SETREDRAW";
		case 0x0C: return "WM_SETTEXT";
		case 0x0D: return "WM_GETTEXT";
		case 0x0E: return "WM_GETTEXTLENGTH";
		case 0x0F: return "WM_PAINT";
		case 0x10: return "WM_CLOSE";
		case 0x11: return "WM_QUERYENDSESSION";
		case 0x12: return "WM_QUIT";
		case 0x13: return "WM_QUERYOPEN";
		case 0x14: return "WM_ERASEBKGND";
		case 0x15: return "WM_SYSCOLORCHANGE";
		case 0x16: return "WM_ENDSESSION";
		case 0x17: return "WM_SYSTEMERROR";
		case 0x18: return "WM_SHOWWINDOW";
		case 0x19: return "WM_CTLCOLOR";
		//case 0x1A: return "WM_WININICHANGE";
		case 0x1A: return "WM_SETTINGCHANGE";
		case 0x1B: return "WM_DEVMODECHANGE";
		case 0x1C: return "WM_ACTIVATEAPP";
		case 0x1D: return "WM_FONTCHANGE";
		case 0x1E: return "WM_TIMECHANGE";
		case 0x1F: return "WM_CANCELMODE";
		case 0x20: return "WM_SETCURSOR";
		case 0x21: return "WM_MOUSEACTIVATE";
		case 0x22: return "WM_CHILDACTIVATE";
		case 0x23: return "WM_QUEUESYNC";
		case 0x24: return "WM_GETMINMAXINFO";
		case 0x26: return "WM_PAINTICON";
		case 0x27: return "WM_ICONERASEBKGND";
		case 0x28: return "WM_NEXTDLGCTL";
		case 0x2A: return "WM_SPOOLERSTATUS";
		case 0x2B: return "WM_DRAWITEM";
		case 0x2C: return "WM_MEASUREITEM";
		case 0x2D: return "WM_DELETEITEM";
		case 0x2E: return "WM_VKEYTOITEM";
		case 0x2F: return "WM_CHARTOITEM";
		case 0x30: return "WM_SETFONT";
		case 0x31: return "WM_GETFONT";
		case 0x32: return "WM_SETHOTKEY";
		case 0x33: return "WM_GETHOTKEY";
		case 0x37: return "WM_QUERYDRAGICON";
		case 0x39: return "WM_COMPAREITEM";
		case 0x41: return "WM_COMPACTING";
		case 0x46: return "WM_WINDOWPOSCHANGING";
		case 0x47: return "WM_WINDOWPOSCHANGED";
		case 0x48: return "WM_POWER";
		case 0x4A: return "WM_COPYDATA";
		case 0x4B: return "WM_CANCELJOURNAL";
		case 0x4E: return "WM_NOTIFY";
		case 0x50: return "WM_INPUTLANGCHANGEREQUEST";
		case 0x51: return "WM_INPUTLANGCHANGE";
		case 0x52: return "WM_TCARD";
		case 0x53: return "WM_HELP";
		case 0x54: return "WM_USERCHANGED";
		case 0x55: return "WM_NOTIFYFORMAT";
		case 0x7B: return "WM_CONTEXTMENU";
		case 0x7C: return "WM_STYLECHANGING";
		case 0x7D: return "WM_STYLECHANGED";
		case 0x7E: return "WM_DISPLAYCHANGE";
		case 0x7F: return "WM_GETICON";
		case 0x80: return "WM_SETICON";
		case 0x81: return "WM_NCCREATE";
		case 0x82: return "WM_NCDESTROY";
		case 0x83: return "WM_NCCALCSIZE";
		case 0x84: return "WM_NCHITTEST";
		case 0x85: return "WM_NCPAINT";
		case 0x86: return "WM_NCACTIVATE";
		case 0x87: return "WM_GETDLGCODE";
		case 0xA0: return "WM_NCMOUSEMOVE";
		case 0xA1: return "WM_NCLBUTTONDOWN";
		case 0xA2: return "WM_NCLBUTTONUP";
		case 0xA3: return "WM_NCLBUTTONDBLCLK";
		case 0xA4: return "WM_NCRBUTTONDOWN";
		case 0xA5: return "WM_NCRBUTTONUP";
		case 0xA6: return "WM_NCRBUTTONDBLCLK";
		case 0xA7: return "WM_NCMBUTTONDOWN";
		case 0xA8: return "WM_NCMBUTTONUP";
		case 0xA9: return "WM_NCMBUTTONDBLCLK";
		//case 0x100: return "WM_KEYFIRST";
		case 0x100: return "WM_KEYDOWN";
		case 0x101: return "WM_KEYUP";
		case 0x102: return "WM_CHAR";
		case 0x103: return "WM_DEADCHAR";
		case 0x104: return "WM_SYSKEYDOWN";
		case 0x105: return "WM_SYSKEYUP";
		case 0x106: return "WM_SYSCHAR";
		case 0x107: return "WM_SYSDEADCHAR";
		case 0x108: return "WM_KEYLAST";
		case 0x10D: return "WM_IME_STARTCOMPOSITION";
		case 0x10E: return "WM_IME_ENDCOMPOSITION";
		case 0x10F: return "WM_IME_COMPOSITION";
		//case 0x10F: return "WM_IME_KEYLAST";
		case 0x110: return "WM_INITDIALOG";
		case 0x111: return "WM_COMMAND";
		case 0x112: return "WM_SYSCOMMAND";
		case 0x113: return "WM_TIMER";
		case 0x114: return "WM_HSCROLL";
		case 0x115: return "WM_VSCROLL";
		case 0x116: return "WM_INITMENU";
		case 0x117: return "WM_INITMENUPOPUP";
		case 0x11F: return "WM_MENUSELECT";
		case 0x120: return "WM_MENUCHAR";
		case 0x121: return "WM_ENTERIDLE";
		case 0x132: return "WM_CTLCOLORMSGBOX";
		case 0x133: return "WM_CTLCOLOREDIT";
		case 0x134: return "WM_CTLCOLORLISTBOX";
		case 0x135: return "WM_CTLCOLORBTN";
		case 0x136: return "WM_CTLCOLORDLG";
		case 0x137: return "WM_CTLCOLORSCROLLBAR";
		case 0x138: return "WM_CTLCOLORSTATIC";
		//case 0x200: return "WM_MOUSEFIRST";
		case 0x200: return "WM_MOUSEMOVE";
		case 0x201: return "WM_LBUTTONDOWN";
		case 0x202: return "WM_LBUTTONUP";
		case 0x203: return "WM_LBUTTONDBLCLK";
		case 0x204: return "WM_RBUTTONDOWN";
		case 0x205: return "WM_RBUTTONUP";
		case 0x206: return "WM_RBUTTONDBLCLK";
		case 0x207: return "WM_MBUTTONDOWN";
		case 0x208: return "WM_MBUTTONUP";
		case 0x209: return "WM_MBUTTONDBLCLK";
		case 0x20A: return "WM_MOUSEWHEEL";
		case 0x20E: return "WM_MOUSEHWHEEL";
		case 0x210: return "WM_PARENTNOTIFY";
		case 0x211: return "WM_ENTERMENULOOP";
		case 0x212: return "WM_EXITMENULOOP";
		case 0x213: return "WM_NEXTMENU";
		case 0x214: return "WM_SIZING";
		case 0x215: return "WM_CAPTURECHANGED";
		case 0x216: return "WM_MOVING";
		case 0x218: return "WM_POWERBROADCAST";
		case 0x219: return "WM_DEVICECHANGE";
		case 0x220: return "WM_MDICREATE";
		case 0x221: return "WM_MDIDESTROY";
		case 0x222: return "WM_MDIACTIVATE";
		case 0x223: return "WM_MDIRESTORE";
		case 0x224: return "WM_MDINEXT";
		case 0x225: return "WM_MDIMAXIMIZE";
		case 0x226: return "WM_MDITILE";
		case 0x227: return "WM_MDICASCADE";
		case 0x228: return "WM_MDIICONARRANGE";
		case 0x229: return "WM_MDIGETACTIVE";
		case 0x230: return "WM_MDISETMENU";
		case 0x231: return "WM_ENTERSIZEMOVE";
		case 0x232: return "WM_EXITSIZEMOVE";
		case 0x233: return "WM_DROPFILES";
		case 0x234: return "WM_MDIREFRESHMENU";
		case 0x281: return "WM_IME_SETCONTEXT";
		case 0x282: return "WM_IME_NOTIFY";
		case 0x283: return "WM_IME_CONTROL";
		case 0x284: return "WM_IME_COMPOSITIONFULL";
		case 0x285: return "WM_IME_SELECT";
		case 0x286: return "WM_IME_CHAR";
		case 0x290: return "WM_IME_KEYDOWN";
		case 0x291: return "WM_IME_KEYUP";
		case 0x2A1: return "WM_MOUSEHOVER";
		case 0x2A2: return "WM_NCMOUSELEAVE";
		case 0x2A3: return "WM_MOUSELEAVE";
		case 0x300: return "WM_CUT";
		case 0x301: return "WM_COPY";
		case 0x302: return "WM_PASTE";
		case 0x303: return "WM_CLEAR";
		case 0x304: return "WM_UNDO";
		case 0x305: return "WM_RENDERFORMAT";
		case 0x306: return "WM_RENDERALLFORMATS";
		case 0x307: return "WM_DESTROYCLIPBOARD";
		case 0x308: return "WM_DRAWCLIPBOARD";
		case 0x309: return "WM_PAINTCLIPBOARD";
		case 0x30A: return "WM_VSCROLLCLIPBOARD";
		case 0x30B: return "WM_SIZECLIPBOARD";
		case 0x30C: return "WM_ASKCBFORMATNAME";
		case 0x30D: return "WM_CHANGECBCHAIN";
		case 0x30E: return "WM_HSCROLLCLIPBOARD";
		case 0x30F: return "WM_QUERYNEWPALETTE";
		case 0x310: return "WM_PALETTEISCHANGING";
		case 0x311: return "WM_PALETTECHANGED";
		case 0x312: return "WM_HOTKEY";
		case 0x317: return "WM_PRINT";
		case 0x318: return "WM_PRINTCLIENT";
		case 0x358: return "WM_HANDHELDFIRST";
		case 0x35F: return "WM_HANDHELDLAST";
		case 0x380: return "WM_PENWINFIRST";
		case 0x38F: return "WM_PENWINLAST";
		case 0x390: return "WM_COALESCE_FIRST";
		case 0x39F: return "WM_COALESCE_LAST";
		//case 0x3E0: return "WM_DDE_FIRST";
		case 0x3E0: return "WM_DDE_INITIATE";
		case 0x3E1: return "WM_DDE_TERMINATE";
		case 0x3E2: return "WM_DDE_ADVISE";
		case 0x3E3: return "WM_DDE_UNADVISE";
		case 0x3E4: return "WM_DDE_ACK";
		case 0x3E5: return "WM_DDE_DATA";
		case 0x3E6: return "WM_DDE_REQUEST";
		case 0x3E7: return "WM_DDE_POKE";
		case 0x3E8: return "WM_DDE_EXECUTE";
		//case 0x3E8: return "WM_DDE_LAST";
		case 0x400: return "WM_USER";
		case 0x8000: return "WM_APP";
		default: return "unknown message";
	}
//	return "unknown message";
}

#endif//_DEBUGTRACE_8A7AC67B_B017_4AAB_BBA7_1EE09FEDC416_
