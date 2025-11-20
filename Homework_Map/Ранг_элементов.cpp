#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::vector<int> arrayRankTransform(std::vector<int>& vec) {
    std::vector<int> tmp = vec;
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    std::map<int, int> mp;
    for(int i = 0; i < vec.size(); ++i) {
        mp[vec[i]] = i + 1;
    }
    std::vector<int> result;
    for(int el : tmp) {
        result.push_back(mp[el]);
    }
    return result;
}

int main() {
    std::vector<int> arr = {40, 10, 20, 30};
    auto result = arrayRankTransform(arr); 
    for(int el : result) {
        std::cout << el << " ";
    }
    std::vector<int> arr2 = {100, 100, 100};
    auto result2 = arrayRankTransform(arr2);
    std::cout << std::endl;
    for(int el : result2) {
        std::cout << el << " ";
    }
    return 0;
}
