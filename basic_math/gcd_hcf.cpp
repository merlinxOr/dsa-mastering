#include <iostream>

using namespace std;

int equilateral_algorithm(int, int);
int gcd(int, int);

int main(int argc, char const *argv[])
{
    int n = 40;
    int x = 20;

    for (int i = min(n, x); i >= 1; i--)
    {
        if (n % i == 0 && x % i == 0)
        {
            cout << i << endl;
            break;
        }
    }

    cout << equilateral_algorithm(52, 10) << endl;
    cout << gcd(40, 20) << endl;

    return 0;
}

int equilateral_algorithm(int a, int b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    if (a == 0)
        return b;

    return a;
}

// equilateral_algorithm but elegant
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
