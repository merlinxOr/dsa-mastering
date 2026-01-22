#include <iostream>

using namespace std;

typedef void (*func)(int);

struct Functions
{
    func pattern1;
    func pattern2;
    func pattern3;
    func pattern4;
    func pattern5;
    func pattern6;
    func pattern7;
    func pattern8;
    func pattern9;
    func pattern10;
    func pattern11;
    func pattern12;
    func pattern13;
    func pattern14;
    func pattern15;
    func pattern16;
};

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "*" << " ";
        }

        cout << endl;
    }
}
void pattern6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < 2 * (n - i) - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern9(int n)
{
    pattern7(n);
    pattern8(n);
}
void pattern10(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int pattern = i + 1;
        if (pattern > n)
        {
            pattern = n + (n - i) - 1;
        }
        for (int j = 0; j < pattern; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}
void pattern11(int n)
{
    int val = 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            val = 1;
        }
        else
        {
            val = 0;
        }
        for (int j = 0; j <= i; j++)
        {

            cout << val << " ";
            val = 1 - val;
        }

        cout << endl;
    }
}
void pattern12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " " << " ";
        }

        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }

        cout << endl;
    }
}
void pattern13(int n)
{
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << count++ << " ";
        }
        cout << endl;
    }
}
void pattern14(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char a = 65;
        for (int j = 0; j < i; j++)
        {
            cout << a << " ";
            a += 1;
        }
        cout << endl;
    }
}
void pattern15(int n)
{
    for (int i = n; i > 0; i--)
    {
        char a = 65;
        for (int j = 0; j < i; j++)
        {
            cout << a << " ";
            a += 1;
        }
        cout << endl;
    }
}
void pattern16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }

        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n = 5;

    func patternArray[] = {
        pattern1,
        pattern2,
        pattern3,
        pattern4,
        pattern5,
        pattern6,
        pattern7,
        pattern8,
        pattern9,
        pattern10,
        pattern11,
        pattern12,
        pattern13,
        pattern14,
        pattern15,
        pattern16};

    int numPatterns = sizeof(patternArray) / sizeof(patternArray[0]);

    for (int i = 0; i < numPatterns; i++)
    {
        patternArray[i](n);
        cout << endl;
    }

    return 0;
}
