#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::string filename = "students.csv";

    std::ofstream outFile(filename);
    outFile << "姓名,年龄,成绩" << std::endl;
    outFile << "张三,20,85" << std::endl;
    outFile << "李四,21,92" << std::endl;
    outFile << "王五,19,78" << std::endl;
    outFile.close();
    std::cout << "CSV文件已创建" << std::endl;

    std::ifstream inFile(filename);
    std::string line;

    std::getline(inFile, line);
    std::cout << "\n表头：" << line << std::endl;

    std::cout << "\n学生数据：" << std::endl;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string name, ageStr, scoreStr;
        
        std::getline(ss, name, ',');
        std::getline(ss, ageStr, ',');
        std::getline(ss, scoreStr, ',');

        int age = std::stoi(ageStr);
        int score = std::stoi(scoreStr);

        std::cout << " 姓名：" << name
                  << "，年龄：" << age
                  << "，成绩：" << score << "分" << std::endl;
    }
    inFile.close();

    std::ifstream calcFile(filename);
    std::getline(calcFile, line);
    int total = 0, count = 0;
    while (std::getline(calcFile, line)) {
        std::stringstream ss(line);
        std::string field;
        std::getline(ss, field, ',');
        std::getline(ss, field, ',');
        std::getline(ss, field, ',');
        total += std::stoi(field);
        count++;
    }
    std::cout << "\n平均成绩：" << (double)total / count << "分" << std::endl;
    calcFile.close();

    return 0;
}