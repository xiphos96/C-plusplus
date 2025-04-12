#if !defined(AFX_CONTROLSTATUSBAR_H__E8C02A97_2404_4457_A0B1_DBC1E7A1EC70__INCLUDED_)
#define AFX_CONTROLSTATUSBAR_H__E8C02A97_2404_4457_A0B1_DBC1E7A1EC70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ControlStatusBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CControlStatusBar window

// CArray를 사용하기 위한 헤더파일
#include "afxtempl.h"

// 상태바에 추가할 수 있는 컨트롤 종류
enum CONTROL_TYPE	{ CONTROL_STATIC, CONTROL_EDIT, CONTROL_BUTTON, CONTROL_CHECK, CONTROL_PROGRESS };

// 상태바의 컨트롤 페인에 대한 정보 구조체
struct SControlPane
{
	CWnd			*pWnd;					// 컨트롤의 윈도우 포인터
	int				nPane;					// 페인의 인덱스
	UINT			nID;					// 페인의 ID
	CString			strText;				// 페인의 텍스트

	SControlPane()
	{
		// 멤버 변수들을 초기화한다
		pWnd			= NULL;
		nPane			= -1;
		nID				= 0;
	}
};


// 컨트롤을 넣을 수 있는 상태바 클래스
class CControlStatusBar : public CStatusBar
{
// Construction
public:
	CControlStatusBar();

// Attributes
public:
	// 컨트롤 페인의 구조체 배열
	CArray<SControlPane*, SControlPane*>	m_ControlArray;

// Operations
public:
	// 새로운 페인에 컨트롤을 추가하는 함수
	int InsertControlPane(LPCTSTR pText, CONTROL_TYPE nType, UINT nID, int nPane, int nWidth);
	// 컨트롤 페인을 삭제하는 함수
	int RemoveControlPane(int nPane);
	// 특정 페인의 폭을 설정하는 함수
	int SetPaneWidth(int nPane, int nWidth);
	// 특정 인덱스의 컨트롤 페인 구조체를 리턴하는 함수
	SControlPane* GetControlPane(int nPane);
	// 특정 ID의 컨트롤 페인 구조체를 리턴하는 함수
	SControlPane* GetControlPane(UINT nID);
	// 상태바의 컨트롤들의 위치를 재조정하는 함수
	void RepositionAll();

protected:
	// 새로운 페인에 컨트롤을 추가하는 함수
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
