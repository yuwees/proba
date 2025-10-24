
#include <iostream>
#include <limits>
using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    bool a;

    cout << "Выберите подпункт (0,1)" << endl;
    cin >> a;

    if (a == false) {

        const int NMax = 8;
        int count = 0;
        bool flag_1 = false;

        int arr[NMax];

        cout << "Введите 8 чисел" << endl;
        for (int j = 0; j < NMax; ++j) {
            cin >> arr[j];
        }
        cout << endl;
        for (int i = 0; i < NMax; ++i) {
            if (arr[i] == 25) {
                ++count;
            }
            if (count == 3) {
                flag_1 = true;
                break;
            }
        }
        if (flag_1 == true) {
            for (int i = 0; i < NMax - 1; ++i) {
                for (int j = i + 1; j < NMax; ++j) {
                    if (arr[i] > arr[j]) {
                        swap(arr[i], arr[j]);
                    }
                }
            }
            for (int i = 0; i < NMax; ++i) {
                cout << arr[i] << endl;
            }
        }
        else {
            cout << "25 встречается меньше 3 раз" << endl;
        }
    }
    else {
        const int NMax = 3;
        const int MMax = 4;
        int matrix[NMax][MMax] = {
        {1,2,2,1},
        {4,1,1,1},
        {1,1,0,1}
        };

        cout << "Введитие матрицу размера 3x4" << endl;

        for (short i = 0; i < NMax; ++i) {
            for (short j = 0; j < MMax; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;

        int max_str = 0;
        int ans = -1;

        for (int i = 0; i < NMax; ++i) {
            int count = 0;
            for (int j = 0; j < MMax; ++j) {
                if (matrix[i][j] == 0) {
                    ++count;
                }
                int tmp = max_str;
                max_str = max(max_str, count);
                if (max_str > tmp) {
                    ans = i;
                }
            }
        }
        if (ans >= 0 and ans < NMax) {
            for (int j = 0; j < MMax; ++j) {
                if (matrix[ans][j] == 0) {
                    matrix[ans][j] = 888;
                }
            }
            for (int i = 0; i < NMax; ++i) {
                for (int j = 0; j < MMax; ++j) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
        else {
            cout << "Нет 0" << endl;
        }
    }

    return 0;
}