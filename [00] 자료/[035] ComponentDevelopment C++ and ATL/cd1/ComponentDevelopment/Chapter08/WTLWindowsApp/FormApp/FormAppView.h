// FormAppView.h : interface of the CFormAppView class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#import "progid:HelloServer.Hello.1" no_namespace named_guids

class CFormView : public CDialogImpl<CFormView>,
				  public CWinDataExchange<CFormView>
{
public:
	enum { IDD = IDD_FORMAPP_FORM };

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		return CWindow::IsDialogMessage(pMsg);
	}

	BEGIN_MSG_MAP(CFormAppView)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDC_SAYHELLO, OnSayHello)
	END_MSG_MAP()

	BEGIN_DDX_MAP(CFormView)
		DDX_TEXT(IDC_MESSAGE, m_message)
		DDX_TEXT(IDC_NOTE, m_note)
		DDX_CONTROL_HANDLE(IDC_NAMES, m_names)
	END_DDX_MAP()

	LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&) {
		memset(m_message, 0, 127);
		strcpy(m_note, "반갑습니다.");

		DoDataExchange(FALSE);
		
		m_names.AddString("전병선");
		m_names.AddString("이영");
		m_names.AddString("전민");
		m_names.AddString("전원");
		m_names.SetCurSel(0);
		m_names.SetFocus();
		
		return 0;
	}
	LRESULT OnSayHello(WORD, UINT, HWND, BOOL&) {
		TCHAR name[128];
		LPCTSTR message;
		
		DoDataExchange(TRUE);

		int index = m_names.GetCurSel();
		m_names.GetText(index, name);
		CComQIPtr<IHello, &IID_IHello> pHello;
		pHello.CoCreateInstance(CLSID_CHello);
		pHello->sayHello((wchar_t*)name, (wchar_t**)&message);

		strcpy(m_message, message);
		strcat(m_message, " ");
		strcat(m_message, m_note);

		::CoTaskMemFree((LPVOID)message);

		DoDataExchange(FALSE);

		return 0;
	}

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
private:
	CListBox m_names;
	TCHAR m_note[128];
	TCHAR m_message[128];
};
