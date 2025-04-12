#if !defined(AFX_RULERSPLITTERWND_H__7F1979E9_8381_4B23_8E9A_7CECD9C0EAC7__INCLUDED_)
#define AFX_RULERSPLITTERWND_H__7F1979E9_8381_4B23_8E9A_7CECD9C0EAC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RulerSplitterWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRulerSplitterWnd window

// 메인 뷰에서 수평/수직자에게 스크롤 및 마우스 위치 변화를 알려주기 위해 사용하는 인자 값
enum UPDATE_KIND { UPDATE_HSCROLL, UPDATE_VSCROLL, UPDATA_CURSOR };

// 메인 뷰의 수평/수직 스크롤 상태와 마우스 위치를 알려주는 구조체
class CScrollHint : public CObject
{
public:
	int m_nCX;
	int m_nCY;

	int m_nScrollX;
	int m_nScrollY;

	int m_nCursorX;
	int m_nCursorY;
};


// 수평/수직자 구현 스플리터 윈도우 클래스
class CRulerSplitterWnd : public CSplitterWnd
{
// Construction
public:
	CRulerSplitterWnd();

// Attributes
public:

// Operations
public:
	// 수평/수직자 구현을 위한 프레임 분할 함수
	BOOL CreateRulerSplitter(CWnd *pFrame, CRuntimeClass *pView, CCreateContext* pContext);

	// 스플리터의 이동을 막기 위한 마우스 히트 테스트 함수
	int HitTest(CPoint pt) const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRulerSplitterWnd)
	virtual void OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRulerSplitterWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRulerSplitterWnd)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULERSPLITTERWND_H__7F1979E9_8381_4B23_8E9A_7CECD9C0EAC7__INCLUDED_)
