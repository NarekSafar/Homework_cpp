#include <iostream>
#include <set>
#include <cmath>

bool hasAllCodes(const std::string &s, int k) {
    if (s.size() < pow(2, k)) {
        return false;
    }
    std::string result;
    std::set<std::string> st;
    for (int i = 0; i < s.size() - k; i++) {
        result = s.substr(i, k);
        st.insert(result);
    }
    return st.size() == pow(2, k);
}

int main() {
    std::cout << hasAllCodes("00110110", 2) << '\n';
    return 0;
}