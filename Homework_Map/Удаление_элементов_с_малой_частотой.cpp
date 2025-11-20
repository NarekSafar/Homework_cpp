#include <iostream>
#include <map>

int removeInfrequent(std::map<std::string, int>& freq, int threshold) {
    int count = 0;
    auto it = freq.begin();
    while(it != freq.end()) {
        if(it->second < threshold) {
            it = freq.erase(it);
            count++;
        } else {
            it++;
        }
    }
    return count;
}

int main() {
    std::map<std::string, int> freq = {{"apple", 5}, {"banana", 2}, {"cherry", 8}, {"date", 1}};
    int removed = removeInfrequent(freq, 3);
    std::cout << removed << '\n';
    for(const auto& [key, val] : freq) {
        std::cout << key << ':' << val << ' ';
    }
    return 0;
}
