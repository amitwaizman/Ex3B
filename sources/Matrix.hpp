//
// Created by USER on 02/04/2022.
//

#ifndef MATRIX_CALCULATOR_A_MATRIX_H
#define MATRIX_CALCULATOR_A_MATRIX_H
#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;
namespace zich {
    class Matrix {
    private:
        vector<double> v;
        int r;
        int c;
    public:
        // Constructor
        Matrix();
        Matrix(const vector<double> &mat, const int row, const int column);
        ~Matrix();
        // copy Constructor
        Matrix(const Matrix& mat);

        Matrix operator+(const Matrix& mat);
        Matrix& operator+=(const Matrix& mat);
        Matrix& operator+();
        Matrix& operator-=(const Matrix& mat);
        Matrix operator-(const Matrix &mat);
        Matrix operator-();

        bool operator>(const  Matrix& mat);
        bool operator>=(const Matrix& mat);
        bool operator<(const Matrix& mat);
        bool operator<=(const Matrix& mat);
        friend bool operator==(const Matrix& mat,const Matrix& mat2 );
        bool operator==(const Matrix& mat);
        bool operator!=(const Matrix& mat);

        Matrix operator*(const double  n);
        Matrix& operator*=(const double  n);
        Matrix operator*(const Matrix &mat);
        Matrix& operator*=(const Matrix& mat);
        friend Matrix operator*( double n, Matrix& mat);
        Matrix &operator++();
        Matrix  operator++(int n); //n++
        Matrix &operator--();
        Matrix  operator--(int n); //n--
        friend std::ostream &operator<<(std::ostream &output, const Matrix &mat);
        friend std::istream &operator>>(std::istream &input,  Matrix &mat);


    };
}


#endif //MATRIX_CALCULATOR_A_MATRIX_H

