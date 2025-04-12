// AddBack.cpp : DLL 내보내기의 구현입니다.

#include "stdafx.h"
#include "resource.h"

// 모듈 특성에 의해 DllMain, DllRegisterServer 및 DllUnregisterServer가 자동으로 구현됩니다.
[ module(dll, uuid = "{26193A54-724C-40E8-ABE7-74E03CFD6AF9}", 
		 name = "AddBack", 
		 helpstring = "AddBack 1.0 형식 라이브러리",
		 resource_name = "IDR_ADDBACK") ]
class CAddBackModule
{
public:
// CAtlDllModuleT 멤버를 재정의합니다.
};
		 
