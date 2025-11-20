#include <iostream>
#include <vector>
#include <map>

std::map<int, int> countFrequency(const std::vector<int>& vec) {
    std::map<int, int> result{};
    for(int el : vec) {
        result[el]++;
    }
    return result;
}

int main() {
    std::vector<int> nums = {4, 2, 3, 4, 2, 3, 4, 3, 1, 4};
    auto result = countFrequency(nums);
    for(const auto& [key, val] : result) {
        std::cout << key << ':' << val << '\n';
    }
    return 0;
}