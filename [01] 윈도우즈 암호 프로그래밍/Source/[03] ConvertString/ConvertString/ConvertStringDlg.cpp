﻿
// ConvertStringDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ConvertString.h"
#include "ConvertStringDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CConvertStringDlg 대화 상자



CConvertStringDlg::CConvertStringDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONVERTSTRING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CConvertStringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CConvertStringDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CONVERT_TO_NUMBER, &CConvertStringDlg::OnBnClickedBtnConvertToNumber)
	ON_BN_CLICKED(IDC_BTN_CONVERT_TO_CHARACTER, &CConvertStringDlg::OnBnClickedBtnConvertToCharacter)
END_MESSAGE_MAP()


// CConvertStringDlg 메시지 처리기

BOOL CConvertStringDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CConvertStringDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CConvertStringDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CConvertStringDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CConvertStringDlg::OnBnClickedBtnConvertToNumber()
{
	UpdateData(TRUE);

	CString strNumberInput, strNumberOutput;
	CString strCharacterInput, strCharacterOutput;

	GetDlgItem(IDC_EDT_INPUT_CHARACTER)->GetWindowTextW(strCharacterInput);

	mpz_t z;
	char str_mpz[1024];
	mpz_init(z);
	
	// CString을 char* 형식으로 바꾸기
	CStringA strA = CStringA(strCharacterInput);
	//char* pChar = strA.GetBuffer();

	int nLen = strA.GetLength();
	unsigned char *chArray = new unsigned char[nLen];
	memcpy(chArray, strA.GetBuffer(), nLen);
	
	mympz_inp_raw(z, chArray, nLen);
	mpz_get_str(str_mpz, 16, z);

	CString cstring(str_mpz);
	strNumberOutput = cstring;
	GetDlgItem(IDC_EDT_OUTPUT_HEXA_CHARACTER)->SetWindowTextW(strNumberOutput);

	mpz_clear(z);
	delete[] chArray;
	UpdateData(FALSE);
}

void CConvertStringDlg::mympz_inp_raw(mpz_t z, const unsigned char* c, int n)
{
	int i = 0;
	mpz_set_ui(z, 0);
	while (i < n)
	{
		mpz_mul_2exp(z, z, 8);
		mpz_add_ui(z, z, c[i]);

		i++;
	}
}
void CConvertStringDlg::OnBnClickedBtnConvertToCharacter()
{
	UpdateData(TRUE);

	CString strHexaCharacterInput;
	GetDlgItem(IDC_EDT_INPUT_HEXA_CHARACTER)->GetWindowTextW(strHexaCharacterInput);

	mpz_t temp;
	mpz_init(temp);
	CStringA strA(strHexaCharacterInput);
	const char* cCStringToChar = strA;
	mpz_init_set_str(temp, cCStringToChar, 16);
	

	// 숫자 mpz_t temp를 문자로 변환
	byte_string_t bs2;
	int i = mympz_sizeinbytes(temp);
	byte_string_init(bs2, i);
	mympz_out_raw(temp, bs2->data, i);
	char* d = new char[bs2->len+1];
	memcpy(d, bs2->data, bs2->len);
	d[bs2->len] = '\0';

	// char* -> wchar 변환
	BSTR buf;
	int len = MultiByteToWideChar(CP_ACP, 0, d, strlen(d), NULL, NULL);
	buf = SysAllocStringLen(NULL, len);
	MultiByteToWideChar(CP_ACP, 0, d, strlen(d), buf, len);

	// wchar_t( to CString
	CString strStringOutput;
	strStringOutput.Format(_T("%s"), buf);

	GetDlgItem(IDC_EDT_OUTPUT_CHARACTER)->SetWindowTextW(strStringOutput);
	byte_string_clear(bs2);
	UpdateData(FALSE);

	delete[] d;
}

void CConvertStringDlg::mympz_out_raw(mpz_t x, unsigned char* c, int n)
{
	// 숫자를 문자로 변환
	unsigned long l;
	mpz_t z;
	int i = n - 1; // 배열은 0부터 시작하기 때문
	mpz_init_set(z, x);
	while (i >= 0)
	{
		l = mpz_get_ui(z); // mpz_t를 c타입 정수 unsigned long 형 타입으로 변환
		c[i] = (unsigned char)l;
		mpz_tdiv_q_2exp(z, z, 8);
		i--;
	}

	mpz_clear(z);
}

int CConvertStringDlg::mympz_sizeinbytes(mpz_t x)
{
	int i, n;
	n = mpz_sizeinbase(x, 2); // 영문자 개수 = m이면 n = m-1 => 2^n으로 표현
	i = n >> 3; // 3칸 왼쪽으로 이동 => 2^3으로 나눔 효과
	if (n % 8)
	{
		i++; // 영문자 입력 개수, 한글 입력 개수 * 2
	}

	return i;
}