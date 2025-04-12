#if !defined(AFX_WARPTEXT_H__23D25ED7_D6EA_42B6_86D9_EB456C03D09C__INCLUDED_)
#define AFX_WARPTEXT_H__23D25ED7_D6EA_42B6_86D9_EB456C03D09C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WarpText.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWarpText window


// 텍스트 워핑 클래스
class CWarpText : public CStatic
{
// Construction
public:
	CWarpText();

// Attributes
public:
	BSTR			m_bstrText;				// 워핑할 텍스트 
	BSTR			m_bstrFontName;			// 텍스트에 사용할 폰트
	Color			m_clrFontColor;			// 텍스트를 칠할 색상
	Color			m_clrOutline;			// 텍스트 외곽선 색상

	CRect			m_rcClient;				// 컨트롤의 영역

	RectF			m_rcText;				// 텍스트 출력에 필요한 영역
	PointF			*m_ptWarp;				// 워핑에 사용될 좌표 배열
	GraphicsPath	m_TextPath;				// 텍스트에 대한 경로 객체

	BOOL			m_bShowGuideLine;		// 가이드 라인을 출력할지 여부

// Operations
public:
	// 워핑할 텍스트와 폰트를 설정하는 함수
	void SetText(LPCTSTR pText, LPCTSTR pFontName = NULL);
	// 텍스트를 칠하는 색상 설정 함수
	void SetFontColor(COLORREF clrFont);
	// 텍스트 외곽선을 칠하는 색상 설정 함수
	void SetOutlineColor(COLORREF clrOutline);
	// 가이드 라인 출력 여부를 설정하는 함수
	void ShowGuideLine(BOOL bShow);

	// 워핑 좌표를 설정하는 함수
	BOOL SetWarpPoint(CPoint *pWarpPoint);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWarpText)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWarpText();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWarpText)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WARPTEXT_H__23D25ED7_D6EA_42B6_86D9_EB456C03D09C__INCLUDED_)
