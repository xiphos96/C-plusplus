// ExplorerListCtrlDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ExplorerListCtrlDemo.h"
#include "ExplorerListCtrlDemoDlg.h"

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


// CExplorerListCtrlDemoDlg ��ȭ ����



CExplorerListCtrlDemoDlg::CExplorerListCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExplorerListCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExplorerListCtrlDemoDlg)
	m_nType = 3;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExplorerListCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExplorerListCtrlDemoDlg)
	DDX_Control(pDX, IDC_DRIVE_COMBO, m_DriveCombo);
	DDX_Control(pDX, IDC_EXPLORER_LIST, m_ExplorerListCtrl);
	DDX_Radio(pDX, IDC_ICON_RADIO, m_nType);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExplorerListCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CExplorerListCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ICON_RADIO, OnIconRadio)
	ON_BN_CLICKED(IDC_SMALL_ICON_RADIO, OnSmallIconRadio)
	ON_BN_CLICKED(IDC_LIST_RADIO, OnListRadio)
	ON_BN_CLICKED(IDC_REPORT_RADIO, OnReportRadio)
	ON_BN_CLICKED(IDC_GO_UP_BUTTON, OnGoUpButton)
	ON_CBN_SELCHANGE(IDC_DRIVE_COMBO, OnSelchangeDriveCombo)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_EXPLORER_FILE_SELECT, OnExplorerFileSelecct)
END_MESSAGE_MAP()


// CExplorerListCtrlDemoDlg �޽��� ó����

BOOL CExplorerListCtrlDemoDlg::OnInitDialog()
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

	SHFILEINFO		ShellFileInfo;

	HIMAGELIST hSmallIcon = (HIMAGELIST)::SHGetFileInfo("c:\\", 0, &ShellFileInfo, sizeof(SHFILEINFO),
		SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_SMALLICON);

	CImageList SmallImageList;
	SmallImageList.Attach(hSmallIcon);

	m_DriveCombo.SetImageList(&SmallImageList);

	SmallImageList.Detach();

	DWORD dwDrive = ::GetLogicalDrives();
	int i, nCount;

	for(nCount = i = 0; i < 32; i++)
	{
		if(dwDrive & ((DWORD)0x01 << i))		nCount++;
	}

	char *pDriveName = new char[nCount * 4 + 1];
	::GetLogicalDriveStrings(nCount * 4 + 1, pDriveName);
	
	COMBOBOXEXITEM	ComboExItem;
	ComboExItem.mask = CBEIF_IMAGE | CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
	ComboExItem.iItem = -1;					// Insert at end

	int nDrive = -1;
	for(i = 0; i < nCount; i++)
	{
		ComboExItem.pszText			= pDriveName + i * 4;
		ComboExItem.iImage			= m_ExplorerListCtrl.FindIconIndex(pDriveName, TRUE);
		ComboExItem.iSelectedImage	= ComboExItem.iImage;

		m_DriveCombo.InsertItem(&ComboExItem);

		if(pDriveName[i * 4] == 'C')	nDrive = i;
	}

	delete[] pDriveName;

	m_DriveCombo.SetCurSel(nDrive);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CExplorerListCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExplorerListCtrlDemoDlg::OnPaint() 
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
HCURSOR CExplorerListCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExplorerListCtrlDemoDlg::OnIconRadio() 
{
	// ����Ʈ ��Ʈ���� Ÿ���� ������ Ÿ������ �����Ѵ�
	m_ExplorerListCtrl.ModifyStyle(LVS_TYPEMASK, LVS_ICON);
}

void CExplorerListCtrlDemoDlg::OnSmallIconRadio() 
{
	// ����Ʈ ��Ʈ���� Ÿ���� ���� ������ Ÿ������ �����Ѵ�
	m_ExplorerListCtrl.ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);
}

void CExplorerListCtrlDemoDlg::OnListRadio() 
{
	// ����Ʈ ��Ʈ���� Ÿ���� ����Ʈ Ÿ������ �����Ѵ�
	m_ExplorerListCtrl.ModifyStyle(LVS_TYPEMASK, LVS_LIST);
}

void CExplorerListCtrlDemoDlg::OnReportRadio() 
{
	// ����Ʈ ��Ʈ���� Ÿ���� ����Ʈ Ÿ������ �����Ѵ�
	m_ExplorerListCtrl.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
}

void CExplorerListCtrlDemoDlg::OnGoUpButton() 
{
	m_ExplorerListCtrl.GoUp();
}

void CExplorerListCtrlDemoDlg::OnSelchangeDriveCombo() 
{
	int nSel = m_DriveCombo.GetCurSel();

	if(nSel == CB_ERR)		return;

	CString strDrive;
	
	m_DriveCombo.GetLBText(nSel, strDrive);
	m_ExplorerListCtrl.ChangeDrive(strDrive);
}

LRESULT CExplorerListCtrlDemoDlg::OnExplorerFileSelecct(WPARAM wParam, LPARAM lParam)
{
	MessageBox((LPCTSTR)lParam, "���� ����", MB_ICONINFORMATION | MB_OK);
	return 0;
}
