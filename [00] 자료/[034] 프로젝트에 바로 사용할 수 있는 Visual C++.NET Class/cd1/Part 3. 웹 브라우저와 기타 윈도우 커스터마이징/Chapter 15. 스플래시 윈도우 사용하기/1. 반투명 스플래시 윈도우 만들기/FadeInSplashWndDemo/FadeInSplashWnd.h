// CG: This file was added by the Splash Screen component.

#ifndef _SPLASH_SCRN_
#define _SPLASH_SCRN_

// FadeInSplashWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
//   Splash Screen class

// ������ ���÷��� ������ Ŭ����
class CFadeInSplashWnd : public CWnd
{
// Construction
protected:
	CFadeInSplashWnd();

// Attributes:
public:
	CBitmap			m_bitmap;			// ���÷��� ��Ʈ��
	BITMAP			m_infoBmp;			// ���÷��� ��Ʈ�� ����
	int				m_nOpaque;			// ������
	BLENDFUNCTION	m_Blend;			// ���� �Ӽ�

// Operations
public:
	// ���÷��� ��� ���� ���θ� �����ϴ� �Լ�
	static void EnableSplashScreen(BOOL bEnable = TRUE);
	// ��Ʈ�� ���ҽ��� �̹����� ���÷��� �����츦 ����ϴ� �Լ�
	static void ShowSplashScreen(CWnd* pParentWnd, UINT nBitmapID);
	// ��Ʈ�� ������ �̹����� ���÷��� �����츦 ����ϴ� �Լ�
	static void ShowSplashScreen(CWnd* pParentWnd, LPCTSTR pBitmapFileName);
	// ���ø����̼��� �޽����� ���� ��ó���ϴ� �Լ�
	static BOOL PreTranslateAppMessage(MSG* pMsg);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFadeInSplashWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CFadeInSplashWnd();
	// ���÷��� ������ ������ �Ҹ� �Լ�
	virtual void PostNcDestroy();

protected:
	// ��Ʈ�� ���ҽ��� ����ϴ� ���÷��� �����츦 �����ϴ� �Լ�
	BOOL Create(CWnd* pParentWnd, UINT nBitmapID);
	// ��Ʈ�� ������ ����ϴ� ���÷��� �����츦 �����ϴ� �Լ�
	BOOL Create(CWnd* pParentWnd, LPCTSTR pBitmapFileName);
	// ���÷��� �����츦 �Ҹ��Ű�� �Լ�
	void HideSplashScreen();

	// ���÷��� ��� ����
	static BOOL c_bShowSplashWnd;
	// ���� ��� ���� ���÷��� ������ ������
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
