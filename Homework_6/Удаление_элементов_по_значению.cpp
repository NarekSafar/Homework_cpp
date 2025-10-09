#include <iostream>
#include <forward_list>

int removeAllOccurrences(std::forward_list<int>& fl, int val) {
    int count = 0;
    auto prev = fl.before_begin();
    auto curr = fl.begin();

    while (curr != fl.end()) {
        if (*curr == val) {
            curr = fl.erase_after(prev);
            count++;
        } else {
            prev = curr;
            ++curr;
        }
    }
    return count;
}

int main() {
    std::forward_list<int> fl = {1, 2, 3, 2, 4, 2};
    int removed = removeAllOccurrences(fl, 2);    
    for(int x : fl) {
        std::cout << x << " "; 
    }   
    std::cout << "\n" << removed << std::endl;
    std::cout << std::endl;
    return 0;
}

