#include <iostream>
#include <memory>
#include <string>
#include <vector>


class Animal {
protected:
  std::string name;

public:
  Animal(const std::string &name) : name(name) {}
  virtual ~Animal() {}

  virtual std::string makeSound() const = 0;

  std::string eat() const { return name + "正在吃东西"; }

  std::string getName() const { return name; }
};

class Dog : public Animal {
public:
  Dog(const std::string &name) : Animal(name) {}

  std::string makeSound() const override { return "汪汪！"; }

  std::string fetchBall() const { return name + "在捡球"; }
};

class Cat : public Animal {
public:
  Cat(const std::string &name) : Animal(name) {}

  std::string makeSound() const override { return "喵喵！"; }

  std::string climbTree() const { return name + "在爬树"; }
};

int main() {
  std::vector<std::unique_ptr<Animal>> animals;
  animals.push_back(std::make_unique<Dog>("旺财"));
  animals.push_back(std::make_unique<Cat>("咪咪"));

  for (const auto &animal : animals) {
    std::cout << animal->getName() << "说：" << animal->makeSound()
              << std::endl;
    std::cout << animal->eat() << std::endl;
  }

  Dog dog("小黑");
  std::cout << "\n" << dog.fetchBall() << std::endl;

  Cat cat("小白");
  std::cout << cat.climbTree() << std::endl;

  return 0;
}