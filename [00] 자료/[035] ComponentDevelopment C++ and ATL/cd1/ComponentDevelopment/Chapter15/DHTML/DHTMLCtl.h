// DHTMLCtl.h : CDHTMLCtl의 선언입니다.
#pragma once
#include "resource.h"       // 주 기호입니다.
#include <atlctl.h>

[
	object, 
	dual,
	uuid(CC72F349-A155-4E77-BAE6-29EEB8355AC0),
	helpstring("IDHTMLCtlUI 인터페이스"),
	pointer_default(unique)
]
__interface IDHTMLCtlUI : IDispatch
{
	// HTML에서 호출할 예제 메서드입니다.
	[id(1)] HRESULT OnClick([in]IDispatch* pdispBody, [in]VARIANT varColor);
	[id(2), helpstring("메서드 GoTo")] HRESULT GoTo(void);
};

// 인터페이스 정의 위치 변경 <- UI 클래스에서 컨트롤 인터페이스를 참조할 수 있도록
// IDHTMLCtl
[
	object,
	uuid(301363E5-1A3D-45E5-9AC5-0D8596AF5F86),
	dual,
	helpstring("IDHTMLCtl 인터페이스"),
	pointer_default(unique)
]
__interface IDHTMLCtl : public IDispatch
{
	[propget, id(1), helpstring("속성 UrlPath")] HRESULT UrlPath([out, retval] BSTR* pVal);
	[propput, id(1), helpstring("속성 UrlPath")] HRESULT UrlPath([in] BSTR newVal);
	[id(2), helpstring("메서드 GoToURL")] HRESULT GoToURL(void);
};

[
	coclass,
	threading("apartment"),
	version(1.0),
	uuid("542F7C7E-4296-4389-9A23-33196246AC1F"),
	noncreatable
]
class ATL_NO_VTABLE CDHTMLCtlUI :
	public IDHTMLCtlUI
{
public:
	// UI 클래스에서 컨트롤 인터페이스를 호출할 수 있도록 추가함
	CComQIPtr<IDHTMLCtl> m_pCtrl;

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

	// <BODY> 배경색을 변경하기 위해 HTML에서 호출한 예제 메서드입니다.
	STDMETHOD(OnClick)(IDispatch* pdispBody, VARIANT varColor)
	{
		CComQIPtr<IHTMLBodyElement> spBody(pdispBody);
		if (spBody != NULL)
			spBody->put_bgColor(varColor);
		return S_OK;
	}
	STDMETHOD(GoTo)(void);
};



// CDHTMLCtl
[
	coclass,
	threading("apartment"),
	vi_progid("DHTML.DHTMLCtl"),
	progid("DHTML.DHTMLCtl.1"),
	version(1.0),
	uuid("73FED92B-DA89-4C5D-A99E-9C15E9D480E9"),
	helpstring("DHTMLCtl Class"),
	support_error_info(IDHTMLCtl),
	registration_script("control.rgs")
]
class ATL_NO_VTABLE CDHTMLCtl : 
	public IDHTMLCtl,
	public IPersistStreamInitImpl<CDHTMLCtl>,
	public IOleControlImpl<CDHTMLCtl>,
	public IOleObjectImpl<CDHTMLCtl>,
	public IOleInPlaceActiveObjectImpl<CDHTMLCtl>,
	public IViewObjectExImpl<CDHTMLCtl>,
	public IOleInPlaceObjectWindowlessImpl<CDHTMLCtl>,
	public IPersistStorageImpl<CDHTMLCtl>,
	public ISpecifyPropertyPagesImpl<CDHTMLCtl>,
	public IQuickActivateImpl<CDHTMLCtl>,
	public IDataObjectImpl<CDHTMLCtl>,
	public IProvideClassInfo2Impl<&__uuidof(CDHTMLCtl), NULL>,
	public CComControl<CDHTMLCtl>
{
public:

	CDHTMLCtl()
	{
		m_bWindowOnly = TRUE;
		m_urlpath = CComBSTR("www.microsoft.com/korea/msdn");
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE | 
	OLEMISC_CANTLINKINSIDE | 
	OLEMISC_INSIDEOUT | 
	OLEMISC_ACTIVATEWHENVISIBLE | 
	OLEMISC_SETCLIENTSITEFIRST
)


BEGIN_PROP_MAP(CDHTMLCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// 예제 항목
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
	PROP_ENTRY("UrlPath", 1, CLSID_NULL)
END_PROP_MAP()


BEGIN_MSG_MAP(CDHTMLCtl)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	CHAIN_MSG_MAP(CComControl<CDHTMLCtl>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// 처리기 프로토타입:
// LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
// LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
// LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IDHTMLCtl

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		CAxWindow wnd(m_hWnd);
		wnd.ModifyStyle(0, WS_HSCROLL | WS_VSCROLL);
		HRESULT hr = wnd.CreateControl(IDH_DHTMLCTL);
		if (SUCCEEDED(hr))
		{
			CComObject<CDHTMLCtlUI> *pObject = NULL;
			hr = CComObject<CDHTMLCtlUI>::CreateInstance(&pObject);
			if (SUCCEEDED(hr) && pObject != NULL) {
				// UI 클래스에서 컨트롤을 호출할 수 있도록 추가함
				pObject->m_pCtrl = (IDHTMLCtl*)this;
				hr = wnd.SetExternalDispatch(static_cast<IDHTMLCtlUI*>(pObject));
			}
		}
		if (SUCCEEDED(hr))
			hr = wnd.QueryControl(IID_IWebBrowser2, (void**)&m_spBrowser);
		return SUCCEEDED(hr) ? 0 : -1;
	}

	STDMETHOD(TranslateAccelerator)(LPMSG pMsg)
	{
		CComPtr<IOleInPlaceActiveObject> spIOleInPlaceActiveObject;
		
		HRESULT hr = m_spBrowser->QueryInterface(&spIOleInPlaceActiveObject);
		if (SUCCEEDED(hr))
			hr = spIOleInPlaceActiveObject->TranslateAccelerator(pMsg);
		if (hr != S_OK)
			hr = IOleInPlaceActiveObjectImpl<CDHTMLCtl>::TranslateAccelerator(pMsg);

		return hr;
	}
	CComPtr<IWebBrowser2> m_spBrowser;

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}
	STDMETHOD(get_UrlPath)(BSTR* pVal);
	STDMETHOD(put_UrlPath)(BSTR newVal);
protected:
	CComBSTR m_urlpath;
public:
	STDMETHOD(GoToURL)(void);

};

