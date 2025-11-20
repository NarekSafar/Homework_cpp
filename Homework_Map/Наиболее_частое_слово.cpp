#include <iostream>
#include <map>
#include <cctype>
#include <sstream> 

std::string mostFrequentWord(const std::string& s) {
    std::string cleaned;
    for (char c : s) {
        if (!std::ispunct(c)) {
            cleaned += std::tolower(c);
        }
    }
    std::istringstream iss(cleaned);
    std::string word;
    std::map<std::string, int> freq{};
    while (iss >> word) {
        freq[word]++;
    }
    std::string maxWord;
    int maxFreq = 0;
    for(const auto& [key, val] : freq) {
        if(val > maxFreq) {
            maxWord = key;
            maxFreq = val;
        } 
    }
    return maxWord;
}

int main() {
    std::string text = "Bob hit a ball, the Hit BALL flew far after it was HIT.";
    std::cout << mostFrequentWord(text) << '\n'; 
    return 0;
}
