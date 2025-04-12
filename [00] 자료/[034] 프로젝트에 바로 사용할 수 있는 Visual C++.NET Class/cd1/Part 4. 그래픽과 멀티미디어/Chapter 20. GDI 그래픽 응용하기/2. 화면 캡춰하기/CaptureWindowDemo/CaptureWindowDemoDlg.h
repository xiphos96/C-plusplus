// CaptureWindowDemoDlg.h : ��� ����
//

#pragma once

#include "CaptureWindow.h"


// CCaptureWindowDemoDlg ��ȭ ����
class CCaptureWindowDemoDlg : public CDialog
{
// ����
public:
	CCaptureWindowDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CCaptureWindowDemoDlg)
	enum { IDD = IDD_CAPTUREWINDOWDEMO_DIALOG };
	CCaptureWindow	m_CaptureWindow;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCaptureWindowDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CCaptureWindowDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	afx_msg LRESULT OnSelectStart(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSelectEnd(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCaptureFinish(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
