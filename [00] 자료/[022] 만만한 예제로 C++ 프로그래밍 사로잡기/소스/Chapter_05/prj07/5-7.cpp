// 5-7.cpp

#include <iostream.h>
#include <string.h>		// strtok()

const int MAXCHAR = 255;

int strtoknum(const char *str, const char *seps=" \t\n");

void main()
{
	cout << "한 문장에서 단어수 세기 \n";
	int n;
	char *string1 = "I am a boy.\tYou're a girl\n";
	n = strtoknum(string1);
	cout << "string1 = " << string1 << ": " << n << endl;
	
	char *string2 = "UNIX,WINDOW XP,LINUX,OS/2", delim = ',';
	n = strtoknum(string2, &delim);
	cout << "string2 = " << string2 << ": " << n << endl;

	char *string3 = "\tC/C++/Java/VC++/MFC\n"
						"\t\tSmalltalk/Clos/Prolog\tLanguage";
	char *seps = " \n\t/";
	n = strtoknum(string3, seps);
	cout << "string3 = " << string3 << ": " << n << endl;
}

int strtoknum(const char *str, const char *seps /*=" \t\n"*/)
{   
	int count = 0;
	char *token;
	char tmp[MAXCHAR+1];

	strcpy(tmp, str);			// side-effect 방지
	token = strtok(tmp, seps);
	while( token != NULL )
	{
		count++;
		token = strtok( NULL, seps );
	}
	return count;
}