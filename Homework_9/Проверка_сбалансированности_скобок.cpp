#include <iostream>
#include <stack>

bool isBalanced(const std::string& s) {
    std::stack<char> st;
    for(char c : s) {
        if(c == ')' && st.top() == '(') {
            st.pop();
        } else if(c == ']' && st.top() == '[') {
            st.pop();
        } else if(c == '}' && st.top() == '{') {
            st.pop();
        } else {
            st.push(c);
        }
    }
    return st.empty();
}

int main() {
    std::cout << isBalanced("({[]})") << '\n';  
    std::cout << isBalanced("([)]") << '\n';    
    std::cout << isBalanced("{[}]") << '\n';
    return 0;
}