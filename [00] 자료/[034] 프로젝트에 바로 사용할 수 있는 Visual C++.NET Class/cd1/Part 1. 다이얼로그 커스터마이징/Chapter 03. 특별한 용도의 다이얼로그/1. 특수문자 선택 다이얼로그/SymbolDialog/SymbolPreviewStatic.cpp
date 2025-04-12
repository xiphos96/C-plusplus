// SymbolPreviewStatic.cpp : implementation file
//

#include "stdafx.h"
#include "SymbolPreviewStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSymbolPreviewStatic

CSymbolPreviewStatic::CSymbolPreviewStatic()
{
	// 초기값을 설정한다
	m_bIsUnicode		= FALSE;
	m_FontName			= "굴림";

	m_cHighByte			= 0x00;
	m_cLowByte			= 0;
}

CSymbolPreviewStatic::~CSymbolPreviewStatic()
{
	// 폰트를 소멸시킨다
	m_DisplayFont.DeleteObject();
}


BEGIN_MESSAGE_MAP(CSymbolPreviewStatic, CStatic)
	//{{AFX_MSG_MAP(CSymbolPreviewStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSymbolPreviewStatic message handlers

void CSymbolPreviewStatic::InitPreview()
{
	// 클라이언트 영역을 구한다
	GetClientRect(&m_ClientRect);

	// 설정된 폰트 이름의 폰트를 생성한다
	HDC hDC = ::GetDC(NULL);
	m_DisplayFont.CreateFont(-MulDiv(30, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, m_FontName);
	::ReleaseDC(NULL, hDC);
}

// 새로운 특수 문자를 설정하고 화면을 다시 그린다
void CSymbolPreviewStatic::RefreshCode(unsigned char cHighByte, unsigned char cLowByte)
{
	m_cHighByte		= cHighByte;
	m_cLowByte		= cLowByte;

	Invalidate();
}

// 배경을 하얀색으로 지우기
BOOL CSymbolPreviewStatic::OnEraseBkgnd(CDC* pDC) 
{
	pDC->FillSolidRect(m_ClientRect, RGB(255, 255, 255));

	return TRUE;
}

void CSymbolPreviewStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// 널문자가 아니라면
	if(m_cHighByte > 0 || m_cLowByte > 0)
	{
		// 폰트를 설정하고 배경을 투명으로 설정한다
		CFont	*pOldFont	= dc.SelectObject(&m_DisplayFont);
		int		nOldBkMode	= dc.SetBkMode(TRANSPARENT);

		int nX, nY;
		CSize szText;

		if(!m_bIsUnicode)
		{
			// 아스키 문자의 경우 하위 바이트만 설정하여 화면에 출력한다
			m_strAscii[0] = m_cLowByte;
			m_strAscii[1] = 0;

			// 특수 문자 출력에 필요한 영역을 계산한다
			::GetTextExtentPoint32(dc.m_hDC, m_strAscii, 1, &szText);

			// 클라이언트 중앙에 나타나도록 좌표를 계산한다
			nX = m_ClientRect.left + (m_ClientRect.Width() - szText.cx) / 2;
			nY = m_ClientRect.top + (m_ClientRect.Height() - szText.cy) / 2;

			// 특수 문자를 출력한다
			::ExtTextOut(dc.m_hDC, nX, nY, ETO_OPAQUE, &m_ClientRect, m_strAscii, 1, NULL);
		}
		else
		{
			// 유니코드 문자를 생성한다
			m_strUni[0] = MAKEWORD(m_cLowByte, m_cHighByte);
			m_strUni[1] = NULL;

			// 특수 문자 출력에 필요한 영역을 계산한다
			::GetTextExtentPoint32W(dc.m_hDC, m_strUni, 1, &szText);

			// 클라이언트 중앙에 나타나도록 좌표를 계산한다
			nX = m_ClientRect.left + (m_ClientRect.Width() - szText.cx) / 2;
			nY = m_ClientRect.top + (m_ClientRect.Height() - szText.cy) / 2;

			// 특수 문자를 출력한다
			::ExtTextOutW(dc.m_hDC, nX, nY, ETO_OPAQUE, &m_ClientRect, m_strUni, 1, NULL);
		}

		dc.SetBkMode(nOldBkMode);
		dc.SelectObject(pOldFont);
	}
}
