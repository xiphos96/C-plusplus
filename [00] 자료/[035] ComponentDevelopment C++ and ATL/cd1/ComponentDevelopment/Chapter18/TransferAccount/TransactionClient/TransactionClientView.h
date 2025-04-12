// TransactionClientView.h : interface of the CTransactionClientView class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include <atlddx.h>
#include "resource.h"

class CTransactionClientView : public CDialogImpl<CTransactionClientView>,
								public CWinDataExchange<CTransactionClientView>
{
public:
	enum { IDD = IDD_TRANSACTIONCLIENT_FORM };

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		return CWindow::IsDialogMessage(pMsg);
	}

	BEGIN_MSG_MAP(CTransactionClientView)
		COMMAND_HANDLER(IDC_BUTTON1, BN_CLICKED, TransferMoney)
	END_MSG_MAP()

	BEGIN_DDX_MAP(CRemInClientView)
		DDX_INT(IDC_EDIT1, m_srcAccount)
		DDX_INT(IDC_EDIT2, m_destAccount)
		DDX_INT(IDC_EDIT3, m_amount)
	END_DDX_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
private:
	long m_srcAccount;
	long m_destAccount;
	long m_amount;
public:
	LRESULT TransferMoney(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};
