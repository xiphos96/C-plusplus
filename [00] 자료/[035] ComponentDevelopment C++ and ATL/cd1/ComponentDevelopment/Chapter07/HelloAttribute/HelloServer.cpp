#pragma once
#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_ATTRIBUTES
#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE
#include <atlbase.h>
#include <atlcom.h>
#include <atlwin.h>
#include <atltypes.h>
#include <atlctl.h>
#include <atlhost.h>
using namespace ATL;

// HelloServer ���
[ module(dll, name = "HelloServer", 
		 helpstring = "HelloServer 1.0 ���� ���̺귯��") 
];
[ emitidl ];

// IHello �������̽�
[
	object,
	uuid("C4646F65-6C21-4051-8DA8-E0AC06BF1CEB"),
	helpstring("IHello �������̽�"),
	pointer_default(unique)
]
__interface IHello : IUnknown
{
	HRESULT sayHello([in]wchar_t* name, [out]wchar_t** message);
};

// CHello COM Ŭ����
[
	coclass,
	threading("apartment"),
	vi_progid("HelloServer.Hello"),
	progid("HelloServer.Hello.1"),
	version(1.0),
	uuid("D84CDA2F-5AF1-4e97-BE21-983E0AB93D67"),
	helpstring("Hello COM ��ü")
]
class ATL_NO_VTABLE CHello : public IHello
{
public:
	CHello(){
	}
	HRESULT sayHello(wchar_t* name, wchar_t** message) {
		char * buffer = (char*)::CoTaskMemAlloc(256);
		if(buffer == NULL)
			return E_FAIL;
	
		::wsprintf(buffer, "%s �� �ȳ��ϼ���?", name);
		*message = (wchar_t*)buffer;
	
		return S_OK;
	}
	
	DECLARE_PROTECT_FINAL_CONSTRUCT()
	HRESULT FinalConstruct() {
		return S_OK;
	}
	void FinalRelease() {
	}
};
