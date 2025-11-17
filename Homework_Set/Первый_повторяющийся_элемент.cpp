#include <iostream>
#include <vector>
#include <set>

int firstRepeating(const std::vector<int>& a) {
    std::set<int> st;
    for(int x : a) {
        if(st.count(x)) {
            return x;
        }
        st.insert(x);
    }
    return -1;
}


int main() {
    std::vector<int> nums = {1, 2, 3, 4, 2, 5, 6, 3};
    std::cout << firstRepeating(nums) << '\n'; 
    return 0;
}