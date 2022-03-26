#include <iostream>

using namespace std;

#include "matrix.h"

// constructor
TwoDimensionMatrix::TwoDimensionMatrix() {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix &other_matrix) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            matrix[i][j] = other_matrix.get(i, j);
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement other_matrix[size][size]) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            matrix[i][j] = other_matrix[i][j];
        }
    }
}

// getter
MatrixElement TwoDimensionMatrix::get(size_t row, size_t column) const {
    return matrix[row][column];
}

// operator =
TwoDimensionMatrix &TwoDimensionMatrix::operator=(const TwoDimensionMatrix &other_matrix) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            matrix[i][j] = other_matrix.get(i, j);
        }
    }
    return *this;
}

// operator << (output)
ostream &operator<<(ostream &output, const TwoDimensionMatrix &other_matrix) {
    for (size_t i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for (size_t j = 0; j < TwoDimensionMatrix::getSize(); j++) {
            output << other_matrix.get(i, j) << " ";
        }
        output << endl;
    }
    return output;
}

// operator >> (input)
istream &operator>>(istream &input, TwoDimensionMatrix &other_matrix) {
    for (auto &i: other_matrix.matrix) {
        for (int &j: i) {
            input >> j;
        }
    }
    return input;
}

// operator +
TwoDimensionMatrix operator+(const TwoDimensionMatrix &matrix1, const TwoDimensionMatrix &matrix2) {
    TwoDimensionMatrix result_matrix;
    for (size_t i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for (size_t j = 0; j < TwoDimensionMatrix::getSize(); j++) {
            result_matrix[i][j] = matrix1.get(i, j) + matrix2.get(i, j);
        }
    }
    return result_matrix;
}

// operator *=
TwoDimensionMatrix &TwoDimensionMatrix::operator*=(MatrixElement number) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            matrix[i][j] *= number;
        }
    }
    return *this;
}

// operator &&
TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &other_matrix) const {
    TwoDimensionMatrix result_matrix;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            result_matrix[i][j] = matrix[i][j] && other_matrix.get(i, j);
        }
    }
    return result_matrix;
}

// operator []
MatrixElement *TwoDimensionMatrix::operator[](size_t i) {
    return matrix[i];
}

const MatrixElement *TwoDimensionMatrix::operator[](size_t i) const {
    return matrix[i];
}