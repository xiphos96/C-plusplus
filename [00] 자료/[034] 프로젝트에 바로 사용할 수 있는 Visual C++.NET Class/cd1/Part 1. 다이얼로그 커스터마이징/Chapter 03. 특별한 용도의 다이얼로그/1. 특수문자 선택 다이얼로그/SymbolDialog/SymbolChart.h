#if !defined(AFX_SYMBOLCHART_H__E0729224_2431_11D5_AA4B_0000B4C34F32__INCLUDED_)
#define AFX_SYMBOLCHART_H__E0729224_2431_11D5_AA4B_0000B4C34F32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SymbolChart.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSymbolChart window

class CSymbolPreviewStatic;

// 특수 문자표 출력 컨트롤

class CSymbolChart : public CStatic
{
// Construction
public:
	CSymbolChart();

// Attributes
public:
	BOOL			m_bIsUnicode;				// 유니코드인지 여부
	BOOL			m_bIsUpper;					// 하위 바이트가 0~127 부분인지 128~255 부분인지 여부
	char			m_SelectedCode;				// 현재 선택된 코드 셀 번호

	unsigned char	m_cHighByte;				// 특수 문자의 상위 바이트

	CRect			m_ClientRect;				// 컨트롤의 클라이언트 영역
	int				m_nItemWidth;				// 한 셀의 폭
	int				m_nItemHeight;				// 한 셀의 높이

	CFont			m_DisplayFont;				// 화면 출력에 사용되는 폰트
	CString			m_FontName;					// 화면 출력에 사용되는 폰트 이름

	CEdit			*m_pEdit;					// 특수 문자의 코드를 출력할 에디트 컨트롤 포인터
	CSymbolPreviewStatic	*m_pPreview;		// 특수 문자 미리보기 컨트롤 포인터

	wchar_t			m_strUni[2];				// 유니코드 저장용 변수
	char			m_strAscii[2];				// 아스키 코드 저장용 변수

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSymbolChart)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSymbolChart();

	void InitCodeChart();							// 특수 문자표 관련 변수들을 초기화하는 함수
	void UpdateCodeEdit();							// 현재 선택된 특수 문자의 코드를 에디트 박스에 설정하는 함수
	void RedrawCode(CDC *pDC, int nRow, int nCol);	// 특정 특수 문자를 화면에 출력하는 함수

	unsigned char GetSelectedLowCode();				// 현재 선택된 특수 문자의 하위 바이트를 리턴하는 함수

	// Generated message map functions
protected:
	//{{AFX_MSG(CSymbolChart)
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYMBOLCHART_H__E0729224_2431_11D5_AA4B_0000B4C34F32__INCLUDED_)
