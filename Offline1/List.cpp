#include <iostream>
using namespace std;
template <class dataType>
class List
{
public:
    int capacity;
    int length;
    int currentPosition;

    List(int length, int capacity)
    {
        this->length = length;
        this->capacity = capacity;
        currentPosition = 0;
    }

    List(const List &list)
    {
        this->length = list.length;
        this->capacity = list.capacity;
        currentPosition = list.currentPosition;
    }

    int size() { return this->length; } // Returns the number of elements

    virtual void push(const dataType item) = 0; // Push an element at current position

    virtual void pushBack(const dataType item) = 0; // Push an element at the end of the list

    virtual dataType erase() = 0; // Erase and return the current element

    virtual void setToBegin() = 0; // Make beginning of the list as current position

    virtual void setToEnd() = 0; // Make end of the list as current position

    virtual void prev() = 0; // Move the current position to one step left. Ignore if already at the beginning

    virtual void next() = 0; // Move the current position to one step right. Ignore if already at the end

    virtual int currPos() { return this->currentPosition; } // Return the position of current element

    virtual void setToPos(int pos) = 0; // Set current position

    virtual dataType getValue() = 0; // Return current element

    virtual int find(const dataType item) = 0; // Return the position of item if it exists, otherwise return -1

    virtual void clear() = 0; // Clear the list
};