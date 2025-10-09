#include <iostream>
#include <forward_list>

void moveElementsToFront(std::forward_list<int>& fl, int val) {
	auto curr = fl.begin(), prev = fl.before_begin();
	
	while(curr != fl.end()) {
	    if(*curr == val) {
	        curr = fl.erase_after(prev);
	        fl.push_front(val);
	    } else {
	        prev = curr;
	        ++curr;
	    } 
	}
}

int main() {
	std::forward_list<int> fl = {1, 3, 2, 3, 4, 3};
    moveElementsToFront(fl, 3);
	for(int x : fl) {
	    std::cout << x << " ";
	}
	return 0;
}

