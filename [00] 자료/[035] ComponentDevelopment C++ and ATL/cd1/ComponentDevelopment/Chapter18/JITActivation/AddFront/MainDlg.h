// MainDlg.h : interface of the CAddFrontDlg class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <atlddx.h>
#include "resource.h"

#import "progid:AddBack.AddBack.1" 
#import "progid:AddBack_Stateless.AddBack.1" 

class CAddFrontDlg : public CDialogImpl<CAddFrontDlg>,
					 public CWinDataExchange<CAddFrontDlg>
{
public:
	enum { IDD = IDD_MAINDLG };

	BEGIN_MSG_MAP(CAddFrontDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_HANDLER(IDC_BUTTON1, BN_CLICKED, OnBnClickedButton1)
		COMMAND_HANDLER(IDC_BUTTON2, BN_CLICKED, OnBnClickedButton2)
	END_MSG_MAP()

	BEGIN_DDX_MAP(CAddFrontDlg)
		DDX_INT(IDC_EDIT1, m_sum)
		DDX_INT(IDC_EDIT2, m_addend)
	END_DDX_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		// center the dialog on the screen
		CenterWindow();

		// set icons
		HICON hIcon = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME), 
			IMAGE_ICON, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON), LR_DEFAULTCOLOR);
		SetIcon(hIcon, TRUE);
		HICON hIconSmall = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME), 
			IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
		SetIcon(hIconSmall, FALSE);

		m_pIAddBack = AddBackLib::IAddBackPtr(__uuidof(AddBackLib::AddBack));
		m_pIAddBack_Stateless = AddBack_StatelessLib::IAddBackPtr(__uuidof(AddBack_StatelessLib::AddBack));
		m_addend = 10;
		m_sum = m_pIAddBack->getSum();
		DoDataExchange(FALSE);

		return TRUE;
	}

	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		// TODO: Add validation code 
		EndDialog(wID);
		return 0;
	}
protected:
	AddBackLib::IAddBackPtr m_pIAddBack;
	AddBack_StatelessLib::IAddBackPtr m_pIAddBack_Stateless;
public:
	long m_addend;
	long m_sum;
	LRESULT OnBnClickedButton1(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedButton2(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};
