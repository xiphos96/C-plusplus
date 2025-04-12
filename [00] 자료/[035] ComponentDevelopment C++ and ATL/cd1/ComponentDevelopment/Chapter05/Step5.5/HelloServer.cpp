#include "stdafx.h"
#include "HelloFactory.h"

BOOL OpenFactory(void);
BOOL CloseFactory(void);
void RegisterServer (void);
void UnregisterServer (void);
DWORD g_dwRegister;
CHelloFactory* g_pFactory;
HINSTANCE g_hInstance;

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	HRESULT hr;
	MSG msg;

	// COM 라이브러리를 초기화한다.
	hr = ::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if(FAILED(hr)) {
		MessageBox(NULL, "COM 라이브러리를 초기화할 수 없습니다!", NULL, MB_OK);
		return 0;
	}

	if (lstrcmpiA(lpCmdLine, "-Embedding") == 0 ||
		lstrcmpiA(lpCmdLine, "/Embedding") == 0)
		OpenFactory();
	if (lstrcmpiA(lpCmdLine, "-RegServer") == 0 ||
		lstrcmpiA(lpCmdLine, "/RegServer") == 0) {
		g_hInstance = hInstance;
		RegisterServer();
		return 0;
	}
	else
	if (lstrcmpiA(lpCmdLine, "-UnregServer") == 0 ||
		lstrcmpiA(lpCmdLine, "/UnregServer") == 0) {
		UnregisterServer();
		return 0;
	}

	// 메시지 루프
	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	CloseFactory();
	// COM 라이브러리를 해제한다.
	::CoUninitialize();

	return 0;
}

BOOL OpenFactory(void)
{
	BOOL bOK = FALSE;
	HRESULT hr;

	g_pFactory = new CHelloFactory;
	if(g_pFactory != NULL) {
		g_pFactory->AddRef();
		hr = ::CoRegisterClassObject(CLSID_Hello,
								  g_pFactory,
								  CLSCTX_LOCAL_SERVER,
								  REGCLS_MULTIPLEUSE,
								  &g_dwRegister);
		bOK = SUCCEEDED(hr);
		if(!bOK) {
			g_pFactory->Release();
			delete g_pFactory;
		}
	}
	else
		bOK = FALSE;
	return bOK;
}

BOOL CloseFactory(void)
{
	BOOL bOK = TRUE;
	HRESULT hr;

	if (g_dwRegister != 0) {
		hr = ::CoRevokeClassObject(g_dwRegister);
		if (FAILED(hr))
			bOK = FALSE;
	}
	if(g_pFactory)
		g_pFactory->Release();

	return bOK;
}

void CloseExe (void)
{
	if (g_cObjects == 0 && g_cLocks == 0)
		PostQuitMessage(0);
}

BOOL SetRegKeyValue(LPTSTR pszKey, 
					LPTSTR pszSubkey, 
					LPTSTR pszValue)
{
	BOOL bOk = FALSE;
	LONG ec;
	HKEY hKey;
	TCHAR szKey[256];

	lstrcpy(szKey, pszKey);

	if(NULL != pszSubkey) {
		lstrcat(szKey, TEXT("\\"));
		lstrcat(szKey, pszSubkey);
	}

	ec = RegCreateKeyEx(
			HKEY_CLASSES_ROOT,
			szKey,
			0,
			NULL,
			REG_OPTION_NON_VOLATILE,
			KEY_ALL_ACCESS,
			NULL,
			&hKey,
			NULL);

	if(ERROR_SUCCESS == ec) {
		if(NULL != pszValue) {
			ec = RegSetValueEx(
						hKey,
						NULL,
						0,
						REG_SZ,
						(BYTE *)pszValue,
						(lstrlen(pszValue)+1)*sizeof(TCHAR));
		}
		if(ERROR_SUCCESS == ec)
			bOk = TRUE;
		RegCloseKey(hKey);
	}

	return bOk;
}


void RegisterServer (void)
{
	HRESULT hr = NOERROR;
	TCHAR szID[129];
	TCHAR szCLSID[129];
	TCHAR szModulePath[MAX_PATH];
	wchar_t wszCLSID[129];

	GetModuleFileName(g_hInstance, szModulePath, 
		sizeof(szModulePath)/sizeof(TCHAR));
	StringFromGUID2(CLSID_Hello, wszCLSID, 128);
	wcstombs(szID, wszCLSID, 128) ;

	lstrcpy(szCLSID, TEXT("CLSID\\"));
	lstrcat(szCLSID, szID);
	SetRegKeyValue(
		TEXT("HelloServer.Hello.1"),
		NULL,
		TEXT("Hello COM 객체"));
	SetRegKeyValue(
		TEXT("HelloServer.Hello.1"),
		TEXT("CLSID"),
		szID);
	
	SetRegKeyValue(
		szCLSID,
		NULL,
		TEXT("Hello COM 객체"));
	SetRegKeyValue(
		szCLSID,
		TEXT("ProgID"),
		TEXT("HelloServer.Hello.1"));
	SetRegKeyValue(
		szCLSID,
		TEXT("LocalServer32"),
		szModulePath);
}

void UnregisterServer (void)
{
	HRESULT hr = NOERROR;
	TCHAR szID[129];
	TCHAR szCLSID[129];
	TCHAR szTemp[129];
	wchar_t wszCLSID[129];

	StringFromGUID2(CLSID_Hello, wszCLSID, 128);
	wcstombs(szID, wszCLSID, 128) ;

	lstrcpy(szCLSID, TEXT("CLSID\\"));
	lstrcat(szCLSID, szID);

	RegDeleteKey(HKEY_CLASSES_ROOT, 
		TEXT("HelloServer.Hello.1\\CLSID"));
	RegDeleteKey(HKEY_CLASSES_ROOT, 
		TEXT("HelloServer.Hello.1"));

	wsprintf(szTemp, TEXT("%s\\%s"), szCLSID, 
		TEXT("LocalServer32"));
	RegDeleteKey(HKEY_CLASSES_ROOT, szTemp);
	wsprintf(szTemp, TEXT("%s\\%s"), szCLSID, 
		TEXT("ProgID"));
	RegDeleteKey(HKEY_CLASSES_ROOT, szTemp);
	RegDeleteKey(HKEY_CLASSES_ROOT, szCLSID);
}

