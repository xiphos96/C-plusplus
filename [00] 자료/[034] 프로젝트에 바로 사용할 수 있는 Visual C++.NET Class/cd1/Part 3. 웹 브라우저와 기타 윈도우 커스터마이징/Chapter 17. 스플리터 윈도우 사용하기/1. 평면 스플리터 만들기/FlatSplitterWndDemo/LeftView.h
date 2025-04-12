#if !defined(AFX_LEFTVIEW_H__D6CADED5_EFEF_49FC_BBF7_8152F7B3BB32__INCLUDED_)
#define AFX_LEFTVIEW_H__D6CADED5_EFEF_49FC_BBF7_8152F7B3BB32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeftView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

// 메인프레임의 좌측 뷰 클래스
class CLeftView : public CFormView
{
protected:
	CLeftView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLeftView)

// Form Data
public:
	//{{AFX_DATA(CLeftView)
	enum { IDD = IDD_FORM_VIEW };
	int		m_nCX;
	int		m_nCY;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CLeftView)
	afx_msg void OnChangeButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTVIEW_H__D6CADED5_EFEF_49FC_BBF7_8152F7B3BB32__INCLUDED_)
