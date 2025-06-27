#include <iostream>
using namespace std;

int min_max(int *arr, int i, int j, int *min, int *max)
{
    if (i == j)
    {
        *min = *max = arr[i];
    }
    else if (i == j - 1)
    {
        if (arr[i] < arr[j])
        {
            *min = arr[i];
            *max = arr[j];
        }
        else
        {
            *min = arr[j];
            *max = arr[i];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int min1, min2, max1, max2;
        min_max(arr, i, mid, &min1, &max1);
        min_max(arr, mid + 1, j, &min2, &max2);

        if (min1 > min2)
        {
            min1 = min2;
        }
        *min = min1;
        if (max1 < max2)
        {
            max1 = max2;
        }
        *max = max1;
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
    int min, max;
    min_max(arr, 0, len - 1, &min, &max);
    cout << "Max =" << max << endl;
    cout << "Min=" << min;
}