#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row , int col , vector<vector<bool>>&visited , vector<vector<int>>&arr){

          if((row >=0 && row < arr.size()) 
          && (col >= 0 && col < arr.size())&&
        arr[row][col] == 1 && visited[row][col] != 1 
            ){
                  return true;
          }
          return false;
     
}

void solve(int row , int col , string path , vector<string>&ans , vector<vector<int>>&arr
    ,vector<vector<bool>> &visited){
          
    if( row == arr.size() - 1 && col == arr.size() -1 ){
          ans.push_back(path);
    }

    //Down
    if(isSafe(row + 1, col , visited , arr)){
           visited[row][col] = true;
           solve(row + 1 , col , path + 'D' , ans, arr , visited);
           visited[row][col] = false;
    }

    //Left
     
    if(isSafe(row , col - 1 , visited , arr)){
           visited[row][col] = true;
           solve(row  , col - 1 , path + 'L' ,ans, arr , visited);
           visited[row][col] = false;
    }



    //Right
     
    if(isSafe(row , col + 1, visited , arr)){
           visited[row][col] = true;
           solve(row  , col + 1 , path + 'R' ,ans, arr , visited);
           visited[row][col] = false;
    }

    //Up
    if(isSafe(row - 1 , col , visited , arr)){
           visited[row][col] = true;
           solve(row - 1 , col , path + 'U' , ans,arr , visited);
           visited[row][col] = false;
    }

}


int main(){

  int row;
  int col;

  cout <<"Enter the row and column(square matrix): ";
  cin >> row >> col;
  
  vector<vector<int>> arr(row , vector<int>(col));
  cout << "Enter the 2D array elements: ";
  for(int i = 0 ; i < row ; i++){
       for(int j = 0 ; j < col ; j++){
           cin >> arr[i][j];
       }
  }
  
  cout <<"Printing the 2D array matrix " << endl;
  for(int i = 0 ; i < row ; i++ ){
      for(int j = 0 ; j < col ; j++){
          cout << arr[i][j] <<" ";
      }

      cout << endl;
  }

  vector<string> ans ;
  vector<vector<bool>> visited(row , vector<bool>(row , false));
  string path = " ";

  solve( 0 , 0 , path ,ans , arr, visited);

 cout <<"The string containes it: "<< endl;
  for(string val : ans){
    cout << val << " ";
  }



}