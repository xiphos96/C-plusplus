// AddBacko.h : Declaration of the CAddBack

#pragma once
#include "AddBack.h"
#include "resource.h"       // main symbols
#include <comsvcs.h>


// CAddBack

class ATL_NO_VTABLE CAddBack : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAddBack, &CLSID_AddBack>,
	public IDispatchImpl<IAddBack, &IID_IAddBack, &LIBID_AddBackLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CAddBack()
		: m_sum(0)
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

DECLARE_REGISTRY_RESOURCEID(IDR_ADDBACK1)

DECLARE_NOT_AGGREGATABLE(CAddBack)

BEGIN_COM_MAP(CAddBack)
	COM_INTERFACE_ENTRY(IAddBack)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


// IAddBack
public:
	STDMETHOD(Add)(long addend);
private:
	int m_sum;
public:
	STDMETHOD(getSum)(long* sum);
};

OBJECT_ENTRY_AUTO(__uuidof(AddBack), CAddBack)
