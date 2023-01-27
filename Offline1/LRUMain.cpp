#include <iostream>
#include "LRUCache.cpp"
using namespace std;
int main()
{
    freopen("lru_input.txt", "r", stdin);
    freopen("lru_output.txt", "w", stdout);
    int capacity;
    cin >> capacity;
    LRUCache<int, int> lru(capacity);
    int query;
    int func, x, y;
    cin >> query;
    for (int i = 0; i < query; i++)
    {
        cin >> func;
        if (func == 1)
        {
            cin >> x;
            cout << lru.get(x) << "\n";
        }
        else if (func == 2)
        {
            cin >> x >> y;
            lru.put(x, y);
        }
    }
}

// 2
// 7
// 2 1 1
// 2 2 2
// 2 3 3
// 1 1
// 1 2
// 2 4 4
// 1 3