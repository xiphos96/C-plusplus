// RemOutServer.cpp : WinMain의 구현입니다.

#include "stdafx.h"
#include "resource.h"
#include "RemOutServer.h"

class CRemOutServerModule : public CAtlExeModuleT< CRemOutServerModule >
{
public :
	DECLARE_LIBID(LIBID_RemOutServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_REMOUTSERVER, "{D618655A-CEF6-44A1-B64E-D730DFB95577}")
};

CRemOutServerModule _AtlModule;


//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
                                LPTSTR /*lpCmdLine*/, int nShowCmd)
{
    return _AtlModule.WinMain(nShowCmd);
}

