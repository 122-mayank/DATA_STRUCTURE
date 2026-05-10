#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&nums , int idx , int size , vector<vector<int>>&ans){

     if(idx >= size){
         ans.push_back(nums);
         return;
     }


     for(int j = idx ; j < size ; j++){

        swap(nums[j] , nums[idx]);

        solve(nums , idx + 1 , size , ans);

        //backtrack
        swap(nums[j] , nums[idx]);

     }

}
vector<vector<int>>permutations(vector<int>&arr){

    int size = arr.size();
    vector<vector<int>>output;
   solve(arr, 0 , size , output);

   return output;
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

    vector<vector<int>>ans = permutations(arr);

    cout <<"Permutations: "<< endl;
    for(int i = 0 ; i < ans.size() ; i++){
        
        for(int j = 0 ; j < ans[i].size() ; j++){
            cout << ans[i][j] <<" ";
        }
        cout << endl;
    }

}