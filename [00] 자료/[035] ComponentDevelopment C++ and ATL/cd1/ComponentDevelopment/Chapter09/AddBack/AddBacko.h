// AddBacko.h : CAddBack의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.


// IAddBack
[
	object,
	uuid("CE06761C-AF3B-4606-A6E9-CF7FE4DA1F2F"),
	dual,	helpstring("IAddBack 인터페이스"),
	pointer_default(unique)
]
__interface IAddBack : IDispatch
{
	[id(1), helpstring("메서드 Add")] HRESULT Add(void);
	[id(2), helpstring("메서드 AddTen")] HRESULT AddTen(void);
	[id(3), helpstring("메서드 Clear")] HRESULT Clear(void);
	[propget, id(4), helpstring("속성 AddEnd")] HRESULT AddEnd([out, retval] SHORT* pVal);
	[propput, id(4), helpstring("속성 AddEnd")] HRESULT AddEnd([in] SHORT newVal);
	[propget, id(5), helpstring("속성 Sum")] HRESULT Sum([out, retval] SHORT* pVal);
};



// CAddBack

[
	coclass,
	threading("apartment"),
	support_error_info("IAddBack"),
	vi_progid("AddBack.AddBack"),
	progid("AddBack.AddBack.1"),
	version(1.0),
	uuid("7C550737-8DD8-4091-BD15-18A43D74BD7A"),
	helpstring("AddBack Class")
]
class ATL_NO_VTABLE CAddBack : 
	public IAddBack
{
public:
	CAddBack()
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

	STDMETHOD(Add)(void);
	STDMETHOD(AddTen)(void);
	STDMETHOD(Clear)(void);
	STDMETHOD(get_AddEnd)(SHORT* pVal);
	STDMETHOD(put_AddEnd)(SHORT newVal);
	STDMETHOD(get_Sum)(SHORT* pVal);
private:
	SHORT m_Sum;
	SHORT m_AddEnd;
};

