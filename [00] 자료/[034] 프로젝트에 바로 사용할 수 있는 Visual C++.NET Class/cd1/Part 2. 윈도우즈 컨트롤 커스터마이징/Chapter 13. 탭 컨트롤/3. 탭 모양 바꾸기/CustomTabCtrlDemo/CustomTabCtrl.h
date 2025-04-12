#if !defined(AFX_CUSTOMTABCTRL_H__2D6E4273_A3DE_4118_8CE5_AAC9F2C07763__INCLUDED_)
#define AFX_CUSTOMTABCTRL_H__2D6E4273_A3DE_4118_8CE5_AAC9F2C07763__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomTabCtrl.h : header file
//

// CArray�� ����ϱ� ���� ��� ����
#include <afxtempl.h>

// ����� ���� �ǿ��� �θ� ���̾�α׿��� ������ �޽��� ����
#define WM_OT_SELCHANGING		(WM_USER + 1)	// ���� ���� ������� �˸��� �޽���
#define WM_OT_SELCHANGE			(WM_USER + 2)	// ���� ���� ����Ǿ����� �˸��� �޽���

class CCustomTabCtrl;


// ����� ���� �ǿ��� �ǿ� ���ϴ� ��Ʈ���� �����ϴ� Ŭ����
class CControlContainer
{
	// �ǿ� ���ϴ� ��Ʈ���� ������ ������ �迭
	CArray<CWnd*, CWnd*>	m_Controls;
	// ���� ���̴� ������ ����
	BOOL					m_bShow;

public:
	// ������
	CControlContainer();
	// �Ҹ���
	virtual ~CControlContainer();

	// �����̳ʿ� ��Ʈ���� �߰��ϴ� �Լ�
	int AddControl(CWnd *pCtrl);
	// �����̳��� ��Ʈ�ѵ��� ���̰ų� ���ߴ� �Լ�
	void ShowControls(BOOL bShow = TRUE);
};


/////////////////////////////////////////////////////////////////////////////
// CCustomTabCtrl window

// ����� ���� �� ��Ʈ�� Ŭ����
class CCustomTabCtrl : public CTabCtrl
{
// Construction
public:
	CCustomTabCtrl();

// Attributes
public:
	// �� ��ư�� ������� ����� ��Ʈ�� ��ü��
	CBitmap			m_bmpTabBkgndLeft;
	CBitmap			m_bmpTabBkgndCenter;
	CBitmap			m_bmpTabBkgndRight;
	// �� ��ư ��Ʈ�ʵ��� ��Ʈ�� ���� 
	BITMAP			m_infoTabBkgndLeft;
	BITMAP			m_infoTabBkgndCenter;
	BITMAP			m_infoTabBkgndRight;

	COLORREF		m_clrButtonText;			// ��ư�� �ؽ�Ʈ ����
	COLORREF		m_clrButtonFace;			// ��ư�� �� ����
	COLORREF		m_clrButtonLight;			// ��ư�� ���� ����
	COLORREF		m_clrButtonShadow;			// ��ư�� ��ο� ����
	CPen			m_penButtonLight;			// ��ư�� ������ ��
	CPen			m_penButtonShadow;			// ��ư�� ��ο�� ��

	CPen			m_penBorder;				// ���� �� ���� �׵θ� ��
	COLORREF		m_clrBorder;				// ���� �� ���� �׵θ� ����
	COLORREF		m_clrBkgnd;					// ���� ��� ����

	CRect			m_rcClient;					// ���� ��ü Ŭ���̾�Ʈ ����
	CRect			m_rcView;					// ���� �� ����

	int				m_nHoverItem;				// ���� ���콺�� ��ġ�� �׸� ��ȣ

	// �� ��Ʈ���� �ǿ� ���� �����̳� �迭
	CArray<CControlContainer*, CControlContainer*>	m_Containers;

// Operations
public:
	// Ư�� ���� �ؽ�Ʈ�� �̹��� ��ȣ�� �����ϴ� �Լ�
	int GetTabText(int nItem, CString &strText);
	// ���� �߰��� �ǰ� �̹����� ����Ͽ� �� ��ư�� ����� ����ϴ� �Լ�
	void RecalcTabSize();

	// �� ��ư ��Ʈ�� �ڵ��� �����ϴ� �Լ�
	HBITMAP GetTabLeftBmp()			{ return (HBITMAP)m_bmpTabBkgndLeft; }
	HBITMAP GetTabCenterBmp()		{ return (HBITMAP)m_bmpTabBkgndCenter; }
	HBITMAP GetTabRightBmp()		{ return (HBITMAP)m_bmpTabBkgndRight; }
	// �� ��ư ��Ʈ���� �����ϴ� �Լ�
	void SetTabBmp(UINT nLeftID, UINT nCenterID, UINT nRightID);
	// �̹��� ����Ʈ�� �����ϴ� �Լ�
	CImageList* SetImageList(CImageList * pImageList);

	// ��ư�� �ؽ�Ʈ ������ ����/�����ϴ� �Լ�
	COLORREF GetButtonTextColor()	{ return m_clrButtonText; }
	void SetButtonTextColor(COLORREF clrText);
	// ��ư�� �� ������ ����/�����ϴ� �Լ�
	COLORREF GetButtonFaceColor()	{ return m_clrButtonFace; }
	void SetButtonFaceColor(COLORREF clrFace);
	// ��ư�� ���� ������ ����/�����ϴ� �Լ�
	COLORREF GetButtonLightColor()	{ return m_clrButtonLight; }
	void SetButtonLightColor(COLORREF clrLight);
	// ��ư�� ��ο� ������ ����/�����ϴ� �Լ�
	COLORREF GetButtonShadowColor()	{ return m_clrButtonShadow; }
	void SetButtonShadowColor(COLORREF clrShadow);
	// ���� �� ���� �׵θ� ������ ����/�����ϴ� �Լ�
	COLORREF GetBorderColor()		{ return m_clrBorder; }
	void SetBorderColor(COLORREF clrBorder);
	// ���� ��� ������ ����/�����ϴ� �Լ�
	COLORREF GetBkgndColor()		{ return m_clrBkgnd; }
	void SetBkgndColor(COLORREF clrBkgnd);

	// Ư�� �� ��ư�� �׸��� �Լ�
	void DrawTab(int nItem, CDC *pDC);

	// Ư�� ���� �����ϴ� �Լ�
	int SetCurSel(int nItem);
	// Ư�� �ǿ� ��Ʈ���� �߰��ϴ� �Լ�
	BOOL AddControl(int nTab, CWnd *pWnd);

	// ���ο� ���� �����ϴ� �Լ�
	BOOL InsertItem(int nItem, TCITEM* pTabCtrlItem);
	// ���ο� ���� �����ϴ� �Լ�
	BOOL InsertItem(int nItem, LPCTSTR lpszItem);
	// ���ο� ���� �����ϴ� �Լ�
	BOOL InsertItem(int nItem, LPCTSTR lpszItem, int nImage);
	// ���ο� ���� �����ϴ� �Լ�
	BOOL InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam);
	// Ư�� ���� �����ϴ� �Լ�
	BOOL DeleteItem(int nItem);
	// ��� ���� �����ϴ� �Լ�
	BOOL DeleteAllItems();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomTabCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomTabCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomTabCtrl)
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMTABCTRL_H__2D6E4273_A3DE_4118_8CE5_AAC9F2C07763__INCLUDED_)
