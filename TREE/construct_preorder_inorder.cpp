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


void inorder(TreeNode* root){

    if(root == NULL){
        return;
    }


    inorder(root -> left);
    cout << root -> data <<" ";
    inorder(root -> right);

}


int findPos(int element , vector<int>&inorder , int size)
{


   for(int i = 0 ; i < size ; i++){

      if(inorder[i] == element){
            return i;
      }

   }
   return -1;


}

TreeNode* solve(vector<int>&inorder , vector<int>&preorder , int size , int st , int end , int&index){


      if(index >= size || st < end){
        return NULL;
      }


      int element = preorder[index++];
      TreeNode* root = new TreeNode(element);
      int pos = findPos(element , inorder , size);

      root -> left = solve(preorder , inorder , size , st , pos-1 , index);
      root -> right = solve(preorder , inorder , size , pos+1,end, index);

      return root;

}


int main(){



     int size ;
     cout <<"Enter the size of array: "<< endl;
     cin >> size;

     vector<int>inorder(size);
     vector<int>preorder(size);

     for(int i = 0 ; i < size ; i++){
         cin >> inorder[i];
     }

     for(int j = 0 ; j < size ; j++){
         cin >> preorder[i];
     }

    TreeNode* ans =  solve(inorder , preorder , size , 0 , size - 1, 0);
    


}