#include<iostream>
using namespace std;

class node{
 
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }

};

node* buildTree(node* root){
int data;
cout <<"Enter the data: "<<endl;
cin >> data;

root = new node(data);

if(data == -1){
    return NULL;
}

cout<<"Enter the left data: "<<data<<endl;
  root -> left = buildTree(root -> left);
  cout <<"Enter the right data: "<<data<<endl;
  root -> right = buildTree(root -> right);

  return root;



}

int getlength(node* root){
        
    if( root == NULL){
        return 0;
    }

    int left = getlength(root->left);
    int right = getlength (root -> right);

    int max = (left > right) ? left : right;
    return max+1;

}

int main(){

 node * root = NULL;

 root = buildTree(root);
 
 cout <<"Height of binary tree: "<<endl;
 cout <<getlength(root) <<endl;

 


}