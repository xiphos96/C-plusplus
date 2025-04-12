// ClientView.h : interface of the CClientView class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include <atlctrls.h>
#include <atlddx.h>
#include "resource.h"

#import "progid:Company.Company.1" no_namespace

class CClientView : public CDialogImpl<CClientView>,
					public CWinDataExchange<CClientView>
{
public:
	enum { IDD = IDD_CLIENT_FORM };

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		return CWindow::IsDialogMessage(pMsg);
	}

	BEGIN_MSG_MAP(CClientView)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_HANDLER(IDC_BUTTON1, BN_CLICKED, OnBnClickedButton1)
		COMMAND_HANDLER(IDC_BUTTON2, BN_CLICKED, OnBnClickedButton2)
		COMMAND_HANDLER(IDC_BUTTON3, BN_CLICKED, OnBnClickedButton3)
		COMMAND_HANDLER(IDC_BUTTON4, BN_CLICKED, OnBnClickedButton4)
	END_MSG_MAP()

	BEGIN_DDX_MAP(CAddFront1View)
		DDX_TEXT(IDC_NAME, m_name)
		DDX_TEXT(IDC_ADDR, m_addr)
		DDX_TEXT(IDC_PHONE, m_phone)
	END_DDX_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
LRESULT OnBnClickedButton1(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
LRESULT OnBnClickedButton2(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
LRESULT OnBnClickedButton3(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	
	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/) {
		m_list.Attach(GetDlgItem(IDC_LIST));
		m_edit.Attach(GetDlgItem(IDC_NAME));
		m_pCompany = new ICompanyPtr(__uuidof(CCompany));
		m_pEmployees = m_pCompany->Employees;
		return 0;
	}

private:
	CListBox m_list;
	CEdit m_edit;
	ICompanyPtr m_pCompany;
	IEmployeesPtr m_pEmployees;
	IEmployeePtr m_pEmployee;

	TCHAR m_name[128];
	TCHAR m_addr[128];
	TCHAR m_phone[128];

public:
	LRESULT OnBnClickedButton4(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};
