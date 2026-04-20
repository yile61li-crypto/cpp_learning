#include <iostream>
using namespace std;

int main() {
    int a = 17;
    int b = 5;
    cout << "a = " << a << ", b= " << b << endl;
    cout << "和：" << a + b << endl;
    cout << "差：" << a - b << endl;
    cout << "积：" << a * b << endl;
    cout << "整数商：" << a / b << endl;
    cout << "浮点商：" << (double)a / b << endl;
    cout << "余数：" << a % b << endl;

    int x = 10;
    cout << "\nx初始值: " << x << endl;
    cout << "前缀++x = " << ++x << endl;
    cout << "后缀x++ = " << x++ << endl;
    cout << "x当前值" << x << endl;
    
    return 0;
}