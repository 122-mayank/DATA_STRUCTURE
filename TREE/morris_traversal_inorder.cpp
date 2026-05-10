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


    root = new TreeNode(data);

    cout <<"Enter the left child of the "<< data << endl;
    createBinaryTree(root -> left);

    cout << "Enter the right child of the "<< data << endl;
    createBinaryTree(root -> right);


 }


 void morrisTraversal(TreeNode* root , vector<int>&ans){


    TreeNode* curr = root;

    while(curr != NULL){

            if(curr -> left == nullptr){

                 ans.push_back(curr -> data);
                 curr = curr ->right;

            }

            else{

                 TreeNode* prev = curr -> left;
                 while(prev -> right != nullptr && prev -> right != curr){
                            prev = prev -> right;
                 }

                 if(prev -> right == nullptr){
                        prev -> right = curr;
                        curr = curr -> left;
                 }
                 else{

                    prev -> right = nullptr;
                    ans.push_back(curr -> data);
                    curr = curr -> right;

                 }


            }
    }
 }





int main(){


    TreeNode* root = nullptr;
    createBinaryTree(root);


    vector<int>ans;

    cout << endl;
    morrisTraversal(root , ans);

    cout <<"Morris Traversel for inorder: "<< endl;

    for(int i = 0 ; i < ans.size() ; i++){
         cout << ans[i] <<" ";
    }

    cout << endl;

}