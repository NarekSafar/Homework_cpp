#include <iostream>
std::string makeSentence(std::string el) {
 return el + ".";
}

template <typename... Rest >
std::string makeSentence(std::string first, Rest... rest) {
 return first + " " + makeSentence(rest...);
}

int main() {
 std::cout << makeSentence("AAAA", "BBBB", "CCCC") << std::endl;
 return 0;
}

