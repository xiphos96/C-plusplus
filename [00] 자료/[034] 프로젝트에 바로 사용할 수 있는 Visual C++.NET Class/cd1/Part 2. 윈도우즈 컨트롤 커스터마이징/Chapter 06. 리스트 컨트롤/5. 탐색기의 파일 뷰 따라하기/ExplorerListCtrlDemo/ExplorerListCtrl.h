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


// 탐색기 리스트 컨트롤 클래스
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
	// 현재 드라이브를 변경하는 함수
	void ChangeDrive(LPCTSTR pDrive);
	// 현재 폴더를 변경하는 함수
	void ChangeFolder(LPCTSTR pFolder);
	// 한단계 위의 폴더로 이동하는 함수
	BOOL GoUp();
	// 탐색기 리스트 컨트롤에서 폴더만을 보여주도록 설정하는 함수
	void SetFolderOnly(BOOL bOnly);

	// 현재 선택된 항목이 폴더인지 리턴하는 함수
	BOOL IsFolder();
	// 현재 선택된 항목이 파일인지 리턴하는 함수
	BOOL IsFile();
	// 현재 선택된 폴더의 경로를 리턴하는 함수
	BOOL GetSelectedFolder(CString &strFolder);
	// 현재 선택된 파일의 경로를 리턴하는 함수
	BOOL GetSelectedFile(CString &strFile);

	// 탐색기 리스트 컨트롤을 다시 구성하는 함수
	void RefreshExplorer();
	// 특정 파일이나 폴더의 시스템 아이콘 번호를 리턴하는 함수
	int FindIconIndex(LPCTSTR pName, BOOL bIsDirectory);

	// 정렬 함수
	void Sort();
	void Sort(BOOL bAscending, BOOL bExt);
	// 퀵정렬 함수
	void QuickSort(int nStart, int nEnd);
	// 기준 값을 중심으로 큰 값과 작은 값으로 나누는 함수
	int Partition(int nStart, int nEnd);
	// 두 항목을 맞 바꾸는 함수
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
