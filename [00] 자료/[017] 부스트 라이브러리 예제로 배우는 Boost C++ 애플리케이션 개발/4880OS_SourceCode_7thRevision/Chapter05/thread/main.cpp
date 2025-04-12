#include <algorithm>
#include <fstream>
#include <iterator>

void set_not_first_run();
bool is_first_run();

// 실행 시간이 긴 함수
void fill_file_with_data(char fill_char, std::size_t size, const char* filename) {
    std::ofstream ofs(filename);
    std::fill_n(std::ostreambuf_iterator<char>(ofs), size, fill_char);
    set_not_first_run();
}

void example_without_threads() {
    // ...
    // 사용자 인터페이스를 그리는 스레드의 어딘가
    if (is_first_run()) {
        // 사용자 인터페이스가 정지해있는 동안 
        // 이 부분이 오랫동안 실행된다
        fill_file_with_data(0, 8 * 1024 * 1024, "save_file.txt");
    }
}

#include <boost/thread.hpp>
void example_with_threads() {
    // ...
    // 사용자 인터페이스를 그리는 스레드의 어딘가
    if (is_first_run()) {
        boost::thread(boost::bind(
            &fill_file_with_data,
            0,
            8 * 1024 * 1024,
            "save_file.txt"
        )).detach();
    }
}

void example_with_joining_threads() {
    // ...
    // 사용자 인터페이스를 그리는 스레드의 어딘가
    if (is_first_run()) {
        boost::thread t(boost::bind(
            &fill_file_with_data,
            0,
            8 * 1024 * 1024,
            "save_file.txt"
        ));

        // 몇 가지 일을 한다
        // ...

        // 스레드가 끝나길 기다린다
        t.join();
    }
}

int main() {
    example_with_threads();
    example_with_joining_threads();
}

#include <boost/thread/scoped_thread.hpp>
void some_func();
void example_with_raii() {
    boost::scoped_thread<boost::join_if_joinable> t(
        (boost::thread(&some_func))
    );

    // 영역을 나갈 때 't'가 조인된다
}

static bool g_is_first_run = true;
void set_not_first_run() {
    g_is_first_run = false;
}

bool is_first_run() {
    return g_is_first_run;
}

void some_func(){}
