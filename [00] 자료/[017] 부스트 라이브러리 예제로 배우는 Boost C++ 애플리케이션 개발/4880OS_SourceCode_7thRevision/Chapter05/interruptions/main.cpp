bool stop_parsing = true;
bool not_end_of_parsing = true;

#include <boost/thread.hpp>

void do_parse();

int main() {
    boost::thread parser_thread(&do_parse);

    // ���⿡ �ڵ� �� ���� �´�
    // ...

    if (stop_parsing) {
        // ���̻� �Ľ��� �ʿ� ����
        // �� ��: �ļ� �ߴ�
    }

    if (stop_parsing) {
        // ���̻� �Ľ��� �ʿ� ����
        parser_thread.interrupt();
    }

	parser_thread.join();
}

void do_parse() {
    while (not_end_of_parsing) {
        boost::this_thread::interruption_point();
        // �Ľ̿� �ʿ��� �ڵ�

    }

    // �� ������� �������� �´� 
    assert(false);
}

