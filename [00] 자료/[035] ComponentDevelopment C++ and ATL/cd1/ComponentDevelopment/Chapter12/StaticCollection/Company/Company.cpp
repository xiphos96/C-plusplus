// Company.cpp : DLL 내보내기의 구현입니다.

#include "stdafx.h"
#include "resource.h"

// 모듈 특성에 의해 DllMain, DllRegisterServer 및 DllUnregisterServer가 자동으로 구현됩니다.
[ module(dll, uuid = "{600CC229-9F29-4DAF-8B7C-F60789527F32}", 
		 name = "Company", 
		 helpstring = "Company 1.0 형식 라이브러리",
		 resource_name = "IDR_COMPANY") ]
class CCompanyModule
{
public:
// CAtlDllModuleT 멤버를 재정의합니다.
};
		 
