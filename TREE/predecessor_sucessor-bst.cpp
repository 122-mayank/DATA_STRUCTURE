#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert in BST
Node* insertBST(Node* root, int val) {
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Find predecessor and successor
pair<int, int> findPreSuc(Node* root, int key) {
    int pred = -1, succ = -1;
    Node* temp = root;

    while (temp != NULL) {
        if (temp->data == key) {
            // Go left for predecessor
            Node* leftTree = temp->left;
            while (leftTree) {
                pred = leftTree->data;
                leftTree = leftTree->right;
            }

            // Go right for successor
            Node* rightTree = temp->right;
            while (rightTree) {
                succ = rightTree->data;
                rightTree = rightTree->left;
            }
            break;
        } else if (key < temp->data) {
            succ = temp->data;
            temp = temp->left;
        } else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    return {pred, succ};
}

int main() {
    Node* root = NULL;
    cout << "Enter values to insert in BST (-1 to stop): " << endl;
    int val;
    while (cin >> val && val != -1) {
        root = insertBST(root, val);
    }

    cout << "Inorder Traversal    " << endl;
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter the key:       " << endl;
    cin >> key;

    pair<int, int> ans = findPreSuc(root, key);
    cout << "Inorder successor : " << ans.second << endl;
    cout << "Inorder Predecessor : " << ans.first << endl;

    return 0;
}
