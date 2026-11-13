#pragma once

#include "SelfOrderedListADT.h"
#include "llist.h"
#include <iostream>

// The use of a template class allows the user to create a self-ordered list of any data type. The SelfOrderedList class inherits from the SelfOrderedListADT abstract class and implements its pure virtual functions. The class uses a linked list to store the elements and maintains a count of comparisons made during searches.
template <typename E>
class SelfOrderedList : public SelfOrderedListADT<E> {
private:

    // The Record struct is used to store each element in the list along with its frequency of access. The frequency is incremented each time the element is accessed, which can be used for self-ordering heuristics.
    struct Record {
        
        E value{};
        int frequency = 0;

        Record() = default;

        Record(const E& item) : value(item) {};
    };

    // The list of records is stored in a linked list. The mutable keyword allows the list to be modified even in const member functions, which is necessary for the search function that may reorder the list.
    mutable Llist<Record> records;
    // The comparisons variable keeps track of the number of comparisons made during searches. This is useful for analyzing the efficiency of the self-ordering heuristics.
    int comparisons = 0;

public:

};