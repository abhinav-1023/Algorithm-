#include <iostream>
using namespace std;

int partitioning(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (j >= low && arr[j] > pivot)
            j--;

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]); // Place pivot at correct position
    return j;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int j = partitioning(arr, low, high);
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
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

    quickSort(arr, 0, len - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
