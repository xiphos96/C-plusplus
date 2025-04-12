#if !defined(AFX_EXPLORERLISTCTRL_H__B9891EB5_2BD1_432E_AE17_43F221FCA12D__INCLUDED_)
#define AFX_EXPLORERLISTCTRL_H__B9891EB5_2BD1_432E_AE17_43F221FCA12D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExplorerListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExplorerListCtrl window

#define WM_EXPLORER_FILE_SELECT			(WM_USER + 1)


// Ž���� ����Ʈ ��Ʈ�� Ŭ����
class CExplorerListCtrl : public CListCtrl
{
// Construction
public:
	CExplorerListCtrl();

// Attributes
public:
	BOOL	m_bFolderOnly;
	BOOL	m_bSortByExt;
	BOOL	m_bSortAscending;
	CString m_strDrive;
	CString m_strCurPath;

// Operations
public:
	// ���� ����̺긦 �����ϴ� �Լ�
	void ChangeDrive(LPCTSTR pDrive);
	// ���� ������ �����ϴ� �Լ�
	void ChangeFolder(LPCTSTR pFolder);
	// �Ѵܰ� ���� ������ �̵��ϴ� �Լ�
	BOOL GoUp();
	// Ž���� ����Ʈ ��Ʈ�ѿ��� �������� �����ֵ��� �����ϴ� �Լ�
	void SetFolderOnly(BOOL bOnly);

	// ���� ���õ� �׸��� �������� �����ϴ� �Լ�
	BOOL IsFolder();
	// ���� ���õ� �׸��� �������� �����ϴ� �Լ�
	BOOL IsFile();
	// ���� ���õ� ������ ��θ� �����ϴ� �Լ�
	BOOL GetSelectedFolder(CString &strFolder);
	// ���� ���õ� ������ ��θ� �����ϴ� �Լ�
	BOOL GetSelectedFile(CString &strFile);

	// Ž���� ����Ʈ ��Ʈ���� �ٽ� �����ϴ� �Լ�
	void RefreshExplorer();
	// Ư�� �����̳� ������ �ý��� ������ ��ȣ�� �����ϴ� �Լ�
	int FindIconIndex(LPCTSTR pName, BOOL bIsDirectory);

	// ���� �Լ�
	void Sort();
	void Sort(BOOL bAscending, BOOL bExt);
	// ������ �Լ�
	void QuickSort(int nStart, int nEnd);
	// ���� ���� �߽����� ū ���� ���� ������ ������ �Լ�
	int Partition(int nStart, int nEnd);
	// �� �׸��� �� �ٲٴ� �Լ�
	void Swap(int nItem1, int nItem2);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExplorerListCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExplorerListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CExplorerListCtrl)
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPLORERLISTCTRL_H__B9891EB5_2BD1_432E_AE17_43F221FCA12D__INCLUDED_)
