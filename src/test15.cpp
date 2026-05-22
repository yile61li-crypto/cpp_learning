#include <iostream>

void increment(int &value) { value++; }

void doubleValue(int *ptr) {
  if (ptr != nullptr) {
    *ptr *= 2;
  }
}

int main() {
  int x = 42;
  int *ptr = &x;

  std::cout << "x的值：" << x << std::endl;
  std::cout << "x的地址：" << &x << std::endl;
  std::cout << "ptr的值（地址）：" << ptr << std::endl;
  std::cout << "ptr指向的值：" << *ptr << std::endl;

  *ptr = 100;
  std::cout << "修改后x的值：" << x << std::endl;

  int &ref = x;
  ref = 200;
  std::cout << "\n通过引用修改后x的值：" << x << std::endl;

  int num = 10;
  std::cout << "\n函数调用前：" << num << std::endl;
  increment(num);
  std::cout << "increment后：" << num << std::endl;
  doubleValue(&num);
  std::cout << "doubleValue后：" << num << std::endl;

  int arr[] = {10, 20, 30, 40, 50};
  int *arrPtr = arr;
  std::cout << "\n指针遍历数组：";
  for (int i = 0; i < 5; i++) {
    std::cout << *(arrPtr + i) << " ";
  }
  std::cout << std::endl;

  int *dynArr = new int[3]{1, 2, 3};
  std::cout << "\n动态数组：";
  for (int i = 0; i < 3; i++) {
    std::cout << dynArr[i] << " ";
  }
  std::cout << std::endl;
  delete[] dynArr;

  return 0;
}