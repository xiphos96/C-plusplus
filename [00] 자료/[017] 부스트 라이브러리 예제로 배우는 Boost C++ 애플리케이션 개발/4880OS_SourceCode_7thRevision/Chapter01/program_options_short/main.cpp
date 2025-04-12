#include <boost/program_options.hpp>
// 'reading_file' 예외는 errors.hpp에 선언되어 있다
#include <boost/program_options/errors.hpp>
#include <iostream>

namespace opt = boost::program_options;

int main(int argc, char *argv[])
{
    opt::options_description desc("All options");

    // 'a'와 'o'는 사과(apple)과 오렌지(orange)를 나타내는 짧게 줄인 선택사항 이름
    // 'name' 옵션은 'required()'로 표시되지 않았으므로, 사용자가 제공하지 않을 수 있다
    desc.add_options()
        ("apples,a", opt::value<int>()->default_value(10), "how many apples do you have")
        ("oranges,o", opt::value<int>(), "how many oranges do you have")
        ("name", opt::value<std::string>(), "your name")
        ("help", "produce help message")
    ;

    opt::variables_map vm;

    // 명령행을 파싱한 후 'vm'에 값 저장
    opt::store(opt::parse_command_line(argc, argv, desc), vm);

    // 'parse_environment' 메소드를 사용해 환경 변수도 파싱할 수 있다
    opt::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    // "aples_oranges.cfg" 구성 파일에서 빠진 선택사항을 추가	
    // 'parse_config_file' 에 대한 첫번째 파라미터로 
	// istreamable 객체를 줄 수도 있다
    // 'char' 템플릿 파라미터는 std::basic_istream object로 전달된다
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

