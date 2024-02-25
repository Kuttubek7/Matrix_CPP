#ifndef CPP_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H
#define CPP_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H

#include <time.h>  // для функции time который я использовал в rand

#include <cmath>     // для fabs
#include <iostream>  // default

#define EPS 1e-7
using namespace std;  // пространства имен

class S21Matrix {
 private:
  int rows_ = 0, cols_ = 0;    // ряды и столбцы
  double** matrix_ = nullptr;  // Указатель на память, где размещена матрица

 public:
  /*--------------------------------------------------------------------------------------------*/
  // конструкторы
  S21Matrix() = default;  // конструктор по умолчанию
  S21Matrix(int rows, int cols);  // параметизированный конструктор
  S21Matrix(const S21Matrix& other);  // конструктор копирования
  S21Matrix(S21Matrix&& other);  // конструктор переноса
  ~S21Matrix();                  // Деструктор
  /*--------------------------------------------------------------------------------------------*/
  // аксессор и мутатор
  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(int cols);
  /*--------------------------------------------------------------------------------------------*/
  //  методы
  bool EqMatrix(const S21Matrix& other)
      const;  // проверяет матрицы на равенство между собой
  void SumMatrix(
      const S21Matrix& other);  // прибавляет вторую матрицу к текущей
  void SubMatrix(const S21Matrix& other);  // вычитает из текущей матрицы другую
  void MulNumber(const double num);  // умножает матрицу на число
  void MulMatrix(const S21Matrix& other);  // умножает текущую матрицу на вторую
  S21Matrix Transpose()
      const;  // создает новую транспонированную матрицу из текущей
  S21Matrix CalcComplements()
      const;  // вычисляет матрицу алгебраического сложения текущей
  double Determinant()
      const;  // вычисляет и возвращает определитель текущей матрицы
  S21Matrix InverseMatrix() const;  // вычисляет и возвращает обратную матрицу
  /*--------------------------------------------------------------------------------------------*/
  // операторы
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix operator=(S21Matrix&& other);
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(const double num);
  bool operator==(const S21Matrix& other) const;
  double& operator()(int i, int j);
  const double& operator()(int i, int j) const;
  /*---------------------------------------------------------------------------------------------*/
  // допольнительные вспомогательные функции
  void PrintMatrix();   // принтует матрицу
  void InitMatrix();    // инициализирует матрицу
  void SetNull();       // обнуляет матрицу
  void CreateMatrix();  // создает матрицу
  void CreateMatrix(int rows, int cols);  // создает параметизированную матрицу
  void DoesTheMatrixExist() const;  // проверяет существует ли матрица
  void DoesTheMatrixExist(
      const S21Matrix& other) const;  // проверяет существует ли матрицы
  void RemoveMatrix();                      // удаляет матрицу
  void CopyMatrix(const S21Matrix& other);  // копирует матрицу
  void ExceptionOutOfRange(
      int i, int j) const;  // проверяет выходы за границ в матрице
  void MatrixIsNotSquare() const;  // проверяет матрицу не квадратная ли она
  void CreateMinor(int i, int j,
                   const S21Matrix& minor) const;  // определяет минор
  void CheckDeterminantValidity(
      double determinant) const;  // проверяет детерминант
  void CheckDimensionsForMultiplication(const S21Matrix& other)
      const;  // количество столбцов не равно количеству строк
  void CheckDimensionsEquality(
      const S21Matrix& other) const;  // проверяет размеры матриц
  /*--------------------------------------------------------------------------------------------*/
};

#endif  // CPP_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H