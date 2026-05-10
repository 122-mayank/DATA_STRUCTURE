#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr , int size , int idx , vector<int>dp){

      
     if(idx >= size){
         return 0;
     }

     if(dp[idx] != -1){
          return dp[idx];
     }


     int steal = arr[idx] + solve(arr , size , idx + 2 , dp);
     int skip = solve(arr , size , idx + 1, dp);


     return max(steal , skip);
}

int main(){

    int size;
    cout <<"Enter the size: "<< endl;
    cin >> size;

    vector<int>arr(size);

    cout <<"Enter the elements: "<< endl;
    for(int i = 0 ; i < size ; i++){
         cin >> arr[i];
    }

    //using the dynamic programming -> Recursion + Memoization
    vector<int>dp(size + 1 , -1);
    int ans = solve(arr , size , 0 , dp);

    cout <<"Maximum sum: "<< ans << endl;

}