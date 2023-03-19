#include "ll.h"

LinkedList::LinkedList()
        : _head(nullptr), _tail(nullptr), _size(0) { }

LinkedList::LinkedList(size_t num_elems)
        : _head(nullptr), _tail(nullptr), _size(0) {
    for (size_t i = 0; i < num_elems; i++) {
        pushBack(0);
    }
}

LinkedList::LinkedList(size_t num_elems, int default_value)
        : _head(nullptr), _tail(nullptr), _size(0) {
    for (size_t i = 0; i < num_elems; i++) {
        pushBack(default_value);
    }
}

bool LinkedList::isEmpty() const {
    return _size == 0;
}

size_t LinkedList::size() const {
    return _size;
}

void LinkedList::pushBack(int value) {
    _size++;

    Node *new_node = new Node(value);

    if (_head == nullptr && _tail == nullptr) {
        _head = new_node;
        _tail = new_node;
    } else if (_head == _tail) {
        _head->_next = new_node;
        new_node->_prev = _head;
        _tail = new_node;
    } else {
        _tail->_next = new_node;
        new_node->_prev = _tail;
        _tail = new_node;
    }
}

void LinkedList::pushFront(int value) {
    _size++;

    Node *new_node = new Node(value);

    if (_head == nullptr && _tail == nullptr) {
        _head = new_node;
        _tail = new_node;
    } else if (_head == _tail) {
        _head->_prev = new_node;
        new_node->_next = _head;
        _head = new_node;
    } else {
        _head->_prev = new_node;
        new_node->_next = _head;
        _head = new_node;
    }
}

void LinkedList::popBack() {
    if (_head == nullptr && _tail == nullptr) {
        return;
    }

    _size--;
    
    if (_head == _tail) {
        delete _head;
        _head = nullptr;
        _tail = nullptr;
    } else {
        _tail->_prev->_next = nullptr;
        Node *temp = _tail->_prev;
        delete _tail;
        _tail = temp;
    }
}

void LinkedList::popFront() {
    if (_head == nullptr && _tail == nullptr) {
        return;
    }

    _size--;

    if (_head == _tail) {
        delete _head;
        _head = nullptr;
        _tail = nullptr;
    } else {
        _head->_next->_prev = nullptr;
        Node *temp = _head->_next;
        delete _head;
        _head = temp;
    }
}

void LinkedList::clear() {
    while (_head != nullptr) {
        popBack();
    }
}

void LinkedList::print() {
    switch (_size) {
        case 0:
            std::cout << "[]\n";
            break;
        
        case 1:
            std::cout << "[" << _head->_value << "]\n";
            break;

        default:
            std::cout << "[";
            
            Node *cur = _head;
            for ( ; cur->_next != nullptr; cur = cur->_next) {
                std::cout << cur->_value << ", ";
            }

            std::cout << cur->_value << "]\n";

            break;
    }
}
