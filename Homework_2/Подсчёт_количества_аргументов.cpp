#include <iostream>

int countArgs() {
 return 0;
}

template <typename T, typename... Rest>
int countArgs(T first, Rest... rest) {
 return countArgs(rest...) + 1;
}

int main() {
 std::cout << countArgs(1, 2, 3, 4, 5, 6, 7 ,87) << std::endl;
 std::cout << countArgs("A", "B", 1, 5, 6, 9.0) << std::endl;
 return 0;
}
