#include <iostream>
#include <array>

template <typename T, int N>
bool compareArrays(std::array<T, N> arr_1, std::array<T, N> arr_2) {
    for(int i = 0; i < N; ++i) {
        if(arr_1[i] != arr_2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::array<int, 3> arr_1 = {1, 2, 4};
    std::array<int, 3> arr_2 = {1, 2, 3};
    std::cout << std::boolalpha << compareArrays<int, 3>(arr_1, arr_2);
    return 0;
}