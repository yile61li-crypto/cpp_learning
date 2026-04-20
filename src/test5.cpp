#include<iostream>
using namespace std;

int main() {
    int x = 10, y = 5;
    cout << boolalpha;
    
    cout << "x > y: " << (x > y) << endl;
    cout << "x == 10: " << (x == 10) << endl;
    cout << "x != y: " << (x != y) << endl;
    cout << "\nx > 0 && y > 0: " << (x > 0 && y > 0) << endl;
    cout << "x > 20 || y < 10: " << (x > 20 || y < 10) << endl;
    cout << "!(x < y):" << !(x < y) << endl;
    
    int a =12, b = 10;
    cout << "\na = " << a << "（二进制：1100）" << endl;
    cout << "b = " << b << "（二进制：1010）" << endl;
    cout << "a & b = " << (a & b) << "（按位与）" << endl;
    cout << "a | b = " << (a | b) << "（按位或）" << endl;
    cout << "a ^ b = " << (a ^ b) << "（按位异或）" << endl;
    cout << "a << 1 = " << (a << 1) << "（左移1位）" << endl;

    return 0;
}
