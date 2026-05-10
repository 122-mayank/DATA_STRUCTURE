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
    cout <<"Enter the data: ";
    cin >> data;

    if(data == -1){
        return;
    }

    root = new TreeNode(data);

    cout <<"Enter the left child of the " << data << endl;
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

void solve(TreeNode* root, int &count , int k , vector<int> path){

    if(root == NULL){
        return;
    }


    path.push_back(root -> data);
    solve(root -> left , count , k , path);
    solve(root -> right , count , k , path);


    int size = path.size();
    int sum = 0;


    for(int i = size ; i >= 0 ; i--){
         sum += path[i];

         if(sum == k){
            count++;
         }
    }

    path.pop_back();
}


int main(){

     TreeNode* root = nullptr;
     createBinaryTree(root);

     cout <<"Inorder Traversal: "<< endl;
     inorder(root);

     cout << endl;

     int count = 0;
     int k;
     cout <<"Enter the k: ";
     cin >> k;

     

     vector<int> path;

     solve(root , count , k, path);

     cout<<"The paths in the root is : "<< count << endl;


}