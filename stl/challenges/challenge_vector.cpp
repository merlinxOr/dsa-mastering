#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int>);
int sorted(int, int);
void sort_vector(vector<int> &);
void sort_vector_elements(vector<int> &, int, int);
void swap(int &, int &);

int main(int argc, char const *argv[])
{

    // Generate a vector of about 10 elements. Choose an element type (e.g. int ).
    // The elements can be unsorted.

    vector<int> vector1;

    int num = 0;

    for (auto i = 0; i < 10; i++)
    {
        vector1.push_back(num++);
    }

    cout << "Exercises 1: " << endl;
    print_vector(vector1);

    // Try to access illegal indices using [] and at(int)

    cout << "Exercises 2: " << endl;
    try
    {
        cout << vector1[98] << endl; // Prints 0
        // cout << vector1.at(98) << endl; // Prints vector::_M_range_check: __n (which is 98) >= this->size() (which is 10)
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << endl;

    // Define a function int sorted( Type one, Type two ) , which returns 1 if num-
    // ber one is less or equal than number two and 0 otherwise.

    cout << "Exercises 3: " << endl;
    cout << sorted(1, 2) << endl;
    cout << sorted(1, 1) << endl;
    cout << sorted(2, 1) << endl;
    cout << endl;

    // Write a function to swap two elements of a vector.
    cout << "Exercises 4: " << endl;
    swap(vector1.at(1), vector1.at(2));

    print_vector(vector1);
    cout << endl;

    // Write a function to sort two elements of a vector. Use sorted and swap

    vector<int>
        vector2 = {54, 33, 67, 89, 0, 1, 69, 122};

    cout << "Exercises 5: " << endl;
    print_vector(vector2);
    sort_vector_elements(vector2, 3, 4);

    print_vector(vector2);
    cout << endl;

    // Write a function to calculate the average of a vector.

    cout << "Exercises 6: " << endl;
    float average = 0;

    for (auto a : vector2)
    {
        average += a;
    }

    cout << average / vector2.size() << endl;
    cout << endl;

    // Write a function to find the smallest element of a vector. Use sorted.

    cout << "Exercises 7: " << endl;
    int min = vector2[0];

    for (vector<int>::iterator it = vector2.begin() + 1; it != vector2.end(); ++it)
    {
        if (sorted(*(it), min))
        {
            min = *(it);
        }
    }

    cout << "Min value: " << min << endl;
    cout << endl;

    // Write a function to sort a vector.
    cout << "Exercises 8: " << endl;

    sort_vector(vector2);

    print_vector(vector2);
    cout << endl;

    return 0;
}

void print_vector(vector<int> v)
{
    for (auto a : v)
    {
        cout << a << " ";
    }
    cout << endl;
}

int sorted(int num1, int num2)
{
    return (num1 < num2 || num1 == num2) ? 1 : 0;
}

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void sort_vector_elements(vector<int> &v, int x, int y)
{
    if (!sorted(v[x], v[y]))
    {
        swap(v[x], v[y]);
    }
}

void sort_vector(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (!sorted(v[j], v[j + 1]))
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}