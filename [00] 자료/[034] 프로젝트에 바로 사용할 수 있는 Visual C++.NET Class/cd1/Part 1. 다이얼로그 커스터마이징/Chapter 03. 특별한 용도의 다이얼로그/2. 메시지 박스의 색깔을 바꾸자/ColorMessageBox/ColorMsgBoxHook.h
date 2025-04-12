#ifndef _COLOR_MESSAGE_BOX_HOOK_H_
#define _COLOR_MESSAGE_BOX_HOOK_H_

// �÷� �޽��� �ڽ� Ŭ����
class CColorMsgBoxHook
{
private:
protected:
	HINSTANCE		m_hInstance;				// ���α׷� �ν��Ͻ� �ڵ�

	HHOOK			m_hHook;					// ��ŷ �ڵ�
	WNDPROC			m_pOriginMsgBoxProc;		// ���� �޽��� �ڽ��� �޽��� ó�� �Լ�

	HWND			m_hMsgBox;					// �޽��� �ڽ��� ������ �ڵ�
	HWND			m_hParent;					// �޽��� �ڽ��� �θ� ������ �ڵ�

	COLORREF		m_clrText;					// �ؽ�Ʈ ��� ����
	COLORREF		m_clrBkgnd;					// ��� ����

	CBrush			m_brsBkgnd;					// ��� ��¿� �귯��

public:

private:
protected:

public:
	CColorMsgBoxHook();
	virtual ~CColorMsgBoxHook();

	void Install();								// ��ŷ�� �����ϴ� �Լ�
	void Uninstall();							// ��ŷ�� �����ϴ� �Լ�

	// ��ŷ �ڵ� ���� �Լ�
	HHOOK GetHookHandle()					{ return m_hHook; }
	// �޽��� �ڽ��� �޽��� ó�� �Լ� ����/���� �Լ� 
	WNDPROC GetOriginProc()					{ return m_pOriginMsgBoxProc; }
	void SetOriginProc(WNDPROC pProc)		{ m_pOriginMsgBoxProc = pProc; }
	// �޽��� �ڽ� ������ �ڵ� ����/���� �Լ�
	HWND GetMsgBoxHandle()					{ return m_hMsgBox; }
	void SetMsgBoxHandle(HWND hWnd)			{ m_hMsgBox = hWnd; }
	// �޽��� �ڽ��� �θ� ������ �ڵ� ����/���� �Լ�
	HWND GetParentHandle()					{ return m_hParent; }
	void SetParentHandle(HWND hWnd)			{ m_hParent = hWnd; }
	// �ؽ�Ʈ ���� ����/���� �Լ�
	COLORREF GetColorText()					{ return m_clrText; }
	void SetColorText(COLORREF clrText)		{ m_clrText = clrText; }
	// ��� ���� ����/���� �Լ�
	COLORREF GetColorBkgnd()				{ return m_clrBkgnd; }
	void SetColorBkgnd(COLORREF clrBkgnd);
	// ��� �귯�� ���� �Լ�
	HBRUSH GetBkgndBrush()					{ return (HBRUSH)m_brsBkgnd; }

	// �޽��� �ڽ� ��� �Լ�
	int MessageBox(HWND hWnd, LPCTSTR lpszText, LPCTSTR lpszCaption = NULL, UINT nType = MB_OK);

	int AfxMessageBox(LPCTSTR lpszText, UINT nType = MB_OK, UINT nIDHelp = 0);
	int AfxMessageBox(UINT nIDPrompt, UINT nType = MB_OK, UINT nIDHelp = (UINT) -1);
};

// �÷� �޽��� �ڽ� ���� ����
extern CColorMsgBoxHook g_MsgBoxHook;

#endif // _COLOR_MESSAGE_BOX_HOOK_H_