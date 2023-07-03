#include "test.h"

TEST(GetSet, IncreaseDecrease) {
  S21Matrix A(1, 1);
  A.GetMatrix()[0][0] = 1;

  A.SetCols(10);
  A.SetRows(11);

  EXPECT_EQ(11, A.GetRows());
  EXPECT_EQ(10, A.GetCols());
  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++)
      if (i == 0 && j == 0)
        EXPECT_EQ(1, A.GetMatrix()[0][0]);
      else
        ASSERT_EQ(A.GetMatrix()[i][j], 0);
  }

  A.SetCols(1);
  A.SetRows(1);

  EXPECT_EQ(1, A.GetRows());
  EXPECT_EQ(1, A.GetCols());

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) ASSERT_EQ(A.GetMatrix()[i][j], 1);
  }
}

TEST(GetSet, NegativeGetSet) {
  S21Matrix A(1, 1);
  EXPECT_THROW(A.SetCols(-10), std::invalid_argument);
}

TEST(GetSet, NullGetSet) {
  S21Matrix A;
  EXPECT_THROW(A.SetRows(0), std::invalid_argument);
}