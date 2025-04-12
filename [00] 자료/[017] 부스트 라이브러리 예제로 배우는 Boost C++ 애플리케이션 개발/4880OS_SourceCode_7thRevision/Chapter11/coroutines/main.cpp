#include <boost/coroutine/coroutine.hpp>

typedef boost::coroutines::coroutine< 
    std::string&(std::size_t max_characters_to_process) 
> corout_t;

void coroutine_task(corout_t::caller_type& caller) {
    std::string result;
    // ���� ���α׷����� �ǵ��ư���
    caller(result);

    while (1) {
        std::size_t max_characters_to_process = caller.get();

        // ���� ó��
        // ...
        result.resize(result.size() + max_characters_to_process);

        // ����� ��ȯ
        // ���� ���α׷����� �ǵ��ư�
        caller(result);
    } /*while*/
}


struct spinlock_t {
    bool try_lock() {
        static int i = 0;
        return i++ >= 100;
    }
};

struct port_t {
    bool block_ready() {
        static int i = 0;
        return i++ >= 10;
    }
};

void coroutine_task(corout_t::caller_type& caller);

int main() {
    corout_t coroutine(coroutine_task);

    // �� ���� �۾�
    // ...
    spinlock_t spinlock;
    port_t port;
    
    while (!spinlock.try_lock()) {
        // ���� ���(spinlock)�� �ѹ� �� ��ױ� ���� 
        // ������ ���� �� �ص���
        coroutine(10); // ª�� ���� �ð� �α�
    }
    // ���� ��� ��ױ�
    // ...
    assert(coroutine.get().size() == 10 * 100);
    coroutine.get().clear();

    while (!port.block_ready()) {
        // �ٽ� �����͸� �������� ����
        // ������ ���� �� �ص���
        coroutine(300);  // �� ū ���� �ð� �α�
        std::string& s = coroutine.get();
        // ...
        (void)s;
    }

    assert(coroutine.get().size() == 10 * 300);
}
