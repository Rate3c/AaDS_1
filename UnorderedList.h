#pragma once

#include <iostream>
#include <stdexcept>

class UnorderedList {

private:

    class Node {
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int data, Node* prev = NULL, Node* next = NULL) : data(data), prev(prev), next(next) {};
    };

    Node* head; // pointer to the first newNode of list
    Node* tail; // pointer to the last newNode of List
    int size; // size of list

    // get pointer to the newNode of list by index
    Node* getNode(int index) {
        if (index < get_size() && index >= 0) {
            Node* newNode = head;
            newNode = head;
            for (int i = 0; i < (int)index; i++) {
                newNode = newNode->next;
            }
            return newNode;
            newNode = NULL;
        }
    }

public:

    UnorderedList(int data);
    UnorderedList();
    ~UnorderedList();

    //methods
    void push_back(int data);
    void push_front(int data);
    void pop_back();
    void pop_front();
    void insert(int index, int data);
    int at(int index);
    void remove(int index);
    int get_size();
    void clear();
    void set(int index, int data);
    bool isEmpty();

    friend std::ostream& operator<< (std::ostream& out, const UnorderedList& list);
};

// Constructors
UnorderedList::UnorderedList(int data) {
    Node* newNode = new Node(data); // Create temporary node
    head = tail = newNode;
    size = 1;
}
UnorderedList::UnorderedList() {
    head = tail = NULL;
    size = 0;
}
// Destructor
UnorderedList::~UnorderedList() {
    clear();
}

//1. add element to the end
void UnorderedList::push_back(int data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

// 2. add element to the front
void UnorderedList::push_front(int data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;

}

//3. delete last element
void UnorderedList::pop_back() {
    if (!isEmpty()) {
        if (get_size() == 1) {
            delete head;
            head = tail = NULL;
            size--;
        }
        if (get_size() > 1) {
            Node* newNode = tail->prev;
            delete tail;
            tail = newNode;
            tail->next = NULL;
            size--;
        }
    }

    else {
        throw std::out_of_range("List is empty");
    }
}

// 4. delete front element
void UnorderedList::pop_front() {
    if (!isEmpty()) {
        if (get_size() == 1) {
            delete head;
            head = tail = NULL;
            size--;
        }

        else if (get_size() > 1) {
            Node* newNode = head->next;
            delete head;
            head = newNode;
            head->prev = NULL;
            size--;
        }
    }
    else {
        throw std::out_of_range("List is empty");
    }
}

//5. insert element
void UnorderedList::insert(int index, int data) {
    if (index < get_size() && index >= 0) {
        if (index == 0) push_front(data);
        else if (index == get_size()) push_back(data);
        else {
            Node* previous = head;
            int i = 0;
            while (i < index - 1) {
                previous = previous->next;
                i++;
            }

            Node* newNode = new Node(data, previous, previous->next);
            previous->next = newNode;
            size++;
        }
    }
    else {
        throw std::invalid_argument("Index is out of range");
    }
}

// 6. get data of element by index
int UnorderedList::at(int index) {
    if (index < get_size() && index >= 0) {
        return getNode(index)->data;
    }

    else {
        throw std::invalid_argument("Index is out of range");
    }
}

//7. remove element by index
void UnorderedList::remove(int index) {
    if (index < get_size() && index >= 0) {
        Node* newNode = getNode(index);
        if (get_size() == 1) {
            delete newNode;
            head = tail = NULL;
        }
        else {
            if (index == get_size() - 1) {
                newNode->prev->next = NULL;
                tail = getNode(index);
            }
            else if (index == 0) {
                newNode->next->prev = NULL;
                head = newNode;
            }
            else {

                newNode->next->prev = newNode->prev;
                newNode->prev->next = newNode->next;
            }
            delete newNode;
        }
        size--;
    }
    else {
        throw std::invalid_argument("Index is out of range");
    }
}

//8. get list size
int UnorderedList::get_size() {
    if (size >= 0)
        return size;
    else throw std::logic_error("List is empty");
}

//9. clear list
void UnorderedList::clear() {
    while (head != NULL) {
        Node* newNode = head->next;
        delete head;
        head = newNode;
    }
    head = tail = NULL;
    size = 0;
}

//10. Replacing an element by index
void UnorderedList::set(int index, int data) {
    if (index < get_size() && index >= 0) {
        getNode(index)->data = data;
    }
    else {
        throw std::invalid_argument("Index is out of range");
    }
}

//11. is list empty
bool UnorderedList::isEmpty() {
    return get_size() == 0;
}

//12. Overload the output operator
std::ostream& operator<< (std::ostream& out, const UnorderedList& list) {

    UnorderedList::Node* print = list.head;
    while (print != NULL) {
        out << print->data << " ";
        print = print->next;
    }
    return out;

}

