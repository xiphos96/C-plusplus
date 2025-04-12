#if !defined(AFX_SCROLLABLEDLG_H__D27F1F94_ACF9_4F5E_AE01_DE12E92407E4__INCLUDED_)
#define AFX_SCROLLABLEDLG_H__D27F1F94_ACF9_4F5E_AE01_DE12E92407E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScrollableDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScrollableDlg dialog

class CScrollableDlg : public CDialog
{
// Construction
public:
	CScrollableDlg(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScrollableDlg)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	CScrollBar	m_wndSizeBox;							// 사이즈 조절 핸들

	CPoint		m_ScrollPos;							// 현재 스크롤 위치 저장 변수
	CSize		m_ScrollSize;							// 스크롤 범위 저장 변수
	CRect		m_rcOriginalClient;						// 초기 다이얼로그 크기 저장 변수

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollableDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScrollableDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLABLEDLG_H__D27F1F94_ACF9_4F5E_AE01_DE12E92407E4__INCLUDED_)
