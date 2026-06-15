#include <iostream>
#include <limits>

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }

double divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("除数不能为零");
    }
    return a / b;
}

int main() {
    std::cout << "=== 简单计算器 ===" << std::endl;

    char continueCalc;
    do {
        double num1, num2;
        char op;

        std::cout << "\n请输入表达式（如 10 + 5）：";
        if (!(std::cin >> num1 >> op >> num2)) {
            std::cout << "输入格式错误，请重新输入！" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        double result;
        bool valid = true;

        try {
            switch (op) {
                case '+':
                    result = add(num1, num2);
                    break;
                case '-':
                    result = subtract(num1, num2);
                    break;
                case '*':
                    result = multiply(num1, num2);
                    break;
                case '/':
                    result = divide(num1, num2);
                    break;
                default:
                    std::cout << "不支持的运算符！" << std::endl;
                    valid = false;
                    break;
            }
        }
        catch (const std::exception& e) {
            std::cout << "计算错误: " << e.what() << std::endl;
            valid = false;
        }

        if (valid) {
            std::cout << "结果: " << result << std::endl;
        }

        std::cout << "是否继续计算？(y/n): ";
        std::cin >> continueCalc;
    } while (continueCalc == 'y' || continueCalc == 'Y');

    std::cout << "感谢使用计算器！" << std::endl;
    return 0;
}