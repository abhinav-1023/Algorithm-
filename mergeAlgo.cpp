#include <iostream>
using namespace std;

void merge(int *arr, int len, int low, int mid)
{
    int b[len];
    int i = low, k = low, j = mid + 1;
    while (i <= mid && j < len)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        for (j; j < len; j++)
        {
            b[k] = arr[j];
            k++;
        }
    }
    else
    {
        for (i; i <= mid; i++)
        {
            b[k] = arr[i];
            k++;
        }
    }
    for (int i = 0; i < len; i++)
    {
        arr[i] = b[i];
    }
}
