#include<iostream>
using namespace std;

class TreeNode{
    
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

TreeNode* createBinaryTree() {

    int data;
    cout <<"Enter the data(-1 for NULL) : "<<endl;
    cin >> data;


    if( data == -1){
        return NULL;
    }

    TreeNode* newnode = new TreeNode(data);
    
    cout <<"Enter the left child of "<< data <<endl;
    newnode -> left = createBinaryTree();

    cout <<"Enter the right child of "<< data <<endl;
    newnode -> right = createBinaryTree();


   return newnode;

}

void inorder(TreeNode* root){

    if( root == NULL){
        return ;
    }

    inorder(root -> left);
    cout << root -> data <<" ";
    inorder( root -> right);

}



int main(){
    
    TreeNode* root = createBinaryTree();
    inorder( root);


}