#include "test.h"

TEST(DetermTest, DetermNormalMatrix1) {
  int size = 5;
  S21Matrix a(size, size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      a.GetMatrix()[i][j] = j;
    }
  }
double determ = a.Determinant();
  ASSERT_EQ(determ, 0);
}

TEST(DetermTest, DetermNormalMatrix2) {
  int size = 4;
  S21Matrix a(size, size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      a.GetMatrix()[i][j] = j + i;
    }
  }
double determ = a.Determinant();
  ASSERT_EQ(determ, 0);
}

TEST(DetermTest, DetermNormalMatrix3) {
  int size = 5;
  S21Matrix a(size, size);

  a.GetMatrix()[0][1] = 6;
  a.GetMatrix()[0][2] = -2;
  a.GetMatrix()[0][3] = -1;
  a.GetMatrix()[0][4] = 5;
  a.GetMatrix()[1][3] = -9;
  a.GetMatrix()[1][4] = -7;
  a.GetMatrix()[2][1] = 15;
  a.GetMatrix()[2][2] = 35;
  a.GetMatrix()[3][1] = -1;
  a.GetMatrix()[3][2] = -11;
  a.GetMatrix()[3][3] = -2;
  a.GetMatrix()[3][4] = 1;
  a.GetMatrix()[4][0] = -2;
  a.GetMatrix()[4][1] = -2;
  a.GetMatrix()[4][2] = 3;
  a.GetMatrix()[4][4] = -2;

  double determ = a.Determinant();
  ASSERT_EQ(determ, 2480);
}

TEST(DetermTest, DetermNormalMatrix4) {
  int size = 3;
  S21Matrix a(size, size);

  a.GetMatrix()[0][0] = 2;
  a.GetMatrix()[0][1] = 3;
  a.GetMatrix()[0][2] = 1;
  a.GetMatrix()[1][0] = 7;
  a.GetMatrix()[1][1] = 4;
  a.GetMatrix()[1][2] = 1;
  a.GetMatrix()[2][0] = 9;
  a.GetMatrix()[2][1] = -2;
  a.GetMatrix()[2][2] = 1;

  double determ = a.Determinant();
  ASSERT_EQ(determ, -32);
}