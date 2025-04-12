// CG: This file was added by the Splash Screen component.
// FadeInSplashWnd.cpp : implementation file
//

#include "stdafx.h"  // e. g. stdafx.h
#include "resource.h"  // e.g. resource.h

#include "FadeInSplashWnd.h"  // e.g. splash.h

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
//   Splash Screen class

BOOL CFadeInSplashWnd::c_bShowSplashWnd				= TRUE;
CFadeInSplashWnd* CFadeInSplashWnd::c_pSplashWnd	= NULL;

CFadeInSplashWnd::CFadeInSplashWnd()
{
	// �ʱ� �������� 1�� �����Ѵ�
	m_nOpaque = 0;
}

CFadeInSplashWnd::~CFadeInSplashWnd()
{
	// Clear the static window pointer.
	// ���÷��� ������ ���� ������ �ʱ�ȭ�Ѵ�
	ASSERT(c_pSplashWnd == this);
	c_pSplashWnd = NULL;
}

BEGIN_MESSAGE_MAP(CFadeInSplashWnd, CWnd)
	//{{AFX_MSG_MAP(CFadeInSplashWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// ���÷��� ��� ���� ���θ� �����ϴ� �Լ�
void CFadeInSplashWnd::EnableSplashScreen(BOOL bEnable)
{
	// ���÷��� ��� ���� ���θ� �����Ѵ�
	c_bShowSplashWnd = bEnable;
}

// ��Ʈ�� ���ҽ��� �̹����� ���÷��� �����츦 ����ϴ� �Լ�
void CFadeInSplashWnd::ShowSplashScreen(CWnd* pParentWnd, UINT nBitmapID)
{
	// ���÷��� ����� �Ұ����ϰų� �̹� ��� ���� ���÷��ð� �ִٸ� �����Ѵ�
	if (!c_bShowSplashWnd || c_pSplashWnd != NULL)
		return;

	// ���ο� ���÷��� ������ ��ü�� �����
	c_pSplashWnd = new CFadeInSplashWnd;
	// ���÷��� �����츦 �����Ѵ�
	if (!c_pSplashWnd->Create(pParentWnd, nBitmapID))
		// �����ϸ� ���÷��� ������ ��ü�� �����Ѵ�
		delete c_pSplashWnd;
	else
		// ���÷��� �����츦 �����Ѵ�
		c_pSplashWnd->UpdateWindow();
}

// ��Ʈ�� ������ �̹����� ���÷��� �����츦 ����ϴ� �Լ�
void CFadeInSplashWnd::ShowSplashScreen(CWnd* pParentWnd, LPCTSTR pBitmapFileName)
{
	// ���÷��� ����� �Ұ����ϰų� �̹� ��� ���� ���÷��ð� �ִٸ� �����Ѵ�
	if (!c_bShowSplashWnd || c_pSplashWnd != NULL)
		return;

	// ���ο� ���÷��� ������ ��ü�� �����
	c_pSplashWnd = new CFadeInSplashWnd;
	// ���÷��� �����츦 �����Ѵ�
	if (!c_pSplashWnd->Create(pParentWnd, pBitmapFileName))
		// �����ϸ� ���÷��� ������ ��ü�� �����Ѵ�
		delete c_pSplashWnd;
	else
		// ���÷��� �����츦 �����Ѵ�
		c_pSplashWnd->UpdateWindow();
}

// ���ø����̼��� �޽����� ���� ��ó���ϴ� �Լ�
BOOL CFadeInSplashWnd::PreTranslateAppMessage(MSG* pMsg)
{
	// ���� ��� ���� ���÷��� �����찡 ���ٸ� ����
	if (c_pSplashWnd == NULL)
		return FALSE;

	// ���� Ű���峪 ���콺 ������ �ִٸ� ���÷��� ����� �ߴ��Ѵ�
	if (pMsg->message == WM_KEYDOWN ||
	    pMsg->message == WM_SYSKEYDOWN ||
	    pMsg->message == WM_LBUTTONDOWN ||
	    pMsg->message == WM_RBUTTONDOWN ||
	    pMsg->message == WM_MBUTTONDOWN ||
	    pMsg->message == WM_NCLBUTTONDOWN ||
	    pMsg->message == WM_NCRBUTTONDOWN ||
	    pMsg->message == WM_NCMBUTTONDOWN)
	{
		// ���÷��� �����츦 �Ҹ��Ų��
		c_pSplashWnd->HideSplashScreen();
		return TRUE;	// message handled here
	}

	return FALSE;	// message not handled
}

// ��Ʈ�� ���ҽ��� ����ϴ� ���÷��� �����츦 �����ϴ� �Լ�
BOOL CFadeInSplashWnd::Create(CWnd* pParentWnd, UINT nBitmapID)
{
	// ��Ʈ�� ���ҽ��� �о���δ�
	if (!m_bitmap.LoadBitmap(nBitmapID))
		return FALSE;

	// ��Ʈ�� ������ ��´�
	m_bitmap.GetBitmap(&m_infoBmp);

	// ���÷��� �����츦 �����Ѵ�
	return CreateEx(0,
		AfxRegisterWndClass(0, AfxGetApp()->LoadStandardCursor(IDC_ARROW)),
			NULL, WS_POPUP | WS_VISIBLE, 0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
			pParentWnd->GetSafeHwnd(), NULL);
}

// ��Ʈ�� ������ ����ϴ� ���÷��� �����츦 �����ϴ� �Լ�
BOOL CFadeInSplashWnd::Create(CWnd* pParentWnd, LPCTSTR pBitmapFileName)
{
	// ���Ϸκ��� ��Ʈ���� �����Ѵ�
	HBITMAP hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			LPCTSTR(pBitmapFileName), IMAGE_BITMAP,
			0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	// ��Ʈ�� ������ �����ϸ� ����
	if(hBitmap == NULL)			return FALSE;

	// ��Ʈ�� ��ü�� ��Ʈ�� �ڵ��� �����Ѵ�
	m_bitmap.Attach(hBitmap);

	// ��Ʈ�� ������ ��´�
	m_bitmap.GetBitmap(&m_infoBmp);

	// ���÷��� �����츦 �����Ѵ�
	return CreateEx(0,
		AfxRegisterWndClass(0, AfxGetApp()->LoadStandardCursor(IDC_ARROW)),
			NULL, WS_POPUP | WS_VISIBLE, 0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
			pParentWnd->GetSafeHwnd(), NULL);
}

// ���÷��� �����츦 �Ҹ��Ű�� �Լ�
void CFadeInSplashWnd::HideSplashScreen()
{
	// ���÷��� �����츦 �Ҹ��Ų��
	DestroyWindow();
	// ���� ���̾�α׸� Ȱ��ȭ ��Ų��
	AfxGetMainWnd()->UpdateWindow();
}

// ���÷��� ������ ������ �Ҹ� �Լ�
void CFadeInSplashWnd::PostNcDestroy()
{
	// ���÷��� ������ ������ �����Ѵ�
	delete this;
}

int CFadeInSplashWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// ���� �Ӽ��� �ʱ�ȭ�Ѵ�
	m_Blend.BlendOp				= AC_SRC_OVER;
	m_Blend.BlendFlags			= 0;
	m_Blend.AlphaFormat			= 0;
	m_Blend.SourceConstantAlpha = m_nOpaque = 0;

	// ���÷��� �����츦 ���� �������� ����� �ű��
	CenterWindow();

	// �������� �����ų Ÿ�̸Ӹ� �����Ѵ�
	SetTimer(1, 100, NULL);

	return 0;
}

void CFadeInSplashWnd::OnPaint()
{
	CPaintDC dc(this);

	// ���� �������� ���� �Ӽ��� �����Ѵ�
	m_Blend.SourceConstantAlpha = m_nOpaque;

	CDC MemDC, BmpDC;

	CBitmap MemBmp, *pOldMemBmp;

	// �޸� DC�� �����Ѵ�
	MemDC.CreateCompatibleDC(&dc);
	// �޸� ��Ʈ���� �����Ѵ�
	MemBmp.CreateCompatibleBitmap(&dc, m_infoBmp.bmWidth, m_infoBmp.bmHeight);
	// �޸� DC�� �޸� ��Ʈ���� �����Ѵ�
	pOldMemBmp = MemDC.SelectObject(&MemBmp);

	// �޸� DC�� ȭ�� ������ �����Ѵ�
	MemDC.BitBlt(0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
		&dc, 0, 0, SRCCOPY);

	// ��Ʈ�� DC�� �����Ѵ�
	BmpDC.CreateCompatibleDC(&dc);
	// ���÷��� ��Ʈ���� ��Ʈ�� DC�� �����Ѵ�
	CBitmap *pOldBmp = BmpDC.SelectObject(&m_bitmap);

	// �޸� DC�� ���뿡 �ٰ� ���÷��� ��Ʈ���� ���� �Ӽ��� ���� �����ϰ� ����Ѵ�
	::AlphaBlend(MemDC.m_hDC, 0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
		BmpDC.m_hDC, 0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight, m_Blend); 
	
	// �޸� DC�� ������ ȭ�鿡 ����Ѵ�
	dc.BitBlt(0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
		&MemDC, 0, 0, SRCCOPY);

	// GDI ��ü�� ��ȯ
	BmpDC.SelectObject(pOldBmp);
	BmpDC.DeleteDC();

	MemDC.SelectObject(pOldMemBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
}

void CFadeInSplashWnd::OnTimer(UINT nIDEvent)
{
	// �������� ������Ų��
	m_nOpaque = (int)((m_nOpaque + 5) * 1.1);

	// ���� �������� �ְ�� �ö󰬴ٸ�
	if(m_nOpaque > 255)
	{
		// Ÿ�̸Ӹ� �����Ѵ�
		KillTimer(nIDEvent);
		// ���÷��� �����츦 �Ҹ��Ų��
		HideSplashScreen();
	}
	else
	{
		// �������� ���� �Ӽ��� �����Ѵ�
		m_Blend.SourceConstantAlpha = m_nOpaque;

		CDC *pDC = GetDC();
		CDC MemDC, BmpDC;

		CBitmap MemBmp, *pOldMemBmp;

		// �޸� DC�� �����Ѵ�
		MemDC.CreateCompatibleDC(pDC);
		// �޸� ��Ʈ���� �����Ѵ�
		MemBmp.CreateCompatibleBitmap(pDC, m_infoBmp.bmWidth, m_infoBmp.bmHeight);
		// �޸� DC�� �޸� ��Ʈ���� �����Ѵ�
		pOldMemBmp = MemDC.SelectObject(&MemBmp);

		// �޸� DC�� ȭ�� ������ �����Ѵ�
		MemDC.BitBlt(0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
			pDC, 0, 0, SRCCOPY);

		// ��Ʈ�� DC�� �����Ѵ�
		BmpDC.CreateCompatibleDC(pDC);
		// ���÷��� ��Ʈ���� ��Ʈ�� DC�� �����Ѵ�
		CBitmap *pOldBmp = BmpDC.SelectObject(&m_bitmap);

		// �޸� DC�� ���뿡 �ٰ� ���÷��� ��Ʈ���� ���� �Ӽ��� ���� �����ϰ� ����Ѵ�
		::AlphaBlend(MemDC.m_hDC, 0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
			BmpDC.m_hDC, 0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight, m_Blend); 
		
		// �޸� DC�� ������ ȭ�鿡 ����Ѵ�
		pDC->BitBlt(0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
			&MemDC, 0, 0, SRCCOPY);

		// GDI ��ü�� ��ȯ
		BmpDC.SelectObject(pOldBmp);
		BmpDC.DeleteDC();

		MemDC.SelectObject(pOldMemBmp);
		MemDC.DeleteDC();
		MemBmp.DeleteObject();

		ReleaseDC(pDC);
	}
}

BOOL CFadeInSplashWnd::OnEraseBkgnd(CDC* pDC) 
{
	// ����� �׸��� �ʴ´�
	return TRUE;
}
