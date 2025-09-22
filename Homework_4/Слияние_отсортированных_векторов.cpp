#include <iostream>
#include <vector>

template <typename T>
std::vector<int> mergeSortedVectors(std::vector<T> vec_1, std::vector<T> vec_2) {
    std::vector<int> result;
    result.reserve(vec_1.size() + vec_2.size()); 
    int i = 0, j = 0;

    while (i < vec_1.size() && j < vec_2.size()) {
        if (vec_1[i] <= vec_2[j]) {
            result.push_back(vec_1[i++]);
        } else {
            result.push_back(vec_2[j++]);
        }
    }

    while (i < vec_1.size()) {
        result.push_back(vec_1[i++]);
    }
    
    while (j < vec_2.size()) {
        result.push_back(vec_2[j++]);
    }

    return result;
}

int main() {
    std::vector<int> vec1 = {1, 3, 5, 7, 13, 18};
    std::vector<int> vec2 = {2, 4, 6, 8, 9, 10, 12, 14};
    std::vector<int> merged = mergeSortedVectors(vec1, vec2);
    for(int x : merged) {
        std::cout << x << " ";
    }
    return 0;
}
