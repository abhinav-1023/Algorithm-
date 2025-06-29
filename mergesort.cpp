#include <iostream>
using namespace std;

void merge(int *arr, int low, int mid, int high)
{
    int b[high - low + 1];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }

    while (i <= mid)
        b[k++] = arr[i++];

    while (j <= high)
        b[k++] = arr[j++];

    for (int p = 0; p < k; p++)
        arr[low + p] = b[p]; // Copy back to original array
}

void mergeSort(int *arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int len;
    cout << "Enter length of Array: ";
    cin >> len;

    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cout << "Enter value at " << i << " place: ";
        cin >> arr[i];
    }

    mergeSort(arr, 0, len - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
