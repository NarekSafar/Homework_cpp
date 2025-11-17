#include <iostream>
#include <set>

int rangeCount(const std::set<int>& nums, int low, int high) {
    int count = 0;
    auto it = nums.lower_bound(low);
    auto end = nums.upper_bound(high);
    for(; it != end; ++it) count++;
    return count;
}


int main() {
    std::set<int> s = {1, 3, 5, 7, 9, 11, 13, 15};
    std::cout << rangeCount(s, 5, 11) << '\n';   
    return 0;
}