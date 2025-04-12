// 연습 문제 4를 발전시킴
// copy semantics
#include <iostream>
#include <string>
#include <chrono>			// Exer
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
		cout << "배열 " << serial_number << " default 생성" << endl;
	}

	Array(int s)
		: size(s), serial_number(++counter)
	{
		if (size < 0)
			throw ArrayException("배열 크기는 0 이상: " + to_string(size));
		ptr = new int[size];
		cout << "배열 " << serial_number << " 생성" << endl;
	}

	Array(const Array& original)
		: size(original.size), ptr(new int[size]), serial_number(++counter)
	{
		for (int i = 0; i < size; i++)
			ptr[i] = original.ptr[i];
		cout << "배열 " << serial_number << " copy 생성" << endl;
	}

	~Array()
	{
		delete[] ptr;
		cout << "배열 " << serial_number << " 소멸" << endl;
	}

	Array& operator=(const Array& original)
	{
		if (this == &original)
			return *this;
		delete[] ptr;
		size = original.size; ptr = new int[size];
		for (int i = 0; i < size; i++)
			ptr[i] = original.ptr[i];
		cout << "배열 " << serial_number << "에 배열 "
			<< original.serial_number << " copy 배정" << endl;
	}

	int getSerial_number() const
	{ return serial_number; }

	int get_size() const
	{ return size; }

	int& operator[](int index)
	{
		if (index < 0 || index > size - 1) {
			throw ArrayException("크기를 벗어남: "+ to_string(index));
		}
		return ptr[index];
	}

	const int& operator[](int index) const
	{
		if (index < 0 || index > size - 1) {
			throw ArrayException("크기를 벗어남: " + to_string(index));
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
		const int BIG_SIZE = 10000000;
		Array a1(BIG_SIZE);
		Array a2(BIG_SIZE);
		for (int i = 0; i < BIG_SIZE; ++i)
			a1[i] = i;
		// Exer: copy semantics
		auto ct1 = high_resolution_clock::now();
		a2 = squarem(a1);
		auto ct2 = high_resolution_clock::now();
		auto delta = duration_cast<milliseconds>(ct2 - ct1).count();
		cout << "소요 시간 " << delta << " msec" << endl;
	}
	catch (const ArrayException& e) {
		cout << e.what() << endl;
	}

	cout << "Done!" << endl;
	return 0;
}