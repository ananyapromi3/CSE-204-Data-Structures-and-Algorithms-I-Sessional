#include <iostream>
#include <cstring>
#include "MinHeap.cpp"
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    MinHeap *minHeap;
    minHeap = new MinHeap(100);
    char str[50];
    while (cin >> str)
    {
        if (!strcmp(str, "INS"))
        {
            int val;
            cin >> val;
            minHeap->insert(val);
        }
        else if (!strcmp(str, "PRI"))
        {
            cout << "Printing the binary heap ...\n";
            minHeap->print();
        }
        else if (!strcmp(str, "DEC"))
        {
            int prevKey, newKey;
            cin >> prevKey >> newKey;
            minHeap->DecreaseKey(prevKey, newKey);
        }
        else if (!strcmp(str, "FIN"))
        {
            cout << "FindMin returned " << minHeap->FindMin() << "\n";
        }
        else if (!strcmp(str, "EXT"))
        {
            cout << "ExtractMin returned " << minHeap->ExtractMin() << "\n";
        }
    }
    MinHeap *minHeap2;
    int arr[] = {4, 10, 8, 30, 2, 3, 6, 70, 25, 1};
    minHeap2 = new MinHeap(20);
    minHeap2->insertNoHeapify(4);
    minHeap2->insertNoHeapify(10);
    minHeap2->insertNoHeapify(8);
    minHeap2->insertNoHeapify(30);
    minHeap2->insertNoHeapify(2);
    minHeap2->insertNoHeapify(3);
    minHeap2->insertNoHeapify(6);
    minHeap2->insertNoHeapify(70);
    minHeap2->insertNoHeapify(25);
    minHeap2->insertNoHeapify(1);
    minHeap2->print();
    minHeap2->heapifyFull();
    minHeap2->print();
}

// INS 7
// INS 10
// INS 5
// PRI
// INS 12
// INS 15
// PRI
// DEC 15 3
// PRI
// FIN
// EXT
// PRI