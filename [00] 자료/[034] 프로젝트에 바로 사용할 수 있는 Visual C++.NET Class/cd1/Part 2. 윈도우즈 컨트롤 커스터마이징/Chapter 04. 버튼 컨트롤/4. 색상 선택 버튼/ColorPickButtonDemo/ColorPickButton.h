#if !defined(AFX_COLORPICKBUTTON_H__D69CD6F9_C6AA_4722_BAEE_7712E374BB09__INCLUDED_)
#define AFX_COLORPICKBUTTON_H__D69CD6F9_C6AA_4722_BAEE_7712E374BB09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorPickButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorPickButton window

// 팔레트 윈도우 클래스 헤더 파일
#include "ColorPaletteWnd.h"

// XP의 테마에서 사용하는 상수들을 정의한다
#include <tmschema.h>
#include <UxTheme.h>

/*
#define	HTHEME				HANDLE
#define	BP_PUSHBUTTON		0x00000001
#define	PBS_NORMAL			0x00000001
#define	PBS_DEFAULTED		0x00000005
#define	PBS_HOT				0x00000002
#define	PBS_PRESSED			0x00000003
#define	PBS_DISABLED		0x00000004
*/


class CColorPickButton : public CButton
{
// Construction
public:
	CColorPickButton();

// Attributes
public:
	static HMODULE		m_hThemeDLL;				// XP 테마 DLL의 핸들
	static int			m_nCount;					// XP 테마 DLL을 사용하는 버튼 갯수

	BOOL				m_bFlat;					// 평면 버튼인지 입체 버튼인지 여부
	BOOL				m_bHover;					// 마우스가 버튼 위에 있는지 여부
	CRect				m_rcClient;					// 버튼의 클라이언트 크기

	CRect				m_rcColor;					// 버튼에서 색상 출력 위치
	CString				m_strText;					// 버튼의 텍스트
	CRect				m_rcText;					// 버튼에서 텍스트 출력 위치
	CRect				m_rcArrow;					// 버튼에서 화살표 출력 위치

	POINT				m_ptArrow[3];				// 화살표의 세 꼭지점 위치

	CString				m_strToolTip;				// 툴팁 텍스트
	CToolTipCtrl		m_wndToolTip;				// 툴팁 컨트롤

	COLORREF			m_clrSelect;				// 현재 선택된 색상
	COLORREF			m_clrDefault;				// 기본 색상
	COLORREF			m_clrText;					// 색상 이름 출력용 색상 
	COLORREF			m_clrBkgnd;					// 버튼의 배경 색상

	BOOL				m_bPopupWindow;				// 팔레트 윈도우가 띄워져 있는지 여부

	CColorPaletteWnd	*m_pPaletteWnd;				// 팔레트 윈도우


// Operations
public:
	// 평면 버튼인지 리턴/설정하는 함수
	BOOL IsFlat()							{ return m_bFlat; }
	void SetFlat(BOOL bFlat);

	// 버튼의 툴팁을 리턴/설정하는 함수
	LPCTSTR GetToolTipText()				{ return m_strToolTip; }
	void SetToolTipText(LPCTSTR pTip);

	// 현재 색상을 리턴/설정하는 함수
	COLORREF GetColor();
	void SetColor(COLORREF clrColor);

	// 기본 색상을 리턴/설정하는 함수
	COLORREF GetDefaultColor()				{ return m_clrDefault; }
	void SetDefaultColor(COLORREF clrColor)	{ m_clrDefault = clrColor; }

	// 현재 색상이 기본 색상인지 리턴하는 함수
	BOOL IsDefaultColor()					{ return m_clrSelect == CLR_DEFAULT; }

	// 색상 이름 출력용 색상을 리턴/설정하는 함수
	COLORREF GetTextColor()					{ return m_clrText; }
	void SetTextColor(COLORREF clrText)		{ m_clrText = clrText; }

	// 버튼 출력 함수
	void RedrawButton(CDC *pDC, COLORREF clrColor, BOOL bPressed, BOOL bEnable);

	// XP 테마 DLL에 있는 함수들을 호출해주는 함수
	// 현재 프로그램에 테마가 적용되어 있는지 확인하는 함수
	BOOL IsAppThemed();
	// 특정 윈도우에 대한 특정 클래스의 테마 데이터를 오픈하는 함수
	HTHEME OpenThemeData(HWND hwnd, LPCWSTR pszClassList);
	// 열려진 테마 데이터를 닫는 함수
	HRESULT CloseThemeData(HTHEME hTheme);
	// 열려진 테마로 배경을 그리는 함수
	HRESULT DrawThemeBackground(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorPickButton)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CColorPickButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CColorPickButton)
	afx_msg void OnClicked();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnTrackColor(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSelEndOK(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSelEndCancel(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORPICKBUTTON_H__D69CD6F9_C6AA_4722_BAEE_7712E374BB09__INCLUDED_)
