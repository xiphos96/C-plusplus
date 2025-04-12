#if !defined(AFX_FILTEREDIT_H__9B281E0E_BE48_44BD_AB88_6D284EFD4109__INCLUDED_)
#define AFX_FILTEREDIT_H__9B281E0E_BE48_44BD_AB88_6D284EFD4109__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FilterEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFilterEdit window

// 필터 에디트 컨트롤에 설정 할 수 있는 모드
#define FILTER_NONE				0			// 필터 사용하지 않음
#define FILTER_NUMBER			1			// 숫자만 입력 가능
#define FILTER_SIGN				2			// 부호 문자('-')만 입력 가능
#define FILTER_SIGNEDNUMBER		3			// 부호 있는 숫자만 입력 가능
#define FILTER_DECIMALPOINT		4			// 소수점만 입력 가능
#define FILTER_REALNUMBER		7			// 실수만 입력 가능
#define FILTER_UPPERCASE		8			// 알파벳 대문자만 입력 가능
#define FILTER_LOWERCASE		16			// 알파벳 소문자만 입력 가능
#define FILTER_ALPHA			24			// 알파벳만 입력 가능
#define FILTER_ALNUM			25			// 알파벳과 숫자만 입력 가능
#define FILTER_CURRENCY			32			// 금액만 입력 가능
#define FILTER_DATE				64			// 날짜만 입력 가능
#define FILTER_TIME				128			// 시간만 입력 가능
#define FILTER_MASK				256			// 마스크에 설정된 대로만 입력 가능

#define FILTER_MASK_NUMBER		'#'			// 마스크에서 숫자 입력 자리 표시용 문자
#define FILTER_MASK_ALPHA		'$'			// 마스크에서 문자 입력 자리 표시용 문자

// 필터 에디트 컨트롤 클래스
class CFilterEdit : public CEdit
{
// Construction
public:
	CFilterEdit();

// Attributes
public:
	COLORREF		m_clrText;				// 텍스트 색상
	COLORREF		m_clrBkgnd;				// 배경 색상
	CBrush			m_brsBkgnd;				// 배경에 사용할 브러쉬

	int				m_nType;				// 필터로 사용할 모드
	CString			m_strMask;				// 필터로 사용할 마스크 문자열

	int				m_nDecPointPos;			// 현재 소수점의 위치

	CString			m_strCurrency;			// 현재 시스템의 화폐 단위 문자
	CString			m_strDateFormat;		// 날짜 입력시 사용할 마스크
	CString			m_strTimeFormat;		// 시간 입력시 사용할 마스크
	BOOL			m_bTime24;				// 24시 표기를 사용할 것인지 여부
	BOOL			m_bAmPm;				// 현재 오전인지 오후인지 여부

// Operations
public:
	// 현재 읽기 전용 모드인지 여부
	BOOL IsReadOnly()				{ return GetStyle() & ES_READONLY; }

	// 텍스트 색상을 리턴/설정하는 함수
	COLORREF GetTextColor()			{ return m_clrText; }
	void SetTextColor(COLORREF clrText);
	// 배경 색상을 리턴/설정하는 함수
	COLORREF GetBkgndColor()		{ return m_clrBkgnd; }
	void SetBkgndColor(COLORREF clrBkgnd);

	// 필터로 사용할 모드를 설정하는 함수들
	int SetFormat(int nFormat, BOOL bEraseAll = TRUE);
	int SetFormat(LPCTSTR pFormat, BOOL bEraseAll = TRUE);
	int SetDateFormat(LPCTSTR pFormat, BOOL bEraseAll = TRUE);
	int SetTimeFormat(LPCTSTR pFormat, BOOL bTime24 = FALSE, BOOL bEraseAll = TRUE);

protected:
	// 내부적으로 사용하는 유효성 검사 함수들
	inline BOOL IsValidChar(char ch, int n, int nRemain);
	void CheckText(CString &strInput, CString &strOutput);
	int CheckCurrency(CString &strInput, CString &strOutput, int nPos);
	int CheckDate(CString &strInput, CString &strOutput, int nPos);
	int CheckTime(CString &strInput, CString &strOutput, int nPos);
	int CheckFormat(CString &strInput, CString &strOutput, int nPos);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilterEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFilterEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFilterEdit)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	afx_msg LONG OnCut(UINT wParam, LONG lParam);
	afx_msg LRESULT OnPaste(UINT wParam, LONG lParam);
	afx_msg LONG OnClear(UINT wParam, LONG lParam);
	afx_msg LRESULT OnSetText(UINT wParam, LONG lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILTEREDIT_H__9B281E0E_BE48_44BD_AB88_6D284EFD4109__INCLUDED_)
