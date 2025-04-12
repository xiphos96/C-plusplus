// CustomTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "customtabctrldemo.h"
#include "CustomTabCtrl.h"
#include ".\customtabctrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControlContainer

// ������
CControlContainer::CControlContainer()
{
	// ��� ������ �ʱ�ȭ�Ѵ�
	m_bShow = FALSE;
}

// �Ҹ���
CControlContainer::~CControlContainer()
{
	// ��Ʈ�� �迭�� �ʱ�ȭ�Ѵ�
	m_Controls.RemoveAll();
}

// �����̳ʿ� ��Ʈ���� �߰��ϴ� �Լ�
int CControlContainer::AddControl(CWnd *pCtrl)
{
	// ��Ʈ�� �迭�� �����͸� �߰��Ѵ�
	return (int)m_Controls.Add(pCtrl);
}

// �����̳��� ��Ʈ�ѵ��� ���̰ų� ���ߴ� �Լ�
void CControlContainer::ShowControls(BOOL bShow)
{
	// ���� ���� ���¿� �����ϴٸ� ����
	if(m_bShow == bShow)		return;

	// ���ο� ���¸� �����Ѵ�
	m_bShow = bShow;

	// ��Ʈ�� �迭�� ��� ��Ʈ���� ���̰ų� �����
	int i, nSize = (int)m_Controls.GetSize();
	CWnd *pWnd;

	for(i = 0; i < nSize; i++)
	{
		pWnd = m_Controls.GetAt(i);
		pWnd->SetWindowPos(&CWnd::wndTop, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE |
			(bShow ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
	}
}


/////////////////////////////////////////////////////////////////////////////
// CCustomTabCtrl

// �̹����� �ؽ�Ʈ, �׸��� �� ��ư ������ ����
#define CONST_ITEM_GAP			4

CCustomTabCtrl::CCustomTabCtrl()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
	::memset(&m_infoTabBkgndLeft, 0, sizeof(BITMAP));
	::memset(&m_infoTabBkgndCenter, 0, sizeof(BITMAP));
	::memset(&m_infoTabBkgndRight, 0, sizeof(BITMAP));

	m_clrButtonText		= RGB(60, 77, 120);
	m_clrButtonFace		= RGB(242, 245, 251);
	m_clrButtonLight	= RGB(174, 186, 223);
	m_clrButtonShadow	= RGB(79, 107, 160);

	m_clrBorder			= RGB(68, 96, 151);
	m_clrBkgnd			= RGB(255, 255, 255);

	m_penButtonLight.CreatePen(PS_SOLID, 1, m_clrButtonLight);
	m_penButtonShadow.CreatePen(PS_SOLID, 1, m_clrButtonShadow);
	m_penBorder.CreatePen(PS_SOLID, 1, m_clrBorder);

	m_nHoverItem		= -1;
}

CCustomTabCtrl::~CCustomTabCtrl()
{
	// GDI ���ҽ����� ��ȯ�Ѵ�
	if(m_bmpTabBkgndLeft.m_hObject)		m_bmpTabBkgndLeft.DeleteObject();
	if(m_bmpTabBkgndCenter.m_hObject)	m_bmpTabBkgndCenter.DeleteObject();
	if(m_bmpTabBkgndRight.m_hObject)	m_bmpTabBkgndRight.DeleteObject();

	m_penButtonLight.DeleteObject();
	m_penButtonShadow.DeleteObject();
	m_penBorder.DeleteObject();

	// �����̳� �迭�� ������ �����Ѵ�
	int i, nSize = (int)m_Containers.GetSize();

	for(i = 0; i < nSize; i++)
	{
		delete m_Containers.GetAt(i);
	}
	m_Containers.RemoveAll();
}


BEGIN_MESSAGE_MAP(CCustomTabCtrl, CTabCtrl)
	//{{AFX_MSG_MAP(CCustomTabCtrl)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_NOTIFY_REFLECT(TCN_SELCHANGING, OnSelchanging)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnSelchange)
	ON_WM_ERASEBKGND()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomTabCtrl message handlers

void CCustomTabCtrl::PreSubclassWindow() 
{
	// �� ��Ʈ���� �Ӽ��� �����Ѵ�
	ModifyStyle(TCS_RIGHTJUSTIFY | TCS_RAGGEDRIGHT, TCS_OWNERDRAWFIXED, SWP_FRAMECHANGED);
	
	// ���� Ŭ���̾�Ʈ ������ ���Ѵ�
	GetClientRect(&m_rcClient);

	// �⺻ ��ư ũ��� ������ ����Ѵ�
	RecalcTabSize();

	CTabCtrl::PreSubclassWindow();
}

// Ư�� ���� �ؽ�Ʈ�� �̹��� ��ȣ�� �����ϴ� �Լ�
int CCustomTabCtrl::GetTabText(int nItem, CString &strText)
{
	// �׸��� ������ ��´�
	TCITEM item;
	::memset(&item, 0, sizeof(TCITEM));
	item.mask		= TCIF_TEXT | TCIF_IMAGE;
	item.pszText	= strText.GetBuffer(MAX_PATH);
	item.cchTextMax	= MAX_PATH;

	GetItem(nItem, &item);
	strText.ReleaseBuffer();

	// �̹��� ��ȣ�� �����Ѵ�
	return item.iImage;
}

// ���� �߰��� �ǰ� �̹����� ����Ͽ� �� ��ư�� ����� ����ϴ� �Լ�
void CCustomTabCtrl::RecalcTabSize()
{
	// ���� ������ ��Ʈ���� ���̸� �⺻ ũ��� �����Ѵ�
	CSize szTab(0, m_infoTabBkgndLeft.bmHeight), szImage;

	// ���� ������ �̹��� ����Ʈ�� ��´�
	CImageList *pImageList = GetImageList();
	if(pImageList)
	{
		// �̹��� ����Ʈ�� ������ ��´�
		IMAGEINFO info;
		pImageList->GetImageInfo(0, &info);

		// �̹��� ����Ʈ�� �̹��� ���� ���̸� ��ư ����� �����Ѵ�
		szTab.cx = szImage.cx = info.rcImage.right - info.rcImage.left
			+ CONST_ITEM_GAP * 2;
		szImage.cy = info.rcImage.bottom - info.rcImage.top + CONST_ITEM_GAP;
		if(szTab.cy < szImage.cy)	szTab.cy = szImage.cy;
	}

	CSize szText;
	int i, nSize = GetItemCount();
	CString strText;

	// ���� �� ��Ʈ���� ��Ʈ�� �����Ѵ�
	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());

	// ��� �׸� ����
	for(i = 0; i < nSize; i++)
	{
		// �׸� �ؽ�Ʈ�� ��´�
		GetTabText(i, strText);

		// �ؽ�Ʈ ��¿� �ʿ��� ����� ��´�
		szText = pDC->GetTextExtent(strText);

		// �ؽ�Ʈ ũ��� �̹��� ����Ʈ�� ũ�⸦ �����Ѵ�
		szText.cx += CONST_ITEM_GAP * 2;
		if(szText.cx < szImage.cx)		szText.cx = szImage.cx;
		szText.cy += CONST_ITEM_GAP * 2 + szImage.cy;

		// ���� �� ��ư ũ�⺸�� ũ�ٸ� �����Ѵ�
		if(szText.cx > szTab.cx)	szTab.cx = szText.cx;
		if(szText.cy > szTab.cy)	szTab.cy = szText.cy;
	}

	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// ���� ũ�Ⱑ ���ٸ� ���� ũ�⸦ �����Ѵ�
	if(szTab.cx <= 0)		szTab.cx = CONST_ITEM_GAP * 2;
	if(szTab.cy <= 0)		szTab.cy = CONST_ITEM_GAP * 2;

	// �� ������ ��ǥ�� �ٽ� �����Ѵ�
	m_rcView = m_rcClient;
	m_rcView.top = szTab.cy;

	// �� ��ư�� ũ�⸦ �����Ѵ�
	SetItemSize(szTab);
}

// �� ��ư ��Ʈ���� �����ϴ� �Լ�
void CCustomTabCtrl::SetTabBmp(UINT nLeftID, UINT nCenterID, UINT nRightID)
{
	// ���� ������ ��Ʈ�� ���ҽ��� �����Ѵ�
	if(m_bmpTabBkgndLeft.m_hObject)		m_bmpTabBkgndLeft.DeleteObject();
	if(m_bmpTabBkgndCenter.m_hObject)	m_bmpTabBkgndCenter.DeleteObject();
	if(m_bmpTabBkgndRight.m_hObject)	m_bmpTabBkgndRight.DeleteObject();

	// ���ο� ��Ʈ�� ���ҽ����� �ε��Ѵ�
	if(!m_bmpTabBkgndLeft.LoadBitmap(nLeftID))
	{
		::memset(&m_infoTabBkgndLeft, 0, sizeof(BITMAP));
		return;
	}
	m_bmpTabBkgndLeft.GetBitmap(&m_infoTabBkgndLeft);

	if(!m_bmpTabBkgndCenter.LoadBitmap(nCenterID))
	{
		::memset(&m_infoTabBkgndCenter, 0, sizeof(BITMAP));
		return;
	}
	m_bmpTabBkgndCenter.GetBitmap(&m_infoTabBkgndCenter);

	if(!m_bmpTabBkgndRight.LoadBitmap(nRightID))
	{
		::memset(&m_infoTabBkgndRight, 0, sizeof(BITMAP));
		return;
	}
	m_bmpTabBkgndRight.GetBitmap(&m_infoTabBkgndRight);

	// �� ��ư�� ũ�⸦ �ٽ� ����Ѵ�
	RecalcTabSize();

	// ���� ���� �� ��Ʈ���� ���̴� ���¶�� ȭ���� �����Ѵ�
	if(IsWindowVisible())		Invalidate(FALSE);
}

// �̹��� ����Ʈ�� �����ϴ� �Լ�
CImageList* CCustomTabCtrl::SetImageList(CImageList * pImageList)
{
	// �̹��� ����Ʈ�� �����Ѵ�
	CImageList *pPrevImage = CTabCtrl::SetImageList(pImageList);

	// �� ��ư�� ũ�⸦ �ٽ� ����Ѵ�
	RecalcTabSize();

	// ���� ���� �� ��Ʈ���� ���̴� ���¶�� ȭ���� �����Ѵ�
	if(IsWindowVisible())		Invalidate(FALSE);

	// ���� �̹��� ����Ʈ�� �����Ѵ�
	return pPrevImage;
}

// ��ư�� �ؽ�Ʈ ������ �����ϴ� �Լ�
void CCustomTabCtrl::SetButtonTextColor(COLORREF clrText)
{
	// ��ư �ؽ�Ʈ ������ �����Ѵ�
	m_clrButtonText = clrText;

	// ���� ���� �� ��Ʈ���� ���̴� ���¶�� ȭ���� �����Ѵ�
	if(IsWindowVisible())		Invalidate(FALSE);
}

// ��ư�� �� ������ �����ϴ� �Լ�
void CCustomTabCtrl::SetButtonFaceColor(COLORREF clrFace)
{
	// ��ư �� ������ �����Ѵ�
	m_clrButtonFace = clrFace;

	// ���� ���� �� ��Ʈ���� ���̴� ���¶�� ȭ���� �����Ѵ�
	if(IsWindowVisible())		Invalidate(FALSE);
}

// ��ư�� ���� ������ �����ϴ� �Լ�
void CCustomTabCtrl::SetButtonLightColor(COLORREF clrLight)
{
	// ��ư�� ���� ������ �����Ѵ�
	m_clrButtonLight = clrLight;

	// ���� ���� ���� �����ϰ� ���ο� �������� �ٽ� �����Ѵ�
	m_penButtonLight.DeleteObject();
	m_penButtonLight.CreatePen(PS_SOLID, 1, m_clrButtonLight);

	// ���� ���� �� ��Ʈ���� ���̴� ���¶�� ȭ���� �����Ѵ�
	if(IsWindowVisible())		Invalidate(FALSE);
}

// ��ư�� ��ο� ������ �����ϴ� �Լ�
void CCustomTabCtrl::SetButtonShadowColor(COLORREF clrShadow)
{
	// ��ư�� ��ο� ������ �����Ѵ�
	m_clrButtonShadow = clrShadow;

	// ��ο� ���� ���� �����ϰ� ���ο� �������� �ٽ� �����Ѵ�
	m_penButtonShadow.DeleteObject();
	m_penButtonShadow.CreatePen(PS_SOLID, 1, m_clrButtonShadow);

	// ���� ���� �� ��Ʈ���� ���̴� ���¶�� ȭ���� �����Ѵ�
	if(IsWindowVisible())		Invalidate(FALSE);
}

// ���� �� ���� �׵θ� ������ �����ϴ� �Լ�
void CCustomTabCtrl::SetBorderColor(COLORREF clrBorder)
{
	// ���� �� ���� �׵θ� ������ �����Ѵ�
	m_clrBorder = clrBorder;

	// �׵θ� ���� �����ϰ� ���ο� �������� �ٽ� �����Ѵ�
	m_penBorder.DeleteObject();
	m_penBorder.CreatePen(PS_SOLID, 1, m_clrBorder);

	// ���� ���� �� ��Ʈ���� ���̴� ���¶�� ȭ���� �����Ѵ�
	if(IsWindowVisible())		Invalidate(FALSE);
}

// ���� ��� ������ �����ϴ� �Լ�
void CCustomTabCtrl::SetBkgndColor(COLORREF clrBkgnd)
{
	// ��� ������ �����Ѵ�
	m_clrBkgnd = clrBkgnd;

	// ���� ���� �� ��Ʈ���� ���̴� ���¶�� ȭ���� �����Ѵ�
	if(IsWindowVisible())		Invalidate(FALSE);
}

void CCustomTabCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CDC MemDC;
	CBitmap MemBmp, *pOldBmp;

	MemDC.CreateCompatibleDC(&dc);
	MemBmp.CreateCompatibleBitmap(&dc, m_rcClient.Width(), m_rcClient.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// Ŭ���̾�Ʈ ������ ��� �������� ĥ�Ѵ�
	MemDC.FillSolidRect(&m_rcClient, m_clrBkgnd);

	// ���� �� ��ư ��� ��Ʈ���� �����Ǿ� �ִٸ�
	if(m_bmpTabBkgndLeft.m_hObject && m_bmpTabBkgndCenter.m_hObject && m_bmpTabBkgndRight.m_hObject)
	{
		// m_rcView ���� �������� ��Ʈ�ʵ��� ����Ѵ�
		int nHeight = m_rcView.top;
		int nWidth;

		CDC BmpDC;
		BmpDC.CreateCompatibleDC(&dc);

		nWidth = m_infoTabBkgndLeft.bmWidth;
		CBitmap *pOldBmp = BmpDC.SelectObject(&m_bmpTabBkgndLeft);
		MemDC.StretchBlt(0, 0, nWidth, nHeight,
			&BmpDC, 0, 0, m_infoTabBkgndLeft.bmWidth, m_infoTabBkgndLeft.bmHeight, SRCCOPY);

		// ��� ��Ʈ���� ����/���� ��Ʈ���� ����ϰ� ���� ������ ���� ���η� �÷��� ����Ѵ�
		nWidth = m_rcClient.Width() - m_infoTabBkgndLeft.bmWidth - m_infoTabBkgndRight.bmWidth;
		BmpDC.SelectObject(&m_bmpTabBkgndCenter);
		MemDC.StretchBlt(m_infoTabBkgndLeft.bmWidth, 0, nWidth, nHeight,
			&BmpDC, 0, 0, m_infoTabBkgndCenter.bmWidth, m_infoTabBkgndCenter.bmHeight, SRCCOPY);

		nWidth = m_infoTabBkgndRight.bmWidth;
		BmpDC.SelectObject(&m_bmpTabBkgndRight);
		MemDC.StretchBlt(m_rcClient.Width() - m_infoTabBkgndRight.bmWidth, 0, nWidth, nHeight,
			&BmpDC, 0, 0, m_infoTabBkgndRight.bmWidth, m_infoTabBkgndRight.bmHeight, SRCCOPY);

		BmpDC.SelectObject(pOldBmp);
		BmpDC.DeleteDC();
	}

	// �׵θ� ���� �����Ѵ�
	CPen *pOldPen = MemDC.SelectObject(&m_penBorder);
	// �ձ� �𼭸� �簢���� �׵θ��� ����Ѵ�
	MemDC.RoundRect(&m_rcView, CPoint(6, 6));

	// ���� �� ��Ʈ���� ��Ʈ�� �����Ѵ�
	CFont *pOldFont = MemDC.SelectObject(GetFont());

	// ��� �� ��ư�鿡 ����
	int i, nSize = GetItemCount();
	for(i = 0; i < nSize; i++)
	{
		// �� ��ư�� �׸���
		DrawTab(i, &MemDC);
	}

	dc.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(),
		&MemDC, 0, 0, SRCCOPY);

	// ���� ��ü���� ��ȯ�Ѵ�
	MemDC.SelectObject(pOldPen);
	MemDC.SelectObject(pOldFont);
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
}

BOOL CCustomTabCtrl::OnEraseBkgnd(CDC* pDC) 
{
	// ����� ������ �ʴ´�
	return TRUE;
//	return CTabCtrl::OnEraseBkgnd(pDC);
}

// Ư�� �� ��ư�� �׸��� �Լ�
void CCustomTabCtrl::DrawTab(int nItem, CDC *pDC)
{
	CRect rcItem, rcText;

	// �� ��ư�� ������ ��´�
	GetItemRect(nItem, &rcItem);

	// ������ ������ �����Ѵ�
	rcItem.DeflateRect(1, CONST_ITEM_GAP);
	rcText = rcItem;

	// �� ��ư�� �ؽ�Ʈ�� �̹��� ��ȣ�� ��´�
	CString strTab;
	int nImage = GetTabText(nItem, strTab);

	// ���� ��ư�� ���¸� ��´�
	DWORD nState;
	nState = GetItemState(nItem, TCIS_BUTTONPRESSED);

	// ���� ������ �����̰ų� ���콺�� ��ġ�� �ִٸ�
	if(nState & TCIS_BUTTONPRESSED || m_nHoverItem == nItem)
	{
		// ��ư�� �ܰ��� ������ ��� ��ο� �� ���� ����Ͽ� �׵θ��� �׸���
		pDC->SelectObject(&m_penButtonLight);
		pDC->MoveTo(rcItem.left + 1, rcItem.top);
		pDC->LineTo(rcItem.right, rcItem.top);
		pDC->MoveTo(rcItem.left, rcItem.top + 1);
		pDC->LineTo(rcItem.left, rcItem.bottom);

		pDC->SelectObject(&m_penButtonShadow);
		pDC->MoveTo(rcItem.left + 1, rcItem.bottom);
		pDC->LineTo(rcItem.right, rcItem.bottom);
		pDC->MoveTo(rcItem.right, rcItem.top + 1);
		pDC->LineTo(rcItem.right, rcItem.bottom);

		// �׵θ� ������ ��ư �� �������� ĥ�Ѵ�
		rcItem.DeflateRect(1, 1);
		pDC->FillSolidRect(&rcItem, m_clrButtonFace);
	}

	// �̹��� ����Ʈ�� ��´�
	CImageList *pImageList = GetImageList();
	if(pImageList)
	{
		// ���� �̹��� ����Ʈ�� �����Ǿ� �ִٸ�
		IMAGEINFO info;
		pImageList->GetImageInfo(0, &info);

		// �̹��� ����Ʈ�� ũ�⸦ ���Ѵ�
		CSize szImage;
		szImage.cx = info.rcImage.right - info.rcImage.left;
		szImage.cy = info.rcImage.bottom - info.rcImage.top;

		// �̹����� ��ư ������ �߾� ���ʿ� ����ϱ� ���� ��ǥ�� ����Ѵ�
		CPoint ptImage;
		ptImage.x = rcItem.left + (rcItem.Width() - szImage.cx) / 2;
		ptImage.y = rcItem.top;

		// �̹��� ����Ʈ���� �ش� �̹����� ����Ѵ�
		pImageList->DrawIndirect(pDC, nImage, ptImage, szImage, CPoint(0, 0));

		// �ؽ�Ʈ ��� ������ �����ϳ�
		rcText.top += szImage.cy + CONST_ITEM_GAP;
	}

	// ��ư �ؽ�Ʈ ������ �����Ѵ�
	COLORREF clrOldText = pDC->SetTextColor(m_clrButtonText);
	// �ؽ�Ʈ ��� ��� ��带 �������� �����Ѵ�
	int nBkMode = pDC->SetBkMode(TRANSPARENT);

	// ��ư �ؽ�Ʈ�� ����Ѥ�
	pDC->DrawText(strTab, &rcText, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	// ���� �Ӽ��� �����Ѵ�
	pDC->SetTextColor(clrOldText);
	pDC->SetBkMode(nBkMode);
}

void CCustomTabCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���콺�� �� ��ư ������ �̵� ���̸�,
	// �ý��ۿ��� ���콺�� Ż�⿡ ���� �޽����� ������ ���� ��û
	TRACKMOUSEEVENT MouseEvent;
	MouseEvent.cbSize		= sizeof(TRACKMOUSEEVENT);
	MouseEvent.dwFlags		= TME_LEAVE;
	MouseEvent.hwndTrack	= m_hWnd;
	MouseEvent.dwHoverTime	= 1;

	::TrackMouseEvent(&MouseEvent);
	
	// �� ��ư���� ������ ���콺�� �ִ��� Ȯ���Ѵ�
	int i, nSize = GetItemCount();
	CRect rcItem;

	for(i = 0; i < nSize; i++)
	{
		GetItemRect(i, &rcItem);

		if(rcItem.PtInRect(point))
		{
			// ���� ������ ���콺�� ��ġ�ߴ� ��ư�� �ƴ϶��
			if(m_nHoverItem != i)
			{
				// ���� ���콺�� ��ġ�ߴ� ��ư�� ������ ���Ѵ�
				CRect rcPrevItem;
				GetItemRect(m_nHoverItem, &rcPrevItem);

				// ���ο� ��ư�� ��ȣ�� �����Ѵ�
				m_nHoverItem = i;

				// ���� ��ư ������ ���ο� ��ư ������ �ٽ� �׸���
				InvalidateRect(&rcPrevItem, FALSE);
				InvalidateRect(&rcItem, FALSE);
			}
			break;
		}
	}

	CTabCtrl::OnMouseMove(nFlags, point);
}

LRESULT CCustomTabCtrl::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	// ���콺�� �� ��ư�� ������ ����ٸ�
	// ���� ���콺�� ���� ȿ���� ��µ� ��ư�� �ִٸ�
	if(m_nHoverItem >= 0)
	{
		// �ش� ��ư�� ������ ���Ѵ�
		CRect rcItem;
		GetItemRect(m_nHoverItem, &rcItem);

		// ���콺�� ��ġ�� ��ư�� ��ȣ�� �ʱ�ȭ�Ѵ�
		m_nHoverItem = -1;

		// �ش� ��ư�� ������ �ٽ� �׸���
		InvalidateRect(&rcItem, FALSE);
	}

	return 0;
}

void CCustomTabCtrl::OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// ���� �� ��ȣ�� ��´�
	int nTab = GetCurSel();

	// �� ��ȣ�� �����̶��
	if(nTab >= 0 && nTab < m_Containers.GetSize())
	{
		// �ǿ� �ش��ϴ� �����̳� �����͸� ��´�
		CControlContainer *pContainer = m_Containers.GetAt(nTab);
		// �����̳��� ��Ʈ�ѵ��� �����
		pContainer->ShowControls(FALSE);
	}
	
	// �θ� ���̾�α׿��� ���� �ٲ�� ������ �˸���
	GetParent()->SendMessage(WM_OT_SELCHANGING, GetDlgCtrlID(), nTab);

	*pResult = 0;
}

void CCustomTabCtrl::OnSelchange(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// ���� �� ��ȣ�� ��´�
	int nTab = GetCurSel();

	// �� ��ȣ�� �����̶��
	if(nTab >= 0 && nTab < m_Containers.GetSize())
	{
		// �ǿ� �ش��ϴ� �����̳� �����͸� ��´�
		CControlContainer *pContainer = m_Containers.GetAt(nTab);
		// �����̳��� ��Ʈ�ѵ��� ���̰� �����
		pContainer->ShowControls(TRUE);
	}

	// �θ� ���̾�α׿��� ���� �ٲ������ �˸���
	GetParent()->SendMessage(WM_OT_SELCHANGE, GetDlgCtrlID(), nTab);

	Invalidate(FALSE);

	*pResult = 0;
}

// Ư�� ���� �����ϴ� �Լ�
int CCustomTabCtrl::SetCurSel(int nItem)
{
	// ���� �� ��ȣ�� ��´�
	int nCur = GetCurSel();
	CControlContainer *pContainer;

	// ���� ���� �� ��ȣ�� ���� �����ϴ� �� ��ȣ�� �ٸ��ٸ�
	if(nCur != nItem)
	{
		// ���� �� ��ȣ�� �����̶��
		if(nCur >= 0 && nCur < m_Containers.GetSize())
		{
			// �ǿ� �ش��ϴ� �����̳� �����͸� ��´�
			pContainer = m_Containers.GetAt(nCur);
			// �����̳��� ��Ʈ�ѵ��� �����
			pContainer->ShowControls(FALSE);
		}

		// ���ο� ���� �����Ѵ�
		CTabCtrl::SetCurSel(nItem);
	}

	// ���� ���ο� �� ��ȣ�� �����̶��
	if(nItem >= 0 && nItem < m_Containers.GetSize())
	{
		// �ǿ� �ش��ϴ� �����̳� �����͸� ��´�
		pContainer = m_Containers.GetAt(nItem);
		// �����̳��� ��Ʈ�ѵ��� ���̰� �����
		pContainer->ShowControls(TRUE);
	}

	// ���� �� ��ȣ�� �����Ѵ�
	return nCur;
}

// Ư�� �ǿ� ��Ʈ���� �߰��ϴ� �Լ�
BOOL CCustomTabCtrl::AddControl(int nTab, CWnd *pWnd)
{
	// ���� �� ��ȣ�� ������ �ƴ϶�� �����Ѵ�
	if(nTab < 0 || nTab >= m_Containers.GetSize())		return FALSE;

	// �ǿ� �ش��ϴ� �����̳� �����͸� ��´�
	CControlContainer *pContainer = m_Containers.GetAt(nTab);
	// �����̳ʸ� ���� �� ���ٸ� �����Ѵ�
	if(pContainer == NULL)					return FALSE;

	// �߰��Ϸ��� ��Ʈ���� �����
	pWnd->ShowWindow(SW_HIDE);
	// �����̳ʿ� �߰��Ѵ�
	pContainer->AddControl(pWnd);

	return TRUE;
}

// ���ο� ���� �����ϴ� �Լ�
BOOL CCustomTabCtrl::InsertItem(int nItem, TCITEM* pTabCtrlItem)
{
	// ���� �߰��Ѵ�
	if(CTabCtrl::InsertItem(nItem, pTabCtrlItem) < 0)	return FALSE;

	// ���ο� �����̳ʸ� �����Ѵ�
	CControlContainer *pItem = new CControlContainer;

	// ���� �� �߰��� �����ϴ� ���̶��
	if(nItem < m_Containers.GetSize())
		// �ش� ��ġ�� �����Ѵ�
		m_Containers.InsertAt(nItem, pItem);
	else
		// �迭�� �߰��Ѵ�
		m_Containers.Add(pItem);

	// �� ��ư�� ũ�⸦ �ٽ� ����Ѵ�
	RecalcTabSize();

	return TRUE;
}

// ���ο� ���� �����ϴ� �Լ�
BOOL CCustomTabCtrl::InsertItem(int nItem, LPCTSTR lpszItem)
{
	// ���� �߰��Ѵ�
	if(CTabCtrl::InsertItem(nItem, lpszItem) < 0)	return FALSE;

	// ���ο� �����̳ʸ� �����Ѵ�
	CControlContainer *pItem = new CControlContainer;

	// ���� �� �߰��� �����ϴ� ���̶��
	if(nItem < m_Containers.GetSize())
		// �ش� ��ġ�� �����Ѵ�
		m_Containers.InsertAt(nItem, pItem);
	else
		// �迭�� �߰��Ѵ�
		m_Containers.Add(pItem);

	// �� ��ư�� ũ�⸦ �ٽ� ����Ѵ�
	RecalcTabSize();

	return TRUE;
}

// ���ο� ���� �����ϴ� �Լ�
BOOL CCustomTabCtrl::InsertItem(int nItem, LPCTSTR lpszItem, int nImage)
{
	// ���� �߰��Ѵ�
	if(CTabCtrl::InsertItem(nItem, lpszItem, nImage) < 0)	return FALSE;

	// ���ο� �����̳ʸ� �����Ѵ�
	CControlContainer *pItem = new CControlContainer;

	// ���� �� �߰��� �����ϴ� ���̶��
	if(nItem < m_Containers.GetSize())
		// �ش� ��ġ�� �����Ѵ�
		m_Containers.InsertAt(nItem, pItem);
	else
		// �迭�� �߰��Ѵ�
		m_Containers.Add(pItem);

	// �� ��ư�� ũ�⸦ �ٽ� ����Ѵ�
	RecalcTabSize();

	return TRUE;
}

// ���ο� ���� �����ϴ� �Լ�
BOOL CCustomTabCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam)
{
	// ���� �߰��Ѵ�
	if(CTabCtrl::InsertItem(nMask, nItem, lpszItem, nImage, lParam) < 0)	return FALSE;

	// ���ο� �����̳ʸ� �����Ѵ�
	CControlContainer *pItem = new CControlContainer;

	// ���� �� �߰��� �����ϴ� ���̶��
	if(nItem < m_Containers.GetSize())
		// �ش� ��ġ�� �����Ѵ�
		m_Containers.InsertAt(nItem, pItem);
	else
		// �迭�� �߰��Ѵ�
		m_Containers.Add(pItem);

	// �� ��ư�� ũ�⸦ �ٽ� ����Ѵ�
	RecalcTabSize();

	return TRUE;
}

// Ư�� ���� �����ϴ� �Լ�
BOOL CCustomTabCtrl::DeleteItem(int nItem)
{
	// ���� �����Ѵ�
	if(!CTabCtrl::DeleteItem(nItem))		return FALSE;

	// �� ��ȣ�� �����̳� �迭�� ũ�⺸�� �۴ٸ�
	if(nItem >= 0 && nItem < m_Containers.GetSize())
	{
		// �ش� �����̳ʸ� �����Ѵ�
		delete m_Containers.GetAt(nItem);
		// �迭���� �����̳ʸ� �����Ѵ�
		m_Containers.RemoveAt(nItem);
	}

	// �� ��ư�� ũ�⸦ �ٽ� ����Ѵ�
	RecalcTabSize();

	return TRUE;
}

// ��� ���� �����ϴ� �Լ�
BOOL CCustomTabCtrl::DeleteAllItems()
{
	// ��� ���� �����Ѵ�
	if(!CTabCtrl::DeleteAllItems())			return FALSE;

	// �����̳� �迭�� ũ�⸦ ���Ѵ�
	int i, nSize = (int)m_Containers.GetSize();
	for(i = 0; i < nSize; i++)
	{
		// �� �����̳ʸ� �����Ѵ�
		delete m_Containers.GetAt(i);
	}
	// �迭�� �ʱ�ȭ�Ѵ�
	m_Containers.RemoveAll();

	return TRUE;
}

void CCustomTabCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CTabCtrl::OnHScroll(nSBCode, nPos, pScrollBar);

	if(nSBCode == SB_ENDSCROLL)
	{
		Invalidate(FALSE);
	}
}
