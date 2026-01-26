#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int num = 371; // 1634 35
    int temp = num;
    int sum = 0;

    int size = (int)log10(num) + 1;

    while (num != 0)
    {
        int digit = num % 10;
        sum += pow(digit, size);
        num /= 10;
    }

    cout << ((sum == temp) ? "Is Armstrong number" : "Is not Armstrong number") << endl;

    return 0;
}
