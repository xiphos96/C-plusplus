// CustomPropertySheetDemoDlg.h : ��� ����
//

#pragma once


// CCustomPropertySheetDemoDlg ��ȭ ����
class CCustomPropertySheetDemoDlg : public CDialog
{
// ����
public:
	CCustomPropertySheetDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CCustomPropertySheetDemoDlg)
	enum { IDD = IDD_CUSTOMPROPERTYSHEETDEMO_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCustomPropertySheetDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CCustomPropertySheetDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
