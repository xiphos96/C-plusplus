
void may_throw1(const char* buffer);
void may_throw2(const char* buffer);

void foo() {
    // ���ÿ� 10MB�� �̸��� �޸𸮴� �Ҵ��� �� ����.
    // �׷��� ���� �Ҵ��ؾ��Ѵ�
    char* buffer = new char[1024 * 1024 * 10];

    // ���⿡ ���ܸ� ���� ���� �ִ� �ڵ� ����
    may_throw1(buffer);
    may_throw2(buffer);

    delete[] buffer;
}

#include <boost/scoped_array.hpp>

void foo_fixed() {
    // ���� �Ҵ��Ѵ�
    boost::scoped_array<char> buffer(new char[1024 * 1024 * 10]);

    // ���⿡ ���ܸ� ���� ���� �ִ� �ڵ� ����
    // ������ �̹����� �޸𸮰� ������� �ʴ´�
    may_throw1(buffer.get());
    may_throw2(buffer.get());

    // 'buffer'�� �Ҹ��ڰ� delete[] ȣ��
}

#include <stdexcept>
#include <assert.h>

int main() {
    // foo(); // �޸� ����
    try {
        foo_fixed();
    } catch (...){}

    return 0;
}


void may_throw1(const char* /*buffer*/) {
    // �ƹ� �͵� ���� �ʴ´�
}

void may_throw2(const char* /*buffer*/) {
    throw std::exception();
}
