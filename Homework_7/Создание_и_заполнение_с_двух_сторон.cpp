#include <iostream>
#include <deque>

void createAndFillDeque(int N) {
	std::deque<int> result{};
	for(int i = 0; i < N; ++i) {
		if((i+1) % 2 == 0) {
			result.push_front(i+1);
		} else {
			result.push_back(i+1);
		}
	}
	for(int i = 0; i < N; ++i) {
		std::cout << result[i] << " " ;
	}
}

int main() {
	createAndFillDeque(15);
	return 0;
}