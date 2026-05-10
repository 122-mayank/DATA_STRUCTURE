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

    cout <<"Enter the left child of the " << data << endl;
    createBinaryTree(root -> left);


    cout <<"Enter the right  child of the " << data << endl;
    createBinaryTree(root -> right);

}

void inorder(TreeNode* &root){

     if(root == NULL){
        return;
     }

     inorder(root -> left);
     cout << root -> data <<" ";
     inorder(root -> right);


}

vector<int> topViewBinaryTree(TreeNode* &root) {

    vector<int> ans;
    if(root == NULL) return ans;

    queue<pair<TreeNode*, int>> q; // node, horizontal distance
    q.push({root, 0});

    map<int, int> topNode;  // HD → node value

    while(!q.empty()) {

        auto temp = q.front();
        q.pop(); // FIXED

        TreeNode* frontNode = temp.first;
        int hd = temp.second;

        // If HD is visited first time → this is the top view node
        if(topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left) {
            q.push({frontNode->left, hd - 1});
        }
        if(frontNode->right) {
            q.push({frontNode->right, hd + 1});
        }
    }

    // After BFS, extract correct left → right top view
    for(auto &i : topNode) {
        ans.push_back(i.second);
    }

    return ans;
}


int main(){


      TreeNode* root = nullptr;

      createBinaryTree(root);
      cout <<"Inorder Traversal: "<< endl;

      inorder(root);

      vector<int>ans = topViewBinaryTree(root);

      cout << endl;

      cout <<"Top view of Binary Tree"<< endl;
      for(int i =0 ; i < ans.size() ; i++){
           cout << ans[i] <<" ";
      }

      cout << endl;

      


}