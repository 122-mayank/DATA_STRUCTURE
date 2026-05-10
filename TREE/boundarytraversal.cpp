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


void createBinaryTree(TreeNode*&root){

     int data;
     cout <<"Enter the data: "<< endl;
     cin >> data;

     if(data == -1){
        return;
     }

     root =  new TreeNode(data);


     cout <<"Enter the left child of the " << data << endl;
     createBinaryTree(root -> left);

     cout <<"Enter the rigth child of the "<< data << endl;
     createBinaryTree(root -> right);
}

void inorder(TreeNode*root){

     if(root == nullptr){
        return;
     }

     inorder(root -> left);
     cout << root -> data <<" ";
     inorder(root -> right);


}

void rootleft(TreeNode* root , vector<int>&ans){

    if( root == NULL || (root -> left == NULL && root -> right == NULL)){
        return;
    }


    ans.push_back(root -> data);
    if(root -> left){
         rootleft(root -> left , ans);
    }

    else{
         rootleft(root -> right ,ans);
    }
}

void leaftraverse(TreeNode* root , vector<int>&ans){

    if(root == NULL){
        return;
    }

    if(root -> left == NULL && root -> right == NULL){
         ans.push_back(root -> data);
         return;
    }

    leaftraverse(root -> left ,ans);
    leaftraverse(root -> right , ans);


}

void rootright(TreeNode* root, vector<int>&ans){

     if((root == NULL) || (root -> left == NULL && root -> right == NULL)){
          return;
     }


     if(root -> right){
         rootright(root -> right , ans);
     }
     else{
        rootright(root -> left ,ans);
     }

     ans.push_back(root -> data);



}
int main(){



     TreeNode* root = nullptr;
     createBinaryTree(root);

     cout <<"Inorder Traversal: "<< endl;
     inorder(root);

     vector<int>ans;
     ans.push_back(root -> data);

     rootleft(root->left , ans);

     //left traversal of binary tree
     leaftraverse(root -> left , ans);
     //right traversal of binary Tree
     leaftraverse(root -> right , ans);

     rootright(root -> right , ans);


     cout << endl;
     cout <<"Boundary Traversal: "<< endl;
     for(int i = 0 ; i < ans.size() ; i++){
         cout << ans[i] <<" ";
     }

     cout << endl;


}