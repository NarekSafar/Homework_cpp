#include <iostream>

template <typename T1, typename T2>
class Pair {
private:
    T1 val_1;
    T2 val_2;
public:
    Pair(T1 val_1, T2 val_2) : val_1(val_1), val_2(val_2) {};
    void print() const {
        std::cout << val_1 << " " << val_2 << "\n"; 
    }
};

template <typename T>
class Pair<T, T> {
private:
    T val_1;
    T val_2;
public:
    Pair(T val_1, T val_2) : val_1(val_1), val_2(val_2) {};
    void print() const {
        std::cout << "Pair of identical types: " << val_1 << " " << val_2 << "\n"; 
    }
};

int main() {
    Pair<int, double> p1(10, 3.14);
    p1.print(); 

    Pair<int, int> p2(5, 5);
    p2.print(); 

    Pair<std::string, std::string> p3("Hi", "Hello");
    p3.print(); 
    return 0;
}

