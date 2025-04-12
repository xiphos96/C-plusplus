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
	// ���� �ʱ�ȭ
	m_bIsUnicode		= FALSE;
	m_bIsUpper			= TRUE;
	m_cHighByte			= 0x00;

	m_SelectedCode		= 0;

	m_FontName			= "����";
	m_pEdit				= NULL;
	m_pPreview			= NULL;
}

CSymbolChart::~CSymbolChart()
{
	// ��Ʈ�� �Ҹ��Ų��
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
	// Ŭ���̾�Ʈ ������ ũ�⸦ ���ϰ� �� ���� ���� ���̸� ����Ѵ�
	GetClientRect(&m_ClientRect);
	m_nItemWidth	= m_ClientRect.Width() / 16;
	m_nItemHeight	= m_ClientRect.Height() / 8;

	// ���� �׸��� ���� ���� ������ ���Ѵ�
	int nHorzInterval = m_ClientRect.Width() - (16 * m_nItemWidth);
	CRect rcClient;

	// ����ǥ ��Ʈ���� ��ġ�� ���Ѵ�
	GetWindowRect(&rcClient);
	GetParent()->ScreenToClient(&rcClient);

	// ���� ������ ����Ͽ� ����ǥ ��ġ�� �������Ѵ�
	rcClient.left	+= (nHorzInterval / 2);
	rcClient.right	= rcClient.left + (m_nItemWidth * 16) + 4;
	rcClient.bottom	= rcClient.top + (m_nItemHeight * 8) + 4;

	MoveWindow(rcClient);

	// Ŭ���̾�Ʈ ������ �������Ѵ�
	m_ClientRect.SetRect(0, 0, m_nItemWidth * 16 - 1, m_nItemHeight * 8 - 1);

	// Ư�� ���� ��¿� ����� ��Ʈ�� �����Ѵ�
	HDC hDC = ::GetDC(NULL);
	m_DisplayFont.CreateFont(-MulDiv(12, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, m_FontName);
	::ReleaseDC(NULL, hDC);

	// ù��° ������ ���� ���·� �Ѵ�
	m_SelectedCode = 0;
}

// ����ǥ ȭ�� ���
void CSymbolChart::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// ��Ʈ�� �����ϰ� ����� �������� �����Ѵ�
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

// Ư�� Ư�� ���ڸ� ȭ�鿡 ����ϴ� �Լ�
void CSymbolChart::RedrawCode(CDC *pDC, int nRow, int nCol)
{
	CRect ItemRect;
	int i;

	// �࿭�� �ش��ϴ� ���� ��ġ�� ���Ѵ�
	ItemRect.SetRect(nCol * m_nItemWidth, nRow * m_nItemHeight, (nCol + 1) * m_nItemWidth, (nRow + 1) * m_nItemHeight);
	if(nCol == 15)				ItemRect.right	= m_ClientRect.right;
	if(nRow == 7)				ItemRect.bottom	= m_ClientRect.bottom;

	// ���� ���õ� ���̶�� ���������� ȸ������ �Ѵ�
	if(m_SelectedCode == nRow * 16 + nCol)
		pDC->FillSolidRect(&ItemRect, RGB(200, 200, 200));
	else
		pDC->FillSolidRect(&ItemRect, RGB(255, 255, 255));

	int nX, nY;
	CSize szText;

	if(!m_bIsUnicode)
	{
		// �ƽ�Ű ������ ��� ���� ����Ʈ�� �����Ͽ� ȭ�鿡 ����Ѵ�
		m_strAscii[0] = nRow * 16 + nCol;
		m_strAscii[1] = 0;

		// Ư�� ���� ��¿� �ʿ��� ������ ����Ѵ�
		::GetTextExtentPoint32(pDC->m_hDC, m_strAscii, 1, &szText);

		// Ŭ���̾�Ʈ �߾ӿ� ��Ÿ������ ��ǥ�� ����Ѵ�
		nX = ItemRect.left + (ItemRect.Width() - szText.cx) / 2;
		nY = ItemRect.top + (ItemRect.Height() - szText.cy) / 2;

		// Ư�� ���ڸ� ����Ѵ�
		::ExtTextOut(pDC->m_hDC, nX, nY, ETO_OPAQUE, &ItemRect, m_strAscii, 1, NULL);
	}
	else
	{
		// �����ڵ� ���ڸ� �����Ѵ�
		m_strUni[0] = MAKEWORD(nRow * 16 + nCol + (m_bIsUpper? 0 : 128), m_cHighByte);
		m_strUni[1] = NULL;

		// Ư�� ���� ��¿� �ʿ��� ������ ����Ѵ�
		::GetTextExtentPoint32W(pDC->m_hDC, m_strUni, 1, &szText);

		// Ŭ���̾�Ʈ �߾ӿ� ��Ÿ������ ��ǥ�� ����Ѵ�
		nX = ItemRect.left + (ItemRect.Width() - szText.cx) / 2;
		nY = ItemRect.top + (ItemRect.Height() - szText.cy) / 2;

		// Ư�� ���ڸ� ����Ѵ�
		::ExtTextOutW(pDC->m_hDC, nX, nY, ETO_OPAQUE, &ItemRect, m_strUni, 1, NULL);
	} 

	// �׵θ��� �׸���
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

// �� Ŭ���� �ش� ���ڸ� ���� ���·� �����
void CSymbolChart::OnLButtonUp(UINT nFlags, CPoint point) 
{
	int x, y;
	CRect ItemRect;

	// � ���� Ŭ���ߴ��� �࿭�� ����Ѵ�
	x = point.x / m_nItemWidth;
	y = point.y / m_nItemHeight;

	// ���� ������ ����Ѵ�
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

	// ���� ���� ���� �࿭�� ����Ѵ�
	int nRow, nCol;
	nCol = m_SelectedCode % 16;
	nRow = m_SelectedCode / 16;

	// ���ο� ���� ���� ���·� �����Ѵ�
	m_SelectedCode = y * 16 + x;

	// ���� ���� ���� ���� ���·� �ٽ� �׸���
	RedrawCode(pDC, nRow, nCol);

	// ���ο� ���� ���� ���·� �ٽ� �׸���
	RedrawCode(pDC, y, x);

	pDC->SetBkMode(nOldBkMode);
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// �ڵ� ��� ����Ʈ ��Ʈ�ѿ� ���� �����Ѵ�
	UpdateCodeEdit();

	// �̸����� ��Ʈ���� �����Ѵ�
	if(m_pPreview)
	{
		m_pPreview->RefreshCode(m_cHighByte, m_SelectedCode + (m_bIsUpper? 0 : 128));
	}

	CStatic::OnLButtonUp(nFlags, point);
}

// ���� ���õ� Ư�� ������ �ڵ带 ����Ʈ �ڽ��� �����ϴ� �Լ�
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

// �� ����Ŭ���� �ش� ���ڸ� ���� ���·� �ϰ� ���̾�α׸� �ݴ� �Լ�
void CSymbolChart::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	int x, y;
	CRect ItemRect;

	// � ���� Ŭ���ߴ��� �࿭�� ����Ѵ�
	x = point.x / m_nItemWidth;
	y = point.y / m_nItemHeight;
	
	// ���� ������ ����Ѵ�
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

	// ���� ���� ���� �࿭�� ����Ѵ�
	int nRow, nCol;
	nCol = m_SelectedCode % 16;
	nRow = m_SelectedCode / 16;

	// ���ο� ���� ���� ���·� �����Ѵ�
	m_SelectedCode = y * 16 + x;

	// ���� ���� ���� ���� ���·� �ٽ� �׸���
	RedrawCode(pDC, nRow, nCol);

	// ���ο� ���� ���� ���·� �ٽ� �׸���
	RedrawCode(pDC, y, x);

	pDC->SetBkMode(nOldBkMode);
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);
	
	// �ڵ� ��� ����Ʈ ��Ʈ�ѿ� ���� �����Ѵ�
	UpdateCodeEdit();

	// �̸����� ��Ʈ���� �����Ѵ�
	if(m_pPreview)
	{
		m_pPreview->RefreshCode(m_cHighByte, y * 16 + x + (m_bIsUpper? 0 : 128));
	}
	
	CStatic::OnLButtonDblClk(nFlags, point);

	// ���̾�α׸� �ݴ´�
	((CSymbolDlg*)GetParent())->OnOK();
}

// ���� ���õ� Ư�� ������ ���� ����Ʈ�� �����ϴ� �Լ�
unsigned char CSymbolChart::GetSelectedLowCode()
{
	return (m_bIsUpper ? 0 : 128) + m_SelectedCode;
}
