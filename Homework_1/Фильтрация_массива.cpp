#include <iostream>
#include <string>

bool pred(int t) {
    return t > 2;   
}

bool pred(double t) {
    return t > 2.0; 
}

bool pred(const std::string& t) {
    return t.length() > 3; 
}

template <typename T, typename P>
void filter(T* arr, int* size, P pred) {
    int j = 0;
    for (int i = 0; i < *size; i++) {
        if (pred(arr[i])) {
            arr[j] = arr[i];
            j++;
        }
    }
    *size = j;
}

int main() {
    int size = 4;
    int arr1[] = { 1, 2, 9, 5};
    double arr2[] = { 1.2, 2.15, 3.3, 45.2};
    std::string arr3[] = {"AAAA", "bbbb", "Ccc", "dDDD"};

    filter(arr1, &size, static_cast<bool(*)(int)>(pred)); 
    for (int i = 0; i < size; i++) {
        std::cout << arr1[i] << '\n';
    }

    size = 4;
    filter(arr2, &size, static_cast<bool(*)(double)>(pred)); 
    for (int i = 0; i < size; i++) {
        std::cout << arr2[i] << '\n';
    }

    size = 4;
    filter(arr3, &size, static_cast<bool(*)(const std::string&)>(pred));
    for (int i = 0; i < size; i++) {
        std::cout << arr3[i] << '\n';
    }

    return 0;
}
