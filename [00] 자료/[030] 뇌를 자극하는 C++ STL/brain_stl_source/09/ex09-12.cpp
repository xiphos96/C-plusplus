#include <iostream>
#include <functional>
using namespace std;

template<typename T>
struct Logical_and: public binary_function<T,T,bool> //����� ������ �����ϵ���.
{
    bool operator( )(const T& left, const T& right) const
    {
        return left && right;
    }
};
void main( )
{
    int n = 30;
    logical_and<bool> oAnd;
    //1. oAnd ��ü�� 10 < n < 50 �ΰ�? true. �Ϲ��� ȣ��
    cout << oAnd( greater<int>()(n, 10), less<int>()(n, 50) ) << endl;
    //2. oAnd ��ü�� 10 < n < 50 �ΰ�? true.  ����� ȣ��
    cout << oAnd.operator()( greater<int>()(n, 10), less<int>()(n, 50) ) << endl;

    //3. �ӽ� ��ü�� 10 < n < 50 �ΰ�? true. �Ϲ��� ȣ��(�Ϲ����� ���)
    cout << logical_and<bool>()( greater<int>()(n, 10), less<int>()(n, 50) ) << endl;
    //4. �ӽ� ��ü�� 10 < n < 50 �ΰ�? true. ����� ȣ��
    cout << logical_and<bool>().operator()( greater<int>()(n, 10), less<int>()(n, 50) ) << endl;
}