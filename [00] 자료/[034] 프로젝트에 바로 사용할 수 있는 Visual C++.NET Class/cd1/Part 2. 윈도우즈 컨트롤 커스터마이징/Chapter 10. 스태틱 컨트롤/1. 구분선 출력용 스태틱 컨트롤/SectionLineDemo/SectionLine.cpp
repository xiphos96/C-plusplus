// SectionLine.cpp : implementation file
//

#include "stdafx.h"
#include "sectionlinedemo.h"
#include "SectionLine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSectionLine

// ���ΰ� �ؽ�Ʈ ������ ����
#define CONST_ITEM_GAP		6

CSectionLine::CSectionLine()
{
	// ��� �������� �ʱ�ȭ �Ѵ�
	m_bHorz			= TRUE;

	m_clrText		= ::GetSysColor(COLOR_BTNTEXT);
	m_clrBkgnd		= ::GetSysColor(COLOR_BTNFACE);
	m_clrHighlight	= ::GetSysColor(COLOR_3DHIGHLIGHT);
	m_clrShadow		= ::GetSysColor(COLOR_3DSHADOW);
}

CSectionLine::~CSectionLine()
{
	m_VertFont.DeleteObject();
}


BEGIN_MESSAGE_MAP(CSectionLine, CStatic)
	//{{AFX_MSG_MAP(CSectionLine)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_ENABLE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SETTEXT, OnSetText)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSectionLine message handlers

void CSectionLine::PreSubclassWindow() 
{
	// �׵θ� �Ӽ��� ���ش�
	ModifyStyle(WS_BORDER, 0);
	ModifyStyleEx(WS_EX_CLIENTEDGE | WS_EX_STATICEDGE, 0);

	// ���� ����ƽ ��Ʈ���� ��Ʈ�� ��´�
	LOGFONT LogFont;
	CFont *pFont = GetFont();
	// ��Ʈ�� �α� ��Ʈ ������ ��´�
	pFont->GetLogFont(&LogFont);
	// ��Ʈ�� 90�� ȸ�� ��Ų��
	LogFont.lfEscapement = 900;
	// ���� �ؽ�Ʈ ��¿� ��Ʈ�� �����Ѵ�
	m_VertFont.CreateFontIndirect(&LogFont);

	// ����ƽ�� �ؽ�Ʈ�� ��´�
	CString strText;
	GetWindowText(strText);

	// �ؽ�Ʈ�� ���� �ؽ�Ʈ ������ ���м� ������ ����Ѵ�
	RecalcSectionLine(strText);

	CStatic::PreSubclassWindow();
}

void CSectionLine::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// ����ƽ ��Ʈ�� ������ �������� ĥ�Ѵ�
	CRect rcClient;
	GetClientRect(&rcClient);
	dc.FillSolidRect(rcClient, m_clrBkgnd);

	// ����ƽ�� �ؽ�Ʈ�� ��´�
	CString strText;
	GetWindowText(strText);

	// �ؽ�Ʈ ����� �����ϰ� �����Ѵ�
	dc.SetBkMode(TRANSPARENT);

	CFont *pOldFont;

	// ����/���� ��忡 ���� ��Ʈ�� �����Ѵ�
	if(m_bHorz)		pOldFont = dc.SelectObject(GetFont());
	else			pOldFont = dc.SelectObject(&m_VertFont);

	// �ؽ�Ʈ ������ �����Ѵ�
	COLORREF clrOldText = dc.SetTextColor(m_clrText);

	// ���� Ȱ��ȭ���� ���� ���¶��
	if(!IsWindowEnabled())
	{
		// ���� �������� �ؽ�Ʈ ������ �����Ѵ�
		dc.SetTextColor(m_clrHighlight);
		// ����/���� ��忡 ���� �ٸ� �Լ��� �ؽ�Ʈ�� ����Ѵ�
		if(m_bHorz)
			dc.DrawText(strText, m_rcText + CPoint(1, 1), DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
		else
			dc.TextOut(m_rcText.left, m_rcText.bottom, strText);
		// ��ο� ������ �ؽ�Ʈ �������� �����Ѵ�
		dc.SetTextColor(m_clrShadow);
	}
	// ����/���� ��忡 ���� �ٸ� �Լ��� �ؽ�Ʈ�� ����Ѵ�
	if(m_bHorz)
		dc.DrawText(strText, m_rcText, DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
	else
		dc.TextOut(m_rcText.left, m_rcText.bottom, strText);

	// ���� ���� ���м��� ������ �����Ǿ� �ִٸ�
	if(!m_rcLineLeft.IsRectEmpty())
		// ���� ���м��� ����Ѵ�
		dc.Draw3dRect(m_rcLineLeft, m_clrShadow, m_clrHighlight);
	// ���� ������ ���м��� ������ �����Ǿ� �ִٸ�
	if(!m_rcLineRight.IsRectEmpty())
		// ������ ���м��� ����Ѵ�
		dc.Draw3dRect(m_rcLineRight, m_clrShadow, m_clrHighlight);

	// ���� �ؽ�Ʈ ����� ��Ʈ�� ��ȯ�Ѵ�
	dc.SetTextColor(clrOldText);
	dc.SelectObject(pOldFont);
}

BOOL CSectionLine::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

void CSectionLine::RecalcSectionLine(LPCTSTR pText)
{
	// Ŭ���̾�Ʈ ������ ��´�
	CRect rcClient, rcText;
	GetClientRect(&rcClient);

	// Ŭ���̾�Ʈ ������ ���� ���̺��� ũ�ٸ� ���� ���� �����Ѵ�
	if(rcClient.Width() > rcClient.Height())	m_bHorz = TRUE;
	else										m_bHorz = FALSE;

	// DC�� ��´�
	CDC *pDC = GetDC();
	CFont *pOldFont;
	
	// ����/���� ��忡 ���� ��Ʈ�� �����Ѵ�
	if(m_bHorz)		pOldFont = pDC->SelectObject(GetFont());
	else			pOldFont = pDC->SelectObject(&m_VertFont);

	// �ؽ�Ʈ ��¿� �ʿ��� ������ ����Ѵ�
	rcText.SetRectEmpty();
	pDC->DrawText(pText, -1, &rcText, DT_LEFT | DT_CALCRECT);

	// ���� ��Ʈ�� �ǵ�����
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// �⺻ ������ Ŭ���̾�Ʈ �������� �����Ѵ�
	m_rcText = m_rcLineLeft = m_rcLineRight= rcClient;

	// ���� �����
	if(m_bHorz)
	{
		// ���м��� ��, �Ʒ� ��ǥ�� ����Ѵ�
		m_rcLineLeft.top	= m_rcLineRight.top		= rcClient.Height() / 2 - 1;
		m_rcLineLeft.bottom	= m_rcLineRight.bottom	= m_rcLineRight.top + 2;
	}
	else
	{
		// �ؽ�Ʈ�� �¿��� ��ǥ�� ����Ѵ�
		m_rcText.left	= (rcClient.Width() - rcText.Height()) / 2;
		m_rcText.right	= m_rcText.left + rcText.Height();
		// ���м��� �¿��� ��ǥ�� ����Ѵ�
		m_rcLineLeft.left	= m_rcLineRight.left	= rcClient.Width() / 2 - 1;
		m_rcLineLeft.right	= m_rcLineRight.right	= m_rcLineRight.left + 2;
	}

	// ����ƽ ��Ʈ���� ���� �Ӽ��� ��´�
	DWORD	nAlign = GetStyle() & SS_TYPEMASK;

	// ���� �Ӽ��� ���� ��ǥ�� ����Ѵ�
	switch(nAlign)
	{
	case SS_LEFT :
		// ���� �����̶��
		if(m_bHorz)
		{
			m_rcText.right			= rcText.right;
			m_rcLineLeft.SetRectEmpty();
			m_rcLineRight.left		= rcText.right + CONST_ITEM_GAP;
		}
		else
		{
			m_rcText.top			= rcClient.Height() - rcText.Width();
			m_rcLineLeft.SetRectEmpty();
			m_rcLineRight.bottom	= m_rcText.top - CONST_ITEM_GAP;
		}
		break;
	case SS_CENTER :
		// ��� �����̶��
		if(m_bHorz)
		{
			m_rcText.left			= (rcClient.Width() - rcText.Width()) / 2;
			m_rcText.right			= m_rcText.left + rcText.Width();
			m_rcLineLeft.right		= m_rcText.left - CONST_ITEM_GAP;
			m_rcLineRight.left		= m_rcText.right + CONST_ITEM_GAP;
		}
		else
		{
			m_rcText.top			= (rcClient.Height() - rcText.Width()) / 2;
			m_rcText.bottom			= m_rcText.top + rcText.Width();
			m_rcLineLeft.top		= m_rcText.bottom + CONST_ITEM_GAP;
			m_rcLineRight.bottom	= m_rcText.top - CONST_ITEM_GAP; 
		}
		break;
	case SS_RIGHT :
		// ������ �����̶��
		if(m_bHorz)
		{
			m_rcText.left			= rcClient.Width() - rcText.Width();
			m_rcLineLeft.right		= m_rcText.left - CONST_ITEM_GAP;
			m_rcLineRight.SetRectEmpty();
		}
		else
		{
			m_rcText.bottom			= rcText.right;
			m_rcLineLeft.top		= m_rcText.bottom + CONST_ITEM_GAP;
			m_rcLineRight.SetRectEmpty();
		}
		break;
	}
}

LONG CSectionLine::OnSetText(WPARAM wParam, LPARAM lParam)
{
	// �⺻ �ؽ�Ʈ ������ �����Ѵ�
	Default();

	// ���ο� �ؽ�Ʈ�� ���� ������ ����Ѵ�
	RecalcSectionLine(LPCTSTR(lParam));
	// ȭ���� �ٽ� �׸���
	Invalidate();

	return TRUE;
}

void CSectionLine::OnEnable(BOOL bEnable) 
{
	CStatic::OnEnable(bEnable);

	// ȭ���� �ٽ� �׸���
	Invalidate();
}

void CSectionLine::OnSize(UINT nType, int cx, int cy) 
{
	CStatic::OnSize(nType, cx, cy);
	
	// ����ƽ ��Ʈ���� �ؽ�Ʈ�� ��´�
	CString strText;
	GetWindowText(strText);

	// ���ο� �ؽ�Ʈ�� ���� ������ ����Ѵ�
	RecalcSectionLine(strText);
	// ȭ���� �ٽ� �׸���
	Invalidate();
}
