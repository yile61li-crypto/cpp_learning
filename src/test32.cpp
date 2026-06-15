#include <fstream>
#include <iostream>
#include <iterator>
#include <string>


int main() {
  std::string filename = "test.txt";

  std::ofstream outFile(filename);
  if (outFile.is_open()) {
    outFile << "Hello, C++!" << std::endl;
    outFile << "这是第二行" << std::endl;
    outFile << "文件读写练习" << std::endl;
    outFile.close();
    std::cout << "写入完成！" << std::endl;
  }

  std::ifstream inFile(filename);
  if (inFile.is_open()) {
    std::string content((std::istreambuf_iterator<char>(inFile)),
                        std::istreambuf_iterator<char>());
    std::cout << "\n文件内容：" << std::endl;
    std::cout << content << std::endl;
    inFile.close();
  }

  std::ifstream lineFile(filename);
  if (lineFile.is_open()) {
    std::string line;
    std::cout << "逐行读取：" << std::endl;
    while (std::getline(lineFile, line)) {
      std::cout << " 行：" << line << std::endl;
    }
    lineFile.close();
  }

  std::ofstream appendFile(filename, std::ios::app);
  if (appendFile.is_open()) {
    appendFile << "这是追加的内容" << std::endl;
    appendFile.close();
    std::cout << "\n追加完成！" << std::endl;
  }

  std::ifstream verifyRile(filename);
  if (verifyRile.is_open()) {
    std::string line;
    std::cout << "\n追加后的文件：" << std::endl;
    while (std::getline(verifyRile, line)) {
      std::cout << " " << line << std::endl;
    }
    verifyRile.close();
  }

  return 0;
}