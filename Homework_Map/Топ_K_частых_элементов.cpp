#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> topKFrequent(const std::vector<int>& vec, int k) {
    std::map<int, int> freq{};
    for(int el : vec) {
        freq[el]++;
    }
    std::vector<std::pair<int, int>> sortedVec(freq.begin(), freq.end());
    std::sort(sortedVec.begin(), sortedVec.end(), [](const auto& a, const auto& b) {return a.second > b.second;});
    std::vector<int> result;
    for(int i = 0; i < k && i < sortedVec.size(); ++i) {
        result.push_back(sortedVec[i].first);
    }
    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    auto result = topKFrequent(nums, 2);
    for(int el : result) {
        std::cout << el << " ";
    }
    return 0;
}
