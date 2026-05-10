#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorderTraversal(Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
Node* insertIntoBst(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data > root->data) {
        root->right = insertIntoBst(root->right, data);
    } else {
        root->left = insertIntoBst(root->left, data);
    }
    return root;
}
void takeInput(Node*& root) {
    int data;
    cout << "Enter node values (end with -1): ";
    cin >> data;
    while (data != -1) {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

Node* minVal(Node* root ){
    Node* temp = root;
    while( temp -> left != NULL){
          temp = temp ->left;
    }
    return temp;
}


Node* deleteFromBST(Node* root , int val){

    if( root == NULL){
        return NULL;
    }
   
    if( root -> data == val){

    //0 child 
     if( root -> left == NULL && root -> right == NULL){
       delete root;
       return NULL;
     }

    //1 child 
     
    //left child 
    if( root -> left != NULL && root -> right == NULL){
           Node* temp = root -> left;
           delete root;
           return temp;
    }
    //right child
    if( root -> left == NULL && root -> right != NULL){
           Node* temp = root -> right;
           delete root;
           return temp;
    }

    //2 child
     if( root ->left != NULL && root -> right != NULL){

          int mini = minVal(root -> right) -> data;
          root -> data = mini;
          root -> right  = deleteFromBST(root  -> right , mini);
          return root;
     }

    }

    if( root -> data > val){
        root -> left = deleteFromBST(root -> left , val);
        return root;
    }

    else{
        root -> right= deleteFromBST(root -> right , val);
        return root;

    }

}


void levelOrderTraversal(Node * root){

              queue<Node*> q;
              q.push(root);
              q.push(NULL);
              while(!q.empty()){
                Node* temp = q.front();
                q.pop();
                 
                 if( temp == NULL){
                    cout << endl;
                    if(!q.empty()){
                        q.push(NULL);

                    }
                 }
                 else{
                       cout << temp -> data <<" ";
                
                if( temp -> left != NULL ){
                    q.push(temp -> left);
                }
                if( temp -> right != NULL ){
                    q.push(temp -> right);
                }
              }
              }
             
}



int main() {

    Node* root = NULL;
    cout << "Enter data to create BST:" << endl;
    takeInput(root);


    if (root == NULL) {
        cout << "BST is empty!" << endl;
    } else {
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    cout << "Level Order Traversal: ";
    cout <<endl;
    levelOrderTraversal(root);
    cout << endl;
    }



    deleteFromBST(root , 50 );
    cout << endl <<endl;



    if (root == NULL) {
        cout << "BST is empty!" << endl;
    } else {
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    cout << "Level Order Traversal: ";
    cout <<endl;
    levelOrderTraversal(root);
    }


    return 0;
}
