#include <iostream>
#include <vector>

class VectorStats {
private:
    std::vector<double> arr;
public:
    VectorStats(const std::vector<double>& arr) : arr(arr) {};
    double mean() const {
        if(arr.empty()) {
            return 0.0;
        }
        double sum = 0.0;
        for(double el : arr) {
            sum += el;
        }
        return sum / arr.size();
    }
    double median() const {
        std::vector<double> copiedArr = arr;
        int size = copiedArr.size();
        for(int i = 0; i < size - 1; ++i) {
            for(int j = 0; j < size - i - 1; ++j) {
                if(copiedArr[j] > copiedArr[j + 1]) {
                    std::swap(copiedArr[j], copiedArr[j + 1]);
                }
            }
        }
        if(size % 2 == 1) {
            return copiedArr[size / 2];
        } else {
            return (copiedArr[size / 2 - 1] + copiedArr[size / 2]) / 2.0;
        }
    }
    void addValue(double value) {
        arr.push_back(value);
    }
    void removeValue(double value) {
        int index = -1;
        for(int i = 0; i < arr.size(); ++i) {
            if(value == arr[i]) {
                index = i;
                break;
            }
        }
        if(index != -1) {
            arr.erase(arr.begin() + index);
        } else {
            std::cout << "There is not such an element to remove!\n";
        }
    }
};

int main() {
    VectorStats stats({1.0, 2.0, 3.0, 4.0});
    double m = stats.mean();   
    double md = stats.median();
    std::cout << m << " " << md << "\n";
    stats.addValue(5.0);
    stats.removeValue(2.0);
}
