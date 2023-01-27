#include <iostream>
// #include "MyArrayList.cpp"
#include "MyLinkedList.cpp"
using namespace std;
template <class dataType1, class dataType2>
class LRUCache
{
    MyList<dataType1> *keys;
    MyList<dataType2> *values;
    int capacity;
    int length;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->length = 0;
    }

    dataType2 get(dataType1 key)
    {
        int index = keys->find(key);
        if (index == -1)
        {
            return -1;
        }
        keys->setToPos(index);
        values->setToPos(index);
        dataType2 tempVal = values->getValue();
        keys->erase();
        keys->pushBack(key);
        values->erase();
        values->pushBack(tempVal);
        return tempVal;
    }

    void put(dataType1 key, dataType2 value)
    {
        if (capacity == 0)
        {
            return;
        }
        else if (length == 0)
        {
            dataType1 *temp1;
            temp1 = new dataType1[1];
            temp1[0] = key;
            keys = new MyList<dataType1>(1, capacity, temp1);
            dataType2 *temp2;
            temp2 = new dataType2[1];
            temp2[0] = value;
            values = new MyList<dataType1>(1, capacity, temp2);
            length++;
        }
        else
        {
            if (length == capacity)
            {
                keys->setToBegin();
                keys->erase();
                values->setToBegin();
                values->erase();
                length--;
            }
            keys->pushBack(key);
            values->pushBack(value);
            length++;
        }
    }
};