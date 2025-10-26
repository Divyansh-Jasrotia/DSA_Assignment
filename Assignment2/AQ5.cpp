#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Diagonal Matrix\n";
    cout << "Enter the size (n): ";
    cin >> n;

    int diagonalMatrix[n][n];
    cout << "Enter the " << n << "x" << n << " diagonal matrix:\n";
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> diagonalMatrix[row][col];
        }
    }

    cout << "You entered:\n";
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << diagonalMatrix[row][col] << " ";
        }
        cout << "\n";
    }

    int diagStorage[n];
    for (int i = 0; i < n; i++) {
        diagStorage[i] = diagonalMatrix[i][i];
    }

    cout << "Linear representation (Diagonal): ";
    for (int i = 0; i < n; i++) {
        cout << diagStorage[i] << " ";
    }
    cout << "\n\n";

    cout << "Tri-diagonal Matrix\n";
    cout << "Enter the size (n): ";
    cin >> n;

    int triDiagMatrix[n][n];
    cout << "Enter the " << n << "x" << n << " matrix:\n";
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> triDiagMatrix[row][col];
        }
    }

    cout << "You entered:\n";
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << triDiagMatrix[row][col] << " ";
        }
        cout << "\n";
    }

    int triStorage[3 * n - 2], index = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row == col || row == col + 1 || col == row + 1) {
                triStorage[index++] = triDiagMatrix[row][col];
            }
        }
    }

    cout << "Linear representation (Tri-diagonal): ";
    for (int i = 0; i < 3 * n - 2; i++) {
        cout << triStorage[i] << " ";
    }
    cout << "\n\n";

    cout << "Lower Triangular Matrix\n";
    cout << "Enter the size (n): ";
    cin >> n;

    int lowerMatrix[n][n];
    cout << "Enter the " << n << "x" << n << " matrix:\n";
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> lowerMatrix[row][col];
        }
    }

    cout << "You entered:\n";
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << lowerMatrix[row][col] << " ";
        }
        cout << "\n";
    }

    int lowerStorage[n * (n + 1) / 2];
    index = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col <= row; col++) {
            lowerStorage[index++] = lowerMatrix[row][col];
        }
    }

    cout << "Linear representation (Lower Triangular): ";
    for (int i = 0; i < n * (n + 1) / 2; i++) {
        cout << lowerStorage[i] << " ";
    }
    cout << "\n\n";

    cout << "Upper Triangular Matrix\n";
    cout << "Enter the size (n): ";
    cin >> n;

    int upperMatrix[n][n];
    cout << "Enter the " << n << "x" << n << " matrix:\n";
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> upperMatrix[row][col];
        }
    }

    cout << "You entered:\n";
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << upperMatrix[row][col] << " ";
        }
        cout << "\n";
    }

    int upperStorage[n * (n + 1) / 2];
    index = 0;
    for (int row = 0; row < n; row++) {
        for (int col = row; col < n; col++) {
            upperStorage[index++] = upperMatrix[row][col];
        }
    }

    cout << "Linear representation (Upper Triangular): ";
    for (int i = 0; i < n * (n + 1) / 2; i++) {
        cout << upperStorage[i] << " ";
    }
    cout << "\n\n";

    cout << "Symmetric Matrix\n";
    cout << "Enter the size (n): ";
    cin >> n;

    int symmetricMatrix[n][n];
    cout << "Enter the " << n << "x" << n << " matrix:\n";
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> symmetricMatrix[row][col];
        }
    }

    cout << "You entered:\n";
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << symmetricMatrix[row][col] << " ";
        }
        cout << "\n";
    }

    int symStorage[n * (n + 1) / 2];
    index = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col <= row; col++) {
            symStorage[index++] = symmetricMatrix[row][col];
        }
    }

    cout << "Linear representation (Symmetric): ";
    for (int i = 0; i < n * (n + 1) / 2; i++) {
        cout << symStorage[i] << " ";
    }
    cout << "\n";

    return 0;
}
