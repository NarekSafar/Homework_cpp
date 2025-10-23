#include <iostream>
#include <vector>
#include <queue>

std::queue<std::string> generateBinaryNumbers(int N) {
    std::queue<std::string> q;
    std::queue<std::string> result;

    q.push("1");

    for (int i = 0; i < N; ++i) {
        std::string current = q.front();
        q.pop();

        result.push(current);

        q.push(current + "0");
        q.push(current + "1");
    }

    return result;
}

int main() {
    auto result = generateBinaryNumbers(5);
    while (!result.empty()) {
        std::cout << result.front() << " ";
        result.pop();
    }
    return 0;
}