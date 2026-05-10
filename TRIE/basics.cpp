#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        this->ch = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* node, string& word, int index) {
        // base case: whole word processed
        if(index == word.size()) {
            node->isTerminal = true;
            return;
        }

        int childIndex = word[index] - 'A';  // assumes uppercase input
        TrieNode* child;

        if(node->children[childIndex] != NULL) {
            child = node->children[childIndex];
        } else {
            child = new TrieNode(word[index]);
            node->children[childIndex] = child;
        }

        insertUtil(child, word, index + 1);
    }

    void insertWord(string word) {
        insertUtil(root, word, 0);
    }

    bool searchUtil(TrieNode* node, string& word, int index) {
        if(index == word.size()) {
            return node->isTerminal;
        }

        int childIndex = word[index] - 'A';
        TrieNode* child = node->children[childIndex];

        if(child == NULL) {
            return false;
        }

        return searchUtil(child, word, index + 1);
    }

    bool searchWord(string word) {
        return searchUtil(root, word, 0);
    }
};

int main() {
    Trie* t = new Trie();

    t->insertWord("ABCD");
    cout << "Present or not: " << t->searchWord("ABCD") << endl;

    t->insertWord("HELLO");
    cout << "Present or not: " << t->searchWord("HEL") << endl;    // false
    cout << "Present or not: " << t->searchWord("HELLO") << endl;  // true

    t->insertWord("ABCE");
    cout << "Present or not: " << t->searchWord("ABCE") << endl;   // true
    cout << "Present or not: " << t->searchWord("XYZ") << endl;    // false
}
