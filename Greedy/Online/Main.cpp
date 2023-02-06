#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    vector<pair<int, int> > v, ans;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start_time, end_time;
        cin >> start_time >> end_time;
        v.push_back(make_pair(start_time, end_time));
    }
    int max_count = 1;
    for (auto i : v)
    {
        int count = 1;
        for (auto j : v)
        {
            if (i != j && j.first <= i.first && j.second > i.first)
            {
                count++;
            }
        }
        max_count = max(max_count, count);
    }
    cout << max_count << "\n";
    return 0;
}