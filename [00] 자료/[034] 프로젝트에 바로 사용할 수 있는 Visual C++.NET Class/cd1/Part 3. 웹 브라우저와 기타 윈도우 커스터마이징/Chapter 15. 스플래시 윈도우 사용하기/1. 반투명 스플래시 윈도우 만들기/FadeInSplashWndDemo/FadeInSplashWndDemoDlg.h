// FadeInSplashWndDemoDlg.h : ��� ����
//

#pragma once


// CFadeInSplashWndDemoDlg ��ȭ ����
class CFadeInSplashWndDemoDlg : public CDialog
{
// ����
public:
	CFadeInSplashWndDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CFadeInSplashWndDemoDlg)
	enum { IDD = IDD_FADEINSPLASHWNDDEMO_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFadeInSplashWndDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CFadeInSplashWndDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShowButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
