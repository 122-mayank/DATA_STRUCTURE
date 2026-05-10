#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*prev;
    Node*next;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
   
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout <<"Memory freed for node with data: "<<val<<endl;



    }

};

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data<<" ";
        temp = temp -> next;
    }
    cout <<endl;
}

//gives length of linked list
int getlength(Node* head){
    int len = 0 ;
    Node* temp = head;

    while(temp != NULL){
       len++;
        temp = temp -> next;
    }
    return len;
}

void insertathead(Node* &head , int d){
    
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertattail(Node* &tail , int d){

    Node* temp = new Node(d);
    tail -> next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertatposition( Node* &tail ,Node* &head , int position ,int d){

    if(position == 1){
       insertathead(head , d);
       return;
    }

    Node*temp = head;
    int cnt  =1 ;
    while(cnt < position -1){
        temp = temp -> next;
        cnt++;
    }
    //last node insertion
    if(temp -> next == NULL){
        insertattail(tail,d);
        return;
    }
    Node* nodetoinsert = new Node(d);
    nodetoinsert -> next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert -> prev = temp;

}



void deletenode(int position , Node* &head,Node* &tail){
    //deleting first or start node
        if( position == 1){
            Node*temp = head;
            temp -> next ->prev = NULL;
            head = temp->next;
            temp-> next = NULL;
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
                 curr->prev=NULL;
                 delete curr;
                 return ;
                 
               }
               curr -> prev = NULL;
               prev ->next = curr->next;
               curr->next = NULL;
               delete curr;
               }
    }



int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    cout << getlength(head) <<endl;

    insertathead(head , 11);
    insertathead(head , 13);
    insertathead(head , 17);

    print(head);

    insertattail(tail , 25);
    insertattail(tail , 45);
   

    print(head);

    insertatposition(tail , head ,2 , 43);
    print(head);

    deletenode(7 , head,tail);
    print(head);
    cout << tail->data <<" "<< head->data<<endl;

    return 0;
}