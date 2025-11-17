#include <iostream>
#include <set>

int removeRange(std::set<int>& nums, int low, int high) {
    int count = 0;
    auto it = nums.lower_bound(low);
    auto end = nums.upper_bound(high);
    while(it != end) {
        it = nums.erase(it);
        count++;
    } 
    return count;
}


int main() {
    std::set s = {1, 3, 5, 7, 9, 11, 13, 15};
    int removed = removeRange(s, 5, 11);
    std::cout << removed << '\n';  
    for(int x : s) {
        std::cout << x << ' ';
    }
    return 0;
}