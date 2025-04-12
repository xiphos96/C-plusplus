// WarpText.cpp : implementation file
//

#include "stdafx.h"
#include "warptextdemo.h"
#include "WarpText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWarpText

CWarpText::CWarpText()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
	m_bstrText = NULL;
	m_bstrFontName = NULL;

	m_ptWarp = NULL;
	m_bShowGuideLine = TRUE;

	// �ؽ�Ʈ ����� �ܰ��� ������ �ʱ�ȭ �Ѵ�
	m_clrFontColor.SetFromCOLORREF(RGB(179, 200, 200));
	m_clrOutline.SetFromCOLORREF(RGB(0, 0, 0));
}

CWarpText::~CWarpText()
{
	// �ؽ�Ʈ �޸� ����
	if(m_bstrText)		::SysFreeString(m_bstrText);
	// ��Ʈ �̸� �޸� ����
	if(m_bstrFontName)	::SysFreeString(m_bstrFontName);
	// ���� ��ǥ �޸� ����
	if(m_ptWarp)		delete[] m_ptWarp;
}


BEGIN_MESSAGE_MAP(CWarpText, CStatic)
	//{{AFX_MSG_MAP(CWarpText)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWarpText message handlers

// ������ �ؽ�Ʈ�� ��Ʈ�� �����ϴ� �Լ�
void CWarpText::SetText(LPCTSTR pText, LPCTSTR pFontName)
{
	int nLength;

	// �̹� ������ �ؽ�Ʈ �޸𸮸� �����Ѵ�
	if(m_bstrText)		::SysFreeString(m_bstrText);

	// �ؽ�Ʈ�� BSTR���� ��ȯ�Ͽ� �����Ѵ�
	nLength = ::MultiByteToWideChar(CP_ACP, 0, pText, strlen(pText), NULL, NULL);
	m_bstrText = ::SysAllocStringLen(NULL, nLength);
	::MultiByteToWideChar(CP_ACP, 0, pText, strlen(pText), m_bstrText, nLength);

	// �̹� ������ ��Ʈ �̸� �޸𸮸� �����Ѵ�
	if(m_bstrFontName)	::SysFreeString(m_bstrFontName);

	// ��Ʈ �̸��� BSTR���� ��ȯ�Ͽ� �����Ѵ�
	nLength = ::MultiByteToWideChar(CP_ACP, 0, pFontName, strlen(pFontName), NULL, NULL);
	m_bstrFontName = ::SysAllocStringLen(NULL, nLength);
	::MultiByteToWideChar(CP_ACP, 0, pFontName, strlen(pFontName), m_bstrFontName, nLength);

	Point ptOrigin(0, 0);
	FontFamily font(m_bstrFontName);
	StringFormat strf;

	// �ؽ�Ʈ�� ���� ��θ� �����Ѵ�
	m_TextPath.Reset();
	m_TextPath.AddString(m_bstrText, ::wcslen(m_bstrText), &font, FontStyleBold, 1, ptOrigin, &strf);
	// �ؽ�Ʈ ��¿� �ʿ��� ������ ��´�
	m_TextPath.GetBounds(&m_rcText);
}

// �ؽ�Ʈ�� ĥ�ϴ� ���� ���� �Լ�
void CWarpText::SetFontColor(COLORREF clrFont)
{
	m_clrFontColor.SetFromCOLORREF(clrFont);
}

// �ؽ�Ʈ �ܰ����� ĥ�ϴ� ���� ���� �Լ�
void CWarpText::SetOutlineColor(COLORREF clrOutline)
{
	m_clrOutline.SetFromCOLORREF(clrOutline);
}

// ���̵� ���� ��� ���θ� �����ϴ� �Լ�
void CWarpText::ShowGuideLine(BOOL bShow)
{
	m_bShowGuideLine = bShow;
}

// ���� ��ǥ�� �����ϴ� �Լ�
BOOL CWarpText::SetWarpPoint(CPoint *pWarpPoint)
{
	// ���� ������ ��ǥ�� �����Ѵ�
	if(m_ptWarp)		delete[] m_ptWarp;
	m_ptWarp = new PointF[4];

	GetClientRect(&m_rcClient);

	// ���� ��ǥ�� �����Ѵ�
	for(int i = 0; i < 4; i++)
	{
		// ��ǥ�� ��Ʈ�� ���� �������� �����Ѵ�
		if(pWarpPoint[i].x < 0)						pWarpPoint[i].x = 0;
		if(pWarpPoint[i].x > m_rcClient.Width())	pWarpPoint[i].x = m_rcClient.Width();
		if(pWarpPoint[i].y < 0)						pWarpPoint[i].y = 0;
		if(pWarpPoint[i].y > m_rcClient.Height())	pWarpPoint[i].y = m_rcClient.Height();

		m_ptWarp[i].X = (REAL)pWarpPoint[i].x;
		m_ptWarp[i].Y = (REAL)pWarpPoint[i].y;
	}

	return TRUE;
}

void CWarpText::OnPaint() 
{
	// ���� ��ǥ�� �����Ǿ� �ִٸ�
	if(m_ptWarp)
	{
		CPaintDC dc(this); // device context for painting

		// Graphics ��ü�� �����Ѵ�
		Graphics graphics(dc.GetSafeHdc());
		// ���� ǰ���� ��µǵ��� �����Ѵ�
		graphics.SetSmoothingMode(SmoothingModeHighQuality);
		// �ؽ�Ʈ ��� ǰ���� ��Ƽ�ٸ�������� �����Ѵ�
		graphics.SetTextRenderingHint(TextRenderingHintAntiAlias);

		// ��� ������ ����ϰ� ���ο� �׵θ� ��¿� ��ü�� �����Ѵ�
		Rect rcClient(0, 0, m_rcClient.Width() - 1, m_rcClient.Height() - 1);
		SolidBrush FillBrush(Color::White);
		Pen EdgePen(Color::Black);

		// ���θ� ��� �귯���� ĥ�Ѵ�
		graphics.FillRectangle(&FillBrush, rcClient);
		// �׵θ��� ������ ������ �׸���
		graphics.DrawRectangle(&EdgePen, rcClient);

		// ���̵� ������ ����Ѵٸ�
		if(m_bShowGuideLine)
		{
			// ���̵� ���ο� ���� �����Ѵ�
			Pen GuidePen(Color::Lime);

			// ���� ���̵� ������ ����Ѵ�
			graphics.DrawLine(&GuidePen, m_ptWarp[0], m_ptWarp[1]);
			// �Ʒ��� ���̵� ������ ����Ѵ�
			graphics.DrawLine(&GuidePen, m_ptWarp[2], m_ptWarp[3]);
		}

		// �ؽ�Ʈ ��θ� �����Ͽ� �� ��θ� �����
		GraphicsPath * pPath = m_TextPath.Clone();

		// ����� ��θ� �����Ѵ�
		pPath->Warp(m_ptWarp, 4, m_rcText, NULL, WarpModePerspective, FlatnessDefault);

		// ���ε� �ؽ�Ʈ ��� ��¿� �귯���� ���� �����Ѵ�
		SolidBrush TextBrush(m_clrFontColor);
		Pen OutlinePen(m_clrOutline);

		// ���ε� �ؽ�Ʈ ��θ� ĥ�Ѵ�
		graphics.FillPath(&TextBrush, pPath);
		// ���ε� �ؽ�Ʈ ����� �ܰ����� �׸���
		graphics.DrawPath(&OutlinePen, pPath);

		// ����� ��θ� �����Ѵ�
		delete pPath;
	}
}
