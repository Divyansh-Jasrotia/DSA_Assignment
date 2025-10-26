#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate == 0) {
            distinctCount++;
        }
    }

    cout << "Number of distinct elements: " << distinctCount << endl;
    return 0;
}
