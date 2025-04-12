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

// �׸� DLL�� ���õ� ���� �������� �ʱ�ȭ�Ѵ�
HMODULE CXPButton::m_hThemeDLL = NULL;
int CXPButton::m_nCount = 0;

CXPButton::CXPButton()
{
	// ���� �׸� DLL�� �ε����� �ʾҴٸ� �ε��Ѵ�
	if(m_hThemeDLL == NULL)
		m_hThemeDLL = ::LoadLibrary(_T("UxTheme.dll"));
	// ī��Ʈ�� 1 ������Ų��
	m_nCount++;
}

CXPButton::~CXPButton()
{
	// ī��Ʈ�� 1 ���� ��Ų��
	m_nCount--;
	// ���� ������ ���̻� ���� �׸� DLL�� �ε�Ǿ� �ִٸ� �����Ѵ�
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

// XP �׸� DLL�� �ִ� �Լ����� ȣ�����ִ� �Լ�

// ���� ���α׷��� �׸��� ����Ǿ� �ִ��� Ȯ���ϴ� �Լ�
BOOL CXPButton::IsAppThemed()
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef BOOL (__stdcall *LPISAPPTHEMED)();
	LPISAPPTHEMED lpIsAppThemed = (LPISAPPTHEMED)GetProcAddress(m_hThemeDLL, "IsAppThemed");

	if(lpIsAppThemed == NULL)	return FALSE;

	return lpIsAppThemed();
}

// Ư�� �����쿡 ���� Ư�� Ŭ������ �׸� �����͸� �����ϴ� �Լ�
HTHEME CXPButton::OpenThemeData(HWND hwnd, LPCWSTR pszClassList)
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef HTHEME (__stdcall *LPOPENTHEMEDATA)(HWND hwnd, LPCWSTR pszClassList);
	LPOPENTHEMEDATA lpOpenThemeData = (LPOPENTHEMEDATA)GetProcAddress(m_hThemeDLL, "OpenThemeData");

	if(lpOpenThemeData == NULL)	return FALSE;

	return lpOpenThemeData(hwnd, pszClassList);
}

// ������ �׸� �����͸� �ݴ� �Լ�
HRESULT CXPButton::CloseThemeData(HTHEME hTheme)
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef BOOL (__stdcall *LPCLOSETHEMEDATA)(HTHEME hTheme);
	LPCLOSETHEMEDATA lpCloseThemeData = (LPCLOSETHEMEDATA)GetProcAddress(m_hThemeDLL, "CloseThemeData");

	if(lpCloseThemeData == NULL)	return FALSE;

	return lpCloseThemeData(hTheme);
}

// ������ �׸��� ����� �׸��� �Լ�
HRESULT CXPButton::DrawThemeBackground(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect)
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef BOOL (__stdcall *LPDRAWTHEMEBACKGROUND)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect);
	LPDRAWTHEMEBACKGROUND lpDrawThemeBackground = (LPDRAWTHEMEBACKGROUND)GetProcAddress(m_hThemeDLL, "DrawThemeBackground");

	if(lpDrawThemeBackground == NULL)	return FALSE;

	return lpDrawThemeBackground(hTheme, hdc, iPartId, iStateId, pRect, pClipRect);
}

// ����� �׸��� �Լ�
void CXPButton::DrawBkgnd(CDC *pDC, BOOL bPressed, BOOL bEnable)
{
	// ���� �׸��� ����ϰ� �ִٸ�
	if(IsAppThemed())
	{
		HTHEME	hTheme = NULL;

		// ��ư ���� �׸� �����͸� ����
		hTheme = OpenThemeData(m_hWnd, L"BUTTON");
		if(hTheme)
		{
			// ���� ��ư�� ���¿� ���� �Ӽ��� ã�´�
			int	iStateId = PBS_NORMAL;
			if(m_bHover)		iStateId = PBS_HOT;
			if(bPressed)		iStateId = PBS_PRESSED;
			if(!bEnable)		iStateId = PBS_DISABLED;

			// ���� �׸��� ��ư�� ���� ���� ������ ����� �׸���
			DrawThemeBackground(hTheme, pDC->m_hDC, BP_PUSHBUTTON,
				iStateId, &m_rcClient, NULL);

			// ������ �׸� �����͸� �ݴ´�
			CloseThemeData(hTheme);

			return;
		}
	}
	
	CCoolButton::DrawBkgnd(pDC, bPressed, bEnable);
}

// �׵θ��� �׸��� �Լ�
void CXPButton::DrawBorder(CDC *pDC, BOOL bPressed, BOOL bFocus)
{
	// �׸��� ������� �ʾ��� ��츸 ������ �׵θ� �׸��� ��ƾ�� �����Ѵ�
	if(!IsAppThemed())	CCoolButton::DrawBorder(pDC, bPressed, bFocus);
}
