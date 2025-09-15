#include <iostream>

template <typename T, typename U>
auto makePairList(T val_1, U val_2) {
    return std::make_pair(val_1, val_2);
}

template <typename T, typename... Rest>
auto makePairList(T first, Rest... rest) {
    return std::make_pair(first, makePairList(rest...));
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    return os << "{" << p.first << ", " << p.second << "}";
}

int main() {
    auto pair1 = makePairList(5, 'c');
    auto pair2 = makePairList(5, 'c', 4.32);
    auto pair3 = makePairList(1, 2, 3, 4);
    
    std::cout << pair1 << "\n";
    std::cout << pair2 << "\n";
    std::cout << pair3 << "\n";
    return 0;
}
