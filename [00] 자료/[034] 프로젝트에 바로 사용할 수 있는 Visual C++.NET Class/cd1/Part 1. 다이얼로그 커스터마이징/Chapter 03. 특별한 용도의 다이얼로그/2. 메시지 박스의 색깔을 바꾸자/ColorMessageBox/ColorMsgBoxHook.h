#ifndef _COLOR_MESSAGE_BOX_HOOK_H_
#define _COLOR_MESSAGE_BOX_HOOK_H_

// 컬러 메시지 박스 클래스
class CColorMsgBoxHook
{
private:
protected:
	HINSTANCE		m_hInstance;				// 프로그램 인스턴스 핸들

	HHOOK			m_hHook;					// 후킹 핸들
	WNDPROC			m_pOriginMsgBoxProc;		// 원래 메시지 박스의 메시지 처리 함수

	HWND			m_hMsgBox;					// 메시지 박스의 윈도우 핸들
	HWND			m_hParent;					// 메시지 박스의 부모 윈도우 핸들

	COLORREF		m_clrText;					// 텍스트 출력 색상
	COLORREF		m_clrBkgnd;					// 배경 색상

	CBrush			m_brsBkgnd;					// 배경 출력용 브러쉬

public:

private:
protected:

public:
	CColorMsgBoxHook();
	virtual ~CColorMsgBoxHook();

	void Install();								// 후킹을 시작하는 함수
	void Uninstall();							// 후킹을 종료하는 함수

	// 후킹 핸들 리턴 함수
	HHOOK GetHookHandle()					{ return m_hHook; }
	// 메시지 박스의 메시지 처리 함수 리턴/설정 함수 
	WNDPROC GetOriginProc()					{ return m_pOriginMsgBoxProc; }
	void SetOriginProc(WNDPROC pProc)		{ m_pOriginMsgBoxProc = pProc; }
	// 메시지 박스 윈도우 핸들 리턴/설정 함수
	HWND GetMsgBoxHandle()					{ return m_hMsgBox; }
	void SetMsgBoxHandle(HWND hWnd)			{ m_hMsgBox = hWnd; }
	// 메시지 박스의 부모 윈도우 핸들 리턴/설정 함수
	HWND GetParentHandle()					{ return m_hParent; }
	void SetParentHandle(HWND hWnd)			{ m_hParent = hWnd; }
	// 텍스트 색상 리턴/설정 함수
	COLORREF GetColorText()					{ return m_clrText; }
	void SetColorText(COLORREF clrText)		{ m_clrText = clrText; }
	// 배경 색상 리턴/설정 함수
	COLORREF GetColorBkgnd()				{ return m_clrBkgnd; }
	void SetColorBkgnd(COLORREF clrBkgnd);
	// 배경 브러쉬 리턴 함수
	HBRUSH GetBkgndBrush()					{ return (HBRUSH)m_brsBkgnd; }

	// 메시지 박스 출력 함수
	int MessageBox(HWND hWnd, LPCTSTR lpszText, LPCTSTR lpszCaption = NULL, UINT nType = MB_OK);

	int AfxMessageBox(LPCTSTR lpszText, UINT nType = MB_OK, UINT nIDHelp = 0);
	int AfxMessageBox(UINT nIDPrompt, UINT nType = MB_OK, UINT nIDHelp = (UINT) -1);
};

// 컬러 메시지 박스 전역 변수
extern CColorMsgBoxHook g_MsgBoxHook;

#endif // _COLOR_MESSAGE_BOX_HOOK_H_