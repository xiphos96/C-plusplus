#if !defined(AFX_CUSTOMPROPERTYSHEET_H__354A391E_3326_486F_983D_E3F713F81CA6__INCLUDED_)
#define AFX_CUSTOMPROPERTYSHEET_H__354A391E_3326_486F_983D_E3F713F81CA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomPropertySheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomPropertySheet

class CCustomPropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CCustomPropertySheet)

// Construction
public:
	CCustomPropertySheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CCustomPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	int m_nCX;									// ���ο� ������Ƽ ��Ʈ�� ��
	int m_nCY;									// ���ο� ������Ƽ ��Ʈ�� ����
	BOOL m_bUseSystemFont;						// �ý��� ��Ʈ ��� ����
	BOOL m_bResize;								// ũ�� ���� ���� ����
	CSize m_MinSize;							// �ּ� ũ��
	CSize m_MaxSize;							// �ִ� ũ��
	CRect m_rcSheet;							// ������Ƽ ��Ʈ�� ������ ũ��

	BOOL m_bInit;								// OnInitDialog ���� ����

// Operations
public:
	// ������Ƽ ��Ʈ�� ũ�⸦ �����ϴ� �Լ�
	void SetSheetSize(int cx, int cy);
	// ������Ƽ �������� ��Ʈ�� ���Ͻ�ų ������ �����ϴ� �Լ�
	void UseSystemFont(BOOL bSystemFont);
	// ������Ƽ ��Ʈ�� ũ�⸦ ������ �� �ֵ��� �����ϴ� �Լ�
	void SetResize(BOOL bResize, int nMinCX, int nMinCY, int nMaxCX, int nMaxCY);

	// ������Ƽ ���������� ��Ʈ �Ӽ��� ����ϱ� ���� ���� �Լ�
	virtual void BuildPropPageArray();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomPropertySheet)
	public:
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomPropertySheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomPropertySheet)
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMPROPERTYSHEET_H__354A391E_3326_486F_983D_E3F713F81CA6__INCLUDED_)
