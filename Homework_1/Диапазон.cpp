#include <iostream>
#include <iomanip>

template <typename T>
class Range {
private:
    T start;
    T end;
public:
    Range(T start, T end) : start(start), end(end) {};
    bool contains(const T& value) const {
        return start <= value && value <= end;
    }
    int length() const {
        return end - start;
    }
    void print() const {
        std::cout << "[" << start << ", " << end << "]"; 
    }
};

int main() {
    Range<int> range_1(1, 4);
    Range<double> range_2(1.6, 10.2);
    Range<char> range_3('a', 'f');
    
    std::cout << std::boolalpha << range_1.contains(2) << "\n";
    std::cout << std::boolalpha << range_2.contains(10.3) << "\n";
    std::cout << "Length of ";
    range_3.print();
    std::cout << " is " << range_3.length();
    
    return 0;
}
