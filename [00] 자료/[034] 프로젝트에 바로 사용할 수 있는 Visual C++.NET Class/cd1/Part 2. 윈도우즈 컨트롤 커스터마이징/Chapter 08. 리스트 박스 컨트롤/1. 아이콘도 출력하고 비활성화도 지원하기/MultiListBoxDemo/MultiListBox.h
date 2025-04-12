#if !defined(AFX_MULTILISTBOX_H__359ECE87_65AA_4D7A_8D43_92CE69F75DFF__INCLUDED_)
#define AFX_MULTILISTBOX_H__359ECE87_65AA_4D7A_8D43_92CE69F75DFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MultiListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMultiListBox window

// �׸��� ������ ����ü
typedef struct _LBDATA
{
	BOOL bEnable;
	int nImage;
} LBDATA, *LPLBDATA;


// �̹����� ��Ȱ��ȭ ���� ����Ʈ �ڽ� ��Ʈ�� Ŭ����
class CMultiListBox : public CDragListBox
{
// Construction
public:
	CMultiListBox();

// Attributes
public:
	CImageList		*m_pImageList;				// ����Ʈ �ڽ����� ����� �̹��� ����Ʈ
	CSize			m_szImage;					// �̹��� ����Ʈ�� �̹��� ũ��

	COLORREF		m_clrBkgnd;					// ���õ��� ���� ������ ��� ����
	COLORREF		m_clrSelected;				// ���õ� ������ ��� ����
	COLORREF		m_clrText;					// �ؽ�Ʈ ����

// Operations
public:
	// �̹��� ����Ʈ ���� �Լ�
	void SetImageList(CImageList *pImageList);

	// ���ο� �׸��� �߰��ϴ� �Լ�
	int AddString(LPCTSTR lpszItem, int nImage = -1);
	// ���ο� �׸��� Ư�� ��ġ�� �߰��ϴ� �Լ�
	int InsertString(int nIndex, LPCTSTR lpszItem, int nImage = -1);
	// Ư�� �׸��� �����ϴ� �Լ�
	int DeleteString(int nIndex);
	// ��� �׸��� �����ϴ� �Լ�
	void ResetContent();

	// Ư�� �׸��� �̹��� ��ȣ�� �����ϴ� �Լ�
	int GetImage(int nIndex);
	// Ư�� �׸��� �̹��� ��ȣ�� �����ϴ� �Լ�
	int SetImage(int nIndex, int nImage);

	// Ư�� �׸��� Ȱ��ȭ �������� �����ϴ� �Լ�
	BOOL IsEnabled(int nIndex);
	// Ư�� �׸��� Ȱ��ȭ ��Ű�ų� ��Ȱ��ȭ ��Ű�� �Լ�
	BOOL EnableString(int nIndex, BOOL bEnable = TRUE);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiListBox)
	public:
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMultiListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMultiListBox)
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTILISTBOX_H__359ECE87_65AA_4D7A_8D43_92CE69F75DFF__INCLUDED_)
