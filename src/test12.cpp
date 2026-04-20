#include <iostream>
#include <string>
#include <cmath>

void greet() {
    std::cout << "Hello, World!" << std::endl;
}

void greetPerson(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

int add (int a, int b) {
    return a + b;
}

double power (double base, int exponent = 2) {
    return pow(base, exponent);
}

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main () {
    greet();
    greetPerson("Alice");
    std::cout << "5 + 3 = " << add(5, 3) << std::endl;
    std::cout << "2的4次方：" << power(2, 4) << std::endl;
    std::cout << "3的平方：" << power(3) << std::endl;
    
    int x =10, y = 20;
    std::cout << "\n交换前：x = " << x << ", y = " << y << std::endl;
    swapValues(x, y);
    std::cout << "交换后：x = " << x << ", y = " << y << std::endl;

    return 0;
}
