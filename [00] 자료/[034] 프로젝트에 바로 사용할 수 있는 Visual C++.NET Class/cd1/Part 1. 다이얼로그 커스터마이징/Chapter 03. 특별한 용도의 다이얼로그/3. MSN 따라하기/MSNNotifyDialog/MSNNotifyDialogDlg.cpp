// MSNNotifyDialogDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MSNNotifyDialog.h"
#include "MSNNotifyDialogDlg.h"

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


// CMSNNotifyDialogDlg ��ȭ ����



CMSNNotifyDialogDlg::CMSNNotifyDialogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMSNNotifyDialogDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMSNNotifyDialogDlg)
	m_nFontPoint = 9;
	m_strMessage = _T("");
	m_nTimeShow = 3000;
	m_nTimeUp = 20;
	m_nTimeDown = 20;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMSNNotifyDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMSNNotifyDialogDlg)
	DDX_Control(pDX, IDC_TEXT_COLOR_STATIC, m_clrText);
	DDX_Control(pDX, IDC_FONT_COMBO, m_FontCombo);
	DDX_Text(pDX, IDC_POINT_EDIT, m_nFontPoint);
	DDX_Text(pDX, IDC_MESSAGE_EDIT, m_strMessage);
	DDX_Text(pDX, IDC_SHOW_EDIT, m_nTimeShow);
	DDX_Text(pDX, IDC_UP_EDIT, m_nTimeUp);
	DDX_Text(pDX, IDC_DOWN_EDIT, m_nTimeDown);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMSNNotifyDialogDlg, CDialog)
	//{{AFX_MSG_MAP(CMSNNotifyDialogDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOW_MSG_BUTTON, OnShowMsgButton)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CMSNNotifyDialogDlg �޽��� ó����

// �ý����� ��Ʈ���� �޺� �ڽ��� �߰��ϴ� �Լ�
int CALLBACK EnumFontsProc(CONST LOGFONT *lplf, CONST TEXTMETRIC *lptm, DWORD dwType, LPARAM lParam) 
{
	CComboBox *pCombo = (CComboBox*)lParam;
	pCombo->AddString(lplf->lfFaceName);

	return TRUE; 
} 

BOOL CMSNNotifyDialogDlg::OnInitDialog()
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

	// �޽��� ���̾�α׸� �켱 �����Ѵ�
	m_MsgDlg.Create(IDD_MSG_DIALOG, this);
	// �޽��� ���̾�α��� ��� ��Ʈ���� �����Ѵ� : ��Ʈ�� ũ��� ���̾�α��� ũ�Ⱑ �����ȴ�.
	m_MsgDlg.SetBitmap(IDB_BKGND_BMP);
	
	// �ý����� ��Ʈ�� �޺� �ڽ��� �߰��Ѵ�
	CDC *pDC = GetDC();	
    EnumFonts(pDC->m_hDC, NULL, (FONTENUMPROC)EnumFontsProc, (LPARAM)&m_FontCombo); 
	ReleaseDC(pDC);

	// �⺻ �ؽ�Ʈ ������ �����Ѵ�
	m_clrText.m_clrColor	= RGB(70, 70, 70);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CMSNNotifyDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMSNNotifyDialogDlg::OnPaint() 
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
HCURSOR CMSNNotifyDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMSNNotifyDialogDlg::OnDestroy() 
{
	CDialog::OnDestroy();

	// �޽��� ���̾�α� �Ҹ�
	m_MsgDlg.DestroyWindow();
}

void CMSNNotifyDialogDlg::OnShowMsgButton() 
{
	UpdateData(TRUE);

	// ��Ʈ�� ���� �Ǿ����� Ȯ���Ѵ�
	if(m_FontCombo.GetCurSel() == CB_ERR)
	{
		MessageBox("��Ʈ �̸��� �����ϼ���.", "MSN �˸� â", MB_OK);
		return;
	}

	// ���õ� ��Ʈ �̸��� ��Ʈ ũ�⸦ �����Ѵ�
	CString strFontName;
	m_FontCombo.GetLBText(m_FontCombo.GetCurSel(), strFontName);
	m_MsgDlg.SetTextFont(strFontName, m_nFontPoint);
	// ����� �޽����� �����Ѵ�
	m_MsgDlg.SetMessage(m_strMessage);
	// �޽��� ��¿� ����� ������ �����Ѵ�
	m_MsgDlg.SetTextColor(m_clrText.m_clrColor);
	// �޽��� ��½� �ð� ���ݵ��� �����Ѵ�
	m_MsgDlg.SetTime(m_nTimeUp, m_nTimeShow, m_nTimeDown);
	// MSN �˸� â�� ����Ѵ�
	m_MsgDlg.Show();
}
