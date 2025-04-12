// Ex3_01.cpp

// ���� �����̳ʸ� ����� ������ ����

#include <cmath>                                 // pow() �Լ�
#include <iostream>                              // ǥ�� ��Ʈ��
#include <stack>                                 // stack<T> �����̳�
#include <algorithm>                             // remove()
#include <stdexcept>                             // runtime_error �ͼ���
#include <string>                                // string Ŭ����
using std::string;

// ������ �켱���� ���� ��ȯ�Ѵ�
inline size_t precedence(const char op)
{
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  if (op == '^')
    return 3;
  throw std::runtime_error {string {"invalid operator in precedence() function: "} + op};
}

// ������ �����Ѵ�
double execute(std::stack<char>& ops, std::stack<double>& operands)
{
  double result {};
  double rhs {operands.top()};                  // ������ �����´�...
  operands.pop();                               // ...�׸��� ���ÿ��� �����Ѵ�
  double lhs {operands.top()};                  // ������ �����´�...
  operands.pop();                               // ...�׸��� ���ÿ��� �����Ѵ�

  switch (ops.top())                            // ���� �����ڸ� �����Ѵ�
  {
  case '+':
    result = lhs + rhs;
    break;
  case '-':
    result = lhs - rhs;
    break;
  case '*':
    result = lhs * rhs;
    break;
  case '/':
    result = lhs / rhs;
    break;
  case '^':
    result = std::pow(lhs, rhs);
    break;
  default:
    throw std::runtime_error {string{"invalid operator: "} + ops.top()};
  }
  ops.pop();                                    // ��� ������ �����ڸ� �����Ѵ�
  operands.push(result);
  return result;
}

int main()
{
  std::stack<double> operands;           // �ǿ����� Ǫ�ôٿ� ����
  std::stack<char> operators;            // ������ Ǫ�ôٿ� ����
  string exp;                            // ���� ����
  std::cout << 
              "An arithmetic expression can include the operators +, -, *, /, and ^ for exponentiation."
            << std::endl;
  try
  {
    while (true)
    {
      std::cout << "Enter an arithmetic expression and press Enter - enter an empty line to end:" << std::endl;
      std::getline(std::cin, exp, '\n');
      if (exp.empty()) break;

      // ������ �����Ѵ�
      exp.erase(std::remove(std::begin(exp), std::end(exp), ' '), std::end(exp));

      size_t index {};                            // ���ڿ� ���� ���� �ε���

      // ��� ǥ���Ŀ��� �ǿ����ڴ� ���ڷ� �����ؾ� �Ѵ�
      operands.push(std::stod(exp, &index));  // ���ÿ� ù ��° �ǿ�����(����, lhs)�� �ִ´�

      while (true)
      {
        operators.push(exp[index++]);             // �����ڸ� ���ÿ� �ִ´�

        // Get rhs operand
        size_t i {};                                      // ���꽺Ʈ���� �ε���
        operands.push(std::stod(exp.substr(index), &i));  // ���� �ǿ�����(rhs)�� �ִ´�
        index += i;                                       // ���� �ε����� ����

        if (index == exp.length())                    // ���� ���� ����������...
        {
          while (!operators.empty())                  // ...ó������ ���� �����ڸ� ����
            execute(operators, operands);
          break;
        }

        // ������� �����ϸ� ó���� �����ڰ� ���� ���� �ִ�...
        // ���� �����ڿ� ���ų� �� ���� �켱�����̸� �����Ѵ�
        while (!operators.empty() && precedence(exp[index]) <= precedence(operators.top())) 
          execute(operators, operands);                   //  ���� �����ڸ� �����Ѵ�
      }
      std::cout << "result = " << operands.top() << std::endl;
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "Calculator ending..." << std::endl;
}
