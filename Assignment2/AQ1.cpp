#include <iostream>
using namespace std;

int main()
{
    int size, target;
    cout << "Enter size of array: ";
    cin >> size;

    int nums[size];
    cout << "Enter elements in sorted order: ";
    for(int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter element to search: ";
    cin >> target;

    int left = 0, right = size - 1, midIndex, foundAt = -1;

    while(left <= right)
    {
        midIndex = (left + right) / 2;

        if(nums[midIndex] == target)
        {
            foundAt = midIndex;
            break;
        }
        else if(nums[midIndex] < target)
        {
            left = midIndex + 1;
        }
        else
        {
            right = midIndex - 1;
        }
    }

    if(foundAt != -1)
    {
        cout << "Element found at index " << foundAt << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}
