#include<bits/stdc++.h>
using namespace std;



bool isSafe(int row, int col, vector<vector<char>>& board, int size) {


    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }


    int x = row, y = col;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 'Q') return false;
        x--; y--;
    }


    x = row; y = col;
    while (x >= 0 && y < size) {
        if (board[x][y] == 'Q') return false;
        x--; y++;
    }

    return true;
}
void solve(vector<vector<char>>&board , int row , int size ){

  if(row == size){
      cout << "Solution:\n";
        for (auto &r : board) {
            for (char c : r) cout << c << " ";
            cout << "\n";
        }
        cout << "\n";
        return;
  }

   for(int col = 0 ; col < size ; col++){
         if(isSafe(row , col, board ,size)){
             board[row][col] = 'Q';
             solve(board , row+1 , size );
             board[row][col] = '0'; //backtrack
         }
   }

}

int main(){

int size;
cout <<"Enter the size: ";
cin >> size;

vector<vector<char>>board(size , vector<char>(size,'0'));
solve(board ,  0 , size );

return 0;
}