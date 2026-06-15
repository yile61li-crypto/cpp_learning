#include <iostream>
#include <string>

template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
void printArray(const T arr[], int size) {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i < size - 1) std::cout << "，";
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T1, typename T2>
class MyPair {
public:
    T1 first;
    T2 second;

    MyPair(T1 f, T2 s) : first(f), second(s) {}

    void display() const {
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }
};

int main() {
    std::cout << "max(3, 7) = " << myMax(3, 7) << std::endl;
    std::cout << "max(3.14, 2.71) = " << myMax(3.14, 2.71) << std::endl;
    std::cout << "max(\"apple\", \"banana\") = " << myMax(std::string("apple"), std::string("banana")) << std::endl;

    int intArr[] = {1, 2, 3, 4, 5};
    double dblArr[] = {1.1, 2.2, 3.3};
    std::cout << "\n整数数组：";
    printArray(intArr, 5);
    std::cout << "浮点数组：";
    printArray(dblArr, 3);

    int a = 10, b = 20;
    std::cout << "\n交换前： a=" << a << "，b=" << b << std::endl;

    mySwap(a, b);
    std::cout << "交换机：a=" << a << "，b" << b << std::endl;

    MyPair<std::string, int> student("张三", 20);
    std::cout << "\n学生信息";
    student.display();

    return 0;
}