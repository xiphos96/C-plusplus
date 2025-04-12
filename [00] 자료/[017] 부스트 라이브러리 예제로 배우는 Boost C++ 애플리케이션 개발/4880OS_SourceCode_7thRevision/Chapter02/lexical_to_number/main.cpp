#include <sstream>

void foo1() {
    std::istringstream iss("100");
    int i;
    iss >> i;
    // 이제 'iss' 변수는 영역이 끝날 때까지 입력을 받는다. 
    // 이 연산을 하는 동안 불필요한 연산이나 가상 함수, 메모리 할당이 얼마나 많이 일어날지는 생각하지 않는 게 낫다.
}

#include <cstdlib>
void foo2() {
    char * end;
    int i = std::strtol ("100", &end, 10);
    // 모든 값을 정수로 변환했을까, 아니면 중간에 멈췄을까?
    // 그리고 이제 'end' 변수가 도입됐다.
    // 한편으로 정수를 원했는데, strtol은 long int를 반환한다. 변환된 값이 정수에 들어맞을까?
    
    (void)i; // 사용하지 않은 변수에 대한 경고 메시지 억제
}

#include <boost/lexical_cast.hpp>

void foo3() {
    {
    int i = boost::lexical_cast<int>("100");
    (void)i; // 사용하지 않은 변수에 대한 경고 메시지 억제
    }

    char chars[] = {'1', '0', '0' };
    int i = boost::lexical_cast<int>(chars, 3);
    assert(i == 100);



    try {
        // 대부분의 x86 short는 32767보다 큰 수를 저장할 수 없다
        short s = boost::lexical_cast<short>("1000000");
        assert(false); // 여기로 오면 안 된다
        (void)s; // 사용하지 않은 변수에 대한 경고 메시지 억제
    } catch (const boost::bad_lexical_cast& /*e*/) {}


    try {
        int i = boost::lexical_cast<int>("This is not a number!");
        assert(false); // 여기로 오면 안 된다
        (void)i; // 사용하지 않은 변수에 대한 경고 메시지 억제
    } catch (const boost::bad_lexical_cast& /*e*/) {}
}

#include <locale>
void foo4() {
    std::locale::global(std::locale("ru_RU.UTF8"));
    // 러시아에서는 소수점으로 쉼표를 쓴다
    float f = boost::lexical_cast<float>("1,0");
    assert(f < 1.01 && f > 0.99);
    std::locale::global(std::locale::classic()); // C 로케일로 돌아감
}



#include <algorithm>
#include <vector>
#include <iterator>
#include <boost/lexical_cast.hpp>

template <class ContainerT>
std::vector<long int> container_to_longs(const ContainerT& container) {
    typedef typename ContainerT::value_type value_type;
    std::vector<long int> ret;
    typedef long int (*func_t)(const value_type&);
    func_t f = &boost::lexical_cast<long int, value_type>;
    std::transform(container.begin(), container.end(), std::back_inserter(ret), f);
    return ret;
}

#include <set>
#include <deque>
#include <string>
#include <boost/array.hpp>

void foo5() {
    // 소스 파일의 어딘가
    std::set<std::string> str_set;
    str_set.insert("1");
    assert(container_to_longs(str_set).front() == 1);

    std::deque<const char*> char_deque;		
    char_deque.push_front("1");
    char_deque.push_back("2");
    assert(container_to_longs(char_deque).front() == 1);
    assert(container_to_longs(char_deque).back() == 2);

    // {}를 써서 사람들을 당황하게 하면 재밌다!
    typedef boost::array<unsigned char, 2> element_t;
    boost::array<element_t, 2> arrays = {{ {{'1', '0'}}, {{'2', '0'}} }};
    assert(container_to_longs(arrays).front() == 10);
    assert(container_to_longs(arrays).back() == 20);
}


int main() {
    foo1();
    foo2();
    foo3();
    foo4();
    foo5();
    return 0;
}
