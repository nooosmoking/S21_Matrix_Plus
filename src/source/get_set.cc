#include "../s21_matrix_oop.h"
using namespace std;

int S21Matrix::GetRows() const { return this->rows_; }

int S21Matrix::GetCols() const { return this->cols_; }

double** S21Matrix::GetMatrix() const { return this->matrix_; }

void S21Matrix::SetRows(int size) {
  if (size < 1)
    throw invalid_argument("Size of raws should be a positive number!");

  S21Matrix tmp(size, this->GetCols());
  for (int i = 0; i < tmp.GetRows(); i++) {
    for (int j = 0; j < tmp.GetCols(); j++) {
      if (i < this->GetRows())
        tmp.matrix_[i][j] = this->matrix_[i][j];
      else
        tmp.matrix_[i][j] = 0;
    }
  }
  *this = tmp;
}

void S21Matrix::SetCols(int size) {
  if (size < 1)
    throw invalid_argument("Size of columns should be a positive number!");

  S21Matrix tmp(this->GetRows(), size);
  for (int i = 0; i < tmp.GetRows(); i++) {
    for (int j = 0; j < tmp.GetCols(); j++) {
      if (j < this->GetCols())
        tmp.matrix_[i][j] = this->matrix_[i][j];
      else
        tmp.matrix_[i][j] = 0;
    }
  }
  *this = tmp;
}