#include<iostream>
using namespace std;

class Node{

     public:
     int data;
     Node* left;
     Node* right;

     Node(int d){
        this -> data = d;
        this -> right = NULL;
        this -> left = NULL;
     }
    
};

Node* buildTree(Node* root){
      
    int data;
    cout<<"Enter the data: "<<endl;
    cin >> data;

    root = new Node(data);

    if( data == -1){
        return NULL;
    }

    cout <<"Enter the data "<< data <<" : " <<endl;
    root -> left = buildTree(root -> left);
    cout<<"Enter the data "<<data<<" : "<<endl;
    root -> right = buildTree(root -> right);

}

pair<bool,int>isBalanced(Node* root){

if( root == NULL){
    pair<bool , int>p = make_pair(true , 0);
    return p;
}

pair<bool , int> left = isBalanced(root -> left);
pair<bool , int> right = isBalanced(root -> right);

bool leftans = left.first;
bool rightans = right.first;

pair<bool,int> ans;

bool diff = abs((left.second - right.second)) <= 1;

ans.second = max(left.second,right.second) + 1;

if(leftans && rightans && diff){
    ans.first = true;
}
else{
   ans.first = false;

}


return ans;

}


int main(){


Node* root = NULL;

root = buildTree(root);

if(isBalanced(root).first){
    cout<<"Balanced Tree"<<endl;
}
else{
    cout <<"Not Balanced Tree"<<endl;
}

}