// SymbolDialogDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "SymbolDialog.h"
#include "SymbolDialogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "SymbolDlg.h"

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


// CSymbolDialogDlg ��ȭ ����



CSymbolDialogDlg::CSymbolDialogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSymbolDialogDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSymbolDialogDlg)
	m_strCode = _T("");
	m_nType = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSymbolDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSymbolDialogDlg)
	DDX_Control(pDX, IDC_FONT_COMBO, m_FontCombo);
	DDX_Text(pDX, IDC_CODE_EDIT, m_strCode);
	DDX_Radio(pDX, IDC_TYPE_RADIO1, m_nType);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSymbolDialogDlg, CDialog)
	//{{AFX_MSG_MAP(CSymbolDialogDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SELECT_BUTTON, OnSelectButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CSymbolDialogDlg �޽��� ó����

// �ý����� ��Ʈ���� �޺� �ڽ��� �߰��ϴ� �Լ�
int CALLBACK EnumFontsProc(CONST LOGFONT *lplf, CONST TEXTMETRIC *lptm, DWORD dwType, LPARAM lParam) 
{
	CComboBox *pCombo = (CComboBox*)lParam;
	pCombo->AddString(lplf->lfFaceName);

	return TRUE; 
} 

BOOL CSymbolDialogDlg::OnInitDialog()
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

	// �ý����� ��Ʈ�� �޺� �ڽ��� �߰��Ѵ�
	CDC *pDC = GetDC();	
    EnumFonts(pDC->m_hDC, NULL, (FONTENUMPROC)EnumFontsProc, (LPARAM)&m_FontCombo); 
	ReleaseDC(pDC);
 
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CSymbolDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSymbolDialogDlg::OnPaint() 
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
HCURSOR CSymbolDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSymbolDialogDlg::OnSelectButton() 
{
	UpdateData(TRUE);

	// ��Ʈ�� ���� �Ǿ����� Ȯ���Ѵ�
	if(m_FontCombo.GetCurSel() == CB_ERR)
	{
		MessageBox("��Ʈ �̸��� �����ϼ���.", "Ư�� ����ǥ", MB_OK);
		return;
	}

	// ���� �ڵ带 �����ߴ��� Ȯ���Ѵ�
	if(m_nType < 0)
	{
		MessageBox("���� Ÿ���� �����ϼ���.", "Ư�� ����ǥ", MB_OK);
		return;
	}

	// Ư�� ���� ���̾�α�
	CSymbolDlg dlg;

	// ���õ� ��Ʈ �̸��� �����Ѵ�
	CString strFontName;
	m_FontCombo.GetLBText(m_FontCombo.GetCurSel(), strFontName);
	dlg.SetFontName(strFontName);

	// ���õ� ���� �ڵ带 �����Ѵ�
	dlg.SetCodeType(m_nType == 1);

	// ���̾�α׸� ����
	if(dlg.DoModal() == IDOK)
	{
		// ���õ� ���� �ڵ带 ��� �´�
		m_strCode = dlg.GetSelectedChar();

		UpdateData(FALSE);
	}	
}
