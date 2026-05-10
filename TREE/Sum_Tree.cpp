#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int d){
    this -> data = d;
    this -> left = NULL;
    this -> right = NULL;
  }
  

};

Node* buildTree(Node* root){
int data;
cout <<"Enter the data: "<<endl;
cin >> data;

root = new Node(data);

if(data == -1){
    return NULL;
}

cout<<"Enter the left data: "<<data<<endl;
  root -> left = buildTree(root -> left);
  cout <<"Enter the right data: "<<data<<endl;
  root -> right = buildTree(root -> right);

  return root;
}

pair<bool,int> isBalancedFast(Node* root){

    if( root == NULL){
        pair<bool , int> p = make_pair(true , 0);
        return p;
    } 

    if( root -> left == NULL && root ->right == NULL){
         pair<bool , int> p = make_pair(true , root -> data);
        return p;
    }
    
    pair<bool , int> leftans = isBalancedFast(root -> left);
    pair<bool , int> rightans = isBalancedFast(root -> right);

    bool left = leftans.first;
    bool right = rightans.first;

    bool condn = root -> data == leftans.second + rightans.second;

    pair<bool,int> ans;

    if( left && right && condn){
        ans.first = true;
        ans.second = 2*root -> data;
    }
    else{
        ans.first = false;
    }

    return ans;
}

bool isSame(Node* root){
    return isBalancedFast(root).first;
}

int main(){

    Node* root = NULL;
     root = buildTree(root);
    cout << isSame(root) <<endl;


}