// Amost all the code for this example is in this header
#include "tasks_processor_base.hpp"
using namespace tp_base;

// tasks_processor_base.hpp�� tasks_processor Ŭ������ �Ϻ� 
// �ҽ� ������ ��򰡿� ���ǵǾ�߸� �Ѵ�
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
        // ������ ���ͷ�Ʈ �䳻����
        // ����� �ϰ����� ������ ������ �ʴ´�
        throw boost::thread_interrupted();
    }

    if (g_val == 90) {
        tasks_processor::get().stop();
    }
}

int main () {
    static const std::size_t tasks_count = 100;
    // 90��°�� stop() ȣ��
    BOOST_STATIC_ASSERT(tasks_count > 90);

    for (std::size_t i =0; i < tasks_count; ++i) {
        tasks_processor::get().push_task(&func_test);
    }

    // boost::bind ȣ���� ����� �۾����� �� �� �ִ�
    tasks_processor::get().push_task(
        boost::bind(std::plus<int>(), 2, 2) // 2 + 2 ����
    );

    // ó���� ���۵��� ����
    assert(g_val == 0);

    // ���ܸ� ������ ������
    // ������ �۾� �� �ϳ��� stop()�� ȣ���� ������ ����
    tasks_processor::get().start();
    assert(g_val == 90);
}
