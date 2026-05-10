#include<iostream>
using namespace std;

class Node{
 
    public:
    int data;
    Node*next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

};


bool iscircular(Node*& head){
    if (head == NULL) return false;

    Node* temp = head -> next;

    while (temp != NULL && temp != head) {
        temp = temp -> next;
    }

    return temp == head;
}

void print(Node*& head){
    Node* temp = head;
    
    if (iscircular(head)) {
        // Circular list printing
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        // Simple list printing
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

void circularLinkedList(Node*& head , int n){

    Node* temp = head;
    int data;

    for( int i = 2 ; i <= n  ; i++)
    {
       cout <<"Enter the "<<i<<" data: ";
       cin >> data;
    
       Node* newnode = new Node(data);
       temp -> next = newnode;
       newnode->next = head;
       temp = newnode;
    
    }

}


void simpleLinkedList(Node*& head , int n){

    Node* temp = head;
    int data;

    for( int i = 2 ; i <= n  ; i++)
    {
       cout <<"Enter the "<<i<<" data: ";
       cin >> data;
    
       Node* newnode = new Node(data);
       temp -> next = newnode;
       temp = newnode;
    
    }

}

int main(){

    int n , data , choice;
    
    cout <<"Enter the head data: ";
    cin >> data;
    
    Node* head = new Node(data);
    
    cout<<"Enter the no of nodes: ";
    cin >> n;
    

    cout <<"Perform choice"<< endl<<"1.)Only simple "<<endl<<"2.)Make Circular "<<endl;
    cin >> choice;
    
    switch(choice){

    case 1:
    simpleLinkedList(head , n);
    break;
    
    case 2:
    circularLinkedList(head , n);
    break;

    default:
    cout<<"Invalid choice"<<endl;

    }
    

    print(head);
    cout <<endl;
    
    bool ans = iscircular(head);
    
    if(ans == 1){
        cout <<"Yes it is circular linked list "<<endl;
    }
    else{
        cout <<"No it is not circular linked list "<<endl;
    }


}    