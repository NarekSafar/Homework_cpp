#include <iostream>

const int size = 4;

template <typename T>
T sumArray(T* arr, int size) {
  T sum{};
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

int main() {
  int arr1[size] = { 1, 2, 3, 4};
  double arr2[size] = { 1.21, 2.1, 3.3, 4.9};
  std::string arr3[size] = {"AAAA", "BBBB", "CCCC", "DDDD"};
  std::cout << sumArray(arr1, size) << "\n";
  std::cout << sumArray(arr2, size) << "\n";
  std::cout << sumArray(arr3, size) << "\n";
  return 0;
}

