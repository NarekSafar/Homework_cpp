#include  <iostream>
#include <vector>

void workWithEmptyVector() {
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i + 1);
		std::cout << vec.size() << "\n";
		std::cout << vec.capacity() << "\n";
	}
	for (int x : vec) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}

int main() {
	workWithEmptyVector();
	return 0;
}
