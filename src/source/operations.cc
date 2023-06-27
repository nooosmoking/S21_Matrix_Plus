#include "../s21_matrix_oop.h"
using namespace std;

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  this->IsMatrix();
  other.IsMatrix();
  bool is_equal = this->IsEqSize(other);
  if (is_equal) {
    for (int i = 0; i < other.GetRows() && is_equal; i++) {
      for (int j = 0; j < other.GetCols() && is_equal; j++) {
        is_equal = fabs(this->matrix_[i][j] - other.matrix_[i][j]) < 1e-7;
      }
    }
  }
  return is_equal;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  this->IsMatrix();
  other.IsMatrix();

  if (!this->IsEqSize(other))
    throw invalid_argument("Matrix should be equal size!");
  for (int i = 0; i < this->GetRows(); i++) {
    for (int j = 0; j < this->GetCols(); j++)
      this->matrix_[i][j] = this->matrix_[i][j] + other.matrix_[i][j];
  }
}
void S21Matrix::SubMatrix(const S21Matrix& other) {
  this->IsMatrix();
  other.IsMatrix();

  if (!this->IsEqSize(other))
    throw invalid_argument("Matrix should be equal size!");
  for (int i = 0; i < this->GetRows(); i++) {
    for (int j = 0; j < this->GetCols(); j++)
      this->matrix_[i][j] = this->matrix_[i][j] - other.matrix_[i][j];
  }
}
void S21Matrix::MulNumber(const double num) {
  this->IsMatrix();
  for (int i = 0; i < this->GetRows(); i++) {
    for (int j = 0; j < this->GetCols(); j++)
      this->matrix_[i][j] = this->matrix_[i][j] * num;
  }
}
void S21Matrix::MulMatrix(const S21Matrix& other) {
  this->IsMatrix();
  other.IsMatrix();
  if (this->GetCols() != other.GetRows())
    throw invalid_argument("Invalid sizes of matrix!");
  S21Matrix res(this->GetRows(), other.GetCols());
  for (int i = 0; i < this->GetRows(); i++) {
    for (int j = 0; j < other.GetCols(); j++) {
      for (int k = 0; k < other.GetRows(); k++)
        res.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
    }
  }
  *this = res;
}
S21Matrix S21Matrix::Transpose() {
  this->IsMatrix();
  S21Matrix result(this->GetCols(), this->GetRows());
  for (int i = 0; i < this->GetRows(); i++) {
    for (int j = 0; j < this->GetCols(); j++)
      result.matrix_[j][i] = this->matrix_[i][j];
  }
  return result;
}

S21Matrix S21Matrix::FindMinor() {
  int size = this->GetRows();
  S21Matrix result(size, size);
  for (int i = 0; i < this->GetRows(); i++) {
    for (int j = 0; j < this->GetCols(); j++) {
      if (this->GetRows() > 1) {
        S21Matrix tmp(size - 1, size - 1);
        tmp = this->GetSimpleMatrix(tmp, i, j, size);
        result.matrix_[i][j] = tmp.SimpleDeterminant(size - 1);
        tmp.RemoveMatrix();
      } else {
        result.matrix_[0][0] = this->SimpleDeterminant(1);
      }
    }
  }
  return result;
}
S21Matrix S21Matrix::CalcComplements() {
  this->IsMatrix();
  this->IsSquare();
  S21Matrix result = this->FindMinor();
  for (int i = 0; i < this->GetRows(); i++) {
    for (int j = 0; j < this->GetCols(); j++)
      result.matrix_[i][j] = result.matrix_[i][j] * pow(-1., i + j);
  }
  return result;
}

S21Matrix S21Matrix::GetSimpleMatrix(S21Matrix tmp, int i, int j, int size) {
  int ki = 0, kj = 0, di = 0, dj = 0;
  for (ki = 0; ki < size - 1; ki++) {  // проверка индекса строки
    if (ki == i) di = 1;
    dj = 0;
    for (kj = 0; kj < size - 1; kj++) {  // проверка индекса столбца
      if (kj == j) dj = 1;
      tmp.matrix_[ki][kj] = this->matrix_[ki + di][kj + dj];
    }
  }
  return tmp;
}

double S21Matrix::SimpleDeterminant(int size) {
  int factor = 1;
  int new_size = size - 1;
  double determ = 0;

  if (size == 1) {
    determ = this->matrix_[0][0];
  }
  if (size == 2) {
    determ = this->matrix_[0][0] * this->matrix_[1][1] -
             (this->matrix_[1][0] * this->matrix_[0][1]);
  }
  if (size > 2) {
    S21Matrix tmp(size, size);

    for (int i = 0; i < size; i++) {
      tmp = this->GetSimpleMatrix(tmp, i, 0, size);
      determ += factor * this->matrix_[i][0] * tmp.SimpleDeterminant(new_size);
      factor = -factor;
    }
  }
  return determ;
}
double S21Matrix::Determinant() {
  this->IsMatrix();
  this->IsSquare();
  return this->SimpleDeterminant(this->GetRows());
}

S21Matrix S21Matrix::InverseMatrix() {
  this->IsMatrix();
  this->IsSquare();
  double determ = this->Determinant();
  if (!determ) throw invalid_argument("You can`t inverse this matrix!");

  S21Matrix result(1, 1);
  if (this->GetRows() == 1) {
    result.matrix_[0][0] = 1. / determ;
  } else {
    S21Matrix minor_tmp = this->CalcComplements();
    result = minor_tmp.Transpose();

    for (int i = 0; i < minor_tmp.GetRows(); i++) {
      for (int j = 0; j < minor_tmp.GetCols(); j++)
        result.matrix_[i][j] /= determ;
    }
  }
  return result;
}
