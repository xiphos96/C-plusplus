#if !defined(AFX_FONTCOMBOBOX_H__988381E4_CC46_4A37_B4D3_100FF10378A7__INCLUDED_)
#define AFX_FONTCOMBOBOX_H__988381E4_CC46_4A37_B4D3_100FF10378A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FontComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFontComboBox window

// 폰트에 대한 정보 구조체
typedef struct _FontTypeInfo
{
	CFont	Font;							// 폰트 객체
	int		nFontType;						// 폰트의 종류
} FONTTYPEINFO, *LPFONTTYPEINFO;


// 폰트 콤보 박스 컨트롤 클래스
class CFontComboBox : public CComboBox
{
// Construction
public:
	CFontComboBox();

// Attributes
public:
	COLORREF		m_clrBkgnd;						// 보통 상태의 항목 배경색
	COLORREF		m_clrSelected;					// 선택된 상태의 항목 배경색
	COLORREF		m_clrText;						// 텍스트 색상
	COLORREF		m_clrTextDisabled;				// 비활성화 텍스트 색상

	CImageList		m_TypeImageList;				// 폰트 종류를 표시하는 이미지 리스트

// Operations
public:
	// 현재 선택된 폰트의 포인터를 리턴하는 함수
	CFont* GetCurrentFont();
	// 현재 선택된 폰트의 이름을 리턴하는 함수
	void GetCurrentFont(CString &strFontName);
	// 현재 선택된 폰트의 LOGFONT 정보를 리턴하는 함수
	void GetLogFont(LOGFONT *pLogFont);
	// 특정 폰트를 선택하는 함수
	int SelectFont(LPCTSTR pFontName);

	// 시스템의 폰트를 찾는 정적 함수
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
