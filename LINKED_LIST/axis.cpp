
//Insert at start 

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
         this -> data = data;
         this -> next = NULL;
    }
};

void insertNode(Node* head){

    Node* temp = head;

    int data , n;
    cout <<"Enter the n nodes"<< endl;
    cin >> n;

    for(int i = 2 ; i <= n ; i++){

        cout <<"Enter the "<< i <<" data "<<endl;
        cin >> data;

        Node* newnode = new Node(data);
        temp -> next = newnode;
        temp = newnode;
    }

}

void print(Node* head){

    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data <<" -> ";
        temp = temp -> next;
    }

    cout <<"NULL"<< endl;

}


int main(){

    Node* head = nullptr;

    int data;
    cout <<"Enter the head"<< endl;
    cin >> data;

    head = new Node(data);
    insertNode(head);

    //printing
    cout <<"Print Linked List"<< endl;
    print(head);

    insertAtHead();

}