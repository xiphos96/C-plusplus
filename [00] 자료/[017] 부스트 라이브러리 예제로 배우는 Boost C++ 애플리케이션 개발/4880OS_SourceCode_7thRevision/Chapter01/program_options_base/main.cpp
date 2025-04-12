#include <boost/program_options.hpp>
#include <iostream>

namespace opt = boost::program_options;

int main(int argc, char *argv[])
{
    // ������ ��Ÿ���� ���û����� �����
    // ���� �������� "All options"�� �����Ѵ�
    opt::options_description desc("All options");

    // ���û����� �߰��� ��,
    // ù��° �Ķ���ʹ� ����࿡�� ����� �̸�
    // �ι�° �Ķ���ʹ� ���û����� ������������ value<>�� �ѷ��Ѵ�.
    // ����° �Ķ���ʹ� �� ���� ���׿� ���� ������ �����̴�. 
    desc.add_options()
        ("apples", opt::value<int>(), "how many apples do you have")
        ("oranges", opt::value<int>(), "how many oranges do you have")
        ("help", "produce help message")
    ;

    // ����� ���ڸ� ������ ����	
    opt::variables_map vm;

    // ���ڸ� �Ľ��� �� ����
    opt::store(opt::parse_command_line(argc, argv, desc), vm);
    opt::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    std::cout << "Fruits count: "
        << vm["apples"].as<int>() + vm["oranges"].as<int>()
        << std::endl;

    return 0;
}

