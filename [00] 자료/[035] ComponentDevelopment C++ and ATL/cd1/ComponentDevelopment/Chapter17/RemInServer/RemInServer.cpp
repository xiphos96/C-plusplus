// RemInServer.cpp : DLL ���������� �����Դϴ�.

#include "stdafx.h"
#include "resource.h"
#include "RemInServer.h"

class CRemInServerModule : public CAtlDllModuleT< CRemInServerModule >
{
public :
	DECLARE_LIBID(LIBID_RemInServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_REMINSERVER, "{A4C9B793-5AF2-458F-BC5E-F577B354CEB9}")
};

CRemInServerModule _AtlModule;


// DLL �������Դϴ�.
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}


// DLL�� OLE�� ���� ��ε�� �� �ִ��� �����ϴ� �� ���˴ϴ�.
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// Ŭ���� ���͸��� ��ȯ�Ͽ� ��û�� ������ ��ü�� ����ϴ�.
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - �ý��� ������Ʈ���� �׸��� �߰��մϴ�.
STDAPI DllRegisterServer(void)
{
    // ��ü, ���� ���̺귯�� �� ���� ���̺귯���� ��� �ִ� ��� �������̽��� ����մϴ�.
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - �ý��� ������Ʈ������ �׸��� �����մϴ�.
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}
