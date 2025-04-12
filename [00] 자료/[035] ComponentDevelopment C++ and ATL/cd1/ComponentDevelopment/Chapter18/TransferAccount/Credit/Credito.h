// Credito.h : Declaration of the CCredit

#pragma once
#include "Credit.h"
#include "resource.h"       // main symbols
#include <comsvcs.h>
#include <mtxattr.h>


// CCredit

class ATL_NO_VTABLE CCredit : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCredit, &CLSID_Credit>,
	public IDispatchImpl<ICredit, &IID_ICredit, &LIBID_CreditLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCredit()
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

DECLARE_REGISTRY_RESOURCEID(IDR_CREDIT1)

DECLARE_NOT_AGGREGATABLE(CCredit)

BEGIN_COM_MAP(CCredit)
	COM_INTERFACE_ENTRY(ICredit)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


// ICredit
public:
	STDMETHOD(ChangeAccount)(long accountID, long amount);
};

OBJECT_ENTRY_AUTO(__uuidof(Credit), CCredit)
