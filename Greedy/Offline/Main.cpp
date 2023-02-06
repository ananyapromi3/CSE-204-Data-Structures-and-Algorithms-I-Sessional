#include <iostream>
#include <utility>
#include <vector>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
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
    sort(v.begin(), v.end(), sortbysec);
    int last_time = 0;
    for (auto i : v)
    {
        if (i.first >= last_time)
        {
            ans.push_back(i);
            last_time = i.second;
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
    {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}