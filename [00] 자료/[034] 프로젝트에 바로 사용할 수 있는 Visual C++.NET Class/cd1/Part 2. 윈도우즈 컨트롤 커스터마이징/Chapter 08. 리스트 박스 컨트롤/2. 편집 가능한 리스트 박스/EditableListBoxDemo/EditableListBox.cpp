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

// ����Ʈ �ڽ��� ���ҽ� ID
#define IDC_LIST_EDIT				1
// �׸� ����
#define CONST_ITEM_GAP				2

CEditableListBox::CEditableListBox()
{
	// ��� ������ �ʱ�ȭ�Ѵ�
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
	// GDI ��ü���� �����Ѵ�
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
	// Ŭ���̾�Ʈ ������ �׵θ� �Ӽ��� ���ش�
    ModifyStyleEx(WS_EX_CLIENTEDGE, 0);
	// ����� ���� �׸��� �Ӽ��� �����ϰ�, �������� �ٽ� �׸���
	ModifyStyle(LBS_SORT, LBS_OWNERDRAWVARIABLE | LBS_HASSTRINGS | LBS_NOINTEGRALHEIGHT | LBS_EXTENDEDSEL | WS_BORDER, SWP_FRAMECHANGED);
	
	CListBox::PreSubclassWindow();
}

void CEditableListBox::OnMouseMove(UINT nFlags, CPoint point) 
{
	CListBox::OnMouseMove(nFlags, point);
	
	// �ý��ۿ��� ���콺�� Ż�⿡ ���� �޽����� ������ ���� ��û
	TRACKMOUSEEVENT MouseEvent;
	MouseEvent.cbSize		= sizeof(TRACKMOUSEEVENT);
	MouseEvent.dwFlags		= TME_LEAVE;
	MouseEvent.hwndTrack	= m_hWnd;
	MouseEvent.dwHoverTime	= 1;

	::TrackMouseEvent(&MouseEvent);

	// ���� ����Ʈ �ڽ��� ��µ� ���¶�� �����Ѵ�
	if(::IsWindow(m_Edit.m_hWnd))		return;

	BOOL bOut;
	// ���� ���콺 Ŀ�� ��ġ�� �׸� ��ȣ�� ��´�
	int nItem = ItemFromPoint(point, bOut);

	// �ٷ��� ���콺�� ��ġ�ߴ� �׸�� �����ϸ� �����Ѵ�
	if(nItem == m_nTrackItem)	return;

	CRect rcItem;

	// ���� ������ ��ġ�ߴ� �׸��� �ִٸ�
	if(m_nTrackItem >= 0)
	{
		// �ش� �׸��� �簢 ������ ���Ѵ�
		GetItemRect(m_nTrackItem, &rcItem);
		// �׸� ��ȣ�� -1�� �ʱ�ȭ�Ѵ�
		m_nTrackItem = -1;
		// �ش� �׸��� �ٽ� �׸���
		InvalidateRect(&rcItem, FALSE);
	}

	// ���� ���콺�� ����Ʈ �ڽ� ������ �̵��ߴٸ� �����Ѵ�
	if(bOut)		return;

	// ���ο� �׸� ��ȣ�� �����Ѵ�
	m_nTrackItem = nItem;
	// �ش� �׸��� �簢 ������ ���Ѵ�
	GetItemRect(m_nTrackItem, &rcItem);
	// �ش� �׸��� �ٽ� �׸���
	InvalidateRect(&rcItem, FALSE);
}

LRESULT CEditableListBox::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	// ���� �ٷ��� ���콺�� ��ġ�ߴ� �׸��� �ִٸ�
	if(m_nTrackItem >= 0)
	{
		CRect rcItem;

		// �ش� �׸��� �簢 ������ ���Ѵ�
		GetItemRect(m_nTrackItem, &rcItem);
		// �׸� ��ȣ�� -1�� �ʱ�ȭ�Ѵ�
		m_nTrackItem = -1;
		// �ش� �׸��� �ٽ� �׸���
		InvalidateRect(&rcItem, FALSE);
	}

	return 0;
}

// �� �׸��� ũ�⸦ ���Ѵ�
void CEditableListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	// �׸��� �ؽ�Ʈ�� ���Ѵ�
	CString strItem;
	GetText(lpMeasureItemStruct->itemID, strItem);

	// DC�� ��� ����Ʈ �ڽ��� ��Ʈ�� �����Ѵ�
	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());

	// �⺻ �׸� ũ�⸦ �����Ѵ�
	CRect rcItem(0, 0, lpMeasureItemStruct->itemWidth, lpMeasureItemStruct->itemHeight);
	if(rcItem.right == 0)
	{
		CRect rcClient;
		GetClientRect(&rcClient);
		rcItem.right = rcClient.Width();
	}

	// �ؽ�Ʈ ����� ���� �ʿ��� ������ ���Ѵ�
	pDC->DrawText(strItem, &rcItem, DT_WORDBREAK | DT_EXPANDTABS | DT_CALCRECT);

	// ��Ʈ�� ��ȯ�ϰ� DC�� ��ȯ�Ѵ�
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// �ؽ�Ʈ ��¿� �ʿ��� ������ ������ ���Ѵ�
	lpMeasureItemStruct->itemWidth = rcItem.Width() + CONST_ITEM_GAP * 2;
	lpMeasureItemStruct->itemHeight = rcItem.Height() + CONST_ITEM_GAP * 2;
}

void CEditableListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// ���� ����ϴ� �׸��� ��ȣ�� ��ȿ���� �ʴٸ� �����Ѵ�
	if((int)lpDrawItemStruct->itemID < 0)											return;
	// ���� ���� ���� ���� �׸��̶�� �����Ѵ�
	if((int)lpDrawItemStruct->itemID == m_nEditItem && ::IsWindow(m_Edit.m_hWnd))	return;

	// �׸��� ������ ���Ѵ�
	CRect rcItem = lpDrawItemStruct->rcItem;
	// �»���� (0, 0)���� �̵���Ų��
	rcItem.OffsetRect(-lpDrawItemStruct->rcItem.left, -lpDrawItemStruct->rcItem.top);

	// ���� ���۸��� �����Ѵ�
	CDC dc, MemDC;
	dc.Attach(lpDrawItemStruct->hDC);
	MemDC.CreateCompatibleDC(&dc);

	CBitmap MemBmp, *pOldBmp;
	MemBmp.CreateCompatibleBitmap(&dc, rcItem.Width(), rcItem.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// ����Ʈ �ڽ��� ��Ʈ�� �����Ѵ�
	CFont *pOldFont = MemDC.SelectObject(GetFont());

	COLORREF clrBkgnd;
	// ���� ���õ� �׸��̸� ���� ������ �������� ����Ѵ�
	if(lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		clrBkgnd = m_clrSelected;
	}
	else
	{
		// ���� ���콺�� ��ġ�� �׸����� ���ο� ���� ������ �ٸ��� ����Ѵ�
		if((int)lpDrawItemStruct->itemID == m_nTrackItem)	clrBkgnd = m_clrHighlight;
		else												clrBkgnd = m_clrBkgnd;
	}
	// ����� ĥ�Ѵ�
	MemDC.FillSolidRect(&rcItem, clrBkgnd);

	// ���� ���� ��Ŀ���� ���� �ִ� �׸��̶��
	if(lpDrawItemStruct->itemState & ODS_FOCUS)
	{
		// ��Ŀ�� ���� ����Ͽ� �׵θ��� �׸���
		CBrush *pOldBrush = MemDC.SelectObject(&m_NullBrush);
		CPen *pOldPen = MemDC.SelectObject(&m_FocusPen);

		MemDC.Rectangle(&rcItem);

		MemDC.SelectObject(pOldBrush);
		MemDC.SelectObject(pOldPen);
	}

	// �׸��� �ؽ�Ʈ�� ���Ѵ�
	CString strItem;
	GetText(lpDrawItemStruct->itemID, strItem);

	// ����� �������� �����ϰ�, �ؽ�Ʈ ������ �����Ѵ�
	MemDC.SetBkMode(TRANSPARENT);
	MemDC.SetTextColor(m_clrText);

	// �ؽ�Ʈ�� ����Ѵ�
	MemDC.DrawText(strItem, &rcItem, DT_LEFT | DT_WORDBREAK | DT_EXPANDTABS);

	// �޸� DC�� ������ ȭ�鿡 ����Ѵ�
	dc.BitBlt(lpDrawItemStruct->rcItem.left, lpDrawItemStruct->rcItem.top,
		rcItem.Width(), rcItem.Height(), &MemDC, 0, 0, SRCCOPY);

	// GDI ��ü���� ��ȯ�Ѵ�
	MemDC.SelectObject(pOldFont);
	MemDC.SelectObject(&pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
	dc.Detach();
}

void CEditableListBox::OnNcPaint() 
{
	Default();

	// ����Ʈ �ڽ��� �׵θ��� ����Ѵ�
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
	// ���� Ŀ�� ��ġ�� ���Ѵ�
	BOOL bOut;
	CPoint ptCursor;
	::GetCursorPos(&ptCursor);
	ScreenToClient(&ptCursor);

	// ���� Ŀ�� ��ġ�� �׸� ��ȣ�� ���Ѵ�
	int nItem = (int)ItemFromPoint(ptCursor, bOut);
	// ���� ���� �׸� ���� ���� �ƴ϶��
	if(nItem >= 0 && !bOut && !::IsWindow(m_Edit.m_hWnd))
	{
		// �׸��� �ؽ�Ʈ�� ���Ѵ�
		CString strItem;
		GetText(nItem, strItem);

		// �׸��� ������ ���Ѵ�
		CRect rcItem;
		GetItemRect(nItem, &rcItem);

		// ���� ���� �׸� ��ȣ�� �����Ѵ�
		m_nEditItem = nItem;

		// ������ ����Ʈ ��Ʈ���� �����Ѵ�
		m_Edit.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL | ES_LEFT | ES_MULTILINE | ES_WANTRETURN,
			rcItem, this, IDC_LIST_EDIT);
		// ����Ʈ �ڽ��� ��Ʈ�� �����Ѵ�
		m_Edit.SetFont(GetFont());
		// �ش� �׸��� �ؽ�Ʈ�� �����Ѵ�
		m_Edit.SetWindowText(strItem);
		// ����Ʈ �ڽ��� ��Ŀ���� �ش�
		m_Edit.SetFocus();
	}
}

void CEditableListBox::OnKillFocusEdit() 
{
	// ���� ����Ʈ �ڽ��� ��Ŀ���� ������ ������ �����Ѵ�
	EndEdit();
}

// �ؽ�Ʈ ������ �����ϴ� �Լ�
void CEditableListBox::EndEdit()
{
	// ���� ����Ʈ �ڽ��� �����찡 �ƴ϶�� �����Ѵ�
	if(!::IsWindow(m_Edit.m_hWnd))			return;

	// ����Ʈ �ڽ��� �Էµ� �ؽ�Ʈ�� ���Ѵ�
	CString strNew;
	m_Edit.GetWindowText(strNew);

	// ���� ���� �׸� ��ȣ�� �ǹٸ��ٸ�
	if(m_nEditItem >= 0)
	{
		// �ش� �׸��� �����ϰ�
		DeleteString(m_nEditItem);
		// �� ��ġ�� ���ο� �ؽ�Ʈ�� �׸��� �����Ѵ�
		InsertString(m_nEditItem, strNew);

		// ���� �׸� ��ȣ�� �ʱ�ȭ�Ѵ�
		m_nEditItem = -1;
	}

	// ����Ʈ �ڽ��� �Ҹ��Ų��
	m_Edit.DestroyWindow();
}

void CEditableListBox::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// ���� DEL Ű�� �����ٸ�
	switch(nChar)
	{
	case VK_DELETE:
		// ���� ���õ� �׸��� �ִٸ�
		if(GetSelCount() > 0)
		{
			int nFirst = -1;
			// ��� �׸�鿡 ���� ���õ� �������� �����Ѵ�
			for(int i = 0; i < GetCount(); i++)
			{
				// ���� ���õ� �׸��̶��
				if(GetSel(i))
				{
					// ù �׸��̶�� �� ��ȣ�� �����Ѵ�
					if(nFirst < 0)			nFirst = i;
					// �ش� �׸��� �����Ѵ�
					DeleteString(i--);
				}
			}

			// ���� ���� �Ŀ��� �׸��� ���� �ִٸ�
			if(GetCount() > 0)
			{
				// ó�� ������ �ٷ� �� ��ġ�� �׸��� �����Ѵ�
				nFirst--;
				if(nFirst < 0)	nFirst = 0;
				SetSel(nFirst);
			}
		}
		break;
	}
	
	CListBox::OnKeyUp(nChar, nRepCnt, nFlags);
}
