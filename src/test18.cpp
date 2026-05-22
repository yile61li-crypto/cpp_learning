#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


int main() {
  std::vector<std::string> fruits = {"苹果", "香蕉", "橙子"};

  std::cout << "初始列表：";
  for (const auto &f : fruits)
    std::cout << f << " ";
  std::cout << std::endl;

  fruits.push_back("葡萄");
  std::cout << "添加后：";
  for (const auto &f : fruits)
    std::cout << f << " ";
  std::cout << std::endl;

  fruits.insert(fruits.begin() + 1, "芒果");
  std::cout << "插入后：";
  for (const auto &f : fruits)
    std::cout << f << " ";
  std::cout << std::endl;

  fruits.erase(fruits.begin() + 2);
  std::cout << "删除后：";
  for (const auto &f : fruits)
    std::cout << f << " ";
  std::cout << std::endl;

  auto it = find(fruits.begin(), fruits.end(), "橙子");
  if (it != fruits.end()) {
    std::cout << "\"橙子\"在索引：" << std::distance(fruits.begin(), it)
              << std::endl;
  }
  std::cout << "元素个数：" << fruits.size() << std::endl;

  return 0;
}