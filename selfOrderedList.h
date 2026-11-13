#pragma once

#include "SelfOrderedListADT.h"
#include "llist.h"
#include <iostream>

// The use of a template class allows the user to create a self-ordered list of any data type. The SelfOrderedList class inherits from the SelfOrderedListADT abstract class and implements its pure virtual functions. The class uses a linked list to store the elements and maintains a count of comparisons made during searches.
template <typename E>
class selfOrderedList : public SelfOrderedListADT<E> {
private:

    // The Record struct is used to store each element in the list along with its frequency of access. The frequency is incremented each time the element is accessed, which can be used for self-ordering heuristics.
    struct Record {
        
        E value{};
        int frequency = 0;

        Record() = default;

        Record(const E& item) : value(item) {};
    };

    // The list of records is stored in a linked list. The mutable keyword allows the list to be modified even in const member functions, which is necessary for the search function that may reorder the list.
    mutable LList<Record> records;
    // The comparisons variable keeps track of the number of comparisons made during searches. This is useful for analyzing the efficiency of the self-ordering heuristics.
    int comparisons = 0;

public:

    // The addIt function adds a new element to the list. It creates a new Record for the element and appends it to the records list. This function is called when an element is not found during a search, allowing the list to grow dynamically.
    void addIt(const E& it) override {
        records.append(Record(it));
    }

    // The size function returns the number of elements in the list. It simply calls the length function of the underlying linked list to get the current size.
    int size() const override {
        return records.length();
    }

    // The getCompares function returns the number of comparisons made during searches. This allows users to analyze the performance of the self-ordering heuristics implemented in the search function.
    int getCompares() const override {
        return comparisons;
    }

    // The printList function prints the entire list of records. It calls the printList function of the underlying linked list, which iterates through the records and outputs their values and frequencies.
    void printlist() const override {
        printlist(size());
    }

    // The printList function prints the first n records in the list. If n is greater than the size of the list, it prints all records.
    void printlist(int n) const override {
        int limit =(n < size()) ? n : size();

        for (int i = 0; i < limit; i++) {
            records.moveToPos(i);

            const Record& record = records.getValue();

            std::cout << record.value << "-" << record.frequency << " ";
        }

        std::cout << std::endl;

    }
    
    // The search function looks for an element in the list. If the element is found, it increments its frequency and reorders the list based on the self-ordering heuristic (in this case, frequency). If the element is not found, it adds the new element to the list. The function also increments the comparisons count for each comparison made during the search.
    bool search(const E& it) override {
        for (int i = 0; i < records.length(); i++) {
            records.moveToPos(i);
            comparisons++; // Increment the comparison count for each comparison made

            if (records.getValue().value == it) {
                Record record = records.remove(); // Remove the found record from the list
                record.frequency++; // Increment the frequency of access for the found record
                records.insert(record); // Reinsert the record to maintain the order based on frequency
                return true; // Return true if the item is found
            }
        }
        addIt(it); // If the item is not found, add it to the list
        return false; // Return false if the item is not found
    }

};