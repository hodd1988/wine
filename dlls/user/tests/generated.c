/* File generated automatically from tools/winapi/test.dat; do not edit! */
/* This file can be copied, modified and distributed without restriction. */

/*
 * Unit tests for data structure packing
 */

#define WINVER 0x0501
#define _WIN32_WINNT 0x0501

#define WINE_NOWINSOCK

#include "windows.h"

#include "wine/test.h"

/***********************************************************************
 * Compability macros
 */

#define DWORD_PTR UINT_PTR
#define LONG_PTR INT_PTR
#define ULONG_PTR UINT_PTR

/***********************************************************************
 * Windows API extension
 */

#if (_MSC_VER >= 1300) && defined(__cplusplus)
# define FIELD_ALIGNMENT(type, field) __alignof(((type*)0)->field)
#elif defined(__GNUC__)
# define FIELD_ALIGNMENT(type, field) __alignof__(((type*)0)->field)
#else
/* FIXME: Not sure if is possible to do without compiler extension */
#endif

/***********************************************************************
 * Test helper macros
 */

#ifdef FIELD_ALIGNMENT
# define TEST_FIELD_ALIGNMENT(type, field, align) \
   ok(FIELD_ALIGNMENT(type, field) == align, \
       "FIELD_ALIGNMENT(" #type ", " #field ") == %d (expected " #align ")", \
           FIELD_ALIGNMENT(type, field))
#else
# define TEST_FIELD_ALIGNMENT(type, field, align) do { } while (0)
#endif

#define TEST_FIELD_OFFSET(type, field, offset) \
    ok(FIELD_OFFSET(type, field) == offset, \
        "FIELD_OFFSET(" #type ", " #field ") == %ld (expected " #offset ")", \
             FIELD_OFFSET(type, field))

#define TEST_TYPE_ALIGNMENT(type, align) \
    ok(TYPE_ALIGNMENT(type) == align, "TYPE_ALIGNMENT(" #type ") == %d (expected " #align ")", TYPE_ALIGNMENT(type))

#define TEST_TYPE_SIZE(type, size) \
    ok(sizeof(type) == size, "sizeof(" #type ") == %d (expected " #size ")", sizeof(type))

/***********************************************************************
 * Test macros
 */

#define TEST_FIELD(type, field_type, field_name, field_offset, field_size, field_align) \
  TEST_TYPE_SIZE(field_type, field_size); \
  TEST_FIELD_ALIGNMENT(type, field_name, field_align); \
  TEST_FIELD_OFFSET(type, field_name, field_offset); \

#define TEST_TYPE(type, size, align) \
  TEST_TYPE_ALIGNMENT(type, align); \
  TEST_TYPE_SIZE(type, size)

void test_pack(void)
{
    /* ACCEL (pack 4) */
    TEST_TYPE(ACCEL, 6, 2);
    TEST_FIELD(ACCEL, BYTE, fVirt, 0, 1, 1);
    TEST_FIELD(ACCEL, WORD, key, 2, 2, 2);
    TEST_FIELD(ACCEL, WORD, cmd, 4, 2, 2);

    /* ACCESSTIMEOUT (pack 4) */
    TEST_TYPE(ACCESSTIMEOUT, 12, 4);
    TEST_FIELD(ACCESSTIMEOUT, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(ACCESSTIMEOUT, DWORD, dwFlags, 4, 4, 4);
    TEST_FIELD(ACCESSTIMEOUT, DWORD, iTimeOutMSec, 8, 4, 4);

    /* ANIMATIONINFO (pack 4) */
    TEST_TYPE(ANIMATIONINFO, 8, 4);
    TEST_FIELD(ANIMATIONINFO, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(ANIMATIONINFO, INT, iMinAnimate, 4, 4, 4);

    /* CBTACTIVATESTRUCT (pack 4) */
    TEST_TYPE(CBTACTIVATESTRUCT, 8, 4);
    TEST_FIELD(CBTACTIVATESTRUCT, BOOL, fMouse, 0, 4, 4);
    TEST_FIELD(CBTACTIVATESTRUCT, HWND, hWndActive, 4, 4, 4);

    /* CBT_CREATEWNDA (pack 4) */
    TEST_TYPE(CBT_CREATEWNDA, 8, 4);
    TEST_FIELD(CBT_CREATEWNDA, CREATESTRUCTA *, lpcs, 0, 4, 4);
    TEST_FIELD(CBT_CREATEWNDA, HWND, hwndInsertAfter, 4, 4, 4);

    /* CBT_CREATEWNDW (pack 4) */
    TEST_TYPE(CBT_CREATEWNDW, 8, 4);
    TEST_FIELD(CBT_CREATEWNDW, CREATESTRUCTW *, lpcs, 0, 4, 4);
    TEST_FIELD(CBT_CREATEWNDW, HWND, hwndInsertAfter, 4, 4, 4);

    /* CLIENTCREATESTRUCT (pack 4) */
    TEST_TYPE(CLIENTCREATESTRUCT, 8, 4);
    TEST_FIELD(CLIENTCREATESTRUCT, HMENU, hWindowMenu, 0, 4, 4);
    TEST_FIELD(CLIENTCREATESTRUCT, UINT, idFirstChild, 4, 4, 4);

    /* COMPAREITEMSTRUCT (pack 4) */
    TEST_TYPE(COMPAREITEMSTRUCT, 32, 4);
    TEST_FIELD(COMPAREITEMSTRUCT, UINT, CtlType, 0, 4, 4);
    TEST_FIELD(COMPAREITEMSTRUCT, UINT, CtlID, 4, 4, 4);
    TEST_FIELD(COMPAREITEMSTRUCT, HWND, hwndItem, 8, 4, 4);
    TEST_FIELD(COMPAREITEMSTRUCT, UINT, itemID1, 12, 4, 4);
    TEST_FIELD(COMPAREITEMSTRUCT, DWORD, itemData1, 16, 4, 4);
    TEST_FIELD(COMPAREITEMSTRUCT, UINT, itemID2, 20, 4, 4);
    TEST_FIELD(COMPAREITEMSTRUCT, DWORD, itemData2, 24, 4, 4);
    TEST_FIELD(COMPAREITEMSTRUCT, DWORD, dwLocaleId, 28, 4, 4);

    /* COPYDATASTRUCT (pack 4) */
    TEST_TYPE(COPYDATASTRUCT, 12, 4);
    TEST_FIELD(COPYDATASTRUCT, DWORD, dwData, 0, 4, 4);
    TEST_FIELD(COPYDATASTRUCT, DWORD, cbData, 4, 4, 4);
    TEST_FIELD(COPYDATASTRUCT, LPVOID, lpData, 8, 4, 4);

    /* CREATESTRUCTA (pack 4) */
    TEST_TYPE(CREATESTRUCTA, 48, 4);
    TEST_FIELD(CREATESTRUCTA, LPVOID, lpCreateParams, 0, 4, 4);
    TEST_FIELD(CREATESTRUCTA, HINSTANCE, hInstance, 4, 4, 4);
    TEST_FIELD(CREATESTRUCTA, HMENU, hMenu, 8, 4, 4);
    TEST_FIELD(CREATESTRUCTA, HWND, hwndParent, 12, 4, 4);
    TEST_FIELD(CREATESTRUCTA, INT, cy, 16, 4, 4);
    TEST_FIELD(CREATESTRUCTA, INT, cx, 20, 4, 4);
    TEST_FIELD(CREATESTRUCTA, INT, y, 24, 4, 4);
    TEST_FIELD(CREATESTRUCTA, INT, x, 28, 4, 4);
    TEST_FIELD(CREATESTRUCTA, LONG, style, 32, 4, 4);
    TEST_FIELD(CREATESTRUCTA, LPCSTR, lpszName, 36, 4, 4);
    TEST_FIELD(CREATESTRUCTA, LPCSTR, lpszClass, 40, 4, 4);
    TEST_FIELD(CREATESTRUCTA, DWORD, dwExStyle, 44, 4, 4);

    /* CREATESTRUCTW (pack 4) */
    TEST_TYPE(CREATESTRUCTW, 48, 4);
    TEST_FIELD(CREATESTRUCTW, LPVOID, lpCreateParams, 0, 4, 4);
    TEST_FIELD(CREATESTRUCTW, HINSTANCE, hInstance, 4, 4, 4);
    TEST_FIELD(CREATESTRUCTW, HMENU, hMenu, 8, 4, 4);
    TEST_FIELD(CREATESTRUCTW, HWND, hwndParent, 12, 4, 4);
    TEST_FIELD(CREATESTRUCTW, INT, cy, 16, 4, 4);
    TEST_FIELD(CREATESTRUCTW, INT, cx, 20, 4, 4);
    TEST_FIELD(CREATESTRUCTW, INT, y, 24, 4, 4);
    TEST_FIELD(CREATESTRUCTW, INT, x, 28, 4, 4);
    TEST_FIELD(CREATESTRUCTW, LONG, style, 32, 4, 4);
    TEST_FIELD(CREATESTRUCTW, LPCWSTR, lpszName, 36, 4, 4);
    TEST_FIELD(CREATESTRUCTW, LPCWSTR, lpszClass, 40, 4, 4);
    TEST_FIELD(CREATESTRUCTW, DWORD, dwExStyle, 44, 4, 4);

    /* CURSORINFO (pack 4) */
    TEST_TYPE(CURSORINFO, 20, 4);
    TEST_FIELD(CURSORINFO, DWORD, cbSize, 0, 4, 4);
    TEST_FIELD(CURSORINFO, DWORD, flags, 4, 4, 4);
    TEST_FIELD(CURSORINFO, HCURSOR, hCursor, 8, 4, 4);
    TEST_FIELD(CURSORINFO, POINT, ptScreenPos, 12, 8, 4);

    /* CWPRETSTRUCT (pack 4) */
    TEST_TYPE(CWPRETSTRUCT, 20, 4);
    TEST_FIELD(CWPRETSTRUCT, LRESULT, lResult, 0, 4, 4);
    TEST_FIELD(CWPRETSTRUCT, LPARAM, lParam, 4, 4, 4);
    TEST_FIELD(CWPRETSTRUCT, WPARAM, wParam, 8, 4, 4);
    TEST_FIELD(CWPRETSTRUCT, DWORD, message, 12, 4, 4);
    TEST_FIELD(CWPRETSTRUCT, HWND, hwnd, 16, 4, 4);

    /* CWPSTRUCT (pack 4) */
    TEST_TYPE(CWPSTRUCT, 16, 4);
    TEST_FIELD(CWPSTRUCT, LPARAM, lParam, 0, 4, 4);
    TEST_FIELD(CWPSTRUCT, WPARAM, wParam, 4, 4, 4);
    TEST_FIELD(CWPSTRUCT, UINT, message, 8, 4, 4);
    TEST_FIELD(CWPSTRUCT, HWND, hwnd, 12, 4, 4);

    /* DEBUGHOOKINFO (pack 4) */
    TEST_TYPE(DEBUGHOOKINFO, 20, 4);
    TEST_FIELD(DEBUGHOOKINFO, DWORD, idThread, 0, 4, 4);
    TEST_FIELD(DEBUGHOOKINFO, DWORD, idThreadInstaller, 4, 4, 4);
    TEST_FIELD(DEBUGHOOKINFO, LPARAM, lParam, 8, 4, 4);
    TEST_FIELD(DEBUGHOOKINFO, WPARAM, wParam, 12, 4, 4);
    TEST_FIELD(DEBUGHOOKINFO, INT, code, 16, 4, 4);

    /* DELETEITEMSTRUCT (pack 4) */
    TEST_TYPE(DELETEITEMSTRUCT, 20, 4);
    TEST_FIELD(DELETEITEMSTRUCT, UINT, CtlType, 0, 4, 4);
    TEST_FIELD(DELETEITEMSTRUCT, UINT, CtlID, 4, 4, 4);
    TEST_FIELD(DELETEITEMSTRUCT, UINT, itemID, 8, 4, 4);
    TEST_FIELD(DELETEITEMSTRUCT, HWND, hwndItem, 12, 4, 4);
    TEST_FIELD(DELETEITEMSTRUCT, DWORD, itemData, 16, 4, 4);

    /* DLGITEMTEMPLATE (pack 2) */
    TEST_TYPE(DLGITEMTEMPLATE, 18, 2);
    TEST_FIELD(DLGITEMTEMPLATE, DWORD, style, 0, 4, 2);
    TEST_FIELD(DLGITEMTEMPLATE, DWORD, dwExtendedStyle, 4, 4, 2);
    TEST_FIELD(DLGITEMTEMPLATE, short, x, 8, 2, 2);
    TEST_FIELD(DLGITEMTEMPLATE, short, y, 10, 2, 2);
    TEST_FIELD(DLGITEMTEMPLATE, short, cx, 12, 2, 2);
    TEST_FIELD(DLGITEMTEMPLATE, short, cy, 14, 2, 2);
    TEST_FIELD(DLGITEMTEMPLATE, WORD, id, 16, 2, 2);

    /* DLGTEMPLATE (pack 2) */
    TEST_TYPE(DLGTEMPLATE, 18, 2);
    TEST_FIELD(DLGTEMPLATE, DWORD, style, 0, 4, 2);
    TEST_FIELD(DLGTEMPLATE, DWORD, dwExtendedStyle, 4, 4, 2);
    TEST_FIELD(DLGTEMPLATE, WORD, cdit, 8, 2, 2);
    TEST_FIELD(DLGTEMPLATE, short, x, 10, 2, 2);
    TEST_FIELD(DLGTEMPLATE, short, y, 12, 2, 2);
    TEST_FIELD(DLGTEMPLATE, short, cx, 14, 2, 2);
    TEST_FIELD(DLGTEMPLATE, short, cy, 16, 2, 2);

    /* DRAWTEXTPARAMS (pack 4) */
    TEST_TYPE(DRAWTEXTPARAMS, 20, 4);
    TEST_FIELD(DRAWTEXTPARAMS, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(DRAWTEXTPARAMS, INT, iTabLength, 4, 4, 4);
    TEST_FIELD(DRAWTEXTPARAMS, INT, iLeftMargin, 8, 4, 4);
    TEST_FIELD(DRAWTEXTPARAMS, INT, iRightMargin, 12, 4, 4);
    TEST_FIELD(DRAWTEXTPARAMS, UINT, uiLengthDrawn, 16, 4, 4);

    /* EVENTMSG (pack 4) */
    TEST_TYPE(EVENTMSG, 20, 4);
    TEST_FIELD(EVENTMSG, UINT, message, 0, 4, 4);
    TEST_FIELD(EVENTMSG, UINT, paramL, 4, 4, 4);
    TEST_FIELD(EVENTMSG, UINT, paramH, 8, 4, 4);
    TEST_FIELD(EVENTMSG, DWORD, time, 12, 4, 4);
    TEST_FIELD(EVENTMSG, HWND, hwnd, 16, 4, 4);

    /* FILTERKEYS (pack 4) */
    TEST_TYPE(FILTERKEYS, 24, 4);
    TEST_FIELD(FILTERKEYS, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(FILTERKEYS, DWORD, dwFlags, 4, 4, 4);
    TEST_FIELD(FILTERKEYS, DWORD, iWaitMSec, 8, 4, 4);
    TEST_FIELD(FILTERKEYS, DWORD, iDelayMSec, 12, 4, 4);
    TEST_FIELD(FILTERKEYS, DWORD, iRepeatMSec, 16, 4, 4);
    TEST_FIELD(FILTERKEYS, DWORD, iBounceMSec, 20, 4, 4);

    /* HARDWAREHOOKSTRUCT (pack 4) */
    TEST_TYPE(HARDWAREHOOKSTRUCT, 16, 4);
    TEST_FIELD(HARDWAREHOOKSTRUCT, HWND, hwnd, 0, 4, 4);
    TEST_FIELD(HARDWAREHOOKSTRUCT, UINT, message, 4, 4, 4);
    TEST_FIELD(HARDWAREHOOKSTRUCT, WPARAM, wParam, 8, 4, 4);
    TEST_FIELD(HARDWAREHOOKSTRUCT, LPARAM, lParam, 12, 4, 4);

    /* HARDWAREINPUT (pack 4) */
    TEST_TYPE(HARDWAREINPUT, 8, 4);
    TEST_FIELD(HARDWAREINPUT, DWORD, uMsg, 0, 4, 4);
    TEST_FIELD(HARDWAREINPUT, WORD, wParamL, 4, 2, 2);
    TEST_FIELD(HARDWAREINPUT, WORD, wParamH, 6, 2, 2);

    /* HELPINFO (pack 4) */
    TEST_TYPE(HELPINFO, 28, 4);
    TEST_FIELD(HELPINFO, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(HELPINFO, INT, iContextType, 4, 4, 4);
    TEST_FIELD(HELPINFO, INT, iCtrlId, 8, 4, 4);
    TEST_FIELD(HELPINFO, HANDLE, hItemHandle, 12, 4, 4);
    TEST_FIELD(HELPINFO, DWORD_PTR, dwContextId, 16, 4, 4);
    TEST_FIELD(HELPINFO, POINT, MousePos, 20, 8, 4);

    /* HELPWININFOA (pack 4) */
    TEST_TYPE(HELPWININFOA, 28, 4);
    TEST_FIELD(HELPWININFOA, int, wStructSize, 0, 4, 4);
    TEST_FIELD(HELPWININFOA, int, x, 4, 4, 4);
    TEST_FIELD(HELPWININFOA, int, y, 8, 4, 4);
    TEST_FIELD(HELPWININFOA, int, dx, 12, 4, 4);
    TEST_FIELD(HELPWININFOA, int, dy, 16, 4, 4);
    TEST_FIELD(HELPWININFOA, int, wMax, 20, 4, 4);
    TEST_FIELD(HELPWININFOA, CHAR[2], rgchMember, 24, 2, 1);

    /* HELPWININFOW (pack 4) */
    TEST_TYPE(HELPWININFOW, 28, 4);
    TEST_FIELD(HELPWININFOW, int, wStructSize, 0, 4, 4);
    TEST_FIELD(HELPWININFOW, int, x, 4, 4, 4);
    TEST_FIELD(HELPWININFOW, int, y, 8, 4, 4);
    TEST_FIELD(HELPWININFOW, int, dx, 12, 4, 4);
    TEST_FIELD(HELPWININFOW, int, dy, 16, 4, 4);
    TEST_FIELD(HELPWININFOW, int, wMax, 20, 4, 4);
    TEST_FIELD(HELPWININFOW, WCHAR[2], rgchMember, 24, 4, 2);

    /* HIGHCONTRASTA (pack 4) */
    TEST_TYPE(HIGHCONTRASTA, 12, 4);
    TEST_FIELD(HIGHCONTRASTA, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(HIGHCONTRASTA, DWORD, dwFlags, 4, 4, 4);
    TEST_FIELD(HIGHCONTRASTA, LPSTR, lpszDefaultScheme, 8, 4, 4);

    /* HIGHCONTRASTW (pack 4) */
    TEST_TYPE(HIGHCONTRASTW, 12, 4);
    TEST_FIELD(HIGHCONTRASTW, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(HIGHCONTRASTW, DWORD, dwFlags, 4, 4, 4);
    TEST_FIELD(HIGHCONTRASTW, LPWSTR, lpszDefaultScheme, 8, 4, 4);

    /* ICONINFO (pack 4) */
    TEST_TYPE(ICONINFO, 20, 4);
    TEST_FIELD(ICONINFO, BOOL, fIcon, 0, 4, 4);
    TEST_FIELD(ICONINFO, DWORD, xHotspot, 4, 4, 4);
    TEST_FIELD(ICONINFO, DWORD, yHotspot, 8, 4, 4);
    TEST_FIELD(ICONINFO, HBITMAP, hbmMask, 12, 4, 4);
    TEST_FIELD(ICONINFO, HBITMAP, hbmColor, 16, 4, 4);

    /* ICONMETRICSA (pack 4) */
    TEST_TYPE(ICONMETRICSA, 76, 4);
    TEST_FIELD(ICONMETRICSA, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(ICONMETRICSA, int, iHorzSpacing, 4, 4, 4);
    TEST_FIELD(ICONMETRICSA, int, iVertSpacing, 8, 4, 4);
    TEST_FIELD(ICONMETRICSA, int, iTitleWrap, 12, 4, 4);
    TEST_FIELD(ICONMETRICSA, LOGFONTA, lfFont, 16, 60, 4);

    /* ICONMETRICSW (pack 4) */
    TEST_TYPE(ICONMETRICSW, 108, 4);
    TEST_FIELD(ICONMETRICSW, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(ICONMETRICSW, int, iHorzSpacing, 4, 4, 4);
    TEST_FIELD(ICONMETRICSW, int, iVertSpacing, 8, 4, 4);
    TEST_FIELD(ICONMETRICSW, int, iTitleWrap, 12, 4, 4);
    TEST_FIELD(ICONMETRICSW, LOGFONTW, lfFont, 16, 92, 4);

    /* INPUT (pack 4) */
    TEST_FIELD(INPUT, DWORD, type, 0, 4, 4);

    /* KBDLLHOOKSTRUCT (pack 4) */
    TEST_TYPE(KBDLLHOOKSTRUCT, 20, 4);
    TEST_FIELD(KBDLLHOOKSTRUCT, DWORD, vkCode, 0, 4, 4);
    TEST_FIELD(KBDLLHOOKSTRUCT, DWORD, scanCode, 4, 4, 4);
    TEST_FIELD(KBDLLHOOKSTRUCT, DWORD, flags, 8, 4, 4);
    TEST_FIELD(KBDLLHOOKSTRUCT, DWORD, time, 12, 4, 4);
    TEST_FIELD(KBDLLHOOKSTRUCT, ULONG_PTR, dwExtraInfo, 16, 4, 4);

    /* KEYBDINPUT (pack 4) */
    TEST_TYPE(KEYBDINPUT, 16, 4);
    TEST_FIELD(KEYBDINPUT, WORD, wVk, 0, 2, 2);
    TEST_FIELD(KEYBDINPUT, WORD, wScan, 2, 2, 2);
    TEST_FIELD(KEYBDINPUT, DWORD, dwFlags, 4, 4, 4);
    TEST_FIELD(KEYBDINPUT, DWORD, time, 8, 4, 4);
    TEST_FIELD(KEYBDINPUT, ULONG_PTR, dwExtraInfo, 12, 4, 4);

    /* MDICREATESTRUCTA (pack 4) */
    TEST_TYPE(MDICREATESTRUCTA, 36, 4);
    TEST_FIELD(MDICREATESTRUCTA, LPCSTR, szClass, 0, 4, 4);
    TEST_FIELD(MDICREATESTRUCTA, LPCSTR, szTitle, 4, 4, 4);
    TEST_FIELD(MDICREATESTRUCTA, HINSTANCE, hOwner, 8, 4, 4);
    TEST_FIELD(MDICREATESTRUCTA, INT, x, 12, 4, 4);
    TEST_FIELD(MDICREATESTRUCTA, INT, y, 16, 4, 4);
    TEST_FIELD(MDICREATESTRUCTA, INT, cx, 20, 4, 4);
    TEST_FIELD(MDICREATESTRUCTA, INT, cy, 24, 4, 4);
    TEST_FIELD(MDICREATESTRUCTA, DWORD, style, 28, 4, 4);
    TEST_FIELD(MDICREATESTRUCTA, LPARAM, lParam, 32, 4, 4);

    /* MDICREATESTRUCTW (pack 4) */
    TEST_TYPE(MDICREATESTRUCTW, 36, 4);
    TEST_FIELD(MDICREATESTRUCTW, LPCWSTR, szClass, 0, 4, 4);
    TEST_FIELD(MDICREATESTRUCTW, LPCWSTR, szTitle, 4, 4, 4);
    TEST_FIELD(MDICREATESTRUCTW, HINSTANCE, hOwner, 8, 4, 4);
    TEST_FIELD(MDICREATESTRUCTW, INT, x, 12, 4, 4);
    TEST_FIELD(MDICREATESTRUCTW, INT, y, 16, 4, 4);
    TEST_FIELD(MDICREATESTRUCTW, INT, cx, 20, 4, 4);
    TEST_FIELD(MDICREATESTRUCTW, INT, cy, 24, 4, 4);
    TEST_FIELD(MDICREATESTRUCTW, DWORD, style, 28, 4, 4);
    TEST_FIELD(MDICREATESTRUCTW, LPARAM, lParam, 32, 4, 4);

    /* MDINEXTMENU (pack 4) */
    TEST_TYPE(MDINEXTMENU, 12, 4);
    TEST_FIELD(MDINEXTMENU, HMENU, hmenuIn, 0, 4, 4);
    TEST_FIELD(MDINEXTMENU, HMENU, hmenuNext, 4, 4, 4);
    TEST_FIELD(MDINEXTMENU, HWND, hwndNext, 8, 4, 4);

    /* MEASUREITEMSTRUCT (pack 4) */
    TEST_TYPE(MEASUREITEMSTRUCT, 24, 4);
    TEST_FIELD(MEASUREITEMSTRUCT, UINT, CtlType, 0, 4, 4);
    TEST_FIELD(MEASUREITEMSTRUCT, UINT, CtlID, 4, 4, 4);
    TEST_FIELD(MEASUREITEMSTRUCT, UINT, itemID, 8, 4, 4);
    TEST_FIELD(MEASUREITEMSTRUCT, UINT, itemWidth, 12, 4, 4);
    TEST_FIELD(MEASUREITEMSTRUCT, UINT, itemHeight, 16, 4, 4);
    TEST_FIELD(MEASUREITEMSTRUCT, DWORD, itemData, 20, 4, 4);

    /* MENUINFO (pack 4) */
    TEST_TYPE(MENUINFO, 28, 4);
    TEST_FIELD(MENUINFO, DWORD, cbSize, 0, 4, 4);
    TEST_FIELD(MENUINFO, DWORD, fMask, 4, 4, 4);
    TEST_FIELD(MENUINFO, DWORD, dwStyle, 8, 4, 4);
    TEST_FIELD(MENUINFO, UINT, cyMax, 12, 4, 4);
    TEST_FIELD(MENUINFO, HBRUSH, hbrBack, 16, 4, 4);
    TEST_FIELD(MENUINFO, DWORD, dwContextHelpID, 20, 4, 4);
    TEST_FIELD(MENUINFO, DWORD, dwMenuData, 24, 4, 4);

    /* MENUITEMINFOA (pack 4) */
    TEST_TYPE(MENUITEMINFOA, 48, 4);
    TEST_FIELD(MENUITEMINFOA, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(MENUITEMINFOA, UINT, fMask, 4, 4, 4);
    TEST_FIELD(MENUITEMINFOA, UINT, fType, 8, 4, 4);
    TEST_FIELD(MENUITEMINFOA, UINT, fState, 12, 4, 4);
    TEST_FIELD(MENUITEMINFOA, UINT, wID, 16, 4, 4);
    TEST_FIELD(MENUITEMINFOA, HMENU, hSubMenu, 20, 4, 4);
    TEST_FIELD(MENUITEMINFOA, HBITMAP, hbmpChecked, 24, 4, 4);
    TEST_FIELD(MENUITEMINFOA, HBITMAP, hbmpUnchecked, 28, 4, 4);
    TEST_FIELD(MENUITEMINFOA, DWORD, dwItemData, 32, 4, 4);
    TEST_FIELD(MENUITEMINFOA, LPSTR, dwTypeData, 36, 4, 4);
    TEST_FIELD(MENUITEMINFOA, UINT, cch, 40, 4, 4);
    TEST_FIELD(MENUITEMINFOA, HBITMAP, hbmpItem, 44, 4, 4);

    /* MENUITEMINFOW (pack 4) */
    TEST_TYPE(MENUITEMINFOW, 48, 4);
    TEST_FIELD(MENUITEMINFOW, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(MENUITEMINFOW, UINT, fMask, 4, 4, 4);
    TEST_FIELD(MENUITEMINFOW, UINT, fType, 8, 4, 4);
    TEST_FIELD(MENUITEMINFOW, UINT, fState, 12, 4, 4);
    TEST_FIELD(MENUITEMINFOW, UINT, wID, 16, 4, 4);
    TEST_FIELD(MENUITEMINFOW, HMENU, hSubMenu, 20, 4, 4);
    TEST_FIELD(MENUITEMINFOW, HBITMAP, hbmpChecked, 24, 4, 4);
    TEST_FIELD(MENUITEMINFOW, HBITMAP, hbmpUnchecked, 28, 4, 4);
    TEST_FIELD(MENUITEMINFOW, DWORD, dwItemData, 32, 4, 4);
    TEST_FIELD(MENUITEMINFOW, LPWSTR, dwTypeData, 36, 4, 4);
    TEST_FIELD(MENUITEMINFOW, UINT, cch, 40, 4, 4);
    TEST_FIELD(MENUITEMINFOW, HBITMAP, hbmpItem, 44, 4, 4);

    /* MENUITEMTEMPLATE (pack 4) */
    TEST_TYPE(MENUITEMTEMPLATE, 6, 2);
    TEST_FIELD(MENUITEMTEMPLATE, WORD, mtOption, 0, 2, 2);
    TEST_FIELD(MENUITEMTEMPLATE, WORD, mtID, 2, 2, 2);
    TEST_FIELD(MENUITEMTEMPLATE, WCHAR[1], mtString, 4, 2, 2);

    /* MENUITEMTEMPLATEHEADER (pack 4) */
    TEST_TYPE(MENUITEMTEMPLATEHEADER, 4, 2);
    TEST_FIELD(MENUITEMTEMPLATEHEADER, WORD, versionNumber, 0, 2, 2);
    TEST_FIELD(MENUITEMTEMPLATEHEADER, WORD, offset, 2, 2, 2);

    /* MINIMIZEDMETRICS (pack 4) */
    TEST_TYPE(MINIMIZEDMETRICS, 20, 4);
    TEST_FIELD(MINIMIZEDMETRICS, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(MINIMIZEDMETRICS, int, iWidth, 4, 4, 4);
    TEST_FIELD(MINIMIZEDMETRICS, int, iHorzGap, 8, 4, 4);
    TEST_FIELD(MINIMIZEDMETRICS, int, iVertGap, 12, 4, 4);
    TEST_FIELD(MINIMIZEDMETRICS, int, iArrange, 16, 4, 4);

    /* MINMAXINFO (pack 4) */
    TEST_TYPE(MINMAXINFO, 40, 4);
    TEST_FIELD(MINMAXINFO, POINT, ptReserved, 0, 8, 4);
    TEST_FIELD(MINMAXINFO, POINT, ptMaxSize, 8, 8, 4);
    TEST_FIELD(MINMAXINFO, POINT, ptMaxPosition, 16, 8, 4);
    TEST_FIELD(MINMAXINFO, POINT, ptMinTrackSize, 24, 8, 4);
    TEST_FIELD(MINMAXINFO, POINT, ptMaxTrackSize, 32, 8, 4);

    /* MONITORINFO (pack 4) */
    TEST_TYPE(MONITORINFO, 40, 4);
    TEST_FIELD(MONITORINFO, DWORD, cbSize, 0, 4, 4);
    TEST_FIELD(MONITORINFO, RECT, rcMonitor, 4, 16, 4);
    TEST_FIELD(MONITORINFO, RECT, rcWork, 20, 16, 4);
    TEST_FIELD(MONITORINFO, DWORD, dwFlags, 36, 4, 4);

    /* MONITORINFOEXA (pack 4) */
    TEST_TYPE(MONITORINFOEXA, 72, 4);
#ifdef NONAMELESSSTRUCT
    TEST_FIELD(MONITORINFOEXA, MONITORINFO, DUMMYSTRUCTNAME, 0, 40, 4);
#else
    TEST_FIELD(MONITORINFOEXA, DWORD, cbSize, 0, 4, 4);
    TEST_FIELD(MONITORINFOEXA, RECT, rcMonitor, 4, 16, 4);
    TEST_FIELD(MONITORINFOEXA, RECT, rcWork, 20, 16, 4);
    TEST_FIELD(MONITORINFOEXA, DWORD, dwFlags, 36, 4, 4);
#endif
    TEST_FIELD(MONITORINFOEXA, CHAR[CCHDEVICENAME], szDevice, 40, 32, 1);

    /* MONITORINFOEXW (pack 4) */
    TEST_TYPE(MONITORINFOEXW, 104, 4);
#ifdef NONAMELESSSTRUCT
    TEST_FIELD(MONITORINFOEXW, MONITORINFO, DUMMYSTRUCTNAME, 0, 40, 4);
#else
    TEST_FIELD(MONITORINFOEXW, DWORD, cbSize, 0, 4, 4);
    TEST_FIELD(MONITORINFOEXW, RECT, rcMonitor, 4, 16, 4);
    TEST_FIELD(MONITORINFOEXW, RECT, rcWork, 20, 16, 4);
    TEST_FIELD(MONITORINFOEXW, DWORD, dwFlags, 36, 4, 4);
#endif
    TEST_FIELD(MONITORINFOEXW, WCHAR[CCHDEVICENAME], szDevice, 40, 64, 2);

    /* MOUSEHOOKSTRUCT (pack 4) */
    TEST_TYPE(MOUSEHOOKSTRUCT, 20, 4);
    TEST_FIELD(MOUSEHOOKSTRUCT, POINT, pt, 0, 8, 4);
    TEST_FIELD(MOUSEHOOKSTRUCT, HWND, hwnd, 8, 4, 4);
    TEST_FIELD(MOUSEHOOKSTRUCT, UINT, wHitTestCode, 12, 4, 4);
    TEST_FIELD(MOUSEHOOKSTRUCT, DWORD, dwExtraInfo, 16, 4, 4);

    /* MOUSEINPUT (pack 4) */
    TEST_TYPE(MOUSEINPUT, 24, 4);
    TEST_FIELD(MOUSEINPUT, LONG, dx, 0, 4, 4);
    TEST_FIELD(MOUSEINPUT, LONG, dy, 4, 4, 4);
    TEST_FIELD(MOUSEINPUT, DWORD, mouseData, 8, 4, 4);
    TEST_FIELD(MOUSEINPUT, DWORD, dwFlags, 12, 4, 4);
    TEST_FIELD(MOUSEINPUT, DWORD, time, 16, 4, 4);
    TEST_FIELD(MOUSEINPUT, ULONG_PTR, dwExtraInfo, 20, 4, 4);

    /* MOUSEKEYS (pack 4) */
    TEST_TYPE(MOUSEKEYS, 28, 4);
    TEST_FIELD(MOUSEKEYS, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(MOUSEKEYS, DWORD, dwFlags, 4, 4, 4);
    TEST_FIELD(MOUSEKEYS, DWORD, iMaxSpeed, 8, 4, 4);
    TEST_FIELD(MOUSEKEYS, DWORD, iTimeToMaxSpeed, 12, 4, 4);
    TEST_FIELD(MOUSEKEYS, DWORD, iCtrlSpeed, 16, 4, 4);
    TEST_FIELD(MOUSEKEYS, DWORD, dwReserved1, 20, 4, 4);
    TEST_FIELD(MOUSEKEYS, DWORD, dwReserved2, 24, 4, 4);

    /* MSG (pack 4) */
    TEST_TYPE(MSG, 28, 4);
    TEST_FIELD(MSG, HWND, hwnd, 0, 4, 4);
    TEST_FIELD(MSG, UINT, message, 4, 4, 4);
    TEST_FIELD(MSG, WPARAM, wParam, 8, 4, 4);
    TEST_FIELD(MSG, LPARAM, lParam, 12, 4, 4);
    TEST_FIELD(MSG, DWORD, time, 16, 4, 4);
    TEST_FIELD(MSG, POINT, pt, 20, 8, 4);

    /* MSGBOXPARAMSA (pack 4) */
    TEST_TYPE(MSGBOXPARAMSA, 40, 4);
    TEST_FIELD(MSGBOXPARAMSA, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(MSGBOXPARAMSA, HWND, hwndOwner, 4, 4, 4);
    TEST_FIELD(MSGBOXPARAMSA, HINSTANCE, hInstance, 8, 4, 4);
    TEST_FIELD(MSGBOXPARAMSA, LPCSTR, lpszText, 12, 4, 4);
    TEST_FIELD(MSGBOXPARAMSA, LPCSTR, lpszCaption, 16, 4, 4);
    TEST_FIELD(MSGBOXPARAMSA, DWORD, dwStyle, 20, 4, 4);
    TEST_FIELD(MSGBOXPARAMSA, LPCSTR, lpszIcon, 24, 4, 4);
    TEST_FIELD(MSGBOXPARAMSA, DWORD_PTR, dwContextHelpId, 28, 4, 4);
    TEST_FIELD(MSGBOXPARAMSA, MSGBOXCALLBACK, lpfnMsgBoxCallback, 32, 4, 4);
    TEST_FIELD(MSGBOXPARAMSA, DWORD, dwLanguageId, 36, 4, 4);

    /* MSGBOXPARAMSW (pack 4) */
    TEST_TYPE(MSGBOXPARAMSW, 40, 4);
    TEST_FIELD(MSGBOXPARAMSW, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(MSGBOXPARAMSW, HWND, hwndOwner, 4, 4, 4);
    TEST_FIELD(MSGBOXPARAMSW, HINSTANCE, hInstance, 8, 4, 4);
    TEST_FIELD(MSGBOXPARAMSW, LPCWSTR, lpszText, 12, 4, 4);
    TEST_FIELD(MSGBOXPARAMSW, LPCWSTR, lpszCaption, 16, 4, 4);
    TEST_FIELD(MSGBOXPARAMSW, DWORD, dwStyle, 20, 4, 4);
    TEST_FIELD(MSGBOXPARAMSW, LPCWSTR, lpszIcon, 24, 4, 4);
    TEST_FIELD(MSGBOXPARAMSW, DWORD_PTR, dwContextHelpId, 28, 4, 4);
    TEST_FIELD(MSGBOXPARAMSW, MSGBOXCALLBACK, lpfnMsgBoxCallback, 32, 4, 4);
    TEST_FIELD(MSGBOXPARAMSW, DWORD, dwLanguageId, 36, 4, 4);

    /* MSLLHOOKSTRUCT (pack 4) */
    TEST_TYPE(MSLLHOOKSTRUCT, 24, 4);
    TEST_FIELD(MSLLHOOKSTRUCT, POINT, pt, 0, 8, 4);
    TEST_FIELD(MSLLHOOKSTRUCT, DWORD, mouseData, 8, 4, 4);
    TEST_FIELD(MSLLHOOKSTRUCT, DWORD, flags, 12, 4, 4);
    TEST_FIELD(MSLLHOOKSTRUCT, DWORD, time, 16, 4, 4);
    TEST_FIELD(MSLLHOOKSTRUCT, ULONG_PTR, dwExtraInfo, 20, 4, 4);

    /* MULTIKEYHELPA (pack 4) */
    TEST_TYPE(MULTIKEYHELPA, 8, 4);
    TEST_FIELD(MULTIKEYHELPA, DWORD, mkSize, 0, 4, 4);
    TEST_FIELD(MULTIKEYHELPA, CHAR, mkKeylist, 4, 1, 1);
    TEST_FIELD(MULTIKEYHELPA, CHAR[1], szKeyphrase, 5, 1, 1);

    /* MULTIKEYHELPW (pack 4) */
    TEST_TYPE(MULTIKEYHELPW, 8, 4);
    TEST_FIELD(MULTIKEYHELPW, DWORD, mkSize, 0, 4, 4);
    TEST_FIELD(MULTIKEYHELPW, WCHAR, mkKeylist, 4, 2, 2);
    TEST_FIELD(MULTIKEYHELPW, WCHAR[1], szKeyphrase, 6, 2, 2);

    /* NCCALCSIZE_PARAMS (pack 4) */
    TEST_TYPE(NCCALCSIZE_PARAMS, 52, 4);
    TEST_FIELD(NCCALCSIZE_PARAMS, RECT[3], rgrc, 0, 48, 4);
    TEST_FIELD(NCCALCSIZE_PARAMS, WINDOWPOS *, lppos, 48, 4, 4);

    /* NMHDR (pack 4) */
    TEST_TYPE(NMHDR, 12, 4);
    TEST_FIELD(NMHDR, HWND, hwndFrom, 0, 4, 4);
    TEST_FIELD(NMHDR, UINT, idFrom, 4, 4, 4);
    TEST_FIELD(NMHDR, UINT, code, 8, 4, 4);

    /* NONCLIENTMETRICSA (pack 4) */
    TEST_TYPE(NONCLIENTMETRICSA, 340, 4);
    TEST_FIELD(NONCLIENTMETRICSA, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSA, INT, iBorderWidth, 4, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSA, INT, iScrollWidth, 8, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSA, INT, iScrollHeight, 12, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSA, INT, iCaptionWidth, 16, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSA, INT, iCaptionHeight, 20, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSA, LOGFONTA, lfCaptionFont, 24, 60, 4);
    TEST_FIELD(NONCLIENTMETRICSA, INT, iSmCaptionWidth, 84, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSA, INT, iSmCaptionHeight, 88, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSA, LOGFONTA, lfSmCaptionFont, 92, 60, 4);
    TEST_FIELD(NONCLIENTMETRICSA, INT, iMenuWidth, 152, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSA, INT, iMenuHeight, 156, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSA, LOGFONTA, lfMenuFont, 160, 60, 4);
    TEST_FIELD(NONCLIENTMETRICSA, LOGFONTA, lfStatusFont, 220, 60, 4);
    TEST_FIELD(NONCLIENTMETRICSA, LOGFONTA, lfMessageFont, 280, 60, 4);

    /* NONCLIENTMETRICSW (pack 4) */
    TEST_TYPE(NONCLIENTMETRICSW, 500, 4);
    TEST_FIELD(NONCLIENTMETRICSW, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSW, INT, iBorderWidth, 4, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSW, INT, iScrollWidth, 8, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSW, INT, iScrollHeight, 12, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSW, INT, iCaptionWidth, 16, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSW, INT, iCaptionHeight, 20, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSW, LOGFONTW, lfCaptionFont, 24, 92, 4);
    TEST_FIELD(NONCLIENTMETRICSW, INT, iSmCaptionWidth, 116, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSW, INT, iSmCaptionHeight, 120, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSW, LOGFONTW, lfSmCaptionFont, 124, 92, 4);
    TEST_FIELD(NONCLIENTMETRICSW, INT, iMenuWidth, 216, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSW, INT, iMenuHeight, 220, 4, 4);
    TEST_FIELD(NONCLIENTMETRICSW, LOGFONTW, lfMenuFont, 224, 92, 4);
    TEST_FIELD(NONCLIENTMETRICSW, LOGFONTW, lfStatusFont, 316, 92, 4);
    TEST_FIELD(NONCLIENTMETRICSW, LOGFONTW, lfMessageFont, 408, 92, 4);

    /* PAINTSTRUCT (pack 4) */
    TEST_TYPE(PAINTSTRUCT, 64, 4);
    TEST_FIELD(PAINTSTRUCT, HDC, hdc, 0, 4, 4);
    TEST_FIELD(PAINTSTRUCT, BOOL, fErase, 4, 4, 4);
    TEST_FIELD(PAINTSTRUCT, RECT, rcPaint, 8, 16, 4);
    TEST_FIELD(PAINTSTRUCT, BOOL, fRestore, 24, 4, 4);
    TEST_FIELD(PAINTSTRUCT, BOOL, fIncUpdate, 28, 4, 4);
    TEST_FIELD(PAINTSTRUCT, BYTE[32], rgbReserved, 32, 32, 1);

    /* SCROLLINFO (pack 4) */
    TEST_TYPE(SCROLLINFO, 28, 4);
    TEST_FIELD(SCROLLINFO, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(SCROLLINFO, UINT, fMask, 4, 4, 4);
    TEST_FIELD(SCROLLINFO, INT, nMin, 8, 4, 4);
    TEST_FIELD(SCROLLINFO, INT, nMax, 12, 4, 4);
    TEST_FIELD(SCROLLINFO, UINT, nPage, 16, 4, 4);
    TEST_FIELD(SCROLLINFO, INT, nPos, 20, 4, 4);
    TEST_FIELD(SCROLLINFO, INT, nTrackPos, 24, 4, 4);

    /* SERIALKEYSA (pack 4) */
    TEST_TYPE(SERIALKEYSA, 28, 4);
    TEST_FIELD(SERIALKEYSA, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(SERIALKEYSA, DWORD, dwFlags, 4, 4, 4);
    TEST_FIELD(SERIALKEYSA, LPSTR, lpszActivePort, 8, 4, 4);
    TEST_FIELD(SERIALKEYSA, LPSTR, lpszPort, 12, 4, 4);
    TEST_FIELD(SERIALKEYSA, UINT, iBaudRate, 16, 4, 4);
    TEST_FIELD(SERIALKEYSA, UINT, iPortState, 20, 4, 4);
    TEST_FIELD(SERIALKEYSA, UINT, iActive, 24, 4, 4);

    /* SERIALKEYSW (pack 4) */
    TEST_TYPE(SERIALKEYSW, 28, 4);
    TEST_FIELD(SERIALKEYSW, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(SERIALKEYSW, DWORD, dwFlags, 4, 4, 4);
    TEST_FIELD(SERIALKEYSW, LPWSTR, lpszActivePort, 8, 4, 4);
    TEST_FIELD(SERIALKEYSW, LPWSTR, lpszPort, 12, 4, 4);
    TEST_FIELD(SERIALKEYSW, UINT, iBaudRate, 16, 4, 4);
    TEST_FIELD(SERIALKEYSW, UINT, iPortState, 20, 4, 4);
    TEST_FIELD(SERIALKEYSW, UINT, iActive, 24, 4, 4);

    /* SOUNDSENTRYA (pack 4) */
    TEST_TYPE(SOUNDSENTRYA, 48, 4);
    TEST_FIELD(SOUNDSENTRYA, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(SOUNDSENTRYA, DWORD, dwFlags, 4, 4, 4);
    TEST_FIELD(SOUNDSENTRYA, DWORD, iFSTextEffect, 8, 4, 4);
    TEST_FIELD(SOUNDSENTRYA, DWORD, iFSTextEffectMSec, 12, 4, 4);
    TEST_FIELD(SOUNDSENTRYA, DWORD, iFSTextEffectColorBits, 16, 4, 4);
    TEST_FIELD(SOUNDSENTRYA, DWORD, iFSGrafEffect, 20, 4, 4);
    TEST_FIELD(SOUNDSENTRYA, DWORD, iFSGrafEffectMSec, 24, 4, 4);
    TEST_FIELD(SOUNDSENTRYA, DWORD, iFSGrafEffectColor, 28, 4, 4);
    TEST_FIELD(SOUNDSENTRYA, DWORD, iWindowsEffect, 32, 4, 4);
    TEST_FIELD(SOUNDSENTRYA, DWORD, iWindowsEffectMSec, 36, 4, 4);
    TEST_FIELD(SOUNDSENTRYA, LPSTR, lpszWindowsEffectDLL, 40, 4, 4);
    TEST_FIELD(SOUNDSENTRYA, DWORD, iWindowsEffectOrdinal, 44, 4, 4);

    /* SOUNDSENTRYW (pack 4) */
    TEST_TYPE(SOUNDSENTRYW, 48, 4);
    TEST_FIELD(SOUNDSENTRYW, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(SOUNDSENTRYW, DWORD, dwFlags, 4, 4, 4);
    TEST_FIELD(SOUNDSENTRYW, DWORD, iFSTextEffect, 8, 4, 4);
    TEST_FIELD(SOUNDSENTRYW, DWORD, iFSTextEffectMSec, 12, 4, 4);
    TEST_FIELD(SOUNDSENTRYW, DWORD, iFSTextEffectColorBits, 16, 4, 4);
    TEST_FIELD(SOUNDSENTRYW, DWORD, iFSGrafEffect, 20, 4, 4);
    TEST_FIELD(SOUNDSENTRYW, DWORD, iFSGrafEffectMSec, 24, 4, 4);
    TEST_FIELD(SOUNDSENTRYW, DWORD, iFSGrafEffectColor, 28, 4, 4);
    TEST_FIELD(SOUNDSENTRYW, DWORD, iWindowsEffect, 32, 4, 4);
    TEST_FIELD(SOUNDSENTRYW, DWORD, iWindowsEffectMSec, 36, 4, 4);
    TEST_FIELD(SOUNDSENTRYW, LPWSTR, lpszWindowsEffectDLL, 40, 4, 4);
    TEST_FIELD(SOUNDSENTRYW, DWORD, iWindowsEffectOrdinal, 44, 4, 4);

    /* STICKYKEYS (pack 4) */
    TEST_TYPE(STICKYKEYS, 8, 4);
    TEST_FIELD(STICKYKEYS, DWORD, cbSize, 0, 4, 4);
    TEST_FIELD(STICKYKEYS, DWORD, dwFlags, 4, 4, 4);

    /* STYLESTRUCT (pack 4) */
    TEST_TYPE(STYLESTRUCT, 8, 4);
    TEST_FIELD(STYLESTRUCT, DWORD, styleOld, 0, 4, 4);
    TEST_FIELD(STYLESTRUCT, DWORD, styleNew, 4, 4, 4);

    /* TOGGLEKEYS (pack 4) */
    TEST_TYPE(TOGGLEKEYS, 8, 4);
    TEST_FIELD(TOGGLEKEYS, DWORD, cbSize, 0, 4, 4);
    TEST_FIELD(TOGGLEKEYS, DWORD, dwFlags, 4, 4, 4);

    /* TPMPARAMS (pack 4) */
    TEST_TYPE(TPMPARAMS, 20, 4);
    TEST_FIELD(TPMPARAMS, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(TPMPARAMS, RECT, rcExclude, 4, 16, 4);

    /* TRACKMOUSEEVENT (pack 4) */
    TEST_TYPE(TRACKMOUSEEVENT, 16, 4);
    TEST_FIELD(TRACKMOUSEEVENT, DWORD, cbSize, 0, 4, 4);
    TEST_FIELD(TRACKMOUSEEVENT, DWORD, dwFlags, 4, 4, 4);
    TEST_FIELD(TRACKMOUSEEVENT, HWND, hwndTrack, 8, 4, 4);
    TEST_FIELD(TRACKMOUSEEVENT, DWORD, dwHoverTime, 12, 4, 4);

    /* WINDOWINFO */
    TEST_FIELD(WINDOWINFO, DWORD, cbSize, 0, 4, 4);
    TEST_FIELD(WINDOWINFO, RECT, rcWindow, 4, 16, 4);
    TEST_FIELD(WINDOWINFO, RECT, rcClient, 20, 16, 4);
    TEST_FIELD(WINDOWINFO, DWORD, dwStyle, 36, 4, 4);
    TEST_FIELD(WINDOWINFO, DWORD, dwExStyle, 40, 4, 4);
    TEST_FIELD(WINDOWINFO, UINT, cxWindowBorders, 48, 4, 4);
    TEST_FIELD(WINDOWINFO, UINT, cyWindowBorders, 52, 4, 4);
    TEST_FIELD(WINDOWINFO, ATOM, atomWindowType, 56, 2, 2);
    TEST_FIELD(WINDOWINFO, WORD, wCreatorVersion, 58, 2, 2);

    /* WINDOWPOS (pack 4) */
    TEST_TYPE(WINDOWPOS, 28, 4);
    TEST_FIELD(WINDOWPOS, HWND, hwnd, 0, 4, 4);
    TEST_FIELD(WINDOWPOS, HWND, hwndInsertAfter, 4, 4, 4);
    TEST_FIELD(WINDOWPOS, INT, x, 8, 4, 4);
    TEST_FIELD(WINDOWPOS, INT, y, 12, 4, 4);
    TEST_FIELD(WINDOWPOS, INT, cx, 16, 4, 4);
    TEST_FIELD(WINDOWPOS, INT, cy, 20, 4, 4);
    TEST_FIELD(WINDOWPOS, UINT, flags, 24, 4, 4);

    /* WNDCLASSA (pack 4) */
    TEST_TYPE(WNDCLASSA, 40, 4);
    TEST_FIELD(WNDCLASSA, UINT, style, 0, 4, 4);
    TEST_FIELD(WNDCLASSA, WNDPROC, lpfnWndProc, 4, 4, 4);
    TEST_FIELD(WNDCLASSA, INT, cbClsExtra, 8, 4, 4);
    TEST_FIELD(WNDCLASSA, INT, cbWndExtra, 12, 4, 4);
    TEST_FIELD(WNDCLASSA, HINSTANCE, hInstance, 16, 4, 4);
    TEST_FIELD(WNDCLASSA, HICON, hIcon, 20, 4, 4);
    TEST_FIELD(WNDCLASSA, HCURSOR, hCursor, 24, 4, 4);
    TEST_FIELD(WNDCLASSA, HBRUSH, hbrBackground, 28, 4, 4);
    TEST_FIELD(WNDCLASSA, LPCSTR, lpszMenuName, 32, 4, 4);
    TEST_FIELD(WNDCLASSA, LPCSTR, lpszClassName, 36, 4, 4);

    /* WNDCLASSEXA (pack 4) */
    TEST_TYPE(WNDCLASSEXA, 48, 4);
    TEST_FIELD(WNDCLASSEXA, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(WNDCLASSEXA, UINT, style, 4, 4, 4);
    TEST_FIELD(WNDCLASSEXA, WNDPROC, lpfnWndProc, 8, 4, 4);
    TEST_FIELD(WNDCLASSEXA, INT, cbClsExtra, 12, 4, 4);
    TEST_FIELD(WNDCLASSEXA, INT, cbWndExtra, 16, 4, 4);
    TEST_FIELD(WNDCLASSEXA, HINSTANCE, hInstance, 20, 4, 4);
    TEST_FIELD(WNDCLASSEXA, HICON, hIcon, 24, 4, 4);
    TEST_FIELD(WNDCLASSEXA, HCURSOR, hCursor, 28, 4, 4);
    TEST_FIELD(WNDCLASSEXA, HBRUSH, hbrBackground, 32, 4, 4);
    TEST_FIELD(WNDCLASSEXA, LPCSTR, lpszMenuName, 36, 4, 4);
    TEST_FIELD(WNDCLASSEXA, LPCSTR, lpszClassName, 40, 4, 4);
    TEST_FIELD(WNDCLASSEXA, HICON, hIconSm, 44, 4, 4);

    /* WNDCLASSEXW (pack 4) */
    TEST_TYPE(WNDCLASSEXW, 48, 4);
    TEST_FIELD(WNDCLASSEXW, UINT, cbSize, 0, 4, 4);
    TEST_FIELD(WNDCLASSEXW, UINT, style, 4, 4, 4);
    TEST_FIELD(WNDCLASSEXW, WNDPROC, lpfnWndProc, 8, 4, 4);
    TEST_FIELD(WNDCLASSEXW, INT, cbClsExtra, 12, 4, 4);
    TEST_FIELD(WNDCLASSEXW, INT, cbWndExtra, 16, 4, 4);
    TEST_FIELD(WNDCLASSEXW, HINSTANCE, hInstance, 20, 4, 4);
    TEST_FIELD(WNDCLASSEXW, HICON, hIcon, 24, 4, 4);
    TEST_FIELD(WNDCLASSEXW, HCURSOR, hCursor, 28, 4, 4);
    TEST_FIELD(WNDCLASSEXW, HBRUSH, hbrBackground, 32, 4, 4);
    TEST_FIELD(WNDCLASSEXW, LPCWSTR, lpszMenuName, 36, 4, 4);
    TEST_FIELD(WNDCLASSEXW, LPCWSTR, lpszClassName, 40, 4, 4);
    TEST_FIELD(WNDCLASSEXW, HICON, hIconSm, 44, 4, 4);

    /* WNDCLASSW (pack 4) */
    TEST_TYPE(WNDCLASSW, 40, 4);
    TEST_FIELD(WNDCLASSW, UINT, style, 0, 4, 4);
    TEST_FIELD(WNDCLASSW, WNDPROC, lpfnWndProc, 4, 4, 4);
    TEST_FIELD(WNDCLASSW, INT, cbClsExtra, 8, 4, 4);
    TEST_FIELD(WNDCLASSW, INT, cbWndExtra, 12, 4, 4);
    TEST_FIELD(WNDCLASSW, HINSTANCE, hInstance, 16, 4, 4);
    TEST_FIELD(WNDCLASSW, HICON, hIcon, 20, 4, 4);
    TEST_FIELD(WNDCLASSW, HCURSOR, hCursor, 24, 4, 4);
    TEST_FIELD(WNDCLASSW, HBRUSH, hbrBackground, 28, 4, 4);
    TEST_FIELD(WNDCLASSW, LPCWSTR, lpszMenuName, 32, 4, 4);
    TEST_FIELD(WNDCLASSW, LPCWSTR, lpszClassName, 36, 4, 4);

}

START_TEST(generated)
{
    test_pack();
}
