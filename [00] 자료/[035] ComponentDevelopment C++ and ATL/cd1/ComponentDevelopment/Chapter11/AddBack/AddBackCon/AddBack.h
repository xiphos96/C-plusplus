// AddBack.h : CAddBack의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#import "progid:AddEnd.AddEnd.1"

// IAddBack
[
	object,
	uuid("13D21EF3-5A50-4FCD-90B7-5984B97718E0"),
	dual,	helpstring("IAddBack 인터페이스"),
	pointer_default(unique)
]
__interface IAddBack : IDispatch
{
	[id(1), helpstring("메서드 Add")] HRESULT Add(void);
	[id(2), helpstring("메서드 AddTen")] HRESULT AddTen(void);
};

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
	[id(3), helpstring("메서드 Clear")] HRESULT Clear(void);
};

// CAddBack

[
	coclass,
	threading("apartment"),
	vi_progid("AddBackCon.AddBack"),
	progid("AddBackCon.AddBack.1"),
	version(1.0),
	uuid("05EFD227-B94B-4F18-B5AD-39037697EFF3"),
	helpstring("AddBack Class")
]
class ATL_NO_VTABLE CAddBack : 
	public IAddBack,
	public IAddEnd
{
public:
	CAddBack()
	{
	}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		m_pAddEnd.CoCreateInstance(__uuidof(AddEnd::CAddEnd));
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:
	// IAddBack 인터페이스 메서드
	STDMETHOD(Add)(void);
	STDMETHOD(AddTen)(void);
	// IAddEnd 인터페이스 메서드
	STDMETHOD(get_AddEnd)(SHORT* pVal);
	STDMETHOD(put_AddEnd)(SHORT newVal);
	STDMETHOD(get_Sum)(SHORT* pVal);
	STDMETHOD(Clear)(void);
private:
	CComPtr<AddEnd::IAddEnd> m_pAddEnd;
};

