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
	// 멤버 변수들을 초기화한다
	m_bstrText = NULL;
	m_bstrFontName = NULL;

	m_ptWarp = NULL;
	m_bShowGuideLine = TRUE;

	// 텍스트 색상과 외곽선 색상을 초기화 한다
	m_clrFontColor.SetFromCOLORREF(RGB(179, 200, 200));
	m_clrOutline.SetFromCOLORREF(RGB(0, 0, 0));
}

CWarpText::~CWarpText()
{
	// 텍스트 메모리 해제
	if(m_bstrText)		::SysFreeString(m_bstrText);
	// 폰트 이름 메모리 해제
	if(m_bstrFontName)	::SysFreeString(m_bstrFontName);
	// 워핑 좌표 메모리 해제
	if(m_ptWarp)		delete[] m_ptWarp;
}


BEGIN_MESSAGE_MAP(CWarpText, CStatic)
	//{{AFX_MSG_MAP(CWarpText)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWarpText message handlers

// 워핑할 텍스트와 폰트를 설정하는 함수
void CWarpText::SetText(LPCTSTR pText, LPCTSTR pFontName)
{
	int nLength;

	// 이미 설정된 텍스트 메모리를 해제한다
	if(m_bstrText)		::SysFreeString(m_bstrText);

	// 텍스트를 BSTR으로 변환하여 저장한다
	nLength = ::MultiByteToWideChar(CP_ACP, 0, pText, strlen(pText), NULL, NULL);
	m_bstrText = ::SysAllocStringLen(NULL, nLength);
	::MultiByteToWideChar(CP_ACP, 0, pText, strlen(pText), m_bstrText, nLength);

	// 이미 설정된 폰트 이름 메모리를 해제한다
	if(m_bstrFontName)	::SysFreeString(m_bstrFontName);

	// 폰트 이름을 BSTR으로 변환하여 저장한다
	nLength = ::MultiByteToWideChar(CP_ACP, 0, pFontName, strlen(pFontName), NULL, NULL);
	m_bstrFontName = ::SysAllocStringLen(NULL, nLength);
	::MultiByteToWideChar(CP_ACP, 0, pFontName, strlen(pFontName), m_bstrFontName, nLength);

	Point ptOrigin(0, 0);
	FontFamily font(m_bstrFontName);
	StringFormat strf;

	// 텍스트에 대한 경로를 생성한다
	m_TextPath.Reset();
	m_TextPath.AddString(m_bstrText, ::wcslen(m_bstrText), &font, FontStyleBold, 1, ptOrigin, &strf);
	// 텍스트 출력에 필요한 영역을 얻는다
	m_TextPath.GetBounds(&m_rcText);
}

// 텍스트를 칠하는 색상 설정 함수
void CWarpText::SetFontColor(COLORREF clrFont)
{
	m_clrFontColor.SetFromCOLORREF(clrFont);
}

// 텍스트 외곽선을 칠하는 색상 설정 함수
void CWarpText::SetOutlineColor(COLORREF clrOutline)
{
	m_clrOutline.SetFromCOLORREF(clrOutline);
}

// 가이드 라인 출력 여부를 설정하는 함수
void CWarpText::ShowGuideLine(BOOL bShow)
{
	m_bShowGuideLine = bShow;
}

// 워핑 좌표를 설정하는 함수
BOOL CWarpText::SetWarpPoint(CPoint *pWarpPoint)
{
	// 이전 설정된 좌표를 제거한다
	if(m_ptWarp)		delete[] m_ptWarp;
	m_ptWarp = new PointF[4];

	GetClientRect(&m_rcClient);

	// 워핑 좌표를 저장한다
	for(int i = 0; i < 4; i++)
	{
		// 좌표를 컨트롤 영역 안쪽으로 보정한다
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
	// 워핑 좌표가 설정되어 있다면
	if(m_ptWarp)
	{
		CPaintDC dc(this); // device context for painting

		// Graphics 객체를 생성한다
		Graphics graphics(dc.GetSafeHdc());
		// 높은 품질로 출력되도록 설정한다
		graphics.SetSmoothingMode(SmoothingModeHighQuality);
		// 텍스트 출력 품질을 앤티앨리어싱으로 설정한다
		graphics.SetTextRenderingHint(TextRenderingHintAntiAlias);

		// 출력 영역을 계산하고 내부와 테두리 출력용 객체를 생성한다
		Rect rcClient(0, 0, m_rcClient.Width() - 1, m_rcClient.Height() - 1);
		SolidBrush FillBrush(Color::White);
		Pen EdgePen(Color::Black);

		// 내부를 흰색 브러쉬로 칠한다
		graphics.FillRectangle(&FillBrush, rcClient);
		// 테두리를 검은색 펜으로 그린다
		graphics.DrawRectangle(&EdgePen, rcClient);

		// 가이드 라인을 출력한다면
		if(m_bShowGuideLine)
		{
			// 가이드 라인용 펜을 생성한다
			Pen GuidePen(Color::Lime);

			// 위쪽 가이드 라인을 출력한다
			graphics.DrawLine(&GuidePen, m_ptWarp[0], m_ptWarp[1]);
			// 아래쪽 가이드 라인을 출력한다
			graphics.DrawLine(&GuidePen, m_ptWarp[2], m_ptWarp[3]);
		}

		// 텍스트 경로를 복사하여 새 경로를 만든다
		GraphicsPath * pPath = m_TextPath.Clone();

		// 복사된 경로를 워핑한다
		pPath->Warp(m_ptWarp, 4, m_rcText, NULL, WarpModePerspective, FlatnessDefault);

		// 워핑된 텍스트 경로 출력용 브러쉬와 펜을 생성한다
		SolidBrush TextBrush(m_clrFontColor);
		Pen OutlinePen(m_clrOutline);

		// 워핑된 텍스트 경로를 칠한다
		graphics.FillPath(&TextBrush, pPath);
		// 워핑된 텍스트 경로의 외곽선을 그린다
		graphics.DrawPath(&OutlinePen, pPath);

		// 복사된 경로를 제거한다
		delete pPath;
	}
}
