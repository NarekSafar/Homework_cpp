#include <iostream>
auto sum() {
 return 0;
}

template <typename T, typename... Args>
auto sum(T first, Args... args) {
 return first + sum(args...);
}

int main() {
 std::cout << sum(1, 2, 3, 4) << std::endl;
 std::cout << sum(1.4, 2.3, 3.8, 4.78) << std::endl;
 return 0;
}
