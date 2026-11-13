#pragma once

#include "SelfOrderedListADT.h"
#include "llist.h"
#include <iostream>

// The Heuristic enum class defines the different self-ordering heuristics that can be applied to the list. The moveToFront heuristic moves accessed elements to the front of the list, the Transpose heuristic swaps accessed elements with their predecessor, and the Count heuristic reorders elements based on their access frequency.
enum class Heuristic {
    moveToFront,
    Transpose,
    Count
};

// The use of a template class allows the user to create a self-ordered list of any data type. The SelfOrderedList class inherits from the SelfOrderedListADT abstract class and implements its pure virtual functions. The class uses a linked list to store the elements and maintains a count of comparisons made during searches.
template <typename E>
class selfOrderedList : public SelfOrderedListADT<E> {
private:

	// The heuristic variable stores the selected self-ordering heuristic for the list. It is set during the construction of the selfOrderedList object and determines how elements are reordered upon access.
    Heuristic heuristic;

    // The Record struct is used to store each element in the list along with its frequency of access. The frequency is incremented each time the element is accessed, which can be used for self-ordering heuristics.
    struct Record {
        
		// The value variable holds the actual data element of type E. It is initialized to a default value using the default constructor.
        E value{};
        int frequency = 0;

		// The default constructor initializes the Record with default values. It is used when creating a new Record without specifying an initial value.
        Record() = default;

		// The parameterized constructor initializes the Record with a specified value. It allows the creation of a Record with an initial data element of type E.
        Record(const E& item) : value(item) {};
    };

    // The list of records is stored in a linked list. The mutable keyword allows the list to be modified even in const member functions, which is necessary for the search function that may reorder the list.
    mutable LList<Record> records;
    // The comparisons variable keeps track of the number of comparisons made during searches. This is useful for analyzing the efficiency of the self-ordering heuristics.
    int comparisons = 0;

public:

    selfOrderedList(Heuristic h) : heuristic(h) {};

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

		// The printList function of the linked list is called to output the records.
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

			// Check if the current record's value matches the searched item
            if (records.getValue().value == it) {
                Record record = records.remove(); // Remove the found record from the list
                record.frequency++;

				// Reinsert the record based on the frequency heuristic
				int j = 0;
				while (j < records.length() && records.getValue().frequency >= record.frequency) {
					records.moveToPos(j);
					j++;
				}
				records.insert(record); // Insert the record back into the list at the correct position
				return true; // Return true indicating the item was found
			}

			// If the item is not found, add it to the list
            if (heuristic == Heuristic::moveToFront) {
                records.moveToStart();
				// Move the accessed element to the front of the list
            } else if (heuristic == Heuristic::Transpose) {
                if (i > 0) {
                    records.moveToPos(i - 1);
                } else {
                    records.moveToStart();
                }
				// Swap the current record with its predecessor
            } else if (heuristic == Heuristic::Count) {
                int newPos = i;
                
				// Move the accessed element to the correct position based on its frequency
                for (int j = 0; j < i; j++) {
                    records.moveToPos(j);

                    if (records.getValue().frequency < record.frequency) {
                        newPos = j;
                        break;
                    }
                }

                records.moveToPos(newPos);
            }

            records.insert(record);
            return true;
            }
        }
        addIt(it); // If the item is not found, add it to the list



        
        if (heuristic == Heuristic::moveToFront) {
        records.moveToPos(records.length() - 1);
        Record record = records.remove();
        records.moveToStart();
        records.insert(record);
        }

        return false; // Return false if the item is not found
    }

};