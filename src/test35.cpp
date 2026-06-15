#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void applyToAll(std::vector<int>& vec, std::function<void(int&)> func) {
    for (auto& val : vec) {
        func(val);
    }
}

int main() {
    auto greet = []() {std::cout << "Hello, Lambda!" << std::endl; };
    greet();

    auto add = [](int a, int b) { return a + b; };
    std::cout << "3 + 5 = " << add(3, 5) << std::endl;

    int factor = 3;
    auto multiply = [factor](int x) { return x * factor; };
    std::cout << "5 x " << factor << " = " << multiply(5) << std::endl;

    int counter = 0;
    auto increment = [&counter]() { counter++; };
    increment();
    increment();
    increment();
    std::cout << "计数器：" << counter << std::endl;

    std::vector<int> nums = {5, 2, 8, 1, 9, 3, 7};

    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    std::cout << "\n降序排列：";
    for (int n : nums) std::cout << n << " ";
    std::cout << std::endl;

    std::vector<int> source = {1, 2, 3, 4, 5, 6, 7, 8,  9, 10};
    std::vector<int> evens;
    std::copy_if(source.begin(), source.end(), std::back_inserter(evens), [](int n) { return n % 2 == 0; });
    std::cout << "偶数：";
    for (int n : evens) std::cout << n << " ";
    std::cout << std::endl;

    std::vector<int> data = {1, 2, 3, 4, 5};
    applyToAll(data, [](int& val) { val *= 2; });
    std::cout << "翻倍后：";
    for (int n : data) std::cout << n << " ";
    std::cout << std::endl;

    return 0;

}