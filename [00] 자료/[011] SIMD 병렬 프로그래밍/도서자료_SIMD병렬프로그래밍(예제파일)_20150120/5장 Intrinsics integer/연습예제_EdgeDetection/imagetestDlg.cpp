// imagetestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "imagetest.h"
#include "imagetestDlg.h"
#include "./include/ximage.h"
#include <emmintrin.h>
#include "StopWatch.h"

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
	const unsigned int WIDTH = 256;			//이미지 넓이 300
	const unsigned int HEIGHT = 256;		//이미지 높이 300
	const unsigned int IMAGE_SIZE = WIDTH*HEIGHT;	//이미지 사이즈 90000
	const unsigned int BMP_HEADER_LENGTH = 1064;	//bmp 해더 길이 1064

	unsigned char* pSrc = new unsigned char[IMAGE_SIZE];	//이미지 데이터 버퍼 A
	unsigned char* pResult = new unsigned char[IMAGE_SIZE];	//Result 데이터 버퍼 
	memset(pResult,0x00,IMAGE_SIZE);

	CxImage SrcImage;
	CxImage Result;
	
	CStopWatch watch;
	float fTimeC, fTimeIntrinsic;

	SrcImage.Load("./image/Source.bmp",CXIMAGE_FORMAT_BMP);	//A 이미지를 로드 한다.
	
	unsigned char* pRAW = (unsigned char*)SrcImage.GetDIB();
	memcpy(pSrc,pRAW+BMP_HEADER_LENGTH,IMAGE_SIZE);	//bmp 해더를 제외한 데이터만 가져온다.

	unsigned int ROI[4] = {0,0,WIDTH,HEIGHT};
	short Kernel[9] = {-1,-1,-1,
						-1,9,-1,
						-1,-1,-1};

	watch.Start();
	EdgeDetect3x3C(pSrc,pResult,WIDTH,HEIGHT,ROI);
	watch.End();

	fTimeC = watch.GetDurationMilliSecond();

	Result.CreateFromArray(pResult,WIDTH,HEIGHT,8,256,FALSE);
	Result.Save("./image/ResultC.bmp",CXIMAGE_FORMAT_BMP);	//Result 이미지 저장.
	
	watch.Start();
	EdgeDetect3x3Intrinsic(pSrc,pResult,WIDTH,HEIGHT,ROI);
	watch.End();

	fTimeIntrinsic = watch.GetDurationMilliSecond();

	Result.CreateFromArray(pResult,WIDTH,HEIGHT,8,256,FALSE);
	Result.Save("./image/ResultIntrinsic.bmp",CXIMAGE_FORMAT_BMP);	//Result 이미지 저장.

	CString ResultString;
	ResultString.Format("C Time : %f msec\nIntrinsic : %f msec\n",
		fTimeC, fTimeIntrinsic);
	
	AfxMessageBox(ResultString);

	delete[] pResult;
	delete[] pSrc;

	CDialog::OnOK();
}

void CImagetestDlg::EdgeDetect3x3Intrinsic(unsigned char* pSrc,unsigned char* pDest,unsigned int nImageWidth, unsigned int nImageHeight,	unsigned int *ROIPoint)
{
	unsigned int nStartX = ROIPoint[0];
	unsigned int nStartY = ROIPoint[1];
	unsigned int nEndX = ROIPoint[2];
	unsigned int nEndY = ROIPoint[3];

	if(0 == nStartX) nStartX = 1;	
	if(0 == nStartY) nStartY = 1;	
	if(nImageWidth == nEndX) nEndX = nImageWidth - 1;
	if(nImageHeight == nEndY) nEndY = nImageHeight - 1;

	unsigned char * iterSrc;
	unsigned char * iterDest;

	__m128i ZeroData = _mm_setzero_si128();

	__m128i ImageHigh;
	__m128i ImageLow;

	__m128i ResultHigh;
	__m128i ResultLow;

	for( int xIndex = nStartX; xIndex < nEndX; xIndex+= 16)
	{
		for( int yIndex = nStartY; yIndex < nEndY; yIndex++)
		{
			iterSrc = pSrc+xIndex+ nImageWidth*yIndex;
			iterDest = pDest+xIndex+ nImageWidth*yIndex;

			ResultHigh = _mm_setzero_si128();
			ResultLow = _mm_setzero_si128();

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc-1-nImageWidth));
			//(x-1,y-1)16 byte 읽기

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			// 1/8 계산
			ImageHigh = _mm_srli_epi16(ImageHigh,3);
			ImageLow = _mm_srli_epi16(ImageLow,3);
			
			// 1/8 값 합계
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);
			
			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc-nImageWidth));
			//(x,y-1)  16 byte 읽기

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			// 1/8 계산
			ImageHigh = _mm_srli_epi16(ImageHigh,3);
			ImageLow = _mm_srli_epi16(ImageLow,3);
			
			// 1/8 값 합계
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);
			
			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc+1-nImageWidth));
			//(x+1,y-1)16 byte 읽기
			
			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			// 1/8 계산
			ImageHigh = _mm_srli_epi16(ImageHigh,3);
			ImageLow = _mm_srli_epi16(ImageLow,3);
			
			// 1/8 값 합계
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);
			
			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc-1));
			//(x-1,y)  16 byte 읽기
			
			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			// 1/8 계산
			ImageHigh = _mm_srli_epi16(ImageHigh,3);
			ImageLow = _mm_srli_epi16(ImageLow,3);
			
			// 1/8 값 합계
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);
			
			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc+1));
			//(x+1,y)  16 byte 읽기
			
			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			// 1/8 계산
			ImageHigh = _mm_srli_epi16(ImageHigh,3);
			ImageLow = _mm_srli_epi16(ImageLow,3);
			
			// 1/8 값 합계
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);
			
			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc-1+nImageWidth));
			//(x-1,y+1)16 byte 읽기
			
			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			// 1/8 계산
			ImageHigh = _mm_srli_epi16(ImageHigh,3);
			ImageLow = _mm_srli_epi16(ImageLow,3);
			
			// 1/8 값 합계
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);
			
			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc+nImageWidth));
			//(x,y+1)  16 byte 읽기
			
			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			// 1/8 계산
			ImageHigh = _mm_srli_epi16(ImageHigh,3);
			ImageLow = _mm_srli_epi16(ImageLow,3);
			
			// 1/8 값 합계
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);
			
			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc+1+nImageWidth));
			//(x+1,y+1)16 byte 읽기
			
			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			// 1/8 계산
			ImageHigh = _mm_srli_epi16(ImageHigh,3);
			ImageLow = _mm_srli_epi16(ImageLow,3);
			
			// 1/8 값 합계
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);
			
			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc));
			//(x,y)    16 byte 읽기
			
			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			//(x,y)값 빼기
			ResultHigh = _mm_subs_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_subs_epi16(ResultLow,ImageLow);
			
			ResultLow = _mm_packus_epi16(ResultLow,ResultHigh);
			//상위 pack과 하위 pack 조합
			ResultLow = _mm_cmpgt_epi8(ResultLow,ZeroData);
			//Edge 부 시각화

			_mm_storeu_si128( (__m128i*)iterDest,ResultLow);
			//메모리에 결과 저장
		}
	}	
	
}

void CImagetestDlg::EdgeDetect3x3C(unsigned char *pSrc, unsigned char *pDest, unsigned int nImageWidth, unsigned int nImageHeight, unsigned int *ROIPoint)
{
	unsigned int nStartX = ROIPoint[0];
	unsigned int nStartY = ROIPoint[1];
	unsigned int nEndX = ROIPoint[2];
	unsigned int nEndY = ROIPoint[3];
	
	if(0 == nStartX) nStartX = 1;
	if(0 == nStartY) nStartY = 1;
	if(nImageWidth == nEndX) nEndX = nImageWidth - 1;
	if(nImageHeight == nEndY) nEndY = nImageHeight - 1;

	short total = 0;
	short value[9] = {0};
	
	for(unsigned int i = nStartX; i < nEndX; i++)
	{
		for(unsigned int j = nStartY; j < nEndY; j++)
		{
			total = 0;
			value[0] = pSrc[i+j*nImageWidth-nImageWidth-1];
			total += value[0]/8;
			
			value[1] = pSrc[i+j*nImageWidth-nImageWidth];
			total += value[1]/8;

			value[2] = pSrc[i+j*nImageWidth-nImageWidth+1];
			total += value[2]/8;
			
			value[3] = pSrc[i+j*nImageWidth-1];
			total += value[3]/8;

			value[4] = pSrc[i+j*nImageWidth];
			total -= value[4];

			value[5] = pSrc[i+j*nImageWidth+1];
			total += value[5]/8;

			value[6] = pSrc[i+j*nImageWidth+nImageWidth-1];
			total += value[6]/8;

			value[7] = pSrc[i+j*nImageWidth+nImageWidth];
			total += value[7]/8;

			value[8] = pSrc[i+j*nImageWidth+nImageWidth+1];
			total += value[8]/8;

			if(total < 0)	total = 0;
			if(total > 0)	total = 255;

			pDest[i+j*nImageWidth] = (unsigned char)total;
		}
	}
}
