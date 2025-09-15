#include <iostream>

template <typename T>
void print(const T& elem) {
  std::cout << elem << std::endl;
}

int main() {
  print<double>(11.3);
  print<std::string>("Hello World!");
  print<int>(5);
  return 0;
}
