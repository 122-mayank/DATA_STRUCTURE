#include<bits/stdc++.h>
using namepsace std;




void solve(int&ans ,  vector<vector<char>>&arr ,vector<vector<char>>&temp,int row , int col ){

         




     //right
      if(isSafe(arr , temp , col , row  )){
                swap(arr[row][col] , arr[row][col-1]);
                swap(arr[row][col-1] , arr[row][col-2]);

                solve(ans , arr , temp , row , col + 1  );

                swap(arr[row][col] , arr[row][col-1]);
                swap(arr[row][col-1] , arr[row][col-2]);
      }


      //down
      if(isSafe(arr , temp , col  , row )){
               swap(arr[row+1][col] , arr[row][col]);
               swap(arr[row+1][col-1], arr[row+1][col-1]);

               solve(ans , arr , temp , row+1 , col );
      }

      //rotation
      


}

int main(){

     int m ;
     cout <<"Enter the number of rows: ";
     cin >> m;

     int n ;
     cout <<"Enter the  number of columns: ";
     cin >> n;

     vector<vector<char>>arr(m , vector<char>(n));

     for(int i = 0 ; i < m ; i++){
           for(int j = 0 ; j < n ; j++){
               cin >> arr[i][j];
           }
     }
      
     vector<vector<char>>temp;
     for(int i = 0 ; i < m ; i++){
           for(int j = 0 ; j < n ; j++){
               if(arr[i][j] == 's'){ 
                   vector<char>other;
                   other.push_back(i);
                   other.push_back(j);
                   temp.push_back(other);

               }
           }
     }
     int ans;
     solve(ans , arr , temp  , 0 , 2);



}