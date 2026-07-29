#include<bits/stdc++.h>
using namespace std;

class TreeNode{

    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
         this -> data = data;
         this -> left = nullptr;
         this -> right = nullptr;
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

void createBinaryTree(TreeNode*&root){

    int data;
    cout <<"Enter the data"<< endl;
    cin >> data;

    if(data == -1){
        return;
    }

    root = new TreeNode(data);

    cout <<"Enter the left child of "<< data << endl;
    createBinaryTree(root -> left);

    cout <<"Enter the right child of "<< data << endl;
    createBinaryTree(root -> right);

}

void deleteDeepest(TreeNode* root, TreeNode* deleteNode){

    queue<TreeNode*>q;
    q.push(root);

    TreeNode* curr;
    while(!q.empty()){

        curr = q.front();
        q.pop();

        if(curr == deleteNode){
            curr = nullptr;
            delete(deleteNode);
            return;
        }

        if(curr -> right){

            if(curr -> right == deleteNode){
                curr -> right = nullptr;
                delete(deleteNode);
                return;
            }

            q.push(curr -> right);
        }

        if(curr -> left){
            if(curr -> left == deleteNode){
                curr -> left = nullptr;
                delete(deleteNode);
                return;
            }
            q.push(curr -> left);
        }


    }

}

TreeNode* deletion(TreeNode* root , int key){

    //tree is empty
    if(root == nullptr){
        return nullptr;
    }

    //if the only one root is present
    if(root ->left == NULL && root -> right == NULL){
        //if match , delete it and return back
        if(root -> data == key){
            return nullptr;
        }
        return root;
    }

    queue<TreeNode*>q;
    q.push(root);

    TreeNode* curr;
    TreeNode* keyNode = nullptr;

    while(!q.empty()){

        curr = q.front();
        q.pop();

        if(curr -> data == key){
            keyNode = curr;
        }
        if(curr -> left){
            q.push(curr -> left);
        }
        if(curr -> right){
            q.push(curr -> right);
        }
    }

    if(keyNode != nullptr){

        //Store the data of rightmost node
        int x = curr -> data;

        // replace the value of x with keyNode
        keyNode -> data = x;

        deleteDeepest(root , curr);

    }
    return root;
}

int main(){

    TreeNode* root = nullptr;
    createBinaryTree(root);

    cout <<"Before Deletion"<< endl;
    inorder(root);

    cout << endl;

    int key;
    cout <<"Enter the key"<< endl;
    cin >> key;

    root = deletion(root , key);

    cout<<"After Deletion"<< endl;
    inorder(root);

}