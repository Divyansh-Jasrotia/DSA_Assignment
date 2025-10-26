#include <iostream>
using namespace std;

int main()
{
    int len;
    cout << "Enter the size of array: ";
    cin >> len;
    int nums[len];
    cout << "Enter " << len << " elements:\n";
    for (int i=0;i<len;i++)

    {
        cin >> nums[i];
    }

    cout << "Original Array:\n";
    for (int i=0;i<len;i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";

    for (int i=0;i<len/2;i++)
    {
        int temp=nums[i];
        nums[i]=nums[len-1-i];
        nums[len-1-i]=temp;
    }

    cout << "Array after reversing:\n";
    for (int i=0;i<len;i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n\n";

    int row1, col1, row2, col2;
    cout << "Enter number of rows and columns of first matrix: ";
    cin >> row1 >> col1;
    cout << "Enter number rows and columns of second matrix: ";
    cin >> row2 >> col2;

    if (col1!=row2)
    {
        cout << "Matrix multiplication is not possible!\n\n";
    }
    else
    {
        int mat1[row1][col1], mat2[row2][col2], result[row1][col2];
        cout << "Enter elements of first matrix:\n";
        for (int i=0;i<row1;i++)
        {
            for (int j=0;j<col1;j++)
            {
                cin >> mat1[i][j];
            }
        }
        cout << "First Matrix:\n";
        for (int i=0;i<row1;i++)
        {
            for (int j=0;j<col1;j++)
            {
                cout << mat1[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Enter elements of second matrix:\n";
        for (int i=0;i<row2;i++)
        {
            for (int j=0;j<col2;j++)
            {
                cin >> mat2[i][j];
            }
        }
        cout << "Second Matrix:\n";
        for (int i=0;i<row2;i++)
        {
            for (int j=0;j<col2;j++)
            {
                cout << mat2[i][j] << " ";
            }
            cout << endl;
        }

        for (int i=0;i<row1;i++)
        {
            for (int j=0;j<col2;j++)
            {
                result[i][j] = 0;
            }
        }
        for (int i=0;i<row1;i++)
        {
            for (int j=0;j<col2;j++)
            {
                for (int k=0;k<col1;k++)
                {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        cout << "Result of multiplication:\n";
        for (int i=0;i<row1;i++)
        {
            for (int j=0;j<col2;j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n";
    }

    int rows, cols;
    cout << "Enter rows and cols of matrix: ";
    cin >> rows >> cols;
    int matrix[rows][cols];
    cout << "Enter elements of matrix:\n";
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Original Matrix:\n";
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    if (rows==cols)
    {
        for (int i=0;i<rows;i++)
        {
            for (int j=i+1;j<cols;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        cout << "Transpose of matrix:\n";
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<cols;j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        int transpose[cols][rows];
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<cols;j++)
            {
                transpose[j][i] = matrix[i][j];
            }
        }
        cout << "Transpose of matrix:\n";
        for (int i=0;i<cols;i++)
        {
            for (int j=0; j<rows;j++)
            {
                cout << transpose[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
