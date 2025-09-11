#include <iostream>

template <typename T, int N>
class FixedArray {
public:
    T arr[N];

    void set(int index, T value) {
        arr[index] = value;
    }
    T get(int index) {
        return arr[index];
    }
    int size() {
        return N;
    }
};

int main() {
    FixedArray<int, 3> arr_int = {1, 2, 3};
    FixedArray<double, 4> arr_double = {1.2, 2.0, 3.4, 23.89};
    FixedArray<std::string, 2> arr_str = {"Hi", "AAA"};

    for(int i = 0; i < 3; i++) {
        std::cout << arr_int.get(i) << std::endl;
    }
    for(int i = 0; i < 4; i++) {
        std::cout << arr_double.get(i) << std::endl;
    }
    for(int i = 0; i < 2; i++) {
        std::cout << arr_str.get(i) << std::endl;
    }
    return 0;
}

