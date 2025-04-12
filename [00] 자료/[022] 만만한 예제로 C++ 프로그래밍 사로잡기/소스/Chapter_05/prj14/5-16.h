// 5-16.h

const char *const NAME[] = {
	"서울", "부산", "대구", "인천", "광주", "대전", "울산",
	"경기", "강원", "충청북", "충청남", "전라북", "전라남",
	"경상북", "경상남","제주", ""
};

const int CODE[] = {
	11, 21, 22, 23, 24, 25, 26, 31,
	32, 33, 34, 35, 36, 37, 38, 39
};

int getCode(const char *name);
void printClass(const char *name);