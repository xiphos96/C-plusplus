// AddFront2View.h : interface of the CAddFront2View class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include "resource.h"

class CAddFront2View : public CDialogImpl<CAddFront2View>,
					   public CWinDataExchange<CAddFront2View> 
{
public:
	enum { IDD = IDD_AddFront2_FORM };

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		return CWindow::IsDialogMessage(pMsg);
	}

	BEGIN_MSG_MAP(CAddFront2View)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		COMMAND_HANDLER(IDC_ADD, BN_CLICKED, OnBnClickedAdd)
		COMMAND_HANDLER(IDC_ADDTEN, BN_CLICKED, OnBnClickedAddten)
		COMMAND_HANDLER(IDC_CLEAR, BN_CLICKED, OnBnClickedClear)
	END_MSG_MAP()

	BEGIN_DDX_MAP(CAddFront2View)
		DDX_INT(IDC_ADDEND, m_AddEnd)
		DDX_INT(IDC_SUM, m_Sum)
	END_DDX_MAP()


// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&); 
LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&); 
LRESULT OnBnClickedAdd(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
LRESULT OnBnClickedAddten(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
LRESULT OnBnClickedClear(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
private:
	SHORT m_AddEnd;
	SHORT m_Sum;
	DWORD m_Cookie;
	IAddBackPtr m_pAddBack;
	CComObject<CEventHandler>* m_pHandler;
};
