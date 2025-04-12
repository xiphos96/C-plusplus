// RemInClientView.h : interface of the CRemInClientView class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include <atlddx.h>
#include "resource.h"

#import "progid:RemInServer.RemInServer.1" no_namespace named_guids

class CRemInClientView : public CDialogImpl<CRemInClientView>,
						  public CWinDataExchange<CRemInClientView>
{
public:
	enum { IDD = IDD_RemInCLIENT_FORM };

	CRemInClientView() {
		m_nInterfaceType = 0;
		m_nAddEnd = 0;
		m_nSum = 0;
	}

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		return CWindow::IsDialogMessage(pMsg);
	}

	BEGIN_MSG_MAP(CRemInClientView)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_HANDLER(IDC_CREATE, BN_CLICKED, OnCreateServer)
		COMMAND_HANDLER(IDC_RELEASE, BN_CLICKED, OnReleaseServer)
		COMMAND_HANDLER(IDC_ADD, BN_CLICKED, OnAdd)
		COMMAND_HANDLER(IDC_ADDTEN, BN_CLICKED, OnAddTen)
		COMMAND_HANDLER(IDC_CLEAR, BN_CLICKED, OnClear)
	END_MSG_MAP()

	BEGIN_DDX_MAP(CRemInClientView)
		DDX_RADIO(IDC_INTERFACE, m_nInterfaceType)
		DDX_INT(IDC_ADDEND, m_nAddEnd)
		DDX_INT(IDC_SUM, m_nSum)
	END_DDX_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

private:
	IAddEndPtr m_pAddEnd;
	IAddPtr m_pAdd;
	void ShowMessage(_com_error & e);

	COSERVERINFO svrInfo;
	MULTI_QI mqi[2];

	int		m_nInterfaceType;
	SHORT	m_nAddEnd;
	SHORT	m_nSum;
public:
	LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&) {
		DoDataExchange(FALSE);
		return 0;
	}
	LRESULT OnCreateServer(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnReleaseServer(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnAdd(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnAddTen(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnClear(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};
