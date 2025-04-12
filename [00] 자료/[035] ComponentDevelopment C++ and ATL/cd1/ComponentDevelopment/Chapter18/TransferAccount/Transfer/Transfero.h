// Transfero.h : Declaration of the CTransfer

#pragma once
#include "Transfer.h"
#include "resource.h"       // main symbols
#include <comsvcs.h>
#include <mtxattr.h>


// CTransfer

class ATL_NO_VTABLE CTransfer : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTransfer, &CLSID_Transfer>,
	public IDispatchImpl<ITransfer, &IID_ITransfer, &LIBID_TransferLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTransfer()
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

DECLARE_REGISTRY_RESOURCEID(IDR_TRANSFER1)

DECLARE_NOT_AGGREGATABLE(CTransfer)

BEGIN_COM_MAP(CTransfer)
	COM_INTERFACE_ENTRY(ITransfer)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


// ITransfer
public:
	STDMETHOD(MoveMoney)(long srcAccount, long destAccount, long amount);
};

OBJECT_ENTRY_AUTO(__uuidof(Transfer), CTransfer)
