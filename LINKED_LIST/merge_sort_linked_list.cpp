#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

void print(Node* temp) {
    while (temp != NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* getmiddle(Node* head) {
    if (head == NULL) return NULL;  // Check if head is NULL

    Node* slow = head;
    Node* fast = head;

    // Move fast by two and slow by one step to find middle
    while (fast && fast->next ) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* merge(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Node* ans = new Node(-1);  // Dummy node
    Node* temp = ans;

    // Merge two sorted lists
    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next = left;
            temp = temp->next;
            left = left->next;
        } else {
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
    }

    // Add remaining nodes of either left or right
    if (left != NULL) {
        temp->next = left;
    } else {
        temp->next = right;
    }

    return ans->next;  // Return the sorted list, skipping the dummy node
}

Node* mergesort(Node* head) {
    if (head == NULL || head->next == NULL) return head;  // Base case

    // Find middle of the list
    Node* middle = getmiddle(head);

    // Divide list into two halves
    Node* left = head;
    Node* right = middle->next;
    middle->next = NULL;

    // Recursively sort both halves
    left = mergesort(left);
    right = mergesort(right);

    // Merge the two sorted halves
    return merge(left, right);
}

int main() {
    int n, data;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the head data: ";
    cin >> data;

    Node* head = new Node(data);
    Node* temp = head;

    for (int i = 2; i <= n; i++) {
        cout << "Enter the " << i << " data: ";
        cin >> data;

        Node* newnode = new Node(data);
        temp->next = newnode;
        temp = newnode;
    }

    cout << "Original List: ";
    print(head);

    Node* ans = mergesort(head);

    cout << "Sorted List: ";
    print(ans);

    return 0;
}
