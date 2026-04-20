#include <iostream>
using namespace std;

int main(){
    int age = 20;
    double height = 1.75;
    char grade = 'A';
    bool isStudent = true;
    string name = "张三";

    cout << "姓名:" << name << endl;
    cout << "年龄:" << age << endl;
    cout << "身高:" << height << endl;
    cout << "等级:" << grade << endl;
    cout << "是学生:" << boolalpha << isStudent << endl;

    cout << "\n各数据类型大小:" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "bool: " << sizeof(bool) << " bytes" << endl;
    cout << "string: " << sizeof(string) << " bytes" << endl;

    auto x = 42;
    auto y = 3.14;
    auto z = "hello";
    cout << "\nauto推断: x=" << x << ", y=" << y << ", z=" << z << endl;
    
    return 0;
}