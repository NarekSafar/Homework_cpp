#include <iostream>
#include <vector>

std::vector<std::vector<int>> groupAdjacent(const std::vector<int> arr) {
    std::vector<std::vector<int>> result;
    for (int i = 0; i < arr.size(); ) {
        std::vector<int> group;
        int current = arr[i];

        while (i < arr.size() && arr[i] == current) {
            group.push_back(arr[i]);
            ++i;
        }

        result.push_back(group);
    }
    return result;
}


int main() {
    std::vector<int> vec = {1, 1, 2, 2, 2, 3, 1, 1};
    std::vector<std::vector<int>> groups = groupAdjacent(vec);
    for(std::vector<int> v : groups) {
        for(int x : v) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
  return 0;
}
