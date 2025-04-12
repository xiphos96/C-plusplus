#if !defined(AFX_COLORPALETTEWND_H__BF2D5D23_953A_445C_856A_D44DDE53DCF4__INCLUDED_)
#define AFX_COLORPALETTEWND_H__BF2D5D23_953A_445C_856A_D44DDE53DCF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorPaletteWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorPaletteWnd window

// 팔레트 윈도우 관련 메시지 정의
#define CLR_TRACKCOLOR		(WM_USER + 1000)
#define CLR_DROPDOWN		(WM_USER + 1001)
#define CLR_CLOSEUP			(WM_USER + 1002)
#define CLR_SELENDOK		(WM_USER + 1003)
#define CLR_SELENDCANCEL	(WM_USER + 1004)

// 팔레트의 각 색상에 대한 정보 구조체
struct COLOR_TABLE
{
	COLORREF	clrColor;
	CString		strName;
};


// 팔레트 윈도우 클래스
class CColorPaletteWnd : public CWnd
{
// Construction
public:
	CColorPaletteWnd();

// Attributes
public:
	static COLOR_TABLE	*m_pColorTable;				// 40가지의 기본 색상에 대한 정보
	static int			m_nCount;					// 색상 테이블을 사용하는 버튼 갯수

	CWnd				*m_pParent;					// 부모 윈도우(버튼)의 포인터
	COLORREF			m_clrColor;					// 초기 색상

	COLORREF			m_clrBkgnd;					// 배경 색상

	CFont				m_TextFont;					// 글자 출력용 폰트

	int					m_nBorder;					// 팔레트의 테두리 두께
	int					m_nSelected;				// 현재 선택된 항목의 번호

	CRect				m_rcDefault;				// "기본 색상" 버튼의 영역
	CRect				m_rcColorBox;				// 색상 버튼들이 위치할 영역
	CRect				m_rcMore;					// "More Colors..." 버튼의 영역
	CRect				m_rcWindow;					// 전체 팔레트 윈도우의 크기

	CString				m_strToolTip;				// 툴팁 텍스트
	CToolTipCtrl		m_wndToolTip;				// 툴팁 컨트롤

	BOOL				m_bColorDialog;				// 현재 색상 다이얼로그가 띄워진 상태인지 여부

// Operations
public:
	// 초기 색상과 위치로 팔레트 윈도우를 생성하는 함수
	BOOL Init(COLORREF clrColor, CWnd *pParent, int x, int y, UINT nID);
	// 특정 색상에 대한 색상 테이블에서의 번호를 리턴하는 함수
	int FindColor(COLORREF clrColor);

	// 색상 테이블에 대한 초기화 함수
	static void InitColorTable();
	// 특정 색상에 대한 색상 이름을 리턴하는 함수
	static void FindColorName(COLORREF clrColor, CString &strName);

	// 팔레트 윈도우의 각 구성요소를 화면에 출력하는 함수
	void DrawColorCell(CDC *pDC, int nItem);
	// 사용자가 색상을 선택하거나 취소한 경우 처리하는 함수
	void EndSelect(BOOL bSelOK);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorPaletteWnd)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CColorPaletteWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CColorPaletteWnd)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
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

#endif // !defined(AFX_COLORPALETTEWND_H__BF2D5D23_953A_445C_856A_D44DDE53DCF4__INCLUDED_)
