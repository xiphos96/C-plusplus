#pragma once

// �������� Ŭ������ ���� ����
class CWebBrowser2;


// �������� ���� Ŭ����
class CExplorerPopup
{
	// OpenNewWindowEx()�� ������ ���������� ������ �ڵ� ���� ����
	HWND	m_hExplorer;

public:
	// ������
	CExplorerPopup();
	// �Ҹ���
	virtual ~CExplorerPopup();

	// ShellExecute()�� ����Ͽ� ����Ʈ�� ���� �Լ�
	BOOL OpenByShellExecute(LPCTSTR pAddress);
	// IWebBrowser2�� ����Ͽ� ����Ʈ�� ���� �Լ�
	BOOL OpenNewWindow(LPCTSTR pAddress);
	// CWebBrowser2 Ŭ������ ����Ͽ� ����Ʈ�� ���� �Լ�
	BOOL OpenNewWindow(LPCTSTR pAddress, CWebBrowser2 *pBrowser);
	// IWebBrowser2�� ����Ͽ� ���������� �����ϰ� �ɼ� ���� �� ����Ʈ�� ���� �Լ�
	BOOL OpenNewWindowEx(LPCTSTR pAddress, BOOL bMenu = TRUE, BOOL bToolBar = TRUE,
		BOOL bAddressBar = TRUE, BOOL bStatusBar = TRUE, BOOL bResize = TRUE,
		int x = -1, int y = -1, int cx = -1, int cy = -1);
	// OpenNewWindowEx()�� ����Ͽ� ������ ���������� �ݴ� �Լ�
	BOOL CloseExplorer();
};