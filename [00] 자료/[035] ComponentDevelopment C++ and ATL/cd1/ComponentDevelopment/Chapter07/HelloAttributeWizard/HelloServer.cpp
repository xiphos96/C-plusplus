// HelloServer.cpp : DLL 내보내기의 구현입니다.

#include "stdafx.h"
#include "resource.h"

// 모듈 특성에 의해 DllMain, DllRegisterServer 및 DllUnregisterServer가 자동으로 구현됩니다.
[ module(dll, uuid = "{7BA0C5C3-0DDE-4429-A2E1-1667B4BF0D46}", 
		 name = "HelloServer", 
		 helpstring = "HelloServer 1.0 형식 라이브러리",
		 resource_name = "IDR_HELLOSERVER") ]
class CHelloServerModule
{
public:
// CAtlDllModuleT 멤버를 재정의합니다.
};
		 
