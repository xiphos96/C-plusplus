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

    // 기본 생성자는 boost::blank 인스턴스를 만든다
    my_var_t var;

    // 'which()' 메소드는 variant가 소유한 데이터형의 인덱스를 반환한다
    assert(var.which() == 0); // 빈 상태

    var = "Hello, dear reader";
    assert(var.which() != 0);
}

void example_func1() {
    boost::variant<int, std::string> variable(0);

	// 변수의 실제 값이 정수가 아니라면
	// 아래 메소드가 boost::bad_get 예외를 던질 수도 있다 
    int s1 = boost::get<int>(variable);

	// 변수의 실제 값이 std::string이 아니라면	
	// NULL 포인터 반환
    int* s2 = boost::get<int>(&variable);


    (void)s1; // 사용하지 않은 변수에 대한 경고 메시지 억제
    (void)s2; // 사용하지 않은 변수에 대한 경고 메시지 억제
}
