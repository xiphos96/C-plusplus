#include <iostream>
using namespace std;

//////// ���� /////////////
// �迭�� ��� ���ҿ� �ݺ����� �۾��� �ϵ��� �߻�ȭ�Ǿ� ����(��ü���� �۾��� ����)
void For_each(int *begin, int *end, void (*pf)(int ) )
{
    while( begin != end )
    {
        pf( *begin++ ); // Ŭ���̾�Ʈ �Լ� ȣ��(�ݹ�)
    }
}
/////// Ŭ���̾�Ʈ /////////
void Print1(int n) // ������ �̿��Ͽ� ���Ҹ� ���
{
    cout << n <<' ';
}
void Print2(int n) // �� ���Ҹ� �����Ͽ� ���
{
    cout << n*n <<" ";
}
void Print3(int n) // ���ڿ��� endl�� �̿��Ͽ� ���Ҹ� ���
{
    cout <<"���� : "<< n <<endl;
}
void main( )
{
    int arr[5] = {10, 20, 30, 40, 50};

    For_each(arr, arr+5, Print1); // Print1() �ݹ� �Լ��� �ּҸ� ����
    cout << endl << endl;
    For_each(arr, arr+5, Print2); // Print2() �ݹ� �Լ��� �ּҸ� ����
    cout << endl << endl;
    For_each(arr, arr+5, Print3); // Print3() �ݹ� �Լ��� �ּҸ� ����
}