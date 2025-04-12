#if !defined(AFX_AUTOTABCTRL_H__DD9BD036_0891_4B9D_92CA_D7240724D3F4__INCLUDED_)
#define AFX_AUTOTABCTRL_H__DD9BD036_0891_4B9D_92CA_D7240724D3F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AutoTabCtrl.h : header file
//

// CArray를 사용하기 위한 헤더 파일
#include <afxtempl.h>

// 자동 탭에서 부모 다이얼로그에게 보내는 메시지 정의
#define WM_AT_SELCHANGING		(WM_USER + 1)	// 선택 탭이 변경됨을 알리는 메시지
#define WM_AT_SELCHANGE			(WM_USER + 2)	// 선택 탭이 변경되었음을 알리는 메시지


// 자동 탭에서 탭에 속하는 컨트롤을 관리하는 클래스
class CControlContainer
{
	// 탭에 속하는 컨트롤의 윈도우 포인터 배열
	CArray<CWnd*, CWnd*>	m_Controls;
	// 현재 보이는 탭인지 여부
	BOOL					m_bShow;

public:
	// 생성자
	CControlContainer();
	// 소멸자
	virtual ~CControlContainer();

	// 컨테이너에 컨트롤을 추가하는 함수
	int AddControl(CWnd *pCtrl);
	// 컨테이너의 컨트롤들을 보이거나 감추는 함수
	void ShowControls(BOOL bShow = TRUE);
};

/////////////////////////////////////////////////////////////////////////////
// CAutoTabCtrl window

// 자동으로 컨트롤을 관리하는 탭 컨트롤 클래스
class CAutoTabCtrl : public CTabCtrl
{
// Construction
public:
	CAutoTabCtrl();

// Attributes
public:
	// 탭 컨트롤의 탭에 대한 컨테이너 배열
	CArray<CControlContainer*, CControlContainer*>	m_Containers;

// Operations
public:
	// 특정 탭을 선택하는 함수
	int SetCurSel(int nItem);
	// 특정 탭에 컨트롤을 추가하는 함수
	BOOL AddControl(int nTab, CWnd *pWnd);

	// 새로운 탭을 생성하는 함수
	BOOL InsertItem(int nItem, TCITEM* pTabCtrlItem);
	// 새로운 탭을 생성하는 함수
	BOOL InsertItem(int nItem, LPCTSTR lpszItem);
	// 새로운 탭을 생성하는 함수
	BOOL InsertItem(int nItem, LPCTSTR lpszItem, int nImage);
	// 새로운 탭을 생성하는 함수
	BOOL InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam);
	// 특정 탭을 삭제하는 함수
	BOOL DeleteItem(int nItem);
	// 모든 탭을 삭제하는 함수
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
