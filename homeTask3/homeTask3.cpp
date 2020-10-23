#include <iostream>
#include <cmath>
#include <fstream>
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
        cout << endl << "Task 1 - Zaem" << endl;
        double S, p, n, r, m;
        cout << "Enter S, p, n: ";
        cin >> S >> p >> n;

        if (p != 0)
        {
            r = p / 100;
            m = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
            cout << "m = " << m << endl;
        }
        else
        {
            m = S / 12 / n;
            cout << "m = " << m << endl;
        }

        task = mojemPovtorit();
    }
}

void task2()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 2 - Ssuda" << endl;
        double S, p, n, r, m, m1 = 0;
        cout << "Enter S, m, n: ";
        cin >> S >> m >> n;

        p = 0;
        while (m1 < m)
        {
            p += 0.01;
            r = p / 100;
            m1 = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
        }

        cout << p << endl;

        task = mojemPovtorit();
    }
}

void task3()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 3 - File" << endl;
        ifstream file("test.txt");
        if (file.is_open())
        {
            char buff[50];
            while (!file.eof())
            {
                file.getline(buff, 50);
                cout << buff << endl;
            }
            file.close();
        }
        else
        {
            cout << "There's no such file in this directory." << endl;
        }

        task = mojemPovtorit();
    }
}

void task4()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 4 - Filter" << endl;
        ifstream file("filter.txt");
        if (file.is_open())
        {
            bool num = false;
            char buff[50];
            while (!file.eof())
            {
                file.getline(buff, 50);
                bool chill = false;
                for (int i = 1; buff[i]; i++)
                {
                    if (buff[i] >= '0' && buff[i] <= '9')
                    {
                        cout << buff[i];
                        num = true;
                        chill = true;
                    }
                    else if (buff[i] == ' ' && chill)
                    {
                        cout << " ";
                        chill = false;
                    }
                }
                cout << endl;
            }
            file.close();
            if (!num)
            {
                cout << "There's no numbers in file." << endl;
            }
        }
        else
        {
            cout << "There's no such file in this directory." << endl;
        }

        task = mojemPovtorit();
    }
}

void task5()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 5 - Sort" << endl;
        char buff[30];
        ifstream file("sort.txt");
        if (file.is_open())
        {
            file.getline(buff, 50);
            cout << buff << endl;
            file.close();

            int x;
            for (int i = 0; i < 30; i++)
            {
                for (int j = 30 - 1; j > i; j--)
                {
                    if (buff[j - 1] > buff[j])
                    {
                        x = buff[j - 1];
                        buff[j - 1] = buff[j];
                        buff[j] = x;
                    }
                }
            }
            cout << buff << endl;
        }
        else
        {
            cout << "There's no such file in this directory." << endl;
        }

        task = mojemPovtorit();
    }
}