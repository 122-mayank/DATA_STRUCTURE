#include<bits/stdc++.h>
using namespace std;

int rotateArray(vector<int>&arr){

    int low = 0;
    int high = arr.size() - 1;

    while(low < high){

        int mid = low + (high - low) / 2;

        if(arr[mid] <= arr[low]){
            low = mid + 1;
        }
        else{
           high = mid;

    }
    return low;
}


int main(){

    int size;
    cout <<"Enter the size"<< endl;
    cin >> size;

    vector<int>arr(size);

    cout <<"Enter the array elements"<< endl;
    for(int i = 0 ; i <size ; i++){
        cin >> arr[i];
    }

    int ans = rotateArray(arr);
    
    cout << ans <<" times of rotated sorted array "<< endl;


}