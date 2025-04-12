// Hello.h : CHello의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "HelloServer.h"


// CHello

class ATL_NO_VTABLE CHello : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHello, &CLSID_Hello>,
	public IHello
{
private:
	BSTR m_name;
public:
	CHello()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HELLO)


BEGIN_COM_MAP(CHello)
	COM_INTERFACE_ENTRY(IHello)
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

	STDMETHOD(sayHello)(wchar_t* name, wchar_t** message);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(put_Name)(BSTR newVal);
};

OBJECT_ENTRY_AUTO(__uuidof(Hello), CHello)
