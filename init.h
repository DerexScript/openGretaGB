#ifndef INIT_H
#define INIT_H

using namespace std;

NOTIFYICONDATA nid = {};
char dirIniFile[MAX_PATH];
char dirExePath[MAX_PATH];
char dirGBPath[MAX_PATH];

bool isCryptPw1 = FALSE;
bool isCryptPw2 = FALSE;
bool isLoginThreads = FALSE;
bool isCommandsThreads = FALSE;
bool isPesoThreads = FALSE;
bool isPesoOnOffL1 = FALSE;
bool isPesoOnOffL2 = FALSE;
HANDLE  pesoThreadL1;
HANDLE  pesoThreadL2;

HWND handleGB1 = NULL, handleGB2 = NULL;
DWORD dwProcessIDGB1 = 0, dwProcessIDGB2 = 0;


HKEY OpenRegistryKey(HKEY hRootKey, char strSubKey[]){
	HKEY hKey;
	LONG lError = RegOpenKeyEx(hRootKey, strSubKey, 0, KEY_ALL_ACCESS, &hKey);
	if(lError == ERROR_FILE_NOT_FOUND){
		MessageBoxA(NULL, "GunBound nao encontrado, favor reinstale o GunBound!", "Error", MB_ICONEXCLAMATION|MB_OK);
		exit(1);
	}
	if(lError != ERROR_SUCCESS){
		MessageBoxA(NULL, "GunBound nao encontrado, favor reinstale o GunBound!", "Error", MB_ICONEXCLAMATION|MB_OK);
		exit(1);
	}
	return hKey;
}

void GetValueFromRegistry(HKEY hRootKey, LPCTSTR lpValue, DWORD dtype){
    LONG lErr;
	char myBuffer[MAX_PATH];
	DWORD bufferSize = sizeof(myBuffer);
    lErr = RegQueryValueEx(hRootKey, lpValue, NULL, &dtype, (LPBYTE)&myBuffer, &bufferSize);
	if(ERROR_SUCCESS != lErr){
        MessageBoxA(NULL, "Não foi possível localizar a instalacao do seu GunBound.\nFavor reinstale seu GunBound", "Error", MB_ICONEXCLAMATION|MB_OK);
        exit(1);
	}else{
	    strcpy(dirGBPath, myBuffer);
	}
}

void gbPath(){
    char subKey[] = "SOFTWARE\\WOW6432Node\\SoftNyx\\GunboundPS";
    HKEY hKey = OpenRegistryKey(HKEY_LOCAL_MACHINE, subKey);
    GetValueFromRegistry(hKey, "Location", REG_SZ);
    RegCloseKey(hKey);
}

void exePath(){
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    string::size_type pos = string(buffer).find_last_of("\\/");
    strcpy(dirIniFile, (string(buffer).substr(0, pos+1)+"\\myConf.ini").c_str());
    strcpy(dirExePath, (string(buffer).substr(0, pos+1)).c_str());
}

void checkMyIniFile(){
    char myProfileString[10];
    GetPrivateProfileString("Dir", "Greta", NULL, myProfileString, sizeof(myProfileString), dirIniFile);
    switch(GetLastError()){
        case 0x2:
            WritePrivateProfileString("Dir", "Greta", "\n", dirIniFile);
            WritePrivateProfileString("Acc1_GB", "User", "", dirIniFile);
            WritePrivateProfileString("Acc1_GB", "Pw", "\n", dirIniFile);
            WritePrivateProfileString("Acc2_GB", "User", "", dirIniFile);
            WritePrivateProfileString("Acc2_GB", "Pw", "", dirIniFile);
        break;
    }
}
#endif //INIT_H
