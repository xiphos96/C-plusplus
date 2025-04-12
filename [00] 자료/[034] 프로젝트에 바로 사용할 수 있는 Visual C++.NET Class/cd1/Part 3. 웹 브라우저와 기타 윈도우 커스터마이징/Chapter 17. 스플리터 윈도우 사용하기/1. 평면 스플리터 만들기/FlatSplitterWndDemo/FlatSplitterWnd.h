#if !defined(AFX_FLATSPLITTERWND_H__099C0BD1_B833_4483_89CA_D00FB2517754__INCLUDED_)
#define AFX_FLATSPLITTERWND_H__099C0BD1_B833_4483_89CA_D00FB2517754__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlatSplitterWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFlatSplitterWnd frame with splitter


// 평면 스플리터 윈도우 클래스
class CFlatSplitterWnd : public CSplitterWnd
{
	DECLARE_DYNCREATE(CFlatSplitterWnd)

public:
	CFlatSplitterWnd();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	// 스플리터의 두께를 설정하는 함수
	void SetSplitterThick(int nHorz, int nVert);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlatSplitterWnd)
	public:
	virtual void OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFlatSplitterWnd();

	// Generated message map functions
	//{{AFX_MSG(CFlatSplitterWnd)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLATSPLITTERWND_H__099C0BD1_B833_4483_89CA_D00FB2517754__INCLUDED_)
