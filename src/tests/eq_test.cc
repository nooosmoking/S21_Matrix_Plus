#include "test.h"

TEST(SumTest, EqRandMatrix1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        double rand_val =  GetRand(DBL_MIN , DBL_MAX );
      a.GetMatrix()[i][j] = rand_val;
      b.GetMatrix()[i][j] = rand_val;
    }
  }

  EXPECT_TRUE(a.EqMatrix(b));
}

TEST(SumTest, EqRandMatrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        double rand_val =  GetRand(DBL_MIN , DBL_MAX );
      a.GetMatrix()[i][j] = rand_val;
      b.GetMatrix()[i][j] = rand_val;
    }
  }

  EXPECT_TRUE(b.EqMatrix(a));
}

TEST(SumTest, EqRandMatrix3) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        double rand_val =  GetRand(DBL_MIN , DBL_MAX );
      a.GetMatrix()[i][j] = rand_val;
      b.GetMatrix()[i][j] = rand_val;
    }
  }

  EXPECT_TRUE(b == a);
}

TEST(SumTest, NotEqMatrix1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
       a.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      b.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
    }
  }
  EXPECT_FALSE(a.EqMatrix(b));
}

TEST(SumTest, NotEqMatrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
       a.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      b.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
    }
  }
  EXPECT_FALSE(b.EqMatrix(a));
}

TEST(SumTest, NotEqMatrix3) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
       a.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
      b.GetMatrix()[i][j] = GetRand(DBL_MIN * 2, DBL_MAX / 2);
    }
  }
  EXPECT_FALSE(a == b);
}

TEST(SumTest, NotEqSize1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix b(rows+1, cols);

  EXPECT_FALSE(a.EqMatrix(b));
}

TEST(SumTest, NotEqSize2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  int cols1 = cols + 1;
  S21Matrix a(rows, cols1);
  S21Matrix b(rows, cols);

  EXPECT_FALSE(a.EqMatrix(b));
}
