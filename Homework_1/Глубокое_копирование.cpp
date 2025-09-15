#include <iostream>

template <typename T>
T copyValue(const T& value) {
    return value;  
}

template <typename T>
T* copyValue(T* ptr) {
    if (!ptr) {
      return nullptr;  
    }      
    return new T(*ptr);           
}

int main() {
    int x = 10;
    int* p = new int(20);

    int xCopy = copyValue(x);      
    int* pCopy = copyValue(p);     

    std::cout << "xCopy: " << xCopy << "\n";       
    std::cout << "*pCopy: " << *pCopy << "\n";     

    *pCopy = 50;
    std::cout << "*p: " << *p << "\n";             
    std::cout << "*pCopy: " << *pCopy << "\n";     

    delete p;
    delete pCopy;

    return 0;
}
