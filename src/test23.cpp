#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

std::tuple<int, int, double> calculateStats(const std::vector<int> &data) {
  int minVal = data[0], maxVal = data[0];
  int sum = 0;
  for (int val : data) {
    if (val < minVal)
      minVal = val;
    if (val > maxVal)
      maxVal = val;
    sum += val;
  };
  return std::make_tuple(minVal, maxVal, (double)sum / data.size());
};

int main() {
  std::pair<std::string, int> student("张三", 20);
  std::cout << "pair - 姓名：" << student.first << "，年龄：" << student.second
            << std::endl;

  auto point = std::make_pair(3.0, 4.0);
  std::cout << "坐标：（" << point.first << "，" << point.second << "）"
            << std::endl;

  std::tuple<std::string, int, double> person("李四", 25, 1.78);
  std::cout << "\ntuple - 姓名：" << std::get<0>(person) << "，年龄："
            << std::get<1>(person) << "，身高：" << std::get<2>(person)
            << std::endl;

  auto [name, age, height] = person;
  std::cout << "解包；" << name << "，" << age << "，" << height << std::endl;

  std::string n;
  int a;
  double h;
  std::tie(n, a, h) = person;
  std::cout << "tie绑定：" << n << "，" << a << "，" << h << std::endl;

  std::vector<int> data = {15, 8, 23, 42, 16};
  auto [minVal, maxVal, avg] = calculateStats(data);
  std::cout << "\n数据统计：" << std::endl;
  std::cout << "最小值：" << minVal << std::endl;
  std::cout << "最大值：" << maxVal << std::endl;
  std::cout << "平均值：" << avg << std::endl;

  return 0;
}