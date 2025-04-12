// CustomSliderCtrlDemoDlg.h : ��� ����
//

#pragma once

// ����� ���� �����̴� ��Ʈ�� ���
#include "CustomSliderCtrl.h"


// CCustomSliderCtrlDemoDlg ��ȭ ����
class CCustomSliderCtrlDemoDlg : public CDialog
{
// ����
public:
	CCustomSliderCtrlDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

	int		m_nThumbStep;					// �ڵ��� �̵� ����
	int		m_nSelectionStep;				// ������ �̵� ����

// ��ȭ ���� ������
	//{{AFX_DATA(CCustomSliderCtrlDemoDlg)
	enum { IDD = IDD_CUSTOMSLIDERCTRLDEMO_DIALOG };
	CCustomSliderCtrl	m_CustomHorzSlider;
	CCustomSliderCtrl	m_CustomVertSlider;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCustomSliderCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CCustomSliderCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRestartButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
