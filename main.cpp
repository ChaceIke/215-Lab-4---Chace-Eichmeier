#include "llist.h"
#include "selfOrderedList.h"
#include <fstream>
#include <string>

// Function to read records from a file and populate the self-ordered list
int main() {

	// Create a self-ordered list with the moveToFront heuristic
    selfOrderedList<char> list1(Heuristic::moveToFront);
	// Create a self-ordered list with the Transpose heuristic
    selfOrderedList<char> list2(Heuristic::Transpose);
	// Create a self-ordered list with the Count heuristic
    selfOrderedList<char> list3(Heuristic::Count);

    for (char c = 'A'; c <= 'H'; c++) {
        list1.addIt(c);
        list2.addIt(c);
        list3.addIt(c);
    }

	// Establish which searches to perform.
    const char searches[] = {
        'F', 'D', 'F', 'G', 'E', 'G', 'F',
        'A', 'D', 'F', 'G', 'E', 'H', 'I'
    };

    for (char c : searches) {
        list1.search(c);
        list2.search(c);
        list3.search(c);
    }

	// Print the results for each heuristic
    std::cout << "Move to Front Heuristic:" << std::endl;
    std::cout << "Size of the list: " << list1.size() << std::endl;
    std::cout << "Number of comparisons made: " << list1.getCompares() << std::endl;

    std::cout << "Transpose Heuristic:" << std::endl;
    std::cout << "Size of the list: " << list2.size() << std::endl;
    std::cout << "Number of comparisons made: " << list2.getCompares() << std::endl;

    std::cout << "Count Heuristic:" << std::endl;
    std::cout << "Size of the list: " << list3.size() << std::endl;
    std::cout << "Number of comparisons made: " << list3.getCompares() << std::endl;

    list1.printlist();
    list2.printlist();
    list3.printlist();

    // String tests using test.txt
    selfOrderedList<std::string> stringList1(Heuristic::moveToFront);
    selfOrderedList<std::string> stringList2(Heuristic::Transpose);
    selfOrderedList<std::string> stringList3(Heuristic::Count);

    std::ifstream inputFile("test.txt");

    if (!inputFile.is_open()) {
        std::cout << "Error opening test.txt" << std::endl;
        return 1;
    }

    std::string word;

    while (inputFile >> word) {
        stringList1.search(word);
        stringList2.search(word);
        stringList3.search(word);
    }

    std::cout << "\nString Test - Move to Front:" << std::endl;
    std::cout << "Total words: " << stringList1.size() << std::endl;
    std::cout << "Comparisons: " << stringList1.getCompares() << std::endl;
    stringList1.printlist(10);

    std::cout << "\nString Test - Transpose: " << std::endl;
    std::cout << "Total words: " << stringList2.size() << std::endl;
    std::cout << "Comparisons: " << stringList2.getCompares() << std::endl;
    stringList2.printlist(10);

    std::cout << "\nString Test - Count:" << std::endl;
    std::cout << "Total words: " << stringList3.size() << std::endl;
    std::cout << "Comparisons: " << stringList3.getCompares() << std::endl;
    stringList3.printlist(10);

    return 0;
}