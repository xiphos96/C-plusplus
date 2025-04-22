#include <gflags.h>
#include <iostream>

using namespace std;

DEFINE_int32(port, 0, "What port to listen on");
DEFINE_string(languages, "english", "comma-separated list of languages to offer in the 'lang' menu");

//��Ʈ ���� ��ȿ������ �˻��ϴ� �ݹ� �Լ�
static bool ValidatePort(const char* flagname, gflags::int32 value) {
	if (value > 0 && value < 32768)   // value is ok
		return true;
	printf("Invalid port value for --%s: %d\n", flagname, (int)value);
	return false;
}

//�� ���α׷����� �����ϴ����� �˻��ϴ� �ݹ� �Լ�
static bool ValidateLanguage(const char* flagname, const std::string& value) {

	if (value.compare("english") == 0 ||
		value.compare("french") == 0 ||
		value.compare("german") == 0)
		return true;

	return false;
}

int main(int argc, char* argv[])
{
	//��Ʈ���� ��ȿ������ �˻��ϴ� �ݹ� �Լ� �߰�
	bool bResult = gflags::RegisterFlagValidator(&FLAGS_port, &ValidatePort);
	assert(bResult == true);

	//��� ��Ʈ���� ��ȿ������ üũ�ϴ� �ݹ� �Լ� �߰�
	bResult = gflags::RegisterFlagValidator(&FLAGS_languages, &ValidateLanguage);
	assert(bResult == true);
	//Ŀ�ǵ� ������ �Ľ�
	gflags::ParseCommandLineFlags(&argc, &argv, true);

	cout << FLAGS_languages.c_str() << endl;
	cout << FLAGS_port << endl;
	return 0;
}
