#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>


int main() {
  std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  std::cout << "原始数据：";
  for (int n : numbers)
    std::cout << n << " ";
  std::cout << std::endl;

  std::vector<int> sorted_acc = numbers;
  std::sort(sorted_acc.begin(), sorted_acc.end());
  std::cout << "升序排序：";
  for (int n : sorted_acc)
    std::cout << n << " ";
  std::cout << std::endl;

  std::vector<int> reversed = numbers;
  std::reverse(reversed.begin(), reversed.end());
  std::cout << "反转后：";
  for (int n : reversed)
    std::cout << n << " ";
  std::cout << std::endl;

  std::vector<int> unique_ver = numbers;
  std::sort(unique_ver.begin(), unique_ver.end());
  unique_ver.erase(std::unique(unique_ver.begin(), unique_ver.end()),
                   unique_ver.end());
  std::cout << "去重后：";
  for (int n : unique_ver)
    std::cout << n << " ";
  std::cout << std::endl;

  std::cout << "\n最大值：" << *std::max_element(numbers.begin(), numbers.end())
            << std::endl;
  std::cout << "\n最小值：" << *std::min_element(numbers.begin(), numbers.end())
            << std::endl;
  std::cout << "\n累加和："
            << std::accumulate(numbers.begin(), numbers.end(), 0) << std::endl;
  std::cout << "元素5出现次数："
            << std::count(numbers.begin(), numbers.end(), 5) << std::endl;

  return 0;
}