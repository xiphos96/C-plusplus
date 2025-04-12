#if !defined(AFX_XPBUTTON_H__09FD40E3_B0FB_4109_8225_D377D1CCCC37__INCLUDED_)
#define AFX_XPBUTTON_H__09FD40E3_B0FB_4109_8225_D377D1CCCC37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XPButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CXPButton window

// ��Ʈ�ʰ� �������� ������ �� �ִ� ��ư Ŭ���� ���
#include "CoolButton.h"

// XP�� �׸����� ����ϴ� ������� �����Ѵ�
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

// XP �׸� ��ư Ŭ����
class CXPButton : public CCoolButton
{
// Construction
public:
	CXPButton();

// Attributes
public:
	static HMODULE		m_hThemeDLL;		// XP �׸� DLL�� �ڵ�
	static int			m_nCount;			// XP �׸� DLL�� ����ϴ� ��ư ����

// Operations
public:
	// XP �׸� DLL�� �ִ� �Լ����� ȣ�����ִ� �Լ�
	// ���� ���α׷��� �׸��� ����Ǿ� �ִ��� Ȯ���ϴ� �Լ�
	BOOL IsAppThemed();
	// Ư�� �����쿡 ���� Ư�� Ŭ������ �׸� �����͸� �����ϴ� �Լ�
	HTHEME OpenThemeData(HWND hwnd, LPCWSTR pszClassList);
	// ������ �׸� �����͸� �ݴ� �Լ�
	HRESULT CloseThemeData(HTHEME hTheme);
	// ������ �׸��� ����� �׸��� �Լ�
	HRESULT DrawThemeBackground(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect);


	// ����� �׸��� �Լ�
	virtual void DrawBkgnd(CDC *pDC, BOOL bPressed, BOOL bEnable);
	// �׵θ��� �׸��� �Լ�
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
