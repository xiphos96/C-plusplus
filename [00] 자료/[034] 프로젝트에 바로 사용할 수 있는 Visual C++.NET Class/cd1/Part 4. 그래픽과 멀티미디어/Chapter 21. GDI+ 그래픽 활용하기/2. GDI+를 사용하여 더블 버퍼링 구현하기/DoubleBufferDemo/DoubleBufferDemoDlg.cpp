// DoubleBufferDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "DoubleBufferDemo.h"
#include "DoubleBufferDemoDlg.h"

#include "DoubleBuffer.h"

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


// CDoubleBufferDemoDlg ��ȭ ����



CDoubleBufferDemoDlg::CDoubleBufferDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDoubleBufferDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDoubleBufferDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDoubleBufferDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDoubleBufferDemoDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDoubleBufferDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDoubleBufferDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CDoubleBufferDemoDlg �޽��� ó����

BOOL CDoubleBufferDemoDlg::OnInitDialog()
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

	// ���̾�α� DC���� Graphics ��ü�� �����Ѵ�
	CDC *pDC = GetDC();
	Graphics graphics(pDC->m_hDC);

	// �ؽ�Ʈ ����� ���� ��Ʈ�� ��ǥ ������ �����Ѵ�
	Font font(L"����ü", 16);
	PointF origin(0, 0);
	RectF rcString;

	// �޽��� �ؽ�Ʈ�� �����Ѵ�
	m_strMessage = "������۸��� ����� �ؽ�Ʈ ��ũ���Դϴ�.";

	// �ؽ�Ʈ�� ���� BSTR�� ��´�
	BSTR bstrMessage = m_strMessage.AllocSysString();
	// �ؽ�Ʈ ��¿� �ʿ��� ũ�⸦ ����Ѵ�
	graphics.MeasureString(bstrMessage, ::wcslen(bstrMessage),
		&font, origin, &rcString);
	// BSTR �޸𸮸� �����Ѵ�
	::SysFreeString(bstrMessage);

	// �ؽ�Ʈ ��� ũ�⸦ �����Ѵ�
	m_TextSize.cx = (LONG)rcString.Width;
	m_TextSize.cy = (LONG)rcString.Height;

	ReleaseDC(pDC);

	GetClientRect(&m_rcClient);

	// �ʱ� �ؽ�Ʈ ��� ��ġ�� ���������� �Ѵ�
	m_nCurPos = m_rcClient.right;

	// Ÿ�̸Ӹ� �����Ѵ�
	SetTimer(1, 1, NULL);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CDoubleBufferDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDoubleBufferDemoDlg::OnPaint() 
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
		// ���� ���۸� ��ü�� �����Ѵ�
		CGraphics dbGraphics(m_hWnd);
		// ���� ���۸� ��ü���� Graphics �����͸� ��´�
		Graphics *pGraphics = dbGraphics.GetGraphics();

		// Graphics �����͸� ����Ͽ� ����� ���� �귯���� ĥ�Ѵ�
		Rect rect(0, 0, m_rcClient.Width(), m_rcClient.Height());
		SolidBrush BlackBrush(Color::Black);
		pGraphics->FillRectangle(&BlackBrush, rect);

		// �ؽ�Ʈ ����� ���� ��Ʈ�� �귯���� �����ϰ� ��ǥ�� ����Ѵ�
		Font font(L"����ü", 16);
		SolidBrush WhiteBrush(Color::White);
		PointF origin((REAL)m_nCurPos, (REAL)(m_rcClient.Height() - m_TextSize.cy) / 2);

		// �׷��� ��� ǰ���� ��Ƽ�ٸ�������� �����Ѵ�
		pGraphics->SetSmoothingMode(SmoothingModeAntiAlias);

		// �ؽ�Ʈ ��� ǰ���� ��Ƽ�ٸ�������� �����Ѵ�
		pGraphics->SetTextRenderingHint(TextRenderingHintAntiAlias);

		// �ؽ�Ʈ�� ���� BSTR�� ��´�
		BSTR bstrMessage = m_strMessage.AllocSysString();
		// �޽��� �ؽ�Ʈ�� ���� ��ġ�� �Ͼ� �� �귯���� ����Ѵ�
		pGraphics->DrawString(bstrMessage, ::wcslen(bstrMessage),
			&font, origin, &WhiteBrush);
		// BSTR �޸𸮸� �����Ѵ�
		::SysFreeString(bstrMessage);

		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�. 
HCURSOR CDoubleBufferDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDoubleBufferDemoDlg::OnTimer(UINT nIDEvent) 
{
	// �ؽ�Ʈ ��� ��ġ�� �������� �̵��Ѵ�
	m_nCurPos--;

	// ���� ��� �ؽ�Ʈ�� �������� �����ٸ� �ؽ�Ʈ ��� ��ġ�� ���������� �����Ѵ�
	if(m_nCurPos < -m_TextSize.cx)
		m_nCurPos = m_rcClient.right;

	// ȭ���� �ٽ� �׸���
	Invalidate(FALSE);
	
	CDialog::OnTimer(nIDEvent);
}

void CDoubleBufferDemoDlg::OnDestroy() 
{
	CDialog::OnDestroy();

	// Ÿ�̸Ӹ� �����Ѵ�
	KillTimer(1);
}

BOOL CDoubleBufferDemoDlg::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}
