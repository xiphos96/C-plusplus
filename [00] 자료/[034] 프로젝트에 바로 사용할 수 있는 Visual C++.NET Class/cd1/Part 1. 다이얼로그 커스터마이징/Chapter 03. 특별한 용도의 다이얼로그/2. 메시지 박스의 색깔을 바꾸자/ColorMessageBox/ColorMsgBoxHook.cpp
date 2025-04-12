#include "stdafx.h"
#include "ColorMsgBoxHook.h"

// �÷� �޽��� �ڽ� ���� ����
CColorMsgBoxHook	g_MsgBoxHook;


// ������ �޽��� �ڽ��� �޽��� ó�� �Լ��� ��ü�� ���ο� �޽��� ó�� �Լ�
LRESULT CALLBACK MsgBoxProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// �޽��� �ڽ��� ���� ����ƽ(�޽��� ��¿�) ��Ʈ���� ������ �����ϴ� �޽����� �������� ���
	switch(msg)
	{
	case WM_CTLCOLORDLG:
	case WM_CTLCOLORSTATIC:
		// �ؽ�Ʈ�� ����� �������� �ϰ�
		SetBkMode((HDC)wParam, TRANSPARENT);
		// �ؽ�Ʈ ��� ������ �����ϰ�
		SetTextColor((HDC)wParam, g_MsgBoxHook.GetColorText());
		// ��� ������ �귯���� �����Ѵ�
		return (LRESULT)g_MsgBoxHook.GetBkgndBrush();
	}

	// ��Ÿ �޽����� ������ �޽��� ó�� �Լ��� �����Ѵ�
	return ::CallWindowProc(g_MsgBoxHook.GetOriginProc(), hWnd, msg, wParam, lParam);
}

// ��ŷ �޽��� �Լ�
LRESULT CALLBACK MsgBoxHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	// nCode�� 0���� ���� ��� �ݵ�� CallNextHookEx()�� ������ �־�� �Ѵ�
	if(nCode < 0) 	return ::CallNextHookEx(g_MsgBoxHook.GetHookHandle(), nCode, wParam, lParam);

	switch(nCode)
	{
	case HCBT_CREATEWND:	// �޽��� �ڽ� ������
		{
			// ���� �ɼ��� ȹ���Ѵ�
			LPCBT_CREATEWND lpCreate = (LPCBT_CREATEWND)lParam;

			if(lpCreate->lpcs->hwndParent == g_MsgBoxHook.GetParentHandle())
			{
				// �޽��� �ڽ��� Ŭ�������� WC_DIALOG�� ����� ���������� Ȯ���Ѵ�
				if(WC_DIALOG == lpCreate->lpcs->lpszClass)
				{
					// �޽��� �ڽ��� ������ �ڵ��� ������ �д�
					g_MsgBoxHook.SetMsgBoxHandle((HWND)wParam);

					// �޽��� �ڽ��� �޽��� ó�� �Լ��� �÷� �޽��� �ڽ��� �޽��� ó�� �Լ��� ��ü�Ѵ�.
					// �̶� ���� �޽��� ó�� �Լ��� ������ �д�
					g_MsgBoxHook.SetOriginProc((WNDPROC)::SetWindowLong(g_MsgBoxHook.GetMsgBoxHandle(),
						GWL_WNDPROC, (LONG)MsgBoxProc));
				}
			}
		}
		break;
	case HCBT_DESTROYWND:	// �޽��� �ڽ� �Ҹ��
		// �޽��� �ڽ��� �Ҹ��̶��
		if((HWND)wParam == g_MsgBoxHook.GetMsgBoxHandle())
		{
			// ���� �޽��� ó�� �Լ��� �޽��� �ڽ����� �ٽ� �����Ѵ�
			::SetWindowLong(g_MsgBoxHook.GetMsgBoxHandle(), GWL_WNDPROC, (LONG)g_MsgBoxHook.GetOriginProc());
			// �����ص� �޽��� �ڽ��� ������ �ڵ��� �����
			g_MsgBoxHook.SetMsgBoxHandle(NULL);
		}
		break;
	}

	return 0;
}

CColorMsgBoxHook::CColorMsgBoxHook()
{
	// ���� �ʱ�ȭ
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
	// ���� ��ŷ�� ������� �ʾҴٸ� �����Ų��
	if(m_hHook)
	{
		::UnhookWindowsHookEx(m_hHook);
	}

	// ��� ��� �귯���� �����Ѵ�
	if(m_brsBkgnd.m_hObject)		m_brsBkgnd.DeleteObject();
}

// ��ŷ�� �����ϴ� �Լ�
void CColorMsgBoxHook::Install()
{
	// �̹� ��ŷ�ǰ� �ִٸ� �׳� �����Ѵ�
	if(m_hHook)				return;

	// ���α׷��� �ν��Ͻ� �ڵ��� ���Ѵ�
	CWinApp *pApp = ::AfxGetApp();
	if(pApp)
	{
		m_hInstance = pApp->m_hInstance;
		if(m_hInstance)
		{
			// ��ŷ�� �����Ѵ�
			m_hHook = ::SetWindowsHookEx(WH_CBT, (HOOKPROC)MsgBoxHookProc, m_hInstance, 0);

			// ��� ��� �귯���� �����Ѵ�
			if(m_brsBkgnd.m_hObject)		m_brsBkgnd.DeleteObject();
			m_brsBkgnd.CreateSolidBrush(m_clrBkgnd);
		}
	}
}

// ��ŷ�� �����ϴ� �Լ�
void CColorMsgBoxHook::Uninstall()
{
	// ���� ��ŷ�ǰ� ���� �ʴٸ� �׳� �����Ѵ�
	if(m_hHook == NULL)		return;

	// ��ŷ�� ������
	::UnhookWindowsHookEx(m_hHook);
	m_hHook = NULL;
}

// ��� ���� ���� �Լ�
void CColorMsgBoxHook::SetColorBkgnd(COLORREF clrBkgnd)
{
	// ���ο� ��� ������ �����ϰ� �귯���� ���� �����
	m_clrBkgnd = clrBkgnd;
	if(m_brsBkgnd.m_hObject)		m_brsBkgnd.DeleteObject();
	m_brsBkgnd.CreateSolidBrush(m_clrBkgnd);
}

// �޽��� �ڽ� ��� �Լ�
int CColorMsgBoxHook::MessageBox(HWND hWnd, LPCTSTR lpszText, LPCTSTR lpszCaption, UINT nType)
{
	// �θ� �������� �ڵ��� �����Ѵ�
	m_hParent = hWnd;

	// ��ŷ�� �����ϰ�
	Install();
	// �޽��� �ڽ��� ����ϰ�
	int nRet = ::MessageBox(hWnd, lpszText, lpszCaption, nType);
	// ��ŷ�� �����Ѵ�
	Uninstall();

	return nRet;
}

// �޽��� �ڽ� ��� �Լ�
int CColorMsgBoxHook::AfxMessageBox(LPCTSTR lpszText, UINT nType, UINT nIDHelp)
{
	// ���� �������� �ڵ��� �����Ѵ�
	m_hParent = AfxGetMainWnd()->m_hWnd;

	// ��ŷ�� �����ϰ�
	Install();
	// �޽��� �ڽ��� ����ϰ�
	int nRet = ::AfxMessageBox(lpszText, nType, nIDHelp);
	// ��ŷ�� �����Ѵ�
	Uninstall();

	return nRet;
}

// �޽��� �ڽ� ��� �Լ�
int CColorMsgBoxHook::AfxMessageBox(UINT nIDPrompt, UINT nType, UINT nIDHelp)
{
	// ���� �������� �ڵ��� �����Ѵ�
	m_hParent = AfxGetMainWnd()->m_hWnd;

	// ��ŷ�� �����ϰ�
	Install();
	// �޽��� �ڽ��� ����ϰ�
	int nRet = ::AfxMessageBox(nIDPrompt, nType, nIDHelp);
	// ��ŷ�� �����Ѵ�
	Uninstall();

	return nRet;
}
