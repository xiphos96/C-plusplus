// Hello.h : CHello의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.


// IHello
[
	object,
	uuid("41EF5B75-EB72-4B62-A335-F927F97D1B1A"),
	helpstring("IHello 인터페이스"),
	pointer_default(unique)
]
__interface IHello : IUnknown
{
	[helpstring("메서드 sayHello")] HRESULT sayHello([in] wchar_t* name, [out] wchar_t** message);
};



// CHello

[
	coclass,
	threading("apartment"),
	vi_progid("HelloServer.Hello"),
	progid("HelloServer.Hello.1"),
	version(1.0),
	uuid("0925C1AB-9BE3-44BE-AA11-0BEA2129ACE2"),
	helpstring("Hello Class")
]
class ATL_NO_VTABLE CHello : 
	public IHello
{
public:
	CHello()
	{
	}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:

	STDMETHOD(sayHello)(wchar_t* name, wchar_t** message);
};

