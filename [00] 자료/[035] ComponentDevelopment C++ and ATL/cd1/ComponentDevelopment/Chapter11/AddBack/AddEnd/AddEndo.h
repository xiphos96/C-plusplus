// AddEndo.h : CAddEnd의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.


// IAddEnd
[
	object,
	uuid("B60724AA-9874-4C9A-B53F-ED2FFD36738F"),
	dual,	helpstring("IAddEnd 인터페이스"),
	pointer_default(unique)
]
__interface IAddEnd : IDispatch
{
	[propget, id(1), helpstring("속성 AddEnd")] HRESULT AddEnd([out, retval] SHORT* pVal);
	[propput, id(1), helpstring("속성 AddEnd")] HRESULT AddEnd([in] SHORT newVal);
	[propget, id(2), helpstring("속성 Sum")] HRESULT Sum([out, retval] SHORT* pVal);
	[propput, id(2), helpstring("속성 Sum")] HRESULT Sum([in] SHORT newVal);
	[id(3), helpstring("메서드 Clear")] HRESULT Clear(void);
};



// CAddEnd

[
	coclass,
	threading("apartment"),
	vi_progid("AddEnd.AddEnd"),
	progid("AddEnd.AddEnd.1"),
	version(1.0),
	uuid("74FD8F48-4B50-4DB3-B195-B74A4B79393F"),
	helpstring("AddEnd Class"),
	aggregatable(allowed)
]
class ATL_NO_VTABLE CAddEnd : 
	public IAddEnd
{
public:
	CAddEnd()
	{
		m_Sum = 0;
		m_AddEnd = 10;
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

	STDMETHOD(get_AddEnd)(SHORT* pVal);
	STDMETHOD(put_AddEnd)(SHORT newVal);
	STDMETHOD(get_Sum)(SHORT* pVal);
	STDMETHOD(put_Sum)(SHORT newVal);
	STDMETHOD(Clear)(void);
private:
	SHORT m_Sum;
	SHORT m_AddEnd;
};

