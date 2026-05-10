#include<bits/stdc++.h>
using namespace std;

class TreeNode{
     public:
     int data;
     TreeNode*left;
     TreeNode* right;

     TreeNode(int data){
         this -> data = data;;
         this -> left = NULL;
         this -> right = NULL;
     }
};

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
         this -> data = data;
         this -> next = NULL;
    }
};
 void createLinkedList(Node* head){

        Node* temp = head;
        int n;
        cout <<"Enter the number of nodes except head: "<< endl;
        cin >> n;

        int data;

        for(int i = 1 ; i <=n  ; i++){
             cout <<"Enter the " << i <<" data: ";
             cin >> data;

             Node* newnode = new Node(data);
             temp -> next = newnode;
             temp  = newnode;
        }

    }

    void printLinkedList(Node* head){
        Node* temp = head;

        while(temp != NULL){
            cout << temp -> data <<" -> ";
            temp = temp -> next;
        }

        cout << "NULL"<< endl;
}

TreeNode* solve(Node*& head , int n){

   if(n <= 0 || head == NULL){
    return NULL;
   }

    TreeNode* leftpointer = solve(head , n / 2);
     TreeNode* root = new TreeNode(head -> data);

     root -> left = leftpointer;

     head = head -> next;

     root -> right = solve(head , n - n / 2 -1);

     return root;


}
void inorder(TreeNode* root){

     if(root == NULL){
        return;
     }
     inorder(root -> left);
     cout << root -> data <<" ";
     inorder(root -> right);

}


int main(){

    Node* head = nullptr;

    int data;
    cout <<"Enter the head data : "<< endl;
    cin >> data;

    head = new Node(data);

    createLinkedList(head);

    cout <<"Display the linked list: "<< endl;
    printLinkedList(head);


    int count = 0;
    Node* temp = head;
    while(temp != NULL){
         count++;
         temp = temp -> next;
    }

  TreeNode* root =   solve(head , count);

  cout <<"Inorder : "<< endl;
  inorder(root);





}