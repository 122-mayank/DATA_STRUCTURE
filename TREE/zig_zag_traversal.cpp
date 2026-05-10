 #include<bits/stdc++.h>
 using namespace std;

class TreeNode{

    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
         this -> data = data;
         this -> left = NULL;
         this -> right = NULL;
    }

};

void createBinaryTree(TreeNode*&root){

    int data;
    cout <<"Enter the data: "<< endl;
    cin >> data;

    if(data == -1){
        return;
    }


    root = new TreeNode(data);


    cout <<"Enter the left child of the " << data << endl;
    createBinaryTree(root -> left);

    cout <<"Enter the right child of the "<< data  << endl;
    createBinaryTree(root -> right);

}


vector<int> zigZagTraversal(TreeNode* root){

      vector<int>ans;

      if(root == NULL){
        return ans;
    }


    queue<TreeNode*>q;
    q.push(root);

    bool leftToright = true;
    while(!q.empty()){

        int size = q.size();
        vector<int>arr(size);

        for(int i = 0 ; i < size ; i++){

             TreeNode* frontNode = q.front();
             q.pop();

             int index = leftToright ? i : size - i - 1;

             arr[index] = frontNode -> data;

             if(frontNode -> left){
                  q.push(frontNode -> left);
             }
             if(frontNode -> right){
                 q.push(frontNode -> right);
             }

        }
        leftToright = !leftToright;
        for(auto i : arr){
             ans.push_back(i);
        }
    }

return ans;

}



 int main(){

    TreeNode* root = nullptr;
    createBinaryTree(root);


    cout<<"ZigZag Traversal: "<< endl;
    vector<int> ans = zigZagTraversal(root);

    //printing the answer
    for(int i = 0 ; i < ans.size() ; i++){
         cout << ans[i] <<" ";
    }
    cout << endl;
 }


