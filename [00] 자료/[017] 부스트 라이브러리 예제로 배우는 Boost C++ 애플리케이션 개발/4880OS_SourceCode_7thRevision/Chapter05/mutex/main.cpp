#include <cassert>
#include <cstddef>

// ���� �����ǿ����� Boost.Thread�� ��� Ŭ������ �����ϴ� 
// <boost/thread.hpp>�� �ҷ��鿴����
#include <boost/thread/thread.hpp>

namespace without_sync {

int shared_i = 0;

void do_inc() {
    for (std::size_t i = 0; i < 30000; ++i) {
        // �� ���� ���� �Ѵ�
        // ...
        int i_snapshot = ++ shared_i;

        // i_snapshot�� �� ���� ���� �Ѵ�
        // ...
        (void) i_snapshot;
    }
}

void do_dec() {
    for (std::size_t i = 0; i < 30000; ++i) {
        // �� ���� ���� �Ѵ�
        // ...
        int i_snapshot = -- shared_i;

        // i_snapshot�� �� ���� ���� �Ѵ�
        // ...
        (void) i_snapshot;
    }
}

void run() {
    boost::thread t1(&do_inc);
    boost::thread t2(&do_dec);

    t1.join();
    t2.join();

    // assert(global_i == 0); // �̷�!
    std::cout << "shared_i == " << shared_i;
}

} // without_sync ���ӽ����̽�

#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>

namespace with_sync {

int shared_i = 0;
boost::mutex i_mutex;

void do_inc() {
    for (std::size_t i = 0; i < 30000; ++i) {
        // �� ���� ���� �Ѵ�
        // ...
        int i_snapshot;
        { // �Ӱ� ���� ����
            boost::lock_guard<boost::mutex> lock(i_mutex);
            i_snapshot = ++ shared_i;
        } // �Ӱ� ���� ��

        // i_snapshot�� �� ���� ���� �Ѵ�
        // ...
        (void)i_snapshot;
    }
}

void do_dec() {
    for (std::size_t i = 0; i < 30000; ++i) {
        // �� ���� ���� �Ѵ�
        // ...
        int i_snapshot;
        { // �Ӱ� ���� ����
            boost::lock_guard<boost::mutex> lock(i_mutex);
            i_snapshot = -- shared_i;
        } // �Ӱ� ���� ��

        // i_snapshot�� �� ���� ���� �Ѵ�
        // ...
        (void) i_snapshot;
    }
}

void run() {
    boost::thread t1(&do_inc);
    boost::thread t2(&do_dec);

    t1.join();
    t2.join();

    assert(shared_i == 0);
    std::cout << "shared_i == " << shared_i;
}

} // without_sync ���ӽ����̽�

#include <boost/thread/recursive_mutex.hpp>

int main() {
    without_sync::run();
    std::cout << '\n';
    with_sync::run();
    std::cout << '\n';
}
