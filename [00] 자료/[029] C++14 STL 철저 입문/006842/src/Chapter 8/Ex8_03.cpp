// Ex8_03.cpp
// ������ ���Ƿ� ī�带 �ٷ��
#include <iostream>                                      // ǥ�� ��Ʈ��
#include <ostream>                                       // ostream ��Ʈ��
#include <iomanip>                                       // ��Ʈ�� ������
#include <iterator>                                      // �ݺ���, begin(), end()
#include <random>                                        // ���� �ѹ� ������� ����
#include <utility>                                       // pair<T1,T2> ���ø�
#include <vector>                                        // vector<T> �����̳�
#include <list>                                          // list<T> �����̳�
#include <array>                                         // array<T,N> �����̳�
#include <string>                                        // string Ŭ����
#include <type_traits>                                   //  is_same ������


using std::string;
enum class Suit : size_t { Clubs, Diamonds, Hearts, Spades };
enum class Face : size_t { Two, Three, Four, Five, Six, Seven, 
                           Eight, Nine, Ten, Jack, Queen, King, Ace };
using Card = std::pair<Suit,Face>;                       // ī�带 ���� Ÿ��
using Hand = std::list<Card>;                            // �տ� �� ī�带 ���� Ÿ��
using Deck = std::list<Card>;                            // ī�� ���� ���� Ÿ��
using Hands = std::vector<Hand>;                         // �տ� �� ī�� �����̳ʸ� ���� Ÿ��
using Range = std::uniform_int_distribution<size_t>::param_type;

// Card ��ü�� ���� ��Ʈ�� ����(<<) ������
std::ostream& operator<<(std::ostream& out, const Card& card)
{
  static std::array<string, 4> suits { "C", "D", "H", "S" };              // ī�� ���� �̸�
  static std::array<string, 13> values { "2", "3", "4", "5", "6", "7",    // ī�� ���� �̸�
                                         "8", "9", "10", "J", "Q", "K", "A" };
  string suit { suits[static_cast<size_t>( card.first )] };
  string value { values[static_cast<size_t>( card.second )] };
  return out << std::setw(2) << value << suit;
}

// ���α׷� �ڵ� ��ü���� ����� �� �ִ� ���� �ѹ� ������
std::default_random_engine& rng()
{
  static std::default_random_engine engine {std::random_device()()};
  return engine;
}

// ���α׷� �ڵ� ��ü���� ����� �� �ִ� int Ÿ���� ���� �յ� ���� ��ü
std::uniform_int_distribution<size_t>& dist()
{
  static std::uniform_int_distribution<size_t> d ;
  return d;
}

// 52���� ī�� ��ü ��Ʈ�� ������ �ʱ�ȭ
Deck& init_deck(Deck& deck)
{
  static std::array<Suit,4> suits{ Suit::Clubs, Suit::Diamonds, Suit::Hearts, Suit::Spades };
  static std::array<Face, 13> values { Face::Two,   Face::Three, Face::Four, Face::Five, Face::Six,
                                       Face::Seven, Face::Eight, Face::Nine, Face::Ten,
                                       Face::Jack,  Face::Queen, Face::King, Face::Ace };
  deck.clear();
  for(const auto& suit : suits)
    for(const auto& value : values)
    deck.emplace_back(Card {suit, value});
  return deck;
}

// ��ü ���� ��(deal)�Ѵ�
void deal(Hands& hands, Deck& deck)
{
  auto d = dist();
  while(!deck.empty())
  {
    for(auto&& hand : hands)
    {
      size_t max_index = deck.size() - 1;
      d.param(Range{0, max_index});
      auto iter = std::begin(deck);
      std::advance(iter, d(rng()));
      hand.push_back(*iter);
      deck.erase(iter);
    }
  }
}

// �տ� �� ī�带 ī�� ������ ����
void sort_hands(Hands& hands)
{
  for(auto&& hand : hands)
    hand.sort([](const auto& crd1, const auto crd2) { return crd1.first < crd2.first ||
      (crd1.first == crd2.first && crd1.second < crd2.second); });
}

// �տ� �� ��� ī�带 ���
void show_hands(const Hands& hands)
{
  for(auto&& hand : hands)
  {
    std::copy(std::begin(hand), std::end(hand), std::ostream_iterator<Card> {std::cout, " "});
    std::cout << std::endl;
  }
}

int main()
{
  // ���� �����Ѵ�
  Deck deck;
  init_deck(deck);

  // ��(hands)�� ����� ���Ѵ�
  Hands hands(4);
  deal(hands, deck);

  // �տ� �� ī�带 �����ϰ� �����ش�
  sort_hands(hands);
  show_hands(hands);
}