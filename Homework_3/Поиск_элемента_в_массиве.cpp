#include <iostream>
#include <array>

template <typename T, int N>
int findElement(std::array<T, N> arr, T val) {
	int index = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == val) {
			index = i;
			break;
		}
	}
	return index;
}

int main() {
	std::array<std::string, 5> arr = {"Hi", "C++", "Hello", "V", "Hello"};
	std::cout << findElement<std::string, 5>(arr, "Hello") << "\n";
	std::cout << findElement<std::string, 5>(arr, "C");
	return 0;
}
