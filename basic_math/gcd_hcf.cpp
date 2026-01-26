#include <iostream>

using namespace std;

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

    return 0;
}
