#include <iostream>

template <typename T>
void mySwap(T& a, T& b) {
  T tmp = std::move(a);
  a = std::move(b);
  b = std::move(tmp);
}

int main() {
  int x = 10, y = 7;
  double a = 7.11, b = 2.17;
  std::string c = "Hello", d = "World!";
  mySwap(x, y);
  mySwap(a, b);
  mySwap(c, d);
  std::cout << x << " " << y << std::endl;
  std::cout << a << " " << b << std::endl;
  std::cout << c << " " << d << std::endl;
  return 0;
}

