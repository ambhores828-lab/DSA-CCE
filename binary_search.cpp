#include <iostream>
using namespace std;

int binary_search(int a[], int n, int x)
{
    int first = 0;
    int last = n - 1;
    int mid;

    while (first <= last)
    {
        mid = (first + last) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] < x)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, x;
    int a[20];

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter " << n << " sorted integers : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the target element to search for : ";
    cin >> x;

    int position = binary_search(a, n, x);
    if (position != -1)
        cout << "Element found at position" << position << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

// Output

/*
PS D:\Atharva_Dighe> cd "d:\Atharva_Dighe\" ; if ($?) { g++ binary_search.cpp -o binary_search } ; if ($?) { .\binary_search }
Enter the size of the array: 5
Enter 5 sorted integers : 
0
1
2
3
4
Enter the target element to search for : 6
Element not found.
PS D:\Atharva_Dighe> cd "d:\Atharva_Dighe\" ; if ($?) { g++ binary_search.cpp -o binary_search } ; if ($?) { .\binary_search }
Enter the size of the array: 5
Enter 5 sorted integers : 
1
2
3 
4
5
Enter the target element to search for : 2
Element found at position1
PS D:\Atharva_Dighe>
*/