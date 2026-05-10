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
    cout <<"Enter the data " << endl;
    cin >> data;

    if(data == -1){
        return;
    }

    root = new TreeNode(data);

    cout <<"Enter the left child of the "<< data << endl;
    createBinaryTree(root -> left);


    cout <<"Enter the right child of the "<< data << endl;
    createBinaryTree(root -> right);

}

void inorder(TreeNode* root , vector<int>&ans){

    if(root == NULL){
         return;
    }

    inorder(root -> left , ans);
    ans.push_back(root -> data );
    inorder(root -> right , ans);
}
int main(){

    TreeNode* root = NULL;
    createBinaryTree(root);

    int key;

    cout <<"Inorder Traversal: "<< endl;
    vector<int>ans;
    inorder(root , ans);

    cout <<"Enter the key: "<< endl;
    cin >> key;

    int index;


    for(int i = 0 ; i < ans.size() ; i++){
              if(ans[i] == key){
                index = i;
                break;
              }
    }

    cout <<"Inorder Predecessor: "<< ans[index-1] << endl;
    cout <<"Inorder Sucessor: "<< ans[index+1] << endl;




}