#if !defined(AFX_AUTOTABCTRL_H__DD9BD036_0891_4B9D_92CA_D7240724D3F4__INCLUDED_)
#define AFX_AUTOTABCTRL_H__DD9BD036_0891_4B9D_92CA_D7240724D3F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AutoTabCtrl.h : header file
//

// CArray�� ����ϱ� ���� ��� ����
#include <afxtempl.h>

// �ڵ� �ǿ��� �θ� ���̾�α׿��� ������ �޽��� ����
#define WM_AT_SELCHANGING		(WM_USER + 1)	// ���� ���� ������� �˸��� �޽���
#define WM_AT_SELCHANGE			(WM_USER + 2)	// ���� ���� ����Ǿ����� �˸��� �޽���


// �ڵ� �ǿ��� �ǿ� ���ϴ� ��Ʈ���� �����ϴ� Ŭ����
class CControlContainer
{
	// �ǿ� ���ϴ� ��Ʈ���� ������ ������ �迭
	CArray<CWnd*, CWnd*>	m_Controls;
	// ���� ���̴� ������ ����
	BOOL					m_bShow;

public:
	// ������
	CControlContainer();
	// �Ҹ���
	virtual ~CControlContainer();

	// �����̳ʿ� ��Ʈ���� �߰��ϴ� �Լ�
	int AddControl(CWnd *pCtrl);
	// �����̳��� ��Ʈ�ѵ��� ���̰ų� ���ߴ� �Լ�
	void ShowControls(BOOL bShow = TRUE);
};

/////////////////////////////////////////////////////////////////////////////
// CAutoTabCtrl window

// �ڵ����� ��Ʈ���� �����ϴ� �� ��Ʈ�� Ŭ����
class CAutoTabCtrl : public CTabCtrl
{
// Construction
public:
	CAutoTabCtrl();

// Attributes
public:
	// �� ��Ʈ���� �ǿ� ���� �����̳� �迭
	CArray<CControlContainer*, CControlContainer*>	m_Containers;

// Operations
public:
	// Ư�� ���� �����ϴ� �Լ�
	int SetCurSel(int nItem);
	// Ư�� �ǿ� ��Ʈ���� �߰��ϴ� �Լ�
	BOOL AddControl(int nTab, CWnd *pWnd);

	// ���ο� ���� �����ϴ� �Լ�
	BOOL InsertItem(int nItem, TCITEM* pTabCtrlItem);
	// ���ο� ���� �����ϴ� �Լ�
	BOOL InsertItem(int nItem, LPCTSTR lpszItem);
	// ���ο� ���� �����ϴ� �Լ�
	BOOL InsertItem(int nItem, LPCTSTR lpszItem, int nImage);
	// ���ο� ���� �����ϴ� �Լ�
	BOOL InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam);
	// Ư�� ���� �����ϴ� �Լ�
	BOOL DeleteItem(int nItem);
	// ��� ���� �����ϴ� �Լ�
	BOOL DeleteAllItems();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoTabCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAutoTabCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CAutoTabCtrl)
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOTABCTRL_H__DD9BD036_0891_4B9D_92CA_D7240724D3F4__INCLUDED_)
