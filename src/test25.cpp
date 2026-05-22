#include <iostream>
#include <string>

class Person {
private:
  std::string name;
  int age;

public:
  Person(const std::string &name, int age) : name(name), age(age) {
    std::cout << "创建对象：" << name << std::endl;
  };

  ~Person() { std::cout << "销毁对象：" << name << std::endl; };

  std::string introduce() {
    return "我叫" + name + "，今年" + std::to_string(age) + "岁";
  };

  void celebrateBirthday() {
    age++;
    std::cout << "生日快乐！" << name << "现在" << age << "岁了" << std::endl;
  };

  std::string getName() { return name; }
  int getAge() { return age; }
};

int main() {
  Person p1("张三", 25);
  Person p2("李四", 30);

  std::cout << "\n" << p1.introduce() << std::endl;
  std::cout << p2.introduce() << std::endl;

  std::cout << std::endl;
  p1.celebrateBirthday();
  std::cout << p1.introduce() << std::endl;

  std::cout << std::endl;

  return 0;
}
