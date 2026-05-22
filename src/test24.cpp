#include <iostream>
#include <queue>
#include <stack>
#include <string>


int main() {
  std::string text = "Hello";
  std::stack<char> charStack;

  for (char c : text) {
    charStack.push(c);
  }

  std::string reversed = "";
  while (!charStack.empty()) {
    reversed += charStack.top();
    charStack.pop();
  }
  std::cout << "原字符串：" << text << std::endl;
  std::cout << "反转后：" << reversed << std::endl;

  std::queue<std::string> line;
  line.push("张三");
  line.push("李四");
  line.push("王五");

  std::cout << "\n--- 模拟排队 ---" << std::endl;
  std::cout << "队伍中有" << line.size() << "人" << std::endl;
  while (!line.empty()) {
    std::cout << line.front() << " 办理完成，离开" << std::endl;
    line.pop();
  }
  std::priority_queue<std::pair<int, std::string>> tasks;
  tasks.push({3, "普通任务"});
  tasks.push({5, "紧急任务"});
  tasks.push({1, "低优先级任务"});
  tasks.push({4, "重要任务"});

  std::cout << "\n--- 按优先级处理任务 ---" << std::endl;
  while (!tasks.empty()) {
    auto [priority, task] = tasks.top();
    std::cout << "[优先级" << priority << "]" << task << std::endl;
    tasks.pop();
  }
  return 0;
}