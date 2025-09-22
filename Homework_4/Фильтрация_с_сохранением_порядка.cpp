#include <iostream>
#include <vector>

template <typename T, typename F>
std::vector<T> filterVector(std::vector<T> vec, F func) {
    std::vector<T> result;
    for(T x : vec) {
        if(func(x)) {
            result.push_back(x);
        }
    }
    return result;
}

bool isEven(int x) { return x % 2 == 0; }

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> filtered = filterVector(vec, isEven);
    for(int x : filtered) {
        std::cout << x << " ";
    }
  return 0;
}
