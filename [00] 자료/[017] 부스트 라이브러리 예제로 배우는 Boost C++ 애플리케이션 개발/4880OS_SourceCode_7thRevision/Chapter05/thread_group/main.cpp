#include <cassert>
#include <boost/atomic.hpp>
boost::atomic_int g_counter(0);
void some_function(){ ++ g_counter; }

#include <boost/thread.hpp>
int main() {
    boost::thread t1(&some_function);
    boost::thread t2(&some_function);
    boost::thread t3(&some_function);
    // ...

    t1.join();
    t2.join();
    t3.join();

    assert(g_counter == 3);

    // ������ 10���� ���۽�Ų��
    boost::thread_group threads;
    for (unsigned i = 0; i < 10; ++i) {
        threads.create_thread(&some_function);
    }

    // ��� �����带 �����Ѵ�
    threads.join_all();

    // threads.interrupt_all();�� ȣ����
    // ��� �����忡 ���ͷ�Ʈ�� �Ǵ�

    assert(g_counter == 13);
}
