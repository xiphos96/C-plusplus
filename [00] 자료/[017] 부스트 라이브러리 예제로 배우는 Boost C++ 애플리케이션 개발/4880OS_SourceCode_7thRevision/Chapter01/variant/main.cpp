#include <boost/variant.hpp>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    typedef boost::variant<int, const char*, std::string> my_var_t;
    std::vector<my_var_t> some_values;
    some_values.push_back(10);
    some_values.push_back("Hello there!");
    some_values.push_back(std::string("Wow!"));

    std::string& s = boost::get<std::string>(some_values.back());
    s += " That is great!\n";
    std::cout << s;
    return 0;
}



void example_func() {
    typedef boost::variant<boost::blank, int, const char*, std::string> my_var_t;

    // �⺻ �����ڴ� boost::blank �ν��Ͻ��� �����
    my_var_t var;

    // 'which()' �޼ҵ�� variant�� ������ ���������� �ε����� ��ȯ�Ѵ�
    assert(var.which() == 0); // �� ����

    var = "Hello, dear reader";
    assert(var.which() != 0);
}

void example_func1() {
    boost::variant<int, std::string> variable(0);

	// ������ ���� ���� ������ �ƴ϶��
	// �Ʒ� �޼ҵ尡 boost::bad_get ���ܸ� ���� ���� �ִ� 
    int s1 = boost::get<int>(variable);

	// ������ ���� ���� std::string�� �ƴ϶��	
	// NULL ������ ��ȯ
    int* s2 = boost::get<int>(&variable);


    (void)s1; // ������� ���� ������ ���� ��� �޽��� ����
    (void)s2; // ������� ���� ������ ���� ��� �޽��� ����
}
