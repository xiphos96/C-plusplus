#include <iostream>
#include <functional>
using namespace std;

template<typename T>
struct Plus: public binary_function<T,T,T> //����� ������ �����ϵ���.
{
    T operator( )(const T& left, const T& right) const
    {
        return left + right;
    }
};
void main( )
{
    Plus<int> oPlus;
    cout << oPlus(10, 20) << endl;
    cout << oPlus.operator()(10,20) << endl;

    cout << Plus<int>()(10, 20) << endl;
    cout << Plus<int>().operator()(10, 20) << endl;
}