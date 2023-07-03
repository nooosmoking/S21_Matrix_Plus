#include "test.h"
using namespace std;

TEST(MulMatrixTest, MulRandMatrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(cols, rows);
  S21Matrix expected(rows, rows);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) a.GetMatrix()[i][j] = GetRand(-10e10, 10e10);

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++) b.GetMatrix()[i][j] = GetRand(-10e10, 10e10);

  for (int i = 0; i < a.GetRows(); i++) {
    for (int j = 0; j < b.GetCols(); j++) {
      expected.GetMatrix()[i][j] = 0;
      for (int k = 0; k < a.GetCols(); k++)
        expected.GetMatrix()[i][j] += a.GetMatrix()[i][k] * b.GetMatrix()[k][j];
    }
  }
  a.MulMatrix(b);
  EXPECT_TRUE(a == expected);
}

TEST(MulMatrixTest, MulCasualMatrix) {
  int rows = 2;
  int cols = 3;
  S21Matrix a(rows, cols);
  S21Matrix b(cols, rows);
  S21Matrix expected(rows, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) a.GetMatrix()[i][j] = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) b.GetMatrix()[i][j] = c++;

  expected.GetMatrix()[0][0] = 58;
  expected.GetMatrix()[0][1] = 64;
  expected.GetMatrix()[1][0] = 139;
  expected.GetMatrix()[1][1] = 154;

  a.MulMatrix(b);
  EXPECT_TRUE(a == expected);
}

TEST(MulMatrixTest, MulDiffMatrix) {
  int size = 3;
  S21Matrix a(size, size);
  S21Matrix b(size - 1, size);

  ASSERT_THROW(a.MulMatrix(b), std::invalid_argument);
}

TEST(MulMatrixTest, MulSignRandMatrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(cols, rows);
  S21Matrix expected(rows, rows);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) a.GetMatrix()[i][j] = GetRand(-10e10, 10e10);

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++) b.GetMatrix()[i][j] = GetRand(-10e10, 10e10);

  for (int i = 0; i < a.GetRows(); i++) {
    for (int j = 0; j < b.GetCols(); j++) {
      expected.GetMatrix()[i][j] = 0;
      for (int k = 0; k < a.GetCols(); k++)
        expected.GetMatrix()[i][j] += a.GetMatrix()[i][k] * b.GetMatrix()[k][j];
    }
  }
  a *= b;

  EXPECT_TRUE(a == expected);
}

TEST(MulMatrixTest, MulSignCasualMatrix) {
  int rows = 2;
  int cols = 3;
  S21Matrix a(rows, cols);
  S21Matrix b(cols, rows);
  S21Matrix expected(rows, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) a.GetMatrix()[i][j] = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) b.GetMatrix()[i][j] = c++;

  expected.GetMatrix()[0][0] = 58;
  expected.GetMatrix()[0][1] = 64;
  expected.GetMatrix()[1][0] = 139;
  expected.GetMatrix()[1][1] = 154;

  a *= b;
  EXPECT_TRUE(a == expected);
}

TEST(MulMatrixTest, MulSignDiffMatrix) {
  int size = 3;
  S21Matrix a(size, size);
  S21Matrix b(size - 1, size);

  ASSERT_THROW(a *= b, std::invalid_argument);
}

TEST(MulMatrixTest, MulTwoRandMatrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(cols, rows);
  S21Matrix expected(rows, rows);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) a.GetMatrix()[i][j] = GetRand(-10e10, 10e10);

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++) b.GetMatrix()[i][j] = GetRand(-10e10, 10e10);

  for (int i = 0; i < a.GetRows(); i++) {
    for (int j = 0; j < b.GetCols(); j++) {
      expected.GetMatrix()[i][j] = 0;
      for (int k = 0; k < a.GetCols(); k++)
        expected.GetMatrix()[i][j] += a.GetMatrix()[i][k] * b.GetMatrix()[k][j];
    }
  }

  S21Matrix res = a * b;
  EXPECT_TRUE(res == expected);
}

TEST(MulMatrixTest, MulTwoCasualMatrix) {
  int rows = 2;
  int cols = 3;
  S21Matrix a(rows, cols);
  S21Matrix b(cols, rows);
  S21Matrix expected(rows, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) a.GetMatrix()[i][j] = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) b.GetMatrix()[i][j] = c++;

  expected.GetMatrix()[0][0] = 58;
  expected.GetMatrix()[0][1] = 64;
  expected.GetMatrix()[1][0] = 139;
  expected.GetMatrix()[1][1] = 154;

  S21Matrix res = a * b;
  EXPECT_TRUE(res == expected);
}

TEST(MulMatrixTest, MulTwoDiffMatrix) {
  int size = 3;
  S21Matrix a(size, size);
  S21Matrix b(size - 1, size);

  ASSERT_THROW(a * b, std::invalid_argument);
}