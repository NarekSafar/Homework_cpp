#include <iostream>
#include <map>

std::map<std::string, int> mergeMaps(std::map<std::string, int> map1, std::map<std::string, int> map2) {
    std::map<std::string, int> result = map1;
    for(const auto& [key, val] : map2) {
        result[key] += val;
    }
    return result;
}

int main() {
   std::map<std::string, int> map1 = {{"a", 1}, {"b", 2}, {"c", 3}};
    std::map<std::string, int> map2 = {{"b", 3}, {"c", 4}, {"d", 5}};
    auto result = mergeMaps(map1, map2);
    for(const auto& [key, val] : result) {
        std::cout << key << ':' << val << '\n';
    }
    return 0;
}