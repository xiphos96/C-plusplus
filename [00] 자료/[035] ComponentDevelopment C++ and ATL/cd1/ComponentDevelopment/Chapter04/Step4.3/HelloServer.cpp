// HelloServer.cpp : DLL ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "HelloFactory.h"

LONG g_cObjects = 0;		// COM ��ü ī����

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
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
