#include <iostream>
#include <vector>
#include <set>

std::vector<int> removeDuplicates(const std::vector<int>& nums) {
    std::set<int> st;
    std::vector<int> res;

    for (int x : nums) st.insert(x);
    for (int x : st) res.push_back(x);

    return res;
}

int main() {
    std::vector<int> nums = {4, 2, 5, 2, 3, 4, 1};
    auto result = removeDuplicates(nums);
    for (int x : result) {
        std::cout << x << " ";
    }
}
