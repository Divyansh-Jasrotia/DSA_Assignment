#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements to add: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i=0;i<n;i++) 
    {
        cin >> arr[i];
    }
    for (int i=0;i<n;i++) 
    {
        for (int j=i+1;j<n;j++) 
        {
            if (arr[i] == arr[j]) 
            {
                for (int k=j;k<n-1;k++) 
                {
                    arr[k]=arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    cout << "Array after removing the duplicate elements:\n";
    for (int i=0;i<n;i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
