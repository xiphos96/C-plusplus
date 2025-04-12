// WordBookDemoDlg.h : ��� ����
//

#pragma once

// �ܾ��� Ŭ���� ��� ���� ��ũ���
#include "WordBook.h"


// CWordBookDemoDlg ��ȭ ����
class CWordBookDemoDlg : public CDialog
{
// ����
public:
	CWordBookDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

	// Ŭ���̾�Ʈ ����
	CRect		m_rcClient;

// ��ȭ ���� ������
	//{{AFX_DATA(CWordBookDemoDlg)
	enum { IDD = IDD_WORDBOOKDEMO_DIALOG };
	CWordBook	m_WordBook;
	CString	m_strEnglish;
	CString	m_strKorean;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CWordBookDemoDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CWordBookDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnAddButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
