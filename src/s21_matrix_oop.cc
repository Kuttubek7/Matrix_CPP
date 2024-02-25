#include "s21_matrix_oop.h"

// int main() {}

/// @brief Эта функция предназначена для возврата количества строк в матрице
/// @return
int S21Matrix::GetRows() const { return rows_; }

/// @brief Эта функция предназначена для возврата количества столбцов в матрице
/// @return
int S21Matrix::GetCols() const { return cols_; }

/// @brief Эта функция предназначена для изменения количества строк в матрице
/// @param rows
void S21Matrix::SetRows(int rows) {
  S21Matrix tempM(rows, cols_);
  // int x = 0; if (rows_ < rows) x = rows_; else x = rows;
  for (int i = 0; i < ((rows_ < rows) ? rows_ : rows); i++) {
    for (int j = 0; j < cols_; j++) {
      tempM.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = move(tempM);
}

/// @brief Эта функция предназначена для изменения количества столбцов в матрице
/// @param cols
void S21Matrix::SetCols(int cols) {
  S21Matrix tempM(rows_, cols);
  // int x = 0; if (cols_ < cols) x = cols_; else x = cols;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < ((cols_ < cols) ? cols_ : cols); j++) {
      tempM.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = move(tempM);
}

/// @brief Параметизированный конструктор
/// @param rows - ряды
/// @param cols - столбцы
S21Matrix::S21Matrix(int rows, int cols) {
  this->rows_ =
      rows;  // нужно добавить проверку на правильное выделение памяти на массив
  this->cols_ = cols;
  S21Matrix::CreateMatrix(rows, cols);
}

/// @brief Конструктор копирования
/// @param other получет матрицу которую нужно скопировать
S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  CopyMatrix(other);
}

/// @brief Переместить конструктор
/// @param other получаю матрицу на основе прошлого обьекта
S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.SetNull();
}

/// @brief Деструктор срабатывает в конце и удаляет матрицу
S21Matrix::~S21Matrix() {
  for (int i = 0; i < this->rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

/// @brief Вычисляет и возвращает обратную матрицу
/// @return
S21Matrix S21Matrix::InverseMatrix() const {
  DoesTheMatrixExist();
  MatrixIsNotSquare();
  double determinant = Determinant();
  CheckDeterminantValidity(determinant);
  S21Matrix result(rows_, cols_);
  if (rows_ == 1) {
    result.matrix_[0][0] = 1 / matrix_[0][0];
  } else {
    result = CalcComplements().Transpose();
    result.MulNumber(1 / determinant);
  }
  return result;
}

/// @brief Вычисляет и возвращает определитель текущей матрицы
/// @return
double S21Matrix::Determinant() const {
  double result = 0.0;
  MatrixIsNotSquare();
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    S21Matrix minor(rows_ - 1, cols_ - 1);
    for (int j = 0; j < cols_; j++) {
      CreateMinor(0, j, minor);
      result += pow(-1.0, j) * minor.Determinant() * matrix_[0][j];
    }
  }
  return result;
}

/// @brief Вычисляет матрицу алгебраического сложения текущей и возвращает ее
/// @return
S21Matrix S21Matrix::CalcComplements() const {
  DoesTheMatrixExist();
  MatrixIsNotSquare();
  S21Matrix result(rows_, cols_);
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      CreateMinor(i, j, minor);
      result.matrix_[i][j] = pow(-1, (j + i) + 2) * minor.Determinant();
    }
  }
  return result;
}

/// @brief Создает новую транспонированную матрицу из текущей и возвращает ее
/// @return
S21Matrix S21Matrix::Transpose() const {
  DoesTheMatrixExist();
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

/// @brief Умножает текущую матрицу на вторую матрицу
/// @param other получает матрицу
void S21Matrix::MulMatrix(const S21Matrix& other) {
  DoesTheMatrixExist(other);
  CheckDimensionsForMultiplication(other);
  S21Matrix tmp(rows_, other.cols_);
  for (int i = 0; i < tmp.rows_; i++) {
    for (int j = 0; j < tmp.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        tmp.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = move(tmp);  // заменяет значения текущей матрицы на значения tmp
}

/// @brief умноженает текущую матрицу на число
/// @param num число на которую нужно умножить
void S21Matrix::MulNumber(const double num) {
  DoesTheMatrixExist();
  if (num != 0) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = matrix_[i][j] * num;
      }
    }
  }
}

/// @brief Вычитает другую матрицу из текущей
/// @param other получает внешнюю матрицу
void S21Matrix::SubMatrix(const S21Matrix& other) {
  DoesTheMatrixExist(other);
  CheckDimensionsEquality(other);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
  }
}

/// @brief Добавляет вторую матрицу к текущей
/// @param other получает другую матрицу и на него суммирует локальную матрицу
void S21Matrix::SumMatrix(const S21Matrix& other) {
  DoesTheMatrixExist(other);
  CheckDimensionsEquality(other);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
  }
}

/// @brief Проверяет матрицы на равенство друг другу
/// @param other матрица
/// @return булевое выражение
bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  // если false то он возвращает 0, если true то какое-то число
  bool result = true;
  DoesTheMatrixExist(other);
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    result = false;
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > EPS) {
        result = false;
      }
    }
  }
  return result;
}

/// @brief Сложение двух матриц
/// @param other
/// @return
S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result = *this;  // Создаем копию текущей матрицы
  result.SumMatrix(other);  // Выполняем сложение с другой матрицей
  return result;  // Возвращаем результат
}

/// @brief Вычитание одной матрицы из другой
/// @param other
/// @return
S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result = *this;
  result.SubMatrix(other);
  return result;
}

/// @brief Умножение матрицы
/// @param other
/// @return
S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result = *this;
  result.MulMatrix(other);
  return result;
}

/// @brief умножение матрицы на число
/// @param num
/// @return
S21Matrix S21Matrix::operator*(double num) {
  S21Matrix result = *this;
  result.MulNumber(num);
  return result;
}

/// @brief Проверяет равенство матриц (EqMatrix)
/// @param other
/// @return
bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

/// @brief Присвоение значений из одной матрицы в другую
/// @param other
/// @return
S21Matrix S21Matrix::operator=(S21Matrix&& other) {
  if (this != &other) {
    RemoveMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.SetNull();
  }
  return *this;
}

/// @brief Присвоение значений из одной матрицы в другую
/// @param other
/// @return
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  S21Matrix tempM(other);
  *this = move(tempM);
  return *this;
}

/// @brief Дополнительное задание (SumMatrix)
/// @param other
/// @return
S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

/// @brief Назначение разности (SubMatrix)
/// @param other
/// @return
S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

/// @brief Назначение умножения MulMatrix
/// @param other
/// @return
S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

/// @brief Назначение умножения MulNumber
/// @param num
/// @return
S21Matrix S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

/// @brief Индексация по элементам матрицы (строка, столбец)
/// @param i
/// @param j
/// @return
double& S21Matrix::operator()(int i, int j) {
  ExceptionOutOfRange(i, j);
  return matrix_[i][j];
}

/// @brief Индексация по элементам матрицы
/// @param i строка
/// @param j столбец
/// @return
const double& S21Matrix::operator()(int i, int j) const {
  ExceptionOutOfRange(i, j);
  return matrix_[i][j];
}

/// @brief проверяет, одинаковые ли размеры матриц
/// @param other
void S21Matrix::CheckDimensionsEquality(const S21Matrix& other) const {
  if ((rows_ != other.rows_) || (cols_ != other.cols_)) {
    throw length_error("Different dimensions");
  }
}

/// @brief проверяет, на количество столбцов первой матрицы не равно количеству
/// строк второй матрицы
/// @param other
void S21Matrix::CheckDimensionsForMultiplication(const S21Matrix& other) const {
  if (cols_ != other.rows_) {
    throw length_error("Different dimensions for mul");
  }
}

/// @brief создает матрицу
void S21Matrix::CreateMatrix() {
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

/// @brief создает матрицу с параметрами
/// @param rows
/// @param cols
void S21Matrix::CreateMatrix(int rows_, int cols_) {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

/// @brief инициализирует матрицу
void S21Matrix::InitMatrix() {
  srand(time(NULL));
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      // matrix_[i][j] = 1;
      // заполняет массив единицой по умолчанию там нули
      matrix_[i][j] = (rand() % 10);
      // заполняет массив рандомными числами от 0 до 9ти
    }
  }
}

/// @brief принтует матрицу
void S21Matrix::PrintMatrix() {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      cout << matrix_[i][j] << " ";
    }
    cout << endl;
  }
}

/// @brief обнуляет матрицу
void S21Matrix::SetNull() {
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

/// @brief для проверки выхода за границы
/// @param i
/// @param j
void S21Matrix::ExceptionOutOfRange(int i, int j) const {
  if (i >= rows_ || j >= cols_ || i < 0 || j < 0) {
    throw length_error("Out of range");
  }
}

/// @brief проверяет матрицу не пустой ли он
void S21Matrix::DoesTheMatrixExist() const {
  if (matrix_ == nullptr) {
    throw length_error("Matrix doesn't exist");
  }
}

/// @brief проверяет обе матрицы не пустой ли матрицы
/// @param other
void S21Matrix::DoesTheMatrixExist(const S21Matrix& other) const {
  if (matrix_ == nullptr || other.matrix_ == nullptr) {
    throw length_error("Matrix doesn't exist");
  }
}

/// @brief проверяет матрицу не квадратная ли она
void S21Matrix::MatrixIsNotSquare() const {
  if (rows_ != cols_) {
    throw length_error("Matrix is not square");
  }
}

/// @brief определяет минор
/// @param i
/// @param j
/// @param minor
void S21Matrix::CreateMinor(int i, int j, const S21Matrix& minor) const {
  int minor_i = 0;
  int minor_j = 0;
  for (int current_i = 0; current_i < rows_; current_i++) {
    for (int current_j = 0; current_j < cols_; current_j++) {
      if (current_j != j && current_i != i) {
        minor.matrix_[minor_i][minor_j] = matrix_[current_i][current_j];
        minor_j++;
        if (minor_j == cols_ - 1) {
          minor_i++;
          minor_j = 0;
        }
      }
    }
  }
}

/// @brief проверка детерминанта цифра больше нуля?
/// @param determinant
void S21Matrix::CheckDeterminantValidity(double determinant) const {
  if (fabs(determinant) < EPS) {
    throw length_error("Matrix determinant is 0");
  }
}

/// @brief удаляет матрицу
void S21Matrix::RemoveMatrix() {
  for (int i = 0; i < this->rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  matrix_ = nullptr;
}

/// @brief копирует матрицу
/// @param other
void S21Matrix::CopyMatrix(const S21Matrix& other) {
  if (this != &other) {
    CreateMatrix();
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
}