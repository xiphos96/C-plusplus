// AnimGIFDemoDlg.h : ��� ����
//

#pragma once

#include "AnimGIF.h"


// CAnimGIFDemoDlg ��ȭ ����
class CAnimGIFDemoDlg : public CDialog
{
// ����
public:
	CAnimGIFDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CAnimGIFDemoDlg)
	enum { IDD = IDD_ANIMGIFDEMO_DIALOG };
	CAnimGIF	m_AnimGIF;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAnimGIFDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CAnimGIFDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlayButton();
	afx_msg void OnPauseButton();
	afx_msg void OnResumeButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnDestroy();
};
