#if !defined(AFX_REPORTDLG_H__CDDA2119_E1BA_4FF7_8509_0A9CE73A28AC__INCLUDED_)
#define AFX_REPORTDLG_H__CDDA2119_E1BA_4FF7_8509_0A9CE73A28AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReportDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReportDlg dialog

// �հ� ���̾�α�
class CReportDlg : public CDialog
{
// Construction
public:
	CReportDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReportDlg)
	enum { IDD = IDD_REPORT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ���� ���̾�α׿� ���� ���̾�α��� �׸����� �հ踦 ����ϰ� ����ϴ� �Լ�
	void RefreshSum();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReportDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReportDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPORTDLG_H__CDDA2119_E1BA_4FF7_8509_0A9CE73A28AC__INCLUDED_)
