#include <iostream>
using namespace std;
void Client();

//////// ���� /////////////
void PrintHello( )
{
    cout << "Hello!" << endl;
    Client(); //�������� Ŭ���̾�Ʈ �ڵ� ȣ��
}
/////// Ŭ���̾�Ʈ /////////
void Client( )
{
    cout << "�� client" << endl;
}
void main( )
{
    PrintHello( ); //���� �ڵ� ȣ��
}