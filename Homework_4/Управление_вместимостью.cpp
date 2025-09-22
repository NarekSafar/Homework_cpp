#include <iostream>
#include <vector>

void manageCapacity(std::vector<int>& vec) { 
    std::cout << "Size: " << vec.size() << "\n";
    std::cout << "Capacity: " << vec.capacity() << "\n";
    vec.reserve(500);
    for(int i = 0; i < 500; ++i) {
        vec.push_back(i + 1);
    }
    std::cout << "Size after adding elements: " << vec.size() << "\n";
    std::cout << "Capacity after adding elements: " << vec.capacity() << "\n";
 }

int main() {
    std::vector<int> vec{};
    manageCapacity(vec);
    return 0;
}
