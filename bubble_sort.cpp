#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    int a[10];

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter " << n << " integers in any order: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bubble_sort(a, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}

//OUTPUT
/*
PS D:\Atharva_Dighe> cd "d:\Atharva_Dighe\" ; if ($?) { g++ bubble_sort.cpp -o bubble_sort } ; if ($?) { .\bubble_sort }
Enter the size of the array: 10
Enter 10 integers in any order: 
90
99
48
25
23
56
96
84
15
12
Sorted array: 12 15 23 25 48 56 84 90 96 99 
PS D:\Atharva_Dighe> 
*/