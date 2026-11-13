#include "llist.h"
#include "selfOrderedList.h"

int main() {

    selfOrderedList<char> list;

    for (char c = 'A'; c <= 'H'; c++) {
        list.addIt(c);
    }

    list.search('C');
    list.search('E');
    list.search('G');

    std::cout << "Size of the list: " << list.size() << std::endl;
    std::cout << "Number of comparisons made: " << list.getCompares() << std::endl;

    list.printlist();

    return 0;
}