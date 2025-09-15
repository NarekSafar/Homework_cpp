#include <iostream>
#include <array>

template <typename T, int N>
void reverseArray(std::array<T, N>& arr) {
	int start = 0, end = N - 1;
	while (start < end) {
		T temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

int main() {
	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	reverseArray(arr);
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}
