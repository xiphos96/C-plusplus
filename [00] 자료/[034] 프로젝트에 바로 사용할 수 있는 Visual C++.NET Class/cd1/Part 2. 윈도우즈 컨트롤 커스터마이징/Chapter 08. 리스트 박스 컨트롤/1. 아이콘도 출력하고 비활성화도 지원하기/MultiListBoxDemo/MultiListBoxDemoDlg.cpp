// MultiListBoxDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MultiListBoxDemo.h"
#include "MultiListBoxDemoDlg.h"

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


// CMultiListBoxDemoDlg ��ȭ ����



CMultiListBoxDemoDlg::CMultiListBoxDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiListBoxDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiListBoxDemoDlg)
	m_strText = _T("");
	m_nImage = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiListBoxDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiListBoxDemoDlg)
	DDX_Control(pDX, IDC_MULTI_LIST, m_MultiList);
	DDX_Text(pDX, IDC_TEXT_EDIT, m_strText);
	DDX_CBIndex(pDX, IDC_IMAGE_COMBO, m_nImage);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiListBoxDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CMultiListBoxDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
	ON_LBN_DBLCLK(IDC_MULTI_LIST, OnDblclkMultiList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CMultiListBoxDemoDlg �޽��� ó����

BOOL CMultiListBoxDemoDlg::OnInitDialog()
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

	// ��Ʈ���� ����ؼ� �̹��� ����Ʈ�� �����Ѵ�
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BOOKLIST);
	m_ImageList.Create(88, 88, ILC_COLOR24 | ILC_MASK, 10, 1);
	m_ImageList.Add(&bmp, RGB(255, 0, 255));
	bmp.DeleteObject();

	// �̹��� ����Ʈ�� ����Ʈ �ڽ��� �����Ѵ�
	m_MultiList.SetImageList(&m_ImageList);

	// ����Ʈ �ڽ��� �׸��� �߰��Ѵ�
	m_MultiList.AddString("\n��ǻ�� �ŴϾ� �÷��� MX\n\n������ ������ �����ϵ��� ������ �п�/�б� �����Դϴ�.\n�׷��Ȱ� OA�� �ٷ�� ������ ���� ���翡 ���� ���� ���� ���� ���� ������ �����ϵ��� ������ �����Դϴ�.", 0);
	m_MultiList.AddString("\nC# & .NET Programming Bible 2nd Edition\n\nC# ������ �ڼ��� �ٷ�� �ʱ��ڵ� ���� ������ �� ������ å ��ü������ �۰� ū ������ ���� �ǽ��ϸ鼭 ���ο� ������ ��ɵ��� �н��� �� �ֽ��ϴ�.", 1);
	m_MultiList.AddString("\n���� Ǯ� Java Database Programming\n\nJDBC 3.0 �ֽ� ������ ������� �پ��� ������ ���� �������� �ڹٿ� DB ���� ���α׷��� ����� ���� �ٷ�� ������ JDBC ����� Ư���� �ڹ��� �ʱ޺��� �ǹ� ����ڱ��� �ʿ��� �κи� ã�Ƽ� ���� �ֵ��� �����ͺ��̽��� ����, JDBC ��� ������, �ڹٰ��� �ǹ����� �� 3�ܰ�� ������ �����ϰ� �ִ�.", 2);
	m_MultiList.AddString("\nmunge's cartoon book ����ø�\n\n��Ƽ�� ���̿��� �α⸦ ��� �ִ�www.munge.co.kr ����Ʈ�� ����� ���ڴ� �������� ���α�ӽ�(Doogy Doop)���� ������ ���� ��Ȱ���� �������� �ܻ���� ��ȭ�� �̾߱��ϰ� �ִ�.", 3);
	m_MultiList.AddString("\nC ���� ���� TCP / IP ��Ʈ��ũ ���α׷���\n\n�� å������ ���������� �ؼ��� �⺻ ������ ���߰� �ִ� ���� �ƴ϶�, ������ ���������� �����Ͽ�, ���������� ����� ���� �Ϳ� ������ �ΰ� �ִ�.", 4);
	m_MultiList.AddString("\nMultimedia Sound Programmnig\n\n���� ���α׷��� �̷а� �߰�� ���α׷����� �ֿ䰳���� �����ϰ� �̷��� ������ �ǽ��� ��ȭ�� �н� ȿ���� �����Ų��.", 5);
	m_MultiList.AddString("\nVisual C# .NET 2003 ���� ������Ʈ\n\n�� å�� Visual Studio.NET 2003 ��ǰ �ѱ������� �۾��Ǿ� �ֽ��ϴ�. C#�� ���� ������ �⺻���� ������ ����� ����� �Ұ��ϴµ� ��ġ�� �ʰ� ���� ������ �������� �� �ǹ��� �ʿ��� �ڵ带 �������� ���� ������Ʈ�� �����ϴ� ����� �Ұ��ϰ� �ֽ��ϴ�.", 6);
	m_MultiList.AddString("\nPhotoshop�� �̿��� ��ǰ ������\n\n�� å�� Ư���� ���伥�� ��� ü�� ������ �˰� �ִ� ����ڵ��� �������� ��������ϴ�.", 7);
	m_MultiList.AddString("\nVisual Basic.NET Programming Bible 2nd Edition\n\n�� å�� VB.NET�� ���� .NET ȯ�濡���� ���α׷��ֿ� ���� ��� ������ �ٷ�� �ֽ��ϴ�.", 8);
	m_MultiList.AddString("\nVisual C++.NET Programming Bible 2nd Edition\n\n���� ū ������ ��ƴٰ� ������ �� �ִ� Visual C++.NET ������ �ʺ��ڵ� ���� ������ �� �ֵ��� ü������ ����� ���� ��� ���� ������ �����Ͽ��ٴ� ���Դϴ�.", 9);

	// Ư�� �׸���� ��Ȱ��ȭ ��Ų��
	m_MultiList.EnableString(3, FALSE);
	m_MultiList.EnableString(6, FALSE);
	m_MultiList.EnableString(9, FALSE);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CMultiListBoxDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMultiListBoxDemoDlg::OnPaint() 
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
HCURSOR CMultiListBoxDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMultiListBoxDemoDlg::OnAddButton() 
{
	// ���ο� �׸��� ����Ʈ �ڽ��� �߰��Ѵ�
	UpdateData(TRUE);

	// ���� �ؽ�Ʈ�� �Էµ��� �ʾҴٸ�
	if(m_strText.IsEmpty())
	{
		MessageBox("�׸� �ؽ�Ʈ�� �Է��ϼ���.");
		return;
	}

	// �ش� �ؽ�Ʈ�� �̹��� ��ȣ�� �׸��� �߰��Ѵ�
	m_MultiList.AddString(m_strText, m_nImage);
}

void CMultiListBoxDemoDlg::OnDblclkMultiList() 
{
	// �׸��� ���� Ŭ���ϸ� ���� ���õ� �׸��� ã�´�
	int nItem = m_MultiList.GetCurSel();

	CString strItem;
	// ���� ���õ� �׸��� ���ٸ� ����
	if(nItem == LB_ERR)					return;
	// ���� ��Ȱ��ȭ�� �׸��̶�� ����
	if(!m_MultiList.IsEnabled(nItem))	return;

	// �׸��� �ؽ�Ʈ�� ��´�
	m_MultiList.GetText(nItem, strItem);
	strItem.TrimLeft();

	// å ���� �κ��� ã�´�
	int nEnd = strItem.Find('\n');
	if(nEnd >= 0)
		strItem.Delete(nEnd, strItem.GetLength() - nEnd);

	// �޽��� �ڽ��� ����Ѵ�
	MessageBox(strItem);
}
