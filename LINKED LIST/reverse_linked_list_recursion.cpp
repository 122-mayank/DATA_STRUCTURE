#include <iostream>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor
    ListNode(int data) {
        this->val = data;
        this->next = NULL;
    }
};

class Solution {
private:
    void reverse(ListNode*& head, ListNode* curr, ListNode* prev) {
        // Base case: if we reach the end of the list
        if (curr == NULL) {
            head = prev;
            return;
        }

        // Recursive case
        ListNode* forward = curr->next;
        reverse(head, forward, curr);
        curr->next = prev;
    }

public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        reverse(head, curr, prev);
        return head;
    }
};

// Function to insert nodes at the end of the linked list
void insertNode(ListNode*& head, int data) {
    if (head == NULL) {
        head = new ListNode(data);
        return;
    }
    
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new ListNode(data);
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    ListNode* head = NULL;

    // Insert nodes
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list
    Solution sol;
    head = sol.reverseList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}
