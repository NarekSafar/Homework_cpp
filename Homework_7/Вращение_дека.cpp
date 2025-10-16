#include <iostream>
#include <deque>

template <typename T>
void rotateDeque(std::deque<T> &dq, int K) {
	if(std::abs(K) > dq.size()) {
		if(K > 0) {
			K = K % dq.size();
		} else {
			K = dq.size() - K % dq.size();
		}
	}
	if(K == 0) return;
	for(int i = 0; i < std::abs(K); ++i) {
		if(K > 0) {
			dq.push_front(dq[dq.size() - 1]);
			dq.pop_back();
		} else {
			dq.push_back(dq[0]);
			dq.pop_front();
		}
	}
}

int main() {
	std::deque<int> d = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	rotateDeque(d, -23);
	for(int x : d) {
		std::cout << x << " ";
	}
	return 0;
}