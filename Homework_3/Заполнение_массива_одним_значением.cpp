#include <iostream>
#include <array>

std::array<int, 10> fillArray(std::array<int, 10>& arr, int num) {
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = num;
	}
	return arr;
}

int main() {
	std::array<int, 10> arr;
	for (int x : fillArray(arr, 34)) {
		std::cout << x << " ";
	}
	return 0;
}
