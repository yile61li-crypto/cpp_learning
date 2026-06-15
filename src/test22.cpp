#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>


int main() {
  std::set<int> s1 = {3, 1, 4, 1, 5, 9, 2, 6};
  std::cout << "s1: ";
  for (int n : s1)
    std::cout << n << " ";
  std::cout << std::endl;

  s1.insert(7);
  s1.erase(4);
  std::cout << "添加7删除4后：";
  for (int n : s1)
    std::cout << n << " ";
  std::cout << std::endl;

  std::cout << "查找5：" << (s1.count(5) ? "存在" : "不存在") << std::endl;
  std::cout << "查找4：" << (s1.count(4) ? "存在" : "不存在") << std::endl;

  std::set<int> setA = {1, 2, 3, 4, 5};
  std::set<int> setB = {4, 5, 6, 7, 8};

  std::vector<int> result;

  std::set_union(setA.begin(), setA.end(), setB.begin(), setB.end(),
                 std::back_inserter(result));
  std::cout << "\n并集: ";
  for (int n : result)
    std::cout << n << " ";
  std::cout << std::endl;

  result.clear();
  std::set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
                        std::back_inserter(result));
  std::cout << "\n交集：";
  for (int n : result)
    std::cout << n << " ";
  std::cout << std::endl;

  result.clear();
  std::set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(),
                      std::back_inserter(result));
  std::cout << "\n差集（A-B）：";
  for (int n : result)
    std::cout << n << " ";
  std::cout << std::endl;

  std::vector<int> nums = {1, 2, 2, 3, 4, 4, 5};
  std::set<int> uniqueSet(nums.begin(), nums.end());
  std::cout << "\n原vector：";
  for (int n : nums)
    std::cout << n << " ";
  std::cout << "\n去重后：";
  for (int n : uniqueSet)
    std::cout << n << " ";
  std::cout << std::endl;

  return 0;
}
