#include <iostream>
using namespace std;
template <typename dataType>
class Link
{
public:
    dataType item;
    Link *next;

    Link(const dataType item, Link *next)
    {
        this->item = item;
        this->next = next;
    }
    Link(const Link &link)
    {
        this->item = link.item;
        this->next = link.next;
    }
};
