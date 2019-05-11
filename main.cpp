#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif
#include <windows.h>
#include <commctrl.h>
#include "resource.h"
#include <string>
#include <iostream>
#include "init.h"
#include "myWindows.h"
#include "myWinMain.h"


int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance,LPSTR lpszArgument,int nCmdShow){
    exePath();
    gbPath();
    checkMyIniFile();
    return myWinMain(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);
}
