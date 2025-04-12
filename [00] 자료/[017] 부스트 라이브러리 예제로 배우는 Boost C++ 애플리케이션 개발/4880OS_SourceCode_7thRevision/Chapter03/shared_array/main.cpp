#include <cstring>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

void do_process(const char* data, std::size_t size);

void do_process_in_background(const char* data, std::size_t size) {
    // ȣ���ڰ� ���� �����͸� �Ҵ� ������ �� �� �� �����Ƿ�
    // �����͸� �����ؾ��Ѵ�
    char* data_cpy = new char[size];
    std::memcpy(data_cpy, data, size);

    // �����͸� ó���ϱ� ���� �����带 �����Ѵ�
    boost::thread(boost::bind(&do_process, data_cpy, size));

    // do_process1�� do_process2�� data_cpy�� ó���ϰ� ���� ���� �𸣹Ƿ�
    // delete[] data_cpy�� �� �� ����	
}

#include <boost/shared_array.hpp>
void do_process_shared_array(const boost::shared_array<char>& data, std::size_t size) {
    do_process(data.get(), size);
}

void do_process_in_background_v1(const char* data, std::size_t size) {
    // ȣ���ڰ� ���� �����͸� �Ҵ� ������ �� �� �� �����Ƿ�
    // �����͸� �����ؾ� �Ѵ�
    boost::shared_array<char> data_cpy(new char[size]);
    std::memcpy(data_cpy.get(), data, size);

    // �����͸� ó���ϱ� ���� �����带 �����Ѵ�
    boost::thread(boost::bind(&do_process_shared_array, data_cpy, size))
            .detach();

    // ���� Ƚ���� 0�� �� ��� data_cpy �Ҹ��ڰ� �˾Ƽ� �����͸� ������Ű�� ������ 
    // data_cpy�� ���� delete[]�� �θ� �ʿ䰡 ����
}


#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

void do_process_shared_ptr(
        const boost::shared_ptr<char[]>& data,
        std::size_t size)
{
    do_process(data.get(), size);
}

void do_process_in_background_v2(const char* data, std::size_t size) {
    // 'ù��° ���'���� ������
    boost::shared_ptr<char[]> data_cpy = boost::make_shared<char[]>(size);
    std::memcpy(data_cpy.get(), data, size);

    // �����͸� ó���ϱ� ���� �����带 �����Ѵ�
    boost::thread(boost::bind(&do_process_shared_ptr, data_cpy, size))
            .detach();

    // ���� Ƚ���� 0�� �� ��� 
    // data_cpy �Ҹ��ڰ� �˾Ƽ� �����͸� ����
}

void do_process_shared_ptr2(
        const boost::shared_ptr<char>& data,
        std::size_t size)
{
    do_process(data.get(), size);
}

void do_process_in_background_v3(const char* data, std::size_t size) {
    // ù��° ����� �ӵ��� ����
    boost::shared_ptr<char> data_cpy(
                new char[size],
                boost::checked_array_deleter<char>()
    );
    std::memcpy(data_cpy.get(), data, size);

    // �����͸� ó���ϱ� ���� �����带 �����Ѵ�
    boost::thread(boost::bind(&do_process_shared_ptr2, data_cpy, size))
            .detach();

    // ���� Ƚ���� 0�� �� ��� 
    // data_cpy �Ҹ��ڰ� �˾Ƽ� �����͸� ����
}

#include <boost/chrono/duration.hpp>
int main () {
    // do_process_in_background(); // �޸� ������ �Ͼ �� �ִ�
    char ch[] = "Hello dear reader.";
    do_process_in_background_v1(ch, sizeof(ch));
    do_process_in_background_v2(ch, sizeof(ch));
    do_process_in_background_v3(ch, sizeof(ch));

    // ��� �����忡�� ���� ��ȸ�� �ο��ȴ�
    // ����: ���� ������ ������������, �����ϱ� �ẻ ���̴�
    boost::this_thread::sleep_for(boost::chrono::seconds(2));
    return 0;
}

void do_process(const char* data, std::size_t size) {
    assert(size);
    assert(data);
}
