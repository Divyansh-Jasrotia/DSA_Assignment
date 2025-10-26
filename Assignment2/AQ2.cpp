#include <iostream>
using namespace std;

int main()
{
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int length = 7;

    for(int pass = 0; pass < length - 1; pass++)
    {
        for(int idx = 0; idx < length - pass - 1; idx++)
        {
            if(data[idx] > data[idx + 1])
            {
                int temp = data[idx];
                data[idx] = data[idx + 1];
                data[idx + 1] = temp;
            }
        }
    }

    cout << "Array after sorting: ";
    for(int k = 0; k < length; k++)
    {
        cout << data[k] << " ";
    }
    cout << endl;
}
