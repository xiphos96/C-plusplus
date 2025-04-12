#include <boost/program_options.hpp>
// 'reading_file' ���ܴ� errors.hpp�� ����Ǿ� �ִ�
#include <boost/program_options/errors.hpp>
#include <iostream>

namespace opt = boost::program_options;

int main(int argc, char *argv[])
{
    opt::options_description desc("All options");

    // 'a'�� 'o'�� ���(apple)�� ������(orange)�� ��Ÿ���� ª�� ���� ���û��� �̸�
    // 'name' �ɼ��� 'required()'�� ǥ�õ��� �ʾ����Ƿ�, ����ڰ� �������� ���� �� �ִ�
    desc.add_options()
        ("apples,a", opt::value<int>()->default_value(10), "how many apples do you have")
        ("oranges,o", opt::value<int>(), "how many oranges do you have")
        ("name", opt::value<std::string>(), "your name")
        ("help", "produce help message")
    ;

    opt::variables_map vm;

    // ������� �Ľ��� �� 'vm'�� �� ����
    opt::store(opt::parse_command_line(argc, argv, desc), vm);

    // 'parse_environment' �޼ҵ带 ����� ȯ�� ������ �Ľ��� �� �ִ�
    opt::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    // "aples_oranges.cfg" ���� ���Ͽ��� ���� ���û����� �߰�	
    // 'parse_config_file' �� ���� ù��° �Ķ���ͷ� 
	// istreamable ��ü�� �� ���� �ִ�
    // 'char' ���ø� �Ķ���ʹ� std::basic_istream object�� ���޵ȴ�
    try {
        opt::store(opt::parse_config_file<char>("apples_oranges.cfg", desc), vm);
    } catch (const opt::reading_file& e) {
        std::cout << "Failed to open configuration file 'apples_oranges.cfg': "
                  << e.what();
    }
    opt::notify(vm);

    if (vm.count("name")) {
        std::cout << "Hi," << vm["name"].as<std::string>() << "!\n";
    }

    std::cout << "Fruits count: "
        << vm["apples"].as<int>() + vm["oranges"].as<int>()
        << std::endl;

    return 0;
}

