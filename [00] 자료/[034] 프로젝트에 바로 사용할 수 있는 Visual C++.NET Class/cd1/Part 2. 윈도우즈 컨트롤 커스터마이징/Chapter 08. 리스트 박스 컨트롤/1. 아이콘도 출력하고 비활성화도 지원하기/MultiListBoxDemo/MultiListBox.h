#if !defined(AFX_MULTILISTBOX_H__359ECE87_65AA_4D7A_8D43_92CE69F75DFF__INCLUDED_)
#define AFX_MULTILISTBOX_H__359ECE87_65AA_4D7A_8D43_92CE69F75DFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MultiListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMultiListBox window

// 항목의 데이터 구조체
typedef struct _LBDATA
{
	BOOL bEnable;
	int nImage;
} LBDATA, *LPLBDATA;


// 이미지와 비활성화 지원 리스트 박스 컨트롤 클래스
class CMultiListBox : public CDragListBox
{
// Construction
public:
	CMultiListBox();

// Attributes
public:
	CImageList		*m_pImageList;				// 리스트 박스에서 사용할 이미지 리스트
	CSize			m_szImage;					// 이미지 리스트의 이미지 크기

	COLORREF		m_clrBkgnd;					// 선택되지 않은 상태의 배경 색상
	COLORREF		m_clrSelected;				// 선택된 상태의 배경 색상
	COLORREF		m_clrText;					// 텍스트 색상

// Operations
public:
	// 이미지 리스트 설정 함수
	void SetImageList(CImageList *pImageList);

	// 새로운 항목을 추가하는 함수
	int AddString(LPCTSTR lpszItem, int nImage = -1);
	// 새로운 항목을 특정 위치에 추가하는 함수
	int InsertString(int nIndex, LPCTSTR lpszItem, int nImage = -1);
	// 특정 항목을 삭제하는 함수
	int DeleteString(int nIndex);
	// 모든 항목을 삭제하는 함수
	void ResetContent();

	// 특정 항목의 이미지 번호를 리턴하는 함수
	int GetImage(int nIndex);
	// 특정 항목의 이미지 번호를 설정하는 함수
	int SetImage(int nIndex, int nImage);

	// 특정 항목이 활성화 상태인지 리턴하는 함수
	BOOL IsEnabled(int nIndex);
	// 특정 항목을 활성화 시키거나 비활성화 시키는 함수
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
