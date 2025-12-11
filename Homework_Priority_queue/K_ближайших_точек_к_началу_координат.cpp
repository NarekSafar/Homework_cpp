#include <iostream>
#include <queue>
#include <vector>

struct Point {
	int x, y;
	int distance() const {
		return x*x + y*y;
	}
};

struct Compare {
	bool operator()(const Point& a, const Point& b) {
		return a.distance() < b.distance();
	}
};

std::vector<Point> kClosest(const std::vector<Point>& points, int k) {
	std::priority_queue<Point, std::vector<Point>, Compare> pq;

	for (const auto& p : points) {
		if (pq.size() < k) {
			pq.push(p);
		} else if (p.distance() < pq.top().distance()) {
			pq.pop();
			pq.push(p);
		}
	}

	std::vector<Point> result;
	while (!pq.empty()) {
		result.push_back(pq.top());
		pq.pop();
	}

	return result;
}

int main() {
	std::vector<Point> pts = {{1,3}, {-2,2}, {5,8}};
	auto result = kClosest(pts, 2);
	for (auto p : result) std::cout << '{' << p.x << ',' << p.y << "} ";
}
