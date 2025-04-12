#if !defined(AFX_FLATHEADERCTRL_H__97A15E65_209F_4833_AF23_0FF044C89F8A__INCLUDED_)
#define AFX_FLATHEADERCTRL_H__97A15E65_209F_4833_AF23_0FF044C89F8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlatHeaderCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFlatHeaderCtrl window

// 평면 헤더 컨트롤 클래스
class CFlatHeaderCtrl : public CHeaderCtrl
{
// Construction
public:
	CFlatHeaderCtrl();

// Attributes
public:
	CRect		m_rcClient;				// 클라이언트 영역
	COLORREF	m_clrFace;				// 헤더 컨트롤의 배경 색상
	COLORREF	m_clrHighLight;			// 헤더 컨트롤의 밝은 면 색상
	COLORREF	m_clrShadow;			// 헤더 컨트롤의 어두운 면 색상
	COLORREF	m_clrText;				// 헤더 컨트롤의 글자 색상
	CPen		m_HighLightPen;			// 구분자를 출력하기 위한 밝은 색 펜
	CPen		m_ShadowPen;			// 구분자를 출력하기 위한 어두운 색 펜

	CToolTipCtrl m_wndToolTip;			// 툴팁 컨트롤

	int			m_nClickColumn;			// 마우스로 클릭된 항목 번호
	int			m_nSortColumn;			// 정렬의 기준인 컬럼 번호
	BOOL		m_bSortAscending;		// 정렬의 방향

// Operations
public:
	// 항목의 이미지를 출력하는 함수
	int DrawImage(CDC *pDC, CRect *pRect, LPHDITEM pItem, CImageList *pImageList, CSize *pSize);
	// 항목의 텍스트를 출력하는 함수
	int DrawText(CDC* pDC, CRect *pRect, LPHDITEM pItem);
	// 항목의 비트맵을 출력하는 함수
	int DrawBitmap(CDC* pDC, CRect *pRect, LPHDITEM pItem, CBitmap* pBitmap);
	// 항목의 정렬 방향 표시자를 출력하는 함수
	int DrawSortMark(CDC *pDC, CRect *pRect, LPHDITEM pItem);

	// 특정 컬럼에 대해 툴팁을 설정하는 함수
	BOOL AddTool(int nCol, LPCTSTR pTipText);
	// 각 컬럼 항목의 위치에 따라 툴팁 출력 영역을 다시 계산하는 함수
	void RecalcToolRect();

	// 새로운 정렬 기준 컬럼과 방향을 설정하는 함수
	void SetSortColumn(int nCol, BOOL bAscending);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlatHeaderCtrl)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFlatHeaderCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFlatHeaderCtrl)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLATHEADERCTRL_H__97A15E65_209F_4833_AF23_0FF044C89F8A__INCLUDED_)
