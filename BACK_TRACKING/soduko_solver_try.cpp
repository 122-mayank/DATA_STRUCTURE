#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>&board , int row , int col , int option){


    for(int i = 0 ; i < 9 ; i++){
        if(board[row][i] == option){
            return false;
        }
    }

    for( int i = 0 ; i < 9 ; i++){
        if(board[i][col] == option){
            return false;
        }
    }

    int x= row- row%3;
    int y= col-col%3;

    for(int i =x;i<x+3;i++){
        for(int j =y;j<y+3;j++){
            if(board[i][j]==option){
                return false;
            }
        }
    }
return true;
}


bool solve( vector<vector<int>>&board ,int row , int col){

    if(row == 8 && col == 9){
        return true;
    }

    if(col == 9){
           row = row +1;
           col = 0;
    }

    if(board[row][col] != 0){
         return solve(board , row, col+1);
    }

    else if(board[row][col] == 0){

         for(int i =1 ; i <= 9 ; i++){

             if(isSafe(board, row ,col , i)){
                 board[row][col] = i;
                 if(solve(board , row , col+1)){
                     return true;
                 }
                 else{
                     board[row][col] = 0; //backtrack
                 }
             }

         }

    }
return false;

}
int main(){

    vector<vector<int>>board ={

        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}

    };

    solve(board , 0 , 0);

     for(int i = 0 ; i < board.size() ; i++){

         for(int j = 0 ; j < board[i].size() ; j++){
             cout << board[i][j] <<" ";
         }
         cout << endl;

     }

}