
// 이번 레시피의 모든 코드는 이 헤더 파일에 있다
#include "tasks_processor_timers.hpp"
using namespace tp_timers;


// tasks_processor_base.hpp의 tasks_processor 클래스의 일부 
// 소스 파일의 어딘가에 정의되어야만 한다
tasks_processor& tasks_processor::get() {
    static tasks_processor proc;
    return proc;
}

void test_func(int& i) {
    i = 1;
    tasks_processor::get().stop();
}

void test_func1() {
    throw std::logic_error("It works!");
}

#include <boost/date_time/posix_time/posix_time.hpp>

int main () {
    const int seconds_to_wait = 3;
    int i = 0;

    tasks_processor::get().run_after(
        boost::posix_time::seconds(seconds_to_wait),
        boost::bind(&test_func, boost::ref(i))
    );
        
    tasks_processor::get().run_at(boost::posix_time::from_time_t(time(NULL) + 1), &test_func1);

    int t1 = static_cast<int>(time(NULL));
    assert(i == 0);

    tasks_processor::get().start();
    assert(i == 1);
    int t2 = static_cast<int>(time(NULL));
    assert(t2 - t1 >= seconds_to_wait); // seconds_to_wait 초만큼 지나야 함
}
