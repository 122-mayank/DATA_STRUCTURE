#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&arr , int idx , int sum , vector<int>&ans){


      if( idx >= arr.size()){
          ans.push_back(sum);
          return;
      }


      //include
      solve(arr, idx + 1 , sum + arr[idx] , ans);


      //exclude
      solve(arr , idx + 1 , sum , ans);

}

int main(){


    int size;
    cout <<"Enter the size of the array: "<< endl;
    cin >> size;


    vector<int>arr(size);
    cout <<"Enter the array elements: "<< endl;

    for(int i = 0 ; i < size ; i++){
         cin >> arr[i];
    }

    vector<int>ans;

    //subset sum
    solve(arr , 0, 0, ans);


    cout <<"Subset Sum "<< endl;
    for(int i = 0 ; i < ans.size() ; i++){
         cout << ans[i] <<" ";
    }

    cout << endl;
}