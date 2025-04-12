// 이번 레시피의 모든 코드는 이 헤더 파일에 있다
#include "tasks_processor_signals.hpp"
using namespace tp_full;

// tasks_processor_base.hpp의 tasks_processor 클래스의 일부 
// 소스 파일의 어딘가에 정의되어야만 한다
tasks_processor& tasks_processor::get() {
    static tasks_processor proc;
    return proc;
}


void accept_3_signals_and_stop(int signal) {
    static int signals_count = 0;
    assert(signal == SIGINT);
    ++ signals_count;
    std::cout << "Captured " << signals_count << " SIGINT\n"; 
    if (signals_count == 3) {
        tasks_processor::get().stop();
    }
}


int main () {
    tasks_processor::get().register_signals_handler(
        &accept_3_signals_and_stop,
        std::vector<int>(1, SIGINT) // 단 한 개의 요소만 갖는 벡터
    );

    tasks_processor::get().start();
}
