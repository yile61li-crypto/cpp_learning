#include <iostream>
#include <string>
using namespace std;

string lifeStage(int age) {
    if (age < 0) {
        return "无效年龄";
    } else if (age <= 12) {
        return "儿童";
    } else if (age <= 18) {
        return "青少年";
    } else if (age <= 35) {
        return "青年";
    } else if (age <= 60) {
        return "中年";
    } else {
        return "老年";
    }
}

int main() {
    int ages[] = {5, 15 ,25, 40, 70, -1};
    
    for (int age : ages) {
        cout << age << "岁：" << lifeStage(age) << endl;
    }

    return 0;
}