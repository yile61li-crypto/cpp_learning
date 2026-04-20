#include <iostream>
#include <string>

std::string gradeLevel(int score) {
    if (score < 0 || score > 100) return "无效分数";
    
    switch (score / 10) {
        case 10:
        case 9:
            return "优秀";
        case 8:
            return "良好";
        case 7:
            return "中等";
        case 6:
            return "及格";
        default:
            return "不及格";
    }
}

int main() {
    int scores[] = {95, 85, 75, 65,55, 100};

    for (int score : scores) {
        std::cout << score << "分：" << gradeLevel(score) << std::endl;
    }

    std::cout << "\n--- 菜单示例 ---" << std::endl;
    char choice = 'B';
    switch (choice) {
        case 'A':
            std::cout << "选择了选项A" << std::endl;
            break;
        case 'B':
            std::cout << "选择了选项B" << std::endl;
            break;
        case 'c':
            std::cout << "选择了选项C" << std::endl;
            break;
        default:
            std::cout << "无效选项" << std::endl;
    }

    return 0;
}