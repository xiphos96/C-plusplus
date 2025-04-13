//#include "ABC_45.h"
//{for encrypter's sake
//E��ϵ�к���
#define BinFileTimeStampCreate XYZ_005
#define BinFileEncrypt XYZ_031
#define BinFileTimeStampGet XYZ_074
#define BinFileDecrypt  XYZ_033
#define FirmwareEncrypt XYZ_026
#define FirmwareDecrypt XYZ_029
//}
//{213x ϵ�к���
#define BinFileTimeStampCreate_213X XYZ_100
#define BinFileEncrypt_213X XYZ_110
#define BinFileTimeStampGet_213X XYZ_113
#define BinFileDecrypt_213X  XYZ_112
#define FirmwareEncrypt_213X XYZ_106

//add new func: 2010-6-4 joelee
#define FirmwareEncrypt_213X_AutoUpgrade XYZ_106N 

#define FirmwareDecrypt_213X XYZ_108
#define GetAgentInfo XYZ_114
//}
#define SDKFirmwareDecrypt_Part XYZ_108_2
#define  FastEncrypt		XYZ_120
#define  FastDecrypt		XYZ_121


extern "C" {
/*
	//{Z80 MCU
    int MCUEncrypt(unsigned char *pbBuffer, long length, unsigned char pbKey);
	//}
	//{D 
	char FileEncrypt(char *pInputFileName, char *pOutputEncryptFileName);
	char FileDecrypt(unsigned char *pInOutputBuffer,long *InOutputBufferLength);
	char FirmwareFileEncrypt(unsigned char * pInOutputBuffer, long *InputBufferLength, 
		unsigned char *pInOutputFileHeaderBuffer, long *InOutputFileHeaderBufferLength);	
	char FirmwareFileDecrypt(unsigned char *pInOutputBuffer, long *InOutputBufferLength);
	//}
	//{E
	char BinFileTimeStampCreate(unsigned char *pOutputBinFileTimeStamp);
	char BinFileEncrypt(unsigned char *pInOutputBuffer, long *InOutputBufferLength, 
		unsigned char *pInputFileNameBuffer, long *InputFileNameTotalLength,
		unsigned char *pInputBinFileTimeStamp);
  char BinFileTimeStampCheck(unsigned char *pInputBinFileTimeStamp1, unsigned char *pInputBinFileTimeStamp2);
  char BinFileDecrypt(unsigned char *pInOutputBuffer, long *InOutputBufferLength,
		unsigned char *pInputFileNameBuffer, 
		long *InputFileNameTotalLength, unsigned char *pInputBinFileTimeStamp);
	char BinFileTimeStampGet(unsigned char *pInputBuffer, long *InputBufferLength, 
		unsigned char *pOutputBinFileTimeStamp);
	char FirmwareEncrypt(unsigned char *pInOutputBuffer, long *InOutputBufferLength,unsigned char *pOutputDogID); 
			char FirmwareDecrypt (unsigned char *pInOutputBuffer, long *InOutputBufferLength,
		unsigned char *pInputDogID);
	//}
	//{213X
	char FirmwareEncrypt_213X(unsigned char *pInOutputBuffer, long *InOutputBufferLength,
		unsigned char *pOutputDogID, AgentData *Agent); 
	char FirmwareEncrypt_213X_AutoUpgrade(unsigned char *pInOutputBuffer, long *InOutputBufferLength,
		unsigned char *pOutputDogID, AgentData *Agent); 
	char BinFileTimeStampGet_213X(unsigned char *pInputBuffer, long *InputBufferLength, 
		unsigned char *pOutputBinFileTimeStamp);
	char BinFileDecrypt_213X(unsigned char *pInOutputBuffer, long *InOutputBufferLength,
		unsigned char *pInputFileNameBuffer, 
		long *InputFileNameTotalLength, unsigned char *pInputBinFileTimeStamp);
	char BinFileTimeStampCreate_213X(unsigned char *pOutputBinFileTimeStamp);
	char BinFileEncrypt_213X(unsigned char *pInOutputBuffer, long *InOutputBufferLength, 
		unsigned char *pInputFileNameBuffer, long *InputFileNameTotalLength,
		unsigned char *pInputBinFileTimeStamp);
	char FirmwareDecrypt_213X (unsigned char *pInOutputBuffer, long *InOutputBufferLength,
		unsigned char *pInputDogID,unsigned char *ChipValue);
	char GetAgentInfo(unsigned char *ChipValue, AgentData *Agent);
	//}
*/
	/************************************************************************/
	/*
	 * pInOutputBuffer         ����\����������bufferָ��(�ڽӿ������ռ����buffer��
     * InOutputBufferLength    ����\����������buffer����
     * DecryptLength           ����Ҫ���ܵ�ʵ�ʳ���
     * pInputDogID             ����Dog ID bufferָ�� //ID 16byte �ӹ��������
     * ChipValue               ���chip��Ϣ//512 byte �����ܣ�
  
	 * ע��̶���*InOutputBufferLength =18*1024+ DecryptLength��
     *                                                                
	/************************************************************************/
	//char SDKFirmwareDecrypt_Part(unsigned char *pInOutputBuffer, long *InOutputBufferLength,
		//long DecryptLength, unsigned char *pInputDogID, unsigned char *ChipValue);

	char FastEncrypt(unsigned char *pInOutputBuffer, long *InOutputBufferLength);
	char FastDecrypt(unsigned char *pInOutputBuffer, long *InOutputBufferLength);
}
