#include <iostream>
#include <vector>
using namespace std;

int Sum(int arr[], int l, int r)
{
    if (r <= l)
    {
        return arr[r];
    }
    int m = (l + r) / 2;
    int lsum = Sum(arr, l, m);
    int rsum = Sum(arr, m + 1, r);
    int lsubsum = 0, rsubsum = 0, maxl = arr[m], maxr = arr[m + 1];
    for (int i = m; i >= l; i--)
    {
        lsubsum += arr[i];
        maxl = max(maxl, lsubsum);
    }
    for (int i = m + 1; i <= r; i++)
    {
        rsubsum += arr[i];
        maxr = max(maxr, rsubsum);
    }
    return max(max(lsum, rsum), (maxl + maxr));
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << Sum(arr, 0, n - 1);
    cout << "\n";
}