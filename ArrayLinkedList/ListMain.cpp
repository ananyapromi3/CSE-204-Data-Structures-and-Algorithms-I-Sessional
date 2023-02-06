#include <iostream>
// #include "MyArrayList.cpp"
#include "MyLinkedList.cpp"
using namespace std;

template <class dataType>
void display(MyList<dataType> &myList)
{
    cout << "< ";
    int cur = myList.currPos();
    myList.setToBegin();
    if (cur == 0 && myList.length > 0)
    {
        cout << "| ";
    }
    for (int i = 0; i < myList.length; i++)
    {
        if (i > 0 && i == cur)
        {
            cout << "| ";
        }
        cout << myList.getValue() << " ";
        myList.next();
    }
    cout << ">\n";
    myList.setToPos(cur);
}

int main()
{
    freopen("list_input.txt", "r", stdin);
    freopen("list_output.txt", "w", stdout);
    int length, capacity, arr[100];
    cin >> length >> capacity;
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
    MyList<int> myList(length, capacity, arr);
    // cin >>capacity;
    // MyList<int> myList(capacity);
    display(myList);
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
            ans = myList.size();
            break;
        case 2:
            myList.push(param);
            break;
        case 3:
            myList.pushBack(param);
            break;
        case 4:
            ans = myList.erase();
            break;
        case 5:
            myList.setToBegin();
            break;
        case 6:
            myList.setToEnd();
            break;
        case 7:
            myList.prev();
            break;
        case 8:
            myList.next();
            break;
        case 9:
            ans = myList.currPos();
            break;
        case 10:
            myList.setToPos(param);
            break;
        case 11:
            ans = myList.getValue();
            break;
        case 12:
            ans = myList.find(param);
            break;
        case 13:
            myList.clear();
            break;

        default:
            break;
        }
        display(myList);
        cout << ans << "\n";
    }
}

// 4 8
// 1 2 3 4
// 4
// 1 1
// 2 10
// 4 0
// 5 0
