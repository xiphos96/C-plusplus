// CoolButtonDemoDlg.h : ��� ����
//

#pragma once

#include "CoolButton.h"


// CCoolButtonDemoDlg ��ȭ ����
class CCoolButtonDemoDlg : public CDialog
{
// ����
public:
	CCoolButtonDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CCoolButtonDemoDlg)
	enum { IDD = IDD_COOLBUTTONDEMO_DIALOG };
	CCoolButton	m_btnBmp;						// ��Ʈ���� ���� ��ư
	CCoolButton	m_btnIcon;						// �������� ���� ��ư
	CCoolButton	m_btnTransparent;				// ��Ʈ���� ������ Ư�� ���� ���� ó���� ��ư
	CCoolButton	m_btnPosition;					// ��ġ ���� ��ư
	int		m_nAlign;							// ��ġ ����
	BOOL	m_bEnable;							// ��ư�� Ȱ��ȭ ����
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCoolButtonDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CCoolButtonDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLeftRadio();
	afx_msg void OnRightRadio();
	afx_msg void OnTopRadio();
	afx_msg void OnBottomRadio();
	afx_msg void OnOverRadio();
	afx_msg void OnEnableCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
