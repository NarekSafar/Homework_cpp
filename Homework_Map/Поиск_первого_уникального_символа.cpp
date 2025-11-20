#include <iostream>
#include <map>

int firstUniqueChar(const std::string& st) {
    std::map<char, int> freq{};
    for(char c : st) {
        freq[c]++;
    }
    for(int i = 0; i < st.size(); ++i) {
        if(freq[st[i]] == 1) return i;
    }
    return -1;
}

int main() {
    std::string s = "leetcode";
    std::cout << firstUniqueChar(s) << '\n'; 
    
    std::string s2 = "loveleetcode";
    std::cout << firstUniqueChar(s2) << '\n'; 
    return 0;
}