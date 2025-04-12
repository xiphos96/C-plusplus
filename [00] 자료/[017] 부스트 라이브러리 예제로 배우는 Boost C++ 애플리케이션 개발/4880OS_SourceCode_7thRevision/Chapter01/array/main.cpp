// char* vector_advance(char* val);

// char ( &vector_advance( char (&val)[4] ) )[4];


#include <boost/array.hpp>
#include <algorithm>

// ���� 1 ������Ű�� �Լ� ��ü
struct add_1 : public std::unary_function<char, void> {
    void operator()(char& c) const {
        ++ c;
    }

    // �Լ� ��ü�� ���� ����� �ƴ����� 
    // 'boost::bind(std::plus<char>(), _1, 1)'�� �� �ϴ� ���� �𸥴ٸ�
	// '�Լ� �Ķ���Ϳ� �� ����' �����Ǹ� �о��
};

typedef boost::array<char, 4> array4_t;
array4_t& vector_advance(array4_t& val) {
    // boost::array���� begin(), cbegin(), end(), cend(), rbegin(),
    // size(), empty()�� �ٸ� STL �����̳��� �����ϴ� ���� �Լ��� �����Ѵ�	
    std::for_each(val.begin(), val.end(), add_1());
    return val;
}

int main() {
    // boost::array�� C++11�� �ٸ� �迭ó�� �ʱ�ȭ�� �� �ִ�
    // array4_t val = {0, 1, 2, 3};
    // ������ C++03������ {}�� �ѹ� �� �ٿ���� �Ѵ�
    array4_t val = {{0, 1, 2, 3}};

    // boost::array�� �Ϲ� �迭ó�� �����Ѵ�
    array4_t val_res;               // ���� ���� ���������� �⺻ ������ �Ҵ��� �����Ѵٸ� 
    val_res = vector_advance(val);  // �⺻ ���� �� �⺻ �Ҵ�� �� �ִ�    

    assert(val.size() == 4);
    assert(val[0] == 1);
    /*val[4];*/ // �ε����� �ִ밪�� 3�̹Ƿ� ������ ��߳��� 

    // ������ �ð��� ���� �˻縦 �غ���.
    // ��� �ϴ� ���� �ñ��ϴٸ�
	// '�������� �� ũ�� �˻��ϱ�' �����Ǹ� �о��
    assert(sizeof(val) == sizeof(char) * array4_t::static_size);
    return 0;
}
