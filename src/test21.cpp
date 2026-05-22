#include <iostream>
#include <map>
#include <ostream>
#include <string>

int main() {
  std::map<std::string, int> scores = {
      {"语文", 88}, {"数学", 95}, {"英语", 82}, {"物理", 90}, {"化学", 86}};

  std::cout << "迭代器遍历：" << std::endl;
  for (std::map<std::string, int>::iterator it = scores.begin();
       it != scores.end(); ++it) {
    std::cout << " " << it->first << "：" << it->second << std::endl;
  };

  std::cout << "\n范围for遍历：" << std::endl;
  for (const auto &pair : scores) {
    std::cout << " " << pair.first << "：" << pair.second << "分" << std::endl;
  };

  std::cout << "\n结构化绑定遍历：" << std::endl;
  int total = 0;
  int maxScore = 0, minScore = 100;
  std::string maxSubject, minSubject;

  for (const auto &[subject, score] : scores) {
    std::cout << " " << subject << "：" << score << "分" << std::endl;
    total += score;
    if (score > maxScore) {
      maxScore = score;
      maxSubject = subject;
    };
    if (score < minScore) {
      minScore = score;
      minSubject = subject;
    };
  };

  std::cout << "\n--- 统计结果 ---" << std::endl;
  std::cout << "科目数：" << scores.size() << std::endl;
  std::cout << "总分：" << total << std::endl;
  std::cout << "平均分：" << (double)total / scores.size() << std::endl;
  std::cout << "最高分：" << maxSubject << " " << maxScore << "分" << std::endl;
  std::cout << "最低分：" << minSubject << " " << minScore << "分" << std::endl;

  return 0;
}