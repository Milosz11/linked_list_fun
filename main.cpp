#include <iostream>

#include "ll.h"

int main() {
    LinkedList ll;

    ll.pushBack(1);
    ll.pushBack(3);
    ll.pushBack(7);
    ll.print();
    ll.clear();
    ll.print();

    LinkedList ll2;

    ll2.pushFront(4);
    ll2.pushFront(7);
    ll2.pushFront(3);
    ll2.print();
    ll2.popBack();
    ll2.popFront();
    ll2.print();
    ll2.clear();
    ll2.print();

    LinkedList ll3(5);
    ll3.print();

    LinkedList ll4(7, 7);
    ll4.print();
    std::cout << "ll4 size: " << ll4.size() << std::endl;

    return 0;
}
