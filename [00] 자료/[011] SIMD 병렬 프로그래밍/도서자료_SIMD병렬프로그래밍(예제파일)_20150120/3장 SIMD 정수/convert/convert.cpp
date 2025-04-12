// convert.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) int IntSource[4] = {1, 2, 3, 4};
	__declspec(align(16)) float FloatSource[4] = {5.0, 6.0, 7.0, 8.0};
	__declspec(align(16)) double DoubleSource[2] = {9.0, 10.0};

	__declspec(align(16)) float IntToFloat[4] = {0};
	__declspec(align(16)) double IntToDouble[2] =  {0};	
	__declspec(align(16)) int FloatToInt[4] = {0};
	__declspec(align(16)) double FloatToDouble[2] = {0};
	__declspec(align(16)) int DoubleToInt[4] =  {0};
	__declspec(align(16)) float DoubleToFloat[4] =  {0};


	__asm
	{
		pushad
			
		movdqa xmm0, IntSource		 //xmm0 = IntSource

		cvtdq2ps xmm1, xmm0			//xmm0 --> xmm1
		cvtdq2pd xmm2, xmm0			//xmm0 --> xmm2
		
		movaps xmm0, FloatSource	 //xmm0 = FloatSource

		cvtps2dq xmm3, xmm0			//xmm0 --> xmm3
		cvtps2pd xmm4, xmm0			//xmm0 --> xmm4
		
		movapd xmm0, DoubleSource	//xmm2 = DoubleSource

		cvtpd2dq xmm5, xmm0			//xmm0 --> xmm5
		cvtpd2ps xmm6, xmm0			//xmm0 --> xmm6

		movaps IntToFloat, xmm1		//IntToFloat = xmm1
		movapd IntToDouble, xmm2	//IntToDouble = xmm2
	
		movdqa FloatToInt, xmm3		//FloatToInt = xmm3
		movapd FloatToDouble, xmm4	//FloatToDouble = xmm4
			
		movdqa DoubleToInt, xmm5	//DoubleToInt = xmm5
		movaps DoubleToFloat, xmm6	//DoubleToFloat = xmm6

		popad
		
	}
	printf("IntToFloat : %.3f,%.3f,%.3f,%.3f \n",
		IntToFloat[3],IntToFloat[2],IntToFloat[1],IntToFloat[0]);
	printf("IntToDouble : %.3f,%.3f \n",
		IntToDouble[1],IntToDouble[0]);

	printf("FloatToInt : %d,%d,%d,%d \n",
		FloatToInt[3],FloatToInt[2],FloatToInt[1],FloatToInt[0]);
	printf("FloatToDouble : %.3f,%.3f \n",
		FloatToDouble[1],FloatToDouble[0]);

	printf("DoubleToInt : %d,%d,%d,%d \n",
		DoubleToInt[3],DoubleToInt[2],DoubleToInt[1],DoubleToInt[0]);
	printf("DoubleToFloat : %.3f,%.3f,%.3f,%.3f \n",
		DoubleToFloat[3],DoubleToFloat[2],DoubleToFloat[1],DoubleToFloat[0]);
	return 0;
}