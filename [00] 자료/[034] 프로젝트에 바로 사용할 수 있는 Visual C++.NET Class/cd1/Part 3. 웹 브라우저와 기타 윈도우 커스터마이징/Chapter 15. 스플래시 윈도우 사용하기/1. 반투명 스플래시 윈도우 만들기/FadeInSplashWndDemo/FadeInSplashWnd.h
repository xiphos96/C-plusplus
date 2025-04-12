// CG: This file was added by the Splash Screen component.

#ifndef _SPLASH_SCRN_
#define _SPLASH_SCRN_

// FadeInSplashWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
//   Splash Screen class

// 반투명 스플래시 윈도우 클래스
class CFadeInSplashWnd : public CWnd
{
// Construction
protected:
	CFadeInSplashWnd();

// Attributes:
public:
	CBitmap			m_bitmap;			// 스플래시 비트맵
	BITMAP			m_infoBmp;			// 스플래시 비트맵 정보
	int				m_nOpaque;			// 불투명도
	BLENDFUNCTION	m_Blend;			// 투명 속성

// Operations
public:
	// 스플래시 출력 가능 여부를 설정하는 함수
	static void EnableSplashScreen(BOOL bEnable = TRUE);
	// 비트맵 리소스를 이미지로 스플래시 윈도우를 출력하는 함수
	static void ShowSplashScreen(CWnd* pParentWnd, UINT nBitmapID);
	// 비트맵 파일을 이미지로 스플래시 윈도우를 출력하는 함수
	static void ShowSplashScreen(CWnd* pParentWnd, LPCTSTR pBitmapFileName);
	// 애플리케이션의 메시지에 대해 전처리하는 함수
	static BOOL PreTranslateAppMessage(MSG* pMsg);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFadeInSplashWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CFadeInSplashWnd();
	// 스플래시 윈도우 프레임 소멸 함수
	virtual void PostNcDestroy();

protected:
	// 비트맵 리소스를 사용하는 스플래시 윈도우를 생성하는 함수
	BOOL Create(CWnd* pParentWnd, UINT nBitmapID);
	// 비트맵 파일을 사용하는 스플래시 윈도우를 생성하는 함수
	BOOL Create(CWnd* pParentWnd, LPCTSTR pBitmapFileName);
	// 스플래시 윈도우를 소멸시키는 함수
	void HideSplashScreen();

	// 스플래시 출력 여부
	static BOOL c_bShowSplashWnd;
	// 현재 출력 중인 스플래시 윈도우 포인터
	static CFadeInSplashWnd* c_pSplashWnd;

// Generated message map functions
protected:
	//{{AFX_MSG(CFadeInSplashWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif
