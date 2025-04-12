#include <boost/noncopyable.hpp>
class connection: boost::noncopyable {
public:
    // ������ ���� �� �ð��� �� �ɸ���
    void open();

    void send_result(int result);

    // �ٸ� �޼ҵ��
    // ...
    int open_count_;
    connection(): open_count_(0) {}
};

// ��� ����
#include <boost/thread/tss.hpp>
connection& get_connection();

// �ҽ� ����
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
    // �� ���� ������ �Ѵ�
    // ...

    // ����� ������
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

    // ��� �۾��� ������ ������ ��ٸ��� 
    t1.join();
    t2.join();
    t3.join();
    t4.join();

}
