// RoleCheck.h : Declaration of the CRoleCheck

#pragma once
#include "RoleSecurity.h"
#include "resource.h"       // main symbols
#include <comsvcs.h>


// CRoleCheck

class ATL_NO_VTABLE CRoleCheck : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRoleCheck, &CLSID_RoleCheck>,
	public IDispatchImpl<IRoleCheck, &IID_IRoleCheck, &LIBID_RoleSecurityLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CRoleCheck()
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

DECLARE_REGISTRY_RESOURCEID(IDR_ROLECHECK)

DECLARE_NOT_AGGREGATABLE(CRoleCheck)

BEGIN_COM_MAP(CRoleCheck)
	COM_INTERFACE_ENTRY(IRoleCheck)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


// IRoleCheck
public:
	STDMETHOD(SecurityCheck)(/*[out, retval]*/BSTR* result);
};

OBJECT_ENTRY_AUTO(__uuidof(RoleCheck), CRoleCheck)
