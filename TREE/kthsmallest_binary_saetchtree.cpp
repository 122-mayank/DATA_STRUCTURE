#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = nullptr;
    }

};

void insertNode(Node*&root , int data){
          
    if( root == NULL){
        root = new Node(data);
        return;
    }

    if( data > root -> data){
         insertNode(root -> right , data );
    }
    else{
        insertNode(root -> left , data);
    }
}

void inorder(Node* root){

    if( root == NULL){
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);


}

int findKSmallest(Node* root , int k , int& i){

    if( root == NULL){
        return -1;
    }
    

   int left =  findKSmallest(root -> left , k , i);
   if( left != -1){
    return left;
   }

    i++;
    if( i == k){
         return root -> data;
    }

  return findKSmallest(root -> right, k , i);

}

int main(){

    int data;
    Node* root = nullptr;
     cout << "Enter values to insert in BST (-1 to stop): " << endl;
    while( true ){
        cin >> data;
         if( data == -1){
            break;
         }
         insertNode(root,data);
    }

    cout <<"Inorder Traversal "<<endl;
    inorder(root);
    cout << endl;

    int k;
    cout <<"Enter the value of k: "<<endl;
    cin >> k;
    int i = 0;
    int ans = findKSmallest(root , k , i);
    cout <<"The k smallest node in the tree is: "<<ans;
    

}