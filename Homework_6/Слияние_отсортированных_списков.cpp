#include <iostream>
#include <forward_list>

void mergeSortedLists(std::forward_list<int>& flst_1, std::forward_list<int>& flst_2) {
	std::forward_list<int>::iterator it_curr_1 = flst_1.begin(),
	                            it_prev_1 = flst_1.before_begin(),
	                            it_2 = flst_2.begin();

	while (it_curr_1 != flst_1.end() && it_2 != flst_2.end()) {
		if (*it_curr_1 > *it_2) {
			flst_1.insert_after(it_prev_1, *it_2);
			++it_2;
			++it_prev_1;
		} else {
		    it_prev_1 = it_curr_1;
		    ++it_curr_1;   
		}
	}

	while (it_2 != flst_2.end()) {
        it_prev_1 = flst_1.insert_after(it_prev_1, *it_2);
        ++it_2;
    }
    
    flst_2.clear();
}

int main() {
	std::forward_list<int> fl1 = {1, 3, 5};
	std::forward_list<int> fl2 = {2, 4, 6, 7, 8};
	mergeSortedLists(fl1, fl2);
	for(int x : fl1) {
	    std::cout << x << " ";
	}
	return 0;
}

