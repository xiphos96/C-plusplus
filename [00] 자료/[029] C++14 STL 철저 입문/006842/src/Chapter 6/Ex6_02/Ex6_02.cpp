// Ex6_02.cpp
// ���İ� ���� ����
#include <iostream>                              // ǥ�� ��Ʈ��
#include <string>                                // string Ŭ����
#include <algorithm>                             // sort(), inplace_merge()
#include <functional>                            // greater<T>
#include <vector>                                // vector �����̳�
#include <utility>                               // pair ���ø� Ÿ��
#include <map>                                   // map �����̳�
#include <iterator>                              // ��Ʈ���� back_inserter
#include "Account.h"
#include "Transaction.h"
#include "Compare_Names.h"

using std::string;
using first_name = string;
using second_name = string;
using Name = std::pair<first_name, second_name>;
using Account_Number = size_t;

// ���� �������� �̸��� �о�´�
Name get_holder_name(Account_Number number)
{
  std::cout << "Enter the holder's first and second names for account number " << number << ": ";
  string first{};
  string second{};
  std::cin >> first >> second;
  return std::make_pair(first, second);
}

int main()
{
  std::vector<Transaction> transactions;

  std::cout << "Enter each transaction as:\n"
    << "   5 digit account number   amount   credit(true or false).\n"
    << "Enter Ctrl+Z to end.\n";

  // �ŷ��� ù ���� ��Ʈ�� �о�´�
  std::copy(std::istream_iterator<Transaction> {std::cin}, std::istream_iterator<Transaction> {},
    std::back_inserter(transactions));
  std::cin.clear();                              // ��Ʈ���� EOF �÷��׸� �����Ѵ�

                                                 // ù ��° ��Ʈ�� ���¹�ȣ ������������ �����Ѵ�
  std::stable_sort(std::begin(transactions), std::end(transactions), std::greater<>());

  // �ŷ��� ����Ѵ�
  std::cout << "First set of transactions after sorting...\n";
  std::copy(std::begin(transactions), std::end(transactions),
    std::ostream_iterator<Transaction>{std::cout, "\n"});


  // �ŷ��� �� ��° ��Ʈ�� �о�´�
  std::cout << "\nEnter more transactions:\n";
  std::copy(std::istream_iterator<Transaction> {std::cin}, std::istream_iterator<Transaction> {},
    std::back_inserter(transactions));
  std::cin.clear();                              // ��Ʈ���� EOF �÷��׸� �����Ѵ�

                                                 // �ŷ��� ����Ѵ�
  std::cout << "\nSorted first set of transactions with second set appended...\n";
  std::copy(std::begin(transactions), std::end(transactions),
    std::ostream_iterator<Transaction>{std::cout, "\n"});

  // �� ��° ��Ʈ�� ���¹�ȣ ������������ �����Ѵ�
  auto iter = std::is_sorted_until(std::begin(transactions), std::end(transactions),
    std::greater<>());
  std::stable_sort(iter, std::end(transactions), std::greater<>());

  // �ŷ��� ����Ѵ�
  std::cout << "\nSorted first set of transactions with sorted second set appended...\n";
  std::copy(std::begin(transactions), std::end(transactions),
    std::ostream_iterator<Transaction>{std::cout, "\n"});

  // ���ο��� �ŷ��� �����Ѵ�
  std::inplace_merge(std::begin(transactions), iter, std::end(transactions), std::greater<>());

  // �ŷ��� ����Ѵ�
  std::cout << "\nMerged sets of transactions...\n";
  std::copy(std::begin(transactions), std::end(transactions),
    std::ostream_iterator<Transaction>{std::cout, "\n"});

  // �ʿ��� �� Account ��ü�� �����ϸ鼭 �ŷ��� ó���Ѵ�
  std::map<Account_Number, Account> accounts;
  for (const auto& tr : transactions)
  {
    Account_Number number = tr.get_acc_number();
    auto iter = accounts.find(number);
    if (iter == std::end(accounts))
      iter = accounts.emplace(number, Account{number, get_holder_name(number)}).first;

    if (iter->second.apply_transaction(tr))
    {
      auto name = iter->second.get_name();
      std::cout << "\nAccount number " << number
        << " for " << name.first << " " << name.second << " is overdrawn!\n"
        << "The concept is that you bank with us - not the other way round, so fix it!\n"
        << std::endl;
    }
  }

  // ���¸� ���� �����̳ʷ� �����Ѵ�
  std::vector<Account> accs;
  for (const auto& pr : accounts)
    accs.push_back(pr.second);

  // �̸������� ������ �Ŀ� ���µ��� ����Ѵ�
  std::stable_sort(std::begin(accs), std::end(accs), Compare_Names());
  std::copy(std::begin(accs), std::end(accs), std::ostream_iterator < Account > {std::cout, "\n"});
}
