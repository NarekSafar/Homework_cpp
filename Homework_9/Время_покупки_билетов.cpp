#include <iostream>
#include <vector>
#include <queue>

int timeRequiredToBuy(std::vector<int> tickets, int k) {
    std::queue<std::pair<int, int>> q; 
    int time = 0;

    for (int i = 0; i < tickets.size(); ++i) {
        q.push({i, tickets[i]});
    }

    while (!q.empty()) {
        int index = q.front().first;
        int count = q.front().second;
        q.pop();
        ++time;
        --count;

        if (count > 0) {
            q.push({index, count});
        }

        if (index == k && count == 0) {
            return time;
        }
    }

    return time;
}

int main() {
    std::vector<int> tickets1 = {2, 3, 2};
    std::cout << timeRequiredToBuy(tickets1, 2) << '\n'; 
    
    std::vector<int> tickets2 = {5, 1, 1, 1};
    std::cout << timeRequiredToBuy(tickets2, 0) << '\n';
    
    return 0;
}