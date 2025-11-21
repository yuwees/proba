#include <iostream>
#include <cstdlib> 
using namespace std;

// Функция для поиска столбцов с нулями и их перемещения в конец
void foundZeroColumns(int** matrix, int rows, int cols, int& newCols) {
   
    int currentCol = 0; // перемещение ненулевых столбцов влево
    for (int j = 0; j < cols; j++) {
        bool skipColumn = false;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 0) {
                skipColumn = true;
                break;
            }
        }
        if (skipColumn == false) { // если столбец не содержит нулей
            for (int i = 0; i < rows; i++) {
                matrix[i][currentCol] = matrix[i][j]; // переносим элементы
            }
            currentCol++;
        }
    }
    newCols = currentCol; // устанавливаем новый размер матрицы
}

// Функция для вывода матрицы
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void procesMatrix() {
    int A, B, C, D;
    do {
        cout << "Введите количество строк A: ";
        cin >> A;
        cout << "Введите количество столбцов B: ";
        cin >> B;
        if (A <= 0 || B <= 0) {
            cerr << "Введите положительные числа" << endl;
        }
    } while (A <= 0 || B <= 0);

    cout << "Введите коэффициенты С и D: ";
    cin >> C >> D;

    // определение размера расширенной матрицы
    int rows = 2 + A;
    int cols = 2 + B;

    // распределяем память для матрицы с помощью malloc
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // шаблон матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < 2) {
                matrix[i][j] = -(i)*C + (j)*D;
            }
            else {
                matrix[i][j] = (i - 2) * C + (j - D);
            }
        }
    }

 
    cout << "Исходная матрица:" << endl;
    printMatrix(matrix, rows, cols);

    int newCols = cols;
    foundZeroColumns(matrix, rows, cols, newCols);

    // уменьшаем размер каждой строки с помощью realloc
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)realloc(matrix[i], newCols * sizeof(int));
    }

  
    cout << "Итоговая матрица после сдвига столбцов с нулями в конец:" << endl;
    printMatrix(matrix, rows, newCols);

    // освобождаем память
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// 2 пункт
void modifVar() {
    double a, b;
    cout << "Введите два вещественных числа a и b: ";
    cin >> a >> b;

    double* ykaz_a = &a;
    double* ykaz_b = &b;

    *ykaz_a *= 3;

    // меняем местами значения переменных 
    double temp = *ykaz_a;
    *ykaz_a = *ykaz_b;
    *ykaz_b = temp;


    cout << "Значения после изменений: a = " << a << " b = " << b << endl;
}

// Основная функция
int main() {
    setlocale(LC_ALL, "Russian");
    procesMatrix(); // пункт 1
    modifVar();      // пункт 2
    return 0;
}