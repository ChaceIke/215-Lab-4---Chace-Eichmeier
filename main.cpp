#include "llist.h"
#include "selfOrderedList.h"

int main() {

    selfOrderedList<char> list1(Heuristic::moveToFront);
    selfOrderedList<char> list2(Heuristic::Transpose);
    selfOrderedList<char> list3(Heuristic::Count);

    for (char c = 'A'; c <= 'H'; c++) {
        list1.addIt(c);
        list2.addIt(c);
        list3.addIt(c);
    }

    const char searches[] = {
        'F', 'D', 'F', 'G', 'E', 'G', 'F',
        'A', 'D', 'F', 'G', 'E', 'H', 'I'
    };

    for (char c : searches) {
        list1.search(c);
        list2.search(c);
        list3.search(c);
    }

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

    return 0;
}