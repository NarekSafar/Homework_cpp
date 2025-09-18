#include <iostream>
#include <array>

template <typename T, int N>
bool validateArray(std::array<T, N> arr, T min, T max) {
	for(T x : arr) {
	    if(!(min <= x && x <= max)) {
	        return false;
	    }
	}
	return true;
}


int main() {
	std::array<int, 4> scores = {85, 92, 78, 1001};
    bool valid = validateArray<int, 4>(scores, 0, 100);
    std::cout << std::boolalpha << valid; 
	return 0;
}
