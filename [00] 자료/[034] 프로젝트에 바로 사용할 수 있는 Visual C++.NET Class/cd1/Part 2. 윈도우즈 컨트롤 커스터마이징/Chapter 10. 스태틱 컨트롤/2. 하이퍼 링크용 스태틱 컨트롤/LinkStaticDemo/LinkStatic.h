#if !defined(AFX_LINKSTATIC_H__5CD619D7_872F_459A_AEF8_2F10203C3034__INCLUDED_)
#define AFX_LINKSTATIC_H__5CD619D7_872F_459A_AEF8_2F10203C3034__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LinkStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLinkStatic window

// 하이퍼 링크 스태틱 컨트롤 클래스
class CLinkStatic : public CStatic
{
// Construction
public:
	CLinkStatic();

// Attributes
public:
	CRect				m_rcClient;					// 클라이언트 크기
	CRect				m_rcText;					// 텍스트 크기

	CFont				m_HoverFont;				// 밑줄을 갖는 폰트
	COLORREF			m_clrText;					// 텍스트 색상
	COLORREF			m_clrHover;					// 마우스가 위치했을 때의 색상
	COLORREF			m_clrBkgnd;					// 배경 색상
	COLORREF			m_clrTransparent;			// 비트맵의 투명 색상
	HCURSOR				m_hCursor;					// 손모양 커서

	BITMAP				m_bmpInfo;					// 현재 이미지의 정보
	CBitmap				m_bmpImage;					// 비트맵 객체
	CBitmap				m_bmpMask;					// 비트맵 객체에서 투명 처리를 위한 마스크 비트맵
	CPoint				m_ptImage;					// 이미지 출력 위치

	BOOL				m_bHover;					// 마우스가 스태틱 컨트롤 위에 있는지 여부
	BOOL				m_bLeftImage;				// 텍스트의 왼쪽에 이미지를 출력할 여부

	CString				m_strToolTip;				// 툴팁 텍스트
	CToolTipCtrl		m_wndToolTip;				// 툴팁 컨트롤

// Operations
public:
	// 스태틱 컨트롤에 비트맵을 설정하는 함수
	void SetLinkBmp(UINT nBitmapID, BOOL bLeft);
	// 스태틱 컨트롤에 비트맵을 설정하고 투명색을 설정하는 함수
	void SetLinkBmp(UINT nBitmapID, COLORREF clrTransparent, BOOL bLeft);

	// 스태틱 컨트롤의 툴팁을 리턴/설정하는 함수
	LPCTSTR GetToolTipText()			{ return m_strToolTip; }
	void SetToolTipText(LPCTSTR pTip);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkStatic)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLinkStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CLinkStatic)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnClicked();
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKSTATIC_H__5CD619D7_872F_459A_AEF8_2F10203C3034__INCLUDED_)
