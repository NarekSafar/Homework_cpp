#include <iostream>
#include <queue>

class MedianFinder {
private:
    std::priority_queue<int> max_pq;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq; 
public:
    void addNum(int num) {
        if(max_pq.empty() || num <= max_pq.top()) {
            max_pq.push(num);
        } else {
            min_pq.push(num);
        }

        if(max_pq.size() > min_pq.size() + 1) {
            min_pq.push(max_pq.top());
            max_pq.pop();
        } else if(min_pq.size() > max_pq.size()) {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }

    double findMedian() {
        if(max_pq.size() == min_pq.size()) {
            return (max_pq.top() + min_pq.top()) / 2.0;
        } else {
            return max_pq.top();
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    std::cout << mf.findMedian() << '\n'; 
    mf.addNum(3);
    std::cout << mf.findMedian() << '\n'; 
}
