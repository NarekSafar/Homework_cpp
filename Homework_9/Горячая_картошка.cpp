#include <iostream>
#include <vector>
#include <queue>

std::string hotPotato(std::vector<std::string> players, int K) {
    std::queue<std::string> q;
    
    for (const std::string& name : players) {
        q.push(name);
    }

    while (q.size() > 1) {
        for (int i = 0; i < K; ++i) {
            q.push(q.front());
            q.pop();          
        }
        q.pop();
    }

    return q.front();
}

int main() {
    std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
    std::cout << hotPotato(players, 7) << '\n'; 
    return 0;
}