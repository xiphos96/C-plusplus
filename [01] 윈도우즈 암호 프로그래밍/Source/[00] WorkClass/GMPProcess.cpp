#include "pch.h"
#include "GMPProcess.hpp"

bool CGMPProcess::InitInstance()
{
	m_strCalcResult = _T("");
	return true;
}

bool CGMPProcess::ExitInstance()
{
	return true;
}

bool CGMPProcess::CalcAdd(CString paraNum1, CString paraNum2)
{
	if ((paraNum1.IsEmpty() == true) || (paraNum2.IsEmpty() == true))
	{
		return false;
	}

	// GMP 변수 선언
	mpz_t gmpNum1, gmpNum2, gmpAddResult, gmpMulResult;

	// CString을 const char* 변환
	CStringA strA = CStringA(paraNum1);
	CStringA strB = CStringA(paraNum2);

	int iStrLength1 = strA.GetLength() + 1;
	int iStrLength2 = strB.GetLength() + 1;

	char* chArray1 = strA.GetBuffer();
	char* chArray2 = strB.GetBuffer();


	// 결과값 저장 메모리
	char cAddResult[1024];
	char cMulResult[1024];
	mpz_init(gmpNum1);
	mpz_init(gmpNum2);
	mpz_init(gmpAddResult);
	mpz_init(gmpMulResult);

	// sz1, sz2를 10진수 변환
	mpz_init_set_str(gmpNum1, chArray1, 10);
	mpz_init_set_str(gmpNum2, chArray2, 10);

	// Add 연산
	mpz_add(gmpAddResult, gmpNum1, gmpNum2);

	// 10진수 결과를 저장
	mpz_get_str(cAddResult, 10, gmpAddResult);

	// 출력 변환
	CString strResult(cAddResult);
	m_strCalcResult = strResult;

	// gmp 변수 해제
	mpz_clear(gmpNum1);
	mpz_clear(gmpNum2);
	mpz_clear(gmpAddResult);
	mpz_clear(gmpMulResult);

	return true;
}

bool CGMPProcess::CalcMul(CString paraNum1, CString paraNum2)
{
	if ((paraNum1.IsEmpty() == true) || (paraNum2.IsEmpty() == true))
	{
		return false;
	}

	// GMP 변수 선언
	mpz_t gmpNum1, gmpNum2, gmpAddResult, gmpMulResult;

	// CString을 const char* 변환
	CStringA strA = CStringA(paraNum1);
	CStringA strB = CStringA(paraNum2);

	int iStrLength1 = strA.GetLength() + 1;
	int iStrLength2 = strB.GetLength() + 1;

	char* chArray1 = strA.GetBuffer();
	char* chArray2 = strB.GetBuffer();


	// 결과값 저장 메모리
	char cAddResult[1024];
	char cMulResult[1024];
	mpz_init(gmpNum1);
	mpz_init(gmpNum2);
	mpz_init(gmpAddResult);
	mpz_init(gmpMulResult);

	// sz1, sz2를 10진수 변환
	mpz_init_set_str(gmpNum1, chArray1, 10);
	mpz_init_set_str(gmpNum2, chArray2, 10);

	// Add 연산
	mpz_mul(gmpAddResult, gmpNum1, gmpNum2);

	// 10진수 결과를 저장
	mpz_get_str(cAddResult, 10, gmpAddResult);

	// 출력 변환
	CString strResult(cAddResult);
	m_strCalcResult = strResult;

	// gmp 변수 해제
	mpz_clear(gmpNum1);
	mpz_clear(gmpNum2);
	mpz_clear(gmpAddResult);
	mpz_clear(gmpMulResult);

	return true;
}

CString CGMPProcess::GetResult()
{
	return m_strCalcResult;
}

CString CGMPProcess::CharToCString(char *data)
{
	int len;
	CString str;
	BSTR buf;
	// char* to wchar* conversion
	len = MultiByteToWideChar(CP_ACP, 0, data, strlen(data), NULL, NULL);
	buf = SysAllocStringLen(NULL, len);
	MultiByteToWideChar(CP_ACP, 0, data, strlen(data), buf, len);
	
	// wchar* to CString conversion
	str.Format(_T("%s", buf));
	
	return str;
}