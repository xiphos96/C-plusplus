#include <iostream>
#include <string>
using namespace std;

template <typename T>
class ObjectInfo
{
    T data;
public:
    ObjectInfo(const T& d):data(d) { }
    void Print( )
    {
        cout <<"Ÿ�� : "<< typeid(data).name() << endl;
        cout <<"ũ�� : "<< sizeof(data) << endl;
        cout <<"�� : "<< data << endl;
        cout <<endl;
    }
};
template <> // T�� string���� Ư��ȭ(Ŭ���� ���ø� Ư��ȭ)
class ObjectInfo<string>
{
    string data;
public:
    ObjectInfo(const string& d):data(d) { }
    void Print( )
    {
        //cout <<"Ÿ�� : "<< typeid(data).name() << endl;
        cout <<"Ÿ�� : "<< "string" << endl; //Ÿ�� ���� ����
        //cout <<"ũ�� : "<< sizeof(data) << endl;
        cout <<"���ڿ� ���� : "<< data.size() << endl; //���� ���� ����
        cout <<"�� : "<< data << endl; 
        cout <<endl;
    }
};
void main( ) 
{
    ObjectInfo<int> d1(10);
    d1.Print( ); // ��ü ���� ���

    ObjectInfo<double> d2(5.5);
    d2.Print( ); // ��ü ���� ���

    ObjectInfo<string> d3("Hello!");
    d3.Print( ); // ��ü ���� ���
}
