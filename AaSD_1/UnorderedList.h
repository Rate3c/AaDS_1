#pragma once

#include <iostream>
#include <stdexcept>

class UnorderedList {

private:

    class Node {
    public:
        int data;
        Node* next;
        Node(int data, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
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
    bool contains(UnorderedList& list);

    friend std::ostream& operator<< (std::ostream& out, const UnorderedList& list);
};

// Constructors
UnorderedList::UnorderedList(int data) {
    Node* newNode = new Node(data); // Create temporary node
    head = tail = newNode;
    size = 1;
}
UnorderedList::UnorderedList() {
    head = tail = nullptr;
    size = 0;
}
// Destructor
UnorderedList::~UnorderedList() {
    clear();
}

//1. add element to the end
void UnorderedList::push_back(int data) {
  
    if (isEmpty()) {
        head = tail = new Node(data);
    }
    else {

        Node* current = this->head;

        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node(data);
    }

    size++;
}

// 2. add element to the front
void UnorderedList::push_front(int data) {

    if (isEmpty()) {
        head = tail = new Node(data, head);
    }
    else {
        head =  new Node(data, head);
    }
    size++;

}

//3. delete last element
void UnorderedList::pop_back() {
    if (!isEmpty()) {
        remove(size - 1);
    }
    else {
        throw std::out_of_range("List is empty");
    }
}

// 4. delete front element
void UnorderedList::pop_front() {
    if (!isEmpty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    else {
        throw std::out_of_range("List is empty");
    }
}

//5. insert element
void UnorderedList::insert(int index, int data) {
    if (index < get_size() && index >= 0) {
        if (index == 0)
        {
            push_front(data);
        }
        else {
            Node* prev = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                prev = prev->next;
            }
            
            Node* newNode = new Node(data, prev->next);
            prev->next = newNode;
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
        if (index == 0)
        {
            pop_front();
        }
        else
        {
            Node* prev = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                prev = prev->next;
            }

            Node* toDelete = prev->next;
            prev->next = toDelete->next;
            delete toDelete;
            size--;
        }
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
    while (print != nullptr) {
        out << print->data << " ";
        print = print->next;
    }
    return out;

}

//17. Checking for the contents of another list in the list
bool UnorderedList::contains(UnorderedList& sublist)
{
    if (sublist.isEmpty())
        return true;

    Node* curNode = head;
    int sizeDelta = this->get_size() - sublist.get_size();
    int counter = 0;

    while (curNode != nullptr)
    {
        if (counter > sizeDelta)
            return false;

        if (curNode->data==sublist.head->data)
        {
            Node* localNode = curNode->next;
            Node* sublistNode = sublist.head->next;
            bool foundSublist = true;

            while (sublistNode != nullptr)
            {
                if (!sublistNode->data==localNode->data)
                {
                    foundSublist = false;
                    break;
                }
                sublistNode = sublistNode->next;
                localNode = localNode->next;
            }

            if (foundSublist)
                return true;
        }
        curNode = curNode->next;
        counter++;
    }

    return false;
}