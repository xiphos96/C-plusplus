// ResizeDialogDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ResizeDialog.h"
#include "ResizeDialogDlg.h"

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


// CResizeDialogDlg ��ȭ ����



CResizeDialogDlg::CResizeDialogDlg(CWnd* pParent /*=NULL*/)
	: CResizeDlg(CResizeDialogDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResizeDialogDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CResizeDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CResizeDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResizeDialogDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CResizeDialogDlg, CResizeDlg)
	//{{AFX_MSG_MAP(CResizeDialogDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CResizeDialogDlg �޽��� ó����

BOOL CResizeDialogDlg::OnInitDialog()
{
	CResizeDlg::OnInitDialog();

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

	// ���̾�α��� �� ��Ʈ�ѵ鿡 ����,
	// ���̾�α� ũ�� ��ȭ�� ���ġ �ɼ��� �����Ѵ�

	// �ؽ�Ʈ ����ƽ���� ���ġ���� �ʴ´�
	SetChildType(GetDlgItem(IDC_TEXT_STATIC1), RE_NONE);
	SetChildType(GetDlgItem(IDC_TEXT_STATIC2), RE_NONE);
	SetChildType(GetDlgItem(IDC_TEXT_STATIC3), RE_NONE);

	// ����Ʈ �ڽ����� ���� ���� ���̾�α� ������ �������� ��ġ�� �����Ѵ�
	SetChildType(GetDlgItem(IDC_EDIT1), RE_INV_X2);
	SetChildType(GetDlgItem(IDC_EDIT2), RE_INV_X2);
	SetChildType(GetDlgItem(IDC_EDIT3), RE_INV_X2);

	// �׷� �ڽ��� ���� ���� ���̾�α� ������ �������� ��ġ�� �����ϰ�
	// �Ʒ��� ���� ���̾�α� �Ʒ��� �������� ��ġ�� �����Ѵ�
	SetChildType(GetDlgItem(IDC_GROUP_STATIC), RE_INV_X2 | RE_INV_Y2);

	// ���� ������ ���� ���� ���̾�α� ������ �������� ��ġ�� �����Ѵ�
	SetChildType(GetDlgItem(IDC_MENT_STATIC), RE_INV_X2);

	// ������ ���� ���� ���̾�α� ������ �������� ��ġ�� �����Ѵ�
	SetChildType(GetDlgItem(IDC_LINE_STATIC), RE_INV_X2);
	
	// ���α׷����ٴ� ���� ���� ���̾�α� ������ �������� ��ġ�� �����ϰ�
	// �Ʒ��� ���� ���̾�α� �Ʒ��� �������� ��ġ�� �����Ѵ�
	SetChildType(GetDlgItem(IDC_PROGRESS1), RE_INV_X2 | RE_INV_Y2);
	
	// ��ư�� ���� ���� ���̾�α� �Ʒ��� �������� ��ġ�� �����ϰ�
	// ���� ���� ���̾�α� ������ �������� �����ϰ�
	// �Ʒ��� ���� ���̾�α� �Ʒ��� �������� �����Ѵ�
	SetChildType(GetDlgItem(IDC_BUTTON1), RE_INV_Y1 | RE_X2 | RE_INV_Y2);

	// �޺� �ڽ��� ���� ���� ������� ���� �������� �����ϰ�
	// ���� ���� ���̾�α� �Ʒ��� �������� �����ϰ�
	// ���� ���� ���̾�α� ������ �������� �����ϰ�
	// �Ʒ��� ���� ���̾�α� �Ʒ��� �������� �����Ѵ�
	SetChildType(GetDlgItem(IDC_COMBO1), RE_X1 | RE_INV_Y1 | RE_INV_X2 | RE_INV_Y2);

	// üũ �ڽ��� ���� ���� ���̾�α� ������ �������� ��ġ�� �����ϰ�
	// ���� ���� ���̾�α� �Ʒ��� �������� �����ϰ�
	// ���� ���� ���̾�α� ������ �������� ��ġ�� �����ϰ�
	// �Ʒ��� ���� ���̾�α� �Ʒ��� �������� �����Ѵ�
	SetChildType(GetDlgItem(IDC_CHECK1), RE_INV_ALL);

	// Ȯ�� ��ư�� ���� ���� ���̾�α� ������ �������� ��ġ�� �����ϰ�
	// ���� ���� ���̾�α� �Ʒ��� �������� �����ϰ�
	// ���� ���� ���̾�α� ������ �������� �����ϰ�
	// �Ʒ��� ���� ���̾�α� �Ʒ��� �������� �����Ѵ�
	SetChildType(GetDlgItem(IDOK), RE_INV_ALL);

	// ��� ��ư�� ���� ���� ���̾�α� ������ �������� ��ġ�� �����ϰ�
	// ���� ���� ���̾�α� �Ʒ��� �������� �����ϰ�
	// ���� ���� ���̾�α� ������ �������� �����ϰ�
	// �Ʒ��� ���� ���̾�α� �Ʒ��� �������� �����Ѵ�
	SetChildType(GetDlgItem(IDCANCEL), RE_INV_ALL);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CResizeDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CResizeDlg::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CResizeDialogDlg::OnPaint() 
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
		CResizeDlg::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�. 
HCURSOR CResizeDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
