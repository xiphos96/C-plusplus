#if !defined(AFX_EXPLORERTREECTRL_H__5A1288CF_5884_481B_8FE7_E72A1249B195__INCLUDED_)
#define AFX_EXPLORERTREECTRL_H__5A1288CF_5884_481B_8FE7_E72A1249B195__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExplorerTreeCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExplorerTreeCtrl window

// 디렉토리가 갖는 정보 구조체
typedef struct
{
	LPSHELLFOLDER	pParentFolder;		// 쉘 폴더 인터페이스
	LPITEMIDLIST	pIDList;			// 현재 디렉토리에 대한 PIDL
	LPITEMIDLIST	pFQIDList;			// 현재 디렉토리까지의 완전한 PIDL
} TVITEMDATA, *LPTVITEMDATA;


// 디렉토리 트리 컨트롤 클래스
class CExplorerTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CExplorerTreeCtrl();

// Attributes
public:
	LPMALLOC		m_pMalloc;			// 메모리 관리자 포인터

// Operations
public:
	// 새로운 디렉토리를 트리에 추가하는 함수
	HTREEITEM InsertFolderItem(HTREEITEM hParent, HTREEITEM hPrev,
		LPSHELLFOLDER pFolder, LPITEMIDLIST pFQIDList, LPITEMIDLIST pIDList);
	// 특정 디렉토리의 하위 디렉토리들을 삭제하는 함수
	int DeleteChildFolder(HTREEITEM hItem);

	// 특정 트리 항목의 경로를 리턴하는 함수
	void GetPath(HTREEITEM hItem, CString &strPath);
	// 특정 트리 항목의 경로를 리턴하는 함수
	LPSTR GetPath(HTREEITEM hItem);
	// 현재 선택된 트리 항목의 경로를 리턴하는 함수
	void GetSelectedPath(CString &strPath);
	// 현재 선택된 트리 항목의 경로를 리턴하는 함수
	LPSTR GetSelectedPath();

	// 특정 경로에 해당하는 트리 항목을 선택하는 함수
	BOOL SelectPath(LPCTSTR pPath);
	// 특정 트리 항목의 하위 항목에서 특정 텍스트를 갖는 항목을 찾는 함수
	HTREEITEM SearchChildFolder(HTREEITEM hParent, LPCTSTR pFolderName, BOOL bRoot);

	// PIDL에서 디렉토리 이름을 리턴하는 함수
	void GetFriendlyName(LPSHELLFOLDER pFolder, LPITEMIDLIST pIDList, LPSTR pName);
	// 두 PIDL을 합치는 함수
	LPITEMIDLIST UnionIDL(LPITEMIDLIST pIDList1, LPITEMIDLIST pIDList2);
	// 특정 PIDL과 동일한 PIDL을 생성하는 함수
	LPITEMIDLIST DuplicateIDL(LPITEMIDLIST pSource);
	// 특정 PIDL의 크기를 구하는 함수
	UINT GetIDLSize(LPITEMIDLIST pIDList);

	// 트리의 항목을 정렬하는 함수
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
