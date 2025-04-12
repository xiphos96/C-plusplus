#if !defined(AFX_DDLISTCTRL_H__B607CB62_8D35_4B2A_8DB6_1F3C82D87A1A__INCLUDED_)
#define AFX_DDLISTCTRL_H__B607CB62_8D35_4B2A_8DB6_1F3C82D87A1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DDListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDDListCtrl window

// ��ӵǴ� �׸� ���� ���� ����ü
struct SDropItemInfo
{
	int		nItem;
	CString strItem;
	LVITEM	lvItem;
};


// �巡�� �� ��� ����Ʈ ��Ʈ�� Ŭ����
class CDDListCtrl : public CListCtrl
{
// Construction
public:
	CDDListCtrl();

// Attributes
public:
	BOOL			m_bDragging;			// ���� �巡�� ������ ����
	CImageList		*m_pDragImage;			// �巡�� �̹����� ���� �̹��� ����Ʈ ������
	int				m_nDropIndex;			// ��ӵǴ� ��ġ
	CListCtrl		*m_pDropList;			// ��ӵǴ� ����Ʈ ��Ʈ�� ������

// Operations
public:
	// �巡�� �̹����� �����ϴ� �Լ�
	CImageList* CreateDragImageEx(LPPOINT lpPoint);
	// ���õ� �׸��� ��� ��� ����Ʈ ��Ʈ�ѿ� �ű�� �Լ�
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
