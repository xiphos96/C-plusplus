#if !defined(AFX_FLATLISTCTRL_H__C532D6FC_E7AF_4A2C_BED1_9A3C2935CA00__INCLUDED_)
#define AFX_FLATLISTCTRL_H__C532D6FC_E7AF_4A2C_BED1_9A3C2935CA00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlatListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFlatListCtrl window

// 평면 헤더 컨트롤 헤더
#include "FlatHeaderCtrl.h"


class CFlatListCtrl : public CListCtrl
{
// Construction
public:
	CFlatListCtrl();

// Attributes
public:
	// 평면 헤더 컨트롤 멤버 변수
	CFlatHeaderCtrl		m_wndHeaderCtrl;
	// 평면 헤더 컨트롤에 사용할 이미지 리스트
	CImageList			m_ImageList;

	int					m_nSortColumn;		// 정렬의 기준 컬럼 번호
	BOOL				m_bSortAscending;	// 정렬 방향(오름차순, 내림차순)

// Operations
public:
	// 평면 헤더 컨트롤에 사용할 이미지 리스트 설정 함수
	void SetHeaderImage(UINT nBitmap, int cx, int nGrow);

	// 컬럼 추가 처리 함수
	int InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat = LVCFMT_LEFT, int nWidth = -1, int nSubItem = -1);
	// 항목 추가 처리 함수
	int InsertItem(const LVITEM* pItem);
	int InsertItem(int nItem, LPCTSTR lpszItem);
	int InsertItem(int nItem, LPCTSTR lpszItem, int nImage);
	int InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, UINT nState, UINT nStateMask, int nImage, LPARAM lParam);

	// 정렬 함수
	void Sort(int *pNew = NULL);
	void Sort(int nColumn, BOOL bAscending, int *pNew = NULL);
	// 퀵정렬 함수
	void QuickSort(int nStart, int nEnd, int *pNew = NULL);
	// 기준 값을 중심으로 큰 값과 작은 값으로 나누는 함수
	int Partition(int nStart, int nEnd, int *pNew = NULL);
	// 두 항목을 맞 바꾸는 함수
	void Swap(int nItem1, int nItem2);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlatListCtrl)
	protected:
	virtual void PreSubclassWindow();
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL
	virtual int OnToolHitTest(CPoint point, TOOLINFO * pTI) const;

// Implementation
public:
	virtual ~CFlatListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFlatListCtrl)
	afx_msg void OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	afx_msg BOOL OnNeedText(UINT id, NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLATLISTCTRL_H__C532D6FC_E7AF_4A2C_BED1_9A3C2935CA00__INCLUDED_)
