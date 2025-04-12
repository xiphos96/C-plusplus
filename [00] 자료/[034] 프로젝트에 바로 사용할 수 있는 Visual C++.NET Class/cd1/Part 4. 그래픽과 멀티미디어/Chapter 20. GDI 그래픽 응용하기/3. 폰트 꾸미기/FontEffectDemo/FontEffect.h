#if !defined(AFX_FONTEFFECT_H__3071E538_9EEC_4607_B73B_8B20A8CA7A52__INCLUDED_)
#define AFX_FONTEFFECT_H__3071E538_9EEC_4607_B73B_8B20A8CA7A52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FontEffect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFontEffect window

// 효과 추가를 위한 함수 포인터 타입 정의
typedef void (*LPPROCESSFUNC)(int nSize, CPoint *pPoint, CSize TextSize);


// 폰트 효과 스태틱 클래스
class CFontEffect : public CStatic
{
// Construction
public:
	CFontEffect();

// Attributes
public:
	CFont			m_TextFont;				// 텍스트 출력용 폰트
	CString			m_strText;				// 출력 텍스트
	BOOL			m_bOutLine;				// 외곽선 출력 여부

	int				m_nPointSize;			// 경로를 구성하는 포인트 갯수
	CPoint			*m_pPointArray;			// 경로를 구성하는 포인트 배열
	BYTE			*m_pTypeArray;			// 경로를 구성하는 형식 배열
	CSize			m_TextSize;				// 기본 텍스트 사이즈
	CRect			m_rcOutput;				// 효과가 적용되어 출력되는 크기

	LPPROCESSFUNC	m_pProcessFunc;			// 효과 추가용 함수 포인터

// Operations
public:
	// 텍스트를 변경하는 함수
	void SetText(LPCTSTR pText, BOOL bRebuild = FALSE);
	// 추가 효과 함수를 설정하는 함수
	void SetFunction(LPPROCESSFUNC pFunc, BOOL bRebuild = FALSE);
	// 외곽선 출력 여부를 설정하는 함수
	void SetOutLine(BOOL bOutLine);

	// 텍스트에 대한 경로를 계산하는 함수
	void BuildEffect();

	// 경로를 출력하는 함수
	void DrawEffect(CDC *pDC, int cx, int cy);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontEffect)
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFontEffect();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFontEffect)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTEFFECT_H__3071E538_9EEC_4607_B73B_8B20A8CA7A52__INCLUDED_)
