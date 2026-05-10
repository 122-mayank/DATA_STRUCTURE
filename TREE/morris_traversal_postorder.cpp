#include<bits/stdc++.h>
using namespace std;

class TreeNode{

    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
         this -> data = data;
         this ->left = NULL;
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

    cout <<"Enter the left child of the data: "<< endl;
    createBinaryTree(root -> left);


    cout <<"Enter the right child of the data: "<< endl;
    createBinaryTree(root -> right);

}

void inorder(TreeNode* root){

    if(root == NULL){
         return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}


void morrisPostorder(TreeNode* root , vector<int>&ans){

     TreeNode* curr = root;


    while(curr != NULL){

          if(curr -> right == nullptr){
                   ans.push_back(curr -> data);
                   curr = curr -> left;
          }


          else{

              TreeNode *predecessor = curr->right;
               while (predecessor->left != NULL && predecessor->left != curr) {
                predecessor = predecessor->left;
            }

            if (predecessor->left == NULL) {
                ans.push_back(curr->data);
                predecessor->left = curr;
                curr = curr->right;
            }


            else {
                predecessor->left = NULL;
                curr = curr->left;
            }

          }
    }
}
int main(){

    TreeNode* root = nullptr;
    createBinaryTree(root);


    cout <<"Inorder Traversal: "<< endl;
    inorder(root);
    cout << endl;


    vector<int>ans;

    morrisPostorder(root , ans);

    reverse(ans.begin() , ans.end());

    cout<<"Morris Traversal of Postorder: "<< endl;
    for(int i = 0 ; i < ans.size() ; i++){
         cout << ans[i] <<" ";
    }

}