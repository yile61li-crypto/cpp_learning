#include <cmath>
#include <ios>
#include <iostream>

class Vector2D {
private:
  double x, y;

public:
  Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

  Vector2D operator+(const Vector2D &other) const {
    return Vector2D(x + other.x, y + other.y);
  }

  Vector2D operator-(const Vector2D &other) const {
    return Vector2D(x - other.x, y - other.y);
  }

  bool operator==(const Vector2D &other) const {
    return x == other.x && y == other.y;
  }

  double &operator[](int index) {
    if (index == 0)
      return x;
    return y;
  }

  double magnitude() const { return sqrt(x * x + y * y); }

  friend std::ostream &operator<<(std::ostream &os, const Vector2D &v) {
    os << "Vector2D(" << v.x << "，" << v.y << ")";
    return os;
  }
};

int main() {
  Vector2D v1(3, 4);
  Vector2D v2(1, 2);

  std::cout << "v1：" << v1 << std::endl;
  std::cout << "v2：" << v2 << std::endl;

  Vector2D v3 = v1 + v2;
  std::cout << "v1 + v2：" << v3 << std::endl;

  std::cout << "v1 - v2：" << (v1 - v2) << std::endl;

  Vector2D v4(3, 4);
  std::cout << "\nv1 == v4：" << std::boolalpha << (v1 == v4) << std::endl;
  std::cout << "v1 == v2：" << (v1 == v2) << std::endl;

  std::cout << "\nv1[0] = " << v1[0] << std::endl;
  std::cout << "v1[1] = " << v1[1] << std::endl;

  std::cout << "\nv1的模长：" << v1.magnitude() << std::endl;

  return 0;
}
