#include "expat.h"
#include "ExpatImpl.h"
#include <minwindef.h>
#include <stdio.h>
//���� �ļ� ����
class CMyXML : public CExpatImpl <CMyXML>
{
public:
	//�߷�
	// Start element handler
	void OnStartElement(const XML_Char* pszName, const XML_Char** papszAttrs)
	{
		printf("We got a start element %s\n", pszName);
		return;
	}

	// End element handler
	void OnEndElement(const XML_Char* pszName)
	{
		printf("We got an end element %s\n", pszName);
		return;
	}

	// Character data handler
	void OnCharacterData(const XML_Char* pszData, int nLength)
	{
		// note, pszData is NOT null terminated
		printf("We got %d bytes of data\n", nLength);
		return;
	}
};
//XML ������ �Ľ��Ѵ�.
bool ParseSomeXML(LPCSTR pszFileName)
{
	//�ļ� ����
	CMyXML sParser;
	if (!sParser.Create())
		return false;
	//XML ������ ����.
	FILE* fp = NULL;
	fp = fopen(pszFileName, "r");
	if (fp == 0)
		return false;

	//�� �پ� ������ �о���̸� �����͸� ó���Ѵ�.
	bool fSuccess = true;
	while (!feof(fp) && fSuccess)
	{
		LPSTR pszBuffer = (LPSTR)sParser.GetBuffer(256); // REQUEST
		if (pszBuffer == NULL)
			fSuccess = false;
		else
		{
			int nLength = fread(pszBuffer, 1, 256, fp); // READ
			//���۸� �Ľ��ϰ� �Ľ̿� �����ϸ� �ļ��� �ڵ鷯�� ȣ��ȴ�.
			fSuccess = sParser.ParseBuffer(nLength, nLength == 0); // PARSE
		}
	}
	
	return true;
}

int main(int argc, char* argv[])
{
	ParseSomeXML("example.xml");
	return 0;
}
