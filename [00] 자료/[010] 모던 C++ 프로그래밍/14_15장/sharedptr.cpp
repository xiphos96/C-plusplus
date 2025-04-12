#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> s(new int);         // 참조 카운트 1
    
    *s = 10;
    cout << "참조 카운트 1" << endl;
    cout << *s << endl;

    shared_ptr<int> t = s;              // 참조 카운트 2
    *t += 1;                            // 11로 증가

    cout << "참조 카운트 2" << endl;
    cout << *s << endl;                 // 증가된 값인 11 출력
    cout << *t << endl;

    shared_ptr<int> u = t;              // 참조 카운트 3

    cout << "참조 카운트 3" << endl;
    *u += 1;

    cout << *s << endl;                 // 증가된 값인 12 출력
    cout << *t << endl;
    cout << *u << endl;

    return 0;
}