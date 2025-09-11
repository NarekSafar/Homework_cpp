#include <iostream>
#include <iomanip>

template <typename T>
void printValue(T value) {
    std::cout << value << "\n";
}

void printValue(bool value) {
    std::cout << std::boolalpha << value << "\n";
}

void printValue(char* value) {
    std::cout << "[" << value << "]" << "\n";
}

int main() {
    char str[] = "Hi";
    printValue(str);
    printValue(true);
    printValue(3);
    printValue(12.34);
    return 0;
}
