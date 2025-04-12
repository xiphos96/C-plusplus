//=========================================================
// 응용 과제 1
// 3장 응용 과제 1의 CoinMoney 클래스와
// 5장 응용 과제 1의 Array 클래스 활용
// Array template class with CoinMoney class
//=========================================================
#include <iostream>
#include <string>
#include <numeric>					// 응용 과제 1
using std::cout; using std::endl; using std::ostream;
using std::string; using std::to_string;
using std::logic_error; using std::accumulate;

class CoinMoney
{
public:
	CoinMoney() : c50(0), c100(0), c500(0) {}
	CoinMoney(int c, int cc, int ccc) : c50(c), c100(cc), c500(ccc) {}
	virtual ~CoinMoney() {}
	int get_value() const { return (50 * c50 + 100 * c100 + 500 * c500); }
	int get_c50() const { return c50; }
	int get_c100() const { return c100; }
	int get_c500() const { return c500; }
	void set_c50(int c) { c50 = c; }
	void set_c100(int cc) { c100 = cc; }
	void set_c500(int ccc) { c500 = ccc; }
protected:
	int c50; int c100; int c500;
};
ostream& operator<<(ostream& os, const CoinMoney& m)
{
	os << "50원 " << m.get_c50() << "개, " << "100원 " << m.get_c100() << "개, "
		<< "500원 " << m.get_c500() << "개, " << "총 "
		<< m.get_value() << "원" << endl;
	return os;
}

class ArrayException : public logic_error
{
public:
	ArrayException(const string& msg) : logic_error(msg), message(msg) {}
	virtual const char* what() const noexcept { return message.c_str(); }
protected:
	string message;
};

template <typename T>				// 응용 과제 1
class Array
{
public:
	Array(int s) : size(s), serial_number(++counter) {
		if (size < 0)
			throw ArrayException("배열 크기는 0 이상: " + to_string(size));
		ptr = new T[size];			// 응용 과제 1
		cout << "배열 " << serial_number << " 생성" << endl;
	}
	~Array() {
		delete[] ptr;
		cout << "배열 " << serial_number << " 소멸" << endl;
	}
	int get_size() const { return size; }
	T& operator[](int index) {		// 응용 과제 1
		if (index < 0 || index > size - 1) {
			throw ArrayException("크기를 벗어남: "+ to_string(index));
		}
		return ptr[index];
	}
	Array(const Array& source) = delete;
	Array& operator=(const Array& source) = delete;
	T* begin() { return &ptr[0]; }	// 응용 과제 1
	T* end() { return &ptr[size]; }
private:
	int size; T* ptr;				// 응용 과제 1
	int serial_number; static int counter;
};
template <typename T>				// 응용 과제 1
int Array<T>::counter = 0;

int main()
{
	try {
		Array<CoinMoney> coinContainer(10);
		for (int i = 0; i < coinContainer.get_size(); ++i) {
			CoinMoney m(i, i + 1, i + 2);
			coinContainer[i] = m;
		}
		for (const CoinMoney& cm : coinContainer)
			cout << cm;
		int sum = accumulate(coinContainer.begin(), coinContainer.end(),
			0, [](int s, const CoinMoney& m) {
			return (s + m.get_value());
		});
		cout << "총 " << sum << "원" << endl;
	}
	catch (const ArrayException& e) {
		cout << e.what() << endl;
	}
	cout << "Done!" << endl;

	return 0;
}