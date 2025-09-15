#include <iostream>

int square(int x) {
    return x * x;
}

template <typename F>
void applyAndPrint(F func) { return; }

template <typename F, typename T, typename... Rest>
void applyAndPrint(F func, T first, Rest... rest) {
    std::cout << func(first) << "\n";
    applyAndPrint(func, rest...);
}

int main() {
    applyAndPrint(square, 2, 3, 4, 5);
    return 0;
}
