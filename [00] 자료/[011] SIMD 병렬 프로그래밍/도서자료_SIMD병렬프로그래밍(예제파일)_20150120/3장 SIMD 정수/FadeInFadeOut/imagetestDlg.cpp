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
	const unsigned int WIDTH = 300;			//이미지 넓이 300
	const unsigned int HEIGHT = 300;		//이미지 높이 300
	const unsigned int IMAGE_SIZE = WIDTH*HEIGHT;	//이미지 사이즈 90000
	const unsigned int BMP_HEADER_LENGTH = 1064;	//bmp 해더 길이 1064

	unsigned char* pSrcA = new unsigned char[IMAGE_SIZE];	//이미지 데이터 버퍼 A
	unsigned char* pSrcB = new unsigned char[IMAGE_SIZE];	//이미지 데이터 버퍼 B
	unsigned char* pResult = new unsigned char[IMAGE_SIZE];	//Result 데이터 버퍼 
	memset(pResult,0x00,IMAGE_SIZE);

	CxImage SrcImageA;
	CxImage SrcImageB;
	CxImage Result;

	SrcImageA.Load("./image/A.bmp",CXIMAGE_FORMAT_BMP);	//A 이미지를 로드 한다.
	SrcImageB.Load("./image/B.bmp",CXIMAGE_FORMAT_BMP);	//B 이미지를 로드 한다.

	unsigned char* pRAWA = (unsigned char*)SrcImageA.GetDIB();
	memcpy(pSrcA,pRAWA+BMP_HEADER_LENGTH,IMAGE_SIZE);	//bmp 해더를 제외한 데이터만 가져온다.

	unsigned char* pRAWB = (unsigned char*)SrcImageB.GetDIB();
	memcpy(pSrcB,pRAWB+BMP_HEADER_LENGTH,IMAGE_SIZE);	//bmp 해더를 제외한 데이터만 가져온다.

	CString sFileFath ="";

	for(int i = 1; i < 8 ; i++)	//8프레임을 증가하면서 반복 실행
	{
		ImageSum(pSrcA,pSrcB,pResult,i,IMAGE_SIZE);
		Result.CreateFromArray(pResult,WIDTH,HEIGHT,8,WIDTH,FALSE);
		sFileFath.Format("./image/Result%d.bmp",i);
		Result.Save(sFileFath,CXIMAGE_FORMAT_BMP);	//Result 이미지 저장.
	}

	delete[] pResult;
	delete[] pSrcA;
	delete[] pSrcB;

	CDialog::OnOK();
}

int CImagetestDlg::ImageSumC(const unsigned char *ImageA, const unsigned char *ImageB,unsigned char *ResultImage, const unsigned char nFrame, const int nImageSize)
{
	if( nFrame == 0 || nFrame == 8)
		return -1;	// 0프레임과 8프레임은 A,B 이미지를 사용하면 되므로 계산하지 않는다.
	
	unsigned short	RatioA = nFrame;		//8개씩 한번에 계산할 A 가중치 마스크 생성
	unsigned short	RatioB = 8 - nFrame;	//8개씩 한번에 계산할 B 가중치 마스크 생성
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
	// 0프레임과 8프레임은 A,B 이미지를 사용하면 되므로 계산하지 않는다.
	const unsigned char* pImageA = ImageA;
	const unsigned char* pImageB = ImageB;
	unsigned char* pResult = ResultImage;
	unsigned short RatioA[8] = {0};
	unsigned short RatioB[8] = {0};
	unsigned char Ratioindex = 0;
	for( Ratioindex = 0; Ratioindex < 8; Ratioindex++)
		RatioA[Ratioindex] = nFrame;		
	//8개씩 한번에 계산할 A 가중치 마스크 생성
	
	for( Ratioindex = 0; Ratioindex < 8; Ratioindex++)
		RatioB[Ratioindex] = 8 - nFrame;	
	//8개씩 한번에 계산할 B 가중치 마스크 생성
	
	unsigned int nLoopCount = (nImageSize/16)*16;
	unsigned int nRemain = nImageSize - nLoopCount;
	
	__asm
	{
		pushad
			
		mov eax, pImageA	//eax = pImageA
		mov ebx, pImageB	//ebx = pImageB
		mov edi, pResult	//edi = pResult
		mov esi, 0		//esi = 0; 소스 인덱스
		mov ecx, nLoopCount	//ecx = nLoopCount; Loop limit
		
		pxor xmm4,xmm4	//xmm4 = 0; temp 변수
		movdqu xmm5, RatioA	//xxm5 = RatioA; xmm5는 A가중치 마스크 레지스터
		movdqu xmm6, RatioB 	//xmm6 = RatioB; xmm6는 B가중치 마스크 레지스터
SIMDLOOP:
		movdqu xmm0, [eax+esi]	//ImageA 에서 16byte 로드
		movdqu xmm1, xmm0	//xmm1 = xmm0 copy
		
		movdqu xmm2, [ebx+esi]	//ImageB 에서 16byte 로드
		movdqu xmm3, xmm2	//xmm3 = xmm2 copy
		
		punpcklbw xmm0, xmm4	//이미지 A 하위8Byte를 short형으로 확장
		punpcklbw xmm2, xmm4	//이미지 B 하위8Byte를 short형으로 확장
		
		pmullw xmm0, xmm5	//A 가중치 비율만큼 곱한다.
		pmullw xmm2, xmm6	//B 가중치 비율만큼 곱한다.
		
		paddw xmm0, xmm2	//두값을 더한다.
		psrlw xmm0, 3		//8로 나눈다.
			
		punpckhbw xmm1, xmm4	//이미지 A 상위8Byte를 short형으로 확장
		punpckhbw xmm3, xmm4	//이미지 B 상위8Byte를 short형으로 확장
			
		pmullw xmm1, xmm5		//A 가중치 비율만큼 곱한다.
		pmullw xmm3, xmm6		//B 가중치 비율만큼 곱한다.
			
		paddw xmm1, xmm3		//두 값을 더한다.
		psrlw xmm1, 3			//8로 나눈다.
		
		packuswb xmm0,xmm1	
		//상위 8개 Short형 하위 8개 Short형을 16개 byte로 합친다.
			
		movdqu [edi+esi], xmm0	//Result 메모리에 대입.
		
		add esi, 16			//16byte 이동
		cmp esi, nLoopCount		//Loop 반복
		jne SIMDLOOP
			
		popad
		
	}
	
	if( nRemain != 0)		//나머지 값 계산, C코드와 동일
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

