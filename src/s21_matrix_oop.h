#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <cmath>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

  void InitMatrix(int rows, int cols);      //?
  void CopyMatrix(const S21Matrix& other);  //?
  void RemoveMatrix();                      //?

  bool IsMatrix() const;                        //?
  bool IsSquare() const;                        //?
  bool IsEqSize(const S21Matrix& other) const;  //?

  S21Matrix FindMinor();                                             //!
  double SimpleDeterminant(int size);                                //!
  S21Matrix GetSimpleMatrix(S21Matrix tmp, int i, int j, int size);  //!

 public:
  S21Matrix();   //?
  ~S21Matrix();  //?

  S21Matrix(int rows, int cols);  //? параметризованный конструктор
  S21Matrix(const S21Matrix& other);  //? конструктор копирования
  S21Matrix(S21Matrix&& other);  //? конструктор перемещения

  int GetRows() const;         //?
  int GetCols() const;         //?
  double** GetMatrix() const;  //?
  void SetRows(int size);      //?
  void SetCols(int size);      //?

  bool EqMatrix(const S21Matrix& other);   //?
  void SumMatrix(const S21Matrix& other);  //?
  void SubMatrix(const S21Matrix& other);  //?
  void MulNumber(const double num);        //?
  void MulMatrix(const S21Matrix& other);  //?
  S21Matrix Transpose();                   //!
  S21Matrix CalcComplements();             //!
  double Determinant();                    //!
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix& other);    //?
  S21Matrix operator-(const S21Matrix& other);    //?
  S21Matrix operator*(const double num);          //?
  S21Matrix operator*(const S21Matrix& other);    //?
  bool operator==(const S21Matrix& other);        //?
  S21Matrix& operator=(const S21Matrix& other);   //?
  S21Matrix& operator+=(const S21Matrix& other);  //?
  S21Matrix& operator-=(const S21Matrix& other);  //?
  S21Matrix& operator*=(const double num);        //?
  S21Matrix& operator*=(const S21Matrix& other);  //?
};

#endif