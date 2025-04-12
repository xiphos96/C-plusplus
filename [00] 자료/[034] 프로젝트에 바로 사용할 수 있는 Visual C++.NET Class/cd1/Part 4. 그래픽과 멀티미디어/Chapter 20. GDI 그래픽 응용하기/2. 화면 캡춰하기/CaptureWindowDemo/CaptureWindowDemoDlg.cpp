// CaptureWindowDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CaptureWindowDemo.h"
#include "CaptureWindowDemoDlg.h"

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


// CCaptureWindowDemoDlg ��ȭ ����



CCaptureWindowDemoDlg::CCaptureWindowDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCaptureWindowDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCaptureWindowDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCaptureWindowDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCaptureWindowDemoDlg)
	DDX_Control(pDX, IDC_SELECTOR_STATIC, m_CaptureWindow);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCaptureWindowDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CCaptureWindowDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SELECT_START, OnSelectStart)
	ON_MESSAGE(WM_SELECT_END, OnSelectEnd)
	ON_MESSAGE(WM_CAPTURE_FINISH, OnCaptureFinish)
END_MESSAGE_MAP()


// CCaptureWindowDemoDlg �޽��� ó����

BOOL CCaptureWindowDemoDlg::OnInitDialog()
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

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CCaptureWindowDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCaptureWindowDemoDlg::OnPaint() 
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
		CBitmap *pCapture = m_CaptureWindow.GetCapturedBitmap();

		if(pCapture->m_hObject)
		{
			CPaintDC dc(this);

			BITMAP bmpInfo;
			pCapture->GetBitmap(&bmpInfo);

			CDC MemDC;
			MemDC.CreateCompatibleDC(&dc);
			CBitmap *pOldBmp = MemDC.SelectObject(pCapture);

			dc.BitBlt(10, 40, bmpInfo.bmWidth, bmpInfo.bmHeight,
				&MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(pOldBmp);
			MemDC.DeleteDC();
		}

		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�. 
HCURSOR CCaptureWindowDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ������ ������ ���۵Ǿ��� �� ����Ǵ� �Լ�
LRESULT CCaptureWindowDemoDlg::OnSelectStart(WPARAM wParam, LPARAM lParam)
{
	CCaptureWindow *pCollector = (CCaptureWindow*)lParam;

	return 1;
}

// �����찡 ���õ� �� ����Ǵ� �Լ�
LRESULT CCaptureWindowDemoDlg::OnSelectEnd(WPARAM wParam, LPARAM lParam)
{
	CCaptureWindow *pCollector = (CCaptureWindow*)lParam;

	return 1;
}

// �����츦 ĸ���� �� ����Ǵ� �Լ�
LRESULT CCaptureWindowDemoDlg::OnCaptureFinish(WPARAM wParam, LPARAM lParam)
{
	CCaptureWindow *pCollector = (CCaptureWindow*)lParam;
	HWND hCaptured = (HWND)wParam;

	CBitmap *pCapture = pCollector->GetCapturedBitmap();

	if(pCapture->m_hObject)
	{
		BITMAP bmpInfo;
		pCapture->GetBitmap(&bmpInfo);

		int nWidth = bmpInfo.bmWidth + 20;
		if(nWidth < 465)		nWidth = 465;

		int nHeight = bmpInfo.bmHeight + 40 + 70;

		SetWindowPos(NULL, 0, 0, nWidth, nHeight, SWP_NOZORDER | SWP_NOMOVE);

		CRect rcButton;
		GetDlgItem(IDOK)->GetWindowRect(&rcButton);

		rcButton.left = nWidth - 10 - rcButton.Width();
		rcButton.right = nWidth - 10;
		rcButton.top = nHeight - 35 - rcButton.Height();
		rcButton.bottom = nHeight - 35;

		GetDlgItem(IDOK)->MoveWindow(&rcButton);

		CString strTitle;
		::GetWindowText(hCaptured, strTitle.GetBuffer(MAX_PATH), MAX_PATH);
		strTitle.ReleaseBuffer();

		CString strMessage;
		strMessage.Format("�����찡 ĸ�� �Ǿ����ϴ�.\n\nŸ��Ʋ : [%s]", strTitle);
		MessageBox(strMessage, "Capture Window", MB_OK);
	}
	else
		MessageBox("ĸ��� �����찡 �����ϴ�.", "Capture Window", MB_OK);

	return 1;
}
