#if !defined(AFX_DDTREECTRL_H__8206715C_1724_4D65_87C8_BD5A07E6C9DB__INCLUDED_)
#define AFX_DDTREECTRL_H__8206715C_1724_4D65_87C8_BD5A07E6C9DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DDTreeCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDDTreeCtrl window

// CArray를 사용하기 위한 헤더 파일
#include "afxtempl.h"

// 드롭되는 항목에 대한 정보 구조체
struct SDropItemInfo
{
	HTREEITEM	hItem;								// 드롭 항목 핸들
	CString		strItem;							// 드롭 항목 텍스트
	TVITEM		tvItem;								// 드롭 항목 정보
	CArray<SDropItemInfo*, SDropItemInfo*>	Childs;	// 드롭 항목의 하위 항목들

	SDropItemInfo()		{ hItem = NULL; }
	~SDropItemInfo()
	{
		// 하위 항목들에 대한 정보들을 삭제한다
		int i, nSize = (int)Childs.GetSize();
		for(i = 0; i < nSize; i++)
		{
			delete Childs.GetAt(i);
		}
		Childs.RemoveAll();
	}
};


// 드래그 앤 드롭 트리 컨트롤 클래스
class CDDTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CDDTreeCtrl();

// Attributes
public:
	BOOL			m_bDragging;			// 현재 드래그 중인지 여부
	CImageList		*m_pDragImage;			// 드래그 이미지에 대한 이미지 리스트 포인터
	HTREEITEM		m_hDragNode;			// 드래그되는 항목 핸들
	HTREEITEM		m_hDropNode;			// 드롭되는 항목 핸들
	CTreeCtrl		*m_pDropTree;			// 드롭되는 트리 컨트롤 포인터

	HCURSOR			m_hDragCursor;

// Operations
public:
	// 이미지 영역까지 고려한 항목 사각 영역 획득 함수
	void GetItemRect(HTREEITEM hItem, LPRECT lpRect);

	// 드래그 이미지를 생성하는 함수
	CImageList* CreateDragImageEx(LPPOINT lpPoint);
	// 드래그되는 하위 항목을 찾는 함수
	void CreateDragImageLoop(HTREEITEM hParent, CRect &rcClient, CRect &rcSelected,
		CArray<HTREEITEM, HTREEITEM> &ItemArray);

	// 선택된 항목을 드롭 대상 트리 컨트롤에 옮기는 함수
	void DropItems();
	// 드롭될 하위 항목들의 정보를 구하는 함수
	void FindDropTarget(SDropItemInfo *pParent);
	// 드롭 트리 컨트롤에 하위 항목들을 추가하는 함수
	void AddDropItem(HTREEITEM hParent, SDropItemInfo *pNew);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDDTreeCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDDTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDDTreeCtrl)
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDTREECTRL_H__8206715C_1724_4D65_87C8_BD5A07E6C9DB__INCLUDED_)
