#include <iostream>
#include <vector>

int findSubsequence(std::vector<int> arr, std::vector<int> subArr) {
  int size = arr.size();
  int subArrSize = subArr.size();
  for(int i = 0; i < size - subArrSize + 1; ++i) {
    int j = 0;
    for(; j < subArrSize; ++j) {
      if(arr[i + j] != subArr[j]) {
        break;
      }
    }
    if(j == subArrSize) {
      return i;
    }
  }
  return -1;
}

int main() {
  std::vector<int> main_vec = {1, 8, 3, 3, 3, 3, 4, 3, 4, 5};
  std::vector<int> sub_vec = {3, 4, 5};
  int index = findSubsequence(main_vec, sub_vec);
  std::cout << index;
  return 0;
}
