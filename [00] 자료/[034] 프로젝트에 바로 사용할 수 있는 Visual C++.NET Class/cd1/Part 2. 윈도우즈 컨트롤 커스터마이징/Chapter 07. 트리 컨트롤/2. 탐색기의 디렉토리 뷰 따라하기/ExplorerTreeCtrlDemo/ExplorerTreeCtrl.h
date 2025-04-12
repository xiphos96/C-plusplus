#if !defined(AFX_EXPLORERTREECTRL_H__5A1288CF_5884_481B_8FE7_E72A1249B195__INCLUDED_)
#define AFX_EXPLORERTREECTRL_H__5A1288CF_5884_481B_8FE7_E72A1249B195__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExplorerTreeCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExplorerTreeCtrl window

// ���丮�� ���� ���� ����ü
typedef struct
{
	LPSHELLFOLDER	pParentFolder;		// �� ���� �������̽�
	LPITEMIDLIST	pIDList;			// ���� ���丮�� ���� PIDL
	LPITEMIDLIST	pFQIDList;			// ���� ���丮������ ������ PIDL
} TVITEMDATA, *LPTVITEMDATA;


// ���丮 Ʈ�� ��Ʈ�� Ŭ����
class CExplorerTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CExplorerTreeCtrl();

// Attributes
public:
	LPMALLOC		m_pMalloc;			// �޸� ������ ������

// Operations
public:
	// ���ο� ���丮�� Ʈ���� �߰��ϴ� �Լ�
	HTREEITEM InsertFolderItem(HTREEITEM hParent, HTREEITEM hPrev,
		LPSHELLFOLDER pFolder, LPITEMIDLIST pFQIDList, LPITEMIDLIST pIDList);
	// Ư�� ���丮�� ���� ���丮���� �����ϴ� �Լ�
	int DeleteChildFolder(HTREEITEM hItem);

	// Ư�� Ʈ�� �׸��� ��θ� �����ϴ� �Լ�
	void GetPath(HTREEITEM hItem, CString &strPath);
	// Ư�� Ʈ�� �׸��� ��θ� �����ϴ� �Լ�
	LPSTR GetPath(HTREEITEM hItem);
	// ���� ���õ� Ʈ�� �׸��� ��θ� �����ϴ� �Լ�
	void GetSelectedPath(CString &strPath);
	// ���� ���õ� Ʈ�� �׸��� ��θ� �����ϴ� �Լ�
	LPSTR GetSelectedPath();

	// Ư�� ��ο� �ش��ϴ� Ʈ�� �׸��� �����ϴ� �Լ�
	BOOL SelectPath(LPCTSTR pPath);
	// Ư�� Ʈ�� �׸��� ���� �׸񿡼� Ư�� �ؽ�Ʈ�� ���� �׸��� ã�� �Լ�
	HTREEITEM SearchChildFolder(HTREEITEM hParent, LPCTSTR pFolderName, BOOL bRoot);

	// PIDL���� ���丮 �̸��� �����ϴ� �Լ�
	void GetFriendlyName(LPSHELLFOLDER pFolder, LPITEMIDLIST pIDList, LPSTR pName);
	// �� PIDL�� ��ġ�� �Լ�
	LPITEMIDLIST UnionIDL(LPITEMIDLIST pIDList1, LPITEMIDLIST pIDList2);
	// Ư�� PIDL�� ������ PIDL�� �����ϴ� �Լ�
	LPITEMIDLIST DuplicateIDL(LPITEMIDLIST pSource);
	// Ư�� PIDL�� ũ�⸦ ���ϴ� �Լ�
	UINT GetIDLSize(LPITEMIDLIST pIDList);

	// Ʈ���� �׸��� �����ϴ� �Լ�
 	static int CALLBACK SortTreeProc(LPARAM lParam1, LPARAM lParam2, LPARAM lSortParam);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExplorerTreeCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExplorerTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CExplorerTreeCtrl)
	afx_msg void OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPLORERTREECTRL_H__5A1288CF_5884_481B_8FE7_E72A1249B195__INCLUDED_)
