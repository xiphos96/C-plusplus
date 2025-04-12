// Test.h : Declaration of the CTest

#pragma once
#include "ObjectPooling.h"
#include "resource.h"       // main symbols
#include <comsvcs.h>


// CTest

class ATL_NO_VTABLE CTest : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public IObjectControl,
	public CComCoClass<CTest, &CLSID_Test>,
	public IDispatchImpl<ITest, &IID_ITest, &LIBID_ObjectPoolingLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTest()
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

DECLARE_REGISTRY_RESOURCEID(IDR_TEST)

BEGIN_COM_MAP(CTest)
	COM_INTERFACE_ENTRY(ITest)
	COM_INTERFACE_ENTRY(IObjectControl)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


// IObjectControl
public:
	STDMETHOD(Activate)();
	STDMETHOD_(BOOL, CanBePooled)();
	STDMETHOD_(void, Deactivate)();

	CComPtr<IObjectContext> m_spObjectContext;

// ITest
public:
};

OBJECT_ENTRY_AUTO(__uuidof(Test), CTest)
