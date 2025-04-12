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

// Operations
public:
	// 항목의 이미지를 출력하는 함수
	int DrawImage(CDC *pDC, CRect *pRect, LPHDITEM pItem, CImageList *pImageList, CSize *pSize);
	// 항목의 텍스트를 출력하는 함수
	int DrawText(CDC* pDC, CRect *pRect, LPHDITEM pItem);
	// 항목의 비트맵을 출력하는 함수
	int DrawBitmap(CDC* pDC, CRect *pRect, LPHDITEM pItem, CBitmap* pBitmap);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlatHeaderCtrl)
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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLATHEADERCTRL_H__97A15E65_209F_4833_AF23_0FF044C89F8A__INCLUDED_)
