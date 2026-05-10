#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool helper(vector<vector<char>>& board, int row, int col, string& word, int i, vector<vector<bool>>& visited) {
        if (i == word.size()) {
            return true;
        }

        int m = board.size(), n = board[0].size();

        // Down
        if (row + 1 < m && !visited[row + 1][col] && board[row + 1][col] == word[i]) {
            visited[row + 1][col] = true;
            if (helper(board, row + 1, col, word, i + 1, visited)) return true;
            visited[row + 1][col] = false;
        }

        // Right
        if (col + 1 < n && !visited[row][col + 1] && board[row][col + 1] == word[i]) {
            visited[row][col + 1] = true;
            if (helper(board, row, col + 1, word, i + 1, visited)) return true;
            visited[row][col + 1] = false;
        }

        // Up
        if (row - 1 >= 0 && !visited[row - 1][col] && board[row - 1][col] == word[i]) {
            visited[row - 1][col] = true;
            if (helper(board, row - 1, col, word, i + 1, visited)) return true;
            visited[row - 1][col] = false;
        }

        // Left
        if (col - 1 >= 0 && !visited[row][col - 1] && board[row][col - 1] == word[i]) {
            visited[row][col - 1] = true;
            if (helper(board, row, col - 1, word, i + 1, visited)) return true;
            visited[row][col - 1] = false;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (helper(board, i, j, word, 1, visited)) return true;
                    visited[i][j] = false;
                }
            }
        }

        return false;
    }
};

// ✅ Main function to test
int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word1 = "ABCCED"; // Should return true
    string word2 = "SEE";    // Should return true
    string word3 = "ABCB";   // Should return false

    cout << "Word: " << word1 << " → " << (sol.exist(board, word1) ? "Found" : "Not Found") << endl;
    cout << "Word: " << word2 << " → " << (sol.exist(board, word2) ? "Found" : "Not Found") << endl;
    cout << "Word: " << word3 << " → " << (sol.exist(board, word3) ? "Found" : "Not Found") << endl;

    return 0;
}
