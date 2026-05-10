#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this.data = data;
        this.right = nullptr;
        this.left = nullptr;
    }

};
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

void takeInput(Node*&root){
    
    int data;
    cout <<"Enter the data: "<<endl;
    cin >> data;

    while(data != -1){
        root = insertIntoBst(root , data);
        cin >> data;
    }

}

int main(){
           
Node* root = nullptr;
cout <<"Enter data to create the BST: ";
takeInput(root);



}