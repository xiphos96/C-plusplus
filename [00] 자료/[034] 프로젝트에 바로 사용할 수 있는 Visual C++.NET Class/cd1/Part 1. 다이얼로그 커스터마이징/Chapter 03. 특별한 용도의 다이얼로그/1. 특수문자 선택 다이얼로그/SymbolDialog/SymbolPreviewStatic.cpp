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
	// �ʱⰪ�� �����Ѵ�
	m_bIsUnicode		= FALSE;
	m_FontName			= "����";

	m_cHighByte			= 0x00;
	m_cLowByte			= 0;
}

CSymbolPreviewStatic::~CSymbolPreviewStatic()
{
	// ��Ʈ�� �Ҹ��Ų��
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
	// Ŭ���̾�Ʈ ������ ���Ѵ�
	GetClientRect(&m_ClientRect);

	// ������ ��Ʈ �̸��� ��Ʈ�� �����Ѵ�
	HDC hDC = ::GetDC(NULL);
	m_DisplayFont.CreateFont(-MulDiv(30, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, m_FontName);
	::ReleaseDC(NULL, hDC);
}

// ���ο� Ư�� ���ڸ� �����ϰ� ȭ���� �ٽ� �׸���
void CSymbolPreviewStatic::RefreshCode(unsigned char cHighByte, unsigned char cLowByte)
{
	m_cHighByte		= cHighByte;
	m_cLowByte		= cLowByte;

	Invalidate();
}

// ����� �Ͼ������ �����
BOOL CSymbolPreviewStatic::OnEraseBkgnd(CDC* pDC) 
{
	pDC->FillSolidRect(m_ClientRect, RGB(255, 255, 255));

	return TRUE;
}

void CSymbolPreviewStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// �ι��ڰ� �ƴ϶��
	if(m_cHighByte > 0 || m_cLowByte > 0)
	{
		// ��Ʈ�� �����ϰ� ����� �������� �����Ѵ�
		CFont	*pOldFont	= dc.SelectObject(&m_DisplayFont);
		int		nOldBkMode	= dc.SetBkMode(TRANSPARENT);

		int nX, nY;
		CSize szText;

		if(!m_bIsUnicode)
		{
			// �ƽ�Ű ������ ��� ���� ����Ʈ�� �����Ͽ� ȭ�鿡 ����Ѵ�
			m_strAscii[0] = m_cLowByte;
			m_strAscii[1] = 0;

			// Ư�� ���� ��¿� �ʿ��� ������ ����Ѵ�
			::GetTextExtentPoint32(dc.m_hDC, m_strAscii, 1, &szText);

			// Ŭ���̾�Ʈ �߾ӿ� ��Ÿ������ ��ǥ�� ����Ѵ�
			nX = m_ClientRect.left + (m_ClientRect.Width() - szText.cx) / 2;
			nY = m_ClientRect.top + (m_ClientRect.Height() - szText.cy) / 2;

			// Ư�� ���ڸ� ����Ѵ�
			::ExtTextOut(dc.m_hDC, nX, nY, ETO_OPAQUE, &m_ClientRect, m_strAscii, 1, NULL);
		}
		else
		{
			// �����ڵ� ���ڸ� �����Ѵ�
			m_strUni[0] = MAKEWORD(m_cLowByte, m_cHighByte);
			m_strUni[1] = NULL;

			// Ư�� ���� ��¿� �ʿ��� ������ ����Ѵ�
			::GetTextExtentPoint32W(dc.m_hDC, m_strUni, 1, &szText);

			// Ŭ���̾�Ʈ �߾ӿ� ��Ÿ������ ��ǥ�� ����Ѵ�
			nX = m_ClientRect.left + (m_ClientRect.Width() - szText.cx) / 2;
			nY = m_ClientRect.top + (m_ClientRect.Height() - szText.cy) / 2;

			// Ư�� ���ڸ� ����Ѵ�
			::ExtTextOutW(dc.m_hDC, nX, nY, ETO_OPAQUE, &m_ClientRect, m_strUni, 1, NULL);
		}

		dc.SetBkMode(nOldBkMode);
		dc.SelectObject(pOldFont);
	}
}
