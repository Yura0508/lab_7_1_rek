// lab_7_1_rek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <iomanip>
#include <ctime> 
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** a, const int rowCount, const int colCount, int i = 0);
void Sort(int** R, const int rowCount, const int colCount, int i0 = 0);
void Change(int** R, const int row1, const int row2, const int colCount, int col = 0);
void Calc(int** R, const int rowCount, const int colCount, int& S, int& k, int row = 0, int col = 0);

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    int Low = 4;
    int High = 51;
    int rowCount = 8;
    int colCount = 5;

    int** R = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        R[i] = new int[colCount];

    Create(R, rowCount, colCount, Low, High);
    cout << "Generated Matrix:" << endl;
    Print(R, rowCount, colCount);
    cout << endl;

    Sort(R, rowCount, colCount);
    Print(R, rowCount, colCount);
    cout << endl;

    int S = 0;
    int k = 0;
    Calc(R, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << endl;

    Print(R, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] R[i];
    delete[] R;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
    a[i][j] = Low + rand() % (High - Low + 1);
    if (j < colCount - 1)
        Create(a, rowCount, colCount, Low, High, i, j + 1);
    else if (i < rowCount - 1)
        Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i) {
    if (i < rowCount) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
        Print(a, rowCount, colCount, i + 1);
    }
}

void Sort(int** R, const int rowCount, const int colCount, int i0) {
    if (i0 >= rowCount - 1) return; // Вихід, якщо досягли кінця
    for (int i1 = 0; i1 < rowCount - i0 - 1; i1++) {

        if ((R[i1][0] > R[i1 + 1][0]) ||
            (R[i1][0] == R[i1 + 1][0] && R[i1][1] < R[i1 + 1][1]) ||
            (R[i1][0] == R[i1 + 1][0] && R[i1][1] == R[i1 + 1][1] && R[i1][2] < R[i1 + 1][2])) {
            Change(R, i1, i1 + 1, colCount);
        }
    }
    Sort(R, rowCount, colCount, i0 + 1); // Переход до наступного раунду сортування
}

void Change(int** R, const int row1, const int row2, const int colCount, int col) {
    if (col >= colCount) return; // Вихід, якщо всі стовпці оброблені


    int tmp = R[row1][col];
    R[row1][col] = R[row2][col];
    R[row2][col] = tmp;


    Change(R, row1, row2, colCount, col + 1);
}

void Calc(int** R, const int rowCount, const int colCount, int& S, int& k, int row, int col) {
    if (row >= rowCount) return; // Вихід, якщо досягли кінця
    if (col >= colCount) {
        Calc(R, rowCount, colCount, S, k, row + 1, 0); // Переход до наступного рядка
        return;
    }

    if (!(R[row][col] % 2 != 0 || (row % 3 == 0 && col % 3 == 0))) {
        S += R[row][col];
        k++;
        R[row][col] = 0;
    }
    Calc(R, rowCount, colCount, S, k, row, col + 1); // Переход до наступного стовпця
}
