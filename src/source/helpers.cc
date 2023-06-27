#include "../s21_matrix_oop.h"
using namespace std;

bool S21Matrix::IsMatrix() const {
  if (this->GetRows() < 1 || this->GetCols() < 1 ||
      this->GetMatrix() == nullptr)
    throw invalid_argument("Incorrect matrix!");
  return true;
}

bool S21Matrix::IsSquare() const { return this->GetCols() == this->GetRows(); }
bool S21Matrix::IsEqSize(const S21Matrix& other) const {
  return (this->GetCols() == other.GetCols()) &&
         (this->GetRows() == other.GetRows());
}