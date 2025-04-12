// SlideEditDemoDlg.h : ��� ����
//

#pragma once

// �����̵� ����Ʈ ��Ʈ���� ����ϱ� ���� Ŭ���� ��� ����
#include "SlideEdit.h"
// �÷� ����ƽ ��Ʈ���� ����ϱ� ���� Ŭ���� ��� ����
#include "ColorStatic.h"


// CSlideEditDemoDlg ��ȭ ����
class CSlideEditDemoDlg : public CDialog
{
// ����
public:
	CSlideEditDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CSlideEditDemoDlg)
	enum { IDD = IDD_SLIDEEDITDEMO_DIALOG };
	CColorStatic	m_ColorStatic;
	CSlideEdit	m_SlideEditR;
	CSlideEdit	m_SlideEditG;
	CSlideEdit	m_SlideEditB;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CSlideEditDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL

// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CSlideEditDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	// �����̵� ����Ʈ ��Ʈ�ѿ��� ������ �޽����� ���� �ڵ鷯
	afx_msg LRESULT OnSlidePosChange(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSlideEndSelect(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
