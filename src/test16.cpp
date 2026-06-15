#include <algorithm>
#include <iostream>
#include <string>


int main() {
  std::string text = "Hello, C++ World!";

  std::cout << "原字符串：" << text << std::endl;
  std::cout << "长度：" << text.length() << std::endl;

  std::cout << "子串：" << text.substr(0, 5) << std::endl;
  size_t pos = text.find("C++");
  std::cout << "\"C++\"的位置：" << pos << std::endl;
  std::string replaced = text;
  replaced.replace(pos, 3, "Java");
  std::cout << "替换后： " << replaced << std::endl;

  std::string suffix = "你好！";
  std::cout << "拼接后：" << text + suffix << std::endl;

  std::string upper = text;
  std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
  std::cout << "大写：" << upper << std::endl;

  std::string lower = text;
  std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
  std::cout << "小写：" << lower << std::endl;

  std::cout << "逐字符：";
  for (char c : text) {
    std::cout << c << " ";
  }
  std::cout << std::endl;

  return 0;
}