#include <iostream>
#include <iomanip>
#include <A:\Coding\Cpp\Git\PP_HW\ohMy.cpp>

using namespace std;

int main()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Enter n: ";
        int n;
        cin >> n;
        int* array = new int[n];
        for (int i = 0; i < n; i++)
        {
            array[i] = i;
            cout << setw(2) << array[i] << " ";
        }
        cout << endl;

        for (int m = 2; m < n; m++)
        {
            for (int j = m * 2; array[m] != 0; j += m)
            {
                if (j < n)
                {
                    array[j] = 0;
                }
                else
                {
                    break;
                }
            }
        }

        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (array[i] != 0)
            {
                j++;
            }
            cout << setw(2) << array[i] << " ";
        }
        cout << endl;

        int* modArray = new int[j], k = 0;
        for (int i = 0; i < n; i++)
        {
            if (array[i] >= 2)
            {
                modArray[k] = array[i];
                cout << setw(2) << modArray[k] << " ";
                k++;
            }
        }
        cout << endl;

        delete[] array;
        delete[] modArray;
        task = mojemPovtorit();
    }
    return 0;
}
