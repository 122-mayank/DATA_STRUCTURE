#include<bits/stdc++.h>
using namespace std;


class TreeNode{

    public:
    int data;
    TreeNode* left;
    TreeNode* right;


    TreeNode(int data){
         this-> data = data;
         this -> left = NULL;
         this -> right = NULL;
    }

};


void createBinaryTree(TreeNode*&root){

   int data;
   cout <<"Enter the data: "<< endl;
   cin >> data;

   if(data == -1){
    return ;
   }

  root = new TreeNode(data);

  cout <<"Enter the left child of the "<< data << endl;
  createBinaryTree(root -> left);


  cout <<"Enter the right child of the "<< data << endl;
  createBinaryTree(root -> right);

}


void preorder(TreeNode* root){

     if(root == NULL){
        return;
     }

     cout << root -> data <<" ";
     preorder(root -> left);
     preorder(root -> right);
}

void morrisPreorder(TreeNode* root, vector<int>&ans){

     while(root){

        if(root -> left == nullptr){
             ans.push_back(root -> data);
             root = root -> right;
        }


        else{

            TreeNode* curr = root -> left;
            while(curr -> right && curr -> right != root){
                 curr = curr -> right;
            }

            if(curr -> right == root){
                curr->right = nullptr;
                root = root->right;
            }
            else{
                  ans.push_back(root->data);
                  curr -> right = root;
                  root = root -> left;
            }


        }



     }


}
int main(){

    TreeNode* root = nullptr;

    createBinaryTree(root);

    cout <<"Preorder Traversal: "<< endl;
    preorder(root);

    vector<int>ans;

    cout << endl;
    cout <<"Morris Traversal for Preorder: "<< endl;
    morrisPreorder(root, ans);

   //printing the traversal
   for(int i = 0 ; i < ans.size() ; i++){
       cout << ans[i] <<" ";
   }



}