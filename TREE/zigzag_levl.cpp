#include<iostream>
#include<vector>
#include<queue>
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


vector<int> zigZagTraversal(Node* root){

   vector<int> ans;
   if( root == NULL){
    return ans;
   }
  
  queue<Node*> q;
  q.push(root);
  bool leftToRight = true;

  while(!q.empty()){

      int size = q.size();
      vector<int> arr(size);
      for( int i = 0 ; i < size ; i++){
        Node* frontNode = q.front();
        q.pop();
         
        int index = leftToRight ? i : size - i -1;

        ans[index] = frontNode -> data;
        if(frontNode -> left){
            q.push(frontNode -> left);
        }
        if( frontNode -> right){
            q.push(frontNode -> right);
        }
      }
      leftToRight = !leftToRight;
    
      for( auto i : arr){
             ans.push_back(i);
      }

   
  }
return ans;

}


int main(){
  
Node* root = NULL;

root = buildTree(root);

vector<int> ans = zigZagTraversal(root);



   

}