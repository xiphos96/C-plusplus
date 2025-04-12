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

// 생성자
CControlContainer::CControlContainer()
{
	// 멤버 변수를 초기화한다
	m_bShow = FALSE;
}

// 소멸자
CControlContainer::~CControlContainer()
{
	// 컨트롤 배열을 초기화한다
	m_Controls.RemoveAll();
}

// 컨테이너에 컨트롤을 추가하는 함수
int CControlContainer::AddControl(CWnd *pCtrl)
{
	// 컨트롤 배열에 포인터를 추가한다
	return (int)m_Controls.Add(pCtrl);
}

// 컨테이너의 컨트롤들을 보이거나 감추는 함수
void CControlContainer::ShowControls(BOOL bShow)
{
	// 만약 현재 상태와 동일하다면 리턴
	if(m_bShow == bShow)		return;

	// 새로운 상태를 저장한다
	m_bShow = bShow;

	// 컨트롤 배열의 모든 컨트롤을 보이거나 감춘다
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

// 이미지와 텍스트, 그리고 각 버튼 사이의 여백
#define CONST_ITEM_GAP			4

CCustomTabCtrl::CCustomTabCtrl()
{
	// 멤버 변수들을 초기화한다
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
	// GDI 리소스들을 반환한다
	if(m_bmpTabBkgndLeft.m_hObject)		m_bmpTabBkgndLeft.DeleteObject();
	if(m_bmpTabBkgndCenter.m_hObject)	m_bmpTabBkgndCenter.DeleteObject();
	if(m_bmpTabBkgndRight.m_hObject)	m_bmpTabBkgndRight.DeleteObject();

	m_penButtonLight.DeleteObject();
	m_penButtonShadow.DeleteObject();
	m_penBorder.DeleteObject();

	// 컨테이너 배열의 내용을 제거한다
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
	// 탭 컨트롤의 속성을 변경한다
	ModifyStyle(TCS_RIGHTJUSTIFY | TCS_RAGGEDRIGHT, TCS_OWNERDRAWFIXED, SWP_FRAMECHANGED);
	
	// 탭의 클라이언트 영역을 구한다
	GetClientRect(&m_rcClient);

	// 기본 버튼 크기와 영역을 계산한다
	RecalcTabSize();

	CTabCtrl::PreSubclassWindow();
}

// 특정 탭의 텍스트와 이미지 번호를 리턴하는 함수
int CCustomTabCtrl::GetTabText(int nItem, CString &strText)
{
	// 항목의 정보를 얻는다
	TCITEM item;
	::memset(&item, 0, sizeof(TCITEM));
	item.mask		= TCIF_TEXT | TCIF_IMAGE;
	item.pszText	= strText.GetBuffer(MAX_PATH);
	item.cchTextMax	= MAX_PATH;

	GetItem(nItem, &item);
	strText.ReleaseBuffer();

	// 이미지 번호를 리턴한다
	return item.iImage;
}

// 현재 추가된 탭과 이미지를 계산하여 탭 버튼의 사이즈를 계산하는 함수
void CCustomTabCtrl::RecalcTabSize()
{
	// 현재 설정된 비트맵의 높이를 기본 크기로 설정한다
	CSize szTab(0, m_infoTabBkgndLeft.bmHeight), szImage;

	// 현재 설정된 이미지 리스트를 얻는다
	CImageList *pImageList = GetImageList();
	if(pImageList)
	{
		// 이미지 리스트의 정보를 얻는다
		IMAGEINFO info;
		pImageList->GetImageInfo(0, &info);

		// 이미지 리스트의 이미지 폭과 높이를 버튼 사이즈에 적용한다
		szTab.cx = szImage.cx = info.rcImage.right - info.rcImage.left
			+ CONST_ITEM_GAP * 2;
		szImage.cy = info.rcImage.bottom - info.rcImage.top + CONST_ITEM_GAP;
		if(szTab.cy < szImage.cy)	szTab.cy = szImage.cy;
	}

	CSize szText;
	int i, nSize = GetItemCount();
	CString strText;

	// 현재 탭 컨트롤의 폰트를 설정한다
	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());

	// 모든 항목에 대해
	for(i = 0; i < nSize; i++)
	{
		// 항목 텍스트를 얻는다
		GetTabText(i, strText);

		// 텍스트 출력에 필요한 사이즈를 얻는다
		szText = pDC->GetTextExtent(strText);

		// 텍스트 크기와 이미지 리스트의 크기를 조합한다
		szText.cx += CONST_ITEM_GAP * 2;
		if(szText.cx < szImage.cx)		szText.cx = szImage.cx;
		szText.cy += CONST_ITEM_GAP * 2 + szImage.cy;

		// 현재 탭 버튼 크기보다 크다면 적용한다
		if(szText.cx > szTab.cx)	szTab.cx = szText.cx;
		if(szText.cy > szTab.cy)	szTab.cy = szText.cy;
	}

	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// 만약 크기가 없다면 여백 크기를 설정한다
	if(szTab.cx <= 0)		szTab.cx = CONST_ITEM_GAP * 2;
	if(szTab.cy <= 0)		szTab.cy = CONST_ITEM_GAP * 2;

	// 뷰 영역의 좌표를 다시 설정한다
	m_rcView = m_rcClient;
	m_rcView.top = szTab.cy;

	// 탭 버튼의 크기를 설정한다
	SetItemSize(szTab);
}

// 탭 버튼 비트맵을 설정하는 함수
void CCustomTabCtrl::SetTabBmp(UINT nLeftID, UINT nCenterID, UINT nRightID)
{
	// 현재 설정된 비트맵 리소스를 제거한다
	if(m_bmpTabBkgndLeft.m_hObject)		m_bmpTabBkgndLeft.DeleteObject();
	if(m_bmpTabBkgndCenter.m_hObject)	m_bmpTabBkgndCenter.DeleteObject();
	if(m_bmpTabBkgndRight.m_hObject)	m_bmpTabBkgndRight.DeleteObject();

	// 새로운 비트맵 리소스들을 로드한다
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

	// 탭 버튼의 크기를 다시 계산한다
	RecalcTabSize();

	// 만약 현재 탭 컨트롤이 보이는 상태라면 화면을 갱신한다
	if(IsWindowVisible())		Invalidate(FALSE);
}

// 이미지 리스트를 설정하는 함수
CImageList* CCustomTabCtrl::SetImageList(CImageList * pImageList)
{
	// 이미지 리스트를 설정한다
	CImageList *pPrevImage = CTabCtrl::SetImageList(pImageList);

	// 탭 버튼의 크기를 다시 계산한다
	RecalcTabSize();

	// 만약 현재 탭 컨트롤이 보이는 상태라면 화면을 갱신한다
	if(IsWindowVisible())		Invalidate(FALSE);

	// 이전 이미지 리스트를 리턴한다
	return pPrevImage;
}

// 버튼의 텍스트 색상을 설정하는 함수
void CCustomTabCtrl::SetButtonTextColor(COLORREF clrText)
{
	// 버튼 텍스트 색상을 저장한다
	m_clrButtonText = clrText;

	// 만약 현재 탭 컨트롤이 보이는 상태라면 화면을 갱신한다
	if(IsWindowVisible())		Invalidate(FALSE);
}

// 버튼의 면 색상을 설정하는 함수
void CCustomTabCtrl::SetButtonFaceColor(COLORREF clrFace)
{
	// 버튼 면 색상을 저장한다
	m_clrButtonFace = clrFace;

	// 만약 현재 탭 컨트롤이 보이는 상태라면 화면을 갱신한다
	if(IsWindowVisible())		Invalidate(FALSE);
}

// 버튼의 밝은 색상을 설정하는 함수
void CCustomTabCtrl::SetButtonLightColor(COLORREF clrLight)
{
	// 버튼의 밝은 색상을 저장한다
	m_clrButtonLight = clrLight;

	// 밝은 색상 펜을 제거하고 새로운 색상으로 다시 생성한다
	m_penButtonLight.DeleteObject();
	m_penButtonLight.CreatePen(PS_SOLID, 1, m_clrButtonLight);

	// 만약 현재 탭 컨트롤이 보이는 상태라면 화면을 갱신한다
	if(IsWindowVisible())		Invalidate(FALSE);
}

// 버튼의 어두운 색상을 설정하는 함수
void CCustomTabCtrl::SetButtonShadowColor(COLORREF clrShadow)
{
	// 버튼의 어두운 색상을 저장한다
	m_clrButtonShadow = clrShadow;

	// 어두운 색상 펜을 제거하고 새로운 색상으로 다시 생성한다
	m_penButtonShadow.DeleteObject();
	m_penButtonShadow.CreatePen(PS_SOLID, 1, m_clrButtonShadow);

	// 만약 현재 탭 컨트롤이 보이는 상태라면 화면을 갱신한다
	if(IsWindowVisible())		Invalidate(FALSE);
}

// 탭의 뷰 영역 테두리 색상을 설정하는 함수
void CCustomTabCtrl::SetBorderColor(COLORREF clrBorder)
{
	// 탭의 뷰 영역 테두리 색상을 저장한다
	m_clrBorder = clrBorder;

	// 테두리 펜을 제거하고 새로운 색상으로 다시 생성한다
	m_penBorder.DeleteObject();
	m_penBorder.CreatePen(PS_SOLID, 1, m_clrBorder);

	// 만약 현재 탭 컨트롤이 보이는 상태라면 화면을 갱신한다
	if(IsWindowVisible())		Invalidate(FALSE);
}

// 탭의 배경 색상을 설정하는 함수
void CCustomTabCtrl::SetBkgndColor(COLORREF clrBkgnd)
{
	// 배경 색상을 저장한다
	m_clrBkgnd = clrBkgnd;

	// 만약 현재 탭 컨트롤이 보이는 상태라면 화면을 갱신한다
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

	// 클라이언트 영역을 배경 색상으로 칠한다
	MemDC.FillSolidRect(&m_rcClient, m_clrBkgnd);

	// 만약 탭 버튼 배경 비트맵이 설정되어 있다면
	if(m_bmpTabBkgndLeft.m_hObject && m_bmpTabBkgndCenter.m_hObject && m_bmpTabBkgndRight.m_hObject)
	{
		// m_rcView 영역 위쪽으로 비트맵들을 출력한다
		int nHeight = m_rcView.top;
		int nWidth;

		CDC BmpDC;
		BmpDC.CreateCompatibleDC(&dc);

		nWidth = m_infoTabBkgndLeft.bmWidth;
		CBitmap *pOldBmp = BmpDC.SelectObject(&m_bmpTabBkgndLeft);
		MemDC.StretchBlt(0, 0, nWidth, nHeight,
			&BmpDC, 0, 0, m_infoTabBkgndLeft.bmWidth, m_infoTabBkgndLeft.bmHeight, SRCCOPY);

		// 가운데 비트맵은 좌측/우측 비트맵을 출력하고 남는 영역에 대해 가로로 늘려서 출력한다
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

	// 테두리 펜을 설정한다
	CPen *pOldPen = MemDC.SelectObject(&m_penBorder);
	// 둥근 모서리 사각형을 테두리로 출력한다
	MemDC.RoundRect(&m_rcView, CPoint(6, 6));

	// 현재 탭 컨트롤의 폰트를 설정한다
	CFont *pOldFont = MemDC.SelectObject(GetFont());

	// 모든 탭 버튼들에 대해
	int i, nSize = GetItemCount();
	for(i = 0; i < nSize; i++)
	{
		// 탭 버튼을 그린다
		DrawTab(i, &MemDC);
	}

	dc.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(),
		&MemDC, 0, 0, SRCCOPY);

	// 이전 객체들을 반환한다
	MemDC.SelectObject(pOldPen);
	MemDC.SelectObject(pOldFont);
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
}

BOOL CCustomTabCtrl::OnEraseBkgnd(CDC* pDC) 
{
	// 배경을 지우지 않는다
	return TRUE;
//	return CTabCtrl::OnEraseBkgnd(pDC);
}

// 특정 탭 버튼을 그리는 함수
void CCustomTabCtrl::DrawTab(int nItem, CDC *pDC)
{
	CRect rcItem, rcText;

	// 탭 버튼의 영역을 얻는다
	GetItemRect(nItem, &rcItem);

	// 영역을 적절히 조정한다
	rcItem.DeflateRect(1, CONST_ITEM_GAP);
	rcText = rcItem;

	// 탭 버튼의 텍스트와 이미지 번호를 얻는다
	CString strTab;
	int nImage = GetTabText(nItem, strTab);

	// 현재 버튼의 상태를 얻는다
	DWORD nState;
	nState = GetItemState(nItem, TCIS_BUTTONPRESSED);

	// 만약 눌려진 상태이거나 마우스가 위치해 있다면
	if(nState & TCIS_BUTTONPRESSED || m_nHoverItem == nItem)
	{
		// 버튼의 외곽에 밝은색 펜과 어두운 색 펜을 사용하여 테두리를 그린다
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

		// 테두리 안쪽을 버튼 면 색상으로 칠한다
		rcItem.DeflateRect(1, 1);
		pDC->FillSolidRect(&rcItem, m_clrButtonFace);
	}

	// 이미지 리스트를 얻는다
	CImageList *pImageList = GetImageList();
	if(pImageList)
	{
		// 만약 이미지 리스트가 설정되어 있다면
		IMAGEINFO info;
		pImageList->GetImageInfo(0, &info);

		// 이미지 리스트의 크기를 구한다
		CSize szImage;
		szImage.cx = info.rcImage.right - info.rcImage.left;
		szImage.cy = info.rcImage.bottom - info.rcImage.top;

		// 이미지를 버튼 영역의 중앙 위쪽에 출력하기 위해 좌표를 계산한다
		CPoint ptImage;
		ptImage.x = rcItem.left + (rcItem.Width() - szImage.cx) / 2;
		ptImage.y = rcItem.top;

		// 이미지 리스트에서 해당 이미지를 출력한다
		pImageList->DrawIndirect(pDC, nImage, ptImage, szImage, CPoint(0, 0));

		// 텍스트 출력 영역을 보정하나
		rcText.top += szImage.cy + CONST_ITEM_GAP;
	}

	// 버튼 텍스트 색상을 설정한다
	COLORREF clrOldText = pDC->SetTextColor(m_clrButtonText);
	// 텍스트 출력 배경 모드를 투명으로 설정한다
	int nBkMode = pDC->SetBkMode(TRANSPARENT);

	// 버튼 텍스트를 출력한ㄷ
	pDC->DrawText(strTab, &rcText, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	// 이전 속성을 복구한다
	pDC->SetTextColor(clrOldText);
	pDC->SetBkMode(nBkMode);
}

void CCustomTabCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 마우스가 탭 버튼 위에서 이동 중이면,
	// 시스템에게 마우스의 탈출에 대한 메시지를 보내줄 것을 요청
	TRACKMOUSEEVENT MouseEvent;
	MouseEvent.cbSize		= sizeof(TRACKMOUSEEVENT);
	MouseEvent.dwFlags		= TME_LEAVE;
	MouseEvent.hwndTrack	= m_hWnd;
	MouseEvent.dwHoverTime	= 1;

	::TrackMouseEvent(&MouseEvent);
	
	// 탭 버튼들의 영역에 마우스가 있는지 확인한다
	int i, nSize = GetItemCount();
	CRect rcItem;

	for(i = 0; i < nSize; i++)
	{
		GetItemRect(i, &rcItem);

		if(rcItem.PtInRect(point))
		{
			// 만약 이전에 마우스가 위치했던 버튼이 아니라면
			if(m_nHoverItem != i)
			{
				// 이전 마우스가 위치했던 버튼의 영역을 구한다
				CRect rcPrevItem;
				GetItemRect(m_nHoverItem, &rcPrevItem);

				// 새로운 버튼의 번호를 저장한다
				m_nHoverItem = i;

				// 이전 버튼 영역과 새로운 버튼 영역을 다시 그린다
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
	// 마우스가 탭 버튼의 영역을 벗어났다면
	// 만약 마우스에 따른 효과가 출력된 버튼이 있다면
	if(m_nHoverItem >= 0)
	{
		// 해당 버튼의 영역을 구한다
		CRect rcItem;
		GetItemRect(m_nHoverItem, &rcItem);

		// 마우스가 위치한 버튼의 번호를 초기화한다
		m_nHoverItem = -1;

		// 해당 버튼의 영역을 다시 그린다
		InvalidateRect(&rcItem, FALSE);
	}

	return 0;
}

void CCustomTabCtrl::OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// 현재 탭 번호를 얻는다
	int nTab = GetCurSel();

	// 탭 번호가 정상이라면
	if(nTab >= 0 && nTab < m_Containers.GetSize())
	{
		// 탭에 해당하는 컨테이너 포인터를 얻는다
		CControlContainer *pContainer = m_Containers.GetAt(nTab);
		// 컨테이너의 컨트롤들을 감춘다
		pContainer->ShowControls(FALSE);
	}
	
	// 부모 다이얼로그에게 탭이 바뀌고 있음을 알린다
	GetParent()->SendMessage(WM_OT_SELCHANGING, GetDlgCtrlID(), nTab);

	*pResult = 0;
}

void CCustomTabCtrl::OnSelchange(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// 현재 탭 번호를 얻는다
	int nTab = GetCurSel();

	// 탭 번호가 정상이라면
	if(nTab >= 0 && nTab < m_Containers.GetSize())
	{
		// 탭에 해당하는 컨테이너 포인터를 얻는다
		CControlContainer *pContainer = m_Containers.GetAt(nTab);
		// 컨테이너의 컨트롤들을 보이게 만든다
		pContainer->ShowControls(TRUE);
	}

	// 부모 다이얼로그에게 탭이 바뀌었음을 알린다
	GetParent()->SendMessage(WM_OT_SELCHANGE, GetDlgCtrlID(), nTab);

	Invalidate(FALSE);

	*pResult = 0;
}

// 특정 탭을 선택하는 함수
int CCustomTabCtrl::SetCurSel(int nItem)
{
	// 현재 탭 번호를 얻는다
	int nCur = GetCurSel();
	CControlContainer *pContainer;

	// 만약 현재 탭 번호가 새로 설정하는 탭 번호와 다르다면
	if(nCur != nItem)
	{
		// 현재 탭 번호가 정상이라면
		if(nCur >= 0 && nCur < m_Containers.GetSize())
		{
			// 탭에 해당하는 컨테이너 포인터를 얻는다
			pContainer = m_Containers.GetAt(nCur);
			// 컨테이너의 컨트롤들을 감춘다
			pContainer->ShowControls(FALSE);
		}

		// 새로운 탭을 선택한다
		CTabCtrl::SetCurSel(nItem);
	}

	// 만약 새로운 탭 번호가 정상이라면
	if(nItem >= 0 && nItem < m_Containers.GetSize())
	{
		// 탭에 해당하는 컨테이너 포인터를 얻는다
		pContainer = m_Containers.GetAt(nItem);
		// 컨테이너의 컨트롤들을 보이게 만든다
		pContainer->ShowControls(TRUE);
	}

	// 이전 탭 번호를 리턴한다
	return nCur;
}

// 특정 탭에 컨트롤을 추가하는 함수
BOOL CCustomTabCtrl::AddControl(int nTab, CWnd *pWnd)
{
	// 만약 탭 번호가 정상이 아니라면 리턴한다
	if(nTab < 0 || nTab >= m_Containers.GetSize())		return FALSE;

	// 탭에 해당하는 컨테이너 포인터를 얻는다
	CControlContainer *pContainer = m_Containers.GetAt(nTab);
	// 컨테이너를 얻을 수 없다면 리턴한다
	if(pContainer == NULL)					return FALSE;

	// 추가하려는 컨트롤을 감춘다
	pWnd->ShowWindow(SW_HIDE);
	// 컨테이너에 추가한다
	pContainer->AddControl(pWnd);

	return TRUE;
}

// 새로운 탭을 생성하는 함수
BOOL CCustomTabCtrl::InsertItem(int nItem, TCITEM* pTabCtrlItem)
{
	// 탭을 추가한다
	if(CTabCtrl::InsertItem(nItem, pTabCtrlItem) < 0)	return FALSE;

	// 새로운 컨테이너를 생성한다
	CControlContainer *pItem = new CControlContainer;

	// 만약 탭 중간에 삽입하는 것이라면
	if(nItem < m_Containers.GetSize())
		// 해당 위치에 삽입한다
		m_Containers.InsertAt(nItem, pItem);
	else
		// 배열에 추가한다
		m_Containers.Add(pItem);

	// 탭 버튼의 크기를 다시 계산한다
	RecalcTabSize();

	return TRUE;
}

// 새로운 탭을 생성하는 함수
BOOL CCustomTabCtrl::InsertItem(int nItem, LPCTSTR lpszItem)
{
	// 탭을 추가한다
	if(CTabCtrl::InsertItem(nItem, lpszItem) < 0)	return FALSE;

	// 새로운 컨테이너를 생성한다
	CControlContainer *pItem = new CControlContainer;

	// 만약 탭 중간에 삽입하는 것이라면
	if(nItem < m_Containers.GetSize())
		// 해당 위치에 삽입한다
		m_Containers.InsertAt(nItem, pItem);
	else
		// 배열에 추가한다
		m_Containers.Add(pItem);

	// 탭 버튼의 크기를 다시 계산한다
	RecalcTabSize();

	return TRUE;
}

// 새로운 탭을 생성하는 함수
BOOL CCustomTabCtrl::InsertItem(int nItem, LPCTSTR lpszItem, int nImage)
{
	// 탭을 추가한다
	if(CTabCtrl::InsertItem(nItem, lpszItem, nImage) < 0)	return FALSE;

	// 새로운 컨테이너를 생성한다
	CControlContainer *pItem = new CControlContainer;

	// 만약 탭 중간에 삽입하는 것이라면
	if(nItem < m_Containers.GetSize())
		// 해당 위치에 삽입한다
		m_Containers.InsertAt(nItem, pItem);
	else
		// 배열에 추가한다
		m_Containers.Add(pItem);

	// 탭 버튼의 크기를 다시 계산한다
	RecalcTabSize();

	return TRUE;
}

// 새로운 탭을 생성하는 함수
BOOL CCustomTabCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam)
{
	// 탭을 추가한다
	if(CTabCtrl::InsertItem(nMask, nItem, lpszItem, nImage, lParam) < 0)	return FALSE;

	// 새로운 컨테이너를 생성한다
	CControlContainer *pItem = new CControlContainer;

	// 만약 탭 중간에 삽입하는 것이라면
	if(nItem < m_Containers.GetSize())
		// 해당 위치에 삽입한다
		m_Containers.InsertAt(nItem, pItem);
	else
		// 배열에 추가한다
		m_Containers.Add(pItem);

	// 탭 버튼의 크기를 다시 계산한다
	RecalcTabSize();

	return TRUE;
}

// 특정 탭을 삭제하는 함수
BOOL CCustomTabCtrl::DeleteItem(int nItem)
{
	// 탭을 삭제한다
	if(!CTabCtrl::DeleteItem(nItem))		return FALSE;

	// 탭 번호가 컨테이너 배열의 크기보다 작다면
	if(nItem >= 0 && nItem < m_Containers.GetSize())
	{
		// 해당 컨테이너를 삭제한다
		delete m_Containers.GetAt(nItem);
		// 배열에서 컨테이너를 제거한다
		m_Containers.RemoveAt(nItem);
	}

	// 탭 버튼의 크기를 다시 계산한다
	RecalcTabSize();

	return TRUE;
}

// 모든 탭을 삭제하는 함수
BOOL CCustomTabCtrl::DeleteAllItems()
{
	// 모든 탭을 삭제한다
	if(!CTabCtrl::DeleteAllItems())			return FALSE;

	// 컨테이너 배열의 크기를 구한다
	int i, nSize = (int)m_Containers.GetSize();
	for(i = 0; i < nSize; i++)
	{
		// 각 컨테이너를 삭제한다
		delete m_Containers.GetAt(i);
	}
	// 배열을 초기화한다
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
