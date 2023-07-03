#include "test.h"

TEST(Constructor, DefaultConstructor) {
  S21Matrix matrix;

  ASSERT_EQ(matrix.GetRows(), 2);
  ASSERT_EQ(matrix.GetCols(), 2);
  ASSERT_NE(matrix.GetMatrix(), nullptr);
  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++)
      ASSERT_EQ(matrix.GetMatrix()[i][j], 0);
  }
}

TEST(Constructor, NormalConstructor) {
  S21Matrix matrix(10, 11);
  ASSERT_EQ(matrix.GetRows(), 10);
  ASSERT_EQ(matrix.GetCols(), 11);
  ASSERT_NE(matrix.GetMatrix(), nullptr);
  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++)
      ASSERT_EQ(matrix.GetMatrix()[i][j], 0);
  }
}

TEST(Constructor, NegativeConstructor) {
  ASSERT_THROW(S21Matrix matrix(0, 10), std::invalid_argument);
  ASSERT_THROW(S21Matrix matrix(10, 0), std::invalid_argument);
}

TEST(Constructor, MoveConstructor) {
  S21Matrix A(5, 5);
  S21Matrix B(std::move(A));
  EXPECT_EQ(5, B.GetRows());
  EXPECT_EQ(5, B.GetCols());
  EXPECT_NE(nullptr, B.GetMatrix());
  for (int i = 0; i < B.GetRows(); i++) {
    for (int j = 0; j < B.GetCols(); j++) ASSERT_EQ(B.GetMatrix()[i][j], 0);
  }
  EXPECT_EQ(0, A.GetRows());
  EXPECT_EQ(0, A.GetCols());
  EXPECT_EQ(nullptr, A.GetMatrix());
}

TEST(Constructor, CopyConstructor) {
  S21Matrix A(3, 4);
  S21Matrix B(A);
  EXPECT_EQ(3, B.GetRows());
  EXPECT_EQ(4, B.GetCols());
  for (int i = 0; i < B.GetRows(); i++) {
    for (int j = 0; j < B.GetCols(); j++) ASSERT_EQ(B.GetMatrix()[i][j], 0);
  }
  EXPECT_EQ(1, A == B);
}
