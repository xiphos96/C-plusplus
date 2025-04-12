// Debito.h : Declaration of the CDebit

#pragma once
#include "Debit.h"
#include "resource.h"       // main symbols
#include <comsvcs.h>
#include <mtxattr.h>


// CDebit

class ATL_NO_VTABLE CDebit : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDebit, &CLSID_Debit>,
	public IDispatchImpl<IDebit, &IID_IDebit, &LIBID_DebitLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDebit()
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

DECLARE_REGISTRY_RESOURCEID(IDR_DEBIT1)

DECLARE_NOT_AGGREGATABLE(CDebit)

BEGIN_COM_MAP(CDebit)
	COM_INTERFACE_ENTRY(IDebit)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


// IDebit
public:
	STDMETHOD(ChangeAccount)(long accountID, long amount);
};

OBJECT_ENTRY_AUTO(__uuidof(Debit), CDebit)
