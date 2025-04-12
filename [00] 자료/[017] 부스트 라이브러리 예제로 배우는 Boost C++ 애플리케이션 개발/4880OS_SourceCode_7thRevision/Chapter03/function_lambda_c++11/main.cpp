#include <boost/function.hpp>
typedef boost::function<void(int)> fobject_t;

// ���� �� �Լ����� �Լ� ��ü�� ���� �� �ִ�
void process_integers(const fobject_t& f);

#include <assert.h>
#include <deque>
int main() {
    // �Ķ���͵� ���� �ʰ�, �ƹ� �͵� ���� �ʴ� ���� �Լ�
    process_integers([](int /*i*/){});

    // �����ڸ� �����ϴ� ���� �Լ�
    std::deque<int> ints;
    process_integers([&ints](int i){
        ints.push_back(i);
    });

    // �ڽ��� ������ �����ϴ� ���� �Լ�
    std::size_t match_count = 0;
    process_integers([ints, &match_count](int i) mutable {
        if (ints.front() == i) {
           ++ match_count;
        }
        ints.pop_front();
    });

    assert(match_count == 6);
}

void process_integers(const fobject_t& f) {
    static const int data[] = {1, 2, 3, 4, 5, 200, 0};
    // �̹� ���������� 6���� ��Ҹ� ����
    std::for_each(data, data + 6, f);
}
