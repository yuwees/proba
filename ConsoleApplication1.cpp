#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;



void display_array(int** array_data, int row_count, int col_count) {
    cout << "\nСформированный массив " << row_count << "x" << col_count << ":\n";
    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < col_count; ++column) {
            cout << setw(6) << array_data[row][column] << " ";
        }
        cout << endl;
    }
}

void expand_array(int**& array_ptr) {
    int new_rows = array_ptr[0][0] + 2;
    int new_cols = array_ptr[0][1] + 2;

    array_ptr = (int**)realloc(array_ptr, new_rows * sizeof(int*));

    for (int row_idx = 0; row_idx < new_rows; ++row_idx) {
        if (row_idx < 2) {
            array_ptr[row_idx] = (int*)realloc(array_ptr[row_idx], new_cols * sizeof(int));
        }
        else {
            array_ptr[row_idx] = (int*)malloc(new_cols * sizeof(int));
        }
    }

    for (int row_idx = 0; row_idx < new_rows; ++row_idx) {
        for (int col_idx = 0; col_idx < new_cols; ++col_idx) {
            if (row_idx < 2 && col_idx < 2) {
                array_ptr[row_idx][col_idx] = array_ptr[row_idx][col_idx];
            }
            else {
                array_ptr[row_idx][col_idx] = ((row_idx - 1) * array_ptr[1][0]) + ((col_idx - 1) * array_ptr[1][1]);
            }
        }
    }
}

int* locate_zero_columns(int** array_ptr, int row_count, int col_count, int& zero_count) {
    zero_count = 0;
    for (int col_idx = 0; col_idx < col_count; col_idx++) {
        for (int row_idx = 0; row_idx < row_count; row_idx++) {
            if (array_ptr[row_idx][col_idx] == 0) {
                zero_count++;
                break;
            }
        }
    }

    int* zero_column_indices = (int*)malloc(zero_count * sizeof(int));

    int current_index = 0;
    for (int col_idx = 0; col_idx < col_count; col_idx++) {
        for (int row_idx = 0; row_idx < row_count; row_idx++) {
            if (array_ptr[row_idx][col_idx] == 0) {
                zero_column_indices[current_index] = col_idx;
                current_index++;
                break;
            }
        }
    }

    return zero_column_indices;
}

void eliminate_columns(int**& array_ptr, int row_count, int col_count, int* columns_to_remove, int remove_count, int& result_cols) {
    result_cols = col_count - remove_count;
    if (result_cols <= 0) {
        cout << "Пустой массив" << endl;
    }

    for (int remove_idx = 0; remove_idx < remove_count; remove_idx++) {
        int target_column = columns_to_remove[remove_idx] - remove_idx;
        for (int col_idx = target_column; col_idx < col_count - 1; col_idx++) {
            for (int row_idx = 0; row_idx < row_count; row_idx++) {
                array_ptr[row_idx][col_idx] = array_ptr[row_idx][col_idx + 1];
            }
        }
    }

    for (int row_idx = 0; row_idx < row_count; row_idx++) {
        array_ptr[row_idx] = (int*)realloc(array_ptr[row_idx], result_cols * sizeof(int));
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    int matrix_rows = 2;
    int matrix_cols = 2;

    // Первый пункт
    int** main_array = (int**)malloc(matrix_rows * sizeof(int*));
    for (int row_idx = 0; row_idx < matrix_rows; ++row_idx) {
        main_array[row_idx] = (int*)calloc(matrix_rows, sizeof(int));
    }

    cout << "Введите элементы массива " << matrix_rows << "x" << matrix_cols << ":" << endl;
    for (int row_idx = 0; row_idx < matrix_rows; ++row_idx) {
        for (int col_idx = 0; col_idx < matrix_cols; ++col_idx) {
            cout << "Элемент [" << row_idx << "][" << col_idx << "]: ";
            cin >> main_array[row_idx][col_idx];
            if (main_array[row_idx][col_idx] < 0) {
                cout << "Введите числа больше нуля" << endl;
                col_idx -= 1;
            }
        }
    }

    int total_rows = main_array[0][0] + matrix_rows;
    int total_cols = main_array[0][1] + matrix_cols;
    expand_array(main_array);
    display_array(main_array, total_rows, total_cols);

    int zero_column_count;
    int* zero_columns = locate_zero_columns(main_array, total_rows, total_cols, zero_column_count);

    int final_cols;
    eliminate_columns(main_array, total_rows, total_cols, zero_columns, zero_column_count, final_cols);

    if (main_array != nullptr) {
        cout << "\nМассив после удаления столбцов с нулями:";
        display_array(main_array, total_rows, final_cols);
    }
    else {
        cout << "\nВсе столбцы были удалены!" << endl;
    }

    free(zero_columns);

    // Второй пункт
    float* value_x = new float;
    float* value_y = new float;

    cout << "Введите значение x: ";
    cin >> *value_x;
    cout << "Введите значение y: ";
    cin >> *value_y;

    *value_x = *value_x * 3;
    float temp_value = *value_x;
    *value_x = *value_y;
    *value_y = temp_value;

    cout << "Значение переменной x: " << *value_x << endl;
    cout << "Значение переменной y: " << *value_y << endl;

    delete value_x;
    delete value_y;

    return 0;
}
