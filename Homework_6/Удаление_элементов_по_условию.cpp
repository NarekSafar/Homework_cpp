#include <iostream>
#include <forward_list>

int removeIf(std::forward_list<int>& fl, bool func(int)) {
    return fl.remove_if(func);
}

bool isOdd(int x) { return x % 2 != 0; }

int main() {
	std::forward_list<int> fl = {1, 2, 3, 4, 5, 6};
    int removed = removeIf(fl, isOdd);
	for(int x : fl) {
	    std::cout << x << " ";
	}
	std::cout << std::endl << removed; 
	return 0;
}

