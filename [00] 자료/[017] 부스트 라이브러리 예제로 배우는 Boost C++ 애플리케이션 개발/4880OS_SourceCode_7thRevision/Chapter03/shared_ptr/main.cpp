class foo_class {
public:
    char data[10000000];

    explicit foo_class(const char* /*param*/){}
};

foo_class* get_data() {
    static int i = 0;
    ++ i;
    if (i % 2) {
        return new foo_class("Just some string");
    } else {
        return 0;
    }
}


#include <boost/thread.hpp>
#include <boost/bind.hpp>

void process1(const foo_class* p);
void process2(const foo_class* p);
void process3(const foo_class* p);

void foo1() {
    while (foo_class* p = get_data()) // C way
    {
        // 스레드가 너무 많다면, 
        // 스레드가 제어할 수 없을 정도로 생겨나는 걸 막기 위해
        // '동시에 여러가지 작업 실행하기' 레시피를 읽어보자

        boost::thread(boost::bind(&process1, p))
                .detach();
        boost::thread(boost::bind(&process2, p))
                .detach();
        boost::thread(boost::bind(&process3, p))
                .detach();
        // delete p; 이런!!!
    }
}


#include <boost/shared_ptr.hpp>

void process_sp1(const boost::shared_ptr<foo_class>& p);
void process_sp2(const boost::shared_ptr<foo_class>& p);
void process_sp3(const boost::shared_ptr<foo_class>& p);

void foo2() {
    typedef boost::shared_ptr<foo_class> ptr_t;
    ptr_t p;
    while (p = ptr_t(get_data())) // C way
    {
        boost::thread(boost::bind(&process_sp1, p))
                .detach();
        boost::thread(boost::bind(&process_sp2, p))
                .detach();
        boost::thread(boost::bind(&process_sp3, p))
                .detach();
        // 아무 일도 안해도 된다
    }
}

#include <string>
#include <boost/smart_ptr/make_shared.hpp>

void process_str1(boost::shared_ptr<std::string> p);
void process_str2(const boost::shared_ptr<std::string>& p);

void foo3() {
    boost::shared_ptr<std::string> ps = boost::make_shared<std::string>(
        "Guess why make_shared<std::string> "
        "is faster than shared_ptr<std::string> "
        "ps(new std::string('this string'))"
    );

    boost::thread(boost::bind(&process_str1, ps))
            .detach();
    boost::thread(boost::bind(&process_str2, ps))
            .detach();
}

#include <boost/chrono/duration.hpp>
int main() {
    // foo1(); // 메모리 누수가 일어난다
    foo2();
    foo3();

    // 모든 스레드에게 끝낼 기회가 부여된다
    // 주의: 정말 끔직한 디자인이지만, 예제니까 써본 것이다
    boost::this_thread::sleep_for(boost::chrono::seconds(2));
    return 0;
}

#include <assert.h>


void process1(const foo_class* p) {
    assert(p);
}

void process2(const foo_class* p) {
    assert(p);
}

void process3(const foo_class* p) {
    assert(p);
}

void process_str1(boost::shared_ptr<std::string> p) {
    assert(p);
}

void process_str2(const boost::shared_ptr<std::string>& p) {
    assert(p);
}
void process_sp1(const boost::shared_ptr<foo_class>& p) {
    assert(!!p);
}

void process_sp2(const boost::shared_ptr<foo_class>& p) {
    assert(!!p);
}

void process_sp3(const boost::shared_ptr<foo_class>& p) {
    assert(!!p);
}

