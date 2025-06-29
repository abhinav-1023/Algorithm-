#include <iostream>
using namespace std;

int binarySearch(int *arr, int key, int i, int j)
{
    if (i > j)
    {
        return -1;
    }

    else
    {
        int mid = (i + j) / 2;

        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            binarySearch(arr, key, i, mid - 1);
        }
        else
        {
            binarySearch(arr, key, mid + 1, j);
        }
    }
}

int main()
{
    int len;
    cout << "Enter length of Array" << endl;
    cin >> len;

    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cout << "Enter value at ", i, "place : ";
        cin >> arr[i];
    }

    int key;
    cout << "Enter element to find in Array" << endl;
    cin >> key;
    int a = binarySearch(arr, key, 0, len);
    cout << "Element found at index =" << a;
}