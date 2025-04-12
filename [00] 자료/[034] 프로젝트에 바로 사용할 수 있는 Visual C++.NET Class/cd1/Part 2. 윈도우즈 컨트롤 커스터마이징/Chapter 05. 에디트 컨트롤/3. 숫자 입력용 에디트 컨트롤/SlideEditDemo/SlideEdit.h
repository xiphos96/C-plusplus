#if !defined(AFX_SLIDEEDIT_H__222FBA88_426C_4152_A6A9_72CBF8E4927C__INCLUDED_)
#define AFX_SLIDEEDIT_H__222FBA88_426C_4152_A6A9_72CBF8E4927C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SlideEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSlideEdit window

// 슬라이드 윈도우에 대한 클래스 헤더 파일
#include "SlideWnd.h"

// CSlideEdit를 사용하여 DDX/DDV를 실행하기 위한 함수
void AFXAPI DDX_SlideEdit(CDataExchange* pDX, int nIDC, CString& strText);


// 슬라이드 에디트 컨트롤 클래스
class CSlideEdit : public CEdit
{
// Construction
public:
	CSlideEdit();

// Attributes
public:
	int			m_nValue;					// 현재 입력된 값
	int			m_nMax;						// 최대 값
	int			m_nMin;						// 최소 값

	int			m_nButtonState;				// 현재 버튼의 상태
	CRect		m_rcButton;					// 버튼의 영역

	HCURSOR		m_hCursor;					// 화살표 마우스 커서

	CSlideWnd	m_wndSlide;					// 슬라이드 윈도우

// Operations
public:
	// 슬라이드 에디트 컨트롤의 값을 리턴/설정하는 함수
	int GetValue()							{ return m_nValue; }
	BOOL SetValue(int nValue);
	// 슬라이드 에디트 컨트롤의 범위를 리턴/설정하는 함수
	void GetRange(int &nMax, int &nMin)		{ nMax = m_nMax; nMin = m_nMin; }
	void SetRange(int nMax, int nMin);

	// 값 조정 버튼을 그리는 함수
	void DrawButton();
	// 슬라이드 윈도우를 띄우는 함수
	void PopupSlide();

	// 값 조정 버튼의 상태 열거
	enum { BUTTON_DISABLED = 0, BUTTON_UP, BUTTON_DOWN };

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSlideEdit)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSlideEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSlideEdit)
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChange();
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	//}}AFX_MSG
	// 슬라이드 윈도우의 메시지에 대한 핸들러
	afx_msg LRESULT OnSlidePosChange(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSlideEndSelect(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDEEDIT_H__222FBA88_426C_4152_A6A9_72CBF8E4927C__INCLUDED_)
