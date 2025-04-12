#if !defined(AFX_XPBUTTON_H__09FD40E3_B0FB_4109_8225_D377D1CCCC37__INCLUDED_)
#define AFX_XPBUTTON_H__09FD40E3_B0FB_4109_8225_D377D1CCCC37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XPButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CXPButton window

// 비트맵과 아이콘을 설정할 수 있는 버튼 클래스 헤더
#include "CoolButton.h"

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

// XP 테마 버튼 클래스
class CXPButton : public CCoolButton
{
// Construction
public:
	CXPButton();

// Attributes
public:
	static HMODULE		m_hThemeDLL;		// XP 테마 DLL의 핸들
	static int			m_nCount;			// XP 테마 DLL을 사용하는 버튼 갯수

// Operations
public:
	// XP 테마 DLL에 있는 함수들을 호출해주는 함수
	// 현재 프로그램에 테마가 적용되어 있는지 확인하는 함수
	BOOL IsAppThemed();
	// 특정 윈도우에 대한 특정 클래스의 테마 데이터를 오픈하는 함수
	HTHEME OpenThemeData(HWND hwnd, LPCWSTR pszClassList);
	// 열려진 테마 데이터를 닫는 함수
	HRESULT CloseThemeData(HTHEME hTheme);
	// 열려진 테마로 배경을 그리는 함수
	HRESULT DrawThemeBackground(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect);


	// 배경을 그리는 함수
	virtual void DrawBkgnd(CDC *pDC, BOOL bPressed, BOOL bEnable);
	// 테두리를 그리는 함수
	virtual void DrawBorder(CDC *pDC, BOOL bPressed, BOOL bFocus);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXPButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CXPButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CXPButton)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XPBUTTON_H__09FD40E3_B0FB_4109_8225_D377D1CCCC37__INCLUDED_)
