#include <iostream>
using namespace std;

struct Node {
    int data;     
    Node* next;   
};

int main() {
    Node* first = new Node{10, nullptr};
    Node* second = new Node{20, nullptr};

    first->next = second;

    Node* current = first;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    printf("\n"); 

    return 0;
}