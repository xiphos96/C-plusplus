// Ex4_06.cpp
// unordered_map �����̳��� ��Ŷ ������ ����, ��� �����ϴ��� �м��ϱ�
#include <iostream>                                 // ǥ�� ��Ʈ��
#include <iomanip>                                  // ��Ʈ�� ������
#include <string>                                   // string Ŭ����
#include <unordered_map>                            // unordered_map �����̳�
#include <vector>                                   // vector �����̳�
#include <algorithm>                                // max_element() �˰���

using std::string;
using std::unordered_map;

// �� ��Ŷ�� �ִ� ������ ������ ���
void list_bucket_counts(const std::vector<size_t>& counts)
{
  for(size_t i {}; i < counts.size(); ++i)
  {
    std::cout << "bucket[" << std::setw(2) << i << "] = " << counts[i] << "  ";
    if((i + 1) % 6 == 0) std::cout << '\n';
  }
  std::cout << std::endl;
}

int main()
{
  unordered_map<string, size_t> people;
  float mlf {people.max_load_factor()};             // ���� �ִ� �ε� ����
  size_t n_buckets {people.bucket_count()};         // �����̳��� ��Ŷ ����

  std::vector<size_t> bucket_counts (n_buckets);    // ��Ŷ�� ����� ���� ������ ���
  string name {"Name"};                             // Ű - ���� ���߿� �߰���
  size_t value {};                                  // ���� ��
  size_t max_count {8192};                          // ������ �� �ִ� ������ �ִ� ����
  auto lf = people.load_factor();                   // ���� �ε� ����
  bool rehash {false};                              // ���ؽð� �߻��� ���� ���

  while(mlf <= 1.5f)                                // �ִ� �ε� ���Ͱ� 1.5�� �� ������ ������ ����
  {
    std::cout << "\n\n***************New Container***************"
              << "\nNumber of buckets: " << n_buckets
              << "  Maximum load factor: " << mlf << std::endl;

    // �����̳ʿ� �ִ� ���ұ��� ����
    for(size_t n_elements {}; n_elements < max_count; ++n_elements)
    {
      lf = people.load_factor();                               // ���� �� �ε� ����
      people.emplace("name" + std::to_string(++value), value);
      auto new_count = people.bucket_count();                  // ���� ��Ŷ ����

      if(new_count > n_buckets)                                // ��Ŷ ������ �����ϸ�...
      {                                                        // ������ ���
        std::cout << "\nBucket count increased to " << new_count
                  << ". Load factor was " << lf << " and is now " << people.load_factor()
                  << "\nMaximum elements in a bucket was "
                  << *std::max_element(std::begin(bucket_counts), std::end(bucket_counts))
                  << std::endl;

        if(n_buckets <= 64)
        {
          std::cout << "Bucket counts before increase were: " << std::endl;
          list_bucket_counts(bucket_counts);
        }

        n_buckets = new_count;                                  // ��Ŷ ���� ������Ʈ
        bucket_counts = std::vector<size_t> (n_buckets);        // ��Ŷ ������ ���� �� ����
        rehash = true;                                          // ���ؽ� �߻��� ���
      }

      // ���� ��Ŷ ������ ���
      for(size_t i {}; i < n_buckets; ++i)
        bucket_counts[i] = people.bucket_size(i);

      if(rehash)                                                // �����̳ʰ� ���ؽõǾ��ٸ�...
      {                                                         // ...������ ���
        rehash = false;                                         // ���ؽ� ǥ�ø� �ʱ�ȭ

        std::cout << "\nRehashed container. Bucket count is " << n_buckets 
                  << ". Element count is " << people.size()
                  << "\nMaximum element count in a bucket is now "
                  << *std::max_element(std::begin(bucket_counts), std::end(bucket_counts)) 
                  << std::endl;

        if(n_buckets <= 64)                                     // ��Ŷ�� 64�����...
        {
          std::cout << "\nBucket counts after rehash are:\n";
          list_bucket_counts(bucket_counts);
        }
      }
    }

    std::cout << "Final state for this container is:\n"
              << "Bucket count: " << people.bucket_count()
              << "  Element count: " << people.size()
              << "  Maximum element count in a bucket: "
              << *std::max_element(std::begin(bucket_counts), std::end(bucket_counts))
              << std::endl;

    value = 1;                                                  // Ű ���̾ �ʱ�ȭ
    people = unordered_map<string, size_t>();                   // �� �����̳ʸ� ���� �Ҵ�
    n_buckets = people.bucket_count();
    bucket_counts = std::vector < size_t >(n_buckets);          // ��Ŷ ������ ���� �� ����
    mlf += 0.25f;                                               // �ִ� �ε� ���� ����...
    people.max_load_factor(mlf);                                // ...�����̳ʿ� ���� ���� ����
  }
}
