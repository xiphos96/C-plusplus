#if !defined(AFX_FOLDERDLG_H__65482C4D_F115_42E2_9A75_25B40D38F6F6__INCLUDED_)
#define AFX_FOLDERDLG_H__65482C4D_F115_42E2_9A75_25B40D38F6F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FolderDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFolderDlg dialog

class CFolderDlg : public CDialog
{
// Construction
public:
	CFolderDlg(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFolderDlg)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

protected:
	HICON	m_hIcon;									// 숨겨졌을 때 보여줄 아이콘

	DWORD	m_dwStyle;									// 원래 윈도우 스타일 저장 변수
	BOOL	m_bIsFolded;								// 숨겨진 상태인지 저장하는 변수
	CRect	m_rcWindow;									// 원래 윈도우 크기를 저장하는 변수
	CRect	m_rcLastFold;								// 마지막 숨겨졌을 때의 위치/크기를 저장하는 변수

public:
	void SetFoldIcon(HICON hIcon);						// 아이콘을 변경하는 함수

	void Fold();										// 다이얼로그를 숨기는 함수
	void Stretch();										// 다이얼로그를 다시 펼치는 함수

protected:
	void Animate(CRect &rcStart, CRect &rcEnd);			// 내부적으로 사용하는 애니메이션 함수

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFolderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFolderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg UINT OnNcHitTest(CPoint point);
	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOLDERDLG_H__65482C4D_F115_42E2_9A75_25B40D38F6F6__INCLUDED_)
