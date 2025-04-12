// UpDownCtl.h : CUpDownCtl의 선언입니다.
#pragma once
#include "resource.h"       // 주 기호입니다.
#include <atlctl.h>

// IUpDownCtl
[
	object,
	uuid(E110287D-B638-4CB4-9AD1-E502664EEBBA),
	dual,
	helpstring("IUpDownCtl 인터페이스"),
	pointer_default(unique)
]
__interface IUpDownCtl : public IDispatch
{
	[propget, id(1), helpstring("속성 MinValue")] HRESULT MinValue([out, retval] short* pVal);
	[propput, id(1), helpstring("속성 MinValue")] HRESULT MinValue([in] short newVal);
	[propget, id(2), helpstring("속성 MaxValue")] HRESULT MaxValue([out, retval] short* pVal);
	[propput, id(2), helpstring("속성 MaxValue")] HRESULT MaxValue([in] short newVal);
	[propget, id(3), helpstring("속성 Value")] HRESULT Value([out, retval] short* pVal);
	[propput, id(3), helpstring("속성 Value")] HRESULT Value([in] short newVal);
};


// _IUpDownCtlEvents입니다.
[
	uuid("98E0E6DC-6884-4D03-A873-10FC84488C8B"),
	dispinterface,
	helpstring("_IUpDownCtlEvents 인터페이스")
]
__interface _IUpDownCtlEvents
{
	[id(1), helpstring("메서드 Changed")] void Changed([in] short newValue);
};

// CUpDownCtl
[
	coclass,
	threading("apartment"),
	vi_progid("UpDown.UpDownCtl"),
	progid("UpDown.UpDownCtl.1"),
	version(1.0),
	uuid("7B8BA776-730A-47D6-9462-EB68C2F8CC2D"),
	helpstring("UpDownCtl Class"),
	event_source("com"),
	support_error_info(IUpDownCtl),
	registration_script("control.rgs")
]
class ATL_NO_VTABLE CUpDownCtl : 
	public IUpDownCtl,
	public IPersistStreamInitImpl<CUpDownCtl>,
	public IOleControlImpl<CUpDownCtl>,
	public IOleObjectImpl<CUpDownCtl>,
	public IOleInPlaceActiveObjectImpl<CUpDownCtl>,
	public IViewObjectExImpl<CUpDownCtl>,
	public IOleInPlaceObjectWindowlessImpl<CUpDownCtl>,
	public IPersistStorageImpl<CUpDownCtl>,
	public ISpecifyPropertyPagesImpl<CUpDownCtl>,
	public IQuickActivateImpl<CUpDownCtl>,
	public IDataObjectImpl<CUpDownCtl>,
	public CComCompositeControl<CUpDownCtl>
{
public:

	CUpDownCtl()
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


BEGIN_PROP_MAP(CUpDownCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// 예제 항목
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
	PROP_ENTRY("MinValue", 1, CLSID_NULL)
	PROP_ENTRY("MaxValue", 1, CLSID_NULL)
	PROP_ENTRY("Value", 1, CLSID_NULL)
END_PROP_MAP()


BEGIN_MSG_MAP(CUpDownCtl)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_HANDLER(IDC_TEXT, EN_CHANGE, OnChangeValue)
	CHAIN_MSG_MAP(CComCompositeControl<CUpDownCtl>)
END_MSG_MAP()
// 처리기 프로토타입:
// LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
// LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
// LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
		SetRange(m_minvalue, m_maxvalue);
		SetDlgItemInt(IDC_TEXT, m_value);
		return 0;
	}
	__event __interface _IUpDownCtlEvents;
// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IUpDownCtl

	enum { IDD = IDD_UPDOWNCTL };

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		m_minvalue = 0;
		m_maxvalue = 100;
		m_value = 0;
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}
	STDMETHOD(get_MinValue)(short* pVal);
	STDMETHOD(put_MinValue)(short newVal);
	STDMETHOD(get_MaxValue)(short* pVal);
	STDMETHOD(put_MaxValue)(short newVal);
	STDMETHOD(get_Value)(short* pVal);
	STDMETHOD(put_Value)(short newVal);
protected:
	short m_minvalue;
	short m_maxvalue;
	short m_value;

	void SetRange(short min, short max) {
		HWND hwnd = GetDlgItem(IDC_SPIN);
		if(!::IsWindow(hwnd))
			return;
		::SendMessage(hwnd, UDM_SETRANGE, 0, MAKELPARAM(max, min));
	}
public:
	LRESULT OnChangeValue(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};

