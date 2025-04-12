// ListSortDemoDlg.h : 헤더 파일
//

#pragma once

// 정렬 기능을 갖는 리스트 컨트롤 헤더 파일
#include "FlatListCtrl.h"


// CListSortDemoDlg 대화 상자
class CListSortDemoDlg : public CDialog
{
// 생성
public:
	CListSortDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CListSortDemoDlg)
	enum { IDD = IDD_LISTSORTDEMO_DIALOG };
	CFlatListCtrl	m_FlatList;
	CString	m_strName;
	CString	m_strAge;
	CString	m_strAddr;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CListSortDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CListSortDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
