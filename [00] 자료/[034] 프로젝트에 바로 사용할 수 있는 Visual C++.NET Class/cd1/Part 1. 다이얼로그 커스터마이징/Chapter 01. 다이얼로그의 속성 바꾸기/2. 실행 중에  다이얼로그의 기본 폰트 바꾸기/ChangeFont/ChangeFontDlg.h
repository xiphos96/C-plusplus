// ChangeFontDlg.h : ��� ����
//

#pragma once


// CChangeFontDlg ��ȭ ����
class CChangeFontDlg : public CDialog
{
// ����
public:
	CChangeFontDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CChangeFontDlg)
	enum { IDD = IDD_CHANGEFONT_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CChangeFontDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL

	CString	m_strFontName;			// ��Ʈ ��ȭ���ڿ��� �Է��� ��Ʈ �̸�
	int		m_nFontSize;			// ��Ʈ ��ȭ���ڿ��� �Է��� ��Ʈ ũ��

// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CChangeFontDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFontButton();
	afx_msg void OnDomodalButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
