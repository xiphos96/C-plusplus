#if !defined(AFX_FONTCOMBOBOX_H__988381E4_CC46_4A37_B4D3_100FF10378A7__INCLUDED_)
#define AFX_FONTCOMBOBOX_H__988381E4_CC46_4A37_B4D3_100FF10378A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FontComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFontComboBox window

// ��Ʈ�� ���� ���� ����ü
typedef struct _FontTypeInfo
{
	CFont	Font;							// ��Ʈ ��ü
	int		nFontType;						// ��Ʈ�� ����
} FONTTYPEINFO, *LPFONTTYPEINFO;


// ��Ʈ �޺� �ڽ� ��Ʈ�� Ŭ����
class CFontComboBox : public CComboBox
{
// Construction
public:
	CFontComboBox();

// Attributes
public:
	COLORREF		m_clrBkgnd;						// ���� ������ �׸� ����
	COLORREF		m_clrSelected;					// ���õ� ������ �׸� ����
	COLORREF		m_clrText;						// �ؽ�Ʈ ����
	COLORREF		m_clrTextDisabled;				// ��Ȱ��ȭ �ؽ�Ʈ ����

	CImageList		m_TypeImageList;				// ��Ʈ ������ ǥ���ϴ� �̹��� ����Ʈ

// Operations
public:
	// ���� ���õ� ��Ʈ�� �����͸� �����ϴ� �Լ�
	CFont* GetCurrentFont();
	// ���� ���õ� ��Ʈ�� �̸��� �����ϴ� �Լ�
	void GetCurrentFont(CString &strFontName);
	// ���� ���õ� ��Ʈ�� LOGFONT ������ �����ϴ� �Լ�
	void GetLogFont(LOGFONT *pLogFont);
	// Ư�� ��Ʈ�� �����ϴ� �Լ�
	int SelectFont(LPCTSTR pFontName);

	// �ý����� ��Ʈ�� ã�� ���� �Լ�
	static int CALLBACK EnumFontProc(ENUMLOGFONTEX *lpelfe,NEWTEXTMETRICEX *lpntme,int FontType,LPARAM lParam);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontComboBox)
	public:
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFontComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFontComboBox)
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTCOMBOBOX_H__988381E4_CC46_4A37_B4D3_100FF10378A7__INCLUDED_)
