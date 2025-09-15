#include <iostream>

template <typename T1, typename T2>
class Pair {
private:
    T1 x;
    T2 y;
public:
    Pair(T1 x, T2 y) : x(x), y(y) {};
    void display() {
        std::cout << x << " " << y;
    }
};

int main() {
  int a = 20; 
  std::string b = "Hi";
  Pair<int, std::string> pair(a, b);
  pair.display();
  return 0;
}

