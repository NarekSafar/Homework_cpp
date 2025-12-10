#include <iostream>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::multiset<long long> tickets;
    long long h;

    for (int i = 0; i < n; i++) {
        std::cin >> h;
        tickets.insert(h);
    }

    for (int i = 0; i < m; i++) {
        long long t;
        std::cin >> t;

        auto it = tickets.upper_bound(t);

        if (it == tickets.begin()) {
            std::cout << -1 << "\n";
        } else {
            --it;
            std::cout << *it << "\n";
            tickets.erase(it);
        }
    }
    return 0;
}
