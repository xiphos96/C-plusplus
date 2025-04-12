// FontEffectDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "FontEffectDemo.h"
#include "FontEffectDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <math.h>


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


// CFontEffectDemoDlg ��ȭ ����



CFontEffectDemoDlg::CFontEffectDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFontEffectDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFontEffectDemoDlg)
	m_bOutLine = FALSE;
	m_nShapeType = 0;
	m_strText = _T("��Ʈ ȿ�� �׽�Ʈ");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFontEffectDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFontEffectDemoDlg)
	DDX_Control(pDX, IDC_EFFECT_STATIC, m_FontEffect);
	DDX_Control(pDX, IDC_SHAPE_BUTTON3, m_btnShape3);
	DDX_Control(pDX, IDC_SHAPE_BUTTON2, m_btnShape2);
	DDX_Control(pDX, IDC_SHAPE_BUTTON1, m_btnShape1);
	DDX_Check(pDX, IDC_OUTLINE_CHECK, m_bOutLine);
	DDX_Radio(pDX, IDC_SHAPE_BUTTON1, m_nShapeType);
	DDX_Text(pDX, IDC_TEXT_EDIT, m_strText);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFontEffectDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CFontEffectDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHAPE_BUTTON1, OnShapeButton1)
	ON_BN_CLICKED(IDC_SHAPE_BUTTON2, OnShapeButton2)
	ON_BN_CLICKED(IDC_SHAPE_BUTTON3, OnShapeButton3)
	ON_BN_CLICKED(IDC_OUTLINE_CHECK, OnOutlineCheck)
	ON_BN_CLICKED(IDC_REFRESH_BUTTON, OnRefreshButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CFontEffectDemoDlg �޽��� ó����

BOOL CFontEffectDemoDlg::OnInitDialog()
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

	m_btnShape1.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_SHAPE1)));
	m_btnShape2.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_SHAPE2)));
	m_btnShape3.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_SHAPE3)));

	OnRefreshButton();

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CFontEffectDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFontEffectDemoDlg::OnPaint() 
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
HCURSOR CFontEffectDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFontEffectDemoDlg::OnShapeButton1() 
{
	// ���� �׷����� �׸��� ȿ�� �Լ��� �����Ѵ�
	m_FontEffect.SetFunction(ShapeFunc1, TRUE);
}

void CFontEffectDemoDlg::OnShapeButton2() 
{
	// �Ʒ������� ���̰� �����ϴ� ȿ�� �Լ��� �����Ѵ�
	m_FontEffect.SetFunction(ShapeFunc2, TRUE);
}

void CFontEffectDemoDlg::OnShapeButton3() 
{
	// ������ �Ʒ������� �Բ� ���̰� �����ϴ� ȿ�� �Լ��� �����Ѵ�
	m_FontEffect.SetFunction(ShapeFunc3, TRUE);
}

void CFontEffectDemoDlg::OnOutlineCheck() 
{
	UpdateData(TRUE);

	// �ܰ��� �ɼ��� �����Ѵ�
	m_FontEffect.SetOutLine(m_bOutLine);
}

void CFontEffectDemoDlg::OnRefreshButton() 
{
	UpdateData(TRUE);

	// �ؽ�Ʈ�� �����Ѵ�
	m_FontEffect.SetText(m_strText);

	switch(m_nShapeType)
	{
	case 0:
		// ���� �׷����� �׸��� ȿ�� �Լ��� �����Ѵ�
		m_FontEffect.SetFunction(ShapeFunc1, TRUE);
		break;

	case 1:
		// �Ʒ������� ���̰� �����ϴ� ȿ�� �Լ��� �����Ѵ�
		m_FontEffect.SetFunction(ShapeFunc2, TRUE);
		break;

	case 2:
		// ������ �Ʒ������� �Բ� ���̰� �����ϴ� ȿ�� �Լ��� �����Ѵ�
		m_FontEffect.SetFunction(ShapeFunc3, TRUE);
		break;
	}

	// ��θ� �ٽ� �����ϰ� ȭ���� �����Ѵ�
	m_FontEffect.BuildEffect();
}

// ���� �׷����� �׸��� ȿ�� �Լ�
void CFontEffectDemoDlg::ShapeFunc1(int nSize, CPoint *pPoint, CSize TextSize)
{
	double dSin;
	for(int i = 0; i < nSize; i++)
	{
		dSin = sin(2 * 3.1415926535 * pPoint[i].x / TextSize.cx);
		dSin *= 30;
		pPoint[i].y = (int)(pPoint[i].y + dSin);
	}
}

// �Ʒ������� ���̰� �����ϴ� ȿ�� �Լ�
void CFontEffectDemoDlg::ShapeFunc2(int nSize, CPoint *pPoint, CSize TextSize)
{
	for(int i = 0; i < nSize; i++)
	{
		pPoint[i].y = (int)(pPoint[i].y * ((double)pPoint[i].x * 4 / TextSize.cx + 1));
	}
}

// ������ �Ʒ������� �Բ� ���̰� �����ϴ� ȿ�� �Լ�
void CFontEffectDemoDlg::ShapeFunc3(int nSize, CPoint *pPoint, CSize TextSize)
{
	for(int i = 0; i < nSize; i++)
	{
		pPoint[i].y -= TextSize.cy / 2;
		pPoint[i].y = (int)(pPoint[i].y * ((double)pPoint[i].x * 4 / TextSize.cx + 1));
	}
}
