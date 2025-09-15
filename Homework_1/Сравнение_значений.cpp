#include <iostream>
#include <iomanip>
#include <cstring>

template <typename T, typename U>
bool isEqual(T value_1, U value_2) {
    return value_1 == value_2;
}

bool isEqual(const char* value_1, const char* value_2) {
    return strcmp(value_1, value_2) == 0;
}

int main() {
    std::cout << std::boolalpha << isEqual(12, 1) << "\n";
    std::cout << std::boolalpha << isEqual(12.2, 12.2) << "\n";
    std::cout << std::boolalpha << isEqual(10, 'A') << "\n";
    std::cout << std::boolalpha << isEqual("C++", "C++") << "\n";
    std::cout << std::boolalpha << isEqual("C++", "C#") << "\n";
    return 0;
}
