#include <iostream>
#include <iomanip>
#include <cmath>
#include <A:\Coding\Cpp\Git\PP_HW\ohMy.cpp>

using namespace std;

void task1();
void task2();
void task3();
void task4();
void sortShell(int array[], int size);
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

    return 0;
}

void task1()
{
    bool task = true;
    while (task)
    {
        cout << "Task 1" << endl
             << "Enter A, B, C: ";
        int A, B, C, N;
        cin >> A >> B >> C;
        if ((A || B || C) > 2e10 || A > C)
        {
            cout << "Joker lol funny" << endl;
        }
        else
        {
            N = floor((C - A) / B);
            cout << "N = " << N << endl;
        }

        task = mojemPovtorit();
    }
}

void task2()
{
    bool task = true;
    while (task)
    {
        cout << "Task 2 - dont remeber" << endl
             << "Enter M: ";
        int M;
        cin >> M;

        if (M < 2e9)
        {
            int three = 0, four = 0;
            while (M % 4 != 0 && M >= 3)
            {
                M -= 3;
                three++;
            }
            if (M % 4 == 0)
            {
                four += M / 4;
            }
            cout << three << endl << four << endl;
        }
        else
        {
            cout << "Joker dumb." << endl;
        }

        task = mojemPovtorit();
    }
}

void task3()
{
    bool task = true;
    while (task)
    {
        cout << "Task 3 - Jail" << endl
             << "Enter N, M: ";
        int N, M;
        cin >> N >> M;

        if (N < 0 || M < 0 || N > 75000 || M > 75000)
        {
            cout << "Joker dumb." << endl;
        }
        else
        {
            int comb = ((N + 1) * N / 2) * ((M + 1) * M / 2);
            cout << comb << endl;
        }

        task = mojemPovtorit();
    }
}

void task4()
{
    bool task = true;
    while (task)
    {
        cout << "Task 4 - Speedwagon" << endl
             << "Enter N: ";
        int speedWagon[9] = {}, N;
        cin >> N;
        cout << "Enter space: ";
        int* space = new int[N];
        for (int i = 0; i < N; i++)
        {
            cin >> space[i];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if ((space[i] <= 4 * (j + 1) && space[i] >= 1 + 4*j) || space[i] == 53 - 2 * j || space[i] == 54 - 2 * j)
                {
                    speedWagon[j]++;
                    break;
                }
            }
        }
        delete[] space;

        int result[9] = {}, s = 0;
        bool podr = true;
        for (int i = 0; i < 9; i++)
        {
            if (speedWagon[i] == 6 && podr)
            {
                result[s]++;
            }
            else if (speedWagon[i] == 6 && !podr)
            {
                result[s]++;
                podr = true;
            }
            else
            {
                s++;
                podr = false;
            }
        }

        sortShell(result, 9);
        cout << "Max is " << result[8] << endl;
        task = mojemPovtorit();
    }
}

void sortShell(int array[], int size)
{
    for (int step = size / 2; step > 0; step /= 2)
    {
        for (int i = step; i < size; i++)
        {
            for (int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step)
            {
                int tmp;
                tmp = array[j];
                array[j] = array[j + step];
                array[j + step] = tmp;
            }
        }
    }
}

void task5()
{
    bool task = true;
    while (task)
    {
        cout << "Task 5 - cinema" << endl <<
            "Enter N, K: ";
        int N, K;
        cin >> N >> K;

        if (K > N || K < 1 || N < 1)
        {
            cout << "Ah, c'mon" << endl;
        }
        else
        {
            int free1, free2, sup = 0;
            for (int i = 0; i < K; i++)
            {
                if (N % 2 == 0)
                {
                    free1 = N / 2 - 1;
                    free2 = N / 2;
                }
                else
                {
                    free1 = free2 = N / 2;
                }

                if (free2 > sup)
                {
                    N = free2;
                    sup = free1;
                }
                else
                {
                    N = sup;
                    sup = free1;
                }
            }
            cout << free1 << " " << free2 << endl;
        }

        task = mojemPovtorit();
    }
}
