#if !defined(AFX_DDLISTCTRL_H__B607CB62_8D35_4B2A_8DB6_1F3C82D87A1A__INCLUDED_)
#define AFX_DDLISTCTRL_H__B607CB62_8D35_4B2A_8DB6_1F3C82D87A1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DDListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDDListCtrl window

// 드롭되는 항목에 대한 정보 구조체
struct SDropItemInfo
{
	int		nItem;
	CString strItem;
	LVITEM	lvItem;
};


// 드래그 앤 드롭 리스트 컨트롤 클래스
class CDDListCtrl : public CListCtrl
{
// Construction
public:
	CDDListCtrl();

// Attributes
public:
	BOOL			m_bDragging;			// 현재 드래그 중인지 여부
	CImageList		*m_pDragImage;			// 드래그 이미지에 대한 이미지 리스트 포인터
	int				m_nDropIndex;			// 드롭되는 위치
	CListCtrl		*m_pDropList;			// 드롭되는 리스트 컨트롤 포인터

// Operations
public:
	// 드래그 이미지를 생성하는 함수
	CImageList* CreateDragImageEx(LPPOINT lpPoint);
	// 선택된 항목을 드롭 대상 리스트 컨트롤에 옮기는 함수
	void DropItems();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDDListCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDDListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDDListCtrl)
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDLISTCTRL_H__B607CB62_8D35_4B2A_8DB6_1F3C82D87A1A__INCLUDED_)
