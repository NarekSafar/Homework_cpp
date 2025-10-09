#include <iostream>
#include <forward_list>

void insertionSort(std::forward_list<int>& fl) {
    if (fl.empty()) {
        return;
    }

    std::forward_list<int> sorted;

    for (int value : fl) {
        auto prev = sorted.before_begin();
        auto curr = sorted.begin();
        
        while (curr != sorted.end() && *curr < value) {
            ++prev;
            ++curr;
        }
        
        sorted.insert_after(prev, value);
        for(int x : sorted) {
            std::cout << x << " "; 
        }
        std::cout << std::endl;
    }

    fl = std::move(sorted);
}


int main() {
    std::forward_list<int> fl = {5, 2, 8, 1, 9};
    insertionSort(fl);
    return 0;
}
