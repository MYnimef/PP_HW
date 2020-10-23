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

    return 0;
}

void task1()
{
    cout << endl << "Task 1 - Name." << endl;
    char name[26];
    bool task = true;
    while (task)
    {
        cout << "Enter your name (not longer than 25 symbols!): ";
        cin >> name;
        while (name[25])
        {
            cout << "Enter your name correctly! One more try: ";
            cin >> name;
        }
        cout << "Your name is " << name << endl;

        task = mojemPovtorit();
    }
}

void task2()
{
    cout << endl << "Task 2 - Calculator." << endl;
    cout << "Enter two values: ";
    float v1, v2;
    cin >> v1 >> v2;

    bool task = true;
    while (task)
    {
        cout << "What do you want to do with " << v1 << " and " << v2 << "?" << endl <<
            "1 - summ" << endl << "2 - difference" << endl << "3 - proz" << endl << "4 - chast" << endl <<
            "5 - change values" << endl << "Your choice is: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << v1 + v2 << endl;
            break;
        case 2:
            cout << v1 - v2 << endl;
            break;
        case 3:
            cout << v1 * v2 << endl;
            break;
        case 4:
            if (v2)
            {
                cout << v1 / v2 << endl;
            }
            else
            {
                cout << "Sorry Pal, but i cant do that..." << endl;
            }
            break;
        case 5:
            cout << "Enter two values: ";
            cin >> v1 >> v2;
            break;
        default:
            cout << "Are you a Joker?" << endl;
        }

        if (choice != 5)
        {
            task = mojemPovtorit();
        }
    }
}

void task3()
{
    cout << endl << "Task 3 - Equation." << endl;
    bool task = true;
    while (task)
    {
        cout << "You have to solve the equation bx + c = 0." << endl <<
            "Enter 'b' and 'c': ";
        float b, c;
        cin >> b >> c;
        if (b)
        {
            cout << "x = " << -c / b << endl;
        }
        else if (b == 0 && c == 0)
        {
            cout << "everything" << endl;
        }
        else
        {
            cout << "Can't be solved." << endl;
        }

        task = mojemPovtorit();
    }
}

void task4()
{
    cout << endl << "Task 4 - second equation." << endl;
    bool task = true;
    while (task)
    {
        cout << "You have to solve the equation ax^2 + bx + c = 0." << endl <<
            "Enter 'a', 'b' and 'c': ";
        float a, b, c;
        cin >> a >> b >> c;

        float D;
        D = pow(b, 2) - 4 * a * c;
        if (a == 0 && b == 0 && c == 0)
        {
            cout << "x can be everything" << endl;
        }
        else if (a == 0)
        {
            if (b)
            {
                cout << "x = " << -c / b << endl;
            }
            else
            {
                cout << "Can't be solved." << endl;
            }
        }
        else if (D < 0)
        {
            cout << "No solutions" << endl;
        }
        else if (D == 0)
        {
            cout << "x = " << -b / (2 * a) << endl;
        }
        else
        {
            cout << "x1 = " << (-b + sqrt(D)) / (2 * a) << ", x2 = " << (-b - sqrt(D)) / (2 * a) << endl;
        }

        task = mojemPovtorit();
    }
}

void task5()
{
    cout << endl << "Task 5 - second equation." << endl;
    bool task = true;
    while (task)
    {
        bool day, window, lamp;
        int time;
        char check;

        cout << "What time is it? (XX o'clock - you just enter XX!!!, 24 hour system): ";
        cin >> time;
        if (time >= 8 && time <= 16)
        {
            day = true;
        }
        else if ((time >= 0 && time < 8) || (time > 16 && time <= 24))
        {
            day = false;
        }
        else
        {
            cout << "Very funny, you're such a genious, then let it be random!" << endl;
            day = rand() % 2;
            if (day)
            {
                cout << "It's day!" << endl;
            }
            else
            {
                cout << "It's not day :(" << endl;
            }

        }

        cout << "Is window closed? (Y/N): ";
        cin >> check;
        if (check == 'N' || check == 'n')
        {
            window = false;
        }
        else if (check == 'Y' || check == 'y')
        {
            window = true;
        }
        else
        {
            cout << "Very funny, you're such a genious, then let it be random!" << endl;
        }

        cout << "Is lamp turned on? (Y/N): ";
        cin >> check;
        if (check == 'N' || check == 'n')
        {
            lamp = false;
        }
        else if (check == 'Y' || check == 'y')
        {
            lamp = true;
        }
        else
        {
            cout << "Very funny, you're such a genious, then let it be random!" << endl;
        }

        if ((day && !window) || lamp)
        {
            cout << "It's bright." << endl;
        }
        else
        {
            cout << "It' dark." << endl;
        }

        task = mojemPovtorit();
    }
}
