#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class Student {
public:
  std::string name;
  int age;
  double score;

  Student(const std::string &name, int age, double score)
      : name(name), age(age), score(score) {}

  void display() const {
    std::cout << " 姓名：" << std::setw(6) << std::left << name << " 年龄："
              << std::setw(3) << age << " 成绩：" << std::fixed
              << std::setprecision(1) << score << std::endl;
  }
};

class StudentManager {
  std::vector<Student> students;

public:
  void addStudent(const std::string &name, int age, double score) {
    students.emplace_back(name, age, score);
    std::cout << "添加成功！" << std::endl;
  }

  void listAll() const {
    if (students.empty()) {
      std::cout << "暂无学生数据！" << std::endl;
      return;
    }
    std::cout << "--- 学生列表 ---" << std::endl;
    for (std::size_t i = 0; i < students.size(); i++) {
      std::cout << "[" << i + 1 << "] ";
      students[i].display();
    }
  }

  void findByName(const std::string &name) const {
    bool found = false;
    for (const auto &s : students) {
      if (s.name == name) {
        s.display();
        found = true;
      }
    }
    if (!found)
      std::cout << "未找到学生：" << name << std::endl;
  }

  void sortByScore() {
    std::sort(
        students.begin(), students.end(),
        [](const Student &a, const Student &b) { return a.score > b.score; });
    std::cout << "已按成绩降序排序！" << std::endl;
  }

  void showStatistics() const {
    if (students.empty()) {
      std::cout << "暂无数据！" << std::endl;
      return;
    }
    double total = 0;
    double maxScore = students[0].score;
    double minScore = students[0].score;
    std::string topName, bottomName;

    for (const auto &s : students) {
      total += s.score;
      if (s.score > maxScore) {
        maxScore = s.score;
        topName = s.name;
      }
      if (s.score < minScore) {
        minScore = s.score;
        bottomName = s.name;
      }
    }
    if (topName.empty()) topName= students[0].name;
    if (bottomName.empty()) bottomName = students[0].name;

    std::cout << "--- 统计信息 ---" << std::endl;
    std::cout << "学生总数：" << students.size() << std::endl;
    std::cout << "平均成绩：" << std::fixed << std::setprecision(1) << total / students.size() << std::endl;
    std::cout << "最高分：" << topName << " " << maxScore << std::endl;
    std::cout << "最低分：" << bottomName << " " << minScore << std::endl;
  }

  void run() {
    addStudent("张三", 20, 85);
    addStudent("李四", 21, 92);
    addStudent("王五", 19, 78);

    std::cout << "\n=== 学生成绩管理系统 ===" << std::endl;
    int choice;
    do {
        std::cout << "\n1.查看全部 2.添加 3.查找 4.排序 5.统计 0.退出" << std::endl;
        std::cout << "请选择：";
        std::cin >> choice;

        switch (choice) {
            case 1: listAll(); break;
            case 2: {
                std::string name; int age; double score;
                std::cout << "姓名："; std::cin >> name;
                std::cout << "年龄："; std::cin >> age;
                std::cout << "成绩："; std::cin >> score;
                addStudent(name, age, score);
                break;
            }
            case 3: {
                std::string name;
                std::cout << "输入姓名："; std::cin >> name;
                findByName(name);
                break;
            }
            case 4: sortByScore(); listAll(); break;
            case 5: showStatistics(); break;
            case 0: std::cout << "再见！" << std::endl; break;
            default: std::cout << "无效选择！" << std::endl;
        }
    } while (choice != 0);
  }
};

int main() {
    StudentManager manager;
    manager.run();
    return 0;
}