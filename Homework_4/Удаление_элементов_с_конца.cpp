#include  <iostream>
#include <vector>

int removeElementsGreaterThan(std::vector<int>& vec, int num) {
	int count = 0;
	int i = 0;
	while(!vec.empty()) {
		if (vec.back() > num) {
			vec.pop_back();
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

int main() {
	std::vector<int> v = { 1, 3, 5, 7, 9 };
	int removed = removeElementsGreaterThan(v, 5);
	std::cout << removed << "\n";
}
