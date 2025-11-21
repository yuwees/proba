#include <iostream>
using namespace std;

// Фунция для поиска столбцов, содержащих нулевые элементы
int* findZeroColumns(int** matrix, int rows, int cols, int& count) {
    count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                count++;
            }
        }
    }

    // распределяем память под массив с индексами столбцов
    int* zeroColumns = (int*)malloc(count * sizeof(int));
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroColumns[index++] = j; // фиксируем индекс столбца
            }
        }
    }
    return zeroColumns;
}

// Функция для удаления столбцов из матрицы
void removeColumns(int*** matrix, int rows, int cols, int* zeroColumns, int count) {
    
    int newCols = cols - count;

  
    int** newMatrix = (int**)calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; i++) {
        newMatrix[i] = (int*)calloc(newCols, sizeof(int));
    }

    // копируем столбцы и искл те, где есть 0
    int colIndex = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool skipColumn = false;
            for (int k = 0; k < count; k++) {
                if (zeroColumns[k] == j) {
                    skipColumn = true;
                    break;
                }
            }
            if (skipColumn == 0) {
                newMatrix[i][colIndex++] = (*matrix)[i][j];
            }
        }
        colIndex = 0;
    }

    // освобождаем старую матрицу
    for (int i = 0; i < rows; i++) {
        free((*matrix)[i]);
    }
    free(*matrix);

   
    *matrix = newMatrix;  // назначаем новую матрицу
}

// основная функция для пункта 1
void matrix() {
    int A, B, C, D;
    do {
        cout << "Введите количество строк A: ";
        cin >> A;
        cout << "Введите количество столбцов B: ";
        cin >> B;
        if (A <= 0 || B <= 0) {
            cerr << "Введите положительные числа!" << endl;
        }
    } while (A <= 0 || B <= 0);

    cout << "Введите коэффициенты С и D: ";
    cin >> C >> D;

    // делаем расширенную матрицу
    int rows = 2 + A;
    int cols = 2 + B;

    // динамически выделяем память под матрицу
    int** matrix = (int**)calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)calloc(cols, sizeof(int));
    }

    // заполняем матрицу по шаблону
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
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    
    int count;
    int* zeroColumns = findZeroColumns(matrix, rows, cols, count);// находим столбцы с нулями
    removeColumns(&matrix, rows, cols, zeroColumns, count);
    free(zeroColumns);  // освобождаем временный массив с индексами столбцов

    cout << "Получившаяся матрица после удаления столбцов с нулями:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - count; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // очищаем память
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// пункт 2
void modif() {
    double a, b;
    cout << "Введите два вещественных числа a и b: ";
    cin >> a >> b;

    // объявляем указатели на переменные
    double* ptr_a = &a;
    double* ptr_b = &b;

    // увеличиваем первую переменную в 3 раза через указатель
    *ptr_a *= 3;
    double temp = *ptr_a; // временно храним значение

    // меняем местами значения через указатели
    *ptr_a = *ptr_b;
    *ptr_b = temp;

    cout << "Изменения: а = " << a << " b = " << b << endl;
}


int main() {
    setlocale(LC_ALL, "Russian");
    matrix(); 
    modif();
    return 0;
}