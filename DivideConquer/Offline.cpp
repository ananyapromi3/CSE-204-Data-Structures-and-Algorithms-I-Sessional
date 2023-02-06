#include <iostream>
#include <vector>
using namespace std;

int MergeAndCount(int arr[], int start1, int end1, int start2, int end2)
{
    int invCount = 0;
    int i = start1;
    int j = start2;
    int n = end2 - start1 + 1;
    int temp[n];
    int t = 0;
    while (i <= end1 && j <= end2)
    {
        if (arr[i] > arr[j])
        {
            invCount += (start2 - i);
            temp[t++] = arr[j++];
        }
        else if (arr[i] < arr[j])
        {
            temp[t++] = arr[i++];
        }
        else
        {
            temp[t++] = arr[i++];
        }
    }
    while (i <= end1)
    {
        temp[t++] = arr[i++];
    }
    while (j <= end2)
    {
        temp[t++] = arr[j++];
    }
    t = 0;
    for (int k = start1; k <= end2; k++)
    {
        arr[k] = temp[t++];
    }
    return invCount;
}

int SortAndCount(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (end + start) / 2;
        int rA = SortAndCount(arr, start, mid);
        int rB = SortAndCount(arr, mid + 1, end);
        int r = MergeAndCount(arr, start, mid, mid + 1, end);
        return rA + rB + r;
    }
    else
    {
        return 0;
    }
}

void PrintInvPairs(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                cout << "(" << arr[i] << ", " << arr[j] << "), ";
            }
        }
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    int arr[n], resv[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        resv[i] = arr[i];
    }
    cout << SortAndCount(resv, 0, n - 1) << "\n";
    PrintInvPairs(arr, n);
    return 0;
}

// 5
// 2 4 1 3 5