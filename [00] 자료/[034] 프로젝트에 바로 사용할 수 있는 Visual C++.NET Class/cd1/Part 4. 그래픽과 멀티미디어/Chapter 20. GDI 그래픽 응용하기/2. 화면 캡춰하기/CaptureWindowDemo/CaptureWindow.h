#if !defined(AFX_CAPTUREWINDOW_H__D9F07177_E232_49F4_A86A_73D27F47912B__INCLUDED_)
#define AFX_CAPTUREWINDOW_H__D9F07177_E232_49F4_A86A_73D27F47912B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CaptureWindow.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCaptureWindow window

// 윈도우 선택 및 캡춰 상황을 알리기 위한 메시지 정의
#define WM_SELECT_START				(WM_USER + 400)		// 윈도우 선택 시작 메시지
#define WM_SELECT_END				(WM_USER + 401)		// 윈도우 선택 종료 메시지
#define WM_CAPTURE_FINISH			(WM_USER + 402)		// 캡춰 완료 메시지


// 윈도우 캡춰 클래스
class CCaptureWindow : public CStatic
{
// Construction
public:
	CCaptureWindow();

// Attributes
public:
	// 스태틱 출력용 비트맵
	CBitmap						m_bmpSelector;			// 윈도우 선택 전 상태의 비트맵
	CBitmap						m_bmpSelectorButton;	// 윈도우 선택 상태의 비트맵

	HWND						m_hLastHWND;			// 윈도우 선택시 마지막 마우스가 이동된 윈도우 핸들
	HCURSOR						m_hSelectorCursor;		// 윈도우 선택시 마우스 커서

	CBitmap						m_bmpCapture;			// 캡춰된 윈도우 화면

// Operations
public:
	// 캡춰된 비트맵을 리턴하는 함수
	CBitmap* GetCapturedBitmap()		{ return &m_bmpCapture; }

	// 특정 윈도우의 외곽에 테두리를 그리는 함수
	void InvertWindowEdge(HWND hWnd);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaptureWindow)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCaptureWindow();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCaptureWindow)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTUREWINDOW_H__D9F07177_E232_49F4_A86A_73D27F47912B__INCLUDED_)
