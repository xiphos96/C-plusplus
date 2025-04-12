#if !defined(AFX_FILEBROWSEBUTTON_H__794D06E4_5C8B_4964_88BC_0664FF5642BB__INCLUDED_)
#define AFX_FILEBROWSEBUTTON_H__794D06E4_5C8B_4964_88BC_0664FF5642BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileBrowseButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileBrowseButton window

// 파일/폴더 찾기 버튼 클래스
class CFileBrowseButton : public CButton
{
// Construction
public:
	CFileBrowseButton();

// Attributes
public:
	// 배경색 출력용 브러쉬
	CBrush			m_BkgndBrush;
	// 라인 출력용 펜
	CPen			m_LinePen;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileBrowseButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFileBrowseButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFileBrowseButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClicked();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEBROWSEBUTTON_H__794D06E4_5C8B_4964_88BC_0664FF5642BB__INCLUDED_)
