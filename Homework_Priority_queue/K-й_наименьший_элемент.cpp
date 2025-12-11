#include <iostream>
#include <vector>
#include <queue>

int kthSmallest_max(const std::vector<int>& vec, int k) {
    std::priority_queue<int> pq;
    for(int el : vec) {
        if(pq.size() < k) pq.push(el);
        else if(el < pq.top()) {
            pq.pop();
            pq.push(el);
        }
    }
    return pq.top();
}


int kthSmallest_min(const std::vector<int>& vec, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(vec.begin(), vec.end());
    int n = pq.size();
    for(int i = 0; i < k - 1; ++i) pq.pop();
    return pq.top();
}

int main() {
    std::vector<int> nums = {7, 10, 4, 3, 20, 15, -1, 8};
    int k = 3;
    std::cout << kthSmallest_max(nums, k) << '\n';
    std::cout << kthSmallest_min(nums, k) << '\n';
    return 0;
}