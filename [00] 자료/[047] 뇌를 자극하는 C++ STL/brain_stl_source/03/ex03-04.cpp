#include <iostream>
#include <algorithm> // fo_each() �˰���(����)�� ����ϱ� ���� ���
using namespace std;
/////// Ŭ���̾�Ʈ /////////
struct Functor1
{
    void operator()(int n) // ������ �̿��Ͽ� ���Ҹ� ���
    {
        cout << n <<' ';
    }
};
struct Functor2
{
    void operator()(int n) // �� ���Ҹ� �����Ͽ� ���
    {
        cout << n*n <<" ";
    }
};
struct Functor3
{
    void operator()(int n) // ���ڿ��� endl�� �̿��Ͽ� ���Ҹ� ���
    {
        cout <<"���� : "<< n <<endl;
    }
};
void main( )
{
    int arr[5] = {10,20,30,40,50};

    for_each(arr, arr+5, Functor1());//�ӽ� �Լ��� ��ü(Functor1())�� ����� �Լ��� ����
    cout << endl << endl;
    for_each(arr, arr+5, Functor2());//�ӽ� �Լ��� ��ü(Functor2())�� ����� �Լ��� ����
    cout << endl << endl;
    for_each(arr, arr+5, Functor3());//�ӽ� �Լ��� ��ü(Functor3())�� ����� �Լ��� ����
}