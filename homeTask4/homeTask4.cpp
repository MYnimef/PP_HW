#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <A:\\Coding\\Cpp\\Git\\PP_HW\\ohMy.cpp>

using namespace std;

void task1();
void task2();
int sign(float x);
void task3();
float rectangle(float a, float b);
float triangle(float a, float h);
float circle(float r);
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();

int main()
{
    int num;
    cout << endl << "Hello, User!" << endl << "If you want to fast-travel, tell me the task You need (there are 9 tasks): ";
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
        case 6:
        {
            task6();
        }
        case 7:
        {
            task7();
        }
        case 8:
        {
            task8();
        }
        case 9:
        {
            task9();
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
        cout << endl << "Task 1 - File" << endl;
        cout << "Enter 10 values: ";
        float n[10], summ = 0;
        for (int i = 0; i < 10; i++)
        {
            cin >> n[i];
            summ += n[i];
        }
        cout << "First summ: " << summ << endl;

        ofstream file("taskFile.txt");
        for (int i = 0; i < 10; i++)
        {
            file << n[i] << " ";
        }
        file.close();
        ifstream file2("taskFile.txt");
        float n2[10], summ2 = 0;
        for (int i = 0; i < 10; i++)
        {
            file2 >> n2[i];
        }
        file2.close();

        for (int i = 0; i < 10; i++)
        {
            summ2 += n2[i];
        }
        cout << "Second summ: " << summ2 << endl;

        task = mojemPovtorit();
    }
}

void task2()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 2 - Znak" << endl;
        cout << "Enter value: ";
        float x;
        cin >> x;
        cout << "Sign is: " << sign(x) << endl;

        task = mojemPovtorit();
    }
}

int sign(float x)
{
    int z;
    if (x > 0)
    {
        z = 1;
    }
    else if (x == 0)
    {
        z = 0;
    }
    else
    {
        z = -1;
    }
    return z;
}

void task3()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 3 - Geometry Figures" << endl;
        cout << "Enter the type of figure (R - Rectangle, T - Triangle, C - Circle): ";
        char type;
        cin >> type;

        switch (type)
        {
        case 'R':
        {
            cout << "Enter a, b: ";
            float a, b;
            cin >> a >> b;
            cout << "S = " << rectangle(a, b) << endl;
            break;
        }
        case 'T':
        {
            cout << "Enter a, h: ";
            float a, h;
            cin >> a >> h;
            cout << "S = " << triangle(a, h) << endl;
            break;
        }
        case 'C':
        {
            cout << "Enter r: ";
            float r;
            cin >> r;
            cout << "S = " << circle(r) << endl;
            break;
        }
        }

        task = mojemPovtorit();
    }
}

float rectangle(float a, float b)
{
    float S;
    S = a * b;
    return S;
}

float triangle(float a, float h)
{
    float S;
    S = (a * h) / 2;
    return S;
}

float circle(float r)
{
    float S;
    S = 3.14 * pow(r, 2);
    return S;
}

void task4()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 4 - Honor" << endl;
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                if (i >= 1 && i <= 6 && j < 8)
                {
                    cout << "*";
                }
                else
                {
                    cout << "_";
                }
            }
            cout << endl;
        }

        task = mojemPovtorit();
    }
}

void task5()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 5 - sin(x)" << endl;
        float eps;
        cout << "Enter Eps (recommended value from 0.1 to 0.05): ";
        cin >> eps;

        for (float i = 1 + eps; i >= -1 - 2 * eps; i -= eps)
        {
            for (float j = 0; j < 10; j += eps)
            {
                if ((sin(j) >= (i - eps / 2)) && (sin(j) <= (i + eps / 2)))
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }

        task = mojemPovtorit();
    }
}

void task6()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 6 - Roman numerals" << endl;
        cout << "Enter value (not bigger than 3999 in Roman!): ";
        char roman[16];
        cin >> roman;

        int arabic = 0, I = 0, V = 0, X = 0, L = 0, C = 0, D = 0, M = 0;
        bool flag = false, sub = false;
        for (int i = 0; roman[i]; i++)
        {
            switch (roman[i])
            {
            case 'I':
            {
                arabic += 1;
                I++;
                X = 0;
                break;
            }
            case 'V':
            {
                if (I == 1)
                {
                    arabic += 3;
                }
                else if (I > 1)
                {
                    flag = true;
                }
                else
                {
                    arabic += 5;
                }

                V++;
                I = X = C = M = 0;
                break;
            }
            case 'X':
            {
                if (I == 1)
                {
                    arabic += 8;
                    sub = true;
                }
                else if (I > 1 || V >= 1)
                {
                    flag = true;
                }
                else
                {
                    arabic += 10;
                }

                X++;
                I = C = M = 0;
                break;
            }
            case 'L':
            {
                if (X == 1)
                {
                    arabic += 30;
                }
                else if (I >= 1 || V >= 1 || X > 1)
                {
                    flag = true;
                }
                else
                {
                    arabic += 50;
                }

                L++;
                I = X = C = M = 0;
                break;
            }
            case 'C':
            {
                if (X == 1)
                {
                    arabic += 80;
                    if (sub)
                    {
                        flag = true;
                    }
                    sub = true;
                }
                else if (I >= 1 || V >= 1 || X > 1 || L >= 1)
                {
                    flag = true;
                }
                else
                {
                    arabic += 100;
                }

                C++;
                I = X = M = 0;
                break;
            }
            case 'D':
            {
                if (C == 1)
                {
                    arabic += 300;
                }
                else if (I >= 1 || V >= 1 || X >= 1 || L >= 1 || C > 1)
                {
                    flag = true;
                }
                else
                {
                    arabic += 500;
                }

                D++;
                I = X = C = M = 0;
                break;
            }
            case 'M':
            {
                if (C == 1)
                {
                    arabic += 800;
                    if (sub)
                    {
                        flag = true;
                    }
                }
                else if (I >= 1 || V >= 1 || X >= 1 || L >= 1 || C > 1 || D >= 1)
                {
                    flag = true;
                }
                else
                {
                    arabic += 1000;
                }

                M++;
                I = X = C = 0;
                break;
            }
            }
        }

        if (I > 3 || V > 1 || X > 3 || L > 1 || C > 3 || D > 1 || M > 3 || flag || arabic >= 4000)
        {
            cout << "Wrong input!" << endl;
        }
        else
        {
            cout << "Arabic = " << arabic << endl;
        }

        task = mojemPovtorit();
    }
}

void task7()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 7 - random" << endl;
        const int a = 8, m = 25, c = 9;
        const float s0 = 5;

        cout << "Enter i: ";
        int i, s = s0;
        cin >> i;
        for (int j = 0; j < i; j++)
        {
            s = (a * s + c) % m;
        }
        cout << "Your \"random\" value: " << s << endl;

        task = mojemPovtorit();
    }
}

void task8()
{
    cout << endl << "Task 8 - matrix" << endl;
    const float A[3][4] =
    {
        {5, 2, 0, 10},
        {3, 5, 2, 5},
        {20, 0, 0, 0}
    };
    cout << endl << "Matrix A =" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << setw(4) << A[i][j] << " ";
        }
        cout << endl;
    }

    const float B[4][2] =
    {
        {1.2, 0.5},
        {2.8, 0.4},
        {5, 1},
        {2, 1.5}
    };
    cout << endl << "Matrix B =" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << setw(4) << B[i][j] << " ";
        }
        cout << endl;
    }

    float C[3][2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << endl << "Matrix C =" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << setw(4) << C[i][j] << " ";
        }
        cout << endl;
    }

    float benefit[] = { 0, 1000 }, commission[] = { 0, 1000 }, sum1 = 0, sum2 = 0;
    int who1[2], who2[2];
    for (int i = 0; i < 3; i++)
    {
        float q1 = 0;
        for (int j = 0; j < 2; j++)
        {
            q1 = abs(q1 - C[i][j]);
        }

        if (q1 > benefit[0])
        {
            benefit[0] = q1;
            who1[0] = i + 1;
        }
        if (q1 < benefit[1])
        {
            benefit[1] = q1;
            who1[1] = i + 1;
        }

        if (C[i][1] > commission[0])
        {
            commission[0] = C[i][1];
            who2[0] = i + 1;
        }
        if (C[i][1] < commission[1])
        {
            commission[1] = C[i][1];
            who2[1] = i + 1;
        }

        sum1 += C[i][0];
        sum2 += C[i][1];
    }
    cout << endl <<
        "1) - The richest is " << who1[0] << " , the poorest is " << who1[1] << endl <<
        "2) - The biggest is " << who2[0] << " , the lowest is " << who2[1] << endl <<
        "3) - Benefit is " << sum1 - sum2 << endl <<
        "4) - Commission is " << sum2 << endl <<
        "5) - Total amount " << sum1 << endl;

    cout << "Press Enter to continue...";
    cin.ignore();
    while (cin.get() != '\n');
}

void task9()
{
    bool task = true;
    while (task)
    {
        cout << endl << "Task 9 - scale transform" << endl;
        cout << "Enter first scale, second scale and number: ";
        int scale1, scale2;
        char buff_ch[50];
        bool flag = true;
        cin >> scale1 >> scale2 >> buff_ch;
        if (scale1 <= 1 || scale2 <= 1)
        {
            flag = false;
        }

        int i, z = 0, cel, buff_int[50];
        bool otr = false, drob = false;
        if (buff_ch[0] == '-')
        {
            z++;
            otr = true;
        }
        for (i = z; buff_ch[i]; i++)
        {
            if (buff_ch[i] >= '0' && buff_ch[i] <= '9')
            {
                buff_int[i - z] = buff_ch[i] - '0';
            }
            else if (buff_ch[i] >= 'A' && buff_ch[i] <= 'Z')
            {
                buff_int[i - z] = buff_ch[i] - 'A' + 10;
            }
            else if (buff_ch[i] == '.' && !drob)
            {
                drob = true;
                cel = i - z;
                buff_int[i - z] = 0;
            }
            else
            {
                flag = false;
            }
        }

        if (!drob)
        {
            cel = i - z;
        }

        long int des_int = 0;
        double des_double = 0;
        for (int j = 0; j < cel; j++)
        {
            if (buff_int[j] < scale1)
            {
                des_int += buff_int[j] * pow(scale1, cel - j - 1);
            }
            else
            {
                flag = false;
            }
        }
        if (drob)
        {
            int sup = 0;
            for (int j = cel + 1; j < i - z; j++)
            {
                sup--;
                if (buff_int[j] < scale1)
                {
                    des_double += buff_int[j] * pow(scale1, sup);
                }
                else
                {
                    flag = false;
                }
            }
        }

        if (flag)
        {
            if (otr)
            {
                cout << "-";
            }
            int j, buff_int2[50];
            for (j = 0; des_int >= scale2; j++)
            {
                buff_int2[j] = des_int % scale2;
                des_int /= scale2;
            }
            buff_int2[j] = des_int;

            char result[50];
            for (int k = 0; k <= j; k++)
            {
                if (buff_int2[j - k] >= 0 && buff_int2[j - k] <= 9)
                {
                    result[k] = '0' + buff_int2[j - k];
                }
                else if (buff_int2[j - k] >= 10)
                {
                    result[k] = 'A' + buff_int2[j - k] - 10;
                }
            }

            int g = j;
            if (drob)
            {
                for (g = j + 1; des_double > 0 && g < 15; g++)
                {
                    des_double = des_double * scale2;
                    buff_int2[g] = floor(des_double);
                    if (buff_int2[g] >= 1)
                    {
                        des_double -= buff_int2[g];
                    }
                }

                result[j + 1] = '.';
                for (int k = j + 2; k <= g; k++)
                {
                    if (buff_int2[k - 1] >= 0 && buff_int2[k - 1] <= 9)
                    {
                        result[k] = '0' + buff_int2[k - 1];
                    }
                    else if (buff_int2[k - 1] >= 10)
                    {
                        result[k] = 'A' + buff_int2[k - 1] - 10;
                    }
                }
            }

            for (int k = 0; k <= g; k++)
            {
                cout << result[k];
            }
            cout << endl;
        }
        else
        {
            cout << "Wrong input!" << endl;
        }

        task = mojemPovtorit();
    }
}