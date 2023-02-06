#include <iostream>
#include "Arr.cpp"
// #include "LL.cpp"
using namespace std;
int main()
{
    freopen("game_input.txt", "r", stdin);
    freopen("game_output.txt", "w", stdout);
    int n, c;
    cin >> n >> c;
    Queue<int> line1(n);
    Stack<int> line2(n);
    int arr_time[n];
    int arr_dur[n];
    int arr_departure[n];
    for (int i = 0; i < n; i++)
    {
        int s, d;
        cin >> s >> d;
        arr_time[i] = s;
        arr_dur[i] = d;
    }
    int j = 0;
    int console_1 = -1, console_2 = -1;
    for (int i = 0; i < c; i++)
    {
        if (console_1 > -1 && arr_departure[console_1] == i)
        {
            console_1 = -1;
        }
        if (console_2 < j && console_2 > -1 && arr_departure[console_2] == i)
        {
            console_2 = -1;
        }
        if (console_1 == -1 && line1.length())
        {
            console_1 = line1.dequeue();
            arr_departure[console_1] = i + arr_dur[console_1];
        }
        if (console_2 == -1 && line2.length())
        {
            console_2 = line2.pop();
            arr_departure[console_2] = i + arr_dur[console_2];
        }
        if (j < n)
        {
            if (arr_time[j] == i)
            {
                if (console_1 == -1)
                {
                    console_1 = j;
                    arr_departure[j] = i + arr_dur[j];
                }
                else if (line1.length() < 3)
                {
                    line1.enqueue(j);
                }
                else
                {
                    if (console_2 == -1)
                    {
                        console_2 = j;
                        arr_departure[j] = i + arr_dur[j];
                    }
                    else
                    {
                        line2.push(j);
                    }
                }
                j++;
            }
        }
        // cout << "Time " << i << "\n";
        // line1.display();
        // line2.display();
    }
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " > " << arr_departure[i] << "\n";
    }
    cout << "\n";
}