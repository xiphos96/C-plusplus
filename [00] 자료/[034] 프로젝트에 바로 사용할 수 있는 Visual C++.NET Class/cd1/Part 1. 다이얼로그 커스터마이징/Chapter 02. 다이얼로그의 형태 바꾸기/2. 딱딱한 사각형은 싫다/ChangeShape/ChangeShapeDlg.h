// ChangeShapeDlg.h : ��� ����
//

#pragma once


// CChangeShapeDlg ��ȭ ����

// ���̾�α��� ����� �ٲٱ� ���� CShapeDlg���� ��� �޴´�
#include "ShapeDlg.h"

class CChangeShapeDlg : public CShapeDlg
{
// ����
public:
	CChangeShapeDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CChangeShapeDlg)
	enum { IDD = IDD_CHANGESHAPE_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CChangeShapeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	CBitmap		m_bmpWindow;				// ���̾�α� ��� ���濡 ����ϰ�, ��濡 ����� �̹���
	BITMAP		m_bmpInfo;					// m_bmpWindow�� ���� ����

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CChangeShapeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
