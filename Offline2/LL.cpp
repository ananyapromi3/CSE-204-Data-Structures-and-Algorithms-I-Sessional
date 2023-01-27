#include <iostream>
#include "Link.cpp"
using namespace std;

template <class dataType>
class Stack
{
    Link<dataType> *head;
    int size;

    void addFirst(dataType item)
    {
        head = new Link<dataType>(item, NULL);
        this->size++;
    }

public:
    Stack(int size, int capacity, dataType items[])
    {
        head = NULL;
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            head = new Link<dataType>(items[i], head);
        }
    }

    Stack(int capacity)
    {
        this->size = 0;
        head = NULL;
    }

    ~Stack() { clear(); }

    Stack(const Stack &stack)
    {
        this->size = stack.size;
        this->head = new Link<dataType>(stack.head->item, stack.head->next);
        Link<dataType> *temp1, *temp2;
        temp1 = head->next;
        temp2 = stack.head->next;
        while (temp2 != NULL)
        {
            temp1 = new Link<dataType>(temp2->item, temp2->next);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    int length() { return this->size; }

    void push(const dataType item)
    {
        if (this->size == 0)
        {
            addFirst(item);
        }
        else
        {
            head = new Link<dataType>(item, head);
            this->size++;
        }

    } // O(1)

    dataType pop()
    {
        if (this->size == 0)
        {
            return -1;
        }
        Link<dataType> *tempLink;
        tempLink = head;
        dataType temp = head->item;
        head = head->next;
        delete tempLink;
        this->size--;
        return temp;
    } // O(1)

    dataType topValue()
    {
        if (this->size == 0)
        {
            return -1;
        }
        return head->item;
    } // O(1)

    void clear()
    {
        Link<dataType> *temp;
        if (this->size == 0)
        {
            return;
        }
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        this->size = 0;
    } // O(n)

    void display()
    {
        Link<dataType> *temp;
        temp = head;
        dataType arr[this->size];
        int i = 0;
        while (temp != NULL)
        {
            arr[i++] = temp->item;
            temp = temp->next;
        }
        cout << "< ";
        for (i = this->size - 1; i >= 0; i--)
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

template <class dataType>
class Queue
{
    Link<dataType> *head;
    Link<dataType> *tail;
    Link<dataType> *current;
    int size;

    void addFirst(dataType item)
    {
        head = new Link<dataType>(item, NULL);
        tail = head;
        current = head;
        this->size++;
    }

    void append(dataType item)
    {
        tail->next = new Link<dataType>(item, NULL);
        tail = tail->next;
    } // O(1)

public:
    Queue(int size, int capacity, dataType items[])
    {
        this->size = size;
        head = new Link<dataType>(items[0], NULL);
        tail = head;
        current = head;
        for (int i = 1; i < size; i++)
        {
            append(items[i]);
        }
    }

    Queue(int capacity)
    {
        this->size = 0;
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    ~Queue() { clear(); }

    Queue(const Queue &queue)
    {
        this->size = queue.size;
        this->head = new Link<dataType>(queue.head->item, queue.head->next);
        this->tail = this->head;
        this->current = this->head;
        Link<dataType> *temp1, *temp2;
        temp1 = head->next;
        temp2 = queue.head->next;
        while (temp2 != NULL)
        {
            temp1 = new Link<dataType>(temp2->item, temp2->next);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    int length() { return this->size; }

    void enqueue(const dataType item)
    {
        if (this->size == 0)
        {
            addFirst(item);
        }
        else
        {
            append(item);
            this->size++;
        }

    } // O(1)

    dataType dequeue()
    {
        if (this->size == 0)
        {
            return -1;
        }
        Link<dataType> *tempLink;
        tempLink = head;
        dataType temp = head->item;
        head = head->next;
        delete tempLink;
        this->size--;
        return temp;
    } // O(1)

    dataType leaveQueue()
    {
        if (this->size == 0)
        {
            return -1;
        }
        Link<dataType> *tempLink;
        Link<dataType> *tempLink2;
        tempLink = head;
        dataType temp = head->item;
        while (tempLink != NULL)
        {
            if (tempLink->next == tail)
            {
                break;
            }
            tempLink = tempLink->next;
        }
        tempLink2 = tail;
        tail = tempLink;
        tail->next = NULL;
        delete tempLink2;
        this->size--;
        return temp;
    } // O(n)

    dataType frontValue() { return head->item; } // O(1)

    dataType rearValue() { return tail->item; } // O(1)

    void clear()
    {
        Link<dataType> *temp;
        if (this->size == 0)
        {
            return;
        }
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        this->size = 0;
    } // O(n)

    void display()
    {
        Link<dataType> *temp;
        temp = head;
        cout << "< ";
        int i = 0;
        while (temp != NULL)
        {
            if (i == 0)
            {
                cout << "| ";
            }
            cout << temp->item << " ";
            temp = temp->next;
            i++;
        }
        cout << ">\n";
    }
};