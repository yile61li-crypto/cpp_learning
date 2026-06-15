#include <iostream>
#include <stdexcept>
#include <string>
#include <random>
#include <algorithm>

class PasswordGenerator {
    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string digits = "0123456789";
    std::string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    std::mt19937 rng;

    char randomChar(const std::string& charser) {
        std::uniform_int_distribution<int> dist(0, charser.size() - 1);
        return charser[dist(rng)];
    }

public:
    PasswordGenerator() : rng(std::random_device{}()) {}

    std::string generatePassword(int length = 12) {
        if (length < 4) {
            throw std::invalid_argument("密码长度至少为4位");
        }

        std::string password;
        password += randomChar(lowercase);
        password += randomChar(uppercase);
        password += randomChar(digits);
        password += randomChar(symbols);

        std::string allchars = lowercase + uppercase + digits + symbols;
        for (int i = 4; i < length; i++) {
            password += randomChar(allchars);
        }

        shuffle(password.begin(),  password.end(), rng);
        return password;
    }

    std::string checkStrength(const std::string& password) const {
        int score = 0;
        if (password.length() >= 8) score++;
        if (std::any_of(password.begin(), password.end(), ::islower)) score++;
        if (std::any_of(password.begin(), password.end(), ::isupper)) score++;
        if (std::any_of(password.begin(), password.end(), ::isdigit)) score++;
        if (std::any_of(password.begin(), password.end(), [this](char c) { return symbols.find(c) != std::string::npos; })) score++;

        if (score >= 4) return "强";
        if (score >= 3) return "中等";
        return "弱";
    }
};

int main() {
    PasswordGenerator gen;

    std::cout << "生成5个密码：" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::string pwd = gen.generatePassword(16);
        std::string strength = gen.checkStrength(pwd);
        std::cout << i + 1 << ". " << pwd << " （强度：" << strength << "）" << std::endl;
    }
    std::cout << "\n不同长度的密码：" << std::endl;
    for (int len : {8, 12, 16, 20}) {
        std::string pwd = gen.generatePassword(len);
        std::cout << "长度" << len << "：" << pwd << std::endl;
    }

    return 0;
}