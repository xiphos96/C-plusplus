#include <iostream>
#include <functional>
using namespace std;

template<typename T>
struct Less: public binary_function<T,T,bool> //����� ������ �����ϵ���.
{
    bool operator( )(const T& left, const T& right) const
    {
        return left < right;
    }
};
void main( )
{
    Less<int> oLess;
    cout << oLess(10, 20) << endl;
    cout << oLess.operator()(10,20) << endl;

    cout << Less<int>()(10, 20) << endl;
    cout << Less<int>().operator()(10, 20) << endl;
}