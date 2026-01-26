#include <bits/stdc++.h>

using namespace std;

void all_divisors(int);
void all_divisors_optimal(int);

int main(int argc, char const *argv[])
{
    all_divisors(36);
    all_divisors_optimal(36);

    return 0;
}

void all_divisors(int num)
{

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

void all_divisors_optimal(int num)
{
    set<int> result;

    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            result.emplace(i);
            if ((num / i) != i)
            {
                result.emplace(num / i);
            }
        }
    }

    for (auto n : result)
    {
        cout << n << " ";
    }
}
