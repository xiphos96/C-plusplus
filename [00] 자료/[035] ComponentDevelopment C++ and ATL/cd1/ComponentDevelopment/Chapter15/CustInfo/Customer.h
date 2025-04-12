// Customer.h : CCustomer의 선언입니다.
#pragma once
#include "resource.h"       // 주 기호입니다.
#include <comutil.h>
#include <atlctl.h>

// ICustomer
[
	object,
	uuid(49EF6A18-9E69-41F5-ABA5-127EF4AFC6AB),
	dual,
	helpstring("ICustomer 인터페이스"),
	pointer_default(unique)
]
__interface ICustomer : public IDispatch
{
	[propget, id(1), helpstring("속성 CustName")] HRESULT CustName([out, retval] BSTR* pVal);
	[propput, id(1), helpstring("속성 CustName")] HRESULT CustName([in] BSTR newVal);
	[propget, id(2), helpstring("속성 CustAddr")] HRESULT CustAddr([out, retval] BSTR* pVal);
	[propput, id(2), helpstring("속성 CustAddr")] HRESULT CustAddr([in] BSTR newVal);
	[propget, id(3), helpstring("속성 CustTelno")] HRESULT CustTelno([out, retval] BSTR* pVal);
	[propput, id(3), helpstring("속성 CustTelno")] HRESULT CustTelno([in] BSTR newVal);
};


// _ICustomerEvents입니다.
[
	uuid("B026A791-5A90-4CDB-9AD4-6B8DAE24374D"),
	dispinterface,
	helpstring("_ICustomerEvents 인터페이스")
]
__interface _ICustomerEvents
{
	[id(1), helpstring("메서드 OnChangedCustName")] void ChangedCustName([in] BSTR newName);
	[id(2), helpstring("메서드 OnChangedCustAddr")] void ChangedCustAddr([in] BSTR newAddr);
	[id(3), helpstring("메서드 OnChangedCustTelno")] void ChangedCustTelno([in] BSTR newTelno);
};

// CCustomer
[
	coclass,
	threading("apartment"),
	vi_progid("CustInfo.Customer"),
	progid("CustInfo.Customer.1"),
	version(1.0),
	uuid("0B16B70E-AA0B-4D14-B57C-1CED7F86A581"),
	helpstring("Customer Class"),
	event_source("com"),
	support_error_info(ICustomer),
	registration_script("control.rgs")
]
class ATL_NO_VTABLE CCustomer : 
	public ICustomer,
	public IPersistStreamInitImpl<CCustomer>,
	public IOleControlImpl<CCustomer>,
	public IOleObjectImpl<CCustomer>,
	public IOleInPlaceActiveObjectImpl<CCustomer>,
	public IViewObjectExImpl<CCustomer>,
	public IOleInPlaceObjectWindowlessImpl<CCustomer>,
	public IPersistStorageImpl<CCustomer>,
	public ISpecifyPropertyPagesImpl<CCustomer>,
	public IQuickActivateImpl<CCustomer>,
	public IDataObjectImpl<CCustomer>,
	public CComCompositeControl<CCustomer>
{
public:

	CCustomer()
	{
		m_bWindowOnly = TRUE;
		CalcExtent(m_sizeExtent);
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE | 
	OLEMISC_CANTLINKINSIDE | 
	OLEMISC_INSIDEOUT | 
	OLEMISC_ACTIVATEWHENVISIBLE | 
	OLEMISC_SETCLIENTSITEFIRST
)


BEGIN_PROP_MAP(CCustomer)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// 예제 항목
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()


BEGIN_MSG_MAP(CCustomer)
	COMMAND_HANDLER(IDC_CUSTNAME, EN_CHANGE, OnChangedCustName)
	COMMAND_HANDLER(IDC_CUSTADDR, EN_CHANGE, OnChangedCustAddr)
	COMMAND_HANDLER(IDC_CUSTTELNO, EN_CHANGE, OnChangedCustTelno)
	CHAIN_MSG_MAP(CComCompositeControl<CCustomer>)
END_MSG_MAP()
// 처리기 프로토타입:
// LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
// LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
// LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	__event __interface _ICustomerEvents;
// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// ICustomer

	enum { IDD = IDD_CUSTOMER };

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}
	LRESULT OnChangedCustName(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnChangedCustAddr(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnChangedCustTelno(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
protected:
	_bstr_t m_name;
	_bstr_t m_addr;
	_bstr_t m_telno;
public:
	STDMETHOD(get_CustName)(BSTR* pVal);
	STDMETHOD(put_CustName)(BSTR newVal);
	STDMETHOD(get_CustAddr)(BSTR* pVal);
	STDMETHOD(put_CustAddr)(BSTR newVal);
	STDMETHOD(get_CustTelno)(BSTR* pVal);
	STDMETHOD(put_CustTelno)(BSTR newVal);
};

