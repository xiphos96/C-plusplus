// CustInfo.cpp : DLL 내보내기의 구현입니다.

#include "stdafx.h"
#include "resource.h"

// 모듈 특성에 의해 DllMain, DllRegisterServer 및 DllUnregisterServer가 자동으로 구현됩니다.
[ module(dll, uuid = "{A3F6ED4A-C8B6-44D0-87CA-712031AF4B7F}", 
		 name = "CustInfo", 
		 helpstring = "CustInfo 1.0 형식 라이브러리",
		 resource_name = "IDR_CUSTINFO") ]
class CCustInfoModule
{
public:
// CAtlDllModuleT 멤버를 재정의합니다.
};
		 
