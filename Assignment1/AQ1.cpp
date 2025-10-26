#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int n=0;
    int com, i, pos, x, found;

    while (true) {
        cout << "----- MENU -----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your command(Number only): ";
        cin >> com;


        if (com==1) 
        {
            cout << "Enter no. of elements: ";
            cin >> n;
            cout << "Enter " << n << " elements:\n";
            for (i = 0; i < n; i++) {
                cin >> arr[i];
            }
        } 
        else if (com==2) 
        {
            if (n == 0)
                cout << "Array has no values.\n";
            else 
            {
                cout << "Array elements: ";
                for (i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }
        } 
        else if (com==3) 
        {
            cout << "Enter position (1 to " << n+1 << "): ";
            cin >> pos;
            cout << "Enter element: ";
            cin >> x;
            if (pos < 1 || pos > n+1) 
            {
                cout << "Invalid position!\n";
            } 
            else 
            {
                for (i = n; i >= pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos - 1] = x;
                n++;
                cout << "Element inserted.\n";
            }
        } 
        else if (com == 4) 
        {
            cout << "Enter position (1 to " << n << "): ";
            cin >> pos;
            if (pos < 1 || pos > n) 
            {
                cout << "Invalid position!\n";
            } 
            else 
            {
                x = arr[pos - 1];
                for (i = pos - 1; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                cout << "Element deleted: " << x << endl;
            }
        } 
        else if (com == 5) 
        {
            cout << "Enter element to search: ";
            cin >> x;
            found = -1;
            for (i = 0; i < n; i++) 
            {
                if (arr[i] == x) 
                {
                    found = i;
                    break;
                }
            }
            if (found == -1)
                cout << "Element not found.\n";
            else
                cout << "Element found at position " << found + 1 << endl;
        } 
        else if (com == 6) 
        {
            cout << "Ending program.\n";
            break;
        } 
        else 
        {
            cout << "Invalid command! Enter Again.\n";
        }
    }
    return 0;
}