#if !defined(AFX_DEFFONTDIALOG_H__16E1A3B7_B67A_4F2A_81F0_40CFCCAA8FE5__INCLUDED_)
#define AFX_DEFFONTDIALOG_H__16E1A3B7_B67A_4F2A_81F0_40CFCCAA8FE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DefFontDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDefFontDialog dialog

class CDefFontDialog : public CDialog
{
// Construction
public:
	CDefFontDialog(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDefFontDialog)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

protected:
	CString		m_strFontName;				// ���� ������ ��Ʈ �̸�
	int			m_nFontSize;				// ���� ������ ��Ʈ ũ��
	UINT		m_nResourceID;				// ����� ���̾�α� ���ҽ� ID

public:
	LPCTSTR GetFontName();					// ��Ʈ �̸� ���� �Լ�
	void SetFontName(CString strFontName);	// ��Ʈ �̸� ���� �Լ�
	int GetFontSize();						// ��Ʈ ũ�� ���� �Լ�
	void SetFontSize(int nSize);			// ��Ʈ ũ�� ���� �Լ�


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDefFontDialog)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDefFontDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEFFONTDIALOG_H__16E1A3B7_B67A_4F2A_81F0_40CFCCAA8FE5__INCLUDED_)
