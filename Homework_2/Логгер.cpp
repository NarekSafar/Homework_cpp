#include <iostream>

class Logger {
private:
    int count;
public:
    Logger(int count) : count(count)  {};
    
    void log() { return; }
    
    template <typename T, typename... Rest>
    void log(T first, Rest... rest) {
        for(int i = 0; i < count; i++) {
            std::cout << " ";
        }
        std::cout << first << "\n";
        log(rest...);
    }
};

int main() {
    Logger logger(10); 
    logger.log("Hello", 42, 3.14, 'A');
    return 0;
}
