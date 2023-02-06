#include <iostream>
using namespace std;
template <class dataType>
class Stack
{
    dataType *arr;
    int size;
    int capacity;

    void increaseCapacity()
    {
        dataType *tempArray;
        tempArray = new dataType[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            tempArray[i] = arr[i];
        }
        delete[] arr;
        this->capacity *= 2;
        arr = new dataType[this->size + 1];
        for (int i = 0; i < this->size; i++)
        {
            arr[i] = tempArray[i];
        }
        delete[] tempArray;
    } // O(n)

    void decreaseCapacity()
    {
        dataType *tempArray;
        tempArray = new dataType[this->size + 1];
        for (int i = 0; i < this->size; i++)
        {
            tempArray[i] = arr[i];
        }
        delete[] arr;
        this->capacity /= 2;
        arr = new dataType[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            arr[i] = tempArray[i];
        }
        delete[] tempArray;
    } // O(n)

public:
    Stack(int size, int capacity, dataType items[])
    {
        arr = new dataType[capacity];
        this->size = size;
        this->capacity = capacity;
        for (int i = 0; i < size; i++)
        {
            arr[i] = items[i];
        }
    }

    Stack(int capacity)
    {
        this->size = size;
        this->capacity = capacity;
        arr = new dataType[capacity];
    }

    ~Stack()
    {
        if (this->size > 0)
        {
            clear();
            delete[] arr;
        }
    }

    Stack(const Stack &stack)
    {
        arr = new dataType[stack.capacity];
        this->size = stack.size;
        this->capacity = stack.capacity;
        for (int i = 0; i < stack.size; i++)
        {
            arr[i] = stack.items[i];
        }
    }

    int length() { return this->size; }

    void push(const dataType item)
    {
        if (this->size == this->capacity)
        {
            increaseCapacity();
        }
        arr[this->size++] = item;
    } // O(1)

    dataType pop()
    {
        if (this->size == 0)
        {
            return -1;
        }
        dataType temp = arr[this->size - 1];
        this->size--;
        if (this->size <= this->capacity / 2)
        {
            decreaseCapacity();
        }
        return temp;
    } // O(1)

    dataType topValue()
    {
        if (this->size == 0)
        {
            return -1;
        }
        return arr[this->size - 1];
    } // O(1)

    void clear()
    {
        if (this->size > 0)
        {
            this->size = 0;
        }
    }

    void display()
    {
        cout << "< ";
        for (int i = 0; i < this->size; i++)
        {
            if (i == this->size - 1)
            {
                cout << "| ";
            }
            cout << arr[i] << " ";
        }
        cout << ">\n";
    }
};

template <class dataType>
class Queue
{
    dataType *arr;
    int capacity;
    int size;

    void increaseCapacity()
    {
        dataType *tempArray;
        tempArray = new dataType[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            tempArray[i] = arr[i];
        }
        delete[] arr;
        this->capacity *= 2;
        arr = new dataType[this->size + 1];
        for (int i = 0; i < this->size; i++)
        {
            arr[i] = tempArray[i];
        }
        delete[] tempArray;
    } // O(n)

    void decreaseCapacity()
    {
        dataType *tempArray;
        tempArray = new dataType[this->size + 1];
        for (int i = 0; i < this->size; i++)
        {
            tempArray[i] = arr[i];
        }
        delete[] arr;
        this->capacity /= 2;
        arr = new dataType[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            arr[i] = tempArray[i];
        }
        delete[] tempArray;
    } // O(n)

public:
    Queue(int size, int capacity, dataType items[])
    {
        this->size = size;
        this->capacity = capacity;
        arr = new dataType[capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = items[i];
        }
    }

    Queue(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        arr = new dataType[capacity];
    }

    ~Queue()
    {
        if (this->size > 0)
        {
            clear();
            delete[] arr;
        }
    }

    Queue(const Queue &queue)
    {
        this->size = queue.size;
        this->capacity = capacity;
        arr = new dataType[queue.capacity];
        for (int i = 0; i < queue.size; i++)
        {
            arr[i] = queue.items[i];
        }
    }

    int length() { return this->size; }

    void enqueue(const dataType item)
    {
        if (this->size == this->capacity)
        {
            increaseCapacity();
        }
        arr[this->size++] = item;
    } // O(1)

    dataType leaveQueue()
    {
        if (this->size == 0)
        {
            return -1;
        }
        dataType temp = arr[this->size - 1];
        this->size--;
        if (this->size <= this->capacity / 2)
        {
            decreaseCapacity();
        }
        return temp;
    } // O(1)

    dataType frontValue()
    {
        if (this->size == 0)
        {
            return -1;
        }
        return arr[0];
    } // O(1)

    dataType rearValue()
    {
        if (this->size == 0)
        {
            return -1;
        }
        return arr[this->size - 1];
    } // O(1)

    dataType dequeue()
    {
        if (this->size == 0)
        {
            return -1;
        }
        dataType temp = arr[0];
        for (int i = 0; i < this->size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        this->size--;
        if (this->size <= this->capacity / 2)
        {
            decreaseCapacity();
        }
        return temp;
    } // O(n)

    void clear()
    {
        if (this->size > 0)
        {
            this->size = 0;
        }
    }

    void display()
    {
        cout << "< ";
        for (int i = 0; i < this->size; i++)
        {
            if (i == 0)
            {
                cout << "| ";
            }
            cout << arr[i] << " ";
        }
        cout << ">\n";
    }
};
