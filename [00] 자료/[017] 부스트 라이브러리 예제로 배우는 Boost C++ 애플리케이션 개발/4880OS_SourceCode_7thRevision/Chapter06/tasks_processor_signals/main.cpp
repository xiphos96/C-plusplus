// �̹� �������� ��� �ڵ�� �� ��� ���Ͽ� �ִ�
#include "tasks_processor_signals.hpp"
using namespace tp_full;

// tasks_processor_base.hpp�� tasks_processor Ŭ������ �Ϻ� 
// �ҽ� ������ ��򰡿� ���ǵǾ�߸� �Ѵ�
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
        std::vector<int>(1, SIGINT) // �� �� ���� ��Ҹ� ���� ����
    );

    tasks_processor::get().start();
}
