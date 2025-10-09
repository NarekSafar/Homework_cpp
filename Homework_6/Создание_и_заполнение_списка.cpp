#include <iostream>
#include <forward_list>

void createAndFillList(int N) {
    std::forward_list<int> flst{};
    for(int i = 0; i < N; ++i) {
        flst.push_front(i + 1);
    }
    for(int x : flst) {
        std::cout << x << " "; 
    }
}

int main() {
    createAndFillList(5);   
    return 0;
}

