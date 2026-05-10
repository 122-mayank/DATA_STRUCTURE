
/*
  The houses are arranged in the cyclic manner in which the start house is neighbour of previous house 
  so u can not steal money from  adjacent houses 
*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums , int idx , int size , vector<int>&dp){

     if( idx > size){
          return 0;
     }

     if(dp[idx] != -1){
          return 0;
     }


     int steal = nums[idx] + solve(nums , idx + 2 , size , dp);
     int skip = solve(nums , idx+ 1, size , dp);


     return dp[idx] = max(steal , skip);

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

    vector<int>dp(size + 1 , -1);

    //recursion + memoization
     int one_process = solve(arr , 0 , size - 2, dp);

     dp.assign(size + 1, -1);

     int second_process = solve(arr , 1 , size - 1, dp);

     int ans = max(one_process , second_process);

     cout <<"Maximum sum: "<< ans << endl;
     


}