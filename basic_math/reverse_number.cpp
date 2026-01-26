#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num = 7789;
    int reversed = 0;

    while (num != 0)
    {
        int digit = num % 10;
        num /= 10;
        reversed = (reversed * 10) + digit;
    }

    cout << reversed << endl;

    return 0;
}
