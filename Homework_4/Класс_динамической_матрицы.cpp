#include <iostream>
#include <vector>

class DynamicMatrix {
private:
    int row;
    int col;
    std::vector<std::vector<int>> matrix;
public:
    DynamicMatrix(int row, int col) : row(row), col(col) {
        matrix.resize(row, std::vector<int>(col, 0));
    };
    int getElement(int row, int col) const {
        return matrix[row][col];
    }
    void setElement(int row, int col, int value) {
        matrix[row][col] = value;
    }
    void addRow() {
        matrix.push_back(std::vector<int>(col, 0));
        row++;
    }
    void addColumn() {
        for(const auto& vec : matrix) {
            vec.push_back(0);
        }
        col++;
    }
    void print() const {
        for(const auto& vec : matrix) {
            for(int el : vec) {
                std::cout << el << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    DynamicMatrix matrix(3, 3);
    matrix.setElement(1, 1, 42);
    matrix.addRow();
    matrix.addColumn();
    matrix.print();
  return 0;
}
