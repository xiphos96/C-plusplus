// RemOutServer.h : CRemOutServer의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "RemOutServer.h"


// CRemOutServer

class ATL_NO_VTABLE CRemOutServer : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRemOutServer, &CLSID_RemOutServer>,
	public IAddEnd,
	public IAdd
{
public:
	CRemOutServer()
	{
		m_sum = 0;
		m_addend = 10;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_REMOUTOBJ)


BEGIN_COM_MAP(CRemOutServer)
	COM_INTERFACE_ENTRY(IAddEnd)
	COM_INTERFACE_ENTRY(IAdd)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:
	STDMETHOD(get_AddEnd)(SHORT* pVal);
	STDMETHOD(put_AddEnd)(SHORT newVal);
	STDMETHOD(get_Sum)(SHORT* pVal);
	STDMETHOD(Clear)(void);
	STDMETHOD(Add)(void);
	STDMETHOD(AddTen)(void);
private:
	SHORT m_sum;
	SHORT m_addend;

};

OBJECT_ENTRY_AUTO(__uuidof(RemOutServer), CRemOutServer)
