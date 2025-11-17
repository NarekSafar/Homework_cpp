#include <iostream>
#include <vector>
#include <set>

bool isSubset(const std::vector<int>& subset, const std::vector<int>& superset) {
    std::set<int> sub(subset.begin(), subset.end());
    std::set<int> super(superset.begin(), superset.end());

    for (int x : sub) {
        if (!super.count(x)) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<int> subset = {1, 3, 5};
    std::vector<int> superset = {1, 2, 3, 4, 5};
    std::cout << isSubset(subset, superset) << '\n'; 
    
    std::vector<int> subset2 = {1, 6};
    std::cout << isSubset(subset2, superset) << '\n';
    return 0;
}