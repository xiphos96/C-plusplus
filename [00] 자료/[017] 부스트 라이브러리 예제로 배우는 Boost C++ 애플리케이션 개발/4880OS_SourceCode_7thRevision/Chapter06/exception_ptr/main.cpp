#include "../tasks_processor_base/tasks_processor_base.hpp"
using namespace tp_base;

// tasks_processor_base.hpp의 tasks_processor 클래스
// 소스 파일의 어딘가에 정의되어야만 한다
tasks_processor& tasks_processor::get() {
    static tasks_processor proc;
    return proc;
}

#include <boost/exception_ptr.hpp>
#include <boost/lexical_cast.hpp>
void func_test2(); // 전방 선언

void process_exception(const boost::exception_ptr& exc) {
    try {
        boost::rethrow_exception(exc);
    } catch (const boost::bad_lexical_cast& /*e*/) {
        std::cout << "Lexical cast exception detected\n" << std::endl;

        // 실행할 다른 작업을 밀어넣는다
        tasks_processor::get().push_task(&func_test2);
    } catch (...) {
        std::cout << "Can not handle such exceptions:\n" 
            << boost::current_exception_diagnostic_information() 
            << std::endl;

        // 중단
        tasks_processor::get().stop();
    }
}

void func_test1() {
    try {
        boost::lexical_cast<int>("oops!");
    } catch (...) {
        tasks_processor::get().push_task(boost::bind(
            &process_exception, boost::current_exception()
        ));
    }
}

#include <stdexcept>
void func_test2() {
    try {
        // 몇몇 코드를 여기 둔다
        BOOST_THROW_EXCEPTION(std::logic_error("Some fatal logic error"));
        // 몇몇 코드를 여기 둔다
    } catch (...) {
        tasks_processor::get().push_task(boost::bind(
            &process_exception, boost::current_exception()
        ));
    }
}

void run_throw(boost::exception_ptr& ptr) {
    try {
        // 상당히 많은 코드를 여기 둔다
    } catch (...) {
        ptr = boost::current_exception();
    }
}

int main () {
    tasks_processor::get().push_task(&func_test1);
    tasks_processor::get().start();


    boost::exception_ptr ptr;
    // 몇 가지 일을 동시에 실행한다
    boost::thread t(boost::bind(
        &run_throw, 
        boost::ref(ptr)
    ));

    // 몇몇 코드를 여기 둔다
    // ...
    
    t.join();

    // 예외 검사
    if (ptr) {
        // 스레드에서 예외 발생
        boost::rethrow_exception(ptr);
    }
}
