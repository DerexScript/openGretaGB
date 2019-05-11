#include <sstream>
HWND handleGB1 = NULL, handleGB2 = NULL;
DWORD dwProcessIDGB1 = 0, dwProcessIDGB2 = 0;

string decrypt(char *myCrypt, int myCryptSize, char myKey[]) {
    char myStringDecrypt[myCryptSize+1];
    const int myKeySize = strlen(myKey);
    int keyInt;
    int cnt = 0;
    int cntf = 0;
    for(int i = 0; i < myCryptSize; i++) {
        if(myCrypt[i] == 'F') {
            cnt++;
        }
    }
    int myCryptInt[cnt+1];
    cnt = 0;
    char tempChar[strlen(myCrypt)+1];
    for(int i = 0; i < myCryptSize; i++) {
        if(myCrypt[i] != 'F' && i < myCryptSize-1) {
            tempChar[cnt] = myCrypt[i];
            cnt++;
        } else {
            if(i == myCryptSize-1)
                tempChar[cnt] = myCrypt[i];
            myCryptInt[cntf] = atoi(tempChar);
            ZeroMemory(tempChar, sizeof(tempChar));
            cntf++;
            cnt = 0;
        }
    }
    for (int aux = 0; aux < ((signed)sizeof(myCryptInt)/4);) {
        for (int i = 0; i < myKeySize; i++) {
            if (aux < (signed)sizeof(myCryptInt)/4) {
                keyInt = myKey[i];
                myStringDecrypt[aux] = (myCryptInt[aux] / keyInt);
            } else {
                myStringDecrypt[aux] = '\0';
                break;
            }
            aux++;
        }
    }
    return myStringDecrypt;
}

void PressNine() {
    int loop = 0;
    for (loop=0; loop<=3; loop++) {
        keybd_event(0x39, 0x10, 0, 0);
        keybd_event(0x39, 0, KEYEVENTF_KEYUP, 0);
        cout << "9";
    }
}

void startAutoFreeCommands() {
    HWND GBExist = FindWindowA("Softnyx", NULL);
    if(GBExist != NULL) {
        Sleep(10000);
        keybd_event(VK_RETURN, 0x10, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(VK_DIVIDE, 0x10, 0, 0);
        keybd_event(VK_DIVIDE, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x47, 0x10, 0, 0);
        keybd_event(0x47, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x50, 0x10, 0, 0);
        keybd_event(0x50, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(VK_SPACE, 0x10, 0, 0);
        keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        PressNine();
        Sleep(100);
        keybd_event(VK_SPACE, 0x10, 0, 0);
        keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        PressNine();
        Sleep(100);
        keybd_event(VK_RETURN, 0x10, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(VK_RETURN, 0x10, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(VK_DIVIDE, 0x10, 0, 0);
        keybd_event(VK_DIVIDE, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x47, 0x10, 0, 0);
        keybd_event(0x47, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x50, 0x10, 0, 0);
        keybd_event(0x50, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x32, 0x10, 0, 0);
        keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(VK_SPACE, 0x10, 0, 0);
        keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        PressNine();
        Sleep(100);
        keybd_event(VK_SPACE, 0x10, 0, 0);
        keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        PressNine();
        Sleep(100);
        keybd_event(VK_RETURN, 0x10, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(VK_RETURN, 0x10, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(VK_DIVIDE, 0x10, 0, 0);
        keybd_event(VK_DIVIDE, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x41, 0x10, 0, 0);
        keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x42, 0x10, 0, 0);
        keybd_event(0x42, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x4D, 0x10, 0, 0);
        keybd_event(0x4D, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x4F, 0x10, 0, 0);
        keybd_event(0x4F, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x44, 0x10, 0, 0);
        keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x45, 0x10, 0, 0);
        keybd_event(0x45, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(VK_SPACE, 0x10, 0, 0);
        keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x30, 0x10, 0, 0);
        keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(VK_RETURN, 0x10, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(VK_RETURN, 0x10, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(VK_DIVIDE, 0x10, 0, 0);
        keybd_event(VK_DIVIDE, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x47, 0x10, 0, 0);
        keybd_event(0x47, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x4F, 0x10, 0, 0);
        keybd_event(0x4F, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x4C, 0x10, 0, 0);
        keybd_event(0x4C, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(0x44, 0x10, 0, 0);
        keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        keybd_event(VK_SPACE, 0x10, 0, 0);
        keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        PressNine();
        Sleep(100);
        keybd_event(VK_SPACE, 0x10, 0, 0);
        keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        PressNine();
        Sleep(100);
        keybd_event(VK_RETURN, 0x10, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);

        Sleep(700);
        keybd_event(VK_CONTROL, 0x10, 0, 0);
        Sleep(100);
        keybd_event(0x53, 0x10, 0, 0);
        Sleep(200);
        keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
        Sleep(200);
        keybd_event(VK_CONTROL, 0x10, KEYEVENTF_KEYUP, 0);
    } else {
        MessageBoxA(NULL, "Voce precisa abrir o jogo para inserir os comandos de free!", "Error", MB_ICONEXCLAMATION|MB_OK);
    }
}

void myCreateProcess (LPCTSTR lpApplicationName, LPCTSTR lpCurrentDirectory) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    if (!CreateProcessA(lpApplicationName, NULL, NULL, NULL, FALSE, 0, NULL, lpCurrentDirectory, &si, &pi)) {
        MessageBoxA(NULL, "Erro ao criar processo", "Error", MB_ICONEXCLAMATION|MB_OK);
    }
}


DWORD WINAPI myThreadLoginWithAccont(LPVOID lpParameter) {
    int acc = *(int*) lpParameter;
    int protectLoop = 0;
    char dirGt[MAX_PATH];
    char dirGB[MAX_PATH];
    HWND myGB = NULL;
    DWORD myDwPIDGB = 0;
    char HWND_TITLE[100];
    bool isPrevOrNext = FALSE;
    char myKey[] = "JUfjkrSnidorg";
    if(handleGB1 != NULL){
        if(!IsWindow(handleGB1)){
            handleGB1 = NULL;
            SendMessage(labelhwndl1, WM_SETTEXT, 0, (LPARAM)"");
        }
    }
    if(handleGB2 != NULL){
        if(!IsWindow(handleGB2)){
            handleGB2 = NULL;
            SendMessage(labelhwndl2, WM_SETTEXT, 0, (LPARAM)"");
        }
    }
    if(handleGB1 == NULL && handleGB2 == NULL){
        DWORD dwProcessIDGB1;
        myGB = FindWindow("Softnyx", NULL);
        HANDLE handleGB;
        if(myGB != NULL){
            GetWindowThreadProcessId(myGB, &dwProcessIDGB1);
            handleGB = OpenProcess(PROCESS_ALL_ACCESS,false,dwProcessIDGB1);
            TerminateProcess(handleGB,1);
        }
    }
    if(handleGB1 != NULL && handleGB2 != NULL){
        if(IsWindow(handleGB1) && IsWindow(handleGB2)){
            MessageBoxA(NULL, "Voce já esta com as 2 contas abertas!", "Warning", MB_ICONEXCLAMATION|MB_OK);
            isThreads = FALSE;
            return 0;
        }
    }
    if((acc = 1) && (handleGB1 != NULL) && IsWindow(handleGB1) ){
        MessageBoxA(NULL, "Voce já esta com a primeira conta aberta!", "Warning", MB_ICONEXCLAMATION|MB_OK);
        isThreads = FALSE;
        return 0;
    }
    if((acc = 2) && (handleGB2 != NULL) && IsWindow(handleGB2)){
        MessageBoxA(NULL, "Voce já esta com a segunda conta aberta!", "Warning", MB_ICONEXCLAMATION|MB_OK);
        isThreads = FALSE;
        return 0;
    }
    //system("date 02-04-19");
    //system("time 23:00");
    strcpy(dirGB,dirGBPath);
    GetPrivateProfileString("Dir", "Greta", NULL, dirGt, sizeof(dirGt), dirIniFile);
    if(strlen(dirGt) > 0 && strlen(dirGB) > 0) {
        string pathFileGt;
        pathFileGt = string(dirGt);
        pathFileGt += "GretaGB73V.exe";
        string pathIniFileGt;
        pathIniFileGt = string(dirGt);
        pathIniFileGt += "GretaGB.cfg";
        string pathIniFileGB;
        pathIniFileGB = string(dirGB);
        pathIniFileGB += "NyxLauncher.ini";
        char login[70];
        char password[70];
        if (acc == 1) {
            SendMessage(textLogin1, WM_GETTEXT, sizeof(login), (LPARAM)login);
            if(isCryptPw1) {
                GetPrivateProfileString("Acc1_GB", "Pw", NULL, password, sizeof(password), dirIniFile);
                strcpy(password, decrypt(password, strlen(password), myKey).c_str());
            } else {
                SendMessage(textPw1, WM_GETTEXT, sizeof(password), (LPARAM)password);
            }
        } else if(acc == 2) {
            SendMessage(textLogin2, WM_GETTEXT, sizeof(login), (LPARAM)login);
            if(isCryptPw2) {
                GetPrivateProfileString("Acc2_GB", "Pw", NULL, password, sizeof(password), dirIniFile);
                strcpy(password, decrypt(password, strlen(password), myKey).c_str());
            } else {
                SendMessage(textPw2, WM_GETTEXT, sizeof(password), (LPARAM)password);
            }
        }
        if (strlen(login) > 0 && strlen(password) > 0) {
            WritePrivateProfileString("GunBound", "User", login, pathIniFileGt.c_str());
            WritePrivateProfileString("NyxLauncher", "SavedID", login, pathIniFileGB.c_str());
            myCreateProcess(pathFileGt.c_str(), dirGt);
            HWND windowGreta = FindWindowA(NULL, "GretaGB7");
            HWND buttonLogin = NULL;
            while(windowGreta == NULL && protectLoop <= 1700) {
                windowGreta = FindWindowA(NULL, "GretaGB7");
                if (windowGreta == NULL){
                    Sleep(10);
                    protectLoop += 1;
                }
            }
            if(protectLoop >= 1700){
                protectLoop = 0;
                isThreads = FALSE;
                MessageBoxA(NULL, "Nao foi possivel iniciarlizar o greta!", "Warning", MB_ICONEXCLAMATION|MB_OK);
                return 0;
            }
            protectLoop = 0;
            while(!IsWindowVisible(windowGreta) && protectLoop <= 1700) {
                if(!IsWindowVisible(windowGreta)){
                    Sleep(10);
                    protectLoop += 1;
                }
            }
            protectLoop = 0;
            while(IsWindowVisible(windowGreta) && protectLoop <= 1700) {
                if(windowGreta != NULL && IsWindowVisible(windowGreta)) {
                    ShowWindow(windowGreta, SW_HIDE);
                    Sleep(10);
                    protectLoop += 1;
                }
            }
            protectLoop = 0;
            Sleep(100);
            while(windowGreta != NULL && protectLoop <= 47) {
                windowGreta = FindWindowA(NULL, "GretaGB7");
                if(windowGreta != NULL)
                    buttonLogin = FindWindowEx(windowGreta, NULL, "Button", NULL);
                if(buttonLogin != NULL)
                    SendMessage(buttonLogin, BM_CLICK, 0, 0);
                if(windowGreta != NULL){
                    Sleep(400);
                    protectLoop += 1;
                }
            }
            protectLoop = 0;
            WritePrivateProfileString("GunBound", "User", login, pathIniFileGt.c_str());
            WritePrivateProfileString("NyxLauncher", "SavedID", login, pathIniFileGB.c_str());
            HWND windowSoftnyxLauncher = FindWindow(NULL, "Softnyx Game Launcher");
            while(windowSoftnyxLauncher == NULL && protectLoop <= 1700) {
                windowSoftnyxLauncher = FindWindowA(NULL, "Softnyx Game Launcher");
                if (windowSoftnyxLauncher == NULL){
                    Sleep(10);
                    protectLoop += 1;
                }
            }
            protectLoop = 0;
            while(!IsWindowVisible(windowSoftnyxLauncher) && protectLoop <= 1700) {
                if(!IsWindowVisible(windowSoftnyxLauncher)){
                    Sleep(10);
                    protectLoop += 1;
                }
            }
            protectLoop = 0;
            while(IsWindowVisible(windowSoftnyxLauncher) && protectLoop <= 1700) {
                if(windowSoftnyxLauncher != NULL && IsWindowVisible(windowSoftnyxLauncher)) {
                    ShowWindow(windowSoftnyxLauncher, SW_HIDE);
                    Sleep(10);
                    protectLoop += 1;
                }
            }
            protectLoop = 0;
            HWND EditGB = FindWindowEx(windowSoftnyxLauncher, NULL, "Edit", NULL);
            char buffer[100];
            while(strlen(buffer) != 85 && protectLoop <= 1700) {
                SendMessage(EditGB, WM_GETTEXT, sizeof(buffer), (LPARAM)buffer);
                Sleep(10);
                protectLoop += 1;
            }
            protectLoop = 0;
            ShowWindow(windowSoftnyxLauncher, SW_HIDE);
            char HWND_TITLE[20];
            int nEdit = 0;
            while(true) {
                GetClassName(EditGB, HWND_TITLE, sizeof(HWND_TITLE));
                if(strcmp(HWND_TITLE, "Edit") == 0) {
                    nEdit += 1;
                    if(nEdit == 2) {
                        SendMessage(EditGB, WM_SETTEXT, sizeof(login), (LPARAM) login);
                    } else if(nEdit == 3) {
                        SendMessage(EditGB, WM_SETTEXT, sizeof(password), (LPARAM) password);
                        while(windowSoftnyxLauncher != NULL) {
                            Sleep(1550);
                            SendMessageA(windowSoftnyxLauncher, WM_IME_KEYDOWN, VK_RETURN, 0);
                            Sleep(50);
                            SendMessageA(windowSoftnyxLauncher, WM_IME_KEYUP, VK_RETURN, 0);
                            Sleep(1500);
                            windowSoftnyxLauncher = FindWindowA(NULL, "Softnyx Game Launcher");
                        }
                    }
                }
                EditGB = GetNextWindow(EditGB, GW_HWNDNEXT);
                if(EditGB == NULL)
                    break;
            }
        } else {
            MessageBoxA(NULL, "Insira o login e senha!", "Error", MB_ICONEXCLAMATION|MB_OK);
        }
    } else {
        MessageBoxA(NULL, "Configure o diretorio do greta no myConf.ini", "Error", MB_ICONEXCLAMATION|MB_OK);
    }
    if(acc == 1){
        if(handleGB2 == NULL){
            myGB = FindWindow(NULL, "GunboundS3");
            while(myGB == NULL){
                myGB = FindWindow(NULL, "GunboundS3");
                Sleep(10);
            }
            while(!IsWindowVisible(myGB)){
                Sleep(10);
            }
            Sleep(1500);
            handleGB1 = myGB;
            GetWindowThreadProcessId(handleGB1, &dwProcessIDGB1);
        }else{
            myGB = FindWindow(NULL, "GunboundS3");
            while(true){
                myGB = FindWindow(NULL, "GunboundS3");
                GetWindowThreadProcessId(myGB, &myDwPIDGB);
                GetClassName(myGB, HWND_TITLE, sizeof(HWND_TITLE));
                if(strcmp(HWND_TITLE, "Softnyx") == 0){
                    if(myDwPIDGB != dwProcessIDGB2){
                        handleGB1 = myGB;
                        dwProcessIDGB1 = myDwPIDGB;
                        break;
                    }
                }
                if (!isPrevOrNext) myGB = GetNextWindow(myGB, GW_HWNDNEXT);
                if (isPrevOrNext) myGB = GetNextWindow(myGB, GW_HWNDPREV);
                if(myGB == NULL && !isPrevOrNext) isPrevOrNext = TRUE;
                if(myGB == NULL && isPrevOrNext) isPrevOrNext = FALSE;
            }
        }
        stringstream  wss;
        wss << (void*)handleGB1;
        SendMessage(labelhwndl1, WM_SETTEXT, 0, (LPARAM)wss.str().c_str());
    }else{
        if(handleGB1 == NULL){
            myGB = FindWindow(NULL, "GunboundS3");
            while(myGB == NULL){
                myGB = FindWindow(NULL, "GunboundS3");
                Sleep(10);
            }
            while(!IsWindowVisible(myGB)){
                Sleep(10);
            }
            Sleep(1500);
            handleGB2 = myGB;
            GetWindowThreadProcessId(handleGB2, &dwProcessIDGB2);
        }else{
            myGB = FindWindow(NULL, "GunboundS3");
            while(true){
                myGB = FindWindow(NULL, "GunboundS3");
                GetWindowThreadProcessId(myGB, &myDwPIDGB);
                GetClassName(myGB, HWND_TITLE, sizeof(HWND_TITLE));
                if(strcmp(HWND_TITLE, "Softnyx") == 0){
                    if(myDwPIDGB != dwProcessIDGB1){
                        handleGB2 = myGB;
                        dwProcessIDGB2 = myDwPIDGB;
                        break;
                    }
                }
                if (!isPrevOrNext) myGB = GetNextWindow(myGB, GW_HWNDNEXT);
                if (isPrevOrNext) myGB = GetNextWindow(myGB, GW_HWNDPREV);
                if(myGB == NULL && !isPrevOrNext) isPrevOrNext = TRUE;
                if(myGB == NULL && isPrevOrNext) isPrevOrNext = FALSE;
            }
        }
        stringstream  wss;
        wss << (void*)handleGB2;
        SendMessage(labelhwndl2, WM_SETTEXT, 0, (LPARAM)wss.str().c_str());
    }
    if(isThreads){
        Sleep(2000);
        isThreads = FALSE;
    }
    return 0;
}

void loginWithAccont(int acc) {
    int *acc1 = (int *)malloc(sizeof(int));
    *acc1 = acc;
    if(!isThreads) {
        CreateThread(0, 0, myThreadLoginWithAccont, acc1, 0, NULL);
        isThreads = TRUE;
    } else {
        MessageBox(NULL, "Ja existe progresso em andamento!\nAguarde...", "Warning", MB_ICONEXCLAMATION|MB_OK);
    }
    free(acc1);
}

void ShowContextMenu(HWND hwnd) {
    POINT pt;
    GetCursorPos(&pt);
    HMENU hMenu = CreatePopupMenu();
    if (hMenu) {
        if(IsWindowVisible(hwnd))
            InsertMenu(hMenu, -1, MF_BYPOSITION, APP_HIDE, "Hide");
        else
            InsertMenu(hMenu, -1, MF_BYPOSITION, APP_SHOW, "Show");
        InsertMenu(hMenu, -1, MF_BYPOSITION, APP_EXIT, "Exit");
        SetForegroundWindow(hwnd);
        TrackPopupMenu(hMenu, TPM_BOTTOMALIGN, pt.x, pt.y, 0, hwnd, NULL);
        DestroyMenu(hMenu);
    }
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case APPWM_ICONNNOTIFY:
        switch(lParam) {
        case WM_LBUTTONUP:
            if(IsWindowVisible(hwnd)) {
                ShowWindow(hwnd, SW_HIDE);
            } else {
                ShowWindow(hwnd, SW_RESTORE);
            }
            break;
        case WM_RBUTTONUP:
            ShowContextMenu(hwnd);
            break;
        case WM_CONTEXTMENU:
            ShowContextMenu(hwnd);
            break;
        }
        break;
    case WM_SYSCOMMAND:
        if((wParam & 0xFFF0) == SC_MINIMIZE) {
            ShowWindow(hwnd, SW_HIDE);
            return 1;
        }
        break;
    case WM_CTLCOLORSTATIC:
    {
        long idMyStatics = GetWindowLong((HWND)lParam, GWL_ID);
        if(idMyStatics >= 13 && idMyStatics <= 16) {
            SetBkMode((HDC)wParam, TRANSPARENT);
            SetTextColor((HDC)wParam, RGB(217, 244, 66));
        }
        return (INT_PTR)GetStockObject(NULL_BRUSH);
    }
    break;
    case WM_COMMAND:
        switch(wParam) {
        case BTN_Login1:
            loginWithAccont(1);
            break;
        case BTN_Login2:
            loginWithAccont(2);
            break;
        case BTN_AutoFree:
            startAutoFreeCommands();
            break;
        case BTN_DONATION:
            ShellExecute(0, 0, "https://www.mercadopago.com/mlb/checkout/start?pref_id=131125171-331fe606-472d-4bef-bbee-3aaa48f5aee1", 0, 0, SW_SHOW);
            break;
        }
        switch(LOWORD(wParam)) {
        case APP_HIDE:
            ShowWindow(hwnd, SW_HIDE);
            break;
        case APP_SHOW:
            ShowWindow(hwnd, SW_RESTORE);
            break;
        case APP_EXIT:
            DestroyWindow(hwnd);
            break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        nid.uFlags = 0;
        Shell_NotifyIconA(NIM_DELETE, &nid);
        PostQuitMessage (0);
        break;
    default:
        return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return DefWindowProc (hwnd, message, wParam, lParam);
}

int myWinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance,LPSTR lpszArgument,int nCmdShow) {
    char szClassName[ ] = "openGretaWithGB";
    MSG messages;
    WNDCLASSEX wincl;
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIconA(hThisInstance, MAKEINTRESOURCE(TRAY_ICON));
    wincl.hIconSm = LoadIconA(hThisInstance, MAKEINTRESOURCE(TRAY_ICON));
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = CreatePatternBrush((HBITMAP) LoadImageA(hThisInstance,MAKEINTRESOURCE(BACKGROUND_BMP),
                          IMAGE_BITMAP,0,0,
                          LR_CREATEDIBSECTION));
    if (!RegisterClassEx (&wincl))
        return 0;
    hwnd = CreateWindowExA (
               WS_EX_APPWINDOW|WS_EX_CLIENTEDGE|WS_EX_COMPOSITED|WS_EX_DLGMODALFRAME|WS_EX_NOINHERITLAYOUT|WS_EX_WINDOWEDGE,
               szClassName,
               "open Greta With GB",
               WS_MINIMIZEBOX|WS_SYSMENU|WS_CAPTION|WS_BORDER|WS_VISIBLE|WS_TILED,
               CW_USEDEFAULT,
               CW_USEDEFAULT,
               544,250,
               HWND_DESKTOP,
               NULL,
               hThisInstance,
               NULL
           );

    myWindows(hThisInstance, hwnd);
    ShowWindow (hwnd, nCmdShow);
    //ShowWindow (hwnd, SW_HIDE);
    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}
