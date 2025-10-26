#include <iostream>
using namespace std;

int main()
{
    cout << "Part (a)\n";

    char first[200], second[100];
    cout << "Enter the first string: ";
    cin.getline(first, 200);
    cout << "Enter the second string: ";
    cin.getline(second, 100);

    int idx1 = 0, idx2 = 0;
    while (first[idx1] != '\0')
    {
        idx1++;
    }
    while (second[idx2] != '\0')
    {
        first[idx1] = second[idx2];
        idx1++;
        idx2++;
    }
    first[idx1] = '\0';
    cout << "Result after concatenation: " << first << endl;

    cout << "\nPart (b)\n";

    char revStr[200];
    cout << "Enter a string to reverse: ";
    cin.getline(revStr, 200);
    int len = 0;
    while (revStr[len] != '\0')
    {
        len++;
    }
    for (int i = 0; i < len / 2; i++)
    {
        char temp = revStr[i];
        revStr[i] = revStr[len - i - 1];
        revStr[len - i - 1] = temp;
    }
    cout << "Reversed string is: " << revStr << endl;

    cout << "\nPart (c)\n";

    char original[200];
    cout << "Enter a string to remove vowels: ";
    cin.getline(original, 200);
    int writeIdx = 0;
    for (int i = 0; original[i] != '\0'; i++)
    {
        char ch = original[i];
        if (!(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' ||
              ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' ||
              ch == 'u' || ch == 'U'))
        {
            original[writeIdx++] = ch;
        }
    }
    original[writeIdx] = '\0';
    cout << "String after removing vowels: " << original << endl;

    cout << "\nPart (d)\n";

    int count;
    cout << "How many strings do you want to sort? ";
    cin >> count;
    cin.ignore(); 

    char list[count][100];
    for (int i = 0; i < count; i++)
    {
        cout << "Enter string " << i + 1 << ": ";
        cin.getline(list[i], 100);
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            int k = 0;
            while (list[i][k] != '\0' && list[j][k] != '\0' && list[i][k] == list[j][k])
            {
                k++;
            }
            if (list[i][k] > list[j][k])
            {
                char temp[100];
                int p = 0;
                while (list[i][p] != '\0')
                {
                    temp[p] = list[i][p];
                    p++;
                }
                temp[p] = '\0';

                p = 0;
                while (list[j][p] != '\0')
                {
                    list[i][p] = list[j][p];
                    p++;
                }
                list[i][p] = '\0';

                p = 0;
                while (temp[p] != '\0')
                {
                    list[j][p] = temp[p];
                    p++;
                }
                list[j][p] = '\0';
            }
        }
    }

    cout << "Strings in sorted order:\n";
    for (int i = 0; i < count; i++)
    {
        cout << list[i] << endl;
    }

    cout << "\nPart (e)\n";

    char upperStr[200];
    cout << "Enter a string in UPPERCASE to convert to lowercase: ";
    cin.getline(upperStr, 200);
    int i = 0;
    while (upperStr[i] != '\0')
    {
        if (upperStr[i] >= 'A' && upperStr[i] <= 'Z')
        {
            upperStr[i] = upperStr[i] + 32;
        }
        i++;
    }
    cout << "Converted to lowercase: " << upperStr << endl;
}
