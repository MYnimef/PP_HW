#include <iostream>
#include <A:\Coding\Cpp\Git\PP_HW\ohMy.cpp>

using namespace std;

int main()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Enter a, b: ";
        int a, b;
        cin >> a >> b;
        while (a != 0 && b != 0)
        {
            if (a > b)
            {
                a = a % b;
            }
            else
            {
                b = b % a;
            }
        }
        cout << "Result: " << a + b << endl;
        task = mojemPovtorit();
    }
    return 0;
}
