// ���� ���� 1�� ������Ŵ
// find_if
#include <iostream>
#include <string>
#include <algorithm>					// Exer
using std::find_if;
using std::cout; using std::endl; using std::ostream;
using std::string; using std::to_string;
using std::logic_error;

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
	os << "50�� " << m.get_c50() << "��, " << "100�� " << m.get_c100() << "��, "
	<< "500�� " << m.get_c500() << "��, " << "�� " << m.get_value() << "��" << endl;
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

template <typename T>
class Array
{
public:
	Array(int s) : size(s), serial_number(++counter) {
		if (size < 0)
			throw ArrayException("�迭 ũ��� 0 �̻�: " + to_string(size));
		ptr = new T[size];			// ���� ���� 1
		cout << "�迭 " << serial_number << " ����" << endl;
	}
	~Array() {
		delete[] ptr;
		cout << "�迭 " << serial_number << " �Ҹ�" << endl;
	}
	int get_size() const { return size; }
	T& operator[](int index) {
		if (index < 0 || index > size - 1) {
			throw ArrayException("ũ�⸦ ���: "+ to_string(index));
		}
		return ptr[index];
	}
	Array(const Array& source) = delete;
	Array& operator=(const Array& source) = delete;
	T* begin() { return &ptr[0]; }
	T* end() { return &ptr[size]; }
private:
	int size; T* ptr;
	int serial_number; static int counter;
};
template <typename T>
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
		int moneyValue = 5000;
		// Exer
		auto it = find_if(coinContainer.begin(), coinContainer.end(),
			[value = moneyValue](const CoinMoney& m) {
			return (value < m.get_value() ? true : false);
		});
		cout << moneyValue << "���� ū ù ��° �����ٹ��� " << endl;
		cout << *it << endl;
	}
	catch (const ArrayException& e) {
		cout << e.what() << endl;
	}

	cout << "Done!" << endl;
	return 0;
}