// FullScreenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "fullscreendialog.h"
#include "FullScreenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFullScreenDlg dialog


CFullScreenDlg::CFullScreenDlg(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CFullScreenDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFullScreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFullScreenDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFullScreenDlg, CDialog)
	//{{AFX_MSG_MAP(CFullScreenDlg)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFullScreenDlg message handlers

BOOL CFullScreenDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// ��ü ȭ�鿡 �����ϵ��� ������ ��Ÿ���� �����Ѵ�
	ModifyStyle(WS_THICKFRAME | WS_BORDER | WS_CAPTION, WS_SYSMENU);
	
	// �ʱ� ���̾�α� ũ�⸦ �����Ѵ�
	GetClientRect(&m_rcClient);

	// �ʱ� �۾� ���� ũ�⸦ �о� �����Ѵ�
	if(::SystemParametersInfo(SPI_GETWORKAREA, 0, &m_rcWorkArea, 0))
	{
		// �۾� ���� ũ�⸦ ��ü �������� �����Ѵ�
		::SystemParametersInfo(SPI_SETWORKAREA, 0, NULL, 0);
	}

	// �۾� ǥ������ �����͸� ȹ���Ѵ�
	CWnd* pTaskBar = CWnd::FindWindow("Shell_TrayWnd", "");
	if(pTaskBar)
	{
		// ���� ���̴� �������� �����Ѵ�
		m_bIsVisibleTaskBar = pTaskBar->IsWindowVisible();
		// �۾� ǥ������ �����
		pTaskBar->ShowWindow(SW_HIDE);
	}

	// ��ü ȭ�� ũ�⸦ ���Ѵ�
	int nScreenCX = ::GetSystemMetrics(SM_CXSCREEN);
	int nScreenCY = ::GetSystemMetrics(SM_CYSCREEN);

	// ���̾�α� ũ�⸦ ��ü ȭ�� ũ��� �����Ѵ�
	SetWindowPos(&wndTopMost, 0, 0, nScreenCX, nScreenCY, SWP_SHOWWINDOW);

	// ���̾�α��� ��Ʈ�ѵ��� �߾����� �̵���Ų��
	ScrollWindow((nScreenCX - m_rcClient.Width()) / 2, (nScreenCY - m_rcClient.Height()) / 2);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFullScreenDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// ���� �۾� ���� ũ��� ȯ�� ��Ų��
	::SystemParametersInfo(SPI_SETWORKAREA, 0, &m_rcWorkArea, 0);

	// �۾� ǥ������ �����͸� ȹ���Ѵ�
	CWnd* pTaskBar = CWnd::FindWindow("Shell_TrayWnd", "");
	if(pTaskBar)
		// �۾� ǥ������ �ʱ� ���·� �ǵ�����
		pTaskBar->ShowWindow(m_bIsVisibleTaskBar ? SW_SHOW : SW_HIDE);
}
