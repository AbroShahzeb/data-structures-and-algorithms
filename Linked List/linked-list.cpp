#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Function to add a new node to the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Function to insert at beginning
    void insert_at_first(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert at end
    void insert_at_end(int value) {
        Node* newNode = new Node(value);
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    void add_after_index(int index, int val) {
        if (index < 1 || index > get_length()) {
            return;
        }

        Node* current = head;
        Node* new_node = new Node(val);

        int i = 0;
        while (i < index - 1) {
            current = current->next;
            i++;
        }

        new_node->next = current->next;
        current->next = new_node;

    }


    // Function to delete first node
    void delete_first() {
        Node* first = head;
        head = first->next;

        delete first;
    }

    // Function to delete last node
    void delete_last() {
        Node* current = head;
        
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    // Function to print middle element of list
    void print_middle_element() {
        int length = get_length();

        Node* current = head;
        int middle = length / 2;

        int i = 0;

        while (i < middle) {
            i++;
            current = current->next;
        }

        cout << "Middle element: " << current->data << endl;
    }

    // Iterative function to reverse list
    void reverse() {
        Node* current = head;
        Node* previous = nullptr;
        Node* next;

        while (current != nullptr) {
            next = current->next;
            current->next = previous;

            previous = current;
            current = next;
        }

        head = previous;

    }

   

    // Function for linear search
    int search(int key) {
        Node* current = head;

        while (current != nullptr && current->data != key) {
            if (current->data == key) return 1;

            current = current->next;
        }

    }

    // Function to delete a node with given value
    void delete_with_value(int val) {
        Node* current = head;
        int found = 0;

        while (current != nullptr && current->data != val) {
            if (current->next->data == val) {
                found = 1;
                break;
            }
            current = current->next;
        }

        if (found) {

        Node* toDelete = current->next;
        current->next = current->next->next;

        delete toDelete;
        }

    }

    // Function to print the elements of the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Function to get length of Linked List
    int get_length() {
        Node* current = head;
        int length = 0;

        while (current != nullptr) {
            length++;
            current = current->next;
        }

        return length;
    } 
};

int main() {
    LinkedList myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    myList.append(5);


    cout << "Linked List: ";
    myList.display();

    myList.insert_at_end(6);
    myList.insert_at_end(7);
    myList.insert_at_end(8);
    myList.insert_at_first(0);
    myList.insert_at_first(-1);
    myList.insert_at_first(-2);
    myList.insert_at_first(-3);
    // myList.print_middle_element();


    // cout << "Search Result: " << myList.search(9) << endl;

    // myList.delete_with_value(-1);

    myList.add_after_index(1, 20);


    cout << "Linked List: ";
    myList.display();

    return 0;
}
