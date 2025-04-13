#include <iostream>
#include <deque>
using namespace std;

void main() 
{
    deque<int> dq;

    dq.push_back( 10 );
    dq.push_back( 20 );
    dq.push_back( 30 );
    dq.push_back( 40 );
    dq.push_back( 50 );

    deque<int>::iterator iter;
    for(iter = dq.begin(); iter != dq.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;

    iter = dq.begin()+2; //�ݺ��ڿ� +2�մϴ�.
    cout << *iter << endl;

    iter += 2; //�ݺ��ڿ� +2�մϴ�.
    cout << *iter << endl;

    iter -= 3; //�ݺ��ڿ� -3�մϴ�.
    cout << *iter << endl;
}
