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
	int m_nCX;									// 새로운 프로퍼티 시트의 폭
	int m_nCY;									// 새로운 프로퍼티 시트의 높이
	BOOL m_bUseSystemFont;						// 시스템 폰트 사용 여부
	BOOL m_bResize;								// 크기 조절 가능 여부
	CSize m_MinSize;							// 최소 크기
	CSize m_MaxSize;							// 최대 크기
	CRect m_rcSheet;							// 프로퍼티 시트의 마지막 크기

	BOOL m_bInit;								// OnInitDialog 실행 여부

// Operations
public:
	// 프로퍼티 시트의 크기를 설정하는 함수
	void SetSheetSize(int cx, int cy);
	// 프로퍼티 페이지의 폰트를 통일시킬 것인지 설정하는 함수
	void UseSystemFont(BOOL bSystemFont);
	// 프로퍼티 시트의 크기를 조절할 수 있도록 설정하는 함수
	void SetResize(BOOL bResize, int nMinCX, int nMinCY, int nMaxCX, int nMaxCY);

	// 프로퍼티 페이지들의 폰트 속성을 사용하기 위한 가상 함수
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
