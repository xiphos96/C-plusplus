#include <cassert>
#include <cstddef>

// 이전 레시피에서는 Boost.Thread의 모든 클래스를 포함하는 
// <boost/thread.hpp>를 불러들였었다
#include <boost/thread/thread.hpp>

namespace without_sync {

int shared_i = 0;

void do_inc() {
    for (std::size_t i = 0; i < 30000; ++i) {
        // 몇 가지 일을 한다
        // ...
        int i_snapshot = ++ shared_i;

        // i_snapshot로 몇 가지 일을 한다
        // ...
        (void) i_snapshot;
    }
}

void do_dec() {
    for (std::size_t i = 0; i < 30000; ++i) {
        // 몇 가지 일을 한다
        // ...
        int i_snapshot = -- shared_i;

        // i_snapshot로 몇 가지 일을 한다
        // ...
        (void) i_snapshot;
    }
}

void run() {
    boost::thread t1(&do_inc);
    boost::thread t2(&do_dec);

    t1.join();
    t2.join();

    // assert(global_i == 0); // 이런!
    std::cout << "shared_i == " << shared_i;
}

} // without_sync 네임스페이스

#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>

namespace with_sync {

int shared_i = 0;
boost::mutex i_mutex;

void do_inc() {
    for (std::size_t i = 0; i < 30000; ++i) {
        // 몇 가지 일을 한다
        // ...
        int i_snapshot;
        { // 임계 영역 시작
            boost::lock_guard<boost::mutex> lock(i_mutex);
            i_snapshot = ++ shared_i;
        } // 임계 영역 끝

        // i_snapshot로 몇 가지 일을 한다
        // ...
        (void)i_snapshot;
    }
}

void do_dec() {
    for (std::size_t i = 0; i < 30000; ++i) {
        // 몇 가지 일을 한다
        // ...
        int i_snapshot;
        { // 임계 영역 시작
            boost::lock_guard<boost::mutex> lock(i_mutex);
            i_snapshot = -- shared_i;
        } // 임계 영역 끝

        // i_snapshot로 몇 가지 일을 한다
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

} // without_sync 네임스페이스

#include <boost/thread/recursive_mutex.hpp>

int main() {
    without_sync::run();
    std::cout << '\n';
    with_sync::run();
    std::cout << '\n';
}
