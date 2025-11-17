#include <iostream>
#include <vector>
#include <set>

int findClosest(const std::set<int>& nums, int target) {
    if (nums.empty()) return -1;

    auto it = nums.lower_bound(target);

    int prevCandidate = -1;
    int nextCandidate = -1;

    if (it != nums.end()) {
        nextCandidate = *it;
    }

    if (it != nums.begin()) {
        auto prevIt = it;
        --prevIt;
        prevCandidate = *prevIt;
    }

    if (nextCandidate == -1) return prevCandidate;
    if (prevCandidate == -1) return nextCandidate;

    int diff1 = std::abs(prevCandidate - target);
    int diff2 = std::abs(nextCandidate - target);

    if (diff1 == diff2) return prevCandidate;
    return diff1 < diff2 ? prevCandidate : nextCandidate;
}


int main() {
    std::set<int> s = {1, 5, 10, 15, 20};
    std::cout << findClosest(s, 12) << '\n';  
    std::cout << findClosest(s, 13) << '\n';   
    return 0;
}