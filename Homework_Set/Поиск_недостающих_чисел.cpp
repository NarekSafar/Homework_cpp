#include <iostream>
#include <vector>
#include <set>

std::vector<int> findMissingNumbers(const std::vector<int>& nums, int N) {
    std::set<int> set(nums.begin(), nums.end());
    std::vector<int> result;

    for (int i = 1; i <= N; ++i) {
        if (!set.count(i)) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    auto result = findMissingNumbers(nums, 6);
    for(int x : result) {
        std::cout << x << ' ';
    }
    return 0;
}