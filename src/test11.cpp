#include <iostream>
#include <iomanip>

int main() {
    std::cout << "九九乘法表：" << std::endl;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j << 'x' << i << "=" << std::setw(2) << i * j << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n三角形：" << std::endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << "\n矩阵元素：" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}