﻿
// GMPAddDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "GMPAdd.h"
#include "GMPAddDlg.h"
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


// CGMPAddDlg 대화 상자



CGMPAddDlg::CGMPAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GMPADD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGMPAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGMPAddDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD, &CGMPAddDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_ADDMULTI, &CGMPAddDlg::OnBnClickedBtnAddmulti)
	ON_BN_CLICKED(IDC_BTN_MULTI, &CGMPAddDlg::OnBnClickedBtnMulti)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &CGMPAddDlg::OnBnClickedBtnClear)
END_MESSAGE_MAP()


// CGMPAddDlg 메시지 처리기

BOOL CGMPAddDlg::OnInitDialog()
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

void CGMPAddDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGMPAddDlg::OnPaint()
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
HCURSOR CGMPAddDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGMPAddDlg::OnBnClickedBtnAdd()
{
	GetDlgItem(IDC_EDT_ADD_RESULT)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDT_MUL_RESULT)->SetWindowTextW(_T(""));

	UpdateData(TRUE);

	// GMP 변수 선언
	mpz_t gmpNum1, gmpNum2, gmpAddResult;

	CString strNum1, strNum2;

	GetDlgItem(IDC_EDT_NUMBER1)->GetWindowText(strNum1);
	GetDlgItem(IDC_EDT_NUMBER2)->GetWindowText(strNum2);

	// CString을 const char* 변환
	CStringA strA = CStringA(strNum1);
	CStringA strB = CStringA(strNum2);
	
	int iStrLength1 = strA.GetLength() + 1;
	int iStrLength2 = strB.GetLength() + 1;

	char *chArray1 = strA.GetBuffer();
	char *chArray2 = strB.GetBuffer();


	// 결과값 저장 메모리
	char strAddResult[1024];
	mpz_init(gmpNum1);
	mpz_init(gmpNum2);
	mpz_init(gmpAddResult);

	// sz1, sz2를 10진수 변환
	mpz_init_set_str(gmpNum1, chArray1, 10);
	mpz_init_set_str(gmpNum2, chArray2, 10);

	// Add 연산
	mpz_add(gmpAddResult, gmpNum1, gmpNum2);

	// 10진수 결과를 저장
	mpz_get_str(strAddResult, 10, gmpAddResult);

	// 출력 변환
	CString strAddReulConv(strAddResult);
	GetDlgItem(IDC_EDT_ADD_RESULT)->SetWindowTextW(strAddReulConv);

	// gmp 변수 해제
	mpz_clear(gmpNum1);
	mpz_clear(gmpNum2);
	mpz_clear(gmpAddResult);

	UpdateData(FALSE);
}

void CGMPAddDlg::OnBnClickedBtnAddmulti()
{
	GetDlgItem(IDC_EDT_ADD_RESULT)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDT_MUL_RESULT)->SetWindowTextW(_T(""));

	UpdateData(TRUE);

	// GMP 변수 선언
	mpz_t gmpNum1, gmpNum2, gmpAddResult, gmpMulResult;

	CString strNum1, strNum2;

	GetDlgItem(IDC_EDT_NUMBER1)->GetWindowText(strNum1);
	GetDlgItem(IDC_EDT_NUMBER2)->GetWindowText(strNum2);

	// CString을 const char* 변환
	CStringA strA = CStringA(strNum1);
	CStringA strB = CStringA(strNum2);

	int iStrLength1 = strA.GetLength() + 1;
	int iStrLength2 = strB.GetLength() + 1;

	char* chArray1 = strA.GetBuffer();
	char* chArray2 = strB.GetBuffer();


	// 결과값 저장 메모리
	char strAddResult[1024];
	char strMulResult[1024];
	mpz_init(gmpNum1);
	mpz_init(gmpNum2);
	mpz_init(gmpAddResult);
	mpz_init(gmpMulResult);

	// sz1, sz2를 10진수 변환
	mpz_init_set_str(gmpNum1, chArray1, 10);
	mpz_init_set_str(gmpNum2, chArray2, 10);

	// Add 연산
	mpz_add(gmpAddResult, gmpNum1, gmpNum2);

	// Multiple 연산
	mpz_mul(gmpMulResult, gmpNum1, gmpNum2);

	// 10진수 결과를 저장
	mpz_get_str(strAddResult, 10, gmpAddResult);
	mpz_get_str(strMulResult, 10, gmpMulResult);

	// 출력 변환
	CString strAddReulConv(strAddResult);
	CString strMulReulConv(strMulResult);

	GetDlgItem(IDC_EDT_ADD_RESULT)->SetWindowTextW(strAddReulConv);
	GetDlgItem(IDC_EDT_MUL_RESULT)->SetWindowTextW(strMulReulConv);

	// gmp 변수 해제
	mpz_clear(gmpNum1);
	mpz_clear(gmpNum2);
	mpz_clear(gmpAddResult);
	mpz_clear(gmpMulResult);


	UpdateData(FALSE);
}

void CGMPAddDlg::OnBnClickedBtnMulti()
{
	GetDlgItem(IDC_EDT_ADD_RESULT)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDT_MUL_RESULT)->SetWindowTextW(_T(""));

	UpdateData(TRUE);

	// GMP 변수 선언
	mpz_t gmpNum1, gmpNum2, gmpMulResult;

	CString strNum1, strNum2;

	GetDlgItem(IDC_EDT_NUMBER1)->GetWindowText(strNum1);
	GetDlgItem(IDC_EDT_NUMBER2)->GetWindowText(strNum2);

	// CString을 const char* 변환
	CStringA strA = CStringA(strNum1);
	CStringA strB = CStringA(strNum2);

	int iStrLength1 = strA.GetLength() + 1;
	int iStrLength2 = strB.GetLength() + 1;

	char* chArray1 = strA.GetBuffer();
	char* chArray2 = strB.GetBuffer();


	// 결과값 저장 메모리
	char strAddResult[1024];
	char strMulResult[1024];
	mpz_init(gmpNum1);
	mpz_init(gmpNum2);
	mpz_init(gmpMulResult);

	// sz1, sz2를 10진수 변환
	mpz_init_set_str(gmpNum1, chArray1, 10);
	mpz_init_set_str(gmpNum2, chArray2, 10);

	// Multiple 연산
	mpz_mul(gmpMulResult, gmpNum1, gmpNum2);

	// 10진수 결과를 저장
	mpz_get_str(strMulResult, 10, gmpMulResult);

	// 출력 변환
	CString strMulReulConv(strMulResult);
	GetDlgItem(IDC_EDT_MUL_RESULT)->SetWindowTextW(strMulReulConv);

	// gmp 변수 해제
	mpz_clear(gmpNum1);
	mpz_clear(gmpNum2);
	mpz_clear(gmpMulResult);


	UpdateData(FALSE);
}

void CGMPAddDlg::OnBnClickedBtnClear()
{
	GetDlgItem(IDC_EDT_NUMBER1)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDT_NUMBER2)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDT_ADD_RESULT)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDT_MUL_RESULT)->SetWindowTextW(_T(""));
}
