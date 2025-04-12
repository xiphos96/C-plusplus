// Employee.h : CEmployee의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.


// IEmployee
[
	object,
	uuid("AD77D5D9-51A6-4D18-918F-8FCFB0DFC8CF"),
	dual,	helpstring("IEmployee 인터페이스"),
	pointer_default(unique)
]
__interface IEmployee : IDispatch
{
	[propget, id(1), helpstring("속성 Name")] HRESULT Name([out, retval] BSTR* pVal);
	[propget, id(2), helpstring("속성 Address")] HRESULT Address([out, retval] BSTR* pVal);
	[propget, id(3), helpstring("속성 Telephone")] HRESULT Telephone([out, retval] BSTR* pVal);
};



// CEmployee

[
	coclass,
	threading("apartment"),
	support_error_info("IEmployee"),
	aggregatable("never"),
	vi_progid("Company.Employee"),
	progid("Company.Employee.1"),
	version(1.0),
	uuid("BB84AD11-16E2-4196-88DB-EBC8E518DC33"),
	helpstring("Employee Class"),
	noncreatable
]
class ATL_NO_VTABLE CEmployee : 
	public IEmployee
{
public:
	friend class CEmployees;

	CEmployee()
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

	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_Address)(BSTR* pVal);
	STDMETHOD(get_Telephone)(BSTR* pVal);
protected:
	CComBSTR m_Name;
	CComBSTR m_Address;
	CComBSTR m_Telephone;
};

