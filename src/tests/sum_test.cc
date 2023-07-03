#include "test.h"
using namespace std;

TEST(SumTest, SumRandMatrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows, cols);
  S21Matrix expected(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      b.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] + b.GetMatrix()[i][j];
    }
  }

  a.SumMatrix(b);
  EXPECT_TRUE(a == expected);
}

TEST(SumTest, SumCasualMatrix) {
  int size = 3;
  S21Matrix a(size, size);
  S21Matrix b(size, size);
  S21Matrix expected(size, size);

  a.GetMatrix()[0][0] = b.GetMatrix()[0][0] = 1;
  a.GetMatrix()[0][1] = b.GetMatrix()[0][1] = 2;
  a.GetMatrix()[0][2] = b.GetMatrix()[0][2] = 3;
  a.GetMatrix()[1][0] = b.GetMatrix()[1][0] = 4;
  a.GetMatrix()[1][1] = b.GetMatrix()[1][1] = 5;
  a.GetMatrix()[1][2] = b.GetMatrix()[1][2] = 6;
  a.GetMatrix()[2][0] = b.GetMatrix()[2][0] = 7;
  a.GetMatrix()[2][1] = b.GetMatrix()[2][1] = 8;
  a.GetMatrix()[2][2] = b.GetMatrix()[2][2] = 9;

  expected.GetMatrix()[0][0] = 2;
  expected.GetMatrix()[0][1] = 4;
  expected.GetMatrix()[0][2] = 6;
  expected.GetMatrix()[1][0] = 8;
  expected.GetMatrix()[1][1] = 10;
  expected.GetMatrix()[1][2] = 12;
  expected.GetMatrix()[2][0] = 14;
  expected.GetMatrix()[2][1] = 16;
  expected.GetMatrix()[2][2] = 18;

  a.SumMatrix(b);
  EXPECT_TRUE(a == expected);
}

TEST(SumTest, SumDiffMatrix) {
  int size = 3;
  S21Matrix a(size, size);
  S21Matrix b(size - 1, size);

  ASSERT_THROW(a.SumMatrix(b), std::invalid_argument);
}

TEST(SumTest, AddSignRandMatrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows, cols);
  S21Matrix expected(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      b.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] + b.GetMatrix()[i][j];
    }
  }

  a += b;
  EXPECT_TRUE(a == expected);
}

TEST(SumTest, AddSignCasualMatrix) {
  int size = 3;
  S21Matrix a(size, size);
  S21Matrix b(size, size);
  S21Matrix expected(size, size);

  a.GetMatrix()[0][0] = b.GetMatrix()[0][0] = 1;
  a.GetMatrix()[0][1] = b.GetMatrix()[0][1] = 2;
  a.GetMatrix()[0][2] = b.GetMatrix()[0][2] = 3;
  a.GetMatrix()[1][0] = b.GetMatrix()[1][0] = 4;
  a.GetMatrix()[1][1] = b.GetMatrix()[1][1] = 5;
  a.GetMatrix()[1][2] = b.GetMatrix()[1][2] = 6;
  a.GetMatrix()[2][0] = b.GetMatrix()[2][0] = 7;
  a.GetMatrix()[2][1] = b.GetMatrix()[2][1] = 8;
  a.GetMatrix()[2][2] = b.GetMatrix()[2][2] = 9;

  expected.GetMatrix()[0][0] = 2;
  expected.GetMatrix()[0][1] = 4;
  expected.GetMatrix()[0][2] = 6;
  expected.GetMatrix()[1][0] = 8;
  expected.GetMatrix()[1][1] = 10;
  expected.GetMatrix()[1][2] = 12;
  expected.GetMatrix()[2][0] = 14;
  expected.GetMatrix()[2][1] = 16;
  expected.GetMatrix()[2][2] = 18;

  a += b;
  EXPECT_TRUE(a == expected);
}

TEST(SumTest, AddSignDiffMatrix) {
  int size = 3;
  S21Matrix a(size, size);
  S21Matrix b(size - 1, size);

  ASSERT_THROW(a += b, std::invalid_argument);
}

TEST(SumTest, AddTwoRandMatrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows, cols);
  S21Matrix expected(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      b.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] + b.GetMatrix()[i][j];
    }
  }

  S21Matrix res = a + b;
  EXPECT_TRUE(res == expected);
}

TEST(SumTest, AddTwoCasualMatrix) {
  int size = 3;
  S21Matrix a(size, size);
  S21Matrix b(size, size);
  S21Matrix expected(size, size);

  a.GetMatrix()[0][0] = b.GetMatrix()[0][0] = 1;
  a.GetMatrix()[0][1] = b.GetMatrix()[0][1] = 2;
  a.GetMatrix()[0][2] = b.GetMatrix()[0][2] = 3;
  a.GetMatrix()[1][0] = b.GetMatrix()[1][0] = 4;
  a.GetMatrix()[1][1] = b.GetMatrix()[1][1] = 5;
  a.GetMatrix()[1][2] = b.GetMatrix()[1][2] = 6;
  a.GetMatrix()[2][0] = b.GetMatrix()[2][0] = 7;
  a.GetMatrix()[2][1] = b.GetMatrix()[2][1] = 8;
  a.GetMatrix()[2][2] = b.GetMatrix()[2][2] = 9;

  expected.GetMatrix()[0][0] = 2;
  expected.GetMatrix()[0][1] = 4;
  expected.GetMatrix()[0][2] = 6;
  expected.GetMatrix()[1][0] = 8;
  expected.GetMatrix()[1][1] = 10;
  expected.GetMatrix()[1][2] = 12;
  expected.GetMatrix()[2][0] = 14;
  expected.GetMatrix()[2][1] = 16;
  expected.GetMatrix()[2][2] = 18;

  S21Matrix res = a + b;
  EXPECT_TRUE(res == expected);
}

TEST(SumTest, AddTwoDiffMatrix) {
  int size = 3;
  S21Matrix a(size, size);
  S21Matrix b(size - 1, size);

  ASSERT_THROW(a + b, std::invalid_argument);
}