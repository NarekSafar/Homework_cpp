#include <iostream>
#include <array>

template <typename T, int N>
void shiftLeft(std::array<T, N>& arr, int shift) {
    int size = arr.size();
    if(shift >= size) {
        shift %= size;
    }
    for(int i = 0; i < shift; ++i) {
        T first = arr[0];
        for(int j = 0; j < size - 1; ++j) {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = first;
    }
}

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    shiftLeft<int, 5>(arr, 2);
    for(int x : arr) {
        std::cout << x << " "; 
    }
    return 0;
}
