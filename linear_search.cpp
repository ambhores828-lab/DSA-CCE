#include <iostream>
using namespace std;

int linear_search(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    int a[20];
    cout << "Enter size of the array: ";
    cin >> n;

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int x;
    cout << "Enter the target element to search for : ";
    cin >> x;

    int location = linear_search(a, n, x);

    if (location != -1)
    {
        cout << "Element " << x << " found at index: " << location << endl;
    }
    else
    {
        cout << "Element" << x << "not found in the array" << endl;
    }
    return 0;
}

//OUTPUT
// PS D:\Atharva_Dighe> cd "d:\Atharva_Dighe\" ; if ($?) { g++ linear_search.cpp -o linear_search } ; if ($?) { .\linear_search }
// Enter size of the array: 10
// Enter 10 integers:
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// Enter the target element to search for : 5 
// Element 5 found at index: 5
// PS D:\Atharva_Dighe> 