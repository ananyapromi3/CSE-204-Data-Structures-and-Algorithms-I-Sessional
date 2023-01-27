#include <iostream>
#include "List.cpp"
#include "Link.cpp"
using namespace std;
template <class dataType>
class MyList : public List<dataType>
{
    Link<dataType> *head;
    Link<dataType> *tail;
    Link<dataType> *current;

    void addFirst(dataType item)
    {
        head = new Link<dataType>(item, NULL, NULL);
        tail = head;
        current = head;
        this->length++;
    }

    void append(dataType item)
    {
        tail->next = new Link<dataType>(item, tail, NULL);
        tail = tail->next;
    } // O(1)

public:
    MyList(int length, int capacity, dataType items[]) : List<dataType>(length, capacity)
    {
        head = new Link<dataType>(items[0], NULL, NULL);
        tail = head;
        current = head;
        for (int i = 1; i < length; i++)
        {
            append(items[i]);
        }
    }

    MyList(int capacity) : List<dataType>(0, capacity)
    {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    ~MyList() { clear(); }

    MyList(const MyList &myList) : List<dataType>(myList)
    {
        this->head = new Link<dataType>(myList.head->item, NULL, myList.head->next);
        this->tail = this->head;
        this->current = this->head;
        Link<dataType> *temp1, *temp2;
        temp1 = head->next;
        temp2 = myList.head->next;
        while (temp2 != NULL)
        {
            temp1 = new Link<dataType>(temp2->item, temp2->prev, temp2->next);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    void push(const dataType item)
    {
        if (this->length == 0)
        {
            addFirst(item);
        }
        else
        {
            Link<dataType> *temp;
            temp = current;
            current = new Link<dataType>(item, current->prev, current);
            if (temp->prev)
            {
                temp->prev->next = current;
            }
            temp->prev = current;
            if (current->prev == NULL)
            {
                head = current;
            }
            this->length++;
        }
    } // O(1)

    void pushBack(const dataType item)
    {
        if (this->length == 0)
        {
            addFirst(item);
        }
        else
        {
            append(item);
            this->length++;
        }

    } // O(1)

    dataType erase()
    {
        if (this->length == 0)
        {
            return -1;
        }
        Link<dataType> *tempLink;
        tempLink = current;
        dataType temp = current->item;
        current = current->next;
        if (this->length == 1)
        {
            head = NULL;
            tail == NULL;
            current == NULL;
            this->length = 0;
            return -1;
        }
        if (tempLink == head)
        {
            head = head->next;
            head->prev = NULL;
        }
        else if (tempLink == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
            this->currentPosition--;
        }
        else
        {
            current->prev = tempLink->prev;
            tempLink->prev->next = current;
        }
        delete tempLink;
        this->length--;
        return temp;
    } // O(1)

    void setToBegin()
    {
        this->currentPosition = 0;
        current = head;
    } // O(1)

    void setToEnd()
    {
        this->currentPosition = this->length - 1;
        current = tail;
    } // O(1)

    void prev()
    {
        if (current != head)
        {
            current = current->prev;
            this->currentPosition--;
        }
    } // O(1)

    void next()
    {
        if (current != tail)
        {
            current = current->next;
            this->currentPosition++;
        }
    } // O(1)

    void setToPos(int pos)
    {
        if (pos < this->length)
        {
            current = head;
            for (int i = 0; i < pos; i++)
            {
                current = current->next;
            }
            this->currentPosition = pos;
        }
    } // O(n)

    dataType getValue() { return current->item; } // O(1)

    int find(const dataType item)
    {
        Link<dataType> *temp;
        temp = head;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->item == item)
            {
                return count;
            }
            temp = temp->next;
            count++;
        }
        return -1;
    } // O(1)

    void clear()
    {
        Link<dataType> *temp;
        if (this->length == 0)
        {
            return;
        }
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        this->length = 0;
    } // O(n)
};