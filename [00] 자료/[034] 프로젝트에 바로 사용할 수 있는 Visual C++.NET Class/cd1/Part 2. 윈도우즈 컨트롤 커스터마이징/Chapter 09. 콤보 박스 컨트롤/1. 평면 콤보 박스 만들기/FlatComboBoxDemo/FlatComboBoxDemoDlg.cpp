// FlatComboBoxDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "FlatComboBoxDemo.h"
#include "FlatComboBoxDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� ������
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ����
	//}}AFX_VIRTUAL

// ����
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CFlatComboBoxDemoDlg ��ȭ ����



CFlatComboBoxDemoDlg::CFlatComboBoxDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFlatComboBoxDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFlatComboBoxDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFlatComboBoxDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFlatComboBoxDemoDlg)
	DDX_Control(pDX, IDC_DROPLIST_COMBO, m_DropListCombo);
	DDX_Control(pDX, IDC_DROPDOWN_COMBO, m_DropDownCombo);
	DDX_Control(pDX, IDC_AUTOCOMPLETE_COMBO, m_AutoComplete);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFlatComboBoxDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CFlatComboBoxDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DROPLIST_CHECK, OnDroplistCheck)
	ON_BN_CLICKED(IDC_DROPDOWN_CHECK, OnDropdownCheck)
	ON_BN_CLICKED(IDC_AUTOCOMPLETE_CHECK, OnAutocompleteCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CFlatComboBoxDemoDlg �޽��� ó����

BOOL CFlatComboBoxDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	// �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// ��� ����Ʈ ���� �޺� �ڽ��� ���ڿ����� �߰��Ѵ�
	m_DropListCombo.AddString("������ �������� �Դٰ� ��� �״´�.");
	m_DropListCombo.AddString("2�� �ٶ��� ���� �� ���� ���׶�����.");
	m_DropListCombo.AddString("�ɻ������� �� ������ ��� �״´�.");
	m_DropListCombo.AddString("����� �� �� ���������� ����������.");
	m_DropListCombo.AddString("�޹���, �޹����� ��Ÿ���� �� �� ¡���̴�.");
	m_DropListCombo.AddString("���̰� ������ �̻縦 �ϸ� �� �� ¡���̴�.");
	m_DropListCombo.AddString("7�� �帶 ������ ���ܴ� ���� �൵ �ȸԴ´�.");
	m_DropListCombo.AddString("ó���� ������ ��⵵ ���� ��Ծ�����.");
	m_DropListCombo.AddString("���� �Ȱ��� ����� �ð� ���Ȱ��� ����� �ش�.");
	m_DropListCombo.AddString("���� ��ǳ�� �칰�� ������.");
	m_DropListCombo.AddString("������� �ѹ� �ö����� �߿�����.");
	m_DropListCombo.AddString("�ܿ￡ ���� ���� ���� ���� ǳ���� ���.");
	
	// ��� �ٿ� ���� �޺� �ڽ��� ���ڿ����� �߰��Ѵ�
	m_DropDownCombo.AddString("������ �������� �Դٰ� ��� �״´�.");
	m_DropDownCombo.AddString("2�� �ٶ��� ���� �� ���� ���׶�����.");
	m_DropDownCombo.AddString("�ɻ������� �� ������ ��� �״´�.");
	m_DropDownCombo.AddString("����� �� �� ���������� ����������.");
	m_DropDownCombo.AddString("�޹���, �޹����� ��Ÿ���� �� �� ¡���̴�.");
	m_DropDownCombo.AddString("���̰� ������ �̻縦 �ϸ� �� �� ¡���̴�.");
	m_DropDownCombo.AddString("7�� �帶 ������ ���ܴ� ���� �൵ �ȸԴ´�.");
	m_DropDownCombo.AddString("ó���� ������ ��⵵ ���� ��Ծ�����.");
	m_DropDownCombo.AddString("���� �Ȱ��� ����� �ð� ���Ȱ��� ����� �ش�.");
	m_DropDownCombo.AddString("���� ��ǳ�� �칰�� ������.");
	m_DropDownCombo.AddString("������� �ѹ� �ö����� �߿�����.");
	m_DropDownCombo.AddString("�ܿ￡ ���� ���� ���� ���� ǳ���� ���.");
	
	// �ڵ� �ϼ� ��� �ٿ� ����Ʈ�� ���ڿ����� �߰��Ѵ�
	m_AutoComplete.AddString("In the beginning, God created the heavens and the earth.");
	m_AutoComplete.AddString("The earth was without form and void, and darkness was over the face of the deep.");
	m_AutoComplete.AddString("And the Spirit of God was hovering over the face of the waters.");
	m_AutoComplete.AddString("And God said, \"Let there be light,\" and there was light.");
	m_AutoComplete.AddString("And God saw that the light was good.");
	m_AutoComplete.AddString("And God separated the light from the darkness.");
	m_AutoComplete.AddString("God called the light Day, and the darkness he called Night.");
	m_AutoComplete.AddString("And there was evening and there was morning, the first day.");
	m_AutoComplete.AddString("And God said, \"Let there be an expanse in the midst of the waters,");
	m_AutoComplete.AddString("and let it separate the waters from the waters.\"");
	m_AutoComplete.AddString("And God made the expanse and separated the waters");
	m_AutoComplete.AddString("that were under the expanse from the waters that were above the expanse.");
	m_AutoComplete.AddString("And it was so.");
	m_AutoComplete.AddString("And God called the expanse Heaven.");
	
	// üũ �ڽ����� üũ�� ���·� �����
	((CButton*)GetDlgItem(IDC_DROPLIST_CHECK))->SetCheck(1);
	((CButton*)GetDlgItem(IDC_DROPDOWN_CHECK))->SetCheck(1);
	((CButton*)GetDlgItem(IDC_AUTOCOMPLETE_CHECK))->SetCheck(1);

	// �ڵ� �ϼ� ����� �����Ѵ�
	m_AutoComplete.EnableAutoComplete(TRUE);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CFlatComboBoxDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CFlatComboBoxDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�. 
HCURSOR CFlatComboBoxDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFlatComboBoxDemoDlg::OnDroplistCheck() 
{
	// ��� ����Ʈ �޺��ڽ� Ȱ��ȭ üũ ��ư�� ���¿� ���� ��� ����Ʈ �޺��ڽ��� Ȱ��ȭ ��Ų��
	m_DropListCombo.EnableWindow(((CButton*)GetDlgItem(IDC_DROPLIST_CHECK))->GetCheck());
}

void CFlatComboBoxDemoDlg::OnDropdownCheck() 
{
	// ��� �ٿ� �޺��ڽ� Ȱ��ȭ üũ ��ư�� ���¿� ���� ��� �ٿ� �޺��ڽ��� Ȱ��ȭ ��Ų��
	m_DropDownCombo.EnableWindow(((CButton*)GetDlgItem(IDC_DROPDOWN_CHECK))->GetCheck());
}

void CFlatComboBoxDemoDlg::OnAutocompleteCheck() 
{
	// �ڵ� �ϼ� �޺��ڽ� Ȱ��ȭ üũ ��ư�� ���¿� ���� �ڵ� �ϼ� �޺��ڽ��� Ȱ��ȭ ��Ų��
	m_AutoComplete.EnableWindow(((CButton*)GetDlgItem(IDC_AUTOCOMPLETE_CHECK))->GetCheck());
}
