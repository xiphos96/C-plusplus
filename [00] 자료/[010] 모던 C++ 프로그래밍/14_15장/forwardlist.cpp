#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> forwardListValue = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    cout << "forwardListValue ���" << endl;
    for (auto it = forwardListValue.begin(); it != forwardListValue.end(); ++it)
        cout << *it << endl;

    return 0;
}