#include "llist.h"

int main() {

    LList<char> list;

    for (char c = 'A'; c <= 'H'; c++) {
        list.append(c);
    }

    cout << "List Size: " << list.length() << endl;

    list.moveToPos(2);
    cout << "Current Element at Position 2: " << list.getValue() << endl;
}