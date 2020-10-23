#include <iostream>
#include <cmath>
#include <A:\Coding\Cpp\Git\PP_HW\ohMy.cpp>

using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();

int main()
{
    int num;
    cout << endl << "Hello, User!" << endl << "If you want to fast-travel, tell me the task You need (there are 5 tasks): ";
    cin >> num;

    switch (num)
    {
    default:
    {
        cout << "Joker, yeah?" << endl;
    }
    case 1:
    {
        task1();
    }
    case 2:
    {
        task2();
    }
    case 3:
    {
        task3();
    }
    case 4:
    {
        task4();
    }
    case 5:
    {
        task5();
    }
    }
    cout << endl;

    return 0;
}

void task1()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 1 - Figure" << endl;
        float h, r, R, l, V, S;
        const float pi = 3.14;
        cout << "Enter R: ";
        cin >> R;
        cout << "Enter r: ";
        cin >> r;
        cout << "Enter h: ";
        cin >> h;

        l = sqrt(pow(h, 2) + pow(R - r, 2));
        V = pi * h * (pow(R, 2) + R * r + pow(r, 2)) / 3;
        S = pi * (pow(R, 2) + (R + r) * l + pow(r, 2));
        cout << "V = " << V << endl << "S = " << S << endl;

        task = mojemPovtorit();
    }
}

void task2()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 2 - Tree" << endl;
        cout << "Input 'a' and 'x': ";
        float a, x;
        cin >> a >> x;

        if (abs(x) == 0)
        {
            cout << "pa2u dodik" << endl;
        }
        else if (abs(x) < 1)
        {
            cout << "w = " << a * log(abs(x)) << endl;
        }
        else if ((a - pow(x, 2)) < 0)
        {
            cout << "pa2u dodik" << endl;
        }
        else
        {
            cout << "w = " << sqrt(a - pow(x, 2)) << endl;
        }

        task = mojemPovtorit();
    }
}

void task3()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 3 - Function" << endl;
        cout << "Input 'b', 'x' and 'y': ";
        float b, x, y;
        cin >> b >> x >> y;

        if ((b - y) <= 0 || (b - x) < 0)
        {
            cout << "pa2u dodik" << endl;
        }
        else
        {
            cout << "z = " << log(b - y) * sqrt(b - x) << endl;
        }

        task = mojemPovtorit();
    }
}

void task4()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 4 - Order" << endl;
        cout << "Enter start value: ";
        float start;
        cin >> start;

        cout << start << " ";
        if (start <= 0)
        {
            for (int i = 0; i < 9; i++)
            {
                cout << 1 + i << " ";
            }
        }
        else
        {
            for (int i = 1; i < 10; i++)
            {
                cout << floor(start) + i << " ";
            }
        }
        cout << endl;

        task = mojemPovtorit();
    }
}

void task5()
{
    cout << endl << "Task 5 - Tab" << endl;

    float x[17];
    int i = 0;
    x[0] = -4;
    while (x[i] != 4)
    {
        i++;
        x[i] = x[i - 1] + 0.5;
    }

    float y[17];
    for (int j = 0; j <= i; j++)
    {
        if (x[j] == 0)
        {
            y[j] = 0;
            cout << "Infinite thing bla" << " | x[" << j << "] = " << x[j] << endl;
        }
        else
        {
            y[j] = (pow(x[j], 2) - 2 * x[j] + 2) / (x[j] - 1);
            cout << "y[" << j << "] = " << y[j] << " | x[" << j << "] = " << x[j] << endl;
        }
    }
}