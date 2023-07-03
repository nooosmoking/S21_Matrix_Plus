#include "test.h"
using namespace std;

TEST(MulTest, MulRandNumber) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  double num = GetRand(DBL_MIN * 2, DBL_MAX / 2);
  S21Matrix expected(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] * num;
    }
  }

  a.MulNumber(num);
  EXPECT_TRUE(a == expected);
}

TEST(MulTest, MulCasualNumber) {
  int size = 3;
  S21Matrix a(size, size);
  double num = 1000;
  S21Matrix expected(size, size);

  a.GetMatrix()[0][0] = 1;
  a.GetMatrix()[0][1] = 2;
  a.GetMatrix()[0][2] = 3;
  a.GetMatrix()[1][0] = 4;
  a.GetMatrix()[1][1] = 5;
  a.GetMatrix()[1][2] = 6;
  a.GetMatrix()[2][0] = 7;
  a.GetMatrix()[2][1] = 8;
  a.GetMatrix()[2][2] = 9;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] * num;
    }
  }

  a.MulNumber(num);
  EXPECT_TRUE(a == expected);
}

TEST(MulTest, MulNegNumber) {
  int size = 3;
  S21Matrix a(size, size);
  double num = -0.1;
  S21Matrix expected(size, size);

  a.GetMatrix()[0][0] = 1;
  a.GetMatrix()[0][1] = 2;
  a.GetMatrix()[0][2] = 3;
  a.GetMatrix()[1][0] = 4;
  a.GetMatrix()[1][1] = 5;
  a.GetMatrix()[1][2] = 6;
  a.GetMatrix()[2][0] = 7;
  a.GetMatrix()[2][1] = 8;
  a.GetMatrix()[2][2] = 9;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] * num;
    }
  }

  a.MulNumber(num);
  EXPECT_TRUE(a == expected);
}

TEST(MulTest, MulSignRandNumber1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  double num = GetRand(DBL_MIN * 2, DBL_MAX / 2);
  S21Matrix expected(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] * num;
    }
  }

  a *= num;
  EXPECT_TRUE(a == expected);
}

TEST(MulTest, MulSignCasualNumber1) {
  int size = 3;
  S21Matrix a(size, size);
  double num = 1000;
  S21Matrix expected(size, size);

  a.GetMatrix()[0][0] = 1;
  a.GetMatrix()[0][1] = 2;
  a.GetMatrix()[0][2] = 3;
  a.GetMatrix()[1][0] = 4;
  a.GetMatrix()[1][1] = 5;
  a.GetMatrix()[1][2] = 6;
  a.GetMatrix()[2][0] = 7;
  a.GetMatrix()[2][1] = 8;
  a.GetMatrix()[2][2] = 9;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] * num;
    }
  }

  a *= num;
  EXPECT_TRUE(a == expected);
}

TEST(MulTest, MulSignNegNumber1) {
  int size = 3;
  S21Matrix a(size, size);
  double num = -0.1;
  S21Matrix expected(size, size);

  a.GetMatrix()[0][0] = 1;
  a.GetMatrix()[0][1] = 2;
  a.GetMatrix()[0][2] = 3;
  a.GetMatrix()[1][0] = 4;
  a.GetMatrix()[1][1] = 5;
  a.GetMatrix()[1][2] = 6;
  a.GetMatrix()[2][0] = 7;
  a.GetMatrix()[2][1] = 8;
  a.GetMatrix()[2][2] = 9;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] * num;
    }
  }

  a *= num;
  EXPECT_TRUE(a == expected);
}

TEST(MulTest, MulSignRandNumber2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  double num = GetRand(DBL_MIN * 2, DBL_MAX / 2);
  S21Matrix expected(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] * num;
    }
  }

  S21Matrix res = a * num;
  EXPECT_TRUE(res == expected);
}

TEST(MulTest, MulSignCasualNumber2) {
  int size = 3;
  S21Matrix a(size, size);
  double num = 1000;
  S21Matrix expected(size, size);

  a.GetMatrix()[0][0] = 1;
  a.GetMatrix()[0][1] = 2;
  a.GetMatrix()[0][2] = 3;
  a.GetMatrix()[1][0] = 4;
  a.GetMatrix()[1][1] = 5;
  a.GetMatrix()[1][2] = 6;
  a.GetMatrix()[2][0] = 7;
  a.GetMatrix()[2][1] = 8;
  a.GetMatrix()[2][2] = 9;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] * num;
    }
  }

  S21Matrix res = a * num;
  EXPECT_TRUE(res == expected);
}

TEST(MulTest, MulSignNegNumber2) {
  int size = 3;
  S21Matrix a(size, size);
  double num = -0.1;
  S21Matrix expected(size, size);

  a.GetMatrix()[0][0] = 1;
  a.GetMatrix()[0][1] = 2;
  a.GetMatrix()[0][2] = 3;
  a.GetMatrix()[1][0] = 4;
  a.GetMatrix()[1][1] = 5;
  a.GetMatrix()[1][2] = 6;
  a.GetMatrix()[2][0] = 7;
  a.GetMatrix()[2][1] = 8;
  a.GetMatrix()[2][2] = 9;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      expected.GetMatrix()[i][j] = a.GetMatrix()[i][j] * num;
    }
  }

  S21Matrix res = a * num;
  EXPECT_TRUE(res == expected);
}