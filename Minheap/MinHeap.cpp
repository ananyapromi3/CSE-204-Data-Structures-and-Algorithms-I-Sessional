#include <iostream>
#include <cmath>
using namespace std;

class MinHeap
{
    int *arr;
    int capacity;
    int size;

    int parent(int i) { return (int)((i - 1) / 2); }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapify(int i)
    {
        int temp;
        while (i > 0)
        {
            if (arr[parent(i)] > arr[i])
            {
                temp = arr[i];
                arr[i] = arr[parent(i)];
                arr[parent(i)] = temp;
                i = parent(i);
            }
            else
            {
                break;
            }
        }
    }

    void heapifyRev(int i, int size)
    {
        int minIndex = i;
        int temp;
        if (leftChild(i) < size && arr[leftChild(i)] < arr[i])
        {
            minIndex = leftChild(i);
        }
        if (rightChild(i) < size && arr[rightChild(i)] < arr[minIndex])
        {
            minIndex = rightChild(i);
        }
        if (minIndex != i)
        {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            heapifyRev(minIndex, size);
        }
    }

    int searchKey(int key)
    {
        for (int i = 0; i < size; i++)
        {
            if (key == arr[i])
            {
                return i;
            }
        }
        return -1;
    }

public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        arr = new int[capacity];
    }

    void heapifyFull()
    {
        for (int i = size / 2; i >= 0; i--)
        {
            heapifyRev(i, size);
        }
        // for (int i = 1; i < size; i++)
        // {
        //     heapify(i);
        // }
    }

    ~MinHeap()
    {
        this->size = 0;
        delete[] arr;
    }

    int FindMin() // Returns the minimum key
    {
        if (size == 0)
        {
            cout << "Heap empty! ";
            return -1;
        }
        return arr[0];
    }

    int ExtractMin() // Returns the minimum key and deletes it from the heap
    {
        if (size == 0)
        {
            cout << "Heap empty! ";
            return -1;
        }
        int min = arr[0];
        arr[0] = arr[--size];
        if (size > 0)
        {
            heapifyRev(0, size);
        }
        return min;
    }

    void insert(int val) // Inserts a new key in the heap
    {
        if (size == capacity)
        {
            cout << "Heap full!\n";
            return;
        }
        arr[size++] = val;
        heapify(size - 1);
        cout << "INSERTED " << val << "\n";
    }

    void insertNoHeapify(int val) // Inserts a new key in the heap without heapify
    {
        if (size == capacity)
        {
            cout << "Heap full!\n";
            return;
        }
        arr[size++] = val;
        cout << "INSERTED " << val << " without heapifying\n";
    }

    void DecreaseKey(int prevKey, int newKey) // Decrease the value of the specified key to a new value
    {
        int index = searchKey(prevKey);
        if (index < 0)
        {
            cout << "Not found!\n";
            return;
        }
        arr[index] = newKey;
        heapify(index);
        cout << prevKey << " decreased to " << newKey << "\n";
    }

    void deleteKey(int key)
    {
        DecreaseKey(key, INT_MIN);
        ExtractMin();
        cout << key << " deleted\n";
    }

    void sort()
    {
        int temp;
        int s = size - 1;
        while (s >= 0)
        {
            temp = arr[s];
            arr[s] = arr[0];
            arr[0] = temp;
            s--;
            heapifyRev(0, s);
        }
    }

    void print()
    {
        int n = 0;
        cout << "- - - - - - - - - - - - - - - - - - - -";
        for (int i = 0; i < size; i++)
        {
            if (pow(2, n) == i + 1)
            {
                cout << "\nLevel " << n << ": ";
                n++;
            }
            cout << arr[i] << " ";
        }
        cout << "\n- - - - - - - - - - - - - - - - - - - -\n";
    }
};