#include <iostream>
#include <forward_list>

bool insertAfterPosition(std::forward_list<int>& flst, int position, int val) {
    auto it = flst.begin();
    for(int i = 0; i < position; ++i) {
        if(it == flst.end()) {
            return false;
        }
        ++it;
    }
    flst.insert_after(it, val);
    return true;
}

int main() {
    std::forward_list<int> fl = {1, 2, 3, 4};
    if(insertAfterPosition(fl, 1, 99)) {
        for(int x : fl) {
            std::cout << x << " "; 
        }   
    }
    std::cout << std::endl;
    return 0;
}

