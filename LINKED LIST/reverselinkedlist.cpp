#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor with an integer parameter
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

// Function to insert nodes into the linked list
void insertnode(Node*& head) {
    int n, data;
    Node* temp = head;
    
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 2; i <= n; i++) {
        cout << "Enter the data for node " << i << ": ";
        cin >> data;
        Node* newnode = new Node(data);
        temp->next = newnode;
        temp = newnode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* reverselinkedlist(Node*& head){

    if( head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while( curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
return prev;
}

int main() {
    // Creating the head node
    Node* head = new Node(20);
    
    // Inserting additional nodes
    insertnode(head);
    
    // Printing the linked list
    cout << "Linked list: ";
    printList(head);

   Node* temp = reverselinkedlist(head);

    cout<<"Reverse linked list: ";
    printList(temp);

    return 0;
}
