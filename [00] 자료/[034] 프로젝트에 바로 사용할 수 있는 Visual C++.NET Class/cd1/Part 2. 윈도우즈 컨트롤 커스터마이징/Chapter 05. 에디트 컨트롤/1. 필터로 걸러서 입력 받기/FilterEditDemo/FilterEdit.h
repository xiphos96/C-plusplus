#if !defined(AFX_FILTEREDIT_H__9B281E0E_BE48_44BD_AB88_6D284EFD4109__INCLUDED_)
#define AFX_FILTEREDIT_H__9B281E0E_BE48_44BD_AB88_6D284EFD4109__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FilterEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFilterEdit window

// ���� ����Ʈ ��Ʈ�ѿ� ���� �� �� �ִ� ���
#define FILTER_NONE				0			// ���� ������� ����
#define FILTER_NUMBER			1			// ���ڸ� �Է� ����
#define FILTER_SIGN				2			// ��ȣ ����('-')�� �Է� ����
#define FILTER_SIGNEDNUMBER		3			// ��ȣ �ִ� ���ڸ� �Է� ����
#define FILTER_DECIMALPOINT		4			// �Ҽ����� �Է� ����
#define FILTER_REALNUMBER		7			// �Ǽ��� �Է� ����
#define FILTER_UPPERCASE		8			// ���ĺ� �빮�ڸ� �Է� ����
#define FILTER_LOWERCASE		16			// ���ĺ� �ҹ��ڸ� �Է� ����
#define FILTER_ALPHA			24			// ���ĺ��� �Է� ����
#define FILTER_ALNUM			25			// ���ĺ��� ���ڸ� �Է� ����
#define FILTER_CURRENCY			32			// �ݾ׸� �Է� ����
#define FILTER_DATE				64			// ��¥�� �Է� ����
#define FILTER_TIME				128			// �ð��� �Է� ����
#define FILTER_MASK				256			// ����ũ�� ������ ��θ� �Է� ����

#define FILTER_MASK_NUMBER		'#'			// ����ũ���� ���� �Է� �ڸ� ǥ�ÿ� ����
#define FILTER_MASK_ALPHA		'$'			// ����ũ���� ���� �Է� �ڸ� ǥ�ÿ� ����

// ���� ����Ʈ ��Ʈ�� Ŭ����
class CFilterEdit : public CEdit
{
// Construction
public:
	CFilterEdit();

// Attributes
public:
	COLORREF		m_clrText;				// �ؽ�Ʈ ����
	COLORREF		m_clrBkgnd;				// ��� ����
	CBrush			m_brsBkgnd;				// ��濡 ����� �귯��

	int				m_nType;				// ���ͷ� ����� ���
	CString			m_strMask;				// ���ͷ� ����� ����ũ ���ڿ�

	int				m_nDecPointPos;			// ���� �Ҽ����� ��ġ

	CString			m_strCurrency;			// ���� �ý����� ȭ�� ���� ����
	CString			m_strDateFormat;		// ��¥ �Է½� ����� ����ũ
	CString			m_strTimeFormat;		// �ð� �Է½� ����� ����ũ
	BOOL			m_bTime24;				// 24�� ǥ�⸦ ����� ������ ����
	BOOL			m_bAmPm;				// ���� �������� �������� ����

// Operations
public:
	// ���� �б� ���� ������� ����
	BOOL IsReadOnly()				{ return GetStyle() & ES_READONLY; }

	// �ؽ�Ʈ ������ ����/�����ϴ� �Լ�
	COLORREF GetTextColor()			{ return m_clrText; }
	void SetTextColor(COLORREF clrText);
	// ��� ������ ����/�����ϴ� �Լ�
	COLORREF GetBkgndColor()		{ return m_clrBkgnd; }
	void SetBkgndColor(COLORREF clrBkgnd);

	// ���ͷ� ����� ��带 �����ϴ� �Լ���
	int SetFormat(int nFormat, BOOL bEraseAll = TRUE);
	int SetFormat(LPCTSTR pFormat, BOOL bEraseAll = TRUE);
	int SetDateFormat(LPCTSTR pFormat, BOOL bEraseAll = TRUE);
	int SetTimeFormat(LPCTSTR pFormat, BOOL bTime24 = FALSE, BOOL bEraseAll = TRUE);

protected:
	// ���������� ����ϴ� ��ȿ�� �˻� �Լ���
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
