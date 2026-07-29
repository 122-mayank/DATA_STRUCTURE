#include<bits/stdc++.h>
using namespace std;

int maximumSubarray(vector<int>&arr){

    int maxi = INT_MIN;
    int currSum = 0;

    for(int i = 0 ; i < arr.size() ; i++){

        currSum = max(arr[i] , currSum + arr[i]);

        maxi = max(maxi , currSum);

    }

    return maxi;

}

int main(){

    int size;
    cout <<"Enter the size"<< endl;
    cin >> size;

    vector<int>arr(size);

    cout <<"Enter the elements of the array "<< endl;
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }

    int maxSum = maximumSubarray(arr);
    
    cout <<"Maximum Subarray "<< maxSum << endl;

}