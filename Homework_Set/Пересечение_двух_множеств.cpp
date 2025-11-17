#include <iostream>
#include <vector>
#include <set>

std::vector<int> findIntersection(const std::vector<int>& a, const std::vector<int>& b) {
    std::set<int> st1(a.begin(), a.end());
    std::set<int> st2(b.begin(), b.end());

    std::vector<int> result;

    for (int x : st1) {
        if (st2.count(x)) {
            result.push_back(x);
        }
    }

    return result;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {3, 4, 5, 6, 7};
    auto result = findIntersection(arr1, arr2); 
    for(int x : result) {
        std::cout << x << ' ';
    }
    return 0;
}