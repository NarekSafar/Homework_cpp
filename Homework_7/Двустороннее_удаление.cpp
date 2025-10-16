#include <iostream>
#include <deque>

void removeFromBothEnds(std::deque<int>& dq, int K) {
	for(int i = 0; i < K; ++i) {
		if(!dq.empty()) {
			dq.pop_front();
			if(!dq.empty()) {
				dq.pop_back();
			}
			std::cout << "Size: " << dq.size() << std::endl;
			for(int j = 0; j < dq.size(); ++j) {
				std::cout << dq[j] << " ";
			}
			std::cout << std::endl;
		} else {
		    break;
		}
	}
}

int main() {
	std::deque<int> d = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	removeFromBothEnds(d, 10);
	return 0;
}
