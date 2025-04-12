// AddBacko.h : CAddBack�� �����Դϴ�.

#pragma once
#include "resource.h"       // �� ��ȣ�Դϴ�.


// IAddBack
[
	object,
	uuid("D3AF576A-CDE3-4C6B-BBE4-678DEB0156B7"),
	dual,	helpstring("IAddBack �������̽�"),
	pointer_default(unique)
]
__interface IAddBack : IDispatch
{
	[id(1), helpstring("�޼��� Add")] HRESULT Add(void);
	[id(2), helpstring("�޼��� AddTen")] HRESULT AddTen(void);
	[id(3), helpstring("�޼��� Clear")] HRESULT Clear(void);
	[propget, id(4), helpstring("�Ӽ� AddEnd")] HRESULT AddEnd([out, retval] SHORT* pVal);
	[propput, id(4), helpstring("�Ӽ� AddEnd")] HRESULT AddEnd([in] SHORT newVal);
	[propget, id(5), helpstring("�Ӽ� Sum")] HRESULT Sum([out, retval] SHORT* pVal);
};


// _IAddBackEvents
[
	dispinterface,
	uuid("6B789D4F-B967-4F16-B0F2-32E2FDA6E05F"),
	helpstring("_IAddBackEvents �������̽�")
]
__interface _IAddBackEvents
{
	[id(1), helpstring("�޼��� ChangeAddEnd")] HRESULT ChangedAddEnd([in] SHORT newVal);
	[id(2), helpstring("�޼��� ChangedSum")] HRESULT ChangedSum([in] SHORT newVal);
};


// CAddBack

[
	coclass,
	threading("apartment"),
	event_source("com"),
	vi_progid("AddBack.AddBack"),
	progid("AddBack.AddBack.1"),
	version(1.0),
	uuid("F792F6D3-7005-4CB8-9C7F-35313B3ADE5B"),
	helpstring("AddBack Class")
]
class ATL_NO_VTABLE CAddBack : 
	public IAddBack
{
public:
	CAddBack()
	{
		m_AddEnd = 10;
		m_Sum = 0;
	}

	__event __interface _IAddBackEvents;

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

