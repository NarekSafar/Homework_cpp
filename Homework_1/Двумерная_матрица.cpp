#include <iostream>

template <typename T, int N, int M>
class Matrix {
private:
    T arr[N][M]{};
public:
    Matrix() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                arr[i][j] = T{};
            }
        }
    }

    Matrix(const T array[N][M]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                arr[i][j] = array[i][j];   
            }
        }
    }

    void set(int row, int col, T value) {
        arr[row][col] = value;
    }

    T get(int row, int col) {
        return arr[row][col];
    }

    void print() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
               std::cout << arr[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    Matrix operator+(const Matrix& other) {
        Matrix sum;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                sum.arr[i][j] = arr[i][j] + other.arr[i][j];
            }
        }
        return sum;
    }
};

int main() {
    int data_int[2][2] = {{1, 2}, {3, 4}};
    int data_int_2[2][2] = {{1, 1}, {2, 9}};
    double data_double[2][3] = {{1.2, 2.0, 3.4}, {4.5, 5.6, 6.7}};
    std::string data_str[2][2] = {{"Hi", "AAA"}, {"CCC", "DDD"}};

    Matrix<int, 2, 2> m_int(data_int);
    Matrix<int, 2, 2> m_int_2(data_int_2);
    Matrix<double, 2, 3> m_double(data_double);
    Matrix<std::string, 2, 2> m_str(data_str);

    m_int.print();
    std::cout << "\n";
    m_double.print();
    std::cout << "\n";
    m_str.print();
    std::cout << "\n";
    (m_int + m_int_2).print();

    return 0;
}
