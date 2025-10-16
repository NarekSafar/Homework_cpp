#include <iostream>
#include <deque>

class Logger {
    std::deque<std::string> log;
    int max;
public:
    Logger(int N) : max(N) {}
    void add(const std::string& message) {
        if(log.size() == max) {
            log.pop_front();
        }
        log.push_back(message);
    }
    void show() const {
        for(const std::string& mes : log) {
            std::cout << mes << "\n";
        }
    }
};

int main() {
	Logger log(3);
    log.add("start");
    log.add("init");
    log.add("run");
    log.add("stop");
    log.show();
	return 0;
}