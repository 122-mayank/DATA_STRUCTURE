#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node( int data ){
        this -> data = data;
        this -> left = NULL;
        this -> right = nullptr;
    }

};

Node* insertBST(Node*root , int data){

    if( root == NULL){
         return new Node(data);
    }

    if( root -> data > data){
        root -> left = insertBST(root -> left, data);
    }
    else{
        root -> right = insertBST(root -> right , data);
    }
   return root;

}

void takeinput(Node*&root){

    int data;
    cout <<"Enter the data : "<<endl;
    cin >> data ;

    while( data != -1){
         root = insertBST( root , data );
         cin >> data;
    }

}

void inorder(Node* root , vector<int>&ans){
    
    if( root == NULL){
        return;
    }

    inorder(root -> left, ans);
    ans.push_back(root -> data);
    inorder( root -> right , ans);

}

void inorder2(Node* root){
    
    if( root == NULL){
        return;
    }

    inorder2(root -> left);
    cout << root -> data <<" ";
    inorder2( root -> right);

}

Node* solve(int s , int e , vector<int>&res){

if( s > e){
    return NULL;
}

int mid = ( s + e) / 2;
Node* root = new Node(res[mid]);
root -> left = solve( s , mid -1 , res);
root -> right = solve(mid +1 , e , res);

return root;

}

int main(){
    
    vector<int>ans1;
    vector<int>ans2;

    Node* root1 = NULL;
    cout  <<"Enter the data to create the BST "<<endl;
    takeinput(root1);
    cout <<"Inorder Traversal of the 1st BST: "<<endl;
    inorder(root1 , ans1);
    inorder2(root1);
    
    cout <<endl <<endl;

    Node* root2 = NULL;
    cout  <<"Enter the data to create the BST "<<endl;
    takeinput(root2);
    cout <<"Inorder Traversal of the 2nd BST: "<<endl;
    inorder(root2 , ans2);
    inorder2(root2);

//     cout <<endl;
//     cout <<"Printing"<<endl;

//     for(int i = 0 ; i < ans1.size() ; i++){
//         cout << ans1[i] << " ";
//     }
//     cout << endl;
//    for(int i = 0 ; i < ans2.size() ; i++){
//         cout << ans2[i] << " ";
//     }
    
    // merging two sorted arrays

    int i = 0 , j = 0;

    int n1 = ans1.size();
    int n2 = ans2.size();

    vector<int> res;


    while( i < n1 && j < n2){
    if( ans1[i] < ans2[j]){
        res.push_back(ans1[i++]);
    }
    else{
        res.push_back(ans2[j++]);
    }
}

while( i < n1){
    res.push_back(ans1[i++]);
}
while( j < n2){
    res.push_back(ans2[j++]);
}

    cout << endl << endl;
    Node* output = solve( 0 , res.size()-1 , res);
    cout <<"Inorder of the merged BST "<<endl;
    inorder2(output);


 }