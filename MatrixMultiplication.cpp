#include <bits/stdc++.h>

using namespace std;

void multiplyMatrix(int m1, int m2, int *first, int n1, int n2, int *second);

void displayMatrix(int r, int c, int *arr) {
    int *currentRow;
    for (int i = 0; i < r; ++i) {
        currentRow = arr + c * i;
        for (int j = 0; j < c; ++j)
            cout << *(currentRow + j) << " ";
        cout << endl;
    }
}

int main() {

    int mat1[1][2] = {{1, 1}};
    int mat2[2][1] = {{1},
                      {2}};
    int m1 = 1, m2 = 2, n1 = 2, n2 = 1;
    multiplyMatrix(m1, m2, (int *) mat1, n1, n2, (int *) mat2);

    return 0;
}

void multiplyMatrix(int m1, int m2, int *first,
                    int n1, int n2, int *second) {
    if (m2 != n1) {
        cout << "Multiplication not possible!" << endl;
        return;
    }

    int result[m1][n2];
    int *firstCurrentRow;   // tracking current row of first matrix
    int *secondCurrentRow;  // tracking current row of second matrix
    for (int i = 0; i < m1; ++i) {
        firstCurrentRow = first + m2 * i;   // calculating current row of first matrix
        for (int j = 0; j < n2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < m2; ++k) {
                secondCurrentRow = second + n2 * k;     // calculating current row of second matrix
                result[i][j] += *(firstCurrentRow + k) * *(secondCurrentRow + j);
            }
        }
    }

    // displaying resultant matrix
    displayMatrix(m1, n2, (int *) result);
}
