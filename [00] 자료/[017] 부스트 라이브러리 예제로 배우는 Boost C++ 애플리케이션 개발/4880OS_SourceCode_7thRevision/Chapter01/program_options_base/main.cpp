#include <boost/program_options.hpp>
#include <iostream>

namespace opt = boost::program_options;

int main(int argc, char *argv[])
{
    // 변수를 나타내는 선택사항을 만들고
    // 문자 설명으로 "All options"을 설정한다
    opt::options_description desc("All options");

    // 선택사항을 추가할 때,
    // 첫번째 파라미터는 명령행에서 사용할 이름
    // 두번째 파라미터는 선택사항의 데이터형으로 value<>로 둘러싼다.
    // 세번째 파라미터는 이 선택 사항에 대한 간략한 설명이다. 
    desc.add_options()
        ("apples", opt::value<int>(), "how many apples do you have")
        ("oranges", opt::value<int>(), "how many oranges do you have")
        ("help", "produce help message")
    ;

    // 명령행 인자를 저장할 변수	
    opt::variables_map vm;

    // 인자를 파싱한 후 저장
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

