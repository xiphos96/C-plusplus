#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point(int _x =0, int _y =0 ):x(_x),y(_y) { }
    void Print( ) const { cout << x <<',' << y << endl; }
    void operator++ ( ) // ���� ++
    {
    }
    void operator++(int ) // ���� ++
    {      
    }
};
void main( )
{
    Point p1(2,3), p2(2,3);

    ++p1; // p1.operator++(); �� �����ϴ�.

    p2++; // p2.operator++(0); �� �����ϴ�. 
}

