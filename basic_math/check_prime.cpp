#include <bits/stdc++.h>

using namespace std;

bool force_brute_prime(int);
bool optimal_prime(int);

int main(int argc, char const *argv[])
{
    // Prime: 11, 13, 5
    // Not prime: 4, 8

    cout << (force_brute_prime(11) ? "Prime number" : "Not prime number") << endl;
    cout << (force_brute_prime(4) ? "Prime number" : "Not prime number") << endl;

    cout << (optimal_prime(13) ? "Prime number" : "Not prime number") << endl;
    cout << (optimal_prime(8) ? "Prime number" : "Not prime number") << endl;

    return 0;
}

bool force_brute_prime(int num)
{
    if (num <= 1)
        return false;

    if (num == 2)
        return true;

    if (num % 2 == 0)
        return false;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

bool optimal_prime(int num)
{
    if (num <= 1)
        return false;

    if (num == 2)
        return true;

    if (num % 2 == 0)
        return false;

    for (int i = 3; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}