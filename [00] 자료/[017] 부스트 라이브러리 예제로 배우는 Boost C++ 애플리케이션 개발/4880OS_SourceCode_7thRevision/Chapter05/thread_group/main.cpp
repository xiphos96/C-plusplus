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

    // 스레드 10개를 시작시킨다
    boost::thread_group threads;
    for (unsigned i = 0; i < 10; ++i) {
        threads.create_thread(&some_function);
    }

    // 모든 스레드를 조인한다
    threads.join_all();

    // threads.interrupt_all();를 호출해
    // 모든 스레드에 인터럽트를 건다

    assert(g_counter == 13);
}
