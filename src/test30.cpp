#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


double safeDivide(double a, double b) {
  if (b == 0) {
    throw std::runtime_error("除数不能为零");
  }
  return a / b;
}

int safeVectorAccess(const std::vector<int> &v, int index) {
  if (index < 0 || index >= static_cast<int>(v.size())) {
    throw std::out_of_range("索引 " + std::to_string(index) + " 超出范围[0, " +
                            std::to_string(v.size() - 1) + "]");
  }
  return v[index];
}

int main() {
  try {
    std::cout << "10 / 2 = " << safeDivide(10, 2) << std::endl;
    std::cout << "10 / 0 = " << safeDivide(10, 0) << std::endl;
  } catch (const std::runtime_error &e) {
    std::cout << "运行时错误：" << e.what() << std::endl;
  }

  std::vector<int> nums = {10, 20, 30};
  try {
    std::cout << "\nnums[1] = " << safeVectorAccess(nums, 1) << std::endl;
    std::cout << "nums[5] = " << safeVectorAccess(nums, 5) << std::endl;
  } catch (const std::out_of_range &e) {
    std::cout << "越界错误：" << e.what() << std::endl;
  }

  try {
    std::string s = "abc";
    int n = std::stoi(s);
  } catch (const std::invalid_argument &e) {
    std::cout << "\n无效参数：" << e.what() << std::endl;
  } catch(const std::exception& e) {
    std::cout << "\n其他异常：" << e.what() << std::endl;
  }

  std::cout << "\n程序正常结束" << std::endl;

  return 0;
}