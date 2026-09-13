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

void createNode(Node* head){

    Node* temp = head;

    int nodes , data;
    cout <<"Enter the nodes except head "<<endl;
    cin >> nodes;

    for(int i = 1 ; i <= nodes ; i++){
          cout <<"Enter the " << i <<" node ";
          cin >> data;

          Node* newnode = new Node(data);
          temp -> next = newnode;
          temp = newnode;
    }

}
void printNode(Node* head){
    Node* temp = head;

    while(temp != NULL){
         cout << temp -> data <<" -> ";
         temp = temp -> next;
    }

    cout <<"NULL" << endl;
}

int main(){

    Node* head = nullptr;

    int data;
    cout <<"Enter the head data "<< endl;
    cin >> data;

    head = new Node(data);

    createNode(head);

    cout <<"Printing Linked List"<< endl;
    printNode(head);

}