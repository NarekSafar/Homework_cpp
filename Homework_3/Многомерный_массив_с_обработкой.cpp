#include <iostream>
#include <array>

template <typename T, typename F, int Rows, int Cols>
auto process2DArray(std::array<std::array<T, Cols>, Rows> arr, F func) {
	std::array<std::array<T, Cols>, Rows> newArr{};
	for(int i = 0; i < Rows; ++i) {
		for(int j = 0; j < Cols; ++j) {
			newArr[i][j] = func(arr[i][j]);
		}
	}
	return newArr;
}

int _double(int x) {
	return x * 2;
}

std::array<std::array<int, 3>, 3> matrix = {{
		{{1, 2, 3}},
		{{4, 5, 6}},
		{{7, 8, 9}}
	}
};

int main() {
	auto doubled = process2DArray<int, int(*)(int), 3, 3>(matrix, _double);
	for(auto row : doubled) {
		for(int x : row) {
			std::cout << x << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
