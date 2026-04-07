#include <bits/stdc++.h>
using namespace std;

int allocate_books_bf(vector<int> &books, int students);
int allocate_books_optimal(vector<int> &books, int students);

int count_students(vector<int> &books, int maxPages);

int main()
{
    vector<int> books = {12, 34, 67, 90};
    int students = 2;

    int res = allocate_books_optimal(books, students);

    cout << res << endl;
}

/*
 * Time complexity = O(n * sum(books))
 * Space complexity = O(1)
 */
int allocate_books_bf(vector<int> &books, int students)
{
    if (students > books.size())
        return -1;

    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);

    for (int pages = low; pages <= high; pages++)
    {
        if (count_students(books, pages) <= students)
            return pages;
    }

    return -1;
}

/*
 * Time complexity = O(n * log(sum(books)))
 * Space complexity = O(1)
 */
int allocate_books_optimal(vector<int> &books, int students)
{
    if (students > books.size())
        return -1;

    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int required = count_students(books, mid);

        if (required <= students)
        {
            ans = mid;      // possible answer
            high = mid - 1; // try smaller maximum
        }
        else
        {
            low = mid + 1; // need more pages
        }
    }

    return ans;
}

/*
 * count how many students are needed
 * if each student gets at most maxPages
 */
int count_students(vector<int> &books, int maxPages)
{
    int students = 1;
    int pages = 0;

    for (int b : books)
    {
        if (pages + b > maxPages)
        {
            students++;
            pages = b;
        }
        else
        {
            pages += b;
        }
    }

    return students;
}