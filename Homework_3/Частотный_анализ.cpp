#include <iostream>
#include <array>

template <int N>
std::array<int, 256> countFrequency(std::array<char, N> arr) {
	std::array<int, 256> freqArr{};
	for(char c : arr) {
	    freqArr[c]++;
	}
	return freqArr;
}

int main() {
	std::array<char, 5> text = {'h', 'e', 'l', 'l', 'o'};
    auto freq = countFrequency<5>(text);
    std::cout << freq['l'] << "\n";
    std::cout << freq['e'] << "\n";
    std::cout << freq['L'] << "\n";
    std::cout << freq['h'] << "\n";
    std::cout << freq['o'] << "\n";
    std::cout << freq['a'] << "\n";
    return 0;
}
