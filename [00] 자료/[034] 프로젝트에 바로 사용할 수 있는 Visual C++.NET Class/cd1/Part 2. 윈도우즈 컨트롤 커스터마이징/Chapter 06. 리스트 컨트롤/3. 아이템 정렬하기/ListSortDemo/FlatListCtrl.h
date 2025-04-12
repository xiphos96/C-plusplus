#if !defined(AFX_FLATLISTCTRL_H__C532D6FC_E7AF_4A2C_BED1_9A3C2935CA00__INCLUDED_)
#define AFX_FLATLISTCTRL_H__C532D6FC_E7AF_4A2C_BED1_9A3C2935CA00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlatListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFlatListCtrl window

// ��� ��� ��Ʈ�� ���
#include "FlatHeaderCtrl.h"


class CFlatListCtrl : public CListCtrl
{
// Construction
public:
	CFlatListCtrl();

// Attributes
public:
	// ��� ��� ��Ʈ�� ��� ����
	CFlatHeaderCtrl		m_wndHeaderCtrl;
	// ��� ��� ��Ʈ�ѿ� ����� �̹��� ����Ʈ
	CImageList			m_ImageList;

	int					m_nSortColumn;		// ������ ���� �÷� ��ȣ
	BOOL				m_bSortAscending;	// ���� ����(��������, ��������)

// Operations
public:
	// ��� ��� ��Ʈ�ѿ� ����� �̹��� ����Ʈ ���� �Լ�
	void SetHeaderImage(UINT nBitmap, int cx, int nGrow);

	// �÷� �߰� ó�� �Լ�
	int InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat = LVCFMT_LEFT, int nWidth = -1, int nSubItem = -1);
	// �׸� �߰� ó�� �Լ�
	int InsertItem(const LVITEM* pItem);
	int InsertItem(int nItem, LPCTSTR lpszItem);
	int InsertItem(int nItem, LPCTSTR lpszItem, int nImage);
	int InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, UINT nState, UINT nStateMask, int nImage, LPARAM lParam);

	// ���� �Լ�
	void Sort(int *pNew = NULL);
	void Sort(int nColumn, BOOL bAscending, int *pNew = NULL);
	// ������ �Լ�
	void QuickSort(int nStart, int nEnd, int *pNew = NULL);
	// ���� ���� �߽����� ū ���� ���� ������ ������ �Լ�
	int Partition(int nStart, int nEnd, int *pNew = NULL);
	// �� �׸��� �� �ٲٴ� �Լ�
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
