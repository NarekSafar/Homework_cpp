#include  <iostream>
#include <vector>

std::vector<int> createVectorFromInput() {
	std::vector<int> vec;
	int val;
	std::cin >> val;
	while (val != 0) {
		vec.push_back(val);
		std::cin >> val;
	}
	return vec;
}

int main() {
	std::vector<int> inputVec = createVectorFromInput();
	return 0;
}
