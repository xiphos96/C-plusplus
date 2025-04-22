#include <iostream>
using namespace std;

struct LessFunctor // 1. �Լ� ��ü ������
{
    bool operator()(int left, int right) const
    {
        return left < right;
    }
};
bool LessFun(int left, int right) // 2. �Լ� ������
{
    return left < right;
}
void main( )
{
    bool (*LessPtr)(int, int) = LessFun; // 3. �Լ� ������ ������
    LessFunctor lessFunctor;
    
    //��� bool ������ ��ȯ
    //1. �Լ� ��ü�� 10�� 20�� ��
    cout << lessFunctor(10, 20) << endl;

    //2. �Լ��� 10�� 20�� ��
    cout << LessFun(10, 20) << endl;

    //3. �Լ� �����ͷ� 10�� 20�� ��
    cout << LessPtr(10, 20) << endl;
}
