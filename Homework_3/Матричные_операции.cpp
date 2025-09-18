#include <iostream>
#include <array>

class Matrix3x3 {
private:
    std::array<std::array<int, 3>, 3> matrix;
public:
    Matrix3x3(int a11, int a12, int a13,
              int a21, int a22, int a23,
              int a31, int a32, int a33) {
        matrix = {{
            {{a11, a12, a13}},
            {{a21, a22, a23}},
            {{a31, a32, a33}}
        }};
    }
    
    int getElement(int row, int col) const {
        return matrix[row][col];
    }
    
    void setElement(int row, int col, int value) {
        matrix[row][col] = value;
    }
   
    void transpose() {
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void print() const {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                std::cout  << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    
    auto operator[](int i) const {
        return matrix[i];
    }
    
};

int main() {
    Matrix3x3 matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
    matrix.print();
    matrix.transpose();
    matrix.print();
    std::cout << matrix[1][2];
    return 0;
}
