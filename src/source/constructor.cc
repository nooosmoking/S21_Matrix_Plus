#include "../s21_matrix_oop.h"
using namespace std;

S21Matrix::S21Matrix() { this->InitMatrix(2, 2); }

S21Matrix::S21Matrix(int rows, int cols) { this->InitMatrix(rows, cols); }

S21Matrix::S21Matrix(const S21Matrix& other) {
  this->InitMatrix(other.rows_, other.cols_);
  this->CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  this->InitMatrix(other.rows_, other.cols_);
  this->CopyMatrix(other);
  other.RemoveMatrix();
}

S21Matrix::~S21Matrix() { this->RemoveMatrix(); }

void S21Matrix::InitMatrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw invalid_argument(
        "Size of raws and columns should be a positive number!");
  }
  this->matrix_ = new double*[rows];
  if (this->matrix_ == nullptr) {
    throw bad_alloc();
  }
  for (int i = 0; i < rows; i++) {
    this->matrix_[i] = new double[cols];
    if (this->matrix_[i] == nullptr) {
      for (int k = 0; k < i; k++) {
        delete[] this->matrix_[k];
      }
      delete[] this->matrix_;
      throw bad_alloc();
    }
  }
  this->cols_ = cols;
  this->rows_ = rows;

  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) this->matrix_[i][j] = 0;
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  other.IsMatrix();

  for (int i = 0; i < other.GetRows(); i++) {
    for (int j = 0; j < other.GetCols(); j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::RemoveMatrix() {
  if (this->GetMatrix() != nullptr) {
    for (int i = 0; i < this->rows_; i++) {
      if (this->matrix_[i] != nullptr) {
        delete[] this->matrix_[i];
        this->matrix_[i] = nullptr;
      }
    }
    delete[] this->matrix_;
    this->matrix_ = nullptr;
    this->rows_ = this->cols_ = 0;
  }
}