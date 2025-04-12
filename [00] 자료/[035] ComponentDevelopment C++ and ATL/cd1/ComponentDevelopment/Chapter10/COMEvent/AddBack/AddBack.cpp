// AddBack.cpp : DLL 내보내기의 구현입니다.

#include "stdafx.h"
#include "resource.h"

// 모듈 특성에 의해 DllMain, DllRegisterServer 및 DllUnregisterServer가 자동으로 구현됩니다.
[ module(dll, uuid = "{A0938237-41D8-4A07-A06D-B4ED2706E777}", 
		 name = "AddBack", 
		 helpstring = "AddBack 1.0 형식 라이브러리",
		 resource_name = "IDR_ADDBACK") ]
class CAddBackModule
{
public:
// CAtlDllModuleT 멤버를 재정의합니다.
};
		 
