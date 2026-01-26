#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num = 1221;
    int temp = num;
    int reverse = 0;

    while (num != 0)
    {
        int digit = num % 10;
        num /= 10;
        reverse = (reverse * 10) + digit;
    }

    cout << ((reverse == temp) ? "Is palindrome" : "Is not palindrome") << endl;

    return 0;
}
