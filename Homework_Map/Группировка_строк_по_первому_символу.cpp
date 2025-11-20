#include <iostream>
#include <vector>
#include <map>

std::map<char, std::vector<std::string>> groupByFirstChar(const std::vector<std::string>& vec) {
    std::map<char, std::vector<std::string>> result{};
    for(const std::string& st : vec) {
        result[st[0]].push_back(st);
    }
    return result;
}

int main() {
    std::vector<std::string> words = {"apple", "banana", "apricot", "cherry", "avocado"};
    auto result = groupByFirstChar(words);
    for(const auto& [key, val] : result) {
        std::cout << key << ": ";
        for(const std::string& el : val) {
            std::cout << el << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}