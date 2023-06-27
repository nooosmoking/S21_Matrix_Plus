#include "../s21_matrix_oop.h"
using namespace std;

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix new_matrix(this->GetRows(), this->GetCols());
  new_matrix += *this;
  new_matrix += other;
  return new_matrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix new_matrix(this->GetRows(), this->GetCols());
  new_matrix += *this;
  new_matrix -= other;
  return new_matrix;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix new_matrix(this->GetRows(), this->GetCols());
  new_matrix = *this;
  new_matrix *= num;
  return new_matrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix new_matrix(this->GetRows(), this->GetCols());
  new_matrix = *this;
  new_matrix *= other;
  return new_matrix;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this->GetMatrix() != other.GetMatrix()) {
    this->RemoveMatrix();
    this->InitMatrix(other.GetRows(), other.GetCols());
    this->CopyMatrix(other);
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}