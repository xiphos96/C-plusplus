#pragma once
#include "../Files/Include/gmp.h"


class CGMPProcess
{
	public:
		bool InitInstance();
		bool ExitInstance();

		CString CalcAdd(CString paraNum1, CString paraNum2);
	private:

	protected:
};