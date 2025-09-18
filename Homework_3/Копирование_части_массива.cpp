#include <iostream>
#include <array>

template <typename T, int N, int M>
auto copySubArray(const std::array<T, N>& arr, int index, int count) {
    std::array<T, M> copiedSubArray{}; 
    if (index >= 0 && index + count <= N && index < N) {
        for (int i = 0; i < count; ++i) {
            copiedSubArray[i] = arr[index + i];
        }
    }
    return copiedSubArray;
}

int main() {
    std::array<int, 10> source = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto sub = copySubArray<int, 10, 4>(source, 5, 4);
    for (int x : sub) {
        std::cout << x << " ";
    }
    return 0;
}
