#ifndef QUOTATIONS_H
#define QUOTATIONS_H
#include <vector>                                          // vector �����̳�
#include <string>                                          // string Ŭ����
#include <exception>                                       // out_of_range �ͼ���

class Quotations
{
private:
  std::vector<std::string> quotes;                         // ������ ������ �����̳�

public:
  // ���ڿ� ���ͷ��� ������ �� ����� �����Ѵ�
  Quotations& operator<<(const char* quote)
  {
    quotes.emplace_back(quote);
    return *this;
  }

  // string ��ü���� ���ͷ� �� ����� �����Ѵ�
  Quotations& operator<<(const std::string& quote)
  {
    quotes.push_back(quote);
    return *this;
  }

  // ����� ���ͷ� �̵��Ѵ�
  Quotations& operator<<(std::string&& quote)
  {
    quotes.push_back(std::move(quote));
    return *this; 
  }

  // �ε����� ������ ����� ��ȯ�Ѵ�
  std::string& operator[](size_t index)
  {
    if(index < quotes.size())
      return quotes[index];
    else
      throw std::out_of_range {"Invalid index to quotations."};
  }

  size_t size() const {  return quotes.size();  }          // ����� ������ ��ȯ

  // ����� ���� �ݺ��ڸ� ��ȯ�Ѵ�
  std::vector<std::string>::iterator begin()
  {
    return std::begin(quotes);
  }

  // ����� const ���� �ݺ��ڸ� ��ȯ�Ѵ�
  std::vector<std::string>::const_iterator begin() const
  {
    return std::begin(quotes);
  }

  // ����� �� �ݺ��ڸ� ��ȯ�Ѵ�
  std::vector<std::string>::iterator end()
  {
    return std::end(quotes); 
  }

  // ����� const �� �ݺ��ڸ� ��ȯ�Ѵ�
  std::vector<std::string>::const_iterator end() const
  {
    return std::end(quotes);
  }
};
#endif
