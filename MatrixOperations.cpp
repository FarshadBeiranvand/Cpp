#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    size_t rows;
    size_t cols;

public:
    // Constructor
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<double>(cols, 0));
    }

    // Access element at (i, j)
    double& operator()(size_t i, size_t j) {
        return data[i][j];
    }

    // Addition of two matrices
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Subtraction of two matrices
    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Scalar multiplication
    Matrix operator*(double scalar) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] * scalar;
            }
        }
        return result;
    }

    // Matrix multiplication
    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result(i, j) += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Transpose of the matrix
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(j, i) = data[i][j];
            }
        }
        return result;
    }

    // Matrix determinant
    double determinant() const {
        if (rows != cols) {
            std::cerr << "Matrix must be square to calculate determinant." << std::endl;
            return 0;
        }
        if (rows == 1) {
            return data[0][0];
        }
        if (rows == 2) {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        }
        double det = 0;
        for (size_t j = 0; j < cols; ++j) {
            det += data[0][j] * cofactor(0, j);
        }
        return det;
    }

    // Matrix inversion
    Matrix inverse() const {
        if (rows != cols) {
            std::cerr << "Matrix must be square to calculate inverse." << std::endl;
            return *this;
        }
        double det = determinant();
        if (det == 0) {
            std::cerr << "Matrix is singular, cannot calculate inverse." << std::endl;
            return *this;
        }
        Matrix adj(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                adj(i, j) = cofactor(j, i) / det;
            }
        }
        return adj;
    }

    // Display matrix
    void display() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    // Calculate cofactor of element (i, j)
    double cofactor(size_t row, size_t col) const {
        Matrix minor(rows - 1, cols - 1);
        size_t minor_row = 0;
        size_t minor_col = 0;
        for (size_t i = 0; i < rows; ++i) {
            if (i == row) {
                continue;
            }
            minor_col = 0;
            for (size_t j = 0; j < cols; ++j) {
                if (j == col) {
                    continue;
                }
                minor(minor_row, minor_col) = data[i][j];
                ++minor_col;
            }
            ++minor_row;
        }
        return minor.determinant() * ((row + col) % 2 == 0 ? 1 : -1);
    }
};

int main() {
    Matrix A(2, 2);
    A(0, 0) = 1; A(0, 1) = 2;
    A(1, 0) = 3; A(1, 1) = 4;

    Matrix B(2, 2);
    B(0, 0) = 5; B(0, 1) = 6;
    B(1, 0) = 7; B(1, 1) = 8;

    std::cout << "Matrix A:" << std::endl;
    A.display();

    std::cout << "Matrix B:" << std::endl;
    B.display();

    Matrix C = A + B;
    std::cout << "Matrix C = A + B:" << std::endl;
    C.display();

    Matrix D = A - B;
    std::cout << "Matrix D = A - B:" << std::endl;
    D.display();

    Matrix E = A * 2.0;
    std::cout << "Matrix E = A * 2.0:" << std::endl;
    E.display();

    Matrix F = B.transpose();
    std::cout << "Matrix F = Transpose(B):" << std::endl;
    F.display();

    std::cout << "Determinant of Matrix A: " << A.determinant() << std::endl;

    std::cout << "Inverse of Matrix A:" << std::endl;
    Matrix invA = A.inverse();
    invA.display();

    return 0;
}
