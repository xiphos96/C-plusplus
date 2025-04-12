#include "stdafx.h"
#include "ColorMsgBoxHook.h"

// 컬러 메시지 박스 전역 변수
CColorMsgBoxHook	g_MsgBoxHook;


// 원래의 메시지 박스의 메시지 처리 함수를 대체할 새로운 메시지 처리 함수
LRESULT CALLBACK MsgBoxProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// 메시지 박스의 배경과 스태틱(메시지 출력용) 컨트롤의 색상을 설정하는 메시지를 수신했을 경우
	switch(msg)
	{
	case WM_CTLCOLORDLG:
	case WM_CTLCOLORSTATIC:
		// 텍스트의 배경을 투명으로 하고
		SetBkMode((HDC)wParam, TRANSPARENT);
		// 텍스트 출력 색상을 설정하고
		SetTextColor((HDC)wParam, g_MsgBoxHook.GetColorText());
		// 배경 색상의 브러쉬를 리턴한다
		return (LRESULT)g_MsgBoxHook.GetBkgndBrush();
	}

	// 기타 메시지는 원래의 메시지 처리 함수를 실행한다
	return ::CallWindowProc(g_MsgBoxHook.GetOriginProc(), hWnd, msg, wParam, lParam);
}

// 후킹 메시지 함수
LRESULT CALLBACK MsgBoxHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	// nCode가 0보다 작을 경우 반드시 CallNextHookEx()를 실행해 주어야 한다
	if(nCode < 0) 	return ::CallNextHookEx(g_MsgBoxHook.GetHookHandle(), nCode, wParam, lParam);

	switch(nCode)
	{
	case HCBT_CREATEWND:	// 메시지 박스 생성시
		{
			// 생성 옵션을 획득한다
			LPCBT_CREATEWND lpCreate = (LPCBT_CREATEWND)lParam;

			if(lpCreate->lpcs->hwndParent == g_MsgBoxHook.GetParentHandle())
			{
				// 메시지 박스의 클래스명인 WC_DIALOG를 사용한 윈도우인지 확인한다
				if(WC_DIALOG == lpCreate->lpcs->lpszClass)
				{
					// 메시지 박스의 윈도우 핸들을 저장해 둔다
					g_MsgBoxHook.SetMsgBoxHandle((HWND)wParam);

					// 메시지 박스의 메시지 처리 함수를 컬러 메시지 박스의 메시지 처리 함수로 교체한다.
					// 이때 원래 메시지 처리 함수는 저장해 둔다
					g_MsgBoxHook.SetOriginProc((WNDPROC)::SetWindowLong(g_MsgBoxHook.GetMsgBoxHandle(),
						GWL_WNDPROC, (LONG)MsgBoxProc));
				}
			}
		}
		break;
	case HCBT_DESTROYWND:	// 메시지 박스 소멸시
		// 메시지 박스의 소멸이라면
		if((HWND)wParam == g_MsgBoxHook.GetMsgBoxHandle())
		{
			// 원래 메시지 처리 함수를 메시지 박스에게 다시 설정한다
			::SetWindowLong(g_MsgBoxHook.GetMsgBoxHandle(), GWL_WNDPROC, (LONG)g_MsgBoxHook.GetOriginProc());
			// 저장해둔 메시지 박스의 윈도우 핸들을 지운다
			g_MsgBoxHook.SetMsgBoxHandle(NULL);
		}
		break;
	}

	return 0;
}

CColorMsgBoxHook::CColorMsgBoxHook()
{
	// 변수 초기화
	m_hInstance = NULL;

	m_clrText	= RGB(30, 30, 30);
	m_clrBkgnd	= RGB(255, 255, 255);

	m_brsBkgnd.CreateSolidBrush(m_clrBkgnd);

	m_hHook				= NULL;
	m_pOriginMsgBoxProc	= NULL;

	m_hMsgBox			= NULL;
}

CColorMsgBoxHook::~CColorMsgBoxHook()
{
	// 아직 후킹이 종료되지 않았다면 종료시킨다
	if(m_hHook)
	{
		::UnhookWindowsHookEx(m_hHook);
	}

	// 배경 출력 브러쉬를 제거한다
	if(m_brsBkgnd.m_hObject)		m_brsBkgnd.DeleteObject();
}

// 후킹을 시작하는 함수
void CColorMsgBoxHook::Install()
{
	// 이미 후킹되고 있다면 그냥 리턴한다
	if(m_hHook)				return;

	// 프로그램의 인스턴스 핸들을 구한다
	CWinApp *pApp = ::AfxGetApp();
	if(pApp)
	{
		m_hInstance = pApp->m_hInstance;
		if(m_hInstance)
		{
			// 후킹을 시작한다
			m_hHook = ::SetWindowsHookEx(WH_CBT, (HOOKPROC)MsgBoxHookProc, m_hInstance, 0);

			// 배경 출력 브러쉬를 생성한다
			if(m_brsBkgnd.m_hObject)		m_brsBkgnd.DeleteObject();
			m_brsBkgnd.CreateSolidBrush(m_clrBkgnd);
		}
	}
}

// 후킹을 종료하는 함수
void CColorMsgBoxHook::Uninstall()
{
	// 아직 후킹되고 있지 않다면 그냥 리턴한다
	if(m_hHook == NULL)		return;

	// 후킹을 끝낸다
	::UnhookWindowsHookEx(m_hHook);
	m_hHook = NULL;
}

// 배경 색상 설정 함수
void CColorMsgBoxHook::SetColorBkgnd(COLORREF clrBkgnd)
{
	// 새로운 배경 색상을 저장하고 브러쉬를 새로 만든다
	m_clrBkgnd = clrBkgnd;
	if(m_brsBkgnd.m_hObject)		m_brsBkgnd.DeleteObject();
	m_brsBkgnd.CreateSolidBrush(m_clrBkgnd);
}

// 메시지 박스 출력 함수
int CColorMsgBoxHook::MessageBox(HWND hWnd, LPCTSTR lpszText, LPCTSTR lpszCaption, UINT nType)
{
	// 부모 윈도우의 핸들을 저장한다
	m_hParent = hWnd;

	// 후킹을 시작하고
	Install();
	// 메시지 박스를 출력하고
	int nRet = ::MessageBox(hWnd, lpszText, lpszCaption, nType);
	// 후킹을 종료한다
	Uninstall();

	return nRet;
}

// 메시지 박스 출력 함수
int CColorMsgBoxHook::AfxMessageBox(LPCTSTR lpszText, UINT nType, UINT nIDHelp)
{
	// 메인 윈도우의 핸들을 저장한다
	m_hParent = AfxGetMainWnd()->m_hWnd;

	// 후킹을 시작하고
	Install();
	// 메시지 박스를 출력하고
	int nRet = ::AfxMessageBox(lpszText, nType, nIDHelp);
	// 후킹을 종료한다
	Uninstall();

	return nRet;
}

// 메시지 박스 출력 함수
int CColorMsgBoxHook::AfxMessageBox(UINT nIDPrompt, UINT nType, UINT nIDHelp)
{
	// 메인 윈도우의 핸들을 저장한다
	m_hParent = AfxGetMainWnd()->m_hWnd;

	// 후킹을 시작하고
	Install();
	// 메시지 박스를 출력하고
	int nRet = ::AfxMessageBox(nIDPrompt, nType, nIDHelp);
	// 후킹을 종료한다
	Uninstall();

	return nRet;
}
