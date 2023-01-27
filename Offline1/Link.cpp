#include <iostream>
using namespace std;
template <typename dataType>
class Link
{
public:
    dataType item;
    Link *next;
    Link *prev;
    Link(const dataType item, Link *prev, Link *next)
    {
        this->item = item;
        this->prev = prev;
        this->next = next;
    }
    Link(const Link &link)
    {
        this->item = link.item;
        this->prev = link.prev;
        this->next = link.next;
    }
};
