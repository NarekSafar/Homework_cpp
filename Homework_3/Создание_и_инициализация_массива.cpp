#include <iostream>
#include <array>

std::array<int, 5> createArray() {
	std::array<int, 5> arr;
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = i + 1;
	}
	return arr;
}

int main() {
	for (int x : createArray()) {
		std::cout << x << " ";
	}
	return 0;
}
