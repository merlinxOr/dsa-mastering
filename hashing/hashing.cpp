#include <bits/stdc++.h>

using namespace std;

void hashing_nums();
void hashing_chars();
void hashing_map_nums();
void hashing_map_chars();

int main(int argc, char const *argv[])
{
    hashing_nums();
    hashing_chars();
    hashing_map_nums();
    hashing_map_chars();
    return 0;
}

void hashing_nums()
{
    int arr[] = {1, 3, 2, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    int hashing[size] = {0};

    for (int i = 0; i < size; i++)
    {
        hashing[arr[i]]++;
    }
}

void hashing_chars()
{
    string str = "abcdabejcz";

    int hashing[26] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        hashing[str[i] - 'a']++;
    }
}

void hashing_map_nums()
{
    unordered_map<int, int> mpp;
    int arr[] = {1, 2, 3, 1, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto i : mpp)
    {
        cout << i.first << " - " << i.second << " " << endl;
    }
}

void hashing_map_chars()
{
    unordered_map<char, int> mpp;
    string str = "abcdabejcz";

    for (int i = 0; i < str.length(); i++)
    {
        mpp[str[i]]++;
    }

    for (auto i : mpp)
    {
        cout << i.first << " - " << i.second << " " << endl;
    }
}