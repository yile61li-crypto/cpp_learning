#include <iostream>

int main() {
    int count = 1;
    std::cout << "计算器：" << std::endl;
    while (count <= 5) {
        std::cout << "  计数：" << count << std::endl;
        count++;
    }

    int total = 0, num = 1;
    while (num <= 10) {
        total += num;
        num++;
    }
    std::cout << "1-10的和：" << total << std::endl;

    int answer = 7;
    int guesses[] = {3, 5, 8, 7};
    int index = 0;
    int guess;

    std::cout << "\n--- 猜数字游戏 ---" << std::endl;
    do {
        guess = guesses[index++];
        std::cout << " -> 猜测：" << guess;
        if (guess < answer) {
            std::cout << " -> 太小了！" << std::endl;
        } else if (guess > answer) {
            std::cout << " -> 太大了！" << std::endl;
        } else {
            std::cout << " ->猜对了!" << std::endl;
        }
    } while (guess != answer);
    std::cout << "共猜了 " << index << " 次" << std::endl;
    
    return 0;
}
