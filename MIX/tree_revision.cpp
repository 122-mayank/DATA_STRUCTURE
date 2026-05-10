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


void LeftView(TreeNode* root ,int level , vector<int>&ans){

     if(root == NULL){
         return;
     }

     if(level == ans.size()){
         ans.push_back(root -> data);
     }

    LeftView(root -> left , level + 1 , ans);
    LeftView(root -> right , level + 1 , ans);

}

void createBinaryTree(TreeNode*&root){

     int data;
     cout<<"Enter the data "<< endl;
     cin >> data;
     

     if(data == -1){
         return;
     }

     root = new TreeNode(data);

     cout <<"Enter the left child of the  "<< data << endl;
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



int main(){


    TreeNode* root = nullptr;

    createBinaryTree(root);

    cout <<"Inorder Traversal: "<< endl;
    inorder(root);

    cout << endl;

    vector<int>ans;

    LeftView(root ,0 ,ans);

    cout <<"LeftView Traversal of the Binary Tree"<< endl;
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] <<" ";
    }

    cout << endl;
}