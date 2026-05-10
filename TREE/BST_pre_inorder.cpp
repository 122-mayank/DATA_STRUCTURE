#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Helper function
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, 
                    int& preIndex, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
    if (preIndex >= preorder.size() || inStart > inEnd) {
        return nullptr;
    }

    int element = preorder[preIndex++];
    TreeNode* root = new TreeNode(element);

    int position = inorderMap[element];

    root->left = buildTree(preorder, inorder, preIndex, inStart, position - 1, inorderMap);
    root->right = buildTree(preorder, inorder, preIndex, position + 1, inEnd, inorderMap);

    return root;
}

TreeNode* createBST(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }
    int preIndex = 0;
    return buildTree(preorder, inorder, preIndex, 0, inorder.size() - 1, inorderMap);
}

// For testing: Inorder traversal printing
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int size;
    cout << "Enter the size: " << endl;
    cin >> size;

    vector<int> preorder(size);
    cout << "Enter the preorder elements: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> preorder[i];
    }

    vector<int> inorder(size);
    cout << "Enter the inorder elements: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> inorder[i];
    }

    TreeNode* root = createBST(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
