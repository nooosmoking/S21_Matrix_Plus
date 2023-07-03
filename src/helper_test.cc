#include "test.h"

TEST(Helpers, NormalIsMatrix) {
  S21Matrix A(3, 4);
  EXPECT_EQ(true, A.IsMatrix());
}

TEST(Helpers, NormalIsSquare) {
  S21Matrix A(100, 100);
  EXPECT_EQ(true, A.IsSquare());
}

TEST(Helpers, NegativeIsSquare) {
  S21Matrix A(101, 100);
  EXPECT_EQ(false, A.IsSquare());
}

TEST(Helpers, NormalIsEqSize) {
  S21Matrix A(101, 100);
  S21Matrix B(101, 100);
  EXPECT_EQ(true, A.IsEqSize(B));
}

TEST(Helpers, NegativeIsEqSize1) {
  S21Matrix A(101, 100);
  S21Matrix B(100, 100);
  EXPECT_EQ(false, A.IsEqSize(B));
}

TEST(Helpers, NegativeIsEqSize2) {
  S21Matrix A(100, 101);
  S21Matrix B(100, 100);
  EXPECT_EQ(false, A.IsEqSize(B));
}

TEST(Helpers, NegativeIsEqSiz3) {
  S21Matrix A(101, 100);
  S21Matrix B(100, 100);
  EXPECT_EQ(false, B.IsEqSize(A));
}