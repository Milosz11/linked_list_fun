#pragma once

#include <stdlib.h>
#include <iostream>

class LinkedList {
private:
    struct Node {
        int _value;
        Node *_next;
        Node *_prev;

        Node() : _value(0), _next(nullptr), _prev(nullptr) {}
        Node(int value) : _value(value), _next(nullptr), _prev(nullptr) {}
    };

public:
    /**
     * Initialize an empty linked list
    */
    LinkedList();

    /**
     * Initialize a linked list with NUM_ELEMS 0's
    */
    LinkedList(size_t num_elems);

    /**
     * Initialize a linked list with NUM_ELEMS DEFAULT_VALUE's
    */
    LinkedList(size_t num_elems, int default_value);

    /**
     * Return whether the linked list is empty
    */
    bool isEmpty() const;

    /**
     * Return the number of elements in the list
    */
    size_t size() const;

    /**
    * Insert an element at the end of the list
    */
    void pushBack(int value);

    /**
     * Insert an element at the beginning of the list
    */
    void pushFront(int value);

    /**
     * Remove the element at the end of the list
    */
    void popBack();

    /**
     * Remove the element at the beginning of the list
    */
    void popFront();

    /**
     * Remove all elements of the list
    */
    void clear();

    /**
     * Prints the list to std::cout, nicely formatted
    */
    void print();

private:
    Node *_head;
    Node *_tail;
    size_t _size;

};
