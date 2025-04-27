#pragma once
#include "../Files/Include/gmp.h"


class CGMPProcess
{
	public:
		bool InitInstance();
		bool ExitInstance();

		bool CalcAdd(CString paraNum1, CString paraNum2);
		bool CalcMul(CString paraNum1, CString paraNum2);
		CString GetResult();

	private:
		CString m_strCalcResult;
	protected:
};