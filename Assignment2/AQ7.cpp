#include <iostream>
using namespace std;

int countInversions(int nums[], int len) {
    int inv = 0;
    for (int a = 0; a < len - 1; a++) {
        for (int b = a + 1; b < len; b++) {
            if (nums[a] > nums[b]) {
                inv++;
            }
        }
    }
    return inv;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int data[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    int total = sizeof(data) / sizeof(data[0]);
    int result = countInversions(data, total);

    cout << "Total inversions: " << result << endl;

    return 0;
}
