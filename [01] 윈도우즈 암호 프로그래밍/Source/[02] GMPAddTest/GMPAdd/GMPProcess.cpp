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

	// GMP ���� ����
	mpz_t gmpNum1, gmpNum2, gmpAddResult, gmpMulResult;

	// CString�� const char* ��ȯ
	CStringA strA = CStringA(paraNum1);
	CStringA strB = CStringA(paraNum2);

	int iStrLength1 = strA.GetLength() + 1;
	int iStrLength2 = strB.GetLength() + 1;

	char* chArray1 = strA.GetBuffer();
	char* chArray2 = strB.GetBuffer();


	// ����� ���� �޸�
	char cAddResult[1024];
	char cMulResult[1024];
	mpz_init(gmpNum1);
	mpz_init(gmpNum2);
	mpz_init(gmpAddResult);
	mpz_init(gmpMulResult);

	// sz1, sz2�� 10���� ��ȯ
	mpz_init_set_str(gmpNum1, chArray1, 10);
	mpz_init_set_str(gmpNum2, chArray2, 10);

	// Add ����
	mpz_add(gmpAddResult, gmpNum1, gmpNum2);

	// 10���� ����� ����
	mpz_get_str(cAddResult, 10, gmpAddResult);

	// ��� ��ȯ
	CString strResult(cAddResult);
	m_strCalcResult = strResult;

	// gmp ���� ����
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

	// GMP ���� ����
	mpz_t gmpNum1, gmpNum2, gmpAddResult, gmpMulResult;

	// CString�� const char* ��ȯ
	CStringA strA = CStringA(paraNum1);
	CStringA strB = CStringA(paraNum2);

	int iStrLength1 = strA.GetLength() + 1;
	int iStrLength2 = strB.GetLength() + 1;

	char* chArray1 = strA.GetBuffer();
	char* chArray2 = strB.GetBuffer();


	// ����� ���� �޸�
	char cAddResult[1024];
	char cMulResult[1024];
	mpz_init(gmpNum1);
	mpz_init(gmpNum2);
	mpz_init(gmpAddResult);
	mpz_init(gmpMulResult);

	// sz1, sz2�� 10���� ��ȯ
	mpz_init_set_str(gmpNum1, chArray1, 10);
	mpz_init_set_str(gmpNum2, chArray2, 10);

	// Add ����
	mpz_mul(gmpAddResult, gmpNum1, gmpNum2);

	// 10���� ����� ����
	mpz_get_str(cAddResult, 10, gmpAddResult);

	// ��� ��ȯ
	CString strResult(cAddResult);
	m_strCalcResult = strResult;

	// gmp ���� ����
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