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

void print(Node*& head){
  
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }

}
Node* kreverse(Node*& head , int k){
 

//base case
if( head == nullptr){
    return head;
}

Node *prev = NULL;
Node* curr = head;
Node* next = NULL;

int count = 0;
while( curr != NULL && count < k){
  
    next = curr -> next;
    curr -> next = prev;

    prev = curr;
    curr = next;
    count ++;
}

if( next != NULL){
    head -> next = kreverse(next , k);
}

return prev;


}

int main(){

int n , data;

cout <<"Enter the head data: ";
cin >> data;

Node* head = new Node(data);

cout<<"Enter the no of nodes: ";
cin >> n;

Node* temp = head;

for( int i = 2 ; i <= n  ; i++)
{
   cout <<"Enter the "<<i<<" data: ";
   cin >> data;

   Node* newnode = new Node(data);
   temp -> next = newnode;
   temp = newnode;

}

int k ;
cout <<"Enter the value of k: ";
cin >> k;


Node* ans = kreverse(head , k);
print(ans);




}