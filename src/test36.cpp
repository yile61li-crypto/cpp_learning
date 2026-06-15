#include <iostream>
#include <vector>
#include <map>
#include <tuple>

auto getStudentInfo() {
    return std::make_tuple("张三", 20, 95.5);
}

int main() {
    auto intVal = 42;
    auto doubleVal = 3.14;
    auto strVal = std::string("hello");
    std::cout << "int：" << intVal << std::endl;
    std::cout << "double：" << doubleVal << std::endl;
    std::cout << "string：" << strVal << std::endl;

    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::cout << "\nauto迭代器遍历：";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "值遍历：";
    for (auto val : nums) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "引用修改：";
    for (auto& val : nums) val *= 10;
    for (auto val : nums) std::cout << val << " ";
    std::cout << std::endl;

    std::map<std::string, int> scores = {{"语文", 88}, {"数学", 95}, {"英语", 82}};
    std::cout << "\n成绩表：" << std::endl;
    for (const auto& [subject, score] : scores) {
        std::cout << " " << subject << "：" << score << "分" << std::endl;
    }

    auto [name, age, grade] = getStudentInfo();
    std::cout << "\n学生信息：" << name << "，" << age << "岁，" << grade << "分" << std::endl;

    int x = 10;
    decltype(x) y = 20;
    std::cout << "\ndecltype推断：y = " << y << std::endl;

    auto lambda = [](auto a, auto b) { return a + b; };
    std::cout << "泛型Lambda：" << lambda(3, 4) << "，" << lambda(1.5, 2.5) << std::endl;

    return 0;
}
