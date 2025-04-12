#if !defined(AFX_SYMBOLPREVIEWSTATIC_H__73372676_AED2_4BED_AFC2_46BD25858CDD__INCLUDED_)
#define AFX_SYMBOLPREVIEWSTATIC_H__73372676_AED2_4BED_AFC2_46BD25858CDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SymbolPreviewStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSymbolPreviewStatic window

// 선택된 특수 문자를 크게 보여주는 컨트롤
class CSymbolPreviewStatic : public CStatic
{
// Construction
public:
	CSymbolPreviewStatic();

// Attributes
public:
	BOOL			m_bIsUnicode;			// 유니코드인지 여부
	CRect			m_ClientRect;			// 컨트롤의 클라이언트 영역

	unsigned char	m_cHighByte;			// 특수 문자의 상위 바이트
	unsigned char	m_cLowByte;				// 특수 문자의 하위 바이트
	wchar_t			m_strUni[2];			// 유니코드 저장용 변수
	char			m_strAscii[2];			// 아스키 코드 저장용 변수

	CFont			m_DisplayFont;			// 화면 출력에 사용되는 폰트
	CString			m_FontName;				// 화면 출력에 사용되는 폰트 이름

// Operations
public:
	void InitPreview();						// 클라이언트 영역을 구하고 폰트를 생성하는 함수
	// 새로운 특수 문자를 출력하는 함수
	void RefreshCode(unsigned char cHighByte, unsigned char cLowByte);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSymbolPreviewStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSymbolPreviewStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSymbolPreviewStatic)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYMBOLPREVIEWSTATIC_H__73372676_AED2_4BED_AFC2_46BD25858CDD__INCLUDED_)
