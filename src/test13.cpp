#include <iostream>
#include <string>
#include <vector>

void print(int value) {
    std::cout << "整数" << value << std::endl;
}

void print(double value) {
    std::cout << "浮点数" << value << std::endl;
}

void print(const std::string& value) {
    std::cout << "字符串" << value << std::endl;
}

void print(const std::vector<int>& vec) {
    std::cout << "向量：[";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size() -1) std::cout << "，";
    }
    std::cout << "]" << std::endl;
}

int calculate(int a, int b) {
    std::cout << "调用两参数版本；";
    return a + b;
}

int calculate(int a, int b, int c) {
    std::cout << "调用三参数版本；";
    return a + b + c;
}

int main() {
    print(42);
    print(3.14);
    print(std::string("Hello, C++"));
    print(std::vector<int>{1, 2, 3, 4, 5});

    std::cout << "\n" << calculate(3, 5) << std::endl;
    std::cout << calculate(1, 2, 3) << std::endl;

    return 0;
}