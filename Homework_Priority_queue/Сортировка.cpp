#include <iostream>
#include <vector>
#include <queue>

std::vector<int> heapSort(const std::vector<int>& vec) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::vector<int> result;
    for(int el : vec) pq.push(el);
    while(!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}

int main() {
    std::vector<int> nums = {4, 2, 8, 1, 9, 3};
    auto result = heapSort(nums);
    for(int el : result) std::cout << el << ' ';
    return 0;
}