#if !defined(AFX_CONTROLSTATUSBAR_H__E8C02A97_2404_4457_A0B1_DBC1E7A1EC70__INCLUDED_)
#define AFX_CONTROLSTATUSBAR_H__E8C02A97_2404_4457_A0B1_DBC1E7A1EC70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ControlStatusBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CControlStatusBar window

// CArray�� ����ϱ� ���� �������
#include "afxtempl.h"

// ���¹ٿ� �߰��� �� �ִ� ��Ʈ�� ����
enum CONTROL_TYPE	{ CONTROL_STATIC, CONTROL_EDIT, CONTROL_BUTTON, CONTROL_CHECK, CONTROL_PROGRESS };

// ���¹��� ��Ʈ�� ���ο� ���� ���� ����ü
struct SControlPane
{
	CWnd			*pWnd;					// ��Ʈ���� ������ ������
	int				nPane;					// ������ �ε���
	UINT			nID;					// ������ ID
	CString			strText;				// ������ �ؽ�Ʈ

	SControlPane()
	{
		// ��� �������� �ʱ�ȭ�Ѵ�
		pWnd			= NULL;
		nPane			= -1;
		nID				= 0;
	}
};


// ��Ʈ���� ���� �� �ִ� ���¹� Ŭ����
class CControlStatusBar : public CStatusBar
{
// Construction
public:
	CControlStatusBar();

// Attributes
public:
	// ��Ʈ�� ������ ����ü �迭
	CArray<SControlPane*, SControlPane*>	m_ControlArray;

// Operations
public:
	// ���ο� ���ο� ��Ʈ���� �߰��ϴ� �Լ�
	int InsertControlPane(LPCTSTR pText, CONTROL_TYPE nType, UINT nID, int nPane, int nWidth);
	// ��Ʈ�� ������ �����ϴ� �Լ�
	int RemoveControlPane(int nPane);
	// Ư�� ������ ���� �����ϴ� �Լ�
	int SetPaneWidth(int nPane, int nWidth);
	// Ư�� �ε����� ��Ʈ�� ���� ����ü�� �����ϴ� �Լ�
	SControlPane* GetControlPane(int nPane);
	// Ư�� ID�� ��Ʈ�� ���� ����ü�� �����ϴ� �Լ�
	SControlPane* GetControlPane(UINT nID);
	// ���¹��� ��Ʈ�ѵ��� ��ġ�� �������ϴ� �Լ�
	void RepositionAll();

protected:
	// ���ο� ���ο� ��Ʈ���� �߰��ϴ� �Լ�
	int InsertControlPane(CWnd *pWnd, UINT nID, int nPane, int nWidth);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControlStatusBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CControlStatusBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CControlStatusBar)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLSTATUSBAR_H__E8C02A97_2404_4457_A0B1_DBC1E7A1EC70__INCLUDED_)
