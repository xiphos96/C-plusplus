// Amost all the code for this example is in this header
#include "tasks_processor_base.hpp"
using namespace tp_base;

// tasks_processor_base.hpp의 tasks_processor 클래스의 일부 
// 소스 파일의 어딘가에 정의되어야만 한다
tasks_processor& tasks_processor::get() {
    static tasks_processor proc;
    return proc;
}


int g_val = 0;
void func_test() {
    ++ g_val;
    if (g_val == 3) {
        throw std::logic_error("Just checking");
    }
    
    boost::this_thread::interruption_point();
    if (g_val == 10) {
        // 스레드 인터럽트 흉내내기
        // 붙잡긴 하겠지만 실행을 멈추진 않는다
        throw boost::thread_interrupted();
    }

    if (g_val == 90) {
        tasks_processor::get().stop();
    }
}

int main () {
    static const std::size_t tasks_count = 100;
    // 90번째에 stop() 호출
    BOOST_STATIC_ASSERT(tasks_count > 90);

    for (std::size_t i =0; i < tasks_count; ++i) {
        tasks_processor::get().push_task(&func_test);
    }

    // boost::bind 호출의 결과도 작업으로 쓸 수 있다
    tasks_processor::get().push_task(
        boost::bind(std::plus<int>(), 2, 2) // 2 + 2 세기
    );

    // 처리가 시작되지 않음
    assert(g_val == 0);

    // 예외를 던지진 않지만
    // 보유한 작업 중 하나가 stop()을 호출할 때까지 멈춤
    tasks_processor::get().start();
    assert(g_val == 90);
}
