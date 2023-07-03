#include "test.h"
using namespace std;

TEST(SubTest, SubRandMatrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows, cols);
  S21Matrix expected(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      b.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] - b.GetMatrix()[i][j];
    }
  }

  a.SubMatrix(b);
  EXPECT_TRUE(a == expected);
}

TEST(SubTest, SubCasualMatrix) {
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

  expected.GetMatrix()[0][0] = 0;
  expected.GetMatrix()[0][1] = 0;
  expected.GetMatrix()[0][2] = 0;
  expected.GetMatrix()[1][0] = 0;
  expected.GetMatrix()[1][1] = 0;
  expected.GetMatrix()[1][2] = 0;
  expected.GetMatrix()[2][0] = 0;
  expected.GetMatrix()[2][1] = 0;
  expected.GetMatrix()[2][2] = 0;

  a.SubMatrix(b);
  EXPECT_TRUE(a == expected);
}

TEST(SubTest, SubDiffMatrix) {
  int size = 3;
  S21Matrix a(size, size);
  S21Matrix b(size - 1, size);

  ASSERT_THROW(a.SubMatrix(b), std::invalid_argument);
}

TEST(SubTest, SubSignRandMatrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows, cols);
  S21Matrix expected(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      b.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] - b.GetMatrix()[i][j];
    }
  }

  a -= b;
  EXPECT_TRUE(a == expected);
}

TEST(SubTest, SubSignCasualMatrix) {
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

  expected.GetMatrix()[0][0] = 0;
  expected.GetMatrix()[0][1] = 0;
  expected.GetMatrix()[0][2] = 0;
  expected.GetMatrix()[1][0] = 0;
  expected.GetMatrix()[1][1] = 0;
  expected.GetMatrix()[1][2] = 0;
  expected.GetMatrix()[2][0] = 0;
  expected.GetMatrix()[2][1] = 0;
  expected.GetMatrix()[2][2] = 0;

  a -= b;
  EXPECT_TRUE(a == expected);
}

TEST(SubTest, SubSignDiffMatrix) {
  int size = 3;
  S21Matrix a(size, size);
  S21Matrix b(size - 1, size);

  ASSERT_THROW(a -= b, std::invalid_argument);
}

TEST(SubTest, SubTwoRandMatrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows, cols);
  S21Matrix expected(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      b.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] - b.GetMatrix()[i][j];
    }
  }

  S21Matrix res = a - b;
  EXPECT_TRUE(res == expected);
}

TEST(SubTest, SubTwoCasualMatrix) {
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

  expected.GetMatrix()[0][0] = 0;
  expected.GetMatrix()[0][1] = 0;
  expected.GetMatrix()[0][2] = 0;
  expected.GetMatrix()[1][0] = 0;
  expected.GetMatrix()[1][1] = 0;
  expected.GetMatrix()[1][2] = 0;
  expected.GetMatrix()[2][0] = 0;
  expected.GetMatrix()[2][1] = 0;
  expected.GetMatrix()[2][2] = 0;

  S21Matrix res = a - b;
  EXPECT_TRUE(res == expected);
}

TEST(SubTest, SubTwoDiffMatrix) {
  int size = 3;
  S21Matrix a(size, size);
  S21Matrix b(size - 1, size);

  ASSERT_THROW(a - b, std::invalid_argument);
}