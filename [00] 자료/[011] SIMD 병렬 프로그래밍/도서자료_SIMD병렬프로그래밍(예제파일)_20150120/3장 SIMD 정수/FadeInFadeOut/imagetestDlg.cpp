// imagetestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "imagetest.h"
#include "imagetestDlg.h"
#include "./include/ximage.h"

#pragma comment(lib, "./lib/cximaged.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
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
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImagetestDlg dialog

CImagetestDlg::CImagetestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImagetestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImagetestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImagetestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImagetestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CImagetestDlg, CDialog)
	//{{AFX_MSG_MAP(CImagetestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImagetestDlg message handlers

BOOL CImagetestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CImagetestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CImagetestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CImagetestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CImagetestDlg::OnOK() 
{
	const unsigned int WIDTH = 300;			//�̹��� ���� 300
	const unsigned int HEIGHT = 300;		//�̹��� ���� 300
	const unsigned int IMAGE_SIZE = WIDTH*HEIGHT;	//�̹��� ������ 90000
	const unsigned int BMP_HEADER_LENGTH = 1064;	//bmp �ش� ���� 1064

	unsigned char* pSrcA = new unsigned char[IMAGE_SIZE];	//�̹��� ������ ���� A
	unsigned char* pSrcB = new unsigned char[IMAGE_SIZE];	//�̹��� ������ ���� B
	unsigned char* pResult = new unsigned char[IMAGE_SIZE];	//Result ������ ���� 
	memset(pResult,0x00,IMAGE_SIZE);

	CxImage SrcImageA;
	CxImage SrcImageB;
	CxImage Result;

	SrcImageA.Load("./image/A.bmp",CXIMAGE_FORMAT_BMP);	//A �̹����� �ε� �Ѵ�.
	SrcImageB.Load("./image/B.bmp",CXIMAGE_FORMAT_BMP);	//B �̹����� �ε� �Ѵ�.

	unsigned char* pRAWA = (unsigned char*)SrcImageA.GetDIB();
	memcpy(pSrcA,pRAWA+BMP_HEADER_LENGTH,IMAGE_SIZE);	//bmp �ش��� ������ �����͸� �����´�.

	unsigned char* pRAWB = (unsigned char*)SrcImageB.GetDIB();
	memcpy(pSrcB,pRAWB+BMP_HEADER_LENGTH,IMAGE_SIZE);	//bmp �ش��� ������ �����͸� �����´�.

	CString sFileFath ="";

	for(int i = 1; i < 8 ; i++)	//8�������� �����ϸ鼭 �ݺ� ����
	{
		ImageSum(pSrcA,pSrcB,pResult,i,IMAGE_SIZE);
		Result.CreateFromArray(pResult,WIDTH,HEIGHT,8,WIDTH,FALSE);
		sFileFath.Format("./image/Result%d.bmp",i);
		Result.Save(sFileFath,CXIMAGE_FORMAT_BMP);	//Result �̹��� ����.
	}

	delete[] pResult;
	delete[] pSrcA;
	delete[] pSrcB;

	CDialog::OnOK();
}

int CImagetestDlg::ImageSumC(const unsigned char *ImageA, const unsigned char *ImageB,unsigned char *ResultImage, const unsigned char nFrame, const int nImageSize)
{
	if( nFrame == 0 || nFrame == 8)
		return -1;	// 0�����Ӱ� 8�������� A,B �̹����� ����ϸ� �ǹǷ� ������� �ʴ´�.
	
	unsigned short	RatioA = nFrame;		//8���� �ѹ��� ����� A ����ġ ����ũ ����
	unsigned short	RatioB = 8 - nFrame;	//8���� �ѹ��� ����� B ����ġ ����ũ ����
	unsigned short	AValue = 0;
	unsigned short	BValue = 0;
	
	for( int nIndex = 0; nIndex < nImageSize; nIndex++)
	{
		AValue = ImageA[nIndex];
		BValue = ImageB[nIndex];
		ResultImage[nIndex] =unsigned char(( RatioA*AValue + RatioB*BValue ) / 8);
	}
	
	return 1;
}

int CImagetestDlg::ImageSum(const unsigned char *ImageA, const unsigned char *ImageB, unsigned char *ResultImage, const unsigned char nFrame, const int nImageSize)
{
	if( nFrame == 0 || nFrame == 8)	return -1;	
	// 0�����Ӱ� 8�������� A,B �̹����� ����ϸ� �ǹǷ� ������� �ʴ´�.
	const unsigned char* pImageA = ImageA;
	const unsigned char* pImageB = ImageB;
	unsigned char* pResult = ResultImage;
	unsigned short RatioA[8] = {0};
	unsigned short RatioB[8] = {0};
	unsigned char Ratioindex = 0;
	for( Ratioindex = 0; Ratioindex < 8; Ratioindex++)
		RatioA[Ratioindex] = nFrame;		
	//8���� �ѹ��� ����� A ����ġ ����ũ ����
	
	for( Ratioindex = 0; Ratioindex < 8; Ratioindex++)
		RatioB[Ratioindex] = 8 - nFrame;	
	//8���� �ѹ��� ����� B ����ġ ����ũ ����
	
	unsigned int nLoopCount = (nImageSize/16)*16;
	unsigned int nRemain = nImageSize - nLoopCount;
	
	__asm
	{
		pushad
			
		mov eax, pImageA	//eax = pImageA
		mov ebx, pImageB	//ebx = pImageB
		mov edi, pResult	//edi = pResult
		mov esi, 0		//esi = 0; �ҽ� �ε���
		mov ecx, nLoopCount	//ecx = nLoopCount; Loop limit
		
		pxor xmm4,xmm4	//xmm4 = 0; temp ����
		movdqu xmm5, RatioA	//xxm5 = RatioA; xmm5�� A����ġ ����ũ ��������
		movdqu xmm6, RatioB 	//xmm6 = RatioB; xmm6�� B����ġ ����ũ ��������
SIMDLOOP:
		movdqu xmm0, [eax+esi]	//ImageA ���� 16byte �ε�
		movdqu xmm1, xmm0	//xmm1 = xmm0 copy
		
		movdqu xmm2, [ebx+esi]	//ImageB ���� 16byte �ε�
		movdqu xmm3, xmm2	//xmm3 = xmm2 copy
		
		punpcklbw xmm0, xmm4	//�̹��� A ����8Byte�� short������ Ȯ��
		punpcklbw xmm2, xmm4	//�̹��� B ����8Byte�� short������ Ȯ��
		
		pmullw xmm0, xmm5	//A ����ġ ������ŭ ���Ѵ�.
		pmullw xmm2, xmm6	//B ����ġ ������ŭ ���Ѵ�.
		
		paddw xmm0, xmm2	//�ΰ��� ���Ѵ�.
		psrlw xmm0, 3		//8�� ������.
			
		punpckhbw xmm1, xmm4	//�̹��� A ����8Byte�� short������ Ȯ��
		punpckhbw xmm3, xmm4	//�̹��� B ����8Byte�� short������ Ȯ��
			
		pmullw xmm1, xmm5		//A ����ġ ������ŭ ���Ѵ�.
		pmullw xmm3, xmm6		//B ����ġ ������ŭ ���Ѵ�.
			
		paddw xmm1, xmm3		//�� ���� ���Ѵ�.
		psrlw xmm1, 3			//8�� ������.
		
		packuswb xmm0,xmm1	
		//���� 8�� Short�� ���� 8�� Short���� 16�� byte�� ��ģ��.
			
		movdqu [edi+esi], xmm0	//Result �޸𸮿� ����.
		
		add esi, 16			//16byte �̵�
		cmp esi, nLoopCount		//Loop �ݺ�
		jne SIMDLOOP
			
		popad
		
	}
	
	if( nRemain != 0)		//������ �� ���, C�ڵ�� ����
	{
		unsigned short	RatioA = nFrame;		
		unsigned short	RatioB = 8 - nFrame;	
		unsigned short	AValue = 0;
		unsigned short	BValue = 0;
		for(int i = nImageSize- nRemain; i < nImageSize; i++)
		{
			AValue = pImageA[i];
			BValue = pImageB[i];
			pResult[i] = unsigned char(( RatioA*AValue + RatioB*BValue ) / 8);
		}
		
	}
	
	return 1;
}

