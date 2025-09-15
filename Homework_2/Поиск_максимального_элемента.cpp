#include <iostream>

template <typename T>
auto findMax(T arg) {
 return arg;
}

template <typename T, typename... Rest>
auto findMax(T first, Rest... rest) {
 T maxValue = first;
 T max = findMax(rest...);
 if (first <= max) {
  maxValue = max;
 }
 return maxValue;
}

int main() {
 std::cout << findMax(1, 2, 7, 4) << std::endl;
 std::cout << findMax(1.4, 2.3, 3.8, 4.78, 9.2) << std::endl;
 return 0;
}
