// Shapec.h : CShape의 선언입니다.
#pragma once
#include "resource.h"       // 주 기호입니다.
#include <atlctl.h>
#include <atlapp.h>
#include <atlgdi.h>
using namespace WTL;

// IShape
[
	object,
	uuid(B11EC349-D82F-494B-A51C-B1CDC2DF0EB4),
	dual,
	helpstring("IShape 인터페이스"),
	pointer_default(unique)
]
__interface IShape : public IDispatch
{
	[propput, bindable, requestedit, id(DISPID_FILLCOLOR)]
	HRESULT FillColor([in]OLE_COLOR clr);
	[propget, bindable, requestedit, id(DISPID_FILLCOLOR)]
	HRESULT FillColor([out, retval]OLE_COLOR* pclr);
	[propget, id(1), helpstring("속성 ShapeType")] HRESULT ShapeType([out, retval] short* pVal);
	[propput, id(1), helpstring("속성 ShapeType")] HRESULT ShapeType([in] short newVal);
	[id(2), helpstring("메서드 ChangeShape")] HRESULT ChangeShape(short shpType);
};


// _IShapeEvents입니다.
[
	uuid("B55B1009-F027-4C95-AE5D-961626ACEF9A"),
	dispinterface,
	helpstring("_IShapeEvents 인터페이스")
]
__interface _IShapeEvents
{
	[id(1), helpstring("메서드 ClickIn")] void ClickIn([in] long x, [in] long y);
	[id(2), helpstring("메서드 ClickOut")] void ClickOut([in] long x, [in] long y);
};

// CShape
[
	coclass,
	threading("apartment"),
	vi_progid("Shape.Shape"),
	progid("Shape.Shape.1"),
	version(1.0),
	uuid("2D1108CF-31BE-4CFC-8EEA-F6CD3EE363BC"),
	helpstring("Shape Class"),
	event_source("com"),
	support_error_info(IShape),
	registration_script("control.rgs")
]
class ATL_NO_VTABLE CShape : 
	public CStockPropImpl<CShape, IShape>,
	public IPersistStreamInitImpl<CShape>,
	public IOleControlImpl<CShape>,
	public IOleObjectImpl<CShape>,
	public IOleInPlaceActiveObjectImpl<CShape>,
	public IViewObjectExImpl<CShape>,
	public IOleInPlaceObjectWindowlessImpl<CShape>,
	public IPersistStorageImpl<CShape>,
	public ISpecifyPropertyPagesImpl<CShape>,
	public IQuickActivateImpl<CShape>,
	public IDataObjectImpl<CShape>,
	public CComControl<CShape>
{
public:

	CShape()
		: m_nShapeType(0)
	{
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE | 
	OLEMISC_CANTLINKINSIDE | 
	OLEMISC_INSIDEOUT | 
	OLEMISC_ACTIVATEWHENVISIBLE | 
	OLEMISC_SETCLIENTSITEFIRST
)


BEGIN_PROP_MAP(CShape)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY("FillColor", DISPID_FILLCOLOR, CLSID_StockColorPage)
	// 예제 항목
	// PROP_ENTRY("Property Description", dispid, clsid)
	PROP_ENTRY("ShapeType", 1, CLSID_NULL)
	PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()


BEGIN_MSG_MAP(CShape)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
	CHAIN_MSG_MAP(CComControl<CShape>)
    DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// 처리기 프로토타입:
// LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
// LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
// LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	__event __interface _IShapeEvents;
// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IShape
public:
	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		/*
		RECT& rc = *(RECT*)di.prcBounds;
		// 클립 영역을 di.prcBounds로 지정된 사각형으로 설정합니다.
		HRGN hRgnOld = NULL;
		if (GetClipRgn(di.hdcDraw, hRgnOld) != 1)
			hRgnOld = NULL;
		bool bSelectOldRgn = false;

		HRGN hRgnNew = CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);

		if (hRgnNew != NULL)
		{
			bSelectOldRgn = (SelectClipRgn(di.hdcDraw, hRgnNew) != ERROR);
		}

		Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);
		SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
		LPCTSTR pszText = _T("ATL 7.0 : Shape");
		TextOut(di.hdcDraw, 
			(rc.left + rc.right) / 2, 
			(rc.top + rc.bottom) / 2, 
			pszText, 
			lstrlen(pszText));

		if (bSelectOldRgn)
			SelectClipRgn(di.hdcDraw, hRgnOld);
		*/

		rc = *(RECT*)di.prcBounds;

		CDC dc(di.hdcDraw);
		OLE_COLOR oleBackColor;
		COLORREF colBack, colFore;
		CBrush oldBrush, brush;
		CPen oldPen;
		CPoint pt[3];

		GetAmbientBackColor(oleBackColor);
		OleTranslateColor(oleBackColor, NULL, &colBack);
		brush.CreateSolidBrush(colBack);
		oldBrush = dc.SelectBrush(brush);
		dc.FillRect(&rc, brush);
		dc.SelectBrush(oldBrush);
		brush.DeleteObject();
		
		OleTranslateColor(m_clrFillColor, NULL, &colFore);
		oldPen = dc.SelectStockPen(BLACK_PEN);
		brush.CreateSolidBrush(colFore);
		oldBrush = dc.SelectBrush(brush);

		switch(m_nShapeType) {
		case 0 : // Rectangle
			dc.Rectangle(rc);
			break;
		case 1 : // Ellipse
			dc.Ellipse(rc);
			break;
		case 2 : // Triangle
			pt[0].x = (rc.left + rc.right) / 2;
			pt[0].y = rc.top;
			pt[1].x = rc.left;
			pt[1].y = rc.bottom;
			pt[2].x = rc.right;
			pt[2].y = rc.bottom;
			dc.Polygon(&pt[0], 3);
			break;
		default:
			dc.Rectangle(rc);
			dc.DrawText(_T("에러!"), -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;
		}
		
		dc.SelectPen(oldPen);
		dc.SelectBrush(oldBrush);
		return S_OK;
	}

	OLE_COLOR m_clrFillColor;
	void OnFillColorChanged()
	{
		ATLTRACE(_T("OnFillColorChanged\n"));
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}
	STDMETHOD(get_ShapeType)(short* pVal);
	STDMETHOD(put_ShapeType)(short newVal);
	STDMETHOD(ChangeShape)(short shpType);

	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
		CPoint pt;
		CPoint pt3[3];
		CRgn rgn;
		BOOL bIn = FALSE;

		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);

		switch(m_nShapeType) {
		case 0 :	// Rectangle
			bIn = PtInRect(&rc, pt);
			break;
		case 1 :	// Ellipse
			bIn = InCircle(pt);
			break;
		case 2:		// Triangle
			pt3[0].x = (rc.left + rc.right) / 2;
			pt3[0].y = rc.top;
			pt3[1].x = rc.left;
			pt3[1].y = rc.bottom;
			pt3[2].x = rc.right;
			pt3[2].y = rc.bottom;
			rgn.CreatePolygonRgn(&pt3[0], 3, WINDING);
			bIn = rgn.PtInRegion(pt);
			break;
		}
		if(bIn)
			__raise ClickIn(pt.x, pt.y);
		else
			__raise ClickOut(pt.x, pt.y);
		
		return 0;
	}

	BOOL InCircle(POINT pt) {
		double a = (rc.right - rc.left) / 2;
		double b = (rc.bottom - rc.top) / 2;

		double x = pt.x - (rc.left + rc.right) / 2;
		double y = pt.y - (rc.top + rc.bottom) / 2;

		return ((x * x) / (a * a) + (y * y) / (b * b) <= 1);
	}
protected:
	short m_nShapeType;
	CRect rc;
};

