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

TreeNode* insertToBst(TreeNode*root , int data){
         
    if( root == nullptr){
        return new TreeNode(data);
    }

    if( root -> data > data){
         root -> left = insertToBst(root -> left , data);
    }
    else{
        root -> right = insertToBst(root -> right , data);
    }

return root;

}
void takeinput(TreeNode*& root){
        int data ;
        cout <<"Enter the data: "<<endl;
        cin >> data;
        while( data != -1){
              root = insertToBst(root , data);
              cin >> data;
        }
}

void convertBstToLL(TreeNode* root , TreeNode*&head){

    if( root == NULL){
          return ;
    }

    convertBstToLL(root -> right , head);
    root -> right = head;
    if( head != NULL){
         head -> left = root;
    }
    head = root;
    convertBstToLL(root -> left , head);

}

TreeNode* merge(TreeNode*head1 , TreeNode* head2){

     TreeNode* head = NULL;
     TreeNode* tail = NULL;

     while( head1 != NULL && head2 != NULL){
              
        if( head1 -> data < head2 -> data){
                 
                if( head == NULL){
                    head = head1;
                    tail = head1;
                    head1 = head1 -> right;
                }

                else{
                    tail -> right = head1;
                    head1 -> left = tail;
                    tail = head1;
                    head1 = head1 -> right;
                }

        }

        else{
                
            if( head == NULL){
                    head = head2;
                    tail = head2;
                    head2 = head2 -> right;
                }

                else{
                    tail -> right = head2;
                    head2 -> left = tail;
                    tail = head2;
                    head2 = head2 -> right;
                }
             
        }       
     }

     while(head1 != NULL){
         tail -> right = head1;
         head1 -> left = tail;
         tail = head1;
         head1 = head1 -> right;
     }

     while(head2 != NULL){

        tail -> right = head2;
        head2 -> left = tail;
        tail = head2;
        head2 = head2 -> right;

     }

    return head;
}

TreeNode* convertLLtoBst(TreeNode*&head , int n){

    if( n <= 0 || head == NULL){
        return NULL;
    }

    TreeNode*left = convertLLtoBst(head , n/2);
    TreeNode* root = head;

    root -> left = left;


    head = head -> right;
    root -> right = convertLLtoBst(head , n - (n / 2) - 1);
    
    return root;

}
void inorder(TreeNode* root){
    
    if( root == NULL){
        return;
    }

    inorder(root -> left);
    cout << root -> data <<" ";
    inorder( root -> right);

}

int count(TreeNode* root){

    int cnt = 0;
    TreeNode* temp = root;

    while( temp != NULL){

        cnt++;
        temp = temp -> right;

    }
  return cnt;
}

int main(){

    TreeNode* root1 = NULL;
    cout <<"Enter the data to create 1st BST: "<<endl;
    takeinput(root1);

    TreeNode* root2 = NULL;
    cout<<"Enter the data to create 2nd BST: "<<endl;
    takeinput(root2);

    TreeNode* head1 = NULL;
    convertBstToLL(root1 , head1);
    head1 -> left = NULL;

    TreeNode* head2 = NULL;
    convertBstToLL(root2 , head2);
    head2 -> left = NULL;

    TreeNode* ans = merge(head1 , head2);

    TreeNode* root = convertLLtoBst(ans , count(ans));
    cout << endl;
    cout <<"Inorder of the BST: "<<endl;
    inorder(root);

}