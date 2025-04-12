// AddBacko.h : CAddBack의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "AddBack.h"
#include "_IAddBackEvents_CP.h"
#include "IAddBackEvents_CP.H"


// CAddBack

class ATL_NO_VTABLE CAddBack : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAddBack, &CLSID_AddBack>,
	public IConnectionPointContainerImpl<CAddBack>,
	public IDispatchImpl<IAddBack, &IID_IAddBack, &LIBID_AddBackLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IProvideClassInfo2Impl<&CLSID_AddBack, &DIID__IAddBackEvents, &LIBID_AddBackLib, 1, 0>,
	public CProxy_IAddBackEvents<CAddBack>, 
	public CProxyIAddBackEvents<CAddBack>
{
public:
	CAddBack()
	{
		m_Sum = 0;
		m_AddEnd = 10;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ADDBACK1)


BEGIN_COM_MAP(CAddBack)
	COM_INTERFACE_ENTRY(IAddBack)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CAddBack)
	CONNECTION_POINT_ENTRY(__uuidof(IAddBackEvents))
	CONNECTION_POINT_ENTRY(__uuidof(_IAddBackEvents))
END_CONNECTION_POINT_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:
	STDMETHOD(Add)(void);
	STDMETHOD(AddTen)(void);
	STDMETHOD(Clear)(void);
	STDMETHOD(get_AddEnd)(SHORT* pVal);
	STDMETHOD(put_AddEnd)(SHORT newVal);
	STDMETHOD(get_Sum)(SHORT* pVal);
private:
	SHORT m_Sum;
	SHORT m_AddEnd;

	void FireChangedAddEnd() {
		CProxy_IAddBackEvents<CAddBack>::Fire_ChangedAddEnd(m_AddEnd);
		CProxyIAddBackEvents<CAddBack>::Fire_ChangedAddEnd(m_AddEnd);
	}

	void FireChangedSum() {
		CProxy_IAddBackEvents<CAddBack>::Fire_ChangedSum(m_Sum);
		CProxyIAddBackEvents<CAddBack>::Fire_ChangedSum(m_Sum);
	}
};

OBJECT_ENTRY_AUTO(__uuidof(AddBack), CAddBack)
