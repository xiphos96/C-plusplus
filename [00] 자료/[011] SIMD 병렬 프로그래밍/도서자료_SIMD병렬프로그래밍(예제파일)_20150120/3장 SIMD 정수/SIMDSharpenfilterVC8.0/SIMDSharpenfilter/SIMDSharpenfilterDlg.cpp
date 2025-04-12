// SIMDSharpenfilterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SIMDSharpenfilter.h"
#include "SIMDSharpenfilterDlg.h"
#include "../include/ximage.h"
#include "StopWatch.h"

#pragma comment(lib, "../lib/cximaged.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CSIMDSharpenfilterDlg dialog




CSIMDSharpenfilterDlg::CSIMDSharpenfilterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSIMDSharpenfilterDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSIMDSharpenfilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSIMDSharpenfilterDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CSIMDSharpenfilterDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSIMDSharpenfilterDlg message handlers

BOOL CSIMDSharpenfilterDlg::OnInitDialog()
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

void CSIMDSharpenfilterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSIMDSharpenfilterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSIMDSharpenfilterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSIMDSharpenfilterDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	const unsigned int WIDTH = 256;			//�̹��� ���� 256
	const unsigned int HEIGHT = 256;		//�̹��� ���� 256
	const unsigned int IMAGE_SIZE = WIDTH*HEIGHT;	//�̹��� ������ 256*256
	const unsigned int BMP_HEADER_LENGTH = 1064;	//bmp �ش� ����+�ķ�Ʈ 1064

	unsigned char* pSrc = new unsigned char[IMAGE_SIZE];	//�̹��� ������ ����
	unsigned char* pResult = new unsigned char[IMAGE_SIZE];	//Result ������ ����


	//�̹��� �ε� ����
	CxImage SrcImage;
	CxImage Result;

	CStopWatch watch;

	//�ð� ���� ����
	float				fTimeforDurationC;
	float				fTimeforDurationSSE;

	CString CalcTime, sFileFath;

	SrcImage.Load("../image/Source.bmp",CXIMAGE_FORMAT_BMP);

	unsigned char* pRAWA = (unsigned char*)SrcImage.GetDIB();
	memcpy(pSrc,pRAWA+BMP_HEADER_LENGTH,IMAGE_SIZE);	//bmp �ش��� ������ �����͸� �����´�.

	//�˻� ���� ����
	unsigned int ROI[4] = {0,0,WIDTH,HEIGHT};
	//���� ���� Ŀ��
	short Kernel[9] = {-1,-1,-1,
						-1,9,-1,
						-1,-1,-1};

	watch.Start();
	//C���� �������� ���μ���
	Convolution3x3C(pSrc,pResult,WIDTH,HEIGHT,ROI,Kernel);
	watch.End();

	fTimeforDurationC = watch.GetDurationMilliSecond(); 

	//��� �̹��� ����
	Result.CreateFromArray(pResult,WIDTH,HEIGHT,8,256,FALSE);
	Result.Save("../image/ResultC.bmp",CXIMAGE_FORMAT_BMP);	//Result �̹��� ����.
	
	watch.Start();		//��������
	
	//SIMD ���� �������� ���μ���
	Convolution3x3SIMD(pSrc,pResult,WIDTH,HEIGHT,ROI,Kernel);

	watch.End();		//��������

	fTimeforDurationSSE = watch.GetDurationMilliSecond(); 
	//C���� SIMD ���� �����ð� ��
	CalcTime.Format("C Version    : %f msec\nSSE version : %f msec", fTimeforDurationC, fTimeforDurationSSE);
	AfxMessageBox(CalcTime);

	Result.CreateFromArray(pResult,WIDTH,HEIGHT,8,256,FALSE);
	Result.Save("../image/ResultSSE.bmp",CXIMAGE_FORMAT_BMP);	//Result �̹��� ����.

	delete[] pResult;
	delete[] pSrc;

	OnOK();
}

void CSIMDSharpenfilterDlg::Convolution3x3SIMD(unsigned char* pSrc,unsigned char* pDest,unsigned int nImageWidth, unsigned int nImageHeight,
					unsigned int *ROIPoint, short* pKernel)
{
	unsigned int nStartX = ROIPoint[0];
	unsigned int nStartY = ROIPoint[1];
	unsigned int nEndX = ROIPoint[2];
	unsigned int nEndY = ROIPoint[3];

	if(0 == nStartX) nStartX = 1;	//���͸����� ���� ������ ����ó��
	if(0 == nStartY) nStartY = 1;	//���͸����� ���� ������ ����ó��
	if(nImageWidth == nEndX) nEndX = nImageWidth - 1;
	if(nImageHeight == nEndY) nEndY = nImageHeight - 1;

	__declspec(align(16)) short Mask0[8],Mask1[8],Mask2[8],Mask3[8];			//short�� 8�� kernel ����
	__declspec(align(16)) short Mask4[8],Mask5[8],Mask6[8],Mask7[8],Mask8[8];	//short�� 8�� kernel ����

	for( int i = 0; i < 8; i++)
	{
		Mask0[i] = pKernel[0];	//kernel [m-1][n-1]
		Mask1[i] = pKernel[1];	//kernel [m][n-1]
		Mask2[i] = pKernel[2];	//kernel [m+1][n-1]

		Mask3[i] = pKernel[3];	//kernel [m-1][n]
		Mask4[i] = pKernel[4];	//kernel [m][n]
		Mask5[i] = pKernel[5];	//kernel [m+1][n]

		Mask6[i] = pKernel[6];	//kernel [m-1][n+1]
		Mask7[i] = pKernel[7];	//kernel [m][n+1]
		Mask8[i] = pKernel[8];	//kernel [m+1][n+1]
	}

	unsigned int nProcessLength = (nEndX - nStartX);
	int HLoopCount = nProcessLength/16;		//16���� ���� ���� ���� ī��Ʈ
	unsigned int VLoopCount = nEndY - nStartY;	//���� ���� ���� ī��Ʈ
	unsigned int nRemain = nProcessLength%16;	//16���� ����� ������ �κ� ó��
	unsigned int nNextStartLength = nImageWidth - nProcessLength+16;	//������ ó��
	unsigned char * pStartSrc = pSrc+nStartX+nStartY*nImageWidth;		//���μ��� ���ۺ� ó��
	unsigned char * pDestSrc = pDest+nStartX+nStartY*nImageWidth;		//dest ���� ���ۺ� ����Ʈ
	unsigned int test = 0;
	unsigned int width = nImageWidth;

	__asm
	{
		pushad
		mov eax, pStartSrc
		mov edx, pDestSrc
		mov esi, nNextStartLength
		mov ebx, VLoopCount
		mov ecx, HLoopCount
		mov edi, width

		movdqu xmm3,Mask8
		pxor xmm4,xmm4
VLOOP:
HLOOP:
		//0�� ��ġ		
		pxor xmm7,xmm7				//���� short�� �� �����
		pxor xmm6,xmm6				//���� short�� �� �����

		sub eax, edi
		movdqa xmm5, Mask0			//kernel [m-1][n-1]
		movdqu xmm0,[eax-1]		//src[m-1][n-1]
		movdqu xmm1, xmm0

		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ

		pmullw xmm0, xmm5			//Kernel[m-1][n-1]*src[m-1][n-1]
		pmullw xmm1, xmm5			//Kernel[m-1][n-1]*src[m-1][n-1]

		paddsw xmm7,xmm0			//���� 8 short ��갪 �Է�
		paddsw xmm6,xmm1			//���� 8 short ��갪 �Է�

		//1�� ��ġ
		movdqa xmm5, Mask1			//Kernel[m][n-1]
		movdqu xmm0,[eax]		//src[m][n-1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ
		
		pmullw xmm0, xmm5			//Kernel[m][n-1]*src[m][n-1]
		pmullw xmm1, xmm5			//Kernel[m][n-1]*src[m][n-1]
		
		paddsw xmm7,xmm0				//���� 8 short ��갪 ��
		paddsw xmm6,xmm1				//���� 8 short ��갪 ��

		//2�� ��ġ
		movdqa xmm5, Mask2			//Kernel[m+1][n-1]
		movdqu xmm0,[eax+1]		//src[m+1][n-1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ
		
		pmullw xmm0, xmm5			//Kernel[m+1][n-1]*src[m+1][n-1]
		pmullw xmm1, xmm5			//Kernel[m+1][n-1]*src[m+1][n-1]
		
		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��
		

		//3�� ��ġ
		add eax, edi
		movdqa xmm5, Mask3			//Kernel[m-1][n]
		movdqu xmm0,[eax-1]			//src[m-1][n]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ

		pmullw xmm0, xmm5			//Kernel[m-1][n]*src[m+1][n]
		pmullw xmm1, xmm5			//Kernel[m-1][n]*src[m+1][n]

		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��

		//4�� ��ġ
		movdqa xmm5, Mask4			//Kernel[m][n]
		movdqu xmm0,[eax]			//src[m][n]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ

		pmullw xmm0, xmm5			//Kernel[m][n]*src[m][n]
		pmullw xmm1, xmm5			//Kernel[m][n]*src[m][n]

		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��
		
		//5�� ��ġ
		movdqa xmm5, Mask5			//Kernel[m+1][n]
		movdqu xmm0,[eax+1]			//src[m+1][n]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ

		pmullw xmm0, xmm5			//Kernel[m+1][n]*src[m+1][n]
		pmullw xmm1, xmm5			//Kernel[m+1][n]*src[m+1][n]

		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��

		//6�� ��ġ
		add eax, edi
		movdqa xmm5, Mask6			//Kernel[m-1][n+1
		movdqu xmm0,[eax-1]			//src[m-1][n+1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ

		pmullw xmm0, xmm5			//Kernel[m-1][n+1]*src[m-1][n+1]
		pmullw xmm1, xmm5			//Kernel[m-1][n+1]*src[m-1][n+1]
		
		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��
		
		//7�� ��ġ
		movdqa xmm5, Mask8			//Kernel[m][n+1]
		movdqu xmm0,[eax]			//src[m][n+1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ

		pmullw xmm0, xmm5			//Kernel[m][n+1]*src[m][n+1]
		pmullw xmm1, xmm5			//Kernel[m][n+1]*src[m][n+1]

		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��
		
		//8�� ��ġ
		movdqa xmm5, Mask8			//Kernel[m+1][n+1]
		movdqu xmm0,[eax+1]			//src[m+1][n+1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ
		
		pmullw xmm0, xmm5			//Kernel[m+1][n+1]*src[m+1][n+1]
		pmullw xmm1, xmm5			//Kernel[m+1][n+1]*src[m+1][n+1]
		
		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��
		
		packuswb xmm7,xmm6			//����8 short�� + ���� 8 short�� -> 16byte�� ��ȯ
		movdqu [edx], xmm7

		sub eax, edi
		dec ecx
		cmp ecx,0
		jg ADD16
		je ADDREMAIN
		jl HLOOPEND
ADD16:		//���� ���ι��� 16byte ���� ó�� �ݺ�
		add eax,16
		add edx,16
		jmp HLOOP
ADDREMAIN:	//������ 16���� ó���� ������ �κ� ó��
		add eax,nRemain
		add edx,nRemain
		jmp HLOOP
HLOOPEND:		//���� ���� ���� ����
		add eax,esi
		add edx,esi
		mov ecx, HLoopCount

		dec ebx
		cmp ebx,0
		jz LOOPEND
		jmp VLOOP	//���� ���� ���� ���� ����
LOOPEND:
		popad
		
	}
}

void CSIMDSharpenfilterDlg::Convolution3x3C(unsigned char *pSrc, unsigned char *pDest, unsigned int nImageWidth, unsigned int nImageHeight, unsigned int *ROIPoint, short *pKernel)
{
	unsigned int nStartX = ROIPoint[0];
	unsigned int nStartY = ROIPoint[1];
	unsigned int nEndX = ROIPoint[2];
	unsigned int nEndY = ROIPoint[3];
	unsigned int nPositionXY = 0;
	if(0 == nStartX) nStartX = 1;
	if(0 == nStartY) nStartY = 1;
	if(nImageWidth == nEndX) nEndX = nImageWidth - 1;
	if(nImageHeight == nEndY) nEndY = nImageHeight - 1;

	short total = 0;
	short value[9] = {0};

	for(unsigned int j = nStartY; j < nEndY; j++)
	{	
		for(unsigned int i = nStartX; i < nEndX; i++)
		{
			total = 0;
            nPositionXY = i+j*nImageWidth;
			value[0] = pSrc[nPositionXY-nImageWidth-1];
			total += pKernel[0]*value[0];
			
			value[1] = pSrc[nPositionXY-nImageWidth];
			total += pKernel[1]*value[1];

			value[2] = pSrc[nPositionXY-nImageWidth+1];
			total += pKernel[2]*value[2];
			
			value[3] = pSrc[nPositionXY-1];
			total += pKernel[3]*value[3];

			value[4] = pSrc[nPositionXY];
			total += pKernel[4]*value[4];

			value[5] = pSrc[nPositionXY+1];
			total += pKernel[5]*value[5];

			value[6] = pSrc[nPositionXY+nImageWidth-1];
			total += pKernel[6]*value[6];

			value[7] = pSrc[nPositionXY+nImageWidth];
			total += pKernel[7]*value[7];

			value[8] = pSrc[nPositionXY+nImageWidth+1];
			total += pKernel[8]*value[8];

			if(total < 0)	total = 0;
			if(total > 255)	total = 255;

			pDest[nPositionXY] = (unsigned char)total;
		}
	}
}