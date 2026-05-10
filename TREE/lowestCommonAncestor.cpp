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

      if( data == -1){
        return;
      }

     root = new TreeNode(data);

     cout <<"Enter the left child of the "<< data << endl;
     createBinaryTree(root -> left);

     cout <<"Enter the right child of the "<< data << endl;
     createBinaryTree(root -> right);

}

void inorder(TreeNode* root){

     if(root == NULL){
        return;
     }


     inorder(root -> left);
     cout << root -> data <<" ";
     inorder(root -> right);
}


TreeNode* lowestCommon(TreeNode* root , int n1 , int n2){


    if(root == NULL){
        return NULL;
    }

    if(root -> data == n1 || root -> data == n2){
          return root;
    }


    TreeNode* left = lowestCommon(root -> left , n1 , n2);
    TreeNode* right = lowestCommon(root -> right , n1 , n2);

    if(left != NULL && right != NULL){
         return root;
    }

    else if(left == NULL && right != NULL){
           return right;
    }

    else if(left != NULL && right == NULL){
        return left;
    }

    else{
        return NULL;
    }



}
int main(){

    TreeNode* root = NULL;
    createBinaryTree(root);

    cout <<"Inorder Traversal: "<< endl;
    inorder(root);

    cout << endl;

    int n1 , n2;
    cout <<"Enter the n1 and n2: "<< endl;
    cin >> n1 >> n2;

    TreeNode* ans  = lowestCommon(root , n1 , n2);

    cout <<"The lowest common ancestor of n1 and n2: "<< ans -> data << endl;




}