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


void insertNode(Node*&head , int data){

    Node* temp = head;

    int size;
    cout <<"Enter the size(except head): ";
    cin >> size;


    for(int i = 1 ; i <= size ; i++){
        
         cout <<"Enter the "<< i <<" data: "<< endl;
         cin >> data;

         Node* newnode = new Node(data);
         temp -> next = newnode;
         newnode -> next = head;
         temp = newnode; 
    }

}

void print(Node* head){

    Node* temp = head;

    while(temp -> next != head){
         cout << temp -> data <<" -> ";
         temp = temp -> next;
    }

    cout <<" NULL "<< endl;

}
int main(){

    int data;
    cout <<"Enter the head data: "<< endl;
    cin >> data;

    Node* head = new Node(data);

    insertNode(head , data);

    print(head);


}