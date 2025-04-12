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
	// 초기 불투명도를 1로 설정한다
	m_nOpaque = 0;
}

CFadeInSplashWnd::~CFadeInSplashWnd()
{
	// Clear the static window pointer.
	// 스플래시 윈도우 정적 변수를 초기화한다
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

// 스플래시 출력 가능 여부를 설정하는 함수
void CFadeInSplashWnd::EnableSplashScreen(BOOL bEnable)
{
	// 스플래시 출력 가능 여부를 저장한다
	c_bShowSplashWnd = bEnable;
}

// 비트맵 리소스를 이미지로 스플래시 윈도우를 출력하는 함수
void CFadeInSplashWnd::ShowSplashScreen(CWnd* pParentWnd, UINT nBitmapID)
{
	// 스플래시 출력이 불가능하거나 이미 출력 중인 스플래시가 있다면 종료한다
	if (!c_bShowSplashWnd || c_pSplashWnd != NULL)
		return;

	// 새로운 스플래시 윈도우 객체를 만든다
	c_pSplashWnd = new CFadeInSplashWnd;
	// 스플래시 윈도우를 생성한다
	if (!c_pSplashWnd->Create(pParentWnd, nBitmapID))
		// 실패하면 스플래시 윈도우 객체를 제거한다
		delete c_pSplashWnd;
	else
		// 스플래시 윈도우를 갱신한다
		c_pSplashWnd->UpdateWindow();
}

// 비트맵 파일을 이미지로 스플래시 윈도우를 출력하는 함수
void CFadeInSplashWnd::ShowSplashScreen(CWnd* pParentWnd, LPCTSTR pBitmapFileName)
{
	// 스플래시 출력이 불가능하거나 이미 출력 중인 스플래시가 있다면 종료한다
	if (!c_bShowSplashWnd || c_pSplashWnd != NULL)
		return;

	// 새로운 스플래시 윈도우 객체를 만든다
	c_pSplashWnd = new CFadeInSplashWnd;
	// 스플래시 윈도우를 생성한다
	if (!c_pSplashWnd->Create(pParentWnd, pBitmapFileName))
		// 실패하면 스플래시 윈도우 객체를 제거한다
		delete c_pSplashWnd;
	else
		// 스플래시 윈도우를 갱신한다
		c_pSplashWnd->UpdateWindow();
}

// 애플리케이션의 메시지에 대해 전처리하는 함수
BOOL CFadeInSplashWnd::PreTranslateAppMessage(MSG* pMsg)
{
	// 현재 출력 중인 스플래시 윈도우가 없다면 리턴
	if (c_pSplashWnd == NULL)
		return FALSE;

	// 만약 키보드나 마우스 동작이 있다면 스플래시 출력을 중단한다
	if (pMsg->message == WM_KEYDOWN ||
	    pMsg->message == WM_SYSKEYDOWN ||
	    pMsg->message == WM_LBUTTONDOWN ||
	    pMsg->message == WM_RBUTTONDOWN ||
	    pMsg->message == WM_MBUTTONDOWN ||
	    pMsg->message == WM_NCLBUTTONDOWN ||
	    pMsg->message == WM_NCRBUTTONDOWN ||
	    pMsg->message == WM_NCMBUTTONDOWN)
	{
		// 스플래시 윈도우를 소멸시킨다
		c_pSplashWnd->HideSplashScreen();
		return TRUE;	// message handled here
	}

	return FALSE;	// message not handled
}

// 비트맵 리소스를 사용하는 스플래시 윈도우를 생성하는 함수
BOOL CFadeInSplashWnd::Create(CWnd* pParentWnd, UINT nBitmapID)
{
	// 비트맵 리소스를 읽어들인다
	if (!m_bitmap.LoadBitmap(nBitmapID))
		return FALSE;

	// 비트맵 정보를 얻는다
	m_bitmap.GetBitmap(&m_infoBmp);

	// 스플래시 윈도우를 생성한다
	return CreateEx(0,
		AfxRegisterWndClass(0, AfxGetApp()->LoadStandardCursor(IDC_ARROW)),
			NULL, WS_POPUP | WS_VISIBLE, 0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
			pParentWnd->GetSafeHwnd(), NULL);
}

// 비트맵 파일을 사용하는 스플래시 윈도우를 생성하는 함수
BOOL CFadeInSplashWnd::Create(CWnd* pParentWnd, LPCTSTR pBitmapFileName)
{
	// 파일로부터 비트맵을 생성한다
	HBITMAP hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			LPCTSTR(pBitmapFileName), IMAGE_BITMAP,
			0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	// 비트맵 생성에 실패하면 리턴
	if(hBitmap == NULL)			return FALSE;

	// 비트맵 객체에 비트맵 핸들을 설정한다
	m_bitmap.Attach(hBitmap);

	// 비트맵 정보를 얻는다
	m_bitmap.GetBitmap(&m_infoBmp);

	// 스플래시 윈도우를 생성한다
	return CreateEx(0,
		AfxRegisterWndClass(0, AfxGetApp()->LoadStandardCursor(IDC_ARROW)),
			NULL, WS_POPUP | WS_VISIBLE, 0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
			pParentWnd->GetSafeHwnd(), NULL);
}

// 스플래시 윈도우를 소멸시키는 함수
void CFadeInSplashWnd::HideSplashScreen()
{
	// 스플래시 윈도우를 소멸시킨다
	DestroyWindow();
	// 메인 다이얼로그를 활성화 시킨다
	AfxGetMainWnd()->UpdateWindow();
}

// 스플래시 윈도우 프레임 소멸 함수
void CFadeInSplashWnd::PostNcDestroy()
{
	// 스플래시 윈도우 객제를 제거한다
	delete this;
}

int CFadeInSplashWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 투명 속성을 초기화한다
	m_Blend.BlendOp				= AC_SRC_OVER;
	m_Blend.BlendFlags			= 0;
	m_Blend.AlphaFormat			= 0;
	m_Blend.SourceConstantAlpha = m_nOpaque = 0;

	// 스플래시 윈도우를 메인 윈도우의 가운데로 옮긴다
	CenterWindow();

	// 불투명도를 변경시킬 타이머를 실행한다
	SetTimer(1, 100, NULL);

	return 0;
}

void CFadeInSplashWnd::OnPaint()
{
	CPaintDC dc(this);

	// 현재 불투명도를 투명 속성에 설정한다
	m_Blend.SourceConstantAlpha = m_nOpaque;

	CDC MemDC, BmpDC;

	CBitmap MemBmp, *pOldMemBmp;

	// 메모리 DC를 생성한다
	MemDC.CreateCompatibleDC(&dc);
	// 메모리 비트맵을 생성한다
	MemBmp.CreateCompatibleBitmap(&dc, m_infoBmp.bmWidth, m_infoBmp.bmHeight);
	// 메모리 DC에 메모리 비트맵을 설정한다
	pOldMemBmp = MemDC.SelectObject(&MemBmp);

	// 메모리 DC에 화면 내용을 복사한다
	MemDC.BitBlt(0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
		&dc, 0, 0, SRCCOPY);

	// 비트맵 DC를 생성한다
	BmpDC.CreateCompatibleDC(&dc);
	// 스플래시 비트맵을 비트맵 DC에 설정한다
	CBitmap *pOldBmp = BmpDC.SelectObject(&m_bitmap);

	// 메모리 DC의 내용에 다가 스플래시 비트맵을 투명 속성에 맞춰 투명하게 출력한다
	::AlphaBlend(MemDC.m_hDC, 0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
		BmpDC.m_hDC, 0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight, m_Blend); 
	
	// 메모리 DC의 내용을 화면에 출력한다
	dc.BitBlt(0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
		&MemDC, 0, 0, SRCCOPY);

	// GDI 객체들 반환
	BmpDC.SelectObject(pOldBmp);
	BmpDC.DeleteDC();

	MemDC.SelectObject(pOldMemBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
}

void CFadeInSplashWnd::OnTimer(UINT nIDEvent)
{
	// 불투명도를 증가시킨다
	m_nOpaque = (int)((m_nOpaque + 5) * 1.1);

	// 만약 불투명도가 최고로 올라갔다면
	if(m_nOpaque > 255)
	{
		// 타이머를 정지한다
		KillTimer(nIDEvent);
		// 스플래시 윈도우를 소멸시킨다
		HideSplashScreen();
	}
	else
	{
		// 불투명도를 투명 속성에 설정한다
		m_Blend.SourceConstantAlpha = m_nOpaque;

		CDC *pDC = GetDC();
		CDC MemDC, BmpDC;

		CBitmap MemBmp, *pOldMemBmp;

		// 메모리 DC를 생성한다
		MemDC.CreateCompatibleDC(pDC);
		// 메모리 비트맵을 생성한다
		MemBmp.CreateCompatibleBitmap(pDC, m_infoBmp.bmWidth, m_infoBmp.bmHeight);
		// 메모리 DC에 메모리 비트맵을 설정한다
		pOldMemBmp = MemDC.SelectObject(&MemBmp);

		// 메모리 DC에 화면 내용을 복사한다
		MemDC.BitBlt(0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
			pDC, 0, 0, SRCCOPY);

		// 비트맵 DC를 생성한다
		BmpDC.CreateCompatibleDC(pDC);
		// 스플래시 비트맵을 비트맵 DC에 설정한다
		CBitmap *pOldBmp = BmpDC.SelectObject(&m_bitmap);

		// 메모리 DC의 내용에 다가 스플래시 비트맵을 투명 속성에 맞춰 투명하게 출력한다
		::AlphaBlend(MemDC.m_hDC, 0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
			BmpDC.m_hDC, 0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight, m_Blend); 
		
		// 메모리 DC의 내용을 화면에 출력한다
		pDC->BitBlt(0, 0, m_infoBmp.bmWidth, m_infoBmp.bmHeight,
			&MemDC, 0, 0, SRCCOPY);

		// GDI 객체들 반환
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
	// 배경은 그리지 않는다
	return TRUE;
}
