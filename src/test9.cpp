#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> fruits = {"apple", "banana", "orange"};
    std::cout << "fruits_list:" << std::endl;
    for (const std::string& fruit : fruits) {
        std::cout << "  - "<< fruit << std::endl;
    }
    
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    std::cout << "\n1-100的和: " << sum << std::endl;
    
    std::string text = "C++";
    std::cout << "\n字符串'" << text << "'的字符：";
    for (char c : text) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    std::cout << "\n跳过3，在7处停止：";
    for (int i =1; i <= 10 ; i++) {
        if (i ==3) continue;
        if (i == 7) break;
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}