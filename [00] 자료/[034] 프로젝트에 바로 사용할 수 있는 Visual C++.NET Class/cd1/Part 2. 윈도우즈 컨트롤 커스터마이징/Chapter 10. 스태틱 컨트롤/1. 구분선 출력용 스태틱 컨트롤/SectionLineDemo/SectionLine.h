#if !defined(AFX_SECTIONLINE_H__D0973981_D6E7_4001_9DC4_2C6FFAE68338__INCLUDED_)
#define AFX_SECTIONLINE_H__D0973981_D6E7_4001_9DC4_2C6FFAE68338__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SectionLine.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSectionLine window


// 구분선 스태틱 컨트롤 클래스
class CSectionLine : public CStatic
{
// Construction
public:
	CSectionLine();

// Attributes
public:
	BOOL			m_bHorz;					// 가로 방향 텍스트 출력 여부
	CRect			m_rcText;					// 텍스트가 출력되는 사각 영역
	CRect			m_rcLineLeft;				// 왼쪽 구분선이 출력되는 사각 영역
	CRect			m_rcLineRight;				// 오른쪽 구분선이 출력되는 사각 영역

	COLORREF		m_clrText;					// 텍스트 색상
	COLORREF		m_clrBkgnd;					// 배경 색상
	COLORREF		m_clrHighlight;				// 밝은 색상
	COLORREF		m_clrShadow;				// 어두운 색상

	CFont			m_VertFont;					// 세로 텍스트 출력용 폰트

// Operations
public:
	// 텍스트의 영역과 구분선의 영역을 계산하는 함수
	void RecalcSectionLine(LPCTSTR pText);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSectionLine)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSectionLine();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSectionLine)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	afx_msg LONG OnSetText(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SECTIONLINE_H__D0973981_D6E7_4001_9DC4_2C6FFAE68338__INCLUDED_)
