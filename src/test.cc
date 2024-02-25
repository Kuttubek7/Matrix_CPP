#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(EqMatrixSuite, eq2) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(0, 0) = 4.3;
  a(0, 1) = 3;
  a(0, 2) = 7;
  a(1, 0) = 11.3;
  a(1, 1) = -1.3;
  a(1, 2) = -1;
  b(0, 0) = 4.3;
  b(0, 1) = 3;
  b(1, 0) = 11.3;
  b(1, 1) = -1.3;
  EXPECT_FALSE(a.EqMatrix(b));
}  // SUCCES

TEST(MulMatrix, MulMatrix1) {
  S21Matrix a(3, 2);
  S21Matrix b(2, 3);
  a(0, 0) = 1;
  a(0, 1) = 4;

  a(1, 0) = 2;
  a(1, 1) = 5;

  a(2, 0) = 3;
  a(2, 1) = 6;

  b(0, 0) = 1;
  b(0, 1) = -1;
  b(0, 2) = 1;

  b(1, 0) = 2;
  b(1, 1) = 3;
  b(1, 2) = 4;
  S21Matrix res(3, 3);
  res(0, 0) = 9;
  res(0, 1) = 11;
  res(0, 2) = 17;
  res(1, 0) = 12;
  res(1, 1) = 13;
  res(1, 2) = 22;
  res(2, 0) = 15;
  res(2, 1) = 15;
  res(2, 2) = 27;
  a.MulMatrix(b);
  EXPECT_TRUE(a.EqMatrix(res));
}  // FAILED

TEST(MulMatrix, MulMatrix3) {
  S21Matrix a(3, 2);
  a(0, 0) = 1;
  a(0, 1) = 4;
  a(1, 0) = 2;
  a(1, 1) = 5;
  a(2, 0) = 3;
  a(2, 1) = 6;
  S21Matrix b(2, 3);
  b(0, 0) = 1;
  b(0, 1) = -1;
  b(0, 2) = 1;
  b(1, 0) = 2;
  b(1, 1) = 3;
  b(1, 2) = 4;
  S21Matrix res(3, 3);
  res(0, 0) = 9;
  res(0, 1) = 11;
  res(0, 2) = 17;
  res(1, 0) = 12;
  res(1, 1) = 13;
  res(1, 2) = 22;
  res(2, 0) = 15;
  res(2, 1) = 15;
  res(2, 2) = 27;
  EXPECT_TRUE(a * b == res);
}  // FAILED

TEST(Test, MulMatrixOp2) {
  S21Matrix a(3, 2);
  a(0, 0) = 1;
  a(0, 1) = 4;
  a(1, 0) = 2;
  a(1, 1) = 5;
  a(2, 0) = 3;
  a(2, 1) = 6;
  S21Matrix b(2, 3);
  b(0, 0) = 1;
  b(0, 1) = -1;
  b(0, 2) = 1;
  b(1, 0) = 2;
  b(1, 1) = 3;
  b(1, 2) = 4;
  S21Matrix res(3, 3);
  res(0, 0) = 9;
  res(0, 1) = 11;
  res(0, 2) = 17;
  res(1, 0) = 12;
  res(1, 1) = 13;
  res(1, 2) = 22;
  res(2, 0) = 15;
  res(2, 1) = 15;
  res(2, 2) = 27;
  EXPECT_TRUE(a * b == res);
}  // FAILED

TEST(Test, LeftMulMatrixOp2) {
  S21Matrix a(3, 2);
  a(0, 0) = 1;
  a(0, 1) = 4;
  a(1, 0) = 2;
  a(1, 1) = 5;
  a(2, 0) = 3;
  a(2, 1) = 6;
  S21Matrix b(2, 3);
  b(0, 0) = 1;
  b(0, 1) = -1;
  b(0, 2) = 1;
  b(1, 0) = 2;
  b(1, 1) = 3;
  b(1, 2) = 4;
  S21Matrix res(3, 3);
  res(0, 0) = 9;
  res(0, 1) = 11;
  res(0, 2) = 17;
  res(1, 0) = 12;
  res(1, 1) = 13;
  res(1, 2) = 22;
  res(2, 0) = 15;
  res(2, 1) = 15;
  res(2, 2) = 27;
  EXPECT_TRUE((a *= b) == res);
}  // FAILED

TEST(EqMatrixSuite, eq0) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(0, 0) = 4.3;
  a(0, 1) = 3;
  a(1, 0) = 11.3;
  a(1, 1) = -1.3;
  b(0, 0) = 4.3;
  b(0, 1) = 3;
  b(1, 0) = 11.3;
  b(1, 1) = -1.3;
  EXPECT_TRUE(a.EqMatrix(b));
}  // SUCCES

TEST(EqMatrixSuite, eq1) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(0, 0) = 4.3;
  a(0, 1) = 3;
  a(1, 0) = 11.3;
  a(1, 1) = -1.3;
  b(0, 0) = 4.3;
  b(0, 1) = 3;
  b(1, 0) = 10;
  b(1, 1) = -1.3;
  EXPECT_FALSE(a.EqMatrix(b));
}  // SUCCES

/*-----------------------------------------------------------------------------------------------*/

TEST(SumMatrixSuite, plus0) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  a.SumMatrix(b);
  EXPECT_DOUBLE_EQ(a(1, 1), 3.3);
}  // SUCCES

TEST(SumMatrixSuite, plus1) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  EXPECT_ANY_THROW(a.SumMatrix(b));
}  // SUCCES

TEST(SumMatrixSuite, plus2) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(0, 0) = 4.3;
  a(0, 1) = 3;
  a(0, 2) = 7;
  a(1, 0) = 11.3;
  a(1, 1) = -1.3;
  a(1, 2) = -1;
  b(0, 0) = 4.3;
  b(0, 1) = 3;
  b(1, 0) = 11.3;
  b(1, 1) = -1.3;
  EXPECT_THROW(a.SumMatrix(b), length_error);
}  // SUCCES

TEST(SumMatrixSuite, plus3) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(0, 0) = 4.3;
  a(0, 1) = 3;
  a(0, 2) = 7;
  a(1, 0) = 11.3;
  a(1, 1) = -1.3;
  a(1, 2) = -1;
  b(0, 0) = 4.3;
  b(0, 1) = 3;
  b(1, 0) = 11.3;
  b(1, 1) = -1.3;
  EXPECT_THROW(a.SumMatrix(b), length_error);
}  // SUCCES

TEST(SumMatrixSuite, plus4) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(0, 0) = 4.3;
  a(0, 1) = 3;
  a(1, 0) = 1;
  a(1, 1) = -1;
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  S21Matrix res(2, 2);
  res(0, 0) = 13;
  res(0, 1) = 3;
  res(1, 0) = -4;
  res(1, 1) = 5;
  a.SumMatrix(b);
  EXPECT_FALSE(a.EqMatrix(res));
}  // SUCCES

TEST(SumMatrixSuite, plus5) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(0, 0) = 4.3;
  a(0, 1) = 3;
  a(1, 0) = 0;
  a(1, 1) = -1;
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  S21Matrix res(2, 2);
  res(0, 0) = 13;
  res(0, 1) = 3;
  res(1, 0) = -4;
  res(1, 1) = 5;
  a.SumMatrix(b);
  EXPECT_FALSE(a.EqMatrix(res));
}  // SUCCES

/*-----------------------------------------------------------------------------------------------*/

TEST(SubMatrixSuite, minus0) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  a.SubMatrix(b);
  EXPECT_DOUBLE_EQ(a(1, 1), -1.1);
}  // SUCCES

TEST(SubMatrixSuite, minus1) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  EXPECT_ANY_THROW(a.SubMatrix(b));
}  // SUCCES

TEST(SubMatrixSuite, minus2) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a(0, 0) = 4.3;
  a(0, 1) = 3;
  a(0, 2) = 7;
  a(1, 0) = 11.3;
  a(1, 1) = -1.3;
  a(1, 2) = -1;
  b(0, 0) = 4.3;
  b(0, 1) = 3;
  b(1, 0) = 11.3;
  b(1, 1) = -1.3;
  EXPECT_THROW(a.SumMatrix(b), length_error);
}  // SUCCES

TEST(SubMatrixSuite, minus3) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 1;
  a(1, 1) = -1;
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  S21Matrix res(2, 2);
  res(0, 0) = -5;
  res(0, 1) = 3;
  res(1, 0) = 6;
  res(1, 1) = -7;
  a.SubMatrix(b);
  EXPECT_TRUE(a.EqMatrix(res));
}  // SUCCES

TEST(SubMatrixSuite, minus4) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 0;
  a(1, 1) = -1;
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  S21Matrix res(2, 2);
  res(0, 0) = -5;
  res(0, 1) = 3;
  res(1, 0) = 6;
  res(1, 1) = -7;
  a.SubMatrix(b);
  EXPECT_FALSE(a.EqMatrix(res));
}  // SUCCES

/*-----------------------------------------------------------------------------------------------*/

TEST(MulNumber, MulNumber0) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 0;
  a(1, 1) = -1;
  const double num = 2.5;
  S21Matrix res(2, 2);
  res(0, 0) = 10;
  res(0, 1) = 7.5;
  res(1, 0) = 0;
  res(1, 1) = -2.5;
  a.MulNumber(num);
  EXPECT_TRUE(a.EqMatrix(res));
}  // SUCCES

TEST(MulNUmber, MulNumber1) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 0;
  a(1, 1) = -1;
  const double num = 2.5;

  S21Matrix res(2, 2);
  res(0, 0) = 10;
  res(0, 1) = 7.5;
  res(1, 0) = 0;
  res(1, 1) = -2.5;

  EXPECT_TRUE(a * num == res);
}  // SUCCES

TEST(MulNumber, MulNumber2) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 0;
  a(1, 1) = -1;
  const double num = 2.5;
  S21Matrix res(2, 2);
  res(0, 0) = 10;
  res(0, 1) = 7.5;
  res(1, 0) = 0;
  res(1, 1) = -2.5;
  EXPECT_TRUE((a *= num) == res);
}  // SUCCES

/*-----------------------------------------------------------------------------------------------*/

TEST(MulMatrix, MulMatrix0) {
  S21Matrix a(3, 2);
  a(0, 0) = 1;
  a(0, 1) = 4;
  a(1, 0) = 2;
  a(1, 1) = 5;
  a(2, 0) = 3;
  a(2, 1) = 6;
  S21Matrix b(3, 4);
  b(0, 0) = 1;
  b(0, 1) = -1;
  b(0, 2) = 1;
  b(0, 3) = 4;
  b(1, 0) = 2;
  b(1, 1) = 3;
  b(1, 2) = 4;
  b(1, 3) = -5;
  b(2, 0) = 1;
  b(2, 1) = 1;
  b(2, 2) = 1;
  b(2, 3) = 1;
  EXPECT_THROW(a.MulMatrix(b), length_error);
}  // SUCCES

TEST(MulMatrix, MulMatrix2) {
  S21Matrix a(3, 2);
  a(0, 0) = 1;
  a(0, 1) = 4;
  a(1, 0) = 2;
  a(1, 1) = 5;
  a(2, 0) = 3;
  a(2, 1) = 6;
  S21Matrix b(3, 4);
  b(0, 0) = 1;
  b(0, 1) = -1;
  b(0, 2) = 1;
  b(0, 3) = 4;
  b(1, 0) = 2;
  b(1, 1) = 3;
  b(1, 2) = 4;
  b(1, 3) = -5;
  b(2, 0) = 1;
  b(2, 1) = 1;
  b(2, 2) = 1;
  b(2, 3) = 1;
  EXPECT_THROW(a * b, length_error);
}  // SUCCES

/*-----------------------------------------------------------------------------------------------*/

TEST(Transpose, transpose0) {
  S21Matrix result(2, 2);
  result(0, 0) = 1;
  result(0, 1) = 2;
  result(1, 0) = 4;
  result(1, 1) = 3;
  result = result.Transpose();
  EXPECT_EQ(result(0, 0), 1);
  EXPECT_EQ(result(0, 1), 4);
  EXPECT_EQ(result(1, 0), 2);
  EXPECT_EQ(result(1, 1), 3);
}  // SUCCES

TEST(Transpose, transpose1) {
  S21Matrix mat;
  EXPECT_THROW(mat.Transpose(), length_error);
}  // SUCCES

TEST(Transpose, transpose2) {
  S21Matrix a(3, 2);
  a(0, 0) = 1;
  a(0, 1) = 4;
  a(1, 0) = 2;
  a(1, 1) = 5;
  a(2, 0) = 3;
  a(2, 1) = 6;
  S21Matrix res(2, 3);
  res(0, 0) = 1;
  res(0, 1) = 2;
  res(0, 2) = 3;
  res(1, 0) = 4;
  res(1, 1) = 5;
  res(1, 2) = 6;
  S21Matrix temp(2, 3);
  temp = a.Transpose();
  EXPECT_TRUE(res.EqMatrix(temp));
}  // SUCCES

/*-----------------------------------------------------------------------------------------------*/

TEST(CalcComplements, CalcComplements1) {
  S21Matrix exception(4, 3);
  EXPECT_ANY_THROW(exception.CalcComplements());
}  // SUCCES

TEST(CalcComplements, CalcComplements2) {
  S21Matrix a(3, 3);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 0;
  a(1, 1) = 4;
  a(1, 2) = 2;
  a(2, 0) = 5;
  a(2, 1) = 2;
  a(2, 2) = 1;
  S21Matrix res(3, 3);
  res(0, 0) = 0;
  res(0, 1) = 10;
  res(0, 2) = -20;
  res(1, 0) = 4;
  res(1, 1) = -14;
  res(1, 2) = 8;
  res(2, 0) = -8;
  res(2, 1) = -2;
  res(2, 2) = 4;
  EXPECT_TRUE(res.EqMatrix(a.CalcComplements()));
}  // SUCCES

TEST(CalcComplements, CalcComplements3) {
  S21Matrix mat(1, 2);
  EXPECT_THROW(mat.CalcComplements(), length_error);
}  // SUCCES

/*-----------------------------------------------------------------------------------------------*/

TEST(Determinant, determinant0) {
  S21Matrix basic(4, 4);
  basic(0, 0) = 9;
  basic(0, 1) = 2;
  basic(0, 2) = 2;
  basic(0, 3) = 4;
  basic(1, 0) = 3;
  basic(1, 1) = 4;
  basic(1, 2) = 4;
  basic(1, 3) = 4;
  basic(2, 0) = 4;
  basic(2, 1) = 4;
  basic(2, 2) = 9;
  basic(2, 3) = 9;
  basic(3, 0) = 1;
  basic(3, 1) = 1;
  basic(3, 2) = 5;
  basic(3, 3) = 1;
  EXPECT_DOUBLE_EQ(basic.Determinant(), -578);
}  // SUCCES

TEST(Determinant, determinant1) {
  S21Matrix basic(1, 1);
  basic(0, 0) = 10;
  EXPECT_DOUBLE_EQ(basic.Determinant(), 10);
}  // SUCCES

TEST(Determinant, determinant2) {
  S21Matrix basic(2, 2);
  basic(0, 0) = 1.1;
  basic(0, 1) = 3.5;
  basic(1, 0) = -2;
  basic(1, 1) = 4;
  EXPECT_DOUBLE_EQ(basic.Determinant(), 11.4);
}  // SUCCES

TEST(Determinant, determinant3) {
  S21Matrix exception(4, 3);
  EXPECT_ANY_THROW(exception.Determinant());
}  // SUCCES

TEST(Determinant, determinant4) {
  S21Matrix a(4, 3);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 4;
  a(1, 1) = 5;
  a(1, 2) = 6;
  a(2, 0) = 7;
  a(2, 1) = 8;
  a(2, 2) = 9;
  a(3, 0) = 1;
  a(3, 1) = 1;
  a(3, 2) = 1;
  EXPECT_THROW(a.Determinant(), length_error);
}  // SUCCES

TEST(Determinant, determinant5) {
  S21Matrix a(3, 3);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 4;
  a(1, 1) = 5;
  a(1, 2) = 6;
  a(2, 0) = 7;
  a(2, 1) = 8;
  a(2, 2) = 9;
  EXPECT_EQ(a.Determinant(), 0);
}  // SUCCES

TEST(Determinant, determinant6) {
  S21Matrix a(3, 3);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 4;
  a(1, 1) = 5;
  a(1, 2) = 6;
  a(2, 0) = 7;
  a(2, 1) = 8;
  a(2, 2) = 10;
  EXPECT_DOUBLE_EQ(a.Determinant(), -3);
}  // SUCCES

/*-----------------------------------------------------------------------------------------------*/

TEST(InverseMatrix, InverseMatrix0) {
  S21Matrix basic(3, 3);
  basic(0, 0) = 4;
  basic(0, 1) = -2;
  basic(0, 2) = 1;
  basic(1, 0) = 1;
  basic(1, 1) = 6;
  basic(1, 2) = -2;
  basic(2, 0) = 1;
  basic(2, 1) = 0;
  basic(2, 2) = 0;
  basic = basic.InverseMatrix();

  EXPECT_EQ(basic(0, 1), 0);
  EXPECT_EQ(basic(0, 2), 1);
  EXPECT_EQ(basic(1, 0), 1);
  EXPECT_EQ(basic(2, 0), 3);
  EXPECT_EQ(basic(2, 1), 1);
  EXPECT_EQ(basic(2, 2), -13);
}  // SUCCES

TEST(InverseMatrix, InverseMatrix1) {
  S21Matrix basic(3, 3);
  basic(0, 0) = 2;
  basic(0, 1) = 2;
  basic(0, 2) = 123;
  basic(1, 0) = 12;
  basic(1, 1) = 6;
  basic(1, 2) = 5;
  basic(2, 0) = 1;
  basic(2, 1) = 2;
  basic(2, 2) = 8;
  basic = basic.InverseMatrix();
  EXPECT_DOUBLE_EQ(basic(0, 1), 0.10910815939278938);
  EXPECT_DOUBLE_EQ(basic(0, 2), -0.34535104364326374);
  EXPECT_DOUBLE_EQ(basic(1, 0), -0.043168880455407968);
  EXPECT_DOUBLE_EQ(basic(2, 0), 0.0085388994307400382);
  EXPECT_DOUBLE_EQ(basic(2, 1), -0.00094876660341555979);
  EXPECT_DOUBLE_EQ(basic(2, 2), -0.0056925996204933585);
}  // SUCCES

TEST(InverseMatrix, InverseMatrix2) {
  S21Matrix exception(3, 3);
  //  determ = 0
  exception(0, 0) = 1;
  exception(0, 1) = 1;
  exception(0, 2) = 3;
  exception(1, 0) = 4;
  exception(1, 1) = 4;
  exception(1, 2) = 6;
  exception(2, 0) = 4;
  exception(2, 1) = 4;
  exception(2, 2) = 9;
  EXPECT_EQ(exception.Determinant(), 0);
  EXPECT_ANY_THROW(exception.InverseMatrix());
}  // SUCCES

TEST(InverseMatrix, InverseMatrix3) {
  S21Matrix exception(3, 3);
  exception(0, 0) = 1;
  exception(0, 1) = 4;
  exception(0, 2) = 1;
  exception(1, 0) = 3;
  exception(1, 1) = 7;
  exception(1, 2) = 2;
  exception(2, 0) = 3;
  exception(2, 1) = 2;
  exception(2, 2) = 1;
  EXPECT_EQ(exception.Determinant(), 0);
  EXPECT_ANY_THROW(exception.InverseMatrix());
}  // SUCCES

TEST(InverseMatrix, InverseMatrix4) {
  S21Matrix exception(3, 2);
  EXPECT_ANY_THROW(exception.InverseMatrix());
}  // SUCCES

/*-----------------------------------------------------------------------------------------------*/

TEST(Test, DefaultConstructor) {
  S21Matrix matrix;
  ASSERT_EQ(matrix.GetRows(), 0);
  ASSERT_EQ(matrix.GetCols(), 0);
  ASSERT_THROW(matrix(0, 0), length_error);
}  // SUCCES

TEST(Test, Constructor1) {
  S21Matrix matrix(2, 4);
  ASSERT_EQ(matrix.GetRows(), 2);
  ASSERT_EQ(matrix.GetCols(), 4);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 4; ++j) ASSERT_EQ(matrix(i, j), 0);
}  // SUCCES

TEST(Test, Constructor2) {
  EXPECT_THROW(S21Matrix matrix(-2, 4), bad_alloc);
}  // SUCCES

TEST(Test, CopyConstructor) {
  S21Matrix matrix(2, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3.1;
  matrix(1, 0) = 4.5;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6.2;
  S21Matrix copyMatrix = matrix;
  ASSERT_EQ(copyMatrix.GetRows(), 2);
  ASSERT_EQ(copyMatrix.GetCols(), 3);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 3; ++j) ASSERT_EQ(matrix(i, j), copyMatrix(i, j));
}  // SUCCES

TEST(Test, MoveConstructor) {
  S21Matrix matrix(2, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3.1;
  matrix(1, 0) = 4.5;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6.2;
  S21Matrix matrixTemp(matrix);
  S21Matrix copyMatrix(move(matrix));
  ASSERT_EQ(copyMatrix.GetRows(), 2);
  ASSERT_EQ(copyMatrix.GetCols(), 3);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 3; ++j) ASSERT_EQ(matrixTemp(i, j), copyMatrix(i, j));
}  // SUCCES

/*-----------------------------------------------------------------------------------------------*/

TEST(Test, Eq1) {
  S21Matrix a(2, 2);
  a(0, 0) = 4.3;
  a(0, 1) = 3;
  a(1, 0) = 11.3;
  a(1, 1) = -1.3;
  S21Matrix b(2, 2);
  b(0, 0) = 4.3;
  b(0, 1) = 3;
  b(1, 0) = 11.3;
  b(1, 1) = -1.3;
  EXPECT_TRUE(a == b);
}  // SUCCES

TEST(Test, Eq2) {
  S21Matrix a(2, 2);
  a(0, 0) = 4.3;
  a(0, 1) = 3;
  a(1, 0) = 11.5;
  a(1, 1) = -1.3;
  S21Matrix b(2, 2);
  b(0, 0) = 4.3;
  b(0, 1) = 3;
  b(1, 0) = 11.3;
  b(1, 1) = -1.3;
  EXPECT_FALSE(a == b);
}  // SUCCES

TEST(Test, Sum1) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 1;
  a(1, 1) = -1;
  S21Matrix b(2, 2);
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  S21Matrix res(2, 2);
  res(0, 0) = 13;
  res(0, 1) = 3;
  res(1, 0) = -4;
  res(1, 1) = 5;
  EXPECT_TRUE((a + b) == res);
}  // SUCCES

TEST(Test, Sum2) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 9;
  a(1, 1) = -1;
  S21Matrix b(2, 2);
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  S21Matrix res(2, 2);
  res(0, 0) = 13;
  res(0, 1) = 3;
  res(1, 0) = -4;
  res(1, 1) = 5;
  EXPECT_FALSE((a + b) == res);
}  // SUCCES

TEST(Test, Sum3) {
  S21Matrix a(1, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  S21Matrix b(2, 2);
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  EXPECT_THROW(a + b, length_error);
}  // SUCCES

TEST(Test, Sub1) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 1;
  a(1, 1) = -1;
  S21Matrix b(2, 2);
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  S21Matrix res(2, 2);
  res(0, 0) = -5;
  res(0, 1) = 3;
  res(1, 0) = 6;
  res(1, 1) = -7;
  EXPECT_TRUE((a - b) == res);
}  // SUCCES

TEST(Test, Sub2) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 9;
  a(1, 1) = -1;
  S21Matrix b(2, 2);
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  S21Matrix res(2, 2);
  res(0, 0) = 13;
  res(0, 1) = 3;
  res(1, 0) = -4;
  res(1, 1) = 5;
  EXPECT_FALSE((a - b) == res);
}  // SUCCES

TEST(Test, Sub3) {
  S21Matrix a(1, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  S21Matrix b(2, 2);
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  EXPECT_THROW(a - b, length_error);
}  // SUCCES

TEST(Test, MulNumberOp) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 0;
  a(1, 1) = -1;
  const double num = 2.5;
  S21Matrix res(2, 2);
  res(0, 0) = 10;
  res(0, 1) = 7.5;
  res(1, 0) = 0;
  res(1, 1) = -2.5;

  EXPECT_TRUE(a * num == res);
}  // SUCCES

TEST(Test, MulMatrixOp1) {
  S21Matrix a(3, 2);
  a(0, 0) = 1;
  a(0, 1) = 4;
  a(1, 0) = 2;
  a(1, 1) = 5;
  a(2, 0) = 3;
  a(2, 1) = 6;
  S21Matrix b(3, 4);
  b(0, 0) = 1;
  b(0, 1) = -1;
  b(0, 2) = 1;
  b(0, 3) = 4;
  b(1, 0) = 2;
  b(1, 1) = 3;
  b(1, 2) = 4;
  b(1, 3) = -5;
  b(2, 0) = 1;
  b(2, 1) = 1;
  b(2, 2) = 1;
  b(2, 3) = 1;
  EXPECT_THROW(a * b, length_error);
}  // SUCCES

TEST(Test, LeftSum1) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 1;
  a(1, 1) = -1;
  S21Matrix b(2, 2);
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  S21Matrix res(2, 2);
  res(0, 0) = 13;
  res(0, 1) = 3;
  res(1, 0) = -4;
  res(1, 1) = 5;
  EXPECT_TRUE((a += b) == res);
}  // SUCCES

TEST(Test, LeftSum3) {
  S21Matrix a(1, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  S21Matrix b(2, 2);
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  EXPECT_THROW(a += b, length_error);
}  // SUCCES

TEST(Test, LeftSub1) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 1;
  a(1, 1) = -1;
  S21Matrix b(2, 2);
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  S21Matrix res(2, 2);
  res(0, 0) = -5;
  res(0, 1) = 3;
  res(1, 0) = 6;
  res(1, 1) = -7;
  EXPECT_TRUE((a -= b) == res);
}  // SUCCES

TEST(Test, LeftSub2) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 9;
  a(1, 1) = -1;
  S21Matrix b(2, 2);
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  S21Matrix res(2, 2);
  res(0, 0) = 13;
  res(0, 1) = 3;
  res(1, 0) = -4;
  res(1, 1) = 5;
  EXPECT_FALSE((a -= b) == res);
}  // SUCCES

TEST(Test, LeftSub3) {
  S21Matrix a(1, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  S21Matrix b(2, 2);
  b(0, 0) = 9;
  b(0, 1) = 0;
  b(1, 0) = -5;
  b(1, 1) = 6;
  EXPECT_THROW(a -= b, length_error);
}  // SUCCES

TEST(Test, LeftMulNumberOp) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a(0, 1) = 3;
  a(1, 0) = 0;
  a(1, 1) = -1;
  const double num = 2.5;
  S21Matrix res(2, 2);
  res(0, 0) = 10;
  res(0, 1) = 7.5;
  res(1, 0) = 0;
  res(1, 1) = -2.5;
  EXPECT_TRUE((a *= num) == res);
}  // SUCCES

TEST(Test, LeftMulMatrixOp1) {
  S21Matrix a(3, 2);
  a(0, 0) = 1;
  a(0, 1) = 4;
  a(1, 0) = 2;
  a(1, 1) = 5;
  a(2, 0) = 3;
  a(2, 1) = 6;
  S21Matrix b(3, 4);
  b(0, 0) = 1;
  b(0, 1) = -1;
  b(0, 2) = 1;
  b(0, 3) = 4;
  b(1, 0) = 2;
  b(1, 1) = 3;
  b(1, 2) = 4;
  b(1, 3) = -5;
  b(2, 0) = 1;
  b(2, 1) = 1;
  b(2, 2) = 1;
  b(2, 3) = 1;
  EXPECT_THROW(a *= b, length_error);
}  // SUCCES

TEST(Test, GetRows) {
  S21Matrix matrix(2, 2);
  EXPECT_TRUE(matrix.GetRows() == 2);
}  // SUCCES

TEST(Test, GetCols) {
  S21Matrix matrix(2, 2);
  EXPECT_TRUE(matrix.GetRows() == 2);
}  // SUCCES

TEST(Test, setRows) {
  S21Matrix matrix(2, 2);
  matrix.SetRows(5);
  EXPECT_TRUE(matrix.GetRows() == 5);
}  // SUCCES

TEST(Test, setCols) {
  S21Matrix matrix(2, 2);
  matrix.SetCols(9);
  EXPECT_TRUE(matrix.GetCols() == 9);
}  // SUCCES

TEST(Test, moveop) {
  S21Matrix a(2, 2);
  S21Matrix b;
  a(0, 0) = 4;
  a(0, 1) = 12;
  a(1, 0) = 1;
  a(1, 1) = 90;
  b = move(a);
  EXPECT_EQ(a.GetCols(), 0);
  EXPECT_EQ(a.GetRows(), 0);
  EXPECT_EQ(b(1, 1), 90);
}  // SUCCES

TEST(Test, mulnumerror) {
  S21Matrix mat;
  EXPECT_THROW(mat.MulNumber(5), length_error);
}  // SUCCES

TEST(Test, transposeerror) {
  S21Matrix mat;
  EXPECT_THROW(mat.Transpose(), length_error);
}  // SUCCES

TEST(Test, calccompserror) {
  S21Matrix mat(1, 2);
  EXPECT_THROW(mat.CalcComplements(), length_error);
}  // SUCCES

TEST(Test, singulardeterminant) {
  S21Matrix mat(1, 1);
  mat(0, 0) = 5;
  EXPECT_DOUBLE_EQ(mat(0, 0), mat.Determinant());
}  // SUCCES

TEST(Test, inverseerror) {
  S21Matrix mat(1, 2);
  EXPECT_THROW(mat.InverseMatrix(), length_error);
}  // SUCCES

TEST(Test, selfassert) {
  S21Matrix mat(1, 1), mat2(1, 1);
  mat(0, 0) = 5;
  mat2(0, 0) = 5;
  mat = mat;
  EXPECT_DOUBLE_EQ(mat(0, 0), mat2(0, 0));
}  // SUCCES

TEST(Test, copy1) {
  S21Matrix mat(5, 5), mat2(3, 3);
  mat = mat2;
  EXPECT_DOUBLE_EQ(mat(0, 0), mat2(0, 0));
}  // SUCCES

TEST(Test, copy2) {
  S21Matrix mat(3, 3), mat2(5, 5);
  mat = mat2;
  EXPECT_DOUBLE_EQ(mat(0, 0), mat2(0, 0));
}  // SUCCES

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}