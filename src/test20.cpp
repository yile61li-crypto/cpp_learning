#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> scores;
  scores["张三"] = 85;
  scores["李四"] = 92;
  scores["王五"] = 78;
  scores.insert(std::make_pair("赵六", 90));

  std::cout << "张三的成绩：" << scores["张三"] << std::endl;

  scores["孙七"] = 88;
  std::cout << "添加后，共有 " << scores.size() << "  个学生" << std::endl;

  scores["王五"] = 85;
  std::cout << "王五修改后的成绩：" << scores["王五"] << std::endl;

  std::string target = "李四";
  auto it = scores.find(target);
  if (it != scores.end()) {
    std::cout << target << " 找到， 成绩：" << it->second << std::endl;
  } else {
    std::cout << target << " 未找到" << std::endl;
  }

  scores.erase("赵六");
  std::cout << " 删除赵六后，共有 " << scores.size() << " 个学生" << std::endl;

  std::cout << "\n所以学生的成绩：" << std::endl;
  for (const auto &[name, score] : scores) {
    std::cout << " " << name << ": " << score << "分" << std::endl;
  }

  return 0;
}