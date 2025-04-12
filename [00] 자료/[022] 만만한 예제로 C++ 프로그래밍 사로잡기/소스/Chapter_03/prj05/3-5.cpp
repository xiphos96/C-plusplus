// 3-5.cpp

void main()
{
	int a = 123;
	int *p1 = &a;			// 정적 포인터
	int *p2 = new int[100];		// 동적 배열 할당
	int *p3 = 0;			// 널 포인터

	delete p1;					
	delete p2;					
	delete p3;					
}