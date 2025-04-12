// SymbolChart.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "SymbolChart.h"
#include "SymbolPreviewStatic.h"
#include "SymbolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSymbolChart

CSymbolChart::CSymbolChart()
{
	// 변수 초기화
	m_bIsUnicode		= FALSE;
	m_bIsUpper			= TRUE;
	m_cHighByte			= 0x00;

	m_SelectedCode		= 0;

	m_FontName			= "굴림";
	m_pEdit				= NULL;
	m_pPreview			= NULL;
}

CSymbolChart::~CSymbolChart()
{
	// 폰트를 소멸시킨다
	m_DisplayFont.DeleteObject();
}


BEGIN_MESSAGE_MAP(CSymbolChart, CStatic)
	//{{AFX_MSG_MAP(CSymbolChart)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSymbolChart message handlers

void CSymbolChart::InitCodeChart()
{
	// 클라이언트 영역의 크기를 구하고 각 셀의 폭과 높이를 계산한다
	GetClientRect(&m_ClientRect);
	m_nItemWidth	= m_ClientRect.Width() / 16;
	m_nItemHeight	= m_ClientRect.Height() / 8;

	// 셀을 그리고 남는 수평 여백을 구한다
	int nHorzInterval = m_ClientRect.Width() - (16 * m_nItemWidth);
	CRect rcClient;

	// 문자표 컨트롤의 위치를 구한다
	GetWindowRect(&rcClient);
	GetParent()->ScreenToClient(&rcClient);

	// 수평 여백을 고려하여 문자표 위치를 재조정한다
	rcClient.left	+= (nHorzInterval / 2);
	rcClient.right	= rcClient.left + (m_nItemWidth * 16) + 4;
	rcClient.bottom	= rcClient.top + (m_nItemHeight * 8) + 4;

	MoveWindow(rcClient);

	// 클라이언트 영역을 재조정한다
	m_ClientRect.SetRect(0, 0, m_nItemWidth * 16 - 1, m_nItemHeight * 8 - 1);

	// 특수 문자 출력에 사용할 폰트를 생성한다
	HDC hDC = ::GetDC(NULL);
	m_DisplayFont.CreateFont(-MulDiv(12, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, m_FontName);
	::ReleaseDC(NULL, hDC);

	// 첫번째 문자을 선택 상태로 한다
	m_SelectedCode = 0;
}

// 문자표 화면 출력
void CSymbolChart::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// 폰트를 설정하고 배경을 투명으로 설정한다
	CFont	*pOldFont = dc.SelectObject(&m_DisplayFont);
	int nOldBkMode	= dc.SetBkMode(TRANSPARENT);

	int i, j;
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 16; j++)
		{
			RedrawCode(&dc, i, j);
		}
	}

	dc.SetBkMode(nOldBkMode);
	dc.SelectObject(pOldFont);
}

// 특정 특수 문자를 화면에 출력하는 함수
void CSymbolChart::RedrawCode(CDC *pDC, int nRow, int nCol)
{
	CRect ItemRect;
	int i;

	// 행열에 해당하는 셀의 위치를 구한다
	ItemRect.SetRect(nCol * m_nItemWidth, nRow * m_nItemHeight, (nCol + 1) * m_nItemWidth, (nRow + 1) * m_nItemHeight);
	if(nCol == 15)				ItemRect.right	= m_ClientRect.right;
	if(nRow == 7)				ItemRect.bottom	= m_ClientRect.bottom;

	// 만약 선택된 셀이라면 바탕색상을 회색으로 한다
	if(m_SelectedCode == nRow * 16 + nCol)
		pDC->FillSolidRect(&ItemRect, RGB(200, 200, 200));
	else
		pDC->FillSolidRect(&ItemRect, RGB(255, 255, 255));

	int nX, nY;
	CSize szText;

	if(!m_bIsUnicode)
	{
		// 아스키 문자의 경우 하위 바이트만 설정하여 화면에 출력한다
		m_strAscii[0] = nRow * 16 + nCol;
		m_strAscii[1] = 0;

		// 특수 문자 출력에 필요한 영역을 계산한다
		::GetTextExtentPoint32(pDC->m_hDC, m_strAscii, 1, &szText);

		// 클라이언트 중앙에 나타나도록 좌표를 계산한다
		nX = ItemRect.left + (ItemRect.Width() - szText.cx) / 2;
		nY = ItemRect.top + (ItemRect.Height() - szText.cy) / 2;

		// 특수 문자를 출력한다
		::ExtTextOut(pDC->m_hDC, nX, nY, ETO_OPAQUE, &ItemRect, m_strAscii, 1, NULL);
	}
	else
	{
		// 유니코드 문자를 생성한다
		m_strUni[0] = MAKEWORD(nRow * 16 + nCol + (m_bIsUpper? 0 : 128), m_cHighByte);
		m_strUni[1] = NULL;

		// 특수 문자 출력에 필요한 영역을 계산한다
		::GetTextExtentPoint32W(pDC->m_hDC, m_strUni, 1, &szText);

		// 클라이언트 중앙에 나타나도록 좌표를 계산한다
		nX = ItemRect.left + (ItemRect.Width() - szText.cx) / 2;
		nY = ItemRect.top + (ItemRect.Height() - szText.cy) / 2;

		// 특수 문자를 출력한다
		::ExtTextOutW(pDC->m_hDC, nX, nY, ETO_OPAQUE, &ItemRect, m_strUni, 1, NULL);
	} 

	// 테두리를 그린다
	for(i = 1; i <= 8; i++)
	{
		pDC->MoveTo(0, i * m_nItemHeight);
		pDC->LineTo(m_ClientRect.right, i * m_nItemHeight);
	}
	for(i = 1; i <= 16; i++)
	{
		pDC->MoveTo(i * m_nItemWidth, 0);
		pDC->LineTo(i * m_nItemWidth, m_ClientRect.bottom);
	}
}

// 셀 클릭시 해당 문자를 선택 상태로 만든다
void CSymbolChart::OnLButtonUp(UINT nFlags, CPoint point) 
{
	int x, y;
	CRect ItemRect;

	// 어떤 셀을 클릭했는지 행열을 계산한다
	x = point.x / m_nItemWidth;
	y = point.y / m_nItemHeight;

	// 셀의 영역을 계산한다
	ItemRect.SetRect(x * m_nItemWidth, y * m_nItemHeight, (x + 1) * m_nItemWidth, (y + 1) * m_nItemHeight);
	if(x >= 16)
	{
		x = 15;
		ItemRect.right	= m_ClientRect.right;
	}
	if(y >= 8)
	{
		y = 7;
		ItemRect.bottom	= m_ClientRect.bottom;
	}

	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(&m_DisplayFont);
	int nOldBkMode	= pDC->SetBkMode(TRANSPARENT);

	// 이전 선택 셀의 행열을 계산한다
	int nRow, nCol;
	nCol = m_SelectedCode % 16;
	nRow = m_SelectedCode / 16;

	// 새로운 셀을 선택 상태로 설정한다
	m_SelectedCode = y * 16 + x;

	// 이전 선택 셀을 비선택 상태로 다시 그린다
	RedrawCode(pDC, nRow, nCol);

	// 새로운 셀을 선택 상태로 다시 그린다
	RedrawCode(pDC, y, x);

	pDC->SetBkMode(nOldBkMode);
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// 코드 출력 에디트 컨트롤에 값을 설정한다
	UpdateCodeEdit();

	// 미리보기 컨트롤을 갱신한다
	if(m_pPreview)
	{
		m_pPreview->RefreshCode(m_cHighByte, m_SelectedCode + (m_bIsUpper? 0 : 128));
	}

	CStatic::OnLButtonUp(nFlags, point);
}

// 현재 선택된 특수 문자의 코드를 에디트 박스에 설정하는 함수
void CSymbolChart::UpdateCodeEdit()
{
	if(m_pEdit)
	{
		CString strTemp;

		strTemp.Format("%04X", MAKEWORD(m_SelectedCode + (m_bIsUpper? 0 : 128), m_cHighByte));
		m_pEdit->SetWindowText(strTemp);
	}
}

BOOL CSymbolChart::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

// 셀 더블클릭시 해당 문자를 선택 상태로 하고 다이얼로그를 닫는 함수
void CSymbolChart::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	int x, y;
	CRect ItemRect;

	// 어떤 셀을 클릭했는지 행열을 계산한다
	x = point.x / m_nItemWidth;
	y = point.y / m_nItemHeight;
	
	// 셀의 영역을 계산한다
	ItemRect.SetRect(x * m_nItemWidth, y * m_nItemHeight, (x + 1) * m_nItemWidth, (y + 1) * m_nItemHeight);
	if(x >= 16)
	{
		x = 15;
		ItemRect.right	= m_ClientRect.right;
	}
	if(y >= 8)
	{
		y = 7;
		ItemRect.bottom	= m_ClientRect.bottom;
	}

	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(&m_DisplayFont);
	int nOldBkMode	= pDC->SetBkMode(TRANSPARENT);

	// 이전 선택 셀의 행열을 계산한다
	int nRow, nCol;
	nCol = m_SelectedCode % 16;
	nRow = m_SelectedCode / 16;

	// 새로운 셀을 선택 상태로 설정한다
	m_SelectedCode = y * 16 + x;

	// 이전 선택 셀을 비선택 상태로 다시 그린다
	RedrawCode(pDC, nRow, nCol);

	// 새로운 셀을 선택 상태로 다시 그린다
	RedrawCode(pDC, y, x);

	pDC->SetBkMode(nOldBkMode);
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);
	
	// 코드 출력 에디트 컨트롤에 값을 설정한다
	UpdateCodeEdit();

	// 미리보기 컨트롤을 갱신한다
	if(m_pPreview)
	{
		m_pPreview->RefreshCode(m_cHighByte, y * 16 + x + (m_bIsUpper? 0 : 128));
	}
	
	CStatic::OnLButtonDblClk(nFlags, point);

	// 다이얼로그를 닫는다
	((CSymbolDlg*)GetParent())->OnOK();
}

// 현재 선택된 특수 문자의 하위 바이트를 리턴하는 함수
unsigned char CSymbolChart::GetSelectedLowCode()
{
	return (m_bIsUpper ? 0 : 128) + m_SelectedCode;
}
