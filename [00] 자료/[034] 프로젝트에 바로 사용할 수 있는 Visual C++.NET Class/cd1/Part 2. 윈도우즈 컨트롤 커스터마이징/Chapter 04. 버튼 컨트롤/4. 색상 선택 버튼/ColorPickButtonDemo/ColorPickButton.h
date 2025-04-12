#if !defined(AFX_COLORPICKBUTTON_H__D69CD6F9_C6AA_4722_BAEE_7712E374BB09__INCLUDED_)
#define AFX_COLORPICKBUTTON_H__D69CD6F9_C6AA_4722_BAEE_7712E374BB09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorPickButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorPickButton window

// �ȷ�Ʈ ������ Ŭ���� ��� ����
#include "ColorPaletteWnd.h"

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


class CColorPickButton : public CButton
{
// Construction
public:
	CColorPickButton();

// Attributes
public:
	static HMODULE		m_hThemeDLL;				// XP �׸� DLL�� �ڵ�
	static int			m_nCount;					// XP �׸� DLL�� ����ϴ� ��ư ����

	BOOL				m_bFlat;					// ��� ��ư���� ��ü ��ư���� ����
	BOOL				m_bHover;					// ���콺�� ��ư ���� �ִ��� ����
	CRect				m_rcClient;					// ��ư�� Ŭ���̾�Ʈ ũ��

	CRect				m_rcColor;					// ��ư���� ���� ��� ��ġ
	CString				m_strText;					// ��ư�� �ؽ�Ʈ
	CRect				m_rcText;					// ��ư���� �ؽ�Ʈ ��� ��ġ
	CRect				m_rcArrow;					// ��ư���� ȭ��ǥ ��� ��ġ

	POINT				m_ptArrow[3];				// ȭ��ǥ�� �� ������ ��ġ

	CString				m_strToolTip;				// ���� �ؽ�Ʈ
	CToolTipCtrl		m_wndToolTip;				// ���� ��Ʈ��

	COLORREF			m_clrSelect;				// ���� ���õ� ����
	COLORREF			m_clrDefault;				// �⺻ ����
	COLORREF			m_clrText;					// ���� �̸� ��¿� ���� 
	COLORREF			m_clrBkgnd;					// ��ư�� ��� ����

	BOOL				m_bPopupWindow;				// �ȷ�Ʈ �����찡 ����� �ִ��� ����

	CColorPaletteWnd	*m_pPaletteWnd;				// �ȷ�Ʈ ������


// Operations
public:
	// ��� ��ư���� ����/�����ϴ� �Լ�
	BOOL IsFlat()							{ return m_bFlat; }
	void SetFlat(BOOL bFlat);

	// ��ư�� ������ ����/�����ϴ� �Լ�
	LPCTSTR GetToolTipText()				{ return m_strToolTip; }
	void SetToolTipText(LPCTSTR pTip);

	// ���� ������ ����/�����ϴ� �Լ�
	COLORREF GetColor();
	void SetColor(COLORREF clrColor);

	// �⺻ ������ ����/�����ϴ� �Լ�
	COLORREF GetDefaultColor()				{ return m_clrDefault; }
	void SetDefaultColor(COLORREF clrColor)	{ m_clrDefault = clrColor; }

	// ���� ������ �⺻ �������� �����ϴ� �Լ�
	BOOL IsDefaultColor()					{ return m_clrSelect == CLR_DEFAULT; }

	// ���� �̸� ��¿� ������ ����/�����ϴ� �Լ�
	COLORREF GetTextColor()					{ return m_clrText; }
	void SetTextColor(COLORREF clrText)		{ m_clrText = clrText; }

	// ��ư ��� �Լ�
	void RedrawButton(CDC *pDC, COLORREF clrColor, BOOL bPressed, BOOL bEnable);

	// XP �׸� DLL�� �ִ� �Լ����� ȣ�����ִ� �Լ�
	// ���� ���α׷��� �׸��� ����Ǿ� �ִ��� Ȯ���ϴ� �Լ�
	BOOL IsAppThemed();
	// Ư�� �����쿡 ���� Ư�� Ŭ������ �׸� �����͸� �����ϴ� �Լ�
	HTHEME OpenThemeData(HWND hwnd, LPCWSTR pszClassList);
	// ������ �׸� �����͸� �ݴ� �Լ�
	HRESULT CloseThemeData(HTHEME hTheme);
	// ������ �׸��� ����� �׸��� �Լ�
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
