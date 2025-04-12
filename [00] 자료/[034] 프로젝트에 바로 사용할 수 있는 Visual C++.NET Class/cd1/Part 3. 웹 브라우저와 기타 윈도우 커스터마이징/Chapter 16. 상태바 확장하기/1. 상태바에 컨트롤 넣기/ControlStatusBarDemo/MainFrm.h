// MainFrm.h : CMainFrame Ŭ������ �������̽�
//


#pragma once

// ��Ʈ���� ���� �� �ִ� ���¹� Ŭ���� ���
#include "ControlStatusBar.h"


class CMainFrame : public CFrameWnd
{
	
protected: // serialization������ ��������ϴ�.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Ư��
public:

// �۾�
public:
	// ���� �������� ���¹� �����͸� �����ϴ� �Լ�
	CControlStatusBar* GetStatusBar()			{ return &m_wndStatusBar; }

// ������
	//{{AFX_VIRTUAL(CMainFrame)
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// ����
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ��Ʈ�� ������ ���Ե� ����Դϴ�.
	// ��Ʈ���� ���� �� �ִ� ���¹� Ŭ���� ����
	CControlStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


