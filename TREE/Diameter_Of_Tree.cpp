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
    cout<<"Enter the data: "<<endl;

    root = new Node(data);

    if(data == -1){
        return ;
    }

    cout<<"Enter the left data "<< data <<" : "<<endl;
    root -> left = buildTree(root -> left);

    cout<<"Enter the right data "<< data <<" : "<<endl;
    root -> right = buildTree(root -> right);


}

pair<int,int>diameterTree(Node* root){
        
    if( root == NULL){
         pair<int,int>p = make_pair(0,0);
         return p;
    }

    pair<int,int> left = diameterTree(root -> left);
    pair<int,int> right = diameterTree(root -> right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1 , max(op2,op3));
    ans.second = max(left.second , right.second )+1;
   
    return ans;
}

int main()
{

Node* root = NULL;
root = buildTree(root);

cout<<"The diameter of tree is: " << diameterTree(root).first<<endl;



}



