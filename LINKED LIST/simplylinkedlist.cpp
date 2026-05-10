#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;
     
    //constructor
    Node(int data){
    this->data = data;
    this->next = NULL;
    }

    //destructor 
    ~Node(){
        int value = this -> data;
        if( this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for node with data " << value <<endl;
    }


};
void insertathead(Node* &head , int d){
    
    //new node create
    Node*temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertattail(Node* &tail , int d){
    Node*temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp ->data <<" ";
        temp = temp ->next;
    }
    cout <<endl;
}

void insertatposition( Node* &tail ,Node* &head , int position ,int d){

     if(position == 1){
        insertathead(head , d);
        return;
     }

    Node* temp = head;
    int cnt = 1 ;

    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }
    //inserting at last position
    if(temp -> next == NULL){
        insertattail(tail , d);
        return ;

    }
    //creating a node for d;
    Node* nodetoinsert = new Node(d);
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;
}

void deletenode(int position , Node* &head,Node* &tail){
//deleting first or start node
    if( position == 1){
        Node*temp = head;
            head = head -> next;
            //memory free start node
            temp -> next = NULL;
            delete temp;
    }
    else{
           Node* curr = head;
           Node*prev = NULL;
           int cnt =1;
           while(cnt < position){
            prev = curr;
            curr = curr -> next;
             cnt++;
           }

           if( curr -> next == NULL){
             tail = prev;
             prev->next = NULL;
             delete curr;
             return ;
             
           }
           prev -> next = curr -> next;
           curr->next = NULL;
           delete curr;
           }
}

int main(){

Node* node1 = new Node(10);
Node* head = node1;
Node* tail = node1;
print(head);

// insertathead(head , 12);
// insertathead(head,15);
insertattail(tail , 12);

print(head);
insertattail(tail, 15);
print(head);

insertatposition(tail , head ,4 , 22);
print(head);
cout << head->data<< " "<< tail -> data <<endl;

deletenode(4,head,tail);
print(head);
cout << head->data<< " "<< tail -> data <<endl;


    return 0;
}