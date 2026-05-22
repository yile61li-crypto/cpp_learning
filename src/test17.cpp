#include <array>
#include <iostream>


int main() {
  int numbers[] = {85, 92, 78, 90, 88};
  int size = sizeof(numbers) / sizeof(numbers[0]);

  std::cout << "原生数组：";
  for (int i = 0; i < size; i++) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  int maxVal = numbers[0], minVal = numbers[0];
  int sum = 0;
  for (int i = 0; i < size; i++) {
    if (numbers[i] > maxVal)
      maxVal = numbers[i];
    if (numbers[i] < minVal)
      minVal = numbers[i];
    sum += numbers[i];
  }
  std::cout << "最大值：" << maxVal << std::endl;
  std::cout << "最小值：" << minVal << std::endl;
  std::cout << "平均值：" << (double)sum / size << std::endl;

  std::array<int, 5> scores = {95, 87, 76, 93, 81};
  std::cout << "\nstd::array：";
  for (int s : scores) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  std::cout << "数组大小：" << scores.size() << std::endl;
  std::cout << "第一个元素：" << scores.front() << std::endl;
  std::cout << "最后一个元素：" << scores.back() << std::endl;

  return 0;
}