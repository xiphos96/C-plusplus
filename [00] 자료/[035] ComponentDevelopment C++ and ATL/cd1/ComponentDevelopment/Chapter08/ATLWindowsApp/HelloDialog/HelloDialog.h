#import "progid:HelloServer.Hello.1" no_namespace named_guids

class CHelloDialog : public CDialogImpl<CHelloDialog>
{
public:

	BEGIN_MSG_MAP(CHelloDialog)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDC_SAYHELLO, OnSayHello)
	END_MSG_MAP()

	enum {IDD = IDD_DIALOG };

private:
	LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&) {
		CenterWindow();
		m_name.Attach(GetDlgItem(IDC_NAME));
		m_message.Attach(GetDlgItem(IDC_MESSAGE));
		m_name.SetWindowText("Àüº´¼±");
		m_name.SetFocus();
		return 0;
	}
	LRESULT OnOK(WORD, UINT, HWND, BOOL&) {
		EndDialog(IDOK);
		return 0;
	}
	LRESULT OnSayHello(WORD, UINT, HWND, BOOL&) {
		TCHAR name[128];
		LPCTSTR message;
		m_name.GetWindowText(name, 127);

		CComQIPtr<IHello, &IID_IHello> pHello;
		pHello.CoCreateInstance(CLSID_CHello);
		pHello->sayHello((wchar_t*)name, (wchar_t**)&message);
		m_message.SetWindowText(message);
		::CoTaskMemFree((LPVOID)message);

		return 0;
	}
	CWindow m_name;
	CWindow m_message;
};
