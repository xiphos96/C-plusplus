// XPButton.cpp : implementation file
//

#include "stdafx.h"
#include "xpbuttondemo.h"
#include "XPButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXPButton

// 테마 DLL과 관련된 정적 변수들을 초기화한다
HMODULE CXPButton::m_hThemeDLL = NULL;
int CXPButton::m_nCount = 0;

CXPButton::CXPButton()
{
	// 아직 테마 DLL이 로딩되지 않았다면 로드한다
	if(m_hThemeDLL == NULL)
		m_hThemeDLL = ::LoadLibrary(_T("UxTheme.dll"));
	// 카운트를 1 증가시킨다
	m_nCount++;
}

CXPButton::~CXPButton()
{
	// 카운트를 1 감소 시킨다
	m_nCount--;
	// 만약 참조가 더이상 없고 테마 DLL이 로드되어 있다면 해제한다
	if(m_nCount == 0 && m_hThemeDLL)
	{
		::FreeLibrary(m_hThemeDLL);
		m_hThemeDLL = NULL;
	}
}


BEGIN_MESSAGE_MAP(CXPButton, CCoolButton)
	//{{AFX_MSG_MAP(CXPButton)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXPButton message handlers

// XP 테마 DLL에 있는 함수들을 호출해주는 함수

// 현재 프로그램에 테마가 적용되어 있는지 확인하는 함수
BOOL CXPButton::IsAppThemed()
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef BOOL (__stdcall *LPISAPPTHEMED)();
	LPISAPPTHEMED lpIsAppThemed = (LPISAPPTHEMED)GetProcAddress(m_hThemeDLL, "IsAppThemed");

	if(lpIsAppThemed == NULL)	return FALSE;

	return lpIsAppThemed();
}

// 특정 윈도우에 대한 특정 클래스의 테마 데이터를 오픈하는 함수
HTHEME CXPButton::OpenThemeData(HWND hwnd, LPCWSTR pszClassList)
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef HTHEME (__stdcall *LPOPENTHEMEDATA)(HWND hwnd, LPCWSTR pszClassList);
	LPOPENTHEMEDATA lpOpenThemeData = (LPOPENTHEMEDATA)GetProcAddress(m_hThemeDLL, "OpenThemeData");

	if(lpOpenThemeData == NULL)	return FALSE;

	return lpOpenThemeData(hwnd, pszClassList);
}

// 열려진 테마 데이터를 닫는 함수
HRESULT CXPButton::CloseThemeData(HTHEME hTheme)
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef BOOL (__stdcall *LPCLOSETHEMEDATA)(HTHEME hTheme);
	LPCLOSETHEMEDATA lpCloseThemeData = (LPCLOSETHEMEDATA)GetProcAddress(m_hThemeDLL, "CloseThemeData");

	if(lpCloseThemeData == NULL)	return FALSE;

	return lpCloseThemeData(hTheme);
}

// 열려진 테마로 배경을 그리는 함수
HRESULT CXPButton::DrawThemeBackground(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect)
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef BOOL (__stdcall *LPDRAWTHEMEBACKGROUND)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect);
	LPDRAWTHEMEBACKGROUND lpDrawThemeBackground = (LPDRAWTHEMEBACKGROUND)GetProcAddress(m_hThemeDLL, "DrawThemeBackground");

	if(lpDrawThemeBackground == NULL)	return FALSE;

	return lpDrawThemeBackground(hTheme, hdc, iPartId, iStateId, pRect, pClipRect);
}

// 배경을 그리는 함수
void CXPButton::DrawBkgnd(CDC *pDC, BOOL bPressed, BOOL bEnable)
{
	// 만일 테마를 사용하고 있다면
	if(IsAppThemed())
	{
		HTHEME	hTheme = NULL;

		// 버튼 관련 테마 데이터를 연다
		hTheme = OpenThemeData(m_hWnd, L"BUTTON");
		if(hTheme)
		{
			// 현재 버튼의 상태에 따른 속성을 찾는다
			int	iStateId = PBS_NORMAL;
			if(m_bHover)		iStateId = PBS_HOT;
			if(bPressed)		iStateId = PBS_PRESSED;
			if(!bEnable)		iStateId = PBS_DISABLED;

			// 현재 테마로 버튼에 대한 현재 상태의 배경을 그린다
			DrawThemeBackground(hTheme, pDC->m_hDC, BP_PUSHBUTTON,
				iStateId, &m_rcClient, NULL);

			// 열려진 테마 데이터를 닫는다
			CloseThemeData(hTheme);

			return;
		}
	}
	
	CCoolButton::DrawBkgnd(pDC, bPressed, bEnable);
}

// 테두리를 그리는 함수
void CXPButton::DrawBorder(CDC *pDC, BOOL bPressed, BOOL bFocus)
{
	// 테마가 적용되지 않았을 경우만 원래의 테두리 그리기 루틴을 실행한다
	if(!IsAppThemed())	CCoolButton::DrawBorder(pDC, bPressed, bFocus);
}
