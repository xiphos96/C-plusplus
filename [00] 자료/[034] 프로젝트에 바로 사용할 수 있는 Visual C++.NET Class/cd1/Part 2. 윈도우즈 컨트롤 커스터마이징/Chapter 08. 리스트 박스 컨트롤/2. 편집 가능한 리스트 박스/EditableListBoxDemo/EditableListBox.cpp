// EditableListBox.cpp : implementation file
//

#include "stdafx.h"
#include "editablelistboxdemo.h"
#include "EditableListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditableListBox

// 에디트 박스용 리소스 ID
#define IDC_LIST_EDIT				1
// 항목간 간격
#define CONST_ITEM_GAP				2

CEditableListBox::CEditableListBox()
{
	// 멤버 변수를 초기화한다
	m_nTrackItem	= -1;
	m_nEditItem		= -1;

	m_clrText		= RGB(0, 0, 0);
	m_clrHighlight	= RGB(230, 233, 240);
	m_clrBkgnd		= RGB(255, 255, 255);
	m_clrSelected	= RGB(193, 200, 217);

	m_NullBrush.CreateStockObject(NULL_BRUSH);
	m_ShadowPen.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_3DSHADOW));
	m_FocusPen.CreatePen(PS_SOLID, 1, RGB(132, 145, 180));
}

CEditableListBox::~CEditableListBox()
{
	// GDI 객체들을 삭제한다
	m_ShadowPen.DeleteObject();
	m_FocusPen.DeleteObject();
}


BEGIN_MESSAGE_MAP(CEditableListBox, CListBox)
	//{{AFX_MSG_MAP(CEditableListBox)
	ON_WM_MOUSEMOVE()
	ON_WM_NCPAINT()
	ON_CONTROL_REFLECT(LBN_DBLCLK, OnDblclk)
	ON_WM_KEYUP()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_EN_KILLFOCUS(IDC_LIST_EDIT, OnKillFocusEdit)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditableListBox message handlers

void CEditableListBox::PreSubclassWindow() 
{
	// 클라이언트 영역의 테두리 속성을 없앤다
    ModifyStyleEx(WS_EX_CLIENTEDGE, 0);
	// 사용자 정의 그리기 속성을 설정하고, 프레임을 다시 그린다
	ModifyStyle(LBS_SORT, LBS_OWNERDRAWVARIABLE | LBS_HASSTRINGS | LBS_NOINTEGRALHEIGHT | LBS_EXTENDEDSEL | WS_BORDER, SWP_FRAMECHANGED);
	
	CListBox::PreSubclassWindow();
}

void CEditableListBox::OnMouseMove(UINT nFlags, CPoint point) 
{
	CListBox::OnMouseMove(nFlags, point);
	
	// 시스템에게 마우스의 탈출에 대한 메시지를 보내줄 것을 요청
	TRACKMOUSEEVENT MouseEvent;
	MouseEvent.cbSize		= sizeof(TRACKMOUSEEVENT);
	MouseEvent.dwFlags		= TME_LEAVE;
	MouseEvent.hwndTrack	= m_hWnd;
	MouseEvent.dwHoverTime	= 1;

	::TrackMouseEvent(&MouseEvent);

	// 만약 에디트 박스가 출력된 상태라면 리턴한다
	if(::IsWindow(m_Edit.m_hWnd))		return;

	BOOL bOut;
	// 현재 마우스 커서 위치의 항목 번호를 얻는다
	int nItem = ItemFromPoint(point, bOut);

	// 바로전 마우스가 위치했던 항목과 동일하면 리턴한다
	if(nItem == m_nTrackItem)	return;

	CRect rcItem;

	// 만약 이전에 위치했던 항목이 있다면
	if(m_nTrackItem >= 0)
	{
		// 해당 항목의 사각 영역을 구한다
		GetItemRect(m_nTrackItem, &rcItem);
		// 항목 번호를 -1로 초기화한다
		m_nTrackItem = -1;
		// 해당 항목을 다시 그린다
		InvalidateRect(&rcItem, FALSE);
	}

	// 만약 마우스가 리스트 박스 밖으로 이동했다면 리턴한다
	if(bOut)		return;

	// 새로운 항목 번호를 저장한다
	m_nTrackItem = nItem;
	// 해당 항목의 사각 영역을 구한다
	GetItemRect(m_nTrackItem, &rcItem);
	// 해당 항목을 다시 그린다
	InvalidateRect(&rcItem, FALSE);
}

LRESULT CEditableListBox::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	// 만약 바로전 마우스가 위치했던 항목이 있다면
	if(m_nTrackItem >= 0)
	{
		CRect rcItem;

		// 해당 항목의 사각 영역을 구한다
		GetItemRect(m_nTrackItem, &rcItem);
		// 항목 번호를 -1로 초기화한다
		m_nTrackItem = -1;
		// 해당 항목을 다시 그린다
		InvalidateRect(&rcItem, FALSE);
	}

	return 0;
}

// 각 항목의 크기를 구한다
void CEditableListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	// 항목의 텍스트를 구한다
	CString strItem;
	GetText(lpMeasureItemStruct->itemID, strItem);

	// DC를 얻고 리스트 박스의 폰트를 설정한다
	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());

	// 기본 항목 크기를 설정한다
	CRect rcItem(0, 0, lpMeasureItemStruct->itemWidth, lpMeasureItemStruct->itemHeight);
	if(rcItem.right == 0)
	{
		CRect rcClient;
		GetClientRect(&rcClient);
		rcItem.right = rcClient.Width();
	}

	// 텍스트 출력을 위해 필요한 영역을 구한다
	pDC->DrawText(strItem, &rcItem, DT_WORDBREAK | DT_EXPANDTABS | DT_CALCRECT);

	// 폰트를 반환하고 DC를 반환한다
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// 텍스트 출력에 필요한 영역에 여백을 더한다
	lpMeasureItemStruct->itemWidth = rcItem.Width() + CONST_ITEM_GAP * 2;
	lpMeasureItemStruct->itemHeight = rcItem.Height() + CONST_ITEM_GAP * 2;
}

void CEditableListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// 만약 출력하는 항목의 번호가 유효하지 않다면 리턴한다
	if((int)lpDrawItemStruct->itemID < 0)											return;
	// 만약 현재 편집 중인 항목이라면 리턴한다
	if((int)lpDrawItemStruct->itemID == m_nEditItem && ::IsWindow(m_Edit.m_hWnd))	return;

	// 항목의 영역을 구한다
	CRect rcItem = lpDrawItemStruct->rcItem;
	// 좌상단을 (0, 0)으로 이동시킨다
	rcItem.OffsetRect(-lpDrawItemStruct->rcItem.left, -lpDrawItemStruct->rcItem.top);

	// 더블 버퍼링을 구현한다
	CDC dc, MemDC;
	dc.Attach(lpDrawItemStruct->hDC);
	MemDC.CreateCompatibleDC(&dc);

	CBitmap MemBmp, *pOldBmp;
	MemBmp.CreateCompatibleBitmap(&dc, rcItem.Width(), rcItem.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// 리스트 박스의 폰트를 설정한다
	CFont *pOldFont = MemDC.SelectObject(GetFont());

	COLORREF clrBkgnd;
	// 현재 선택된 항목이면 선택 색상을 배경색으로 사용한다
	if(lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		clrBkgnd = m_clrSelected;
	}
	else
	{
		// 현재 마우스가 위치한 항목인지 여부에 따라 배경색을 다르게 사용한다
		if((int)lpDrawItemStruct->itemID == m_nTrackItem)	clrBkgnd = m_clrHighlight;
		else												clrBkgnd = m_clrBkgnd;
	}
	// 배경을 칠한다
	MemDC.FillSolidRect(&rcItem, clrBkgnd);

	// 만약 현재 포커스를 갖고 있는 항목이라면
	if(lpDrawItemStruct->itemState & ODS_FOCUS)
	{
		// 포커스 펜을 사용하여 테두리를 그린다
		CBrush *pOldBrush = MemDC.SelectObject(&m_NullBrush);
		CPen *pOldPen = MemDC.SelectObject(&m_FocusPen);

		MemDC.Rectangle(&rcItem);

		MemDC.SelectObject(pOldBrush);
		MemDC.SelectObject(pOldPen);
	}

	// 항목의 텍스트를 구한다
	CString strItem;
	GetText(lpDrawItemStruct->itemID, strItem);

	// 배경을 투명으로 설정하고, 텍스트 색상을 설정한다
	MemDC.SetBkMode(TRANSPARENT);
	MemDC.SetTextColor(m_clrText);

	// 텍스트를 출력한다
	MemDC.DrawText(strItem, &rcItem, DT_LEFT | DT_WORDBREAK | DT_EXPANDTABS);

	// 메모리 DC의 내용을 화면에 출력한다
	dc.BitBlt(lpDrawItemStruct->rcItem.left, lpDrawItemStruct->rcItem.top,
		rcItem.Width(), rcItem.Height(), &MemDC, 0, 0, SRCCOPY);

	// GDI 객체들을 반환한다
	MemDC.SelectObject(pOldFont);
	MemDC.SelectObject(&pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
	dc.Detach();
}

void CEditableListBox::OnNcPaint() 
{
	Default();

	// 리스트 박스의 테두리를 출력한다
    CWindowDC dc(this);

	CRect rcWindow;
	GetWindowRect(&rcWindow);

	CPen *pOldPen = dc.SelectObject(&m_ShadowPen);
	CBrush *pOldBrush = dc.SelectObject(&m_NullBrush);

	dc.Rectangle(0, 0, rcWindow.Width(), rcWindow.Height());

	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
}

void CEditableListBox::OnDblclk() 
{
	// 현재 커서 위치를 구한다
	BOOL bOut;
	CPoint ptCursor;
	::GetCursorPos(&ptCursor);
	ScreenToClient(&ptCursor);

	// 현재 커서 위치의 항목 번호를 구한다
	int nItem = (int)ItemFromPoint(ptCursor, bOut);
	// 만약 현재 항목 편집 중이 아니라면
	if(nItem >= 0 && !bOut && !::IsWindow(m_Edit.m_hWnd))
	{
		// 항목의 텍스트를 구한다
		CString strItem;
		GetText(nItem, strItem);

		// 항목의 영역을 구한다
		CRect rcItem;
		GetItemRect(nItem, &rcItem);

		// 편집 중인 항목 번호를 저장한다
		m_nEditItem = nItem;

		// 편집용 에디트 컨트롤을 생성한다
		m_Edit.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL | ES_LEFT | ES_MULTILINE | ES_WANTRETURN,
			rcItem, this, IDC_LIST_EDIT);
		// 리스트 박스의 폰트를 설정한다
		m_Edit.SetFont(GetFont());
		// 해당 항목의 텍스트를 설정한다
		m_Edit.SetWindowText(strItem);
		// 에디트 박스에 포커스를 준다
		m_Edit.SetFocus();
	}
}

void CEditableListBox::OnKillFocusEdit() 
{
	// 만약 에디트 박스가 포커스를 잃으면 편집을 종료한다
	EndEdit();
}

// 텍스트 편집을 종료하는 함수
void CEditableListBox::EndEdit()
{
	// 만약 에디트 박스가 윈도우가 아니라면 리턴한다
	if(!::IsWindow(m_Edit.m_hWnd))			return;

	// 에디트 박스에 입력된 텍스트를 구한다
	CString strNew;
	m_Edit.GetWindowText(strNew);

	// 편집 중인 항목 번호가 옳바르다면
	if(m_nEditItem >= 0)
	{
		// 해당 항목을 삭제하고
		DeleteString(m_nEditItem);
		// 그 위치에 새로운 텍스트로 항목을 삽입한다
		InsertString(m_nEditItem, strNew);

		// 편집 항목 번호를 초기화한다
		m_nEditItem = -1;
	}

	// 에디트 박스를 소멸시킨다
	m_Edit.DestroyWindow();
}

void CEditableListBox::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// 만약 DEL 키를 눌렀다면
	switch(nChar)
	{
	case VK_DELETE:
		// 현재 선택된 항목이 있다면
		if(GetSelCount() > 0)
		{
			int nFirst = -1;
			// 모든 항목들에 대해 선택된 상태인지 점검한다
			for(int i = 0; i < GetCount(); i++)
			{
				// 만약 선택된 항목이라면
				if(GetSel(i))
				{
					// 첫 항목이라면 그 번호를 저장한다
					if(nFirst < 0)			nFirst = i;
					// 해당 항목을 삭제한다
					DeleteString(i--);
				}
			}

			// 만약 삭제 후에도 항목이 남아 있다면
			if(GetCount() > 0)
			{
				// 처음 삭제된 바로 앞 위치의 항목을 선택한다
				nFirst--;
				if(nFirst < 0)	nFirst = 0;
				SetSel(nFirst);
			}
		}
		break;
	}
	
	CListBox::OnKeyUp(nChar, nRepCnt, nFlags);
}
