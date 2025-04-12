// ColorPickButtonDemoDlg.h : ��� ����
//

#pragma once

// ���� ���� ��ư Ŭ���� ��� ����
#include "ColorPickButton.h"


// CColorPickButtonDemoDlg ��ȭ ����
class CColorPickButtonDemoDlg : public CDialog
{
// ����
public:
	CColorPickButtonDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������
	virtual ~CColorPickButtonDemoDlg();

// ��ȭ ���� ������
	//{{AFX_DATA(CColorPickButtonDemoDlg)
	enum { IDD = IDD_COLORPICKBUTTONDEMO_DIALOG };
	CColorPickButton	m_btnTextDefault;			// �⺻ ���� ���� ���� ��ư
	CColorPickButton	m_btnBkgndDefault;			// �⺻ ��� ���� ���� ��ư
	CColorPickButton	m_btnText;					// ���� ���� ���� ��ư
	CColorPickButton	m_btnBkgnd;					// ��� ���� ���� ��ư
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CColorPickButtonDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL

	COLORREF	m_clrTextDefault;					// ���� �⺻ ���� ����
	COLORREF	m_clrBkgndDefault;					// ���� �⺻ ��� ����
	COLORREF	m_clrText;							// ���� ���� ����
	COLORREF	m_clrBkgnd;							// ���� ��� ����

	CBrush		m_BkgndBrush;						// ��� ��¿� �귯��

// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CColorPickButtonDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	afx_msg LRESULT OnSelEndOKColor(WPARAM wParam, LPARAM lParam);	// ���� ���� �Ϸ� �޽��� �ڵ鷯
	DECLARE_MESSAGE_MAP()
};
