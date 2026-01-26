#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num = 7789;

    while (num != 0)
    {
        int digit = num % 10;
        num /= 10;
        cout << num << ", " << digit << endl;
    }

    return 0;
}
