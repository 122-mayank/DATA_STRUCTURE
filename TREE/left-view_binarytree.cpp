#include<bits/stdc++.h>
using namespace std;

class TreeNode{

     public:
     int data;
     TreeNode* left;
     TreeNode* right;


     TreeNode(int data){
         this -> data = data;
         this -> left = NULL;
         this -> right = NULL;
     }

};
void createBinaryTree(TreeNode* &root){

int data;
cout <<"Enter the data: "<< endl;
cin >> data ;

if( data == -1){
    return ;
}

root = new TreeNode(data);

cout <<"Enter the left child of the "<< data << endl;
createBinaryTree(root -> left);

cout <<"Enter the right child of " << data << endl;
createBinaryTree(root -> right);

}

void inorder(TreeNode* root){

     if(root == null){
        return;
     }

     inorder(root -> left);
     cout << root -> data << endl;
     inorder(root -> right);

}


int main(){


TreeNode* root = nullptr;

createBinaryTree(root);

cout <"Inoder Traversal: "<< endl;
inorder(root);






}