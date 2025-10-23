#include <iostream>
#include <stack>

void reverseString(std::string& s) {
    std::stack<char> rs;
    for(char c : s) {
        rs.push(c);
    }
    for(int i = 0; i < s.size(); ++i) {
        s[i] = rs.top();
        rs.pop();
    }
}

int main() {
    std::string s = "Hello";
    reverseString(s);
    std::cout << s << '\n';
    return 0;
}