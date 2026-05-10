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

void insertNode(Node* head , int data){


    int size;
    cout<<"Enter the number of nodes(except head): ";
    cin >> size;

    Node* temp = head;

    for(int i = 1 ; i <= size ; i++){

        cout <<"Enter the " << i <<" data: ";
        cin >> data;

        Node* newnode = new Node(data);

        temp -> next = newnode;
        temp = newnode;
    }

}

void swapNodePairs(Node* head){

      




}

//recursion approach to reverse the Linked list

// Node* reverseList(Node* head){

//     if( head == NULL || head -> next == NULL){
//          return head;
//     }

//     Node* nextNode = reverseList(head -> next);

//     head -> next -> next = head;
//     head -> next = NULL;

//     return nextNode;
// }


// Time Complexity : O(n)
//simple traversal technique to reverse the linked list
// Node* reverseList(Node* head){

//     Node* prev = NULL;
//     Node* curr = head;
//     Node* forward = NULL;

//     while(curr != NULL){

//         forward = curr -> next;
//         curr -> next = prev;
//         prev = curr;
//         curr = forward;
//     }

//     return prev;

// }

void print(Node* head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data <<" -> ";
        temp = temp -> next;
    }

    cout <<"NULL"<< endl;

}

int main(){

    Node* head = NULL;

    int data;
    cout <<"Enter the head data: ";
    cin >> data;

    head = new Node(data);

    insertNode(head , data);

    cout <<"Before Swapping the linked list: "<< endl;
    print(head);

    swapNodePairs(head);
    cout << endl;

    cout <<"After Swapping the linked list: "<< endl;
    print(reverseHead);


}