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

Node* rotateList(Node* head){

int k;
cout <<"Enter the value of k: "<< endl;
cin >> k;


int length = 0;
Node* temp = head;
while(temp != NULL){
     length = length + 1;
     temp = temp -> next;
}


//update the value of k
k = k % length;
int rem_val = length - k;


Node* nextNode = temp->next;
temp->next = NULL;

// Step 3: Go to end of second part
Node* temp2 = nextNode;

while(temp2->next != NULL){
    temp2 = temp2->next;
}

temp2->next = head;

return nextNode;
}

void insertNode(Node* temp){


    int data , size;
    cout <<"Enter the number of nodes(except head): "<< endl;
    cin >> size;

    for(int i = 1 ; i <= size ; i++){

        cout <<"Enter the "<< i <<" data: ";
        cin >> data;

        Node* newnode = new Node(data);
        temp -> next = newnode;
        temp = newnode;
    }

}


void print(Node* head){

    Node* temp = head;

    while(temp != NULL){
        
        cout << temp -> data<<" -> ";
        temp = temp -> next;

    }

    cout <<" NULL "<< endl;
}

int main(){

    int data;
    Node* head = nullptr;

    cout <<"Enter the data: "<< endl;
    cin >> data;

    head = new head(data);

    insertNode(head);

    cout <<"Before Rotate List"<< endl;
    print(head);

    rotateList(head);
    cout << endl;

    cout <<"After Rotate List"<< endl;
    print(head);



}