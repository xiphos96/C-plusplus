#if !defined(AFX_DIALOGSTATUSBAR_H__0EC49515_5F4C_4653_8914_520CB361D3A5__INCLUDED_)
#define AFX_DIALOGSTATUSBAR_H__0EC49515_5F4C_4653_8914_520CB361D3A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogStatusBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogStatusBar window

// ���̾�α׿� ���¹� Ŭ����
class CDialogStatusBar : public CStatusBar
{
// Construction
public:
	CDialogStatusBar();

// Attributes
public:

// Operations
public:
	// ���¹� ���� �Լ�
	BOOL Create(CWnd* pParentWnd, DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM, UINT nID = AFX_IDW_STATUS_BAR);
	// ���� ���� �Լ�
	BOOL SetIndicators(const UINT* lpIDArray, int nIDCount);
	// �θ� �������� ũ�� ��ȭ�� ���� ���¹� ��ġ/ũ�� ��ȭ �Լ�
	void OnResize(int cx, int cy);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogStatusBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDialogStatusBar();

	// Generated message map functions
protected:
public:
	//{{AFX_MSG(CDialogStatusBar)
	afx_msg void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGSTATUSBAR_H__0EC49515_5F4C_4653_8914_520CB361D3A5__INCLUDED_)
