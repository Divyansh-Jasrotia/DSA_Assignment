#include <iostream>
using namespace std;

int main()
{
    int nums[] = {1, 2, 3, 4, 6, 7, 8};
    int size = 7;
    int missingNum = -1;

    for(int val = 1; val <= size + 1; val++)
    {
        bool found = false;
        for(int idx = 0; idx < size; idx++)
        {
            if(nums[idx] == val)
            {
                found = true;
                break;
            }
        }
        if(!found)
        {
            missingNum = val;
            break;
        }
    }

    cout << "Missing number is: " << missingNum << endl;
}
