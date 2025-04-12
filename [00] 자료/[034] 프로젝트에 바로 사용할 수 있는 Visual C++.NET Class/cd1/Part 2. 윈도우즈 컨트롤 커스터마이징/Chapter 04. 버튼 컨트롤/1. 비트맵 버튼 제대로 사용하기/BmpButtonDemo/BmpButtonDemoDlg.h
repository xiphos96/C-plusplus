// BmpButtonDemoDlg.h : ��� ����
//

#pragma once

// ���� Ŭ���� ó���� ���� ��Ʈ�� ��ư Ŭ���� ���
#include "SpeedBmpButton.h"

// CBmpButtonDemoDlg ��ȭ ����
class CBmpButtonDemoDlg : public CDialog
{
// ����
public:
	CBmpButtonDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CBmpButtonDemoDlg)
	enum { IDD = IDD_BMPBUTTONDEMO_DIALOG };
	CBitmapButton	m_btnOrigin;				// ���� ��Ʈ�� ��ư Ŭ���� ����
	CSpeedBmpButton	m_btnSpeed;					// ���� ��Ʈ�� ��ư Ŭ���� ����
	int		m_nOrigin;							// ���� ��Ʈ�� ��ư Ŭ�� Ƚ��
	int		m_nSpeed;							// ���� ��Ʈ�� ��ư Ŭ�� Ƚ��
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CBmpButtonDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CBmpButtonDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOriginBitmapButton();
	afx_msg void OnSpeedBitmapButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnDoubleclickedSpeedBitmapButton();
//	afx_msg void OnBnDoubleclickedOriginBitmapButton();
};
