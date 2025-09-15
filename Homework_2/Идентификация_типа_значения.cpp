#include <iostream>

template <typename T>
void betterPrint(T& val) {
    std::cout << val << " [lvalue]" << "\n";   
}

template <typename T>
void betterPrint(T&& val) {
    std::cout << val << " [rvalue]" << "\n";   
}

template <typename T, typename... Rest>
void betterPrint(T&& first, Rest&&... rest) {
    betterPrint(std::forward<T>(first));
    betterPrint(std::forward<Rest>(rest)...);
}

int main() {
    int x = 42;
    betterPrint(x, 100, "hello");
    return 0;
}
