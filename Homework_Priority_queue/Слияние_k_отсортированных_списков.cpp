#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int val;      
    int listIdx;  
    int elemIdx;  

    bool operator>(const Node& other) const {
        return val > other.val;
    }
};

std::vector<int> mergeKSortedLists(const std::vector<std::vector<int>>& lists) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    std::vector<int> result;

    for (int i = 0; i < lists.size(); ++i) {
        if (!lists[i].empty()) {
            pq.push({lists[i][0], i, 0});
        }
    }

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        result.push_back(node.val);

        int nextIdx = node.elemIdx + 1;
        if (nextIdx < lists[node.listIdx].size()) {
            pq.push({lists[node.listIdx][nextIdx], node.listIdx, nextIdx});
        }
    }
    return result;
}

int main() {
        std::vector<std::vector<int>> lists = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };
    auto result = mergeKSortedLists(lists);
    for (int x : result) std::cout << x << " ";
    return 0;
}
