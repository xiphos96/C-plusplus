// AddBack.h : CAddBack�� �����Դϴ�.

#pragma once
#include "resource.h"       // �� ��ȣ�Դϴ�.
#import "progid:AddEnd.AddEnd.1"

// IAddBack
[
	object,
	uuid("13D21EF3-5A50-4FCD-90B7-5984B97718E0"),
	dual,	helpstring("IAddBack �������̽�"),
	pointer_default(unique)
]
__interface IAddBack : IDispatch
{
	[id(1), helpstring("�޼��� Add")] HRESULT Add(void);
	[id(2), helpstring("�޼��� AddTen")] HRESULT AddTen(void);
};

// IAddEnd
[
	object,
	uuid("B60724AA-9874-4C9A-B53F-ED2FFD36738F"),
	dual,	helpstring("IAddEnd �������̽�"),
	pointer_default(unique)
]
__interface IAddEnd : IDispatch
{
	[propget, id(1), helpstring("�Ӽ� AddEnd")] HRESULT AddEnd([out, retval] SHORT* pVal);
	[propput, id(1), helpstring("�Ӽ� AddEnd")] HRESULT AddEnd([in] SHORT newVal);
	[propget, id(2), helpstring("�Ӽ� Sum")] HRESULT Sum([out, retval] SHORT* pVal);
	[id(3), helpstring("�޼��� Clear")] HRESULT Clear(void);
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
	// IAddBack �������̽� �޼���
	STDMETHOD(Add)(void);
	STDMETHOD(AddTen)(void);
	// IAddEnd �������̽� �޼���
	STDMETHOD(get_AddEnd)(SHORT* pVal);
	STDMETHOD(put_AddEnd)(SHORT newVal);
	STDMETHOD(get_Sum)(SHORT* pVal);
	STDMETHOD(Clear)(void);
private:
	CComPtr<AddEnd::IAddEnd> m_pAddEnd;
};

