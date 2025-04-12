#include <iostream>
#include <string>

int main()
{
	// ���ڿ� ��� ���� ����
	std::string s1;
	std::cout << "s1 : " << s1 << std::endl;


	// ���ڿ� ���
	std::string s2 = "hello";
    std::cout << "s2 : " << s2 << std::endl;

    std::cout << "s3 : " << std::string("hello") << std::endl;


    // ���ڿ��� �Ϻθ� ��� 
    // ���ڿ��� �ΰ��� s4�� ����
    std::string s4("hello", 2);
    std::cout << "s4 : " << s4 << std::endl;

    // ���ڿ��� 2��° ��ġ���� 8���ڱ����� s5�� ����
    std::string s5("Game is Fun", 1, 8);
    std::cout << "s5 : " << s5 << std::endl;

    std::string s6(s5, 0, 3);
    std::cout << "s6 : " << s6 << std::endl;


    // ���ڸ� ���� Ƚ����ŭ ����
    std::string s7(7, 'c');
    std::cout << "s7 : " << s7 << std::endl;
  

    // �ݺ��ڸ� ����Ͽ� ���ڿ� ����
    std::string s8(s2.begin(), s2.end());
    std::cout << "s8 : " << s8 << std::endl;

	return 0;
}



