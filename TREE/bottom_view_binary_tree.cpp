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

vector<int> bottomViewTraversal(TreeNode* root){

    vector<int>ans;

    if(root == NULL){
        return ans;
    }

    map<int , int> topNode;
    queue<pair<TreeNode* , int>>q;

    q.push(make_pair(root , 0));

    while(!q.empty()){

        auto temp = q.front();
        q.pop();

        TreeNode* frontNode = temp.first;
        int hd = temp.second;


        topNode[hd] = frontNode -> data;

        if(frontNode -> left){
              q.push(make_pair(frontNode -> left , hd - 1));
        }

        if(frontNode -> right){
             q.push(make_pair(frontNode -> right , hd + 1));
        }
    }


    for(auto i : topNode){
           ans.push_back(i.second);
    }

    return ans;

}

int main(){

TreeNode* root = nullptr;
createBinaryTree(root);


cout <<"Inorder Traversal "<< endl;
inorder(root);


vector<int>ans = bottomViewTraversal(root);

cout << endl;
cout <<"Bottom View Traversal "<< endl;
for(int i = 0 ; i < ans.size() ; i++){
       cout << ans[i] <<" ";
}


}