// HTMLCollectorDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "HTMLCollectorDemo.h"
#include "HTMLCollectorDemoDlg.h"

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


// CHTMLCollectorDemoDlg ��ȭ ����



CHTMLCollectorDemoDlg::CHTMLCollectorDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHTMLCollectorDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHTMLCollectorDemoDlg)
	m_strSource = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CHTMLCollectorDemoDlg::~CHTMLCollectorDemoDlg()
{
	// �̹��� ����Ʈ�� �����Ѵ�
	m_ImageList.DeleteImageList();
}

void CHTMLCollectorDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHTMLCollectorDemoDlg)
	DDX_Control(pDX, IDC_IE_LIST, m_IEList);
	DDX_Control(pDX, IDC_FINDER_STATIC, m_HTMLCollector);
	DDX_Text(pDX, IDC_SOURCE_EDIT, m_strSource);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHTMLCollectorDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CHTMLCollectorDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_REFRESH_BUTTON, OnRefreshButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, OnSaveButton)
	ON_NOTIFY(NM_DBLCLK, IDC_IE_LIST, OnDblclkIeList)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_IE_FINDER_START, OnIEFinderStart)
	ON_MESSAGE(WM_IE_FINDER_END, OnIEFinderEnd)
	ON_MESSAGE(WM_IE_FINDER_SELECT, OnIEFinderSelect)
END_MESSAGE_MAP()


// CHTMLCollectorDemoDlg �޽��� ó����

BOOL CHTMLCollectorDemoDlg::OnInitDialog()
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

	// ��Ʈ�� ���ҽ��κ��� �̹��� ����Ʈ�� �����Ѵ�
	CBitmap bmpIE;
	bmpIE.LoadBitmap(IDB_WEB_PAGE);
	m_ImageList.Create(16, 16, ILC_COLORDDB|ILC_MASK, 16, 1);
	m_ImageList.Add(&bmpIE, RGB(198, 198, 198));
	
	// �������� ����Ʈ�� �̹��� ����Ʈ�� �����Ѵ�
	m_IEList.SetImageList(&m_ImageList, LVSIL_SMALL);
	// �������� ����Ʈ�� Ȯ�� �Ӽ��� �����Ѵ�
	m_IEList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_FLATSB);

	// �������� ����Ʈ�� �÷��� �߰��Ѵ�
	m_IEList.InsertColumn(0, "����", LVCFMT_LEFT, 300, 0);
	m_IEList.InsertColumn(1, "�ּ�", LVCFMT_LEFT, 300, 1);

	// ���� ���� �ִ� ���������� �˻��Ͽ� �迭�� �����Ѵ�
	m_HTMLCollector.RefreshIEArray();

	// �˻��� ���������� ������ ��´�
	int i, nSize = m_HTMLCollector.GetIEArrayCount(), nItem;
	SIEWnd *pIEWnd;

	// �˻��� ��� ���������� ���ؼ�
	for(i = 0; i < nSize; i++)
	{
		// �������� ���� ����ü�� ��´�
		pIEWnd = m_HTMLCollector.GetIEWnd(i);

		// ���������� �������� �׸��� �߰��Ѵ�
		nItem = m_IEList.InsertItem(i, pIEWnd->strTitle, 0);
		// ���������� �ּҸ� �ι�° �׸� �ؽ�Ʈ�� �����Ѵ�
		m_IEList.SetItemText(nItem, 1, pIEWnd->strAddress);
	}

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CHTMLCollectorDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHTMLCollectorDemoDlg::OnPaint() 
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
HCURSOR CHTMLCollectorDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// �������� ����Ʈ�� �ٽ� �����ϴ� �Լ�
void CHTMLCollectorDemoDlg::OnRefreshButton() 
{
	// �������� ����Ʈ�� �����
	m_IEList.DeleteAllItems();

	// ���� ���� �ִ� ���������� �ٽ� �˻��Ͽ� �迭�� �����Ѵ�
	m_HTMLCollector.RefreshIEArray();

	// �˻��� ���������� ������ ��´�
	int i, nSize = m_HTMLCollector.GetIEArrayCount(), nItem;
	SIEWnd *pIEWnd;

	// �˻��� ��� ���������� ���ؼ�
	for(i = 0; i < nSize; i++)
	{
		// �������� ���� ����ü�� ��´�
		pIEWnd = m_HTMLCollector.GetIEWnd(i);

		// ���������� �������� �׸��� �߰��Ѵ�
		nItem = m_IEList.InsertItem(i, pIEWnd->strTitle, 0);
		// ���������� �ּҸ� �ι�° �׸� �ؽ�Ʈ�� �����Ѵ�
		m_IEList.SetItemText(nItem, 1, pIEWnd->strAddress);
	}
}

// HTML �ҽ��� ���Ϸ� �����ϴ� �Լ�
void CHTMLCollectorDemoDlg::OnSaveButton() 
{
	// ȹ��� HTML �ҽ��� ��´�
	LPCTSTR pSource = m_HTMLCollector.GetSource();

	// ���� HTML �ҽ��� ���̰� 0�̶�� �����Ѵ�
	if(strlen(pSource) == 0)
	{
		MessageBox("������ �ҽ��� �����ϴ�.");
		return;
	}

	// ���� ���̾�α׸� ���� HTML �ҽ��� ������ ���� ��θ� �Է� �޴´�
	CFileDialog dlg(FALSE, "htm", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"HTML ����(*.htm)|*.htm|�ؽ�Ʈ ����(*.txt)|*.txt|��� ����(*.*)|*.*||", this);

	if(dlg.DoModal() == IDOK)
	{
		// �Էµ� ���� ��ο� �ؽ�Ʈ ������ �����Ͽ� ����
		FILE *pFile = fopen(dlg.GetPathName(), "wt");

		// ȹ��� HTML �ҽ��� �ؽ�Ʈ ���Ͽ� �����Ѵ�
		fwrite(pSource, strlen(pSource), 1, pFile);

		// �ؽ�Ʈ ������ �ݴ´�
		fclose(pFile);
	}
}

// �������� ����Ʈ�� ����Ŭ�� �Ͽ��� �� ����Ǵ� �Լ�
void CHTMLCollectorDemoDlg::OnDblclkIeList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// ���õ� �׸��� ��ġ�� ��´�
	POSITION pos = m_IEList.GetFirstSelectedItemPosition();
	
	// ���� ���õ� �׸��� ���ٸ� �޽��� �ڽ��� ����Ѵ�
	if(pos == NULL)
	{
		MessageBox("���ϴ� ����Ʈ�� �����ִ� ���������� �����ϼ���.");
	}
	else
	{
		// ���õ� �׸��� ��ȣ�� ��´�
		int nSelected = m_IEList.GetNextSelectedItem(pos);

		// �ش� �׸��� �ҽ��� HTML �ҽ� ȹ�� Ŭ�������� ��´�
		m_strSource = m_HTMLCollector.GetSource(nSelected);

		// ���̾�α��� ����Ʈ �ڽ��� HTML �ҽ��� �����Ѵ�
		UpdateData(FALSE);
	}
	
	*pResult = 0;
}

// �������� ������ ���۵Ǿ��� �� ����Ǵ� �Լ�
LRESULT CHTMLCollectorDemoDlg::OnIEFinderStart(WPARAM wParam, LPARAM lParam)
{
	// ���̾�α׸� �ּ�ȭ ��Ų��
	ShowWindow(SW_MINIMIZE);
	return 1;
}

// �������� ������ ������ �� ����Ǵ� �Լ�
LRESULT CHTMLCollectorDemoDlg::OnIEFinderEnd(WPARAM wParam, LPARAM lParam)
{
	// ���̾�α׸� ������Ų��
	ShowWindow(SW_RESTORE);
	return 1;
}

// ���������� ���õǰ� �ҽ��� ȹ���� �� ����Ǵ� �Լ�
LRESULT CHTMLCollectorDemoDlg::OnIEFinderSelect(WPARAM wParam, LPARAM lParam)
{
	// ���ڷ� �Ѿ���� HTML �ҽ� ȹ�� Ŭ���� �����͸� �����Ѵ�
	CHTMLCollector *pCollector = (CHTMLCollector*)lParam;

	// HTML �ҽ� ȹ�� Ŭ�������� HTML �ҽ��� ��´�
	m_strSource = pCollector->GetSource();

	// ���̾�α��� ����Ʈ �ڽ��� HTML �ҽ��� �����Ѵ�
	UpdateData(FALSE);
	return 1;
}
