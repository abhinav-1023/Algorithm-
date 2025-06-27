#include <iostream>
using namespace std;
int swap(int *n, int *m)
{
    int temp = *n;
    *n = *m;
    *m = temp;
    return 0;
}

void binarySort(int *arr, int len)
{
    for (int pass = 1; pass <= len - 1; pass++)
    {
        int flag = 0;
        for (int j = 0; j <= len - pass; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void quickSort(int *arr, int len)
{
    for (int pass = 1; pass <= len - 1; pass++)
    {
        int min_index = pass;
        for (int j = pass + 1; j <= len - 1; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[pass]);
    }
}

void insertionSort(int *arr, int len)
{
    for (int j = 2; j <= len; j++)
    {
        int key = j + 1;
        int i = j;
        while (i > 0 && arr[i] > arr[key])
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] == arr[key];
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
    binarySort(arr, len);

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << ",";
    }
    return 0;
}
