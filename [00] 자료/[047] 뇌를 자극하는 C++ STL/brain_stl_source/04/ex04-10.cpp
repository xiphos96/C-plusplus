#include <iostream>
using namespace std;

class Array
{
    int *buf; 
    int size; // ������ ����
    int capacity; // ���� ������ �޸� ũ��
public:
    explicit Array(int cap = 100):buf(0), size(0), capacity(cap) 
    {
        buf = new int[capacity];
    }
    ~Array( ) { delete [] buf; }
    void Add( int data)
    {
        buf[size++] = data;
    }
    int operator[](int idx) const
    {
        return buf[idx];
    }
    int GetSize() const
    {
        return size;
    }
    // ������ �������̽� ����...
};

void main( )
{
    Array arr;

    arr.Add( 10 );
    arr.Add( 20 );
    arr.Add( 30 );

    for( int i = 0 ; i < arr.GetSize() ; ++i)
        cout << arr[i] << endl;
}