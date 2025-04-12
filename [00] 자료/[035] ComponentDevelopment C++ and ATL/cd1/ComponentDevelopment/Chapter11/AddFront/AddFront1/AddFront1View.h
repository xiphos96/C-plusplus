// AddFront1View.h : interface of the CAddFront1View class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include "resource.h"

class CAddFront1View : public CDialogImpl<CAddFront1View>,
					   public CWinDataExchange<CAddFront1View> 
{
public:
	enum { IDD = IDD_AddFront1_FORM };

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		return CWindow::IsDialogMessage(pMsg);
	}

	BEGIN_MSG_MAP(CAddFront1View)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_HANDLER(IDC_ADD, BN_CLICKED, OnBnClickedAdd)
		COMMAND_HANDLER(IDC_ADDTEN, BN_CLICKED, OnBnClickedAddten)
		COMMAND_HANDLER(IDC_CLEAR, BN_CLICKED, OnBnClickedClear)
	END_MSG_MAP()

	BEGIN_DDX_MAP(CAddFront1View)
		DDX_INT(IDC_ADDEND, m_AddEnd)
		DDX_INT(IDC_SUM, m_Sum)
	END_DDX_MAP()


// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&); 
LRESULT OnBnClickedAdd(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
LRESULT OnBnClickedAddten(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
LRESULT OnBnClickedClear(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
private:
	SHORT m_AddEnd;
	SHORT m_Sum;
	DWORD m_Cookie;
	IAddBackPtr m_pAddBack;
	IAddEndPtr m_pAddEnd;
};
