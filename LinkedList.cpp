#include <iostream>
using namespace std;

struct Node {
    int data;      
    Node* next;   
};

// Function to insert a node at the beginning
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node{newData, head};
    head = newNode;
    cout << "Inserted " << newData << " at beginning." << endl;
}

// Function to insert a node at the end
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node{newData, nullptr};
    if (head == nullptr) {
        head = newNode;
        cout << "Inserted " << newData << " at end." << endl;
        return;
    }
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
    cout << "Inserted " << newData << " at end." << endl;
}

// Function to insert a node at a specific position
void insertAtPosition(Node*& head, int newData, int position) {
    if (position == 0) {
        insertAtBeginning(head, newData);
        return;
    }
    Node* newNode = new Node{newData, nullptr};
    Node* current = head;
    for (int i = 0; current != nullptr && i < position - 1; i++) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Position is out of bounds." << endl;
        delete newNode;
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
    cout << "Inserted " << newData << " at position " << position << "." << endl;
}

// Function to delete a node at the beginning
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    Node* temp = head;
    cout << "Deleted " << head->data << " from beginning." << endl;
    head = head->next;
    delete temp;
}

// Function to delete a node at the end
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted " << head->data << " from end." << endl;
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    cout << "Deleted " << current->next->data << " from end." << endl;
    delete current->next;
    current->next = nullptr;
}

// Function to delete a node at a specific position
void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }
    Node* current = head;
    for (int i = 0; current != nullptr && i < position - 1; i++) {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) {
        cout << "Position is out of bounds." << endl;
        return;
    }
    Node* temp = current->next;
    cout << "Deleted " << temp->data << " from position " << position << "." << endl;
    current->next = current->next->next;
    delete temp;
}

// Function to search for a value in the linked list
bool search(Node* head, int key) {
    Node* current = head;
    int position = 0;
    while (current != nullptr) {
        if (current->data == key) {
            cout << "Element " << key << " found at position " << position << "." << endl;
            return true;
        }
        current = current->next;
        position++;
    }
    cout << "Element " << key << " not found in the list." << endl;
    return false;
}

// Function to print the linked list
void printList(Node* node) {
    if (node == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Linked List: ";
    while (node != nullptr) {
        cout << node->data << " -> "; 
        node = node->next;   
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    cout << "\n=== INSERTION OPERATIONS ===" << endl;
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtBeginning(head, 10);
    insertAtPosition(head, 25, 3);
    printList(head);

    cout << "\n=== SEARCH OPERATIONS ===" << endl;
    search(head, 25);
    search(head, 100);
    search(head, 10);

    cout << "\n=== DELETION OPERATIONS ===" << endl;
    deleteAtBeginning(head);
    printList(head);

    deleteAtEnd(head);
    printList(head);

    deleteAtPosition(head, 1);
    printList(head);

    cout << "\n=== FINAL LIST ===" << endl;
    printList(head);

    while (head != nullptr) {
        deleteAtBeginning(head);
    }

    return 0; 
}