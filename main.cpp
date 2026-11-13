#include "llist.h"
#include "selfOrderedList.h"

int main() {

    // selfOrderedList<char> list(Heuristic::moveToFront);
    // selfOrderedList<char> list(Heuristic::Transpose);
    selfOrderedList<char> list(Heuristic::Count);

    for (char c = 'A'; c <= 'H'; c++) {
        list.addIt(c);
    }

    const char searches[] = {
        'F', 'D', 'F', 'G', 'E', 'G', 'F',
        'A', 'D', 'F', 'G', 'E', 'H', 'I'
    };

    for (char c : searches) {
        list.search(c);
    }

    std::cout << "Size of the list: " << list.size() << std::endl;
    std::cout << "Number of comparisons made: " << list.getCompares() << std::endl;

    list.printlist();

    return 0;
}