
// recursion approach

#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>&arr , int n){

    if( n < 0){
         return 0;
    }

    if(n == 0){
        return arr[0];
    }

    int incl = solve(arr , n - 2) + arr[n];
    int excl = solve( arr , n - 1) + 0;

    return max(incl , excl);

}


int main(){

    int size;
    cout <<"Enter the size of the array: "<< endl;
    cin >> size;

    vector<int>arr(size);

    cout <<"Enter the elements of the array: "<< endl;
    for(int i  = 0 ; i < size ; i++){
         cin >> arr[i];
    }


    int ans = solve(arr , size - 1);

    cout <<"Maximum Sum is : "<< ans << endl;


}