#include<iostream>
using namespace std;

class Node{
 
    public:
    int data;
    Node*next;

    public:
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

};

void print(Node*& head){
 
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }

}

// Node* sortlist(Node*& head){
 
//     int zerocount = 0;
//     int onecount = 0;
//     int twocount = 0;

//     Node*temp = head;

//     while(temp != NULL){

//       if( temp -> data == 0){
//         zerocount++;
//       }
//       else if( temp -> data == 1){
//         onecount++;
//       }
//       else{
//         twocount++;
//       }
//       temp = temp -> next;

//     }

//    temp = head;

//    while( temp != NULL){

//          if( zerocount != 0){
//             temp -> data = 0;
//             zerocount--;
//          }

//          else if( onecount != 0){
//             temp -> data = 1;
//             onecount--;
//          }

//          else if( twocount != 0){
//             temp -> data = 2;
//             twocount--;
//          }
      
//       temp = temp ->next;

//    }

//    return head;

// }

void insertattail(Node*& curr , Node*& temp ){
 
curr -> next = temp;
curr = temp;
}

Node* sortList(Node*& head){

Node* zerohead = new Node(-1);
Node* zerotail = zerohead;

Node* onehead = new Node(-1);
Node* onetail = onehead;

Node* twohead = new Node(-1);
Node* twotail = twohead;

Node* temp = head;

while(temp != NULL){

  if( temp -> data == 0){
    insertattail(zerotail , temp);
  }

  else if(temp -> data == 1){
    insertattail(onetail , temp);
  }

  else if( temp -> data == 2){
    insertattail(twotail, temp);
  }

  temp = temp -> next;

}

if( onehead -> next != NULL){
    zerotail -> next = onehead -> next;
}
else{
    zerotail -> next = twohead -> next;
}

onetail -> next = twohead -> next;
twotail -> next = NULL;

return zerohead -> next;
}

int main(){

int n , data;

cout <<"Enter the no of nodes: ";
cin >> n;

cout <<"Enter the head data: ";
cin >> data;

Node*head = new Node(data);

Node* temp = head;

for( int i = 2 ; i <= n ; i++){
   
    cout <<"Enter the "<<i<<" data: ";
    cin >> data;

    Node* newnode = new Node(data);
   temp -> next = newnode;
   temp = newnode;
}
cout <<"Before sorted list: "<<endl;
print(head);
 
// Node* ans = sortlist(head) ;
// cout<<endl;

Node* ans = sortList(head);
cout<<endl;

cout <<"After sorted list: "<<endl;
print(ans);


}