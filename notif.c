#include <windows.h>
#include <Shellapi.h>

// メッセージIDの定義
#define WM_NOTIFYICON (WM_USER + 100)

void main()
{
	// NOTIFYICONDATA型変数の宣言
	NOTIFYICONDATA nIcon;
	MSG msg;
	LPARAM lParam;

	// アイコンの追加
	nIcon.cbSize = sizeof(NOTIFYICONDATA);
	nIcon.uID    = 1;
	nIcon.hWnd   = NULL;
	nIcon.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
	nIcon.hIcon  = LoadIcon(NULL, IDI_APPLICATION);
	nIcon.uCallbackMessage = WM_NOTIFYICON;

	lstrcpy(nIcon.szTip,"アイコンのヒント");
	Shell_NotifyIcon(NIM_ADD, &nIcon);

	Sleep(8000);

	// アイコンの削除
	Shell_NotifyIcon(NIM_DELETE, &nIcon);
/*
	// メッセージの処理
	switch(msg){
	    case WM_NOTIFYICON:
	        switch(lParam){
	            case WM_RBUTTONDOWN:
	                break;
	            case WM_LBUTTONDBLCLK:
	                break;
	        }
	        break;
	}*/
}
