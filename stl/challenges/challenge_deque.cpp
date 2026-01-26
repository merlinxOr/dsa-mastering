#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(const string &);

int main(int argc, char const *argv[])
{
    std::string test_cases[] = {
        "a",
        "aa",
        "aba",
        "abba",
        "abbcbba",
        "ab",
        "abc",
        "radar",
        "bob",
        "ana",
        "avid diva",
        "Amore, Roma",
        "A Toyota's a toyota",
        "A Santa at NASA",
        "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
        "This is a palindrome",
        "palindrome"};

    for (const string &test : test_cases)
    {
        cout << "\"" << test << "\" - "
             << (is_palindrome(test) ? "Is palindrome" : "not palindrome")
             << endl;
    }

    return 0;
}

bool is_palindrome(const string &str)
{
    deque<char> dq;

    for (auto ch : str)
    {
        if (isalpha(ch))
        {
            dq.push_back(tolower(ch));
        }
    }

    while (dq.size() > 1)
    {
        if (dq.front() != dq.back())
        {
            return false;
        }
        dq.pop_back();
        dq.pop_front();
    }

    return true;
}
