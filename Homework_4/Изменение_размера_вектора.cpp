#include <iostream>
#include <vector>

template <typename T>
void resizeVector(std::vector<T>& vec, int size, T val) {
    std::cout << "Before resizing: ";
    for(const T& x : vec) {
        std::cout << x << " ";
    }
    vec.resize(size, val);
    std::cout << "\nAfter resizing: ";
    for(const T& x : vec) {
        std::cout << x << " ";
    }
 }

int main() {
    std::vector<int> vec = {1, 2, 3};
    resizeVector(vec, 10, 69);
    return 0;
}
