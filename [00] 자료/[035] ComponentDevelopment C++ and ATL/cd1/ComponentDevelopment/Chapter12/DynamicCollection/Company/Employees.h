// Employees.h : CEmployees의 선언입니다.

#pragma once
#include "CollectionSTL.h"
#include "resource.h"       // 주 기호입니다.



// IEmployees
[
	object,
	uuid("C6783455-282B-4AB5-BED5-C8D3A8C38E72"),
	dual,	helpstring("IEmployees 인터페이스"),
	pointer_default(unique)
]
__interface IEmployees : IDispatch
{
	[propget, id(1), helpstring("속성 Count")] HRESULT Count([out, retval] long* pVal);
	[propget, id(DISPID_VALUE), helpstring("속성 Item")] HRESULT Item([in] long index, [out, retval] IEmployee** pVal);
	[propget, id(DISPID_NEWENUM), helpstring("속성 _NewEnum")] HRESULT _NewEnum([out, retval] IUnknown** pVal);
	[id(2), helpstring("메서드 Add")] HRESULT Add([out,retval] IEmployee** retVal);
	[id(3), helpstring("메서드 Remove")] HRESULT Remove([in] long index);
};


typedef CComEnumOnSTL<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT,
                        _CopyVariantFromAdapt<IEmployee>,
                        list< CAdapt< CComPtr<IEmployee> > > >
        CComEnumVariantOnListOfIEmployee;


typedef ICollectionOnSTLImpl<IDispatchImpl<IEmployees, &__uuidof(IEmployees)>,
                             list< CAdapt< CComPtr<IEmployee> > >,
                             IEmployee*,
                             _CopyInterfaceFromAdapt<IEmployee>,
                             CComEnumVariantOnListOfIEmployee >
        IEmployeesCollImpl;


// CEmployees

[
	coclass,
	threading("apartment"),
	support_error_info("IEmployees"),
	aggregatable("never"),
	vi_progid("Company.Employees"),
	progid("Company.Employees.1"),
	version(1.0),
	uuid("6D52EEFB-AEE7-4C46-A472-9350BAC970F0"),
	helpstring("Employees Class"),
	noncreatable
]
class ATL_NO_VTABLE CEmployees : 
	// public IEmployees,
	public IEmployeesCollImpl
{
public:
	CEmployees()
	{
	}
	~CEmployees() {
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
	STDMETHOD(Add)(IEmployee** retVal);
	STDMETHOD(Remove)(long index);
};

