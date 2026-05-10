#include<bits/stdc++.h>
using namespace std;

class  TreeNode{

     public:
     int data;
     TreeNode*left;
     TreeNode*right;


     TreeNode(int data){
         this -> data = data;
         this -> left = NULL;
         this -> right = NULL;
     }

};


vector<int> verticalOrder(TreeNode*root){

     vector<int>ans;

     map<int , map<int , vector<int>>> nodes;

     queue<pair<TreeNode* , pair<int,int>>> q;


     q.push(make_pair(root , make_pair(0,0)));

     while(!q.empty()){

         pair<TreeNode* , pair<int,int>>temp = q.front();
         q.pop();

         TreeNode* frontNode = temp.first;

         int hd = temp.second.first;
         int lvl = temp.second.second;

         nodes[hd][lvl].push_back(frontNode -> data);

         if(frontNode -> left){
                q.push(make_pair(frontNode -> left , make_pair(hd - 1 , lvl + 1)));
         }

         if(frontNode -> right){
                   q.push(make_pair(frontNode -> right , make_pair(hd + 1 , lvl + 1)));
         }

     }

     for(auto i : nodes){
          for(auto j : i.second){
              for(auto k : j.second){
                ans.push_back(k);
              }
          }
     }

     return ans;

}


void createBinaryTree(TreeNode* &root){

    int data;
    cout <<"Enter the data: "<< endl;
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

    vector<int>ans = verticalOrder(root);
    //prinitng the ans
    for(int i = 0 ; i < ans.size() ; i++){
         cout << ans[i] <<" ";
    }



}