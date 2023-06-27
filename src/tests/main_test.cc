#include "test.h"



// TEST(S21MatrixTest, SumMatrixTest) {
//   S21Matrix a(2, 2);
//   S21Matrix b(2, 2);
//   S21Matrix expected(2, 2);

//   a(0, 0) = 1;
//   a(0, 1) = 2;
//   a(1, 0) = 3;
//   a(1, 1) = 4;

//   b(0, 0) = 5;
//   b(0, 1) = 6;
//   b(1, 0) = 7;
//   b(1, 1) = 8;

//   expected(0, 0) = 6;
//   expected(0, 1) = 8;
//   expected(1, 0) = 10;
//   expected(1, 1) = 12;

//   a.SumMatrix(b);
//   EXPECT_TRUE(a == expected);
// }
// TEST(S21MatrixTest, SubMatrixTest) {
//   S21Matrix a(2, 2);
//   S21Matrix b(2, 2);
//   S21Matrix expected(2, 2);

//   a(0, 0) = 4;
//   a(0, 1) = 4;
//   a(1, 0) = 6;
//   a(1, 1) = 6;

//   b(0, 0) = 2;
//   b(0, 1) = 2;
//   b(1, 0) = 3;
//   b(1, 1) = 3;

//   expected(0, 0) = 2;
//   expected(0, 1) = 2;
//   expected(1, 0) = 3;
//   expected(1, 1) = 3;

//   a.SubMatrix(b);
//   EXPECT_TRUE(a == expected);
// }

// TEST(S21MatrixTest, MulMatrixTest) {
//   S21Matrix a(2, 2);
//   S21Matrix b(2, 2);
//   S21Matrix expected(2, 2);

//   a(0, 0) = 1;
//   a(0, 1) = 2;
//   a(1, 0) = 3;
//   a(1, 1) = 4;

//   b(0, 0) = 5;
//   b(0, 1) = 6;
//   b(1, 0) = 7;
//   b(1, 1) = 8;

//   expected(0, 0) = 19;
//   expected(0, 1) = 22;
//   expected(1, 0) = 43;
//   expected(1, 1) = 50;

//   a.MulMatrix(b);

//   EXPECT_TRUE(a == expected);
// }
// TEST(S21MatrixTest, MulNumberTest) {
//   S21Matrix a(2, 2);
//   S21Matrix expected(2, 2);

//   a(0, 0) = 1;
//   a(0, 1) = 2;
//   a(1, 0) = 3;
//   a(1, 1) = 4;

//   expected(0, 0) = 2;
//   expected(0, 1) = 4;
//   expected(1, 0) = 6;
//   expected(1, 1) = 8;

//   a.MulNumber(2);

//   EXPECT_TRUE(a == expected);
// }
// TEST(S21MatrixTest, EqTest) {
//   S21Matrix a(2, 2);
//   S21Matrix b(2, 2);

//   a(0, 0) = 1;
//   a(0, 1) = 2;
//   a(1, 0) = 3;
//   a(1, 1) = 4;

//   b(0, 0) = 1;
//   b(0, 1) = 2;
//   b(1, 0) = 3;
//   b(1, 1) = 4;

//   EXPECT_TRUE(a.EqMatrix(b));
// }
// TEST(Test, EQmatrix) {
//   S21Matrix A;
//   S21Matrix B;
//   EXPECT_THROW(A == B, std::length_error);
// }

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}