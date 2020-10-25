#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <A:\\Coding\\Cpp\\Git\\PP_HW\\ohMy.cpp>

using namespace std;

void series();
void obr_files();
void files();
void sortShell(int array[], int size);

int main()
{
    int num;
    cout << endl << "Hello, User!" << endl << "If you want to fast-travel, tell me the task You need (there are 3 tasks): ";
    cin >> num;

    switch (num)
    {
        default:
        {
            cout << "Joker, yeah?" << endl;
        }
        case 1:
        {
            series();
        }
        case 2:
        {
            obr_files();
        }
        case 3:
        {
            files();
        }
    }
    cout << endl;
    return 0;
}

void series()
{
    bool task = true;
    while (task)
    {
        cout << "Series - 4" << endl <<
            "Enter n: ";
        int n;
        cin >> n;

        if (n < 1)
        {
            cout << "Ha-ha" << endl;
        }
        else
        {
            float y = 0;
            for (int i = 1; i <= n; i++)
            {
                float del = 0;
                int fact = 1;
                for (int j = 1; j <= i; j++)
                {
                    del += pow(-1, j + 1) / j;
                    fact *= j;
                }
                y += fact / del;
            }
            cout << "Result is " << y << endl;
        }

        task = mojemPovtorit();
    }
}

void obr_files()
{
    bool task = true;
    while (task)
    {
        cout << "Obrabotka - 17" << endl;
        ifstream file("A:\\Coding\\Cpp\\Git\\PP_HW\\variat\\textFiles\\ABC1.txt");
        if (!file.is_open())
        {
            cout << "There's no such file in this directory." << endl;
        }
        else
        {
            char words[50][20];
            int size;
            for (size = 0; !file.eof(); size++)
            {
                char buff[20];
                file >> buff;
                strcpy_s(words[size], buff);
            }
            file.close();
            size = size - 1;

            for (int i = 0; i < size; i++)
            {
                cout << words[i] << " ";
            }
            cout << endl;

            for (int step = size / 2; step > 0; step /= 2)
            {
                for (int i = step; i < size; i++)
                {
                    for (int j = i - step; j >= 0 && strcmp(words[j], words[j + step]) > 0; j -= step)
                    {
                        char tmp[50];
                        strcpy_s(tmp, words[j]);
                        strcpy_s(words[j], words[j + step]);
                        strcpy_s(words[j + step], tmp);
                    }
                }
            }

            for (int i = 0; i < size; i++)
            {
                cout << words[i] << " ";
            }
            cout << endl;

            ofstream file2("A:\\Coding\\Cpp\\Git\\PP_HW\\variat\\textFiles\\ABC2.txt");
            for (int i = 0; i < size; i++)
            {
                file2 << words[i] << endl;
            }
            file2.close();
        }

        task = mojemPovtorit();
    }
}

void files()
{
    bool task = true;
    while (task)
    {
        cout << "Files - 9" << endl <<
            "Enter the amount of inegers for A and B: ";
        int intA, intB;
        cin >> intA >> intB;
        srand(time(0));

        int* massA = new int[intA];
        for (int i = 0; i < intA; i++)
        {
            massA[i] = rand() % 50;
        }
        sortShell(massA, intA);

        ofstream A("A:\\Coding\\Cpp\\Git\\PP_HW\\variat\\textFiles\\A.txt");
        for (int i = 0; i < intA; i++)
        {
            A << massA[i] << " ";
        }
        A.close();
        delete[] massA;

        int* massB = new int[intB];
        for (int i = 0; i < intB; i++)
        {
            massB[i] = rand() % 50;
        }
        sortShell(massB, intB);

        ofstream B("A:\\Coding\\Cpp\\Git\\PP_HW\\variat\\textFiles\\B.txt");
        for (int i = 0; i < intB; i++)
        {
            B << massB[i] << " ";
        }
        B.close();
        delete[] massB;

        int intAA[50], sizeA;
        ifstream AA("A:\\Coding\\Cpp\\Git\\PP_HW\\variat\\textFiles\\A.txt");
        for (sizeA = 0; !AA.eof(); sizeA++)
        {
            intAA[sizeA] = 0;
            char buffA[50];
            AA >> buffA;
            for (int j = 0; buffA[j]; j++)
            {
                intAA[sizeA] *= 10;
                intAA[sizeA] += buffA[j] - '0';
            }
        }
        AA.close();
        sizeA--;

        int intBB[50], sizeB;
        ifstream BB("A:\\Coding\\Cpp\\Git\\PP_HW\\variat\\textFiles\\B.txt");
        for (sizeB = 0; !BB.eof(); sizeB++)
        {
            intBB[sizeB] = 0;
            char buffB[50];
            BB >> buffB;
            for (int j = 0; buffB[j]; j++)
            {
                intBB[sizeB] *= 10;
                intBB[sizeB] += buffB[j] - '0';
            }
        }
        BB.close();
        sizeB--;

        ofstream C("A:\\Coding\\Cpp\\Git\\PP_HW\\variat\\textFiles\\C.txt");
        int a = 0, b = 0;
        while (a < sizeA && b < sizeB)
        {
            if (intAA[a] < intBB[b])
            {
                C << intAA[a] << endl;
                a++;
            }
            else
            {
                C << intBB[b] << endl;
                b++;
            }
        }
        if (sizeA > sizeB)
        {
            for (; a < sizeA; a++)
            {
                C << intAA[a] << endl;
            }
        }
        else
        {
            for (; b < sizeB; b++)
            {
                C << intBB[b] << endl;
            }
        }
        C.close();

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
