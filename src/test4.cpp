#include <iostream>
#include <string>
using namespace std;

int main() {
    int intVal = 42;
    double doubleVal = intVal;
    cout << "隐式类型转换: int " << intVal << " -> double " << doubleVal << endl;
    
    double pi = 3.14159;
    int truncated = static_cast<int>(pi);
    int cStyle = (int)pi;
    cout << "static_cast: " << pi << " -> " << truncated << endl;
    cout << "C风格转换: " << pi << " -> " << cStyle << endl;

    char ch = 'A';
    int ascii = static_cast<int>(ch);
    cout << "\n字符'" << ch << "' 的ASCII码: " << ascii << endl;

    string strNum = "123";
    int intNum = stoi(strNum);
    double dblNum = stod("3.14");
    string backToStr = to_string(intNum);

    cout << "\n字符串\"" << strNum << "\" 转换为整数: " << intNum << endl;
    cout << "字符串\"3.14\" 转换为双精度浮点数: " << dblNum << endl;
    cout << "整数" << intNum << " 转换为字符串: \"" << backToStr << "\"" << endl;
    cout << "平方: " << intNum * intNum << endl;
    
    return 0;
}