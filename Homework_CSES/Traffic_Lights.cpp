#include <iostream>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long x;
    int n;
    std::cin >> x >> n;

    std::set<long long> lights;
    std::multiset<long long> lengths;

    lights.insert(0);
    lights.insert(x);
    lengths.insert(x);

    for (int i = 0; i < n; i++) {
        long long p;
        std::cin >> p;
        auto it = lights.lower_bound(p);
        long long right = *it;
        long long left = *std::prev(it);

        auto old_it = lengths.find(right - left);
        lengths.erase(old_it);

        lengths.insert(p - left);
        lengths.insert(right - p);

        lights.insert(p);

        std::cout << *lengths.rbegin();
        if (i + 1 < n) std::cout << ' ';
    }
    return 0;
}
