#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

bool includes(std::vector<int> arr, int n) {
    for(int i = 0; i < arr.size(); ++i) {
        if(arr[i] == n) {
            return true;
        }
    }
    return false;
}

std::vector<int> findIntersection(std::vector<int> vec_1, std::vector<int> vec_2) {
    std::vector<int> result{};
    for(int el : vec_1) {
        if(includes(vec_2, el) && !includes(result, el)) {
            result.push_back(el);
        }
    }
    bubbleSort(result);
    return result;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {3, 4, 5, 6};
    std::vector<int> inter = findIntersection(a, b);
    for(int el : inter) {
        std::cout << el << " "; 
    }
  return 0;
}
