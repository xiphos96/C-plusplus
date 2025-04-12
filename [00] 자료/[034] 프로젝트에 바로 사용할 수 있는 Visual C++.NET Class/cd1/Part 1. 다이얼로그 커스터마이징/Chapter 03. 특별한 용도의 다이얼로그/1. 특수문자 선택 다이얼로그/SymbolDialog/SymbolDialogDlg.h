// SymbolDialogDlg.h : ��� ����
//

#pragma once


// CSymbolDialogDlg ��ȭ ����
class CSymbolDialogDlg : public CDialog
{
// ����
public:
	CSymbolDialogDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CSymbolDialogDlg)
	enum { IDD = IDD_SYMBOLDIALOG_DIALOG };
	CComboBox	m_FontCombo;					// �ý����� ��Ʈ�� �����ϴ� �޺� �ڽ�
	CString	m_strCode;							// ���õ� Ư�� ������ �ڵ带 ����ϴ� ����Ʈ �ڽ�
	int		m_nType;							// Ư�� ������ �ڵ� ����
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CSymbolDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CSymbolDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelectButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
