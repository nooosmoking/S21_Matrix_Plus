#include "test.h"

TEST(TransposeTest, TransposeRandMatrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  S21Matrix a(rows, cols);
  S21Matrix expected( cols, rows);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        double rand_val = GetRand(DBL_MIN, DBL_MAX);
      a.GetMatrix()[i][j] = rand_val;
      expected.GetMatrix()[j][i] = rand_val;
    }
  }

  S21Matrix res = a.Transpose();
  EXPECT_TRUE(res == expected);
}

