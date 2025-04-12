// Ex8_07.cpp
// �̻������ ����� �ֻ��� ������ ������ �����ϴ� ����
#include <random>                              // discrete_distribution, ���� �ѹ� ������
#include <array>                               // array �����̳�
#include <utility>                             // pair Ÿ��
#include <algorithm>                           // count(), remove()
#include <iostream>                            // ǥ�� ��Ʈ��
#include <iomanip>                             // ��Ʈ�� ������
#include "Die.h"                               // �ֻ����� ������ Ŭ����

// ���α׷� �ڵ� ��ü���� ����� ���� �ѹ� ������
std::default_random_engine& rng()
{
  static std::default_random_engine engine {std::random_device()()};
  return engine;
}

int main()
{
  size_t n_games {};                                       // �÷����� ������ Ƚ��
  const size_t n_dice {4};                                 // �ֻ����� ����

  std::array<Die, n_dice> dice                             // �ֻ���
  {
    Die {3, 3, 3, 3, 3, 3},
    Die {0, 0, 4, 4, 4, 4},
    Die {1, 1, 1, 5, 5, 5},
    Die {2, 2, 2, 2, 6, 6}
  };

  std::cout <<
     "For each game, select a die from the following by entering 1, 2, 3, or 4 (or Ctrl+Z to end):\n"
            << "die 1: 3 3 3 3 3 3\n"
            << "die 2: 0 0 4 4 4 4\n"
            << "die 3: 1 1 1 5 5 5\n"
            << "die 4: 2 2 2 2 6 6\n";

  size_t you {}, me {};                                    // �� �ֻ����� ���� �ֻ����� �ε����� ����

  while(true)
  {
    std:: cout << "\nChoose a die: ";
    if((std::cin >> you).eof()) break;                     // EOF - ��� ���� ����

    if(you == 0 || you > n_dice)                           // 1���� 4������ ������ �� ����
    {
      std::cout << "Selection must be from 1 to 4, try again.\n";
      continue;
    }

    // �� �ֻ����� ���������� ���� ������ �����Ѵ�
    me = you-- % n_dice;                                   // ������ 0���� 3, ���� you + 1 mod 4
    std::cout << "I'll choose:  " << (me+1) << std::endl;


    // �ֻ��� ������
    const size_t n_throws {15};
    std::array<std::pair<size_t, size_t>, n_throws> goes; // ���� ��� - pair<me_value, you_value>
    std::generate(std::begin(goes), std::end(goes),       // �ֻ����� ������
      [&dice, me, you] { return std::make_pair(dice[me].throw_it(), dice[you].throw_it()); });

    // ���� ����� ����Ѵ�
    std::cout << "\nGame " << ++n_games << ":\n";

    // �� ������ ����� ���...
    std::cout << "Me : ";
    std::for_each(std::begin(goes), std::end(goes),
      [](const std::pair<size_t, size_t>& pr)
    {  std::cout << std::setw(3) << pr.first; });
    auto my_wins = std::count_if(std::begin(goes), std::end(goes), 
                                                     [](const std::pair<size_t, size_t>& pr)
                                                     { return pr.first > pr.second; });
    std::cout << " My wins:   " << std::setw(2) <<  std::right << my_wins 
              << "   I " << ((my_wins > n_throws / 2) ? "win!!" : "lose {:-(")
              << std::endl;

    // ������ ������ ����� ��� - �� ��� �ؿ� �����ؼ� ����Ѵ�
    std::cout << "You: ";
    std::for_each(std::begin(goes), std::end(goes), [](const std::pair<size_t, size_t>& pr)
                                              { std::cout << std::setw(3) << pr.second; });
    std::cout << " Your wins: " << std::setw(2) << std:: right << n_throws - my_wins 
              << "   You " << ((my_wins <= n_throws / 2) ? "win!!" : "lose!!!") 
              << std::endl;
  }
}
