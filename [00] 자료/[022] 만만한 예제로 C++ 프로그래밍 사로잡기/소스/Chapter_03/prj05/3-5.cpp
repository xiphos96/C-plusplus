// 3-5.cpp

void main()
{
	int a = 123;
	int *p1 = &a;			// ���� ������
	int *p2 = new int[100];		// ���� �迭 �Ҵ�
	int *p3 = 0;			// �� ������

	delete p1;					
	delete p2;					
	delete p3;					
}