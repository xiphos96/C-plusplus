// Companyo.h : CCompany의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "Employees.h"


// ICompany
[
	object,
	uuid("E261C0DF-C91A-4E10-ABC4-0A4099FC8E74"),
	dual,	helpstring("ICompany 인터페이스"),
	pointer_default(unique)
]
__interface ICompany : IDispatch
{
	[propget, id(1), helpstring("속성 Employees")] HRESULT Employees([out, retval] VARIANT* pVal);
};



// CCompany

[
	coclass,
	threading("apartment"),
	support_error_info("ICompany"),
	aggregatable("never"),
	vi_progid("Company.Company"),
	progid("Company.Company.1"),
	version(1.0),
	uuid("4BA637B8-6988-4452-925D-E3E9484E0882"),
	helpstring("Company Class")
]
class ATL_NO_VTABLE CCompany : 
	public ICompany
{
public:
	CCompany()
	{
		m_pEmployees = new CComObject<CEmployees>;
		m_pEmployees->Init();
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

	STDMETHOD(get_Employees)(VARIANT* pVal);

protected:
	CComObject<CEmployees>* m_pEmployees;
};

