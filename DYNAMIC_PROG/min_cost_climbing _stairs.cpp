 #include<bits/stdc++.h>
 using namespace std;

 int solve(vector<int>&cost , int n , vector<int>&dp){

      if( n == 0){
        return cost[0];
      }

      if(n == 1){
         return cost[1];
      }

      if(dp[n] != -1){
          return dp[n];
      }


      dp[n] = cost[n] + min(solve(cost , n- 1 , dp) , solve(cost , n- 2 , dp));

      return dp[n];



 }


 int main(){

    int size;
    cout <<"Enter the size of the array: "<<endl;
    cin >> size;

    vector<int>arr(size);
    cout<<"Enter the array elements: "<< endl;

    for(int i = 0 ; i < size ; i++){
         cin >> arr[i];
    }
    vector<int>dp(size+ 1, -1);

    int ans = min(solve(cost , size - 1 , dp) , solve(cost , size - 2 , dp));
    cout << ans << endl;


 }