#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter total rows and columns: ";
    cin >> rows >> cols;
    int matrix[rows][cols];
    cout << "Input matrix elements:\n";
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "\nThe Matrix is:\n";
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nRow-wise sums:\n";
    for (int i=0;i<rows;i++) {
        int sumRow = 0;
        for (int j=0;j<cols;j++) {
            sumRow += matrix[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << sumRow << endl;
    }
    cout << "\nColumn-wise sums:\n";
    for (int j=0;j<cols;j++) {
        int sumCol = 0;
        for (int i=0;i<rows;i++) {
            sumCol += matrix[i][j];
        }
        cout << "Sum of column " << j+1 << ": " << sumCol << endl;
    }
    return 0;
}
