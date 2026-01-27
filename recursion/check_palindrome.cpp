#include <bits/stdc++.h>

using namespace std;

bool check_palindrome(int, const string &, int);

int main(int argc, char const *argv[])
{
    string str_palindrome = "madam";
    string str_not_palindrome = "madsm";

    cout << (check_palindrome(0, str_palindrome, str_palindrome.length()) ? "Is palindrome" : "Is not palindrome") << endl;
    cout << (check_palindrome(0, str_not_palindrome, str_not_palindrome.length()) ? "Is palindrome" : "Is not palindrome") << endl;
    return 0;
}

bool check_palindrome(int i, const string &str, int n)
{
    if (i >= n / 2)
    {
        return true;
    }
    if (str[i] != str[n - i - 1])
    {
        return false;
    }

    return check_palindrome(i + 1, str, n);
}
