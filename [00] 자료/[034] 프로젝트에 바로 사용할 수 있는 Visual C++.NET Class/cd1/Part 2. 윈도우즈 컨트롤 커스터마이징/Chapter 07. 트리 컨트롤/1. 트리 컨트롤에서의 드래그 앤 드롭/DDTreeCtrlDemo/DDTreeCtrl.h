#if !defined(AFX_DDTREECTRL_H__8206715C_1724_4D65_87C8_BD5A07E6C9DB__INCLUDED_)
#define AFX_DDTREECTRL_H__8206715C_1724_4D65_87C8_BD5A07E6C9DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DDTreeCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDDTreeCtrl window

// CArray�� ����ϱ� ���� ��� ����
#include "afxtempl.h"

// ��ӵǴ� �׸� ���� ���� ����ü
struct SDropItemInfo
{
	HTREEITEM	hItem;								// ��� �׸� �ڵ�
	CString		strItem;							// ��� �׸� �ؽ�Ʈ
	TVITEM		tvItem;								// ��� �׸� ����
	CArray<SDropItemInfo*, SDropItemInfo*>	Childs;	// ��� �׸��� ���� �׸��

	SDropItemInfo()		{ hItem = NULL; }
	~SDropItemInfo()
	{
		// ���� �׸�鿡 ���� �������� �����Ѵ�
		int i, nSize = (int)Childs.GetSize();
		for(i = 0; i < nSize; i++)
		{
			delete Childs.GetAt(i);
		}
		Childs.RemoveAll();
	}
};


// �巡�� �� ��� Ʈ�� ��Ʈ�� Ŭ����
class CDDTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CDDTreeCtrl();

// Attributes
public:
	BOOL			m_bDragging;			// ���� �巡�� ������ ����
	CImageList		*m_pDragImage;			// �巡�� �̹����� ���� �̹��� ����Ʈ ������
	HTREEITEM		m_hDragNode;			// �巡�׵Ǵ� �׸� �ڵ�
	HTREEITEM		m_hDropNode;			// ��ӵǴ� �׸� �ڵ�
	CTreeCtrl		*m_pDropTree;			// ��ӵǴ� Ʈ�� ��Ʈ�� ������

	HCURSOR			m_hDragCursor;

// Operations
public:
	// �̹��� �������� ����� �׸� �簢 ���� ȹ�� �Լ�
	void GetItemRect(HTREEITEM hItem, LPRECT lpRect);

	// �巡�� �̹����� �����ϴ� �Լ�
	CImageList* CreateDragImageEx(LPPOINT lpPoint);
	// �巡�׵Ǵ� ���� �׸��� ã�� �Լ�
	void CreateDragImageLoop(HTREEITEM hParent, CRect &rcClient, CRect &rcSelected,
		CArray<HTREEITEM, HTREEITEM> &ItemArray);

	// ���õ� �׸��� ��� ��� Ʈ�� ��Ʈ�ѿ� �ű�� �Լ�
	void DropItems();
	// ��ӵ� ���� �׸���� ������ ���ϴ� �Լ�
	void FindDropTarget(SDropItemInfo *pParent);
	// ��� Ʈ�� ��Ʈ�ѿ� ���� �׸���� �߰��ϴ� �Լ�
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
