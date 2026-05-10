#include<bits/stdc++.h>
using namespace std;

class TreeNode{

     public:
     int data;
     TreeNode* left;
     TreeNode* right;

     TreeNode(int data){
         this -> data = data;
         this -> left =NULL;
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

     cout <<"Enter the right child of the "<< data << endl;
     createBinaryTree(root -> right);

}

void inorder(TreeNode*root){

    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout << root -> data <<" ";
    inorder(root -> right);


}



TreeNode* createNodeToParent(unordered_map<TreeNode*, TreeNode*>&NodeToParent , int target , TreeNode*root ){

    queue<TreeNode*>q;
    q.push(root);
    TreeNode*res = NULL;

     NodeToParent[root] = NULL;

     while(!q.empty()){

        int n = q.size();

        for(int i = 0 ; i < n ; i++){

            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode -> data == target){
                res = frontNode;
            }

            if(frontNode -> left){
                q.push(frontNode->left);
                NodeToParent[frontNode -> left] = frontNode;
            }

            if(frontNode -> right){
                q.push(frontNode -> right);
                NodeToParent[frontNode -> right ] = frontNode;
            }
        }
     }

     return res;

}



int solve(unordered_map<TreeNode*, TreeNode*>NodeToParent , TreeNode* target){

     queue<TreeNode*>q;
     q.push(target);

     int ans = 0;
     unordered_map<TreeNode* , bool>visited;
     visited[target] = true;

     while(!q.empty()){

         bool flag = 0;
         int n = q.size();

         for(int i = 0 ; i < n ; i++){

            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode -> left && !visited[frontNode -> left]){
                      q.push(frontNode->left);
                      visited[frontNode -> left] = true;
                      flag = 1;
            }
            if(frontNode -> right && !visited[frontNode -> right]){
                      q.push(frontNode->right);
                      visited[frontNode -> right] = true;
                      flag = 1;
            }
            if(NodeToParent[frontNode] && !visited[NodeToParent[frontNode]]){

                      flag = 1;
                      q.push(NodeToParent[frontNode]);
                      visited[NodeToParent[frontNode]] = true;
            }



         }
         if(flag == 1){
            ans++;
         }




     }



return ans;

}

int main(){

    int target;

    TreeNode* root = NULL;
    createBinaryTree(root);


    cout <<"Inorder Traversal: "<< endl;
    inorder(root);

    cout << endl;
    cout <<"Enter the target value: "<< endl;
    cin >> target;


    unordered_map<TreeNode*, TreeNode*>NodeToParent;
    TreeNode* targetNode= createNodeToParent(NodeToParent , target , root);


    int ans = solve( NodeToParent ,targetNode);

    cout <<"Time required: "<< ans << endl;


}