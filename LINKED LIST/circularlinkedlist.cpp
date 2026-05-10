#include<iostream>
#include<map>
using namespace std;

class Node{


    public:
      int data;
      Node*next;
    
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        int val = this -> data;
       if(this->next != NULL){
        delete next;
        next = NULL;
    }
    cout <<"Memory freed for node with data: "<<val<<endl;
    }


};

void insertnode(Node* &tail , int element , int d){

    //assuming theat elemnt is present in the list

    if(tail== NULL){
        Node* newnode = new Node(d);
        tail = newnode;
        newnode -> next = newnode;
    }
    else{
        //non-empty list

        Node* curr = tail;

        while(curr -> data != element){
            curr = curr->next;
        }

        Node*temp = new Node(d);
        temp -> next = curr -> next;
        curr ->next = temp;
    }

}
void print(Node* &tail){
  Node* temp = tail;

  if(tail == NULL){
    cout <<"List is empty" <<endl;
  }

  do{
    cout << tail -> data <<" ";
    tail = tail -> next;
  }while(tail != temp);
  cout <<endl;
  
}

void deletenode(Node* &tail , int value){

//emptylist
if(tail == NULL){
    cout <<"List is empty , please check again"<<endl;
    return ;
}
else{
      Node* prev = tail;
      Node* curr = prev->next;
      while(curr-> data != value){
        prev = curr;
        curr = curr->next;
      }
      prev -> next = curr -> next;
 //1 node linked list
 if(curr == prev){
    tail = NULL;
 }
  //>=2 linked list
      if(tail == curr){
        tail=prev;
      }
      curr -> next = NULL;
      delete curr;
}
}
    
bool detectloop(Node* head){

  if( head == NULL){
    return false;
  }

  map<Node* , bool> visited;

  Node* temp = head;
   while( temp != NULL){

    if( visited[temp] == true)
    {
           return true;
    }
    visited[temp] = true;
    temp = temp -> next;
   }
   return false;

}
Node* floyddetectloop(Node* head){
  if(head == NULL){
    return NULL;
  }
  Node* slow = head;
  Node* fast = head;

  while( slow  != NULL && fast != NULL){
     fast = fast -> next;
     if( fast != NULL){
      fast = fast ->  next;
     }
     slow = slow -> next;

     if( slow == fast){
      return slow;
     }
  }
  return NULL;
}
Node* getstartingnode(Node* head){
   
  if( head == NULL){
    return NULL;
  }
  Node* intersection = floyddetectloop(head);
  Node * slow  = head;
  
  while( slow != intersection){
    slow = slow -> next;
    intersection=intersection->next;
  }
  return slow;

}
void removeloop(Node* head){
     
  if( head == NULL){
    return ;
  }
  Node* startofloop = getstartingnode(head);
  Node* temp = startofloop;
  while( temp -> next != startofloop ){
    temp = temp -> next;
  }
  temp -> next = NULL;

}

int main(){


Node* tail = NULL;
insertnode(tail , 5 , 3);
print(tail);

insertnode(tail , 3, 5);
print(tail);

// insertnode(tail , 5, 7);
// print(tail);

// insertnode(tail , 3, 10);
// print(tail);

// insertnode(tail , 5, 1);
// print(tail);

// deletenode(tail,3);
// print(tail);





    return 0;
}