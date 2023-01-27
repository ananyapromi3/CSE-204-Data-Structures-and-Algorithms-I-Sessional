#include <iostream>
// #include "StackArr.cpp"
// #include "QueueArr.cpp"
// #include "StackLL.cpp"
// #include "QueueLL.cpp"
#include "Arr.cpp"
// #include "LL.cpp"
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int length_s, capacity_s, arr_s[100];
    cin >> length_s >> capacity_s;
    for (int i = 0; i < length_s; i++)
    {
        cin >> arr_s[i];
    }
    Stack<int> stack(length_s, capacity_s, arr_s);
    stack.display();
    int length_q, capacity_q, arr_q[100];
    cin >> length_q >> capacity_q;
    for (int i = 0; i < length_q; i++)
    {
        cin >> arr_q[i];
    }
    Queue<int> queue(length_q, capacity_q, arr_q);
    queue.display();
    int query;
    int func, param;
    cin >> query;
    for (int i = 0; i < query; i++)
    {
        cin >> func >> param;
        int ans = -1;
        switch (func)
        {
        case 1:
            queue.clear();
            queue.display();
            break;
        case 2:
            queue.enqueue(param);
            queue.display();
            break;
        case 3:
            ans = queue.dequeue();
            queue.display();
            break;
        case 4:
            ans = queue.length();
            queue.display();
            break;
        case 5:
            ans = queue.frontValue();
            queue.display();
            break;
        case 6:
            ans = queue.rearValue();
            queue.display();
            break;
        case 7:
            ans = queue.leaveQueue();
            queue.display();
            break;
        case 8:
            stack.clear();
            stack.display();
            break;
        case 9:
            stack.push(param);
            stack.display();
            break;
        case 10:
            ans = stack.pop();
            stack.display();
            break;
        case 11:
            ans = stack.length();
            stack.display();
            break;
        case 12:
            ans = stack.topValue();
            stack.display();
            break;

        default:
            break;
        }
        cout << ans << "\n";
    }
}
