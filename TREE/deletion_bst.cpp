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


TreeNode* createBST(TreeNode* root , int data){

    if(root == NULL){
          return new TreeNode(data);
    }
    
    if(root -> data > data){
       root -> left = createBST(root -> left , data);
    }
    else{
       root -> right = createBST(root -> right, data);
    }
    
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

    TreeNode* root = nullptr;

    int data;
    cout <<"Enter the root node: ";
    cin >> data;

    while(data != -1){
        root = createBST(root , data);
        cout <<"Enter the next data "<< endl;
        cin >> data;
    }

    cout <<"Inorder Traversal of the BST"<< endl;
    inorder(root);

    int key;
    cout <<"Enter the key: ";
    cin >> key;

    deleteNode(root , key);


    
}