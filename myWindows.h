HWND CreateToolTip(HWND hwndTool, string text, HINSTANCE hinstance){
	if (text==""){
		return FALSE;
	}
	HWND hwndTip = CreateWindowEx(0, TOOLTIPS_CLASS, NULL,
		WS_POPUP | TTS_ALWAYSTIP | TTS_BALLOON,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		GetParent(hwndTool), NULL,
		hinstance, NULL);
	if (!hwndTool || !hwndTip){
	    MessageBox(NULL, "Couldn't create the ToolTip control.", "Error", MB_OK);
		return (HWND)NULL;
	}
	TOOLINFO toolInfo = { 0 };
	toolInfo.cbSize = TTTOOLINFOA_V1_SIZE;
	toolInfo.hwnd = GetParent(hwndTool);
	toolInfo.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
	toolInfo.uId = (UINT_PTR)hwndTool;
	toolInfo.lpszText =(LPSTR) text.c_str();
	if (SendMessage(hwndTip, TTM_ACTIVATE, TRUE, 0)){
		int err = GetLastError();
		MessageBox(NULL,to_string(err).c_str(), "Error", MB_OK);
	}
	if (!SendMessage(hwndTip, TTM_ADDTOOL, 0, (LPARAM)&toolInfo)){
		int err = GetLastError();
		MessageBox(NULL,to_string(err).c_str(), "Error", MB_OK);
	}
	return hwndTip;
}

HWND hwnd, textLogin1,labelhwndl1,labelLogin1,textPw1,labelhwndl2,labelLogin2,textLogin2,textPw2,labelUserID,labelUserPw,buttonUser1,buttonUser2,buttonStartFree,buttonDonation;
void myWindows(HINSTANCE hThisInstance, HWND hwnd){
    char login1Imp[50];
    char login2Imp[50];
    char pw1Imp[110];
    char pw2Imp[110];

    HICON hIcon = LoadIconA(hThisInstance, MAKEINTRESOURCE(TRAY_ICON));
    nid.cbSize = sizeof(nid);
    nid.hWnd = hwnd;
    nid.uID = 1;
    nid.uFlags = NIF_ICON|NIF_TIP|NIF_MESSAGE;
    nid.uCallbackMessage = APPWM_ICONNNOTIFY;
    nid.hIcon = hIcon;
    strcpy(nid.szTip, "Aux GB");
    Shell_NotifyIconA(NIM_ADD, &nid);

    labelhwndl1 = CreateWindowExA (
           WS_EX_COMPOSITED|WS_EX_NOACTIVATE|WS_EX_NOPARENTNOTIFY,
           "Static",
           "",
           WS_CHILD|WS_VISIBLE|SS_SIMPLE,
           150, 20, 100, 20,
           hwnd,
           (HMENU)STATIC_L1,
           hThisInstance,
           NULL
    );

    labelLogin1 = CreateWindowExA (
           WS_EX_COMPOSITED|WS_EX_NOACTIVATE|WS_EX_NOPARENTNOTIFY,
           "Static",
           "Conta 1",
           WS_CHILD|WS_VISIBLE|SS_SIMPLE,
           150, 40, 100, 20,
           hwnd,
           (HMENU)STATIC_L1,
           hThisInstance,
           NULL
    );

    GetPrivateProfileString("Acc1_GB", "User", NULL, login1Imp, sizeof(login1Imp), dirIniFile);
    textLogin1 = CreateWindowExA (
           0,
           "Edit",
           login1Imp,
           WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON|WS_TABSTOP,
           70,
           60,
           200,
           20,
           hwnd,
           (HMENU)TXT_LOGIN1,
           hThisInstance,
           NULL
    );
    GetPrivateProfileString("Acc1_GB", "Pw", NULL, pw1Imp, sizeof(pw1Imp), dirIniFile);
    if(strlen(pw1Imp) > 0){
        isCryptPw1 = TRUE;
        strcpy(pw1Imp, "password");
    }
    textPw1 = CreateWindowExA (
           0,
           "Edit",
           pw1Imp,
           WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON|WS_TABSTOP|ES_PASSWORD,
           70,
           90,
           200,
           20,
           hwnd,
           (HMENU)TXT_PW1,
           hThisInstance,
           NULL
    );
    if(strlen(pw1Imp) > 0){
        EnableWindow(textPw1, FALSE);
    }

    labelhwndl2 = CreateWindowExA (
           WS_EX_COMPOSITED|WS_EX_NOACTIVATE|WS_EX_NOPARENTNOTIFY,
           "Static",
           "",
           WS_CHILD|WS_VISIBLE|SS_SIMPLE,
           350, 20, 100, 20,
           hwnd,
           (HMENU)STATIC_L2,
           hThisInstance,
           NULL
    );

    labelLogin2 = CreateWindowExA (
           WS_EX_COMPOSITED|WS_EX_NOACTIVATE|WS_EX_NOPARENTNOTIFY,
           "Static",
           "Conta 2",
           WS_CHILD|WS_VISIBLE|SS_SIMPLE,
           350, 40, 100, 20,
           hwnd,
           (HMENU)STATIC_L2,
           hThisInstance,
           NULL
    );

    GetPrivateProfileString("Acc2_GB", "User", NULL, login2Imp, sizeof(login2Imp), dirIniFile);
    textLogin2 = CreateWindowExA (
           0,
           "Edit",
           login2Imp,
           WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON|WS_TABSTOP,
           280,
           60,
           200,
           20,
           hwnd,
           (HMENU)TXT_LOGIN2,
           hThisInstance,
           NULL
    );
    GetPrivateProfileString("Acc2_GB", "Pw", NULL, pw2Imp, sizeof(pw2Imp), dirIniFile);
    if(strlen(pw2Imp) > 0){
        isCryptPw2 = TRUE;
        strcpy(pw2Imp, "password");
    }
    textPw2 = CreateWindowExA (
           0,
           "Edit",
           pw2Imp,
           WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON|WS_TABSTOP|ES_PASSWORD,
           280,
           90,
           200,
           20,
           hwnd,
           (HMENU)TXT_PW2,
           hThisInstance,
           NULL
    );
    if(strlen(pw2Imp) > 0){
        EnableWindow(textPw2, FALSE);
    }
    labelUserID = CreateWindowExA (
           WS_EX_COMPOSITED|WS_EX_NOACTIVATE|WS_EX_NOPARENTNOTIFY,
           "Static",
           "Login:",
           WS_CHILD|WS_VISIBLE|SS_SIMPLE,
           5, 63, 100, 20,
           hwnd,
           (HMENU)STATIC_L,
           hThisInstance,
           NULL
    );
    labelUserPw = CreateWindowExA (
           WS_EX_COMPOSITED|WS_EX_NOACTIVATE|WS_EX_NOPARENTNOTIFY,
           "Static",
           "Senha:",
           WS_CHILD|WS_VISIBLE|SS_SIMPLE,
           2, 92, 100, 20,
           hwnd,
           (HMENU)STATIC_PW,
           hThisInstance,
           NULL
    );
    buttonUser1 = CreateWindowExA (
           WS_EX_COMPOSITED|WS_EX_NOACTIVATE|WS_EX_NOPARENTNOTIFY,
           "Button",
           "Login 1",
           WS_CHILD|WS_VISIBLE,
           110, 120, 100, 20,
           hwnd,
           (HMENU)BTN_Login1,
           hThisInstance,
           NULL
    );
    buttonUser2 = CreateWindowExA (
           WS_EX_COMPOSITED|WS_EX_NOACTIVATE|WS_EX_NOPARENTNOTIFY,
           "Button",
           "Login 2",
           WS_CHILD|WS_VISIBLE,
           320, 120, 100, 20,
           hwnd,
           (HMENU)BTN_Login2,
           hThisInstance,
           NULL
    );
    buttonStartFree = CreateWindowExA (
           WS_EX_COMPOSITED|WS_EX_NOACTIVATE|WS_EX_NOPARENTNOTIFY,
           "Button",
           "Start AutoFree",
           WS_CHILD|WS_VISIBLE,
           215, 175, 100, 20,
           hwnd,
           (HMENU)BTN_AutoFree,
           hThisInstance,
           NULL
    );

   buttonDonation = CreateWindowExA (
           WS_EX_COMPOSITED|WS_EX_NOACTIVATE|WS_EX_NOPARENTNOTIFY,
           "Button",
           "",
           WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON|BS_BITMAP,
           383, 166, 147, 47,
           hwnd,
           (HMENU)BTN_DONATION,
           hThisInstance,
           NULL
    );
    SendMessageA(buttonDonation, BM_SETIMAGE, IMAGE_BITMAP,(LPARAM) LoadBitmap(hThisInstance, MAKEINTRESOURCE(BTN_DONATE_BMP)));
    CreateToolTip(buttonDonation, "Seja um apoiador, e me incentive a criar novas ferramentas!", hThisInstance);
}
