// AddBack.h : CAddBack의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#import "progid:AddEnd.AddEnd.1" no_namespace named_guids


// IAddBack
[
	object,
	uuid("B91E5E26-3781-4D46-BFA2-1A7D44DA3CBF"),
	dual,	helpstring("IAddBack 인터페이스"),
	pointer_default(unique)
]
__interface IAddBack : IDispatch
{
	[id(1), helpstring("메서드 Add")] HRESULT Add(void);
	[id(2), helpstring("메서드 AddTen")] HRESULT AddTen(void);
};



// CAddBack

[
	coclass,
	threading("apartment"),
	vi_progid("AddBackAgg.AddBack"),
	progid("AddBackAgg.AddBack.1"),
	version(1.0),
	uuid("EA7EB9A7-BCA0-4833-8883-E4609A820FD5"),
	helpstring("AddBack Class"),
	aggregates(__uuidof(CAddEnd)),
	com_interface_entry("COM_INTERFACE_ENTRY(IAddBack)"),
	com_interface_entry("COM_INTERFACE_ENTRY(IDispatch)"),
	com_interface_entry("COM_INTERFACE_ENTRY_AGGREGATE(__uuidof(IAddEnd), m_pUnk.p)")
]
class ATL_NO_VTABLE CAddBack : 
	public IAddBack
{
public:
	CAddBack()
	{
		m_pUnk = 0;
	}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		m_pUnk.CoCreateInstance(__uuidof(CAddEnd), GetControllingUnknown());
		m_pAddEnd = m_pUnk;
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:

	STDMETHOD(Add)(void);
	STDMETHOD(AddTen)(void);
private:
	CComPtr<IUnknown> m_pUnk;
	CComQIPtr<IAddEnd, &__uuidof(IAddEnd)> m_pAddEnd;
};

