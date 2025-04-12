#if !defined(AFX_SLIDEWND_H__89551372_EA59_46DE_B4C5_2831A41AE59D__INCLUDED_)
#define AFX_SLIDEWND_H__89551372_EA59_46DE_B4C5_2831A41AE59D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SlideWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSlideWnd window

// 슬라이드 변동에 따라 전달할 메시지 정의
#define WM_SLIDE_POS_CHANGE			(WM_USER + 1)	// 슬라이드에서의 값 이동
#define WM_SLIDE_END_SELECT			(WM_USER + 2)	// 슬라이드를 사용한 값 변경 완료


// 슬라이드 윈도우 클래스
class CSlideWnd : public CWnd
{
// Construction
public:
	CSlideWnd();

// Attributes
public:
	CPen		m_LinePen;				// 라인을 그리기 위한 펜
	CPen		m_ShadowPen;			// 라인의 그림자를 그리기 위한 펜
	CBrush		m_BkgndBrush;			// 배경을 칠할 브러쉬

	HCURSOR		m_hCursor;				// 화살표 마우스 커서

	CWnd		*m_pParent;				// 슬라이드 에디트 컨트롤에 대한 포인터
	CRect		m_rcClient;				// 슬라이드 윈도우의 클라이언트 영역

	int			m_nCurPos;				// 현재 위치
	int			m_nMax;					// 최대 값
	int			m_nMin;					// 최소 값

// Operations
public:
	// 슬라이드 윈도우를 생성하는 함수
	BOOL PopupSlide(CWnd *pParent, CRect &rcWindow, int nMax, int nMin, int nPos);

	// 값의 변동이 발생할 경우 부모 윈도우에게 알리는 함수
	void OnPosChange();
	// 값 변경이 완료된 경우 부모 윈도우에게 알리는 함수
	void OnEndSelect();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSlideWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSlideWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSlideWnd)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//}}AFX_MSG
#if _MSC_VER <= 1200
	// VC++ 6.0에서의 코드
	afx_msg void OnActivateApp(BOOL bActive, HTASK dwThreadID);
#else
	// VC++.Net에서의 코드
	afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);
#endif
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDEWND_H__89551372_EA59_46DE_B4C5_2831A41AE59D__INCLUDED_)
