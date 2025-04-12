// ���� ���� 6�� ������Ŵ
// operator+ overloading
#include <iostream>
#include <string>
#include <chrono>
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
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

	Array(const Array& original)
		: size(original.size), ptr(new int[size]), serial_number(++counter)
	{
		for (int i = 0; i < size; i++)
			ptr[i] = original.ptr[i];
		cout << "�迭 " << serial_number << " copy ����" << endl;
	}

	Array(Array&& original)
		: size(original.size), ptr(original.ptr), serial_number(++counter)
	{
		original.size = 0;
		original.ptr = nullptr;
		cout << "�迭 " << serial_number << " move ����" << endl;
	}

	Array& operator=(Array&& original)
	{
		if (this == &original)
			return *this;
		delete[] ptr;
		size = original.size; ptr = new int[size];
		ptr = original.ptr;
		original.ptr = nullptr;
		cout << "�迭 " << serial_number << "�� �迭 "
			<< original.serial_number << " move ����" << endl;
	}

	~Array()
	{
		delete[] ptr;
		cout << "�迭 " << serial_number << " �Ҹ�" << endl;
	}

	// Exer: overloaded operator+
	// arrays must have the same size
	Array operator+(const Array& rhs)
	{
		if (size != rhs.get_size())
			throw ArrayException("�����װ� �������� ���� ũ�Ⱑ �ƴ�!");
		Array result(size);
		for (int i = 0; i < size; i++)
			result[i] = ptr[i] + rhs[i];
		return result;
	}

	Array& operator=(const Array& original)
	{
		if (this == &original)
			return *this;
		delete[] ptr;
		size = original.size; ptr = new int[size];
		for (int i = 0; i < size; i++)
			ptr[i] = original.ptr[i];
		cout << "�迭 " << serial_number << "�� �迭 "
			<< original.serial_number << " copy ����" << endl;
	}

	int getSerial_number() const
	{ return serial_number; }

	int get_size() const
	{ return size; }

	int& operator[](int index)
	{
		if (index < 0 || index > size - 1) {
			throw ArrayException("ũ�⸦ ���: "+ to_string(index));
		}
		return ptr[index];
	}

	const int& operator[](int index) const
	{
		if (index < 0 || index > size - 1) {
			throw ArrayException("ũ�⸦ ���: " + to_string(index));
		}
		return ptr[index];
	}
//	Array(const Array& source) = delete;
//	Array& operator=(const Array& source) = delete;
	// data fields
private:
	int size;
	int* ptr;
	int serial_number;
	static int counter;
};

int Array::counter = 0;

void printem(const Array& a)
{
	for (int i = 0; i < a.get_size(); i++)
		cout << '[' << i << "]: " << a[i] << endl;;
}

double averagem(Array a)
{
	double sum = 0;
	for (int i = 0; i < a.get_size(); ++i) {
		sum += a[i];
	}
	return sum / a.get_size();
}

Array squarem(const Array& a)
{
	Array b(a.get_size());
	for (int i = 0; i < a.get_size(); i++)
		b[i] = a[i] * a[i];
	return b;
}

int main()
{
	try {
		cout << "a �迭 �ʱ�ȭ" << endl;
		Array a(5);
		for (int i = 0; i < 5; i++)
			a[i] = i;
		printem(a);
		cout << "a �迭�� �ʱ�ȭ�� b �迭" << endl;
		Array b(a);
		printem(b);
		// Exer
		cout << "rvalue ǥ����(a + b)�� �ʱ�ȭ�� c �迭" << endl;
		Array c(a + b);
		printem(c);
		cout << "default ���� �� rvalue ǥ����(a + b)���� �ʱ�ȭ�� d �迭" << endl;
		Array d;
		d = a + b;
		printem(d);
	}
	catch (const ArrayException& e) {
		cout << e.what() << endl;
	}

	cout << "Done!" << endl;
	return 0;
}