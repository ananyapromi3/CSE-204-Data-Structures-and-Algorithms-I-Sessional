#include <iostream>
#include <vector>
using namespace std;

vector<int> ansVector;

int KnapSack(int weight[], int value[], int n, int w)
{
    int dp[n + 1][w + 1];
    vector<int> v;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], (value[i - 1] + dp[i - 1][j - weight[i - 1]]));
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= w; j++)
    //     {
    //         printf("%4d", dp[i][j]);
    //     }
    //     cout << "\n";
    // }
    int ans = dp[n][w];
    int j = w;
    for (int i = n; i > 0 && ans > 0 && j >= 0; i--)
    {
        if (ans == dp[i - 1][j])
        {
            continue;
        }
        else
        {
            ansVector.push_back(weight[i - 1]);
            j -= weight[i - 1];
            ans -= value[i - 1];
        }
    }
    return dp[n][w];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int *weight, *value;
    weight = new int(n);
    value = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    int w;
    cin >> w;
    cout << KnapSack(weight, value, n, w) << "\n";
    for (auto v : ansVector)
    {
        cout << v << " ";
    }
    cout << "\n";
    return 0;
}

// 4
// 20 40
// 10 100
// 40 50
// 30 60
// 60

// 4
// 2 12
// 1 10
// 3 20
// 2 15
// 5
