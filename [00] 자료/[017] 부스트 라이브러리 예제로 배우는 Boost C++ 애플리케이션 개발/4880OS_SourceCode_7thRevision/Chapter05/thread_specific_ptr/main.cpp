#include <boost/noncopyable.hpp>
class connection: boost::noncopyable {
public:
    // 연결을 여는 데 시간이 꽤 걸린다
    void open();

    void send_result(int result);

    // 다른 메소드들
    // ...
    int open_count_;
    connection(): open_count_(0) {}
};

// 헤더 파일
#include <boost/thread/tss.hpp>
connection& get_connection();

// 소스 파일
boost::thread_specific_ptr<connection> connection_ptr;

connection& get_connection() {
    connection* p = connection_ptr.get();
    if (!p) {
        connection_ptr.reset(new connection);
        p = connection_ptr.get();
        p->open();
    }

    return *p;
}


void task() {
    int result = 2;
    // 몇 가지 연산을 한다
    // ...

    // 결과를 보낸다
    get_connection().send_result(result);
}

void connection::open() {
    assert(!open_count_);
    open_count_ = 1;
}

void connection::send_result(int /*result*/) {}

void run_tasks() {
    for (std::size_t i = 0; i < 10000000; ++i) {
        task();
    }
}

#include <boost/thread/thread.hpp>

int main() {
    boost::thread t1(&run_tasks);
    boost::thread t2(&run_tasks);
    boost::thread t3(&run_tasks);
    boost::thread t4(&run_tasks);

    // 모든 작업이 꺼내질 때까지 기다린다 
    t1.join();
    t2.join();
    t3.join();
    t4.join();

}
