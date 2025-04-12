// 5-14.h

const char NAME[][5] = {
	"서울", "부산", "대구", "인천", "광주", "대전", "울산", "경기",
	"강원", "충북", "충남", "전북", "전남", "경북", "경남","제주"
};

const int CODE[] = {		// 1차원 상수 배열
	11, 21, 22, 23, 24, 25, 26, 31,
	32, 33, 34, 35, 36, 37, 38, 39
};

int getCode(const char *name);
void printClass(const char *name);