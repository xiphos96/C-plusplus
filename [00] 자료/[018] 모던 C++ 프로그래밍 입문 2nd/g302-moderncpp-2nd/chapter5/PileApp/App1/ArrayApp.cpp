//=========================================================
// ���� ���� 1
// Array class
//=========================================================
#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::string; using std::to_string;
using std::exception; using std::logic_error;

class ArrayException : public logic_error
{
public:
	ArrayException(const string& msg)
		: logic_error(msg), message(msg)
	{}

	virtual const char* what() const noexcept
	{
		return message.c_str();
	}
	// data field
protected:
	string message;
};

class Array
{
public:
	Array(int s)
		: size(s), serial_number(++counter)
	{
		if (size < 0)
			// throw a bad-size exception
			throw ArrayException("�迭 ũ��� 0 �̻�: " + to_string(size));
		ptr = new int[size];
		cout << "�迭 " << serial_number << " ����" << endl;
	}

	~Array()
	{
		delete[] ptr;
		cout << "�迭 " << serial_number << " �Ҹ�" << endl;
	}

	int get_size() const
	{ return size; }
	// overload the subscripting operator
	int& operator[](int index)
	{
		if (index < 0 || index > size - 1) {
			// throw a bad-subscript exception
			throw ArrayException("ũ�⸦ ���: "+ to_string(index));
		}
		return ptr[index];
	}
	// forbid copy ctor and assignment
	// no default move ctor and assignment provided because of above dtor
	Array(const Array& source) = delete;
	Array& operator=(const Array& source) = delete;
	// data fields
private:
	int size;
	int* ptr;
	int serial_number;
	static int counter;
};
// initialize static member variable
int Array::counter = 0;
// declaration of zap function
void zap();

int main()
{
	try {
		cout << "�迭 ũ�� �Է�: ";
		int n;
		cin >> n;
		Array my_ints(n);
		cout << n << "���� ���Ұ� �Է�" << endl;
		for (int i = 0; i < my_ints.get_size(); i++) {
			cout << i << ": ";
			int x;
			cin >> x;
			// use subscript operator on left hand side of assignment
			// can use cin >> my_ints[i];
			my_ints[i] = x;;
		}
		for (int i = 0; i < 3; i++) {
			cout << "�迭 ���� �� �� Ȯ��, 0���� " << n - 1 << "����: ";
			int index;
			cin >> index;
			// use subscript operator on right hand side of assignment
			int result = my_ints[index];
			cout << index << "��° ���� " << result << endl;
		}
		zap();
	}
	catch (const ArrayException& e) {
		cout << e.what() << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << "Done!" << endl;
	return 0;
}

void zap()
{
	cout << "zap ����" << endl;
	Array a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i * 5;
	for (int i = 0; i < 5; i++)
		cout << a[i] << ' ';
	cout << endl;
	cout << "zap���� ����" << endl;
	return;
}