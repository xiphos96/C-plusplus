#if !defined(AFX_HTMLCOLLECTOR_H__D9F07177_E232_49F4_A86A_73D27F47912B__INCLUDED_)
#define AFX_HTMLCOLLECTOR_H__D9F07177_E232_49F4_A86A_73D27F47912B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HTMLCollector.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHTMLCollector window

// CArray를 사용하기 위한 헤더파일
#include "afxtempl.h"
// 익스플로러 관련 인터페이스를 사용하기 위한 헤더 파일
#include "Mshtml.h"


// HTML 소스 획득 클래스의 부모 윈도우에게 웹브라우저 선택 상태를 알리기 위한 메시지 정의
#define WM_IE_FINDER_START			(WM_USER + 367)		// 웹브라우저 선택 시작 메시지
#define WM_IE_FINDER_END			(WM_USER + 368)		// 웹브라우저 선택 종료 메시지
#define WM_IE_FINDER_SELECT			(WM_USER + 369)		// HTML 소스 획득 성공 메시지


// 웹브라우저 검색 후 웹브라우저 정보에 대한 구조체
struct SIEWnd
{
	HWND		hExplorer;			// 웹브라우저의 윈도우 핸들
	CString		strTitle;			// 웹브라우저가 출력하는 페이지의 타이틀
	CString		strAddress;			// 웹브라우저가 출력하는 페이지의 주소
};


// HTML 소스 획득 클래스
class CHTMLCollector : public CStatic
{
// Construction
public:
	CHTMLCollector();

// Attributes
public:
	// 스태틱 출력용 비트맵
	CBitmap						m_bmpFinder;			// 웹브라우저 선택 전 상태의 비트맵
	CBitmap						m_bmpFinderButton;		// 웹브라우저 선택 상태의 비트맵

	HWND						m_hLastHWND;			// 웹브라우저 선택시 마지막 마우스가 이동된 윈도우 핸들
	HCURSOR						m_hFinderCursor;		// 웹브라우저 선택시 마우스 커서

	CString						m_strSource;			// 선택되거나 검색된 웹브라우저의 소스

	CArray<SIEWnd*, SIEWnd*>	m_IEWndArray;			// 검색된 웹브라우저 배열


// Operations
public:
	// 획득된 소스를 리턴하는 함수
	LPCTSTR GetSource()					{ return m_strSource; }
	// 검색된 웹브라우저 중에서 특정 웹브라우저의 소스를 획득하여 리턴 하는 함수
	LPCTSTR GetSource(int nIndex);
	// 특정 웹브라우저의 소스를 획득하여 리턴하는 함수
	LPCTSTR GetSource(HWND hWnd);

	// 웹브라우저의 IHTMLDocument2 인터페이스로 소스를 획득하는 함수
	void CheckDocument(IHTMLDocument2 *pIDocument2);

	// 특정 윈도우의 외곽에 테두리를 그리는 함수
	void InvertWindowEdge(HWND hWnd);

	// 검색된 웹브라우저 배열을 지우고 현재 실행중인 웹브라우저들을 검색하는 함수
	int RefreshIEArray();
	// 검색된 웹브라우저 배열의 크기를 리턴하는 함수
	int GetIEArrayCount();
	// 검색된 웹브라우저 배열에서 특정 항목을 리턴하는 함수
	SIEWnd* GetIEWnd(int nIndex);

	// 윈도우 검색시 호출되는 콜백 함수
	static BOOL CALLBACK EnumWindowCallBack(HWND hWnd, LPARAM lParam);
	// 특정 프로세스의 실행 파일 이름을 리턴하는 함수
	static CString GetProcessName(DWORD pid);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHTMLCollector)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHTMLCollector();

	// Generated message map functions
protected:
	//{{AFX_MSG(CHTMLCollector)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTMLCOLLECTOR_H__D9F07177_E232_49F4_A86A_73D27F47912B__INCLUDED_)
