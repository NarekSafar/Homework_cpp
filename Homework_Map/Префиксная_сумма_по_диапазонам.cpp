#include <iostream>
#include <map>
#include <vector>

int rangeSumMap(const std::map<int, int>& mp, int left, int right) {
    int sum = 0;
    auto l = mp.lower_bound(left);
    auto r = mp.upper_bound(right);
    for(auto it = l; it != r; ++it) {
        sum += it->second;
    }
    return sum;
}

int main() {
   std::map<int, int> m = {{1, 10}, {3, 20}, {5, 30}, {7, 40}};
    std::cout << rangeSumMap(m, 3, 7) << '\n';  
    std::cout << rangeSumMap(m, 2, 4) << '\n';  
    return 0;
}
