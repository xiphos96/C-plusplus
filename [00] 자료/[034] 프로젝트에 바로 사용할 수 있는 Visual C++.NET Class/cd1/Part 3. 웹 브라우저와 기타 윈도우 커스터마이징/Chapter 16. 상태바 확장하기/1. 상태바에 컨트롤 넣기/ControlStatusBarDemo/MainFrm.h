// MainFrm.h : CMainFrame 클래스의 인터페이스
//


#pragma once

// 컨트롤을 넣을 수 있는 상태바 클래스 헤더
#include "ControlStatusBar.h"


class CMainFrame : public CFrameWnd
{
	
protected: // serialization에서만 만들어집니다.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 특성
public:

// 작업
public:
	// 메인 프레임의 상태바 포인터를 리턴하는 함수
	CControlStatusBar* GetStatusBar()			{ return &m_wndStatusBar; }

// 재정의
	//{{AFX_VIRTUAL(CMainFrame)
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// 구현
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 컨트롤 모음이 포함된 멤버입니다.
	// 컨트롤을 넣을 수 있는 상태바 클래스 변수
	CControlStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// 메시지 맵 함수를 생성했습니다.
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


