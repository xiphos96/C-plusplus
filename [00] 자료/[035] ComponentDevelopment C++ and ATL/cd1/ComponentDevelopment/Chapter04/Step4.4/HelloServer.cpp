// HelloServer.cpp : DLL 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "HelloFactory.h"

LONG g_cObjects = 0;		// COM 객체 카운터
static HMODULE g_hModule = 0;

BOOL APIENTRY DllMain( HINSTANCE  hModule, 
                       DWORD  dwReason, 
                       LPVOID lpReserved
					 )
{
	switch(dwReason) {
     case DLL_PROCESS_ATTACH:
		// DLL 이 프로세스의 주소 영역에 맵핑됨.
		// DLL 초기화 코드
		g_hModule = hModule;
	   break;
	}
    return TRUE;
}

extern "C"
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	HRESULT hr = CLASS_E_CLASSNOTAVAILABLE;
	IUnknown* pUnk = NULL;

	if(rclsid == CLSID_Hello) {
		hr = E_OUTOFMEMORY;
		pUnk = new CHelloFactory;
	}

	if(pUnk != NULL) {
		hr = pUnk->QueryInterface(riid, ppv);
		if(FAILED(hr))
			delete pUnk;
	}

	return hr;
}

extern "C"
STDAPI DllCanUnloadNow(void)
{
	if(g_cObjects == 0)
		return S_OK;
	return S_FALSE;
}

BOOL SetRegKeyValue(LPTSTR pszKey, 
					LPTSTR pszSubkey, 
					LPTSTR pszValue); 

extern "C"
STDAPI DllRegisterServer (void)
{
	HRESULT hr = NOERROR;
	TCHAR szID[129];
	TCHAR szCLSID[129];
	TCHAR szModulePath[MAX_PATH];
	wchar_t wszCLSID[129];

	GetModuleFileName(g_hModule, szModulePath, 
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
		TEXT("InprocServer32"),
		szModulePath);

	return (hr);
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

