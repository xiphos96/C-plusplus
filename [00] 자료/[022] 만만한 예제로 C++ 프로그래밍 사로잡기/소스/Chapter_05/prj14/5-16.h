// 5-16.h

const char *const NAME[] = {
	"����", "�λ�", "�뱸", "��õ", "����", "����", "���",
	"���", "����", "��û��", "��û��", "�����", "����",
	"����", "���","����", ""
};

const int CODE[] = {
	11, 21, 22, 23, 24, 25, 26, 31,
	32, 33, 34, 35, 36, 37, 38, 39
};

int getCode(const char *name);
void printClass(const char *name);