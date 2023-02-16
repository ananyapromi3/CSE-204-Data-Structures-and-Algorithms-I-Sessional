#include <iostream>
#include "List.cpp"
using namespace std;
template <class dataType>
class MyList : public List<dataType>
{
    dataType *arr;

    void increaseCapacity()
    {
        dataType *tempArray;
        tempArray = new dataType[this->length];
        for (int i = 0; i < this->length; i++)
        {
            tempArray[i] = arr[i];
        }
        delete[] arr;
        this->capacity *= 2;
        arr = new dataType[this->capacity];
        for (int i = 0; i < this->length; i++)
        {
            arr[i] = tempArray[i];
        }
        delete[] tempArray;
    } // O(n)

    void decreaseCapacity()
    {
        dataType *tempArray;
        tempArray = new dataType[this->length];
        for (int i = 0; i < this->length; i++)
        {
            tempArray[i] = arr[i];
        }
        delete[] arr;
        this->capacity /= 2;
        arr = new dataType[this->capacity];
        for (int i = 0; i < this->length; i++)
        {
            arr[i] = tempArray[i];
        }
        delete[] tempArray;
    } // O(n)

public:
    MyList(int length, int capacity, dataType items[]) : List<dataType>(length, capacity)
    {
        arr = new dataType[capacity];
        for (int i = 0; i < length; i++)
        {
            arr[i] = items[i];
        }
    }

    MyList(int capacity) : List<dataType>(0, capacity) { arr = new dataType[capacity]; }

    ~MyList()
    {
        if (this->length > 0)
        {
            clear();
            delete[] arr;
        }
    }

    MyList(const MyList &myList) : List<dataType>(myList)
    {
        arr = new dataType[myList.capacity];
        for (int i = 0; i < myList.length; i++)
        {
            arr[i] = myList.items[i];
        }
    }

    void push(const dataType item)
    {
        if (this->length == this->capacity)
        {
            increaseCapacity();
        }
        for (int i = this->length; i > this->currentPosition; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[this->currentPosition] = item;
        this->length++;
    } // O(n)

    void pushBack(const dataType item)
    {
        if (this->length == this->capacity)
        {
            increaseCapacity();
        }
        arr[this->length++] = item;
    } // O(1)

    dataType erase()
    {
        if (this->length == 0)
        {
            return -1;
        }
        dataType temp = arr[this->currentPosition];
        for (int i = this->currentPosition; i < this->length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        this->length--;
        if (this->length <= this->capacity / 2)
        {
            decreaseCapacity();
        }
        if (this->currentPosition >= this->length && this->currentPosition > 0)
        {
            this->currentPosition--;
        }
        return temp;
    } // O(n)

    void setToBegin() { this->currentPosition = 0; } // O(1)

    void setToEnd() { this->currentPosition = this->length - 1; } // O(1)

    void prev()
    {
        if (this->currentPosition > 0)
        {
            this->currentPosition--;
        }
    } // O(1)

    void next()
    {
        if (this->currentPosition < this->length - 1)
        {
            this->currentPosition++;
        }
    } // O(1)

    void setToPos(int pos) { this->currentPosition = pos; } // O(1)

    dataType getValue() { return arr[this->currentPosition]; } // O(1)

    int find(const dataType item)
    {
        for (int i = 0; i < this->length; i++)
        {
            if (arr[i] == item)
            {
                return i;
            }
        }
        return -1;
    } // O(n)
    
    void clear()
    {
        if (this->length > 0)
        {
            this->length = 0;
            this->currentPosition = 0;
        }
    }
};