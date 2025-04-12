#if !defined(AFX_DIALOGTABCTRL_H__E1DB44BB_1780_4B19_B3A2_63DE9E2CE1AA__INCLUDED_)
#define AFX_DIALOGTABCTRL_H__E1DB44BB_1780_4B19_B3A2_63DE9E2CE1AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogTabCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogTabCtrl window

// CArray�� ����ϱ� ���� ��� ����
#include <afxtempl.h>

// ���̾�α� �ǿ��� �θ� ���̾�α׿��� ������ �޽��� ����
#define WM_AT_SELCHANGING		(WM_USER + 1)	// ���� ���� ������� �˸��� �޽���
#define WM_AT_SELCHANGE			(WM_USER + 2)	// ���� ���� ����Ǿ����� �˸��� �޽���


// ���̾�α� �� ��Ʈ�� Ŭ����
class CDialogTabCtrl : public CTabCtrl
{
// Construction
public:
	CDialogTabCtrl();

// Attributes
public:
	// �� ��Ʈ���� �ǿ� ���� ���̾�α� �迭
	CArray<CDialog*, CDialog*>	m_Dialogs;

// Operations
public:
	// Ư�� ���� �����ϴ� �Լ�
	int SetCurSel(int nItem);
	// ���� ���� �����ϴ� ���̾�α׸� �����ϴ� �Լ�
	CDialog* GetCurSelDlg();
	// Ư�� ���� �����ϴ� ���̾�α׸� �����ϴ� �Լ�
	CDialog* GetDialog(int nItem);

	// ���ο� ���� �����ϴ� �Լ�
	BOOL InsertItem(int nItem, TCITEM* pTabCtrlItem, CDialog *pDialog);
	// ���ο� ���� �����ϴ� �Լ�
	BOOL InsertItem(int nItem, LPCTSTR lpszItem, CDialog *pDialog);
	// ���ο� ���� �����ϴ� �Լ�
	BOOL InsertItem(int nItem, LPCTSTR lpszItem, int nImage, CDialog *pDialog);
	// ���ο� ���� �����ϴ� �Լ�
	BOOL InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam, CDialog *pDialog);
	// Ư�� ���� �����ϴ� �Լ�
	BOOL DeleteItem(int nItem);
	// ��� ���� �����ϴ� �Լ�
	BOOL DeleteAllItems();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogTabCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDialogTabCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDialogTabCtrl)
	afx_msg void OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGTABCTRL_H__E1DB44BB_1780_4B19_B3A2_63DE9E2CE1AA__INCLUDED_)
