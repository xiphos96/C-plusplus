#if !defined(AFX_SYMBOLDLG_H__38AB538F_4338_4A8E_84E5_EF08383D8504__INCLUDED_)
#define AFX_SYMBOLDLG_H__38AB538F_4338_4A8E_84E5_EF08383D8504__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SymbolDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSymbolDlg dialog

#include "SymbolChart.h"
#include "SymbolPreviewStatic.h"

// 특수 문자표 출력 다이얼로그
class CSymbolDlg : public CDialog
{
// Construction
public:
	CSymbolDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSymbolDlg)
	enum { IDD = IDD_SYMBOL_SELECT_DLG };
	CSymbolPreviewStatic	m_CodePreview;			// 특수 문자 미리보기 컨트롤
	CSymbolChart			m_CodeChart;			// 특수 문자표 컨트롤
	CEdit					m_CodeEdit;				// 특수 문자 코드 출력용 에디트 컨트롤
	CString					m_CodeString;			// 특수 문자 코드
	//}}AFX_DATA

	void UpdateButton();					// 현재 코드 범위에 따라 버튼들을 활성화 시키는 함수
	CString GetSelectedChar();				// 현재 선택된 문자의 하위 바이트를 리턴하는 함수

	void SetFontName(LPCTSTR pFontName);	// 특수 문자표에 사용할 폰트 설정 함수
	void SetCodeType(BOOL bUnicode);		// 특수 문자표에 사용할 문자 코드 설정 함수

	void OnLeft();							// 왼쪽 문자로 이동 함수
	void OnRight();							// 오른쪽 문자로 이동 함수
	void OnUp();							// 윗줄로 이동 함수
	void OnDown();							// 아랫 줄로 이동 함수

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSymbolDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
public:

	// Generated message map functions
	//{{AFX_MSG(CSymbolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPageUpButton();
	afx_msg void OnPageDownButton();
	afx_msg void OnGoButton();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYMBOLDLG_H__38AB538F_4338_4A8E_84E5_EF08383D8504__INCLUDED_)
