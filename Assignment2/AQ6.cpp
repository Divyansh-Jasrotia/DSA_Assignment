#include <iostream>
using namespace std;

int main()
{
    int rows, cols, count = 0;
    cout << "Part (a)\n";
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int mat[rows][cols];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
            if (mat[i][j] != 0) {
                count++;
            }
        }
    }

    int sparse[3][count];
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    int idx = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[0][idx] = i;
                sparse[1][idx] = j;
                sparse[2][idx] = mat[i][j];
                idx++;
            }
        }
    }

    cout << "Sparse Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < count; j++) {
            cout << sparse[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < count; i++) {
        int temp = sparse[0][i];
        sparse[0][i] = sparse[1][i];
        sparse[1][i] = temp;
    }

    cout << "Transpose of Sparse Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < count; j++) {
            cout << sparse[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Part (b)\n";
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int nonZeroA = 0, nonZeroB = 0;
    int A[rows][cols], B[rows][cols];

    cout << "Enter Matrix A:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A[i][j];
            if (A[i][j] != 0) nonZeroA++;
        }
    }

    int sparseA[3][nonZeroA];

    cout << "Enter Matrix B:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> B[i][j];
            if (B[i][j] != 0) nonZeroB++;
        }
    }

    int sparseB[3][nonZeroB];

    cout << "Matrix A:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Matrix B:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }

    idx = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] != 0) {
                sparseA[0][idx] = i;
                sparseA[1][idx] = j;
                sparseA[2][idx] = A[i][j];
                idx++;
            }
        }
    }

    cout << "Sparse A:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < nonZeroA; j++) {
            cout << sparseA[i][j] << " ";
        }
        cout << "\n";
    }

    idx = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (B[i][j] != 0) {
                sparseB[0][idx] = i;
                sparseB[1][idx] = j;
                sparseB[2][idx] = B[i][j];
                idx++;
            }
        }
    }

    cout << "Sparse B:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < nonZeroB; j++) {
            cout << sparseB[i][j] << " ";
        }
        cout << "\n";
    }

    int sum[3][nonZeroA + nonZeroB], p = 0, q = 0;
    int sumSize = 0;

    while (p < nonZeroA && q < nonZeroB) {
        if (sparseA[0][p] < sparseB[0][q]) {
            for (int i = 0; i < 3; i++) sum[i][sumSize] = sparseA[i][p];
            p++;
        }
        else if (sparseB[0][q] < sparseA[0][p]) {
            for (int i = 0; i < 3; i++) sum[i][sumSize] = sparseB[i][q];
            q++;
        }
        else {
            if (sparseA[1][p] < sparseB[1][q]) {
                for (int i = 0; i < 3; i++) sum[i][sumSize] = sparseA[i][p];
                p++;
            }
            else if (sparseB[1][q] < sparseA[1][p]) {
                for (int i = 0; i < 3; i++) sum[i][sumSize] = sparseB[i][q];
                q++;
            }
            else {
                sum[0][sumSize] = sparseA[0][p];
                sum[1][sumSize] = sparseA[1][p];
                sum[2][sumSize] = sparseA[2][p] + sparseB[2][q];
                p++;
                q++;
            }
        }
        sumSize++;
    }

    while (p < nonZeroA) {
        for (int i = 0; i < 3; i++) sum[i][sumSize] = sparseA[i][p];
        p++;
        sumSize++;
    }

    while (q < nonZeroB) {
        for (int i = 0; i < 3; i++) sum[i][sumSize] = sparseB[i][q];
        q++;
        sumSize++;
    }

    cout << "Sum (Sparse A + B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < sumSize; j++) {
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Part (c)\n";
    int r1, c1, r2, c2;
    cout << "Enter size of Matrix X (rows cols): ";
    cin >> r1 >> c1;
    cout << "Enter size of Matrix Y (rows cols): ";
    cin >> r2 >> c2;

    if (c1 == r2) {
        int X[r1][c1], Y[r2][c2], xCount = 0, yCount = 0;

        cout << "Enter Matrix X:\n";
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                cin >> X[i][j];
                if (X[i][j] != 0) xCount++;
            }
        }

        int sparseX[3][xCount];

        cout << "Enter Matrix Y:\n";
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                cin >> Y[i][j];
                if (Y[i][j] != 0) yCount++;
            }
        }

        int sparseY[3][yCount];

        cout << "Matrix X:\n";
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                cout << X[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "Matrix Y:\n";
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                cout << Y[i][j] << " ";
            }
            cout << "\n";
        }

        idx = 0;
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                if (X[i][j] != 0) {
                    sparseX[0][idx] = i;
                    sparseX[1][idx] = j;
                    sparseX[2][idx] = X[i][j];
                    idx++;
                }
            }
        }

        cout << "Sparse X:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < xCount; j++) {
                cout << sparseX[i][j] << " ";
            }
            cout << "\n";
        }

        idx = 0;
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                if (Y[i][j] != 0) {
                    sparseY[0][idx] = i;
                    sparseY[1][idx] = j;
                    sparseY[2][idx] = Y[i][j];
                    idx++;
                }
            }
        }

        cout << "Sparse Y:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < yCount; j++) {
                cout << sparseY[i][j] << " ";
            }
            cout << "\n";
        }

        int sparseProd[3][xCount * yCount], prodCount = 0;

        for (int i = 0; i < xCount; i++) {
            for (int j = 0; j < yCount; j++) {
                if (sparseX[1][i] == sparseY[0][j]) {
                    int row = sparseX[0][i];
                    int col = sparseY[1][j];
                    int val = sparseX[2][i] * sparseY[2][j];
                    bool exists = false;

                    for (int z = 0; z < prodCount; z++) {
                        if (sparseProd[0][z] == row && sparseProd[1][z] == col) {
                            sparseProd[2][z] += val;
                            exists = true;
                            break;
                        }
                    }

                    if (!exists) {
                        sparseProd[0][prodCount] = row;
                        sparseProd[1][prodCount] = col;
                        sparseProd[2][prodCount] = val;
                        prodCount++;
                    }
                }
            }
        }

        cout << "Sparse Product:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < prodCount; j++) {
                cout << sparseProd[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "Multiplication Not Possible\n";
    }

    return 0;
}
