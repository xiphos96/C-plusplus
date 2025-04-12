// ���� ���� 1�� ������Ŵ
// default ctor, delete zap function
// add printem(call by const reference)
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
	// Exer: default ctor
	Array()
		: size(0), ptr(nullptr), serial_number(++counter)
	{
		cout << "�迭 " << serial_number << " default ����" << endl;
	}

	Array(int s)
		: size(s), serial_number(++counter)
	{
		if (size < 0)
			throw ArrayException("�迭 ũ��� 0 �̻�: " + to_string(size));
		ptr = new int[size];
		cout << "�迭 " << serial_number << " ����" << endl;
	}

	~Array()
	{
		delete[] ptr;
		cout << "�迭 " << serial_number << " �Ҹ�" << endl;
	}
	// Exer
	int getSerial_number() const
	{
		return serial_number;
	}

	int get_size() const
	{ return size; }

	int& operator[](int index)
	{
		if (index < 0 || index > size - 1) {
			throw ArrayException("ũ�⸦ ���: "+ to_string(index));
		}
		return ptr[index];
	}
	// Exer: operator[] - const version
	const int& operator[](int index) const
	{
		if (index < 0 || index > size - 1) {
			// throw a bad-subscript exception
			throw ArrayException("ũ�⸦ ���: " + to_string(index));
		}
		return ptr[index];
	}
	Array(const Array& source) = delete;
	Array& operator=(const Array& source) = delete;
	// data fields
private:
	int size;
	int* ptr;
	int serial_number;
	static int counter;
};

int Array::counter = 0;
// Exer: const reference - copy ctor not called
void printem(const Array& a)
{
	for (int i = 0; i < a.get_size(); i++)
		cout << '[' << i << "]: " << a[i] << endl;;
}

int main()
{
	try {
		// default array
		Array a;
		cout << "�迭 " << a.getSerial_number() << " ����:" << endl;
		// call by const reference
		printem(a);
		Array b(5);
		for (int i = 0; i < b.get_size(); i++)
			b[i] = i;
		cout << "�迭 " << b.getSerial_number() << " ����:" << endl;
		printem(b);
	}
	catch (const ArrayException& e) {
		cout << e.what() << endl;
	}

	cout << "Done!" << endl;
	return 0;
}