#include <iostream>
#include <stdexcept>
#include <string>


class InsufficientFundsError : public std::runtime_error {
  double balance, amount;

public:
  InsufficientFundsError(double balance, double amount)
      : std::runtime_error("余额不足：余额" + std::to_string(balance) +
                           "，尝试取出" + std::to_string(amount)),
        balance(balance), amount(amount) {}

  double getBalance() const { return balance; }
  double getAmount() const { return amount; }
};

class InvalidAmountError : public std::runtime_error {
public:
  InvalidAmountError(double amount)
      : std::runtime_error("无效金额：" + std::to_string(amount)) {}
};

class BankAccount {
  double balance;

public:
  BankAccount(double balance = 0) : balance(balance) {}

  void deposit(double amount) {
    if (amount <= 0)
      throw InvalidAmountError(amount);
    balance += amount;
    std::cout << "存入" << amount << "，余额：" << balance << std::endl;
  }

  void withdraw(double amount) {
    if (amount <= 0)
      throw InvalidAmountError(amount);
    if (amount > balance)
      throw InsufficientFundsError(balance, amount);
    balance -= amount;
    std::cout << "取出" << amount << "，余额：" << balance << std::endl;
  }

  double getBalance() const { return balance; }
};

int main() {
  BankAccount account(1000);

  try {
    account.deposit(500);
    account.withdraw(300);
    account.withdraw(2000);
  } catch (const InsufficientFundsError &e) {
    std::cout << "捕获异常：" << e.what() << std::endl;
  }

  try {
    account.deposit(-100);
  } catch (const InvalidAmountError &e) {
    std::cout << "捕获异常：" << e.what() << std::endl;
  }

  return 0;
}