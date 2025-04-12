#if !defined(AFX_DIALOGSPLITTERWND_H__938FB453_F60E_4541_BF43_8EABAAE32A8A__INCLUDED_)
#define AFX_DIALOGSPLITTERWND_H__938FB453_F60E_4541_BF43_8EABAAE32A8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogSplitterWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogSplitterWnd window


// CArray를 사용하기 위한 헤더 파일
#include "afxtempl.h"


// 컨트롤이 위치한 방향을 설정하는 나열 상수
enum CONTROL_POS	{ POS_LEFT, POS_TOP, POS_RIGHT, POS_BOTTOM };
// 스플리터의 방향을 설정하는 나열 상수
enum SPLITTER_DIR	{ DIR_HORZ, DIR_VERT };


// 스플리터에 설정되는 컨트롤에 대한 정보 구조체
struct SControlInfo
{
	CWnd	*pWnd;					// 컨트롤의 윈도우 포인터
	int		nPos;					// 컨트롤의 초기 위치 : 컨트롤의 위치 방향에 따라 다른 값이 저장된다
	BOOL	bStretch;				// 스플리터의 이동에 따라 컨트롤을 확장할 것인지 여부
};


// 다이얼로그용 스플리터 클래스
class CDialogSplitterWnd : public CStatic
{
// Construction
public:
	CDialogSplitterWnd();

// Attributes
public:
	SPLITTER_DIR			m_nDirection;		// 스플리터의 방향
	BOOL					m_bCapture;			// 현재 마우스 이벤트를 캡춰하고 있는지 여부

	int						m_nInitPos;			// 스플리터의 초기 위치(수평 - top 좌표, 수직 left 좌표)
	int						m_nLeftRange;		// 스플리터가 좌측 혹은 상단으로 이동할 수 있는 거리
	int						m_nRightRange;		// 스플리터가 우측 혹은 하단으로 이동할 수 있는 거리

	CArray<SControlInfo*, SControlInfo*>	m_LeftControls;		// 스플리터의 좌측 혹은 상단에 위치한 컨트롤들 배열
	CArray<SControlInfo*, SControlInfo*>	m_RightControls;	// 스플리터의 우측 혹은 하단에 위치한 컨트롤들 배열

	COLORREF				m_clrSplitter;		// 스플리터의 바탕색

	HCURSOR					m_hHorzCursor;		// 수평 스플리터에 대한 마우스 커서
	HCURSOR					m_hVertCursor;		// 수직 스플리터에 대한 마우스 커서

// Operations
public:
	// 스플리터의 방향을 설정하는 함수
	void SetDirection(SPLITTER_DIR nDir);
	// 스플리터의 이동 범위를 설정하는 함수
	void SetRange(int nLeft, int nRight);
	// 스플리터에 컨트롤을 추가하는 함수
	int AddControl(CONTROL_POS nPos, CWnd *pControl, BOOL bStretch = TRUE);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogSplitterWnd)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDialogSplitterWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDialogSplitterWnd)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGSPLITTERWND_H__938FB453_F60E_4541_BF43_8EABAAE32A8A__INCLUDED_)
