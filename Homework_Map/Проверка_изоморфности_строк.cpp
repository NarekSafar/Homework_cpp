#include <iostream>
#include <map>

bool isIsomorphic(const std::string& s, const std::string& t) {
    if(s.size() != t.size()) return false;
    std::map<char, char> map1, map2;
    for(int i = 0; i < s.size(); ++i) {
        if(map1.count(s[i]) && map1[s[i]] != t[i]) return false;
        if(map2.count(t[i]) && map2[t[i]] != s[i]) return false;
        map1[s[i]] = t[i];
        map2[t[i]] = s[i];
    }
    return true;
}

int main() {
    std::cout << isIsomorphic("egg", "add") << '\n';     
    std::cout << isIsomorphic("foo", "bar") << '\n';     
    std::cout << isIsomorphic("paper", "title") << '\n'; 
    return 0;
}
